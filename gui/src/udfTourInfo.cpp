#include "udfTourInfo.h"
#include "udfMainFrameBase.h"

#include "db.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

CTourCellAttrProvider::CTourCellAttrProvider()
{
    m_attrForOddRows = new wxGridCellAttr;
    m_attrForOddRows->SetBackgroundColour(wxColour(240,240,240));
}

CTourCellAttrProvider::~CTourCellAttrProvider()
{
    m_attrForOddRows->DecRef();
}

wxGridCellAttr* CTourCellAttrProvider::GetAttr(int row, int col,
	wxGridCellAttr::wxAttrKind  kind // = wxGridCellAttr::Any
	) const
{
    wxGridCellAttr *attr = wxGridCellAttrProvider::GetAttr(row, col, kind);

    if ( row % 2 )
    {
        if ( !attr )
        {
            attr = m_attrForOddRows;
            attr->IncRef();
        }
        else
        {
            if ( !attr->HasBackgroundColour() )
            {
                wxGridCellAttr *attrNew = attr->Clone();
                attr->DecRef();
                attr = attrNew;
                attr->SetBackgroundColour(wxColour(240,240,240));
            }
        }
    }

    return attr;
}

udfTourInfo::udfTourInfo( wxWindow* parent )
: TourInfo( parent )
, m_pCon(NULL)
, m_pMainWindow(NULL)
, m_pTree(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();

	m_gridSuccess->GetTable()->SetAttrProvider(new CTourCellAttrProvider());
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

		tUIList juds;
		GetJudgesForCategory(catItem->GetId(), juds);
		int nColsCount = juds.size() + 2; // Include Pass and Sum col

		tUIList teams;
		GetTeamsInCategory(catItem->GetId(), teams);

		//m_staticTCount->SetLabel(wxString::Format("%ld", teams.size()));

		CTourTypesTable::tDATA data = {0};
		m_tourType = 0;
		GetTourTypeByDancersCount(teams.size(), m_tourType);
		CTourTypesTable(m_pCon).GetRow(m_tourType, data);
		m_staticType->SetLabel(data.name);
		m_staticMinMax->SetLabel(wxString::Format("%d - %d", data.min, data.max));

		m_gridSuccess->AppendCols(nColsCount);

		m_gridSuccess->AppendRows(teams.size());

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

		if(!m_itemId.IsOk())
		{
			__info("tour not selected");
			break;
		}

		udfTreeItemData* tourItem = (udfTreeItemData*)m_pTree->GetItemData(m_itemId);

		CChampionshipToursTable::tDATA tourInfo = {0};
		CChampionshipToursTable(m_pCon).GetRow(tourItem->GetId(), tourInfo);
		m_textLimit->SetValue(wxString::Format(_("%d"), tourInfo.limit));

		tTourMarksList		marksList;
		GetTourMarks(tourItem->GetId(), juds, marksList);

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

		/*
		 * 1. from sum on row[limit]
		 * 2. mark above row with yellow untill sum increase 1 next row must be marked with green and pass flag mus be set
		 * 3. mark below row with ywllow untill sum decrease 1 next row will be marked with red
		 */
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
				m_gridSuccess->SetCellValue(_("X"), nRow, 0);
			}
			else if(cSum == sum)
			{
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
		/*
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
		string startTime = wxString(m_textStart->GetValue() + _(":00")).ToStdString();
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
		GetBlockLenById(blockInfo.id, len);
		m_staticLenght->SetLabel(time2str(len));
		wxString name = wxString::Format(STR_FORMAT_BLOCK_NAME, blockInfo.name, time2str(blockInfo.startTime));
		if(m_itemId.IsOk())
		{
			m_pTree->SetItemText(m_itemId, name);
			m_pMainWindow->RefreshCsBlock(blockInfo.id, m_itemId);
		}
		else
		{
			wxTreeItemId block = m_pTree->AppendItem(m_parentItem, name, -1, -1, new udfTreeItemData(blockInfo.id, IT_BLOCK));
			m_pMainWindow->RefreshCsBlock(blockInfo.id, block);
		}
		//*/
	}while(0);
	Leave();
}

