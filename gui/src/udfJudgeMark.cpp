#include "udfJudgeMark.h"

#include "string_def.h"

#include "common.h"

#include "udfexceptions.h"
#include "udfuiutils.h"

udfJudgeMark::udfJudgeMark( wxWindow* parent, unsigned int nCsId, unsigned int nCsTourId, bool bEditable )
: JudgeMark( parent )
, m_pCon(NULL)
, m_nCsId(nCsId)
, m_nCsTourId(nCsTourId)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshTeams();
	RefreshJudges();
	RefreshMarks();
	
	m_bpGood->Enable(bEditable);
	m_bpBed->Enable(bEditable);
}

void udfJudgeMark::RefreshTeams()
{
	m_Teams.clear();
	CChampionshipTeamsTable::tDATA filter = {0};
	filter.championshipId = m_nCsId;
	CChampionshipTeamsTable(m_pCon).Find(m_Teams, filter);
	
	CChampionshipTeamsTable::tTableIt it = m_Teams.begin();
	while(it != m_Teams.end())
	{
		m_TeamMarkList.insert(std::make_pair(it->first, -1));
		
		it++;
	}
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
			tTeamMarkIt markIt = m_TeamMarkList.find(data.teamId);
			if(markIt != m_TeamMarkList.end())
			{
				markIt->second = data.nMark;
			}
			mIt++;
		}
		
		CChampionshipTeamsTable::tTableIt tIt = m_Teams.begin();
		while(tIt != m_Teams.end())
		{
			tTeamMarkIt markIt = m_TeamMarkList.find(tIt->first);
			if(m_checkShowAll->GetValue() || markIt == m_TeamMarkList.end())
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

void udfJudgeMark::OnSelectTeam( wxCommandEvent& event )
{
	// TODO: Implement OnSelectTeam
}

void udfJudgeMark::OnShowAll( wxCommandEvent& event )
{
	RefreshMarks();
}

void udfJudgeMark::OnSearch( wxCommandEvent& event )
{
	// TODO: Implement OnSearch
}

void udfJudgeMark::OnPlus( wxCommandEvent& event )
{
	// TODO: Implement OnPlus
}

void udfJudgeMark::OnMinus( wxCommandEvent& event )
{
	// TODO: Implement OnMinus
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
