#include "udfTourInfo.h"
#include "udfMainFrameBase.h"
#include "udfJudgeMark.h"
#include "udfFinalMarks.h"

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
		
		m_gridSuccess->ClearGrid();
		if(m_gridSuccess->GetNumberRows())
			m_gridSuccess->DeleteRows(0, m_gridSuccess->GetNumberRows());
		if(m_gridSuccess->GetNumberCols())
			m_gridSuccess->DeleteCols(0, m_gridSuccess->GetNumberCols());

		m_gridSuccess->SetDefaultColSize(25);
		m_gridSuccess->SetDefaultRowSize(25);
		m_gridSuccess->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
		m_gridSuccess->SetRowLabelAlignment(wxALIGN_LEFT, wxALIGN_CENTRE);

		int extraCols = 2;
		if(m_tourType == 1)
			extraCols = 1;
			
		//Start append cols
		tUIList juds;
		GetJudgesForCategory(catItem->GetId(), juds);
		int nColsCount = juds.size() + extraCols; // Include Pass and Sum col

		m_gridSuccess->AppendCols(nColsCount);

		if(m_tourType == 1)
		{
			m_gridSuccess->SetColLabelValue(0, GetVerticalText("Place"));
		}
		else
		{
			m_gridSuccess->SetColLabelValue(0, GetVerticalText("Pass"));
		
			m_gridSuccess->SetColMinimalWidth(1, 30);
			m_gridSuccess->SetColLabelValue(1, GetVerticalText("Sum"));
		}

		int nCol = extraCols;
		tUIListIt jud = juds.begin();
		while(jud != juds.end())
		{
			unsigned int jId = *jud;
			m_gridSuccess->SetColLabelValue(nCol, GetVerticalText(GetCsJudgeNameById(jId)));
			m_col2id[nCol] = jId;
			m_id2col[jId] = nCol;

			nCol++;
			jud++;
		}
		// Finish append cols

		// Start append rows
		

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
			m_row2id[nRow] = data.id;
			m_id2row[data.id] = nRow;
			
			__info("Row: %d, Rows: %d, Cols: %d", nRow, m_gridSuccess->GetNumberRows(), m_gridSuccess->GetNumberCols());
			m_gridSuccess->SetCellValue(wxString::Format(_("%d"), data.sum), nRow, 1);
			
			nCol = extraCols;
			for(tCListIt c = data.marksList.begin(); c != data.marksList.end(); c++, nCol++)
			{
				__info("Row: %d, Col: %d, Mark: %d", nRow, nCol, *c);
				if(*c)
				{
					m_gridSuccess->SetCellValue(_("X"), nRow, nCol);
					if(m_tourType == 1)
					{
						m_gridSuccess->SetCellValue(wxString::Format(_("%d"), *c), nRow, nCol);
					}
				}
			}
			
			nRow++;
			row++;
		}
		
		//Final tour Do not calculate sum
		if(m_tourType == 1)
		{
			CalculatePlaces();
			break;
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
				attr->SetBackgroundColour(wxColour(200, 255, 200));
				if(GetTeamPassTour(m_row2id[nRow], nTourId))
					m_gridSuccess->SetCellValue(_("X"), nRow, 0);
			}
			else if(cSum == sum)
			{
				if(GetTeamPassTour(m_row2id[nRow], nTourId))
					m_gridSuccess->SetCellValue(_("X"), nRow, 0);

				attr->SetBackgroundColour(wxColour(255, 255, 200));
			}
			else
			{
				attr->SetBackgroundColour(wxColour(255, 230, 200));
			}

			m_gridSuccess->SetRowAttr(nRow, attr);
			attr->IncRef();
		}
	}while(0);
	Leave();
}

void udfTourInfo::CalculatePlaces()
{
	Enter();
	do
	{
		__info("Calculate a place by skating rules.");
	}while(0);
	Leave();
}

void udfTourInfo::OnCellLeftClick(wxGridEvent& event)
{
	do
	{
		int row = event.GetRow(),
			col = event.GetCol();

		// Final tour
		if(m_tourType == 1)
		{
			break;
		}
		
		if(col == 0)
		{
			wxString value = m_gridSuccess->GetCellValue(row, col);
			if(value.IsEmpty())
				m_gridSuccess->SetCellValue(row, col, _("X"));
			else
				m_gridSuccess->SetCellValue(row, col, _(""));
		}
	}while(0);
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
		
		if(m_tourType == 1)
		{
			udfFinalMarks(this, tourItem->GetId()).ShowModal();
		}
		else
		{
			udfJudgeMark(this, tourItem->GetId()).ShowModal();
		}
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

		int nRow = 0;
		for(nRow = 0; nRow < m_gridSuccess->GetNumberRows(); ++nRow)
		{
			wxString value = m_gridSuccess->GetCellValue(nRow, 0);
			unsigned int id = -1;

			CChampionshipTourPassTable::tDATA data;
			data.tourId = tourInfo.id;
			data.teamId = m_row2id[nRow];
			long found = CChampionshipTourPassTable(m_pCon).FindId(id, data);
			if(UDF_OK == found && value != _("X"))
			{
				__debug("Found! ID: %d. Delete it...", id);
				CChampionshipTourPassTable(m_pCon).DelRow(id);
			}
			else if(found == UDF_E_NOTFOUND && value == _("X"))
			{
				__debug("NOT Found! Insert it...");
				CChampionshipTourPassTable(m_pCon).AddRow(data);
			}
		}
		//*/
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

void udfTourInfo::OnAddNext(wxCommandEvent& event)
{
	Enter();
	do
	{
		if(m_tourType == 1)
		{
			ShowWarning(STR_WARNING_CAT_ALREADY_HAS_FINAL);
			break;
		}
			
		if(m_pMainWindow)
			m_pMainWindow->OnAddTour(event);
		
	}while(0);
	
	event.Skip();
	
	Leave();
}

void udfTourInfo::OnMarkGreen(wxCommandEvent& event)
{
	int nRow = 0;
	for(nRow = 0; nRow < m_gridSuccess->GetNumberRows(); ++nRow)
	{
		if(m_gridSuccess->GetCellBackgroundColour(nRow, 0) == wxColour(200, 255, 200))
		{
			m_gridSuccess->SetCellValue(_("X"), nRow, 0);
		}
	}
}

void udfTourInfo::OnMarkYellow(wxCommandEvent& event)
{
	int nRow = 0;
	for(nRow = 0; nRow < m_gridSuccess->GetNumberRows(); ++nRow)
	{
		if(m_gridSuccess->GetCellBackgroundColour(nRow, 0) == wxColour(255, 255, 200))
		{
			m_gridSuccess->SetCellValue(_("X"), nRow, 0);
		}
	}
}

