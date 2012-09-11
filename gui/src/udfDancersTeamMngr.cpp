#include "udfDancersTeamMngr.h"

#include "common.h"
#include "string_def.h"

#include "udfexceptions.h"
#include "udfuiutils.h"

#include "udfAddTeamCategory.h"

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
	CClubsTable(m_pCon).GetTable(m_Clubs);
		
	m_comboClub->Clear();
	CClubsTable::tTableIt it = m_Clubs.begin();
	while(it != m_Clubs.end())
	{
		int nPos = m_comboClub->GetCount();
		
		wxString clubName = GetClubNameById(it->first);
		if(!clubName.IsEmpty())
		{
			m_comboClub->Insert(clubName, nPos, (void*)&it->first);
		}
		
		it++;
	}
	m_comboClub->AutoComplete(m_comboClub->GetStrings());
}

void udfDancersTeamMngr::RefreshCategories()
{
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
		
		wxString catName = GetCategoryNameById(data.catId);
		if(!catName.IsEmpty())
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
	
	DEBUG_PRINTF("========= CLUB %d", clubId);
	m_comboDancers->Clear();
	CDancersTable::tTableIt it = m_Dancers.begin();
	while(it != m_Dancers.end())
	{
		int nPos = m_comboDancers->GetCount();
		CDancersTable::tDATA& data = it->second;
		DEBUG_PRINTF("========= Dancer %d", it->first);
		wxString dancerName = GetDancerNameById(data.id);
		if(!dancerName.IsEmpty())
		{
			DEBUG_PRINTF("========= INSERT COMBO %d", data.id);
			m_comboDancers->Insert(dancerName, nPos, (void*)&it->first);
		}
		
		it++;
	}
	m_comboDancers->AutoComplete(m_comboDancers->GetStrings());
}

void udfDancersTeamMngr::RefreshTeamCategories(int teamId)
{
	CChampionshipTeamCategoriesTable table(m_pCon);
	CChampionshipTeamCategoriesTable::tDATA filter = {0};
	filter.teamId = teamId;
	table.Find(m_CsTmCats, filter);
	
	m_listTeamCategories->Clear();
	CChampionshipTeamCategoriesTable::tTableIt item;
	for(item = m_CsTmCats.begin(); item != m_CsTmCats.end(); item++)
	{
		CChampionshipTeamCategoriesTable::tDATA& data = item->second;
		
		wxString catName = GetCategoryNameById(data.catId);
		if(!catName.IsEmpty())
		{
			int nPos = m_listTeamCategories->GetCount();
			m_listTeamCategories->Insert(
				wxString::Format(STF_FORMAT_TEAM_CATEGORY_NAME, catName, data.compositionName),
				nPos, (void*)&item->first);
		}
	}
}

void udfDancersTeamMngr::RefreshTeamDancers(int teamId, int clubId)
{
	CChampionshipTeamDancersTable table(m_pCon);
	CChampionshipTeamDancersTable::tDATA filter = {0};
	filter.teamId = teamId;
	table.Find(m_CsTmDancers, filter);
	
	m_listDancers->Clear();
	CChampionshipTeamDancersTable::tTableIt item;
	for(item = m_CsTmDancers.begin(); item != m_CsTmDancers.end(); item++)
	{
		CChampionshipTeamDancersTable::tDATA& data = item->second;
		
		wxString dancerName = GetDancerNameById(data.dancerId);
		if(!dancerName.IsEmpty())
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
		
		wxString clubName = GetClubNameById(data.clubId);
		if(!clubName.IsEmpty())
		{
			int nPos = m_comboClub->FindString(clubName);
			m_comboClub->SetSelection(nPos);
		}
			
		RefreshTeamCategories(data.id);
		RefreshDancers(data.clubId);
		RefreshTeamDancers(data.id, data.clubId);
		
		EnableEditTeam();
	}while(0);
}

void udfDancersTeamMngr::OnAddDancerTeam( wxCommandEvent& event )
{
	do
	{
		CChampionshipTeamsTable table(m_pCon);
		CChampionshipTeamsTable::tDATA data = {0};
		data.championshipId = m_nCSId;
		
		if(!ValidateData())
			break;
		
		int nClub = GetSelectedClub();
		if(-1 == nClub)
			break;
		data.clubId = *(int*)m_comboClub->GetClientData(nClub);
		
		data.name = m_textName->GetValue();
		data.id = -m_listTeams->GetCount();
		
		int nPos = m_listTeams->GetCount();
		CChampionshipTeamsTable::tTableIt item = 
			m_CsTeams.insert(std::make_pair(data.id, data)).first;
		nPos = m_listTeams->Insert(data.name, nPos, (void*)&item->first);
		m_listTeams->SetSelection(nPos);
		
		EnableEditTeam();
		
	}while(0);
}

void udfDancersTeamMngr::OnRemoveTancerTeam( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveTancerTeam
}

void udfDancersTeamMngr::OnAddDancerTeamCategory( wxCommandEvent& event )
{
	do
	{
		CChampionshipTeamCategoriesTable::tDATA data = {0};
		
		int nTeam = m_listTeams->GetSelection();
		if(-1 == nTeam)
		{
			break;
		}
		
		int nCat = GetSelectedCategory();
		if(-1 == nCat)
		{
			break;
		}
		
		int nPos = m_listTeamCategories->GetCount();
		data.id = -(nPos * nTeam);
		data.catId = *(int*)m_comboCsCategories->GetClientData(nCat);
		data.teamId = *(int*)m_listTeams->GetClientData(nTeam);
		
		wxString cat = GetCategoryNameById(data.catId);
		
		if(-1 != m_listTeamCategories->FindString(cat))
		{
			ShowWarning(STR_WARN_ALREADY_PRESENT);
			break;
		}
		
		udfAddTeamCategory dlg(this, cat);
		if(wxID_OK != dlg.ShowModal())
			break;
			
		data.compositionName = dlg.GetCompisitionName();
		
		CChampionshipTeamCategoriesTable::tTableIt item = 
			m_CsTmCats.insert(std::make_pair(data.id, data)).first;
		m_listTeamCategories->Insert(wxString::Format(STF_FORMAT_TEAM_CATEGORY_NAME, cat, data.compositionName), nPos, (void*)&item->first);
	}while(0);
}

void udfDancersTeamMngr::OnRemoveDancerTeamCategory( wxCommandEvent& event )
{
	do
	{
		int nCat = m_listTeamCategories->GetSelection();
		if(-1 == nCat)
		{
			break;
		}
		
		int nId = *(int*)m_listDancers->GetClientData(nCat);
		m_CsTmCats.erase(nId);
		m_listTeamCategories->Delete(nCat);
		
	}while(0);
}

void udfDancersTeamMngr::OnAddDancer2Team( wxCommandEvent& event )
{
	do
	{
		CChampionshipTeamDancersTable::tDATA data = {0};
		
		int nTeam = m_listTeams->GetSelection();
		if(-1 == nTeam)
		{
			break;
		}
		
		int nDancer = GetSelectedDancer();
		if(-1 == nDancer)
		{
			break;
		}
		
		int nPos = m_listDancers->GetCount();
		data.id = -(nPos * nTeam);
		data.dancerId = *(int*)m_comboDancers->GetClientData(nDancer);
		data.teamId = *(int*)m_listTeams->GetClientData(nTeam);
		
		wxString dancer = GetDancerNameById(data.dancerId);
		
		if(-1 != m_listDancers->FindString(dancer))
		{
			ShowWarning(STR_WARN_ALREADY_PRESENT);
			break;
		}

		CChampionshipTeamDancersTable::tTableIt item = 
			m_CsTmDancers.insert(std::make_pair(data.id, data)).first;
		m_listDancers->Insert(dancer, nPos, (void*)&item->first);
	}while(0);
}

void udfDancersTeamMngr::OnRemoveDancerFromTeam( wxCommandEvent& event )
{
	do
	{
		int nDancer = m_listDancers->GetSelection();
		if(-1 == nDancer)
		{
			break;
		}
		
		int nId = *(int*)m_listDancers->GetClientData(nDancer);
		m_CsTmDancers.erase(nId);
		m_listDancers->Delete(nDancer);
		
	}while(0);
}

void udfDancersTeamMngr::OnSave( wxCommandEvent& event )
{
	CChampionshipTeamsTable table(m_pCon);
	CChampionshipTeamsTable::tTableMap stored;
	CChampionshipTeamsTable::tDATA filter = {0};
	filter.championshipId = m_nCSId;
	table.Find(stored, filter);
		
	CChampionshipTeamsTable::tTableIt listIt = stored.begin();
	while(listIt != stored.end())
	{
		CChampionshipTeamsTable::tTableIt rLstIt = m_CsTeams.find(listIt->first);
		if(rLstIt == m_CsTeams.end())
		{
			RemoveTeamData(listIt->first);
			table.DelRow(listIt->first);
		}
		else if(rLstIt != m_CsTeams.end() && rLstIt->first == listIt->first)
		{
			CChampionshipTeamsTable::tDATA& data = listIt->second;
			CChampionshipTeamsTable::tDATA& cData = rLstIt->second;
			
			if( data.name != cData.name)
			{
				data.name = cData.name;
				table.UpdateRow(listIt->first, data);
			}
			UpdateTeamData(listIt->first);
			m_CsTeams.erase(rLstIt);
		}
		listIt++;
	}
	
	if(m_CsTeams.size() > 0)
	{
		CChampionshipTeamsTable::tTableIt rLstIt = m_CsTeams.begin();
		while(rLstIt != m_CsTeams.end())
		{
			CChampionshipTeamsTable::tDATA& data = rLstIt->second;
			table.AddRow(data);
			AddTeamData(rLstIt->first, data.id);
			rLstIt++;
		}
	}
	
	EndModal(wxID_OK);
}

void udfDancersTeamMngr::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

int udfDancersTeamMngr::GetSelectedClub()
{
	int res = -1;
	do
	{
		wxString value = m_comboClub->GetValue();
		res = m_comboClub->FindString(value);
		if(-1 == res)
		{
			ShowWarning(wxString::Format(STR_NOT_IN_DB, STR_CLUB));
			break;
		}
	}while(0);
	
	return res;
}

int udfDancersTeamMngr::GetSelectedCategory()
{
	int res = -1;
	do
	{
		wxString value = m_comboCsCategories->GetValue();
		res = m_comboCsCategories->FindString(value);
		if(-1 == res)
		{
			ShowWarning(wxString::Format(STR_NOT_IN_DB, STR_CATEGORY));
			break;
		}
	}while(0);
	
	return res;
}

int udfDancersTeamMngr::GetSelectedDancer()
{
	int res = -1;
	do
	{
		wxString value = m_comboDancers->GetValue();
		res = m_comboDancers->FindString(value);
		if(-1 == res)
		{
			ShowWarning(wxString::Format(STR_NOT_IN_DB, STR_DANCER));
			break;
		}
	}while(0);
	
	return res;
}

bool udfDancersTeamMngr::GetSelectedItemData(CDancersTable::tDATA*& pData)
{
}

void udfDancersTeamMngr::OnClubChanged(wxCommandEvent& event)
{
	do
	{
		wxString value = m_comboClub->GetValue();
		int nClub = m_comboClub->FindString(value);
		if(-1 == nClub)
			break;
			
		int nId = *(int*)m_comboClub->GetClientData(nClub);
		RefreshDancers(nId);
	
	}while(0);
}

void udfDancersTeamMngr::OnSelectClub(wxCommandEvent& event)
{
}

bool udfDancersTeamMngr::ValidateData()
{
	return true;
}

void udfDancersTeamMngr::EnableEditTeam(bool bEdit)
{
	m_comboCsCategories->Enable(bEdit);
	m_listTeamCategories->Enable(bEdit);
	m_bpAddDancerTeamCategory->Enable(bEdit);
	m_bpRemoveDancerTeamCategory->Enable(bEdit);
	
	m_comboDancers->Enable(bEdit);
	m_listDancers->Enable(bEdit);
	m_bpAddDancerTeamDancer->Enable(bEdit);
	m_bpRemoveDancerTeamDancer->Enable(bEdit);
	
	m_comboClub->Enable(!bEdit);
}

void udfDancersTeamMngr::AddTeamData(int nTeamId, int nInsertedTeamId)
{
}

void udfDancersTeamMngr::RemoveTeamData(int nTeamId)
{
	CChampionshipTeamCategoriesTable cTable(m_pCon);
	CChampionshipTeamCategoriesTable::tTableMap cStored;
	CChampionshipTeamCategoriesTable::tDATA cFilter = {0};
	cFilter.teamId = nTeamId;
	cTable.Find(cStored, cFilter);
	
	CChampionshipTeamCategoriesTable::tTableIt cListIt = cStored.begin();
	while(cListIt != cStored.end())
	{
		cTable.DelRow(cListIt->first);
	}
	
	CChampionshipTeamDancersTable dTable(m_pCon);
	CChampionshipTeamDancersTable::tTableMap dStored;
	CChampionshipTeamDancersTable::tDATA dFilter = {0};
	dFilter.teamId = nTeamId;
	dTable.Find(dStored, dFilter);
	
	CChampionshipTeamDancersTable::tTableIt dListIt = dStored.begin();
	while(dListIt != dStored.end())
	{
		dTable.DelRow(dListIt->first);
	}
}

void udfDancersTeamMngr::UpdateTeamData(int nTeamId)
{
	CChampionshipTeamCategoriesTable cTable(m_pCon);
	CChampionshipTeamCategoriesTable::tTableMap cStored;
	CChampionshipTeamCategoriesTable::tDATA cFilter = {0};
	cFilter.teamId = nTeamId;
	cTable.Find(cStored, cFilter);
	
	CChampionshipTeamCategoriesTable::tTableIt cListIt = cStored.begin();
	while(cListIt != cStored.end())
	{
		//Update category info for team
	}
	
	CChampionshipTeamDancersTable dTable(m_pCon);
	CChampionshipTeamDancersTable::tTableMap dStored;
	CChampionshipTeamDancersTable::tDATA dFilter = {0};
	dFilter.teamId = nTeamId;
	dTable.Find(dStored, dFilter);
	
	CChampionshipTeamDancersTable::tTableIt dListIt = dStored.begin();
	while(dListIt != dStored.end())
	{
		//Update dancer info for team
	}
}

