#include "udfJudgeMark.h"

#include "string_def.h"

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
	
	m_bpGood->Enable(bEditable);
	m_bpBed->Enable(bEditable);
}

void udfJudgeMark::RefreshTeams()
{
	m_Teams.clear();
	m_listNumbers->Clear();
	
	CChampionshipTeamsTable::tDATA filter = {0};
	filter.championshipId = m_nCsId;
	CChampionshipTeamsTable(m_pCon).Find(m_Teams, filter);
	
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

void udfJudgeMark::OnSelectJudge( wxCommandEvent& event )
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
}

void udfJudgeMark::OnSelectTeam( wxCommandEvent& event )
{
	// TODO: Implement OnSelectTeam
}

void udfJudgeMark::OnShowAll( wxCommandEvent& event )
{
	// TODO: Implement OnShowAll
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

void udfJudgeMark::RefreshJudges()
{
}

void udfJudgeMark::RefreshMarks()
{
}

