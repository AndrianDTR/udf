#include "udfDancersTeamMngr.h"

#include "common.h"
#include "string_def.h"

#include "udfexceptions.h"

#include "udfClubsMngrDlg.h"
#include "udfCategoriesMngrDlg.h"
#include "udfDancersMngrDlg.h"

udfDancersTeamMngr::udfDancersTeamMngr( wxWindow* parent, unsigned int nId )
: DancersTeamMngr( parent )
, m_pCon(NULL)
, m_nCSId(nId)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshList();
	RefreshClubs();
	RefreshCategories();
	
	m_listTeams->SetSelection(0);
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
	udfClubsMngrDlg clubs(this);
	CClubsTable(m_pCon).GetTable(m_Clubs);
		
	m_comboClub->Clear();
	CClubsTable::tTableIt it = m_Clubs.begin();
	while(it != m_Clubs.end())
	{
		int nPos = m_comboClub->GetCount();
		wxString club;
		
		if(clubs.GetNameById(it->first, club))
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
	udfCategoriesMngrDlg catDlg(this);
	
	CChampionshipCategoriesTable table(m_pCon);
	CChampionshipCategoriesTable::tDATA filter = {0};
	filter.championshipId = m_nCSId;
	table.Find(m_CsCategories, filter);
	
	m_comboCsCategories->Clear();
	CChampionshipCategoriesTable::tTableIt it = m_CsCategories.begin();
	while(it != m_CsCategories.end())
	{
		int nPos = m_comboCsCategories->GetCount();
		CChampionshipCategoriesTable::tDATA& data = it->second;
		
		wxString catName;
		if(catDlg.GetNameById(data.catId, catName))
		{
			m_comboCsCategories->Insert(catName, nPos, (void*)&data.catId);
		}
		
		it++;
	}
	m_comboCsCategories->AutoComplete(m_comboCsCategories->GetStrings());
}

void udfDancersTeamMngr::RefreshDancers(int clubId)
{
	CDancersTable table(m_pCon);
	CDancersTable::tDATA filter = {0};
	filter.clubId = clubId;
	table.Find(m_Dancers, filter);
}

void udfDancersTeamMngr::RefreshTeamCategories(int teamId)
{
	udfCategoriesMngrDlg catDlg(this);
	CChampionshipTeamCategoriesTable table(m_pCon);
	CChampionshipTeamCategoriesTable::tDATA filter = {0};
	filter.teamId = teamId;
	table.Find(m_CsTmCats, filter);
	
	m_listTeamCategories->Clear();
	CChampionshipTeamCategoriesTable::tTableIt item;
	for(item = m_CsTmCats.begin(); item != m_CsTmCats.end(); item++)
	{
		CChampionshipTeamCategoriesTable::tDATA& data = item->second;
		
		wxString catName;
		if(catDlg.GetNameById(data.catId, catName))
		{
			int nPos = m_listTeamCategories->GetCount();
			m_listTeamCategories->Insert(
				wxString::Format(STF_FORMAT_TEAM_CATEGORY_NAME, catName, data.compositionName),
				nPos , (void*)&item->first);
		}
	}
}

void udfDancersTeamMngr::RefreshTeamDancers(int teamId, int clubId)
{
	udfDancersMngrDlg dancers(this, clubId);
	CChampionshipTeamDancersTable table(m_pCon);
	CChampionshipTeamDancersTable::tDATA filter = {0};
	filter.teamId = teamId;
	table.Find(m_CsTmDancers, filter);
	
	m_listDancers->Clear();
	CChampionshipTeamDancersTable::tTableIt item;
	for(item = m_CsTmDancers.begin(); item != m_CsTmDancers.end(); item++)
	{
		CChampionshipTeamDancersTable::tDATA& data = item->second;
		
		wxString dancerName;
		if(dancers.GetNameById(data.dancerId, dancerName))
		{
			int nPos = m_listDancers->GetCount();
			m_listDancers->Insert(dancerName, nPos, (void*)&item->first);
		}
	}
}

void udfDancersTeamMngr::OnSearch( wxCommandEvent& event )
{
	wxString search = m_textSearch->GetValue().Upper();
	CChampionshipTeamsTable::tTableIt item;
	
	m_listTeams->Clear();
	for(item = m_CsTeams.begin(); item != m_CsTeams.end(); item++)
	{
		CChampionshipTeamsTable::tDATA& data = item->second;
		
		if(wxString(data.name).Upper().Contains(search))
		{
			int pos = m_listTeams->GetCount();
			m_listTeams->Insert(data.name, pos, (void*)&item->first);
		}
	}
}

void udfDancersTeamMngr::OnSelectTeam(wxCommandEvent& event)
{
	do
	{
		int nItem = m_listTeams->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listTeams->GetClientData(nItem);
		
		CChampionshipTeamsTable::tTableIt it = m_CsTeams.find(nId);
		if(it == m_CsTeams.end())
			break;
		
		CChampionshipTeamsTable::tDATA& data = it->second;
		m_textName->SetValue(data.name);
		
		wxString clubName;
		udfClubsMngrDlg clubsDlg(this);
		if(clubsDlg.GetNameById(data.clubId, clubName))
		{
			int nPos = m_comboClub->FindString(clubName);
			m_comboClub->SetSelection(nPos);
		}
			
		RefreshTeamCategories(data.id);
		RefreshTeamDancers(data.id, data.clubId);
	}while(0);
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
