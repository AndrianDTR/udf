#include "udfFinalMarks.h"

#include "db.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

udfFinalMarks::udfFinalMarks( wxWindow* parent, unsigned int tourId )
: FinalMarks( parent )
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

void udfFinalMarks::OnSave( wxCommandEvent& event )
{
	if(Validate())
	{
		UpdateMarks();
		//EndModal(wxID_OK);
	}
}

void udfFinalMarks::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfFinalMarks::OnCellLClick( wxGridEvent& event )
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

void udfFinalMarks::OnKeyUp( wxKeyEvent& event )
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


void udfFinalMarks::RefreshGrid()
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

		m_gridMarks->SetDefaultColSize(60);
		m_gridMarks->SetDefaultRowSize(60);
		wxFont font = m_gridMarks->GetDefaultCellFont();
		font.SetPointSize(25);
		font.SetWeight(wxFONTWEIGHT_BOLD);
		m_gridMarks->SetDefaultCellFont(font);
		
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
			
			jDescr += wxString::Format(STR_FORMAT_REPORT_JUDGE_SHORTCUT, letter[0], judge);
			
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
			m_gridMarks->SetRowLabelValue(nRow, wxString::Format(STR_FORMAT_START_NUMBER, startNum));
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
					CChampionshipJudgesMarkTable(m_pCon).GetRow(id, data);
					m_gridMarks->SetCellValue(wxString::Format(_("%d"), data.nMark), nRow, nCol);
				}
			}
		}

	}while(0);
	Leave();
}

bool udfFinalMarks::Validate()
{
	Enter();
	
	bool res = false;
	do
	{
		if(0)
			break;
		
		res = true;
	}while(0);
	
	Leave();
	
	return res;
}

void udfFinalMarks::UpdateMarks()
{
	Enter();
	int nRow = 0;
	for(nRow = 0; nRow < m_gridMarks->GetNumberRows(); ++nRow)
	{
		int nCol = 0;
		for(nCol = 0; nCol < m_gridMarks->GetNumberCols(); ++nCol)
		{
			unsigned int id = -1;

			CChampionshipJudgesMarkTable::tDATA data = {0};
			data.tourId = m_tourId;
			data.teamId = m_row2id[nRow];
			data.judgeId = m_col2id[nCol];
						
			m_gridMarks->GetCellValue(nRow, nCol).ToULong((unsigned long *)&data.nMark);
			
			long found = CChampionshipJudgesMarkTable(m_pCon).FindId(id, data);

			__info("Row: %d, Col: %d, tourId: %d, teamId: %d, FOUND: %d == %d", nRow, nCol, data.tourId, data.teamId, found, UDF_E_NOTFOUND);
			if(UDF_OK == found)
			{
				__info("Found! ID: %d. Update it...", id);
				CChampionshipJudgesMarkTable(m_pCon).UpdateRow(id, data);
			}
			else if(found == UDF_E_NOTFOUND)
			{
				__info("NOT Found! Insert it...");
				CChampionshipJudgesMarkTable(m_pCon).AddRow(data);
			}
		}
	}
	Leave();
}

