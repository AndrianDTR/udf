#include "udfTourInfo.h"
#include "udfMainFrameBase.h"
#include "udfJudgeMark.h"

#include "db.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

udfTourInfo::udfTourInfo( wxWindow* parent )
: TourInfo( parent )
, m_pCon(NULL)
, m_pMainWindow(NULL)
, m_pTree(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
}

bool udfTourInfo::Show(bool show)
{
	Enter();
	if(show)
	{
		CreateNewTour();
		FillData();
	}

	Leave();
	return wxPanel::Show(show);
}

void udfTourInfo::CreateNewTour()
{
	Enter();
	do
	{
		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk())
		{
			__info("One of items is not set");
			break;
		}

		udfTreeItemData* catItem = (udfTreeItemData*)m_pTree->GetItemData(m_parentItem);

		m_gridSuccess->ClearGrid();
		if(m_gridSuccess->GetNumberRows())
			m_gridSuccess->DeleteRows(0, m_gridSuccess->GetNumberRows());
		if(m_gridSuccess->GetNumberCols())
			m_gridSuccess->DeleteCols(0, m_gridSuccess->GetNumberCols());

		m_gridSuccess->SetDefaultColSize(25);
		m_gridSuccess->SetDefaultRowSize(25);
		m_gridSuccess->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
		m_gridSuccess->SetRowLabelAlignment(wxALIGN_LEFT, wxALIGN_CENTRE);

		//Start append cols
		tUIList juds;
		GetJudgesForCategory(catItem->GetId(), juds);
		int nColsCount = juds.size() + 2; // Include Pass and Sum col

		m_gridSuccess->AppendCols(nColsCount);

		m_gridSuccess->SetColLabelValue(0, GetVerticalText("Passes"));

		m_gridSuccess->SetColumnWidth(1, 30);
		m_gridSuccess->SetColLabelValue(1, GetVerticalText("Sum"));

		int nCol = 2;
		tUIListIt jud = juds.begin();
		while(jud != juds.end())
		{
			unsigned int jId = *jud;
			m_gridSuccess->SetColLabelValue(nCol, GetVerticalText(GetCsJudgeNameById(jId)));
			m_col2id[nCol] = jId;
			m_id2row[jId] = nCol;

			nCol++;
			jud++;
		}
		// Finish append cols
		
		// Start append rows
		unsigned int nTourId = 0;
		if(m_itemId.IsOk())
		{
			udfTreeItemData* tourItem = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);
			nTourId = tourItem->GetId();
		}
		__info("Tour id: %d", nTourId);

		tUIList teams;
		GetTourTeams(catItem->GetId(), nTourId, teams);
		
		__info("Tour teams: %d", teams.size());
		if(0 == teams.size())
		{
			ShowWarning("There are no any team that pass in previous tour.");
			break;
		}
		
		m_tourType = 0;
		CTourTypesTable::tDATA typeData = {0};
		GetTourTypeByDancersCount(teams.size(), m_tourType);
		CTourTypesTable(m_pCon).GetRow(m_tourType, typeData);
		m_staticType->SetLabel(typeData.name);
		m_staticMinMax->SetLabel(wxString::Format("%d - %d", typeData.min, typeData.max));
		
		m_gridSuccess->AppendRows(teams.size());

		if(0 == nTourId)
		{
			__info("This is new tour");
			break;
		}
		
		CChampionshipToursTable::tDATA tourInfo = {0};
		CChampionshipToursTable(m_pCon).GetRow(nTourId, tourInfo);
		m_textLimit->SetValue(wxString::Format(_("%d"), tourInfo.limit));

		tTourMarksList		marksList;
		GetTourMarks(nTourId, juds, marksList);

		int nRow = 0;
		tTourMarksIt row = marksList.begin();
		while(row != marksList.end())
		{
			tTourMarks& data = *row;

			m_gridSuccess->SetRowLabelValue(nRow, wxString::Format(STR_FORMAT_START_NUMBER, data.startNum));
			m_col2id[nRow] = data.id;
			m_id2row[data.id] = nRow;

			m_gridSuccess->SetCellValue(wxString::Format(_("%d"), data.sum), nRow, 1);

			nCol = 2;
			for(tCListIt c = data.marksList.begin(); c != data.marksList.end(); c++, nCol++)
			{
				if(*c)
				{
					m_gridSuccess->SetCellValue(_("X"), nRow, nCol);
				}
			}

			nRow++;
			row++;
		}

		int sum = 0;
		if(tourInfo.limit < m_gridSuccess->GetNumberRows())
			m_gridSuccess->GetCellValue(tourInfo.limit, 1).ToLong((long*)&sum);

		for(nRow = 0; nRow < m_gridSuccess->GetNumberRows(); ++nRow)
		{
			wxGridCellAttr*	attr = new wxGridCellAttr();
			int cSum = 0;
			m_gridSuccess->GetCellValue(nRow, 1).ToLong((long*)&cSum);

			if(cSum > sum)
			{
				attr->SetBackgroundColour(wxColour(180, 255, 180));
				if(!GetTeamPassTour(m_col2id[nRow], nTourId))
					m_gridSuccess->SetCellValue(_(""), nRow, 0);
				else
					m_gridSuccess->SetCellValue(_("X"), nRow, 0);
			}
			else if(cSum == sum)
			{
				if(GetTeamPassTour(m_col2id[nRow], nTourId))
					m_gridSuccess->SetCellValue(_("X"), nRow, 0);
					
				attr->SetBackgroundColour(wxColour(255, 255, 180));
			}
			else
			{
				attr->SetBackgroundColour(wxColour(255, 180, 180));
			}

			m_gridSuccess->SetRowAttr(nRow, attr);
			attr->IncRef();
		}
	}while(0);
	Leave();
}

void udfTourInfo::FillData()
{
	Enter();
	do
	{
		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk())
		{
			__info("One of items is not set");
			break;
		}

	}while(0);
	Leave();
}

void udfTourInfo::OnCellLeftClick(wxGridEvent& event)
{
	int row = event.GetRow(),
		col = event.GetCol();

	if(col == 0)
	{
		wxString value = m_gridSuccess->GetCellValue(row, col);
		if(value.IsEmpty())
			m_gridSuccess->SetCellValue(row, col, _("X"));
		else
			m_gridSuccess->SetCellValue(row, col, _(""));
	}

	event.Skip();
}

void udfTourInfo::OnResults(wxCommandEvent& event)
{
	do
	{
		if(!m_itemId.IsOk())
		{
			__info("tour not selected");
			break;
		}

		udfTreeItemData* tourItem = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);
		udfJudgeMark(this, tourItem->GetId()).ShowModal();
	}while(0);
}

void udfTourInfo::OnUpdate(wxCommandEvent& event)
{
	Enter();
	do
	{
		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk())
		{
			__info("One of items is not set");
			break;
		}
		
		unsigned int nId = -1;

		if(m_itemId.IsOk())
		{
			udfTreeItemData* tourItem = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);
			nId = tourItem->GetId();
		}

		udfTreeItemData* catItem = (udfTreeItemData*)m_pTree->GetItemData(m_parentItem);

		CChampionshipToursTable::tDATA tourInfo = {0};
		tourInfo.id = nId;
		tourInfo.csCatId = catItem->GetId();
		tourInfo.typeId = m_tourType;
		m_textLimit->GetValue().ToCLong((long*)&tourInfo.limit);

		if(!m_itemId.IsOk())
		{
			CChampionshipToursTable(m_pCon).AddRow(tourInfo);
		}
		else
		{
			CChampionshipToursTable(m_pCon).UpdateRow(nId, tourInfo);
		}
/*
		int nRow = 0;
		for(nRow = 0; nRow < m_gridJudgesCats->GetNumberRows(); ++nRow)
		{
			wxString value = m_gridJudgesCats->GetCellValue(nRow, 0);
			unsigned int id = -1;

			CChampionshipJudgesMarkTable::tDATA data = {0};
			data.tourId = blockInfo.id;
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
		*/
		CTourTypesTable::tDATA typeData = {0};
		CTourTypesTable(m_pCon).GetRow(tourInfo.typeId, typeData);
		wxString name = wxString::Format(STR_FORMAT_TOUR_NAME, typeData.name, tourInfo.limit);
		if(m_itemId.IsOk())
		{
			
			m_pTree->SetItemText(m_itemId, name);
		}
		else
		{
			m_pTree->AppendItem(m_parentItem, name, -1, -1, new udfTreeItemData(tourInfo.id, IT_TOUR));
		}
		//*/
	}while(0);
	Leave();
}

void udfTourInfo::OnRemove(wxCommandEvent& event)
{
	Enter();
	do
	{
		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk() || !m_itemId.IsOk())
		{
			__info("One of items is not set");
			break;
		}
		
		udfTreeItemData* tourItem = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);
		CChampionshipToursTable(m_pCon).DelRow(tourItem->GetId());
		
		udfTreeItemData* catItem = (udfTreeItemData*)m_pTree->GetItemData(m_parentItem);
		m_pMainWindow->RefreshCategory(catItem->GetId(), m_parentItem);
		
	}while(0);
	Leave();
}
