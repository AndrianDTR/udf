#include "udfJudgeMark.h"

#include "db.h"

#include "udfsettingsbase.h"

#include "udfuicommon.h"
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

	int scale = udfSettingsBase::Instance()->GetJudgeMarksScale();
	m_spinScale->SetValue(scale);
	m_fntSize = m_gridMarks->GetDefaultCellFont().GetPointSize();

	if(UDF_OK == GetTourCategoryId(tourId, catId))
		m_catId = catId;

	RefreshGrid();

	m_row = m_col = -1;
}

void udfJudgeMark::OnSave( wxCommandEvent& event )
{
	UpdateMarks();
	//EndModal(wxID_OK);
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

void udfJudgeMark::RefreshGrid()
{
	Enter();
	do
	{
		int nCol = 0;
		int nRow = 0;

		m_gridMarks->ClearGrid();
		if(m_gridMarks->GetNumberRows())
			m_gridMarks->DeleteRows(0, m_gridMarks->GetNumberRows());
		if(m_gridMarks->GetNumberCols())
			m_gridMarks->DeleteCols(0, m_gridMarks->GetNumberCols());

		int scale = m_spinScale->GetValue();
		m_gridMarks->SetDefaultColSize(GRID_CELL_SIZE_DEFAULT * scale / 100);
		m_gridMarks->SetDefaultRowSize(GRID_CELL_SIZE_DEFAULT * scale / 100);
		wxFont fnt = m_gridMarks->GetDefaultCellFont();
		fnt.SetPointSize(m_fntSize * scale / 100);
		m_gridMarks->SetDefaultCellFont(fnt);
		m_gridMarks->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
		m_gridMarks->SetRowLabelAlignment(wxALIGN_LEFT, wxALIGN_CENTRE);

		tUIList juds;
		GetJudgesForCategory(m_catId, juds);

		tUIList teams;
		GetTourTeams(m_catId, m_tourId, teams);

		m_gridMarks->AppendCols(juds.size());
		m_gridMarks->AppendRows(teams.size());

		wxString jDescr;
		tUIListIt jud = juds.begin();
		while(jud != juds.end())
		{
			unsigned int jId = *jud;
			wxString letter = m_gridMarks->GetColLabelValue(nCol);
			wxString judge = GetCsJudgeNameById(jId);

			jDescr += STR_FORMAT(STR_FORMAT_REPORT_JUDGE_SHORTCUT, letter[0], judge);

			m_col2id[nCol] = jId;
			m_id2col[jId] = nCol;

			nCol++;
			jud++;
		}
		m_textJudges->SetValue(jDescr);

		tUIListIt team = teams.begin();
		while(team != teams.end())
		{
			unsigned int tId = *team;
			unsigned int startNum = 0;
			GetTeamStartNumber(tId, startNum);
			m_gridMarks->SetRowLabelValue(nRow, STR_FORMAT(STR_FORMAT_START_NUMBER, startNum));
			m_row2id[nRow] = tId;
			m_id2row[tId] = nRow;

			nRow++;
			team++;
		}

		for(nRow = 0; nRow < m_gridMarks->GetNumberRows(); ++nRow)
		{
			for(nCol = 0; nCol < m_gridMarks->GetNumberCols(); ++nCol)
			{
				unsigned int id = 0;
				CChampionshipJudgesMarkTable::tDATA data = {0};
				data.tourId = m_tourId;
				data.teamId = m_row2id[nRow];
				data.judgeId = m_col2id[nCol];
				long found = CChampionshipJudgesMarkTable(m_pCon).FindId(id, data);

				if(UDF_OK == found)
				{
					m_gridMarks->SetCellValue(_("X"), nRow, nCol);
				}
			}
		}

	}while(0);
	Leave();
}

void udfJudgeMark::UpdateMarks()
{
	Enter();
	int nRow = 0;
	for(nRow = 0; nRow < m_gridMarks->GetNumberRows(); ++nRow)
	{
		int nCol = 0;
		for(nCol = 0; nCol < m_gridMarks->GetNumberCols(); ++nCol)
		{
			wxString value = m_gridMarks->GetCellValue(nRow, nCol);
			unsigned int id = -1;

			CChampionshipJudgesMarkTable::tDATA data = {0};
			data.tourId = m_tourId;
			data.teamId = m_row2id[nRow];
			data.judgeId = m_col2id[nCol];
			long found = CChampionshipJudgesMarkTable(m_pCon).FindId(id, data);

			__info("Row: %d, Col: %d, tourId: %d, teamId: %d, FOUND: %d == %d", nRow, nCol, data.tourId, data.teamId, found, UDF_E_NOTFOUND);
			if(UDF_OK == found && value != _("X"))
			{
				__info("Found! ID: %d. Delete it...", id);
				CChampionshipJudgesMarkTable(m_pCon).DelRow(id);
			}
			else if(found == UDF_E_NOTFOUND && value == _("X"))
			{
				__info("NOT Found! Insert it...");
				data.nMark = 1;
				CChampionshipJudgesMarkTable(m_pCon).AddRow(data);
			}
		}
	}
	Leave();
}

void udfJudgeMark::OnSearch(wxCommandEvent& event)
{
	Enter();
	wxString text = m_textStartNum->GetValue();
	int nRow = 0;
	for(nRow = 0; nRow < m_gridMarks->GetNumberRows(); ++nRow)
	{

		if(!m_gridMarks->GetRowLabelValue(nRow).StartsWith(text))
			m_gridMarks->HideRow(nRow);
		else
			m_gridMarks->ShowRow(nRow);

	}
	Leave();
}

void udfJudgeMark::OnKeyUp( wxKeyEvent& event )
{
	do
	{
		int col = m_gridMarks->GetGridCursorCol();
		int row = m_gridMarks->GetGridCursorRow();

		if( -1 == row || -1 == col)
			break;

		switch(event.GetKeyCode())
		{
			case 'X':
				m_gridMarks->SetCellValue(row, col, _("X"));
				m_gridMarks->MoveCursorDown(false);
				break;

			case WXK_SPACE:
				m_gridMarks->SetCellValue(row, col, _(""));
				m_gridMarks->MoveCursorDown(false);
				break;
		}

	}while(0);
}

void udfJudgeMark::OnKeyDown( wxKeyEvent& event )
{
	if(WXK_SPACE != event.GetKeyCode())
	{
		event.Skip();
	}
}

void udfJudgeMark::OnScaleChange(wxSpinEvent& event)
{
	int scale = m_spinScale->GetValue();
	m_gridMarks->SetDefaultColSize(GRID_CELL_SIZE_DEFAULT * scale / 100);
	m_gridMarks->SetDefaultRowSize(GRID_CELL_SIZE_DEFAULT * scale / 100);
	wxFont fnt = m_gridMarks->GetDefaultCellFont();
	fnt.SetPointSize(m_fntSize * scale / 100);
	m_gridMarks->SetDefaultCellFont(fnt);
	m_gridMarks->ForceRefresh();
	udfSettingsBase::Instance()->SetJudgeMarksScale(scale);
}
