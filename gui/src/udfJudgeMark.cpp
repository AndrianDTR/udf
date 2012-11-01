#include "udfJudgeMark.h"

#include "db.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

udfJudgeMark::udfJudgeMark( wxWindow* parent, unsigned int tourId )
:JudgeMark( parent )
, m_pCon(NULL)
, m_tourId(tourId)
, m_catId(0)
{
	
	m_pCon = CDbManager::Instance()->GetConnection();

	unsigned int catId = 0;
	
	if(UDF_OK == GetTourCategoryId(tourId, catId))
		m_catId = catId;
	
	RefreshGrid();
}

void udfJudgeMark::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfJudgeMark::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfJudgeMark::OnCellLClick( wxGridEvent& event )
{
	int row = event.GetRow(),
		col = event.GetCol();

	wxString value = m_gridMarks->GetCellValue(row, col);
	if(value.IsEmpty())
		m_gridMarks->SetCellValue(row, col, _("X"));
	else
		m_gridMarks->SetCellValue(row, col, _(""));
	
	event.Skip();
}

void udfJudgeMark::OnKeyUp( wxKeyEvent& event )
{
	/*int row = m_gridMarks->GetSelectedRows()[0],
		col = m_gridMarks->GetSelectedCols()[0];

	switch(event.GetKeyCode())
	{
		case 'X':
			m_gridMarks->SetCellValue(row, col, _("X"));
			break;
		
		case WXK_SPACE:
			m_gridMarks->SetCellValue(row, col, _(""));
			break;
	}
	*/
	event.Skip();
}

void udfJudgeMark::RefreshGrid()
{
	Enter();
	do
	{
		m_gridMarks->ClearGrid();
		if(m_gridMarks->GetNumberRows())
			m_gridMarks->DeleteRows(0, m_gridMarks->GetNumberRows());
		if(m_gridMarks->GetNumberCols())
			m_gridMarks->DeleteCols(0, m_gridMarks->GetNumberCols());

		m_gridMarks->SetDefaultColSize(25);
		m_gridMarks->SetDefaultRowSize(25);
		m_gridMarks->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
		m_gridMarks->SetRowLabelAlignment(wxALIGN_LEFT, wxALIGN_CENTRE);

		tUIList juds;
		GetJudgesForCategory(m_catId, juds);
		
		tUIList teams;
		GetTourTeams(m_catId, m_tourId, teams);
		
		m_gridMarks->AppendCols(juds.size());
		m_gridMarks->AppendRows(teams.size());

		int nCol = 0;
		tUIListIt jud = juds.begin();
		while(jud != juds.end())
		{
			unsigned int jId = *jud;
			m_gridMarks->SetColLabelValue(nCol, GetVerticalText(GetCsJudgeNameById(jId)));
			m_col2id[nCol] = jId;
			m_id2row[jId] = nCol;

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
			m_gridMarks->SetRowLabelValue(nRow, wxString::Format(STR_FORMAT_START_NUMBER, startNum));
			m_col2id[nRow] = tId;
			m_id2row[tId] = nRow;

			nRow++;
			team++;
		}
	}while(0);
	Leave();
}
