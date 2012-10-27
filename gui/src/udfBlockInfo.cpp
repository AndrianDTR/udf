#include "udfBlockInfo.h"
#include "udfMainFrameBase.h"

#include "db.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

udfBlockInfo::udfBlockInfo( wxWindow* parent )
: BlockInfo( parent )
, m_pCon(NULL)
, m_pMainWindow(NULL)
, m_pTree(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	m_attr = new wxGridCellAttr();
	m_attr->SetBackgroundColour(*wxRED);
}

wxString udfBlockInfo::GetVerticalText(wxString str)
{
	wxString res;
	int n = 0;
	for(; n < str.Length(); n++)
	{
		res += wxString(str.GetChar(n)) + wxString('\n');
	}
	return res;
}

bool udfBlockInfo::Show(bool show)
{
	do
	{
		if(!show)
			break;

		CreateNewBlock();
		FillData();
		
	}while(0);

	wxPanel::Show(show);
}

void udfBlockInfo::OnUpdateBlock( wxCommandEvent& event )
{
	do
	{
		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk())
			break;
		
		if(!ValidateData())
		{
			break;
		}
		
		unsigned int nId = -1;
		
		if(m_itemId.IsOk())
		{
			udfTreeItemData* blockItem = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);
			nId = blockItem->GetId();
		}
		
		udfTreeItemData* csItem = (udfTreeItemData*)m_pTree->GetItemData(m_parentItem);
				
		CCsBlocksTable::tDATA blockInfo = {0};
		blockInfo.id = nId;
		blockInfo.csId = csItem->GetId();
		blockInfo.name = m_textName->GetValue();
		string startTime = m_textStart->GetValue().ToStdString();
		blockInfo.startTime = str2time(startTime);
		m_textPause->GetValue().ToCLong((long*)&blockInfo.pause);
		
		if(!m_itemId.IsOk())
		{
			CCsBlocksTable(m_pCon).AddRow(blockInfo);
		}
		else
		{
			CCsBlocksTable(m_pCon).UpdateRow(nId, blockInfo);
		}
						
		int nRow = 0;
		for(nRow = 0; nRow < m_gridJudgesCats->GetNumberRows(); ++nRow)
		{
			int nCol = 0;
			for(nCol = 0; nCol < m_gridJudgesCats->GetNumberCols(); ++nCol)
			{
				wxString value = m_gridJudgesCats->GetCellValue(nRow, nCol);
				unsigned int id = -1;
				
				CCsBlockJ2CTable::tDATA data = {0};
				data.blockId = blockInfo.id;
				data.csCatId = m_RowIdMap[nRow];
				data.csJudgeId = m_ColIdMap[nCol];
				long found = CCsBlockJ2CTable(m_pCon).FindId(id, data);
				if(UDF_OK == found && value != _("X"))
				{
					__debug("Found! ID: %d. Delete it...", id);
					CCsBlockJ2CTable(m_pCon).DelRow(id);
				}
				else if(found == UDF_E_NOTFOUND && value == _("X"))
				{
					__debug("NOT Found! Insert it...");
					CCsBlockJ2CTable(m_pCon).AddRow(data);
				}
			}
		}
		
		time_t len;
		GetBlockLenById(nId, len);
		m_staticLenght->SetLabel(time2str(len));
		wxString name = wxString::Format(STR_FORMAT_BLOCK_NAME, blockInfo.name, time2str(blockInfo.startTime));
		m_pTree->SetItemText(m_itemId, name);
			
	}while(0);
}

void udfBlockInfo::OnBlockCategories( wxCommandEvent& event )
{
	Enter();
	do
	{
		if(!m_pMainWindow)
		{
			__info("Main window not set");
			break;
		}
			
		if(wxID_OK == m_pMainWindow->ShowCsCategoryManager())
		{
			CreateNewBlock();
			FillData();
		}
			
	}while(0);
	
	event.Skip();
	Leave();
}

void udfBlockInfo::OnJudgesTemManager(wxCommandEvent& event)
{
	Enter();
	do
	{
		if(!m_pMainWindow)
		{
			__info("Main window not set");
			break;
		}
			
		if(wxID_OK == m_pMainWindow->ShowCsJudgesManager())
		{
			CreateNewBlock();
			FillData();
		}
			
	}while(0);
	
	event.Skip();
	Leave();
}

void udfBlockInfo::OnCellChange( wxGridEvent& event )
{
	int row = event.GetRow(),
		col = event.GetCol();

	wxString value = m_gridJudgesCats->GetCellValue(row, col);

	if(!value.IsEmpty() && value != _(" "))
		m_gridJudgesCats->SetCellValue(row, col, _("X"));

	event.Skip();
}

void udfBlockInfo::OnCellLeftClick( wxGridEvent& event )
{
	int row = event.GetRow(),
		col = event.GetCol();

	wxString value = m_gridJudgesCats->GetCellValue(row, col);
	if(value.IsEmpty())
		m_gridJudgesCats->SetCellValue(row, col, _("X"));
	else
		m_gridJudgesCats->SetCellValue(row, col, _(""));
	
	event.Skip();
}

bool udfBlockInfo::ValidateData()
{
	// check time format
	return true;
}

void udfBlockInfo::CreateNewBlock()
{
	Enter();
	do
	{
		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk())
		{
			__debug("Undefined item.");
			break;
		}
	
		CChampionshipCategoriesTable::tDATA catFilter = {0};
		CChampionshipJudgesTeamTable::tDATA judFilter = {0};
		CChampionshipCategoriesTable::tTableMap cats;
		CChampionshipJudgesTeamTable::tTableMap juds;

		udfTreeItemData* csItem = (udfTreeItemData*)m_pTree->GetItemData(m_parentItem);
		catFilter.championshipId = judFilter.championshipId = csItem->GetId();

		CChampionshipCategoriesTable(m_pCon).Find(cats, catFilter);
		CChampionshipJudgesTeamTable(m_pCon).Find(juds, judFilter);

		m_gridJudgesCats->ClearGrid();
		if(m_gridJudgesCats->GetNumberCols())
			m_gridJudgesCats->DeleteCols(0, m_gridJudgesCats->GetNumberCols());
		if(m_gridJudgesCats->GetNumberRows())
			m_gridJudgesCats->DeleteRows(0, m_gridJudgesCats->GetNumberRows());
		
		m_gridJudgesCats->SetDefaultColSize(25);
		m_gridJudgesCats->SetDefaultRowSize(25);
		m_gridJudgesCats->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
		m_gridJudgesCats->SetRowLabelAlignment(wxALIGN_LEFT, wxALIGN_CENTRE);

		m_gridJudgesCats->AppendCols(juds.size());
		m_gridJudgesCats->AppendRows(cats.size());

		CChampionshipJudgesTeamTable::tTableIt jIt = juds.begin();
		int nCol = 0;
		while(jIt != juds.end())
		{
			CChampionshipJudgesTeamTable::tDATA& data = jIt->second;
			m_gridJudgesCats->SetColLabelValue(nCol, GetVerticalText(GetJudgeNameById(data.judgeId)));
			m_ColIdMap[nCol] = jIt->first;
			m_IdColMap[jIt->first] = nCol;
			nCol++;
			jIt++;
		}

		CChampionshipCategoriesTable::tTableIt cIt = cats.begin();
		int nRow = 0;
		while(cIt != cats.end())
		{
			CChampionshipCategoriesTable::tDATA& data = cIt->second;
			int nTeams = 0;
			GetCategoryNTeamsById(data.id, nTeams);
			wxString rowName = wxString::Format(_("%s - %d")
				, GetCategoryShortNameById(data.catId)
				, nTeams);
			m_gridJudgesCats->SetRowLabelValue(nRow, rowName);
			
			if(m_itemId.IsOk())
			{
				udfTreeItemData* blockItem = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);
				if(UDF_OK == IsCategoryUsedOnCsById(data.id, blockItem->GetId()))
					m_gridJudgesCats->SetRowAttr(nRow, m_attr);
			}
			m_RowIdMap[nRow] = cIt->first;
			m_IdRowMap[cIt->first] = nRow;
			nRow++;
			cIt++;
		}

		FillData();
		
	}while(0);
	
	Leave();
}

void udfBlockInfo::FillData()
{
	Enter();
	do
	{
		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk() || !m_itemId.IsOk())
		{
			__info("One of item is not set");
			break;
		}
		
		udfTreeItemData* blockItem = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);
		unsigned int nId = blockItem->GetId();
		
		CCsBlocksTable::tDATA blockData = {0};
		CCsBlocksTable(m_pCon).GetRow(nId, blockData);
		
		m_textName->SetValue(blockData.name);
		m_textStart->SetValue(time2str(blockData.startTime));
		m_textPause->SetValue(wxString::Format(_("%d"), blockData.pause));
				
		CCsBlockJ2CTable::tDATA 					j2cFilter = {0};
		CCsBlockJ2CTable::tTableMap 				j2c;

		j2cFilter.blockId = nId;
		CCsBlockJ2CTable(m_pCon).Find(j2c, j2cFilter);

		CCsBlockJ2CTable::tTableIt it = j2c.begin();
		while(it != j2c.end())
		{
			CCsBlockJ2CTable::tDATA& data = it->second;
			
			int col = m_IdColMap[data.csJudgeId];
			int row = m_IdRowMap[data.csCatId];
			
			m_gridJudgesCats->SetCellValue(row, col, _("X"));
			
			it++;
		}
		
		time_t len;
		GetBlockLenById(nId, len);
		m_staticLenght->SetLabel(time2str(len));
	}while(0);
	
	Leave();
}
