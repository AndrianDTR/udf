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

		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk() || !m_itemId.IsOk())
		{
			DEBUG_PRINT("Undefined item.");
			break;
		}

		CChampionshipCategoriesTable::tDATA catFilter = {0};
		CChampionshipJudgesTeamTable::tDATA judFilter = {0};
		CChampionshipCategoriesTable::tTableMap cats;
		CChampionshipJudgesTeamTable::tTableMap juds;

		udfTreeItemData* csItem = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);
		catFilter.championshipId = judFilter.championshipId = csItem->GetId();

		CChampionshipCategoriesTable(m_pCon).Find(cats, catFilter);
		CChampionshipJudgesTeamTable(m_pCon).Find(juds, judFilter);

		m_gridJudgesCats->ClearGrid();
		m_gridJudgesCats->DeleteCols(0, m_gridJudgesCats->GetNumberCols(), false);
		m_gridJudgesCats->DeleteRows(0, m_gridJudgesCats->GetNumberRows(), false);
		m_gridJudgesCats->SetDefaultColSize(25);
		m_gridJudgesCats->SetDefaultRowSize(25);
		m_gridJudgesCats->SetDefaultCellAlignment(wxALIGN_CENTRE,wxALIGN_CENTRE);
		m_gridJudgesCats->SetRowLabelAlignment(wxALIGN_LEFT,wxALIGN_CENTRE);


		m_gridJudgesCats->AppendCols(juds.size());
		m_gridJudgesCats->AppendRows(cats.size());

		CChampionshipJudgesTeamTable::tTableIt jIt = juds.begin();
		int nCol = 0;
		while(jIt != juds.end())
		{
			CChampionshipJudgesTeamTable::tDATA& data = jIt->second;
			m_gridJudgesCats->SetColLabelValue(nCol, GetVerticalText(GetJudgeNameById(data.judgeId)));
			m_ColIdMap[nCol] = jIt->first;
			nCol++;
			jIt++;
		}

		CChampionshipCategoriesTable::tTableIt cIt = cats.begin();
		int nRow = 0;
		while(cIt != cats.end())
		{
			CChampionshipCategoriesTable::tDATA& data = cIt->second;
			m_gridJudgesCats->SetRowLabelValue(nRow, GetCategoryShortNameById(data.catId));
			m_RowIdMap[nRow] = cIt->first;
			nRow++;
			cIt++;
		}

	}while(0);

	wxPanel::Show(show);
}

void udfBlockInfo::OnUpdateBlock( wxCommandEvent& event )
{
	do
	{
		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk())
			break;

		/*CCsBlockCategoriesTable::tDATA catFilter = {0};
		CCsBlockJudgesTable::tDATA judFilter = {0};

		catFilter.blockId =
		data.type = *(int*)m_comboType->GetClientData(GetSelectedType());
		data.city = *(int*)m_comboCity->GetClientData(GetSelectedCity());

		data.name = m_textChName->GetValue();
		data.additionalInfo = m_textAdditionalInfo->GetValue();
		data.address = m_textAddress->GetValue();
		data.date = m_dateDate->GetValue().GetTicks();
		data.regOpenDate = m_dateRegOpen->GetValue().GetTicks();
		data.regCloseDate = m_dateRegClose->GetValue().GetTicks();

		if(m_itemId.IsOk())
		{
			udfTreeItemData* csItem = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);
			data.id = csItem->GetId();

			if(UDF_OK != CChampionshipTable(m_pCon).UpdateRow(csItem->GetId(), data))
			{
				ShowError(STR_ERR_UPD_CHAMPIONSHIP_FAILED);
				break;
			}
			m_pTree->SetItemText(m_itemId, data.name);
		}
		else
		{
			data.id = -1;

			if(UDF_OK != CChampionshipTable(m_pCon).AddRow(data))
			{
				ShowError(STR_ERR_ADD_CHAMPIONSHIP_FAILED);
				break;
			}

			m_pTree->AppendItem(m_parentItem, data.name, -1, -1, new udfTreeItemData(data.id, IT_CS));
		}
		*/
	}while(0);
}

void udfBlockInfo::OnBlockCategories( wxCommandEvent& event )
{
// TODO: Implement OnBlockCategories
}

void udfBlockInfo::OnCellChange( wxGridEvent& event )
{
	int row = event.GetRow(),
		col = event.GetCol();

	wxString value1 = event.GetString();
	wxString value2 = m_gridJudgesCats->GetCellValue(row, col);

	if(value2 != _(" "))
		m_gridJudgesCats->SetCellValue(row, col, _("X"));

	event.Skip();
}

void udfBlockInfo::OnCellLeftClick( wxGridEvent& event )
{
// TODO: Implement OnCellLeftClick
}

void udfBlockInfo::OnSelectCell( wxGridEvent& event )
{
	wxArrayInt rows = m_gridJudgesCats->GetSelectedRows();
	m
}
