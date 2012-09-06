#include "udfDancersTeamMngr.h"

#include "common.h"
#include "string_def.h"

#include "udfexceptions.h"

#include "udfClubsMngrDlg.h"

udfDancersTeamMngr::udfDancersTeamMngr( wxWindow* parent, unsigned int nId )
: DancersTeamMngr( parent )
, m_pCon(NULL)
, m_nCSId(nId)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshList();
	RefreshClubs();
	RefreshCategories();
	
}

void udfDancersTeamMngr::RefreshList()
{
	CChampionshipTeamsTable table(m_pCon);
	CChampionshipTeamsTable::tDATA filter = {0};
	filter.championshipId = m_nCSId;
	table.Find(m_CsTeams, filter);
	
	m_listTeams->Clear();
	
	CChampionshipTeamsTable::tTableIt it = m_CsTeams.begin();
	while(it != m_CsTeams.end())
	{
		CChampionshipTeamsTable::tDATA& data = it->second;
		int nPos = m_listTeams->GetCount();
		m_listTeams->Insert(data.name, nPos, (void*)&it->first);
		
		it++;
	}
}

void udfDancersTeamMngr::RefreshClubs()
{
	udfClubsMngrDlg pClubs(this);
	CClubsTable(m_pCon).GetTable(m_Clubs);
		
	m_comboClub->Clear();
	CClubsTable::tTableIt it = m_Clubs.begin();
	while(it != m_Clubs.end())
	{
		int nPos = m_comboClub->GetCount();
		wxString club;
		
		if(pClubs.GetNameById(it->first, club))
		{
			const char* name = club.GetData().AsChar();
			m_comboClub->Insert(club, nPos, (void*)&it->first);
		}
		
		it++;
	}
	m_comboClub->AutoComplete(m_comboClub->GetStrings());
}

void udfDancersTeamMngr::RefreshCategories()
{
	CCategoriesTable(m_pCon).GetTable(m_Categories);

	CChampionshipCategoriesTable table(m_pCon);
	CChampionshipCategoriesTable::tDATA filter = {0};
	filter.championshipId = m_nCSId;
	table.Find(m_CsCategories, filter);
}

void udfDancersTeamMngr::RefreshDancers()
{
}

void udfDancersTeamMngr::RefreshTeamCategories()
{
}

void udfDancersTeamMngr::OnAddDancerTeam( wxCommandEvent& event )
{
	// TODO: Implement OnAddDancerTeam
}

void udfDancersTeamMngr::OnRemoveTancerTeam( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveTancerTeam
}

void udfDancersTeamMngr::OnAddDancerTeamCategory( wxCommandEvent& event )
{
	// TODO: Implement OnAddDancerTeamCategory
}

void udfDancersTeamMngr::OnRemoveDancerTeamCategory( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveDancerTeamCategory
}

void udfDancersTeamMngr::OnAddDancerTeamDancer( wxCommandEvent& event )
{
	// TODO: Implement OnAddDancerTeamDancer
}

void udfDancersTeamMngr::OnRemoveDancerTeamDancer( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveDancerTeamDancer
}

void udfDancersTeamMngr::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfDancersTeamMngr::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

int udfDancersTeamMngr::GetSelectedClub()
{
}

bool udfDancersTeamMngr::GetSelectedItemData(CDancersTable::tDATA*& pData)
{
}

void udfDancersTeamMngr::OnClubChanged(wxCommandEvent& event)
{
}

void udfDancersTeamMngr::OnSelectClub(wxCommandEvent& event)
{
}

bool udfDancersTeamMngr::ValidateData()
{
}

