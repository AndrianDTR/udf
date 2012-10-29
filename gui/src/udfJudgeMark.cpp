#include "udfJudgeMark.h"

#include "string_def.h"

#include "udfcommon.h"

#include "udfexceptions.h"
#include "udfuiutils.h"

udfJudgeMark::udfJudgeMark( wxWindow* parent, unsigned int nCsId, unsigned int nCsTourId, bool bEditable )
: JudgeMark( parent )
, m_pCon(NULL)
, m_nCsId(nCsId)
, m_nCsTourId(nCsTourId)
, m_bEditable(bEditable)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshTeams();
	RefreshJudges();
	RefreshMarks();
	
	m_bpGood->Disable();
	m_bpBed->Disable();
	
	m_textSearch->SetFocus();
}

void udfJudgeMark::RefreshTeams()
{
	m_Teams.clear();
	CChampionshipTeamsTable::tDATA filter = {0};
	filter.championshipId = m_nCsId;
	CChampionshipTeamsTable(m_pCon).Find(m_Teams, filter);	
}

void udfJudgeMark::RefreshJudges()
{
	m_Judges.clear();
	m_comboJudge->Clear();
	
	CChampionshipJudgesTeamTable::tDATA filter = {0};
	filter.championshipId = m_nCsId;
	CChampionshipJudgesTeamTable(m_pCon).Find(m_Judges, filter);
	
	CChampionshipJudgesTeamTable::tTableIt it = m_Judges.begin();
	while(it != m_Judges.end())
	{
		CChampionshipJudgesTeamTable::tDATA& data = it->second;
		int nPos = m_comboJudge->GetCount();
		
		m_comboJudge->Insert(GetJudgeNameById(data.judgeId), nPos, (void*)&it->first);
		it++;
	}
	
	if(m_comboJudge->GetCount())
	{
		m_comboJudge->SetSelection(0);
		RefreshMarks();
	}
}

void udfJudgeMark::RefreshMarks()
{
	do
	{
		m_listNumbers->Clear();
		m_Marks.clear();
		m_TeamMarkList.clear();
		
		int nItem = m_comboJudge->GetSelection();
		if(nItem == -1)
			break;
		
		CChampionshipJudgesMarkTable::tDATA filter = {0};
		filter.championshipId = m_nCsId;
		filter.tourId = m_nCsTourId;
		filter.judgeId = *(int*)m_comboJudge->GetClientData(nItem);
		CChampionshipJudgesMarkTable(m_pCon).Find(m_Marks, filter);
		
		CChampionshipJudgesMarkTable::tTableIt mIt = m_Marks.begin();
		while(mIt != m_Marks.end())
		{
			CChampionshipJudgesMarkTable::tDATA data = mIt->second;
			m_TeamMarkList.insert(std::make_pair(data.teamId, data.nMark));
			mIt++;
		}
		
		CChampionshipTeamsTable::tTableIt tIt = m_Teams.begin();
		while(tIt != m_Teams.end())
		{
			if(m_checkShowAll->GetValue() 
			|| m_TeamMarkList.end() == m_TeamMarkList.find(tIt->first))
			{
				CChampionshipTeamsTable::tDATA& data = tIt->second;
				int nPos = m_listNumbers->GetCount();
				
				m_listNumbers->Insert(wxString::Format(STR_FORMAT_START_NUMBER, (unsigned long)data.startNumber)
					, nPos, (void*)&tIt->first);
			}
			
			tIt++;
		}
	}while(0);
}

void udfJudgeMark::OnSelectJudge( wxCommandEvent& event )
{
	do
	{
		RefreshMarks();
	}while(0);
}

void udfJudgeMark::OnSelectNumber( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listNumbers->GetSelection();
		if(nItem == -1)
			break;
		int nId = *(int*)m_listNumbers->GetClientData(nItem);
		
		if(m_bEditable)
		{
			m_bpBed->Enable();
			m_bpGood->Enable();
		}
		wxColor clr = GetBackgroundColour();
		m_panelPlus->SetBackgroundColour(clr);
		m_panelMinus->SetBackgroundColour(clr);
		
		tTeamMarkIt found = m_TeamMarkList.find(nId);
		if(found == m_TeamMarkList.end())
			break;
		
		m_bpBed->Disable();
		m_bpGood->Disable();
		
		int mark = (int)found->second;
		if(mark == 0)
		{
			m_panelMinus->SetBackgroundColour(wxColour( 255, 0, 0 ));
		}
		else if (mark == 1)
		{
			m_panelPlus->SetBackgroundColour(wxColour(0, 255, 0 ));
		}
	}while(0);
}

void udfJudgeMark::OnShowAll( wxCommandEvent& event )
{
	RefreshMarks();
}

void udfJudgeMark::OnSearch( wxCommandEvent& event )
{
	wxString search = m_textSearch->GetValue().Upper();
	
	m_listNumbers->Clear();
	CChampionshipTeamsTable::tTableIt tIt = m_Teams.begin();
	while(tIt != m_Teams.end())
	{
		if(m_checkShowAll->GetValue() 
		|| m_TeamMarkList.end() == m_TeamMarkList.find(tIt->first))
		{
			CChampionshipTeamsTable::tDATA& data = tIt->second;
			int nPos = m_listNumbers->GetCount();
			wxString num = wxString::Format(STR_FORMAT_START_NUMBER, (unsigned long)data.startNumber);
			if(num.StartsWith(search))
				m_listNumbers->Insert(num, nPos, (void*)&tIt->first);
		}
		
		tIt++;
	}
	
	if(0 < m_listNumbers->GetCount())
	{
		m_listNumbers->SetSelection(0);
	}
	else
	{
		m_bpBed->Disable();
		m_bpGood->Disable();
	}
	
	OnSelectNumber(event);
}

void udfJudgeMark::OnPlus( wxCommandEvent& event )
{
	do
	{
		int nTeam = m_listNumbers->GetSelection();
		if(nTeam == -1)
			break;
		int nTeamId = *(int*)m_listNumbers->GetClientData(nTeam);
		
		int nJudge = m_comboJudge->GetSelection();
		if(nJudge == -1)
			break;
		
		CChampionshipJudgesMarkTable::tDATA data = {0};
		data.championshipId = m_nCsId;
		data.tourId = m_nCsTourId;
		data.judgeId = *(int*)m_comboJudge->GetClientData(nJudge);
		data.teamId = nTeamId;
		
		// Set mark value
		data.nMark = 1;
		CChampionshipJudgesMarkTable(m_pCon).AddRow(data);
		m_TeamMarkList.insert(std::make_pair(nTeamId, 1));
		m_bpBed->Disable();
		m_bpGood->Disable();
		m_panelPlus->SetBackgroundColour(wxColour( 0, 255, 0 ));
		m_textSearch->SetValue("");
		m_textSearch->SetFocus();
	}while(0);
}

void udfJudgeMark::OnMinus( wxCommandEvent& event )
{
	do
	{
		int nTeam = m_listNumbers->GetSelection();
		if(nTeam == -1)
			break;
		int nTeamId = *(int*)m_listNumbers->GetClientData(nTeam);
		
		int nJudge = m_comboJudge->GetSelection();
		if(nJudge == -1)
			break;
		
		CChampionshipJudgesMarkTable::tDATA data = {0};
		data.championshipId = m_nCsId;
		data.tourId = m_nCsTourId;
		data.judgeId = *(int*)m_comboJudge->GetClientData(nJudge);
		data.teamId = nTeamId;
		
		// Set mark value
		data.nMark = 0;
		CChampionshipJudgesMarkTable(m_pCon).AddRow(data);
		m_TeamMarkList.insert(std::make_pair(nTeamId, 0));
		m_bpBed->Disable();
		m_bpGood->Disable();
		m_panelMinus->SetBackgroundColour(wxColour( 255, 0, 0 ));
		m_textSearch->SetValue("");
		m_textSearch->SetFocus();
	}while(0);
}

void udfJudgeMark::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfJudgeMark::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

bool udfJudgeMark::IsTeamMarked(unsigned int nTeamId)
{
	CChampionshipTeamsTable::tTableIt it = m_Teams.begin();
	while(it != m_Teams.end())
	{
		CChampionshipTeamsTable::tDATA& data = it->second;
		int nPos = m_listNumbers->GetCount();
		m_listNumbers->Insert(wxString::Format(STR_FORMAT_START_NUMBER, data.startNumber)
			, nPos, (void*)&it->first);
		it++;
	}
}
