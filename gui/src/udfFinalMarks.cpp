#include "udfFinalMarks.h"

#include "db.h"

#include "udfsettingsbase.h"

#include "udfuicommon.h"
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
	
	int scale = udfSettingsBase::Instance()->GetFinalMarksScale();
	m_spinScale->SetValue(scale);
	m_fntSize = m_gridMarks->GetDefaultCellFont().GetPointSize();
	
	if(UDF_OK == GetTourCategoryId(tourId, catId))
		m_catId = catId;

	RefreshGrid();
}

void udfFinalMarks::OnSave( wxCommandEvent& event )
{
	if(Validate())
	{
		UpdateMarks();
		EndModal(wxID_OK);
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
	
	bool res = true;
	do
	{
		int col = 0;
		for(col = 0; col < m_gridMarks->GetNumberCols(); ++col)
		{
			int row = 0;
			for(row = 0; row < m_gridMarks->GetNumberRows(); ++row)
			{
				wxString m1 = m_gridMarks->GetCellValue(row, col);
				int mark = row + 1;
				for(mark = row + 1; mark < m_gridMarks->GetNumberRows(); ++mark)
				{
					wxString m2 = m_gridMarks->GetCellValue(mark, col);
					
					if(m1[0] == m2[0])
					{
						__info("INVALID");
						m_gridMarks->SetCellBackgroundColour(mark, col, wxColour(255,0,0));
						
						res = false;
					}
				}
			}
		}
	}while(0);
	
	if(res == false)
	{
		m_gridMarks->Refresh();
	}
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
						
			long found = CChampionshipJudgesMarkTable(m_pCon).FindId(id, data);

			__info("Row: %d, Col: %d, tourId: %d, teamId: %d, FOUND: %d == %d", nRow, nCol, data.tourId, data.teamId, found, UDF_E_NOTFOUND);
			if(UDF_OK == found)
			{
				__info("Found! ID: %d. Update it...", id);
				m_gridMarks->GetCellValue(nRow, nCol).ToULong((unsigned long *)&data.nMark);
				CChampionshipJudgesMarkTable(m_pCon).UpdateRow(id, data);
			}
			else if(found == UDF_E_NOTFOUND)
			{
				__info("NOT Found! Insert it...");
				m_gridMarks->GetCellValue(nRow, nCol).ToULong((unsigned long *)&data.nMark);
				CChampionshipJudgesMarkTable(m_pCon).AddRow(data);
			}
		}
	}
	Leave();
}

void udfFinalMarks::OnKeyUp( wxKeyEvent& event )
{
	do
	{
		int col = m_gridMarks->GetGridCursorCol();
		int row = m_gridMarks->GetGridCursorRow();
		
		if( -1 == row || -1 == col)
			break;
		
		int key = event.GetKeyCode();
		switch(key)
		{
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				m_gridMarks->SetCellValue(row, col, wxString::Format(_("%c"), key));
				
				int nRow = 0;
				bool ok = true;
				for(nRow = 0; nRow < m_gridMarks->GetNumberRows(); nRow++)
				{
					if(row == nRow)
						continue;
					
					wxString m1 = wxString::Format(_("%d"), m_gridMarks->GetNumberRows());
					wxString m2 = m_gridMarks->GetCellValue(nRow, col);
					if(m1[0] < key || m2[0] == key )
					{
						m_gridMarks->SetCellBackgroundColour(row, col, wxColour(255,0,0));
						
						ok = false;
						break;
					}
					else
					{
						m_gridMarks->SetCellBackgroundColour(row, col, m_gridMarks->GetDefaultCellBackgroundColour());
					}
					m_gridMarks->Refresh();
				}
				
				if(ok)
					m_gridMarks->MoveCursorDown(false);
					
				break;
		}
		
	}while(0);
}

void udfFinalMarks::OnKeyDown( wxKeyEvent& event )
{
	int key = event.GetKeyCode();
	if(WXK_SPACE != key
	|| WXK_RETURN != key
	|| WXK_NUMPAD_ENTER != key)
	{
		event.Skip();
	}
}

void udfFinalMarks::OnScaleChange(wxSpinEvent& event)
{
	int scale = m_spinScale->GetValue();
	m_gridMarks->SetDefaultColSize(GRID_CELL_SIZE_DEFAULT * scale / 100);
	m_gridMarks->SetDefaultRowSize(GRID_CELL_SIZE_DEFAULT * scale / 100);
	wxFont fnt = m_gridMarks->GetDefaultCellFont();
	fnt.SetPointSize(m_fntSize * scale / 100);
	m_gridMarks->SetDefaultCellFont(fnt);
	m_gridMarks->ForceRefresh();
	udfSettingsBase::Instance()->SetFinalMarksScale(scale);
}