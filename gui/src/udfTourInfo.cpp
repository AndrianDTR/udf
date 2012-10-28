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
	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		if(!pCon)
			break;

		if(!m_pMainWindow || !m_pTree || !m_parentItem.IsOk() || !m_itemId.IsOk())
			break;

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
			
			nCol++;
			jud++;
		}
		
		int nRow = 0;
		tUIListIt team = teams.begin();
		while(team != teams.end())
		{
			unsigned int tId = *team;
			unsigned int startNum = 0;
			GetTeamStartNumber(tId, startNum);
			wxString row = wxString::Format(STR_FORMAT_START_NUMBER, startNum);
			m_gridSuccess->SetRowLabelValue(nRow, row);
			
			nRow++;
			team++;
		}
	}while(0);

	return wxPanel::Show(show);
}

void udfTourInfo::CreateNewTour()
{
}

void udfTourInfo::FillData()
{
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
