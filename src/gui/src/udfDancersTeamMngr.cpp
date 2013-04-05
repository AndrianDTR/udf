#include "udfDancersTeamMngr.h"

#include "udfcommon.h"
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
			m_comboCsCategories->Insert(catName, nPos, (void*)&it->first);
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

	m_comboDancers->Clear();
	CDancersTable::tTableIt it = m_Dancers.begin();
	while(it != m_Dancers.end())
	{
		int nPos = m_comboDancers->GetCount();
		CDancersTable::tDATA& data = it->second;

		wxString dancerName = GetDancerNameById(data.id);
		if(!dancerName.IsEmpty())
		{
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

		wxString catName = GetCsCategoryNameById(data.csCatId);
		if(!catName.IsEmpty())
		{
			int nPos = m_listTeamCategories->GetCount();
			m_listTeamCategories->Insert(
				STR_FORMAT(STR_FORMAT_TEAM_CATEGORY_NAME, catName, data.compositionName),
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

		if(m_listDancers->GetCount())
			m_comboClub->Disable();
		else
			m_comboClub->Enable();
	}while(0);
}

void udfDancersTeamMngr::OnAddTeam( wxCommandEvent& event )
{
	do
	{
		CChampionshipTeamsTable table(m_pCon);
		CChampionshipTeamsTable::tDATA data = {0};
		data.championshipId = m_nCSId;

		int nClub = GetSelectedClub();
		if(-1 == nClub)
			break;
		data.clubId = *(int*)m_comboClub->GetClientData(nClub);

		data.name = m_textName->GetValue();
		data.id = -m_listTeams->GetCount();

		int nPos = m_listTeams->GetCount();
		if(UDF_OK != table.AddRow(data))
		{
			ShowWarning(STR_ERR_ADD_TEAM_FAILED);
			break;
		}
		CChampionshipTeamsTable::tTableIt item =
			m_CsTeams.insert(std::make_pair(data.id, data)).first;
		nPos = m_listTeams->Insert(data.name, nPos, (void*)&item->first);
		m_listTeams->SetSelection(nPos);

		RefreshDancers(data.clubId);
		m_comboClub->Enable();

		m_listDancers->Clear();
		m_CsTmDancers.clear();

		m_listTeamCategories->Clear();
		m_CsTmCats.clear();

	}while(0);
}

void udfDancersTeamMngr::OnRemoveTeam( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listTeams->GetSelection();
		if(-1 == nItem)
			break;

		int nId = *(int*)m_listTeams->GetClientData(nItem);

		RemoveTeamData(nId);

		if(UDF_OK != CChampionshipTeamsTable(m_pCon).DelRow(nId))
		{
			ShowWarning(STR_ERR_DEL_TEAM_FAILED);
			break;
		}
		m_CsTeams.erase(nId);
		m_listTeams->Delete(nItem);
	}while(0);
}

void udfDancersTeamMngr::OnUpdate( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listTeams->GetSelection();
		if(-1 == nItem)
			break;

		int nId = *(int*)m_listTeams->GetClientData(nItem);

		int nClub = GetSelectedClub();
		if(-1 == nClub)
			break;

		CChampionshipTeamsTable::tTableIt tItem = m_CsTeams.find(nId);
		if(tItem == m_CsTeams.end())
			break;

		CChampionshipTeamsTable::tDATA& tData = tItem->second;
		tData.clubId = *(int*)m_comboClub->GetClientData(nClub);
		tData.name = m_textName->GetValue();
		m_listTeams->SetString(nItem, tData.name);
		CChampionshipTeamsTable(m_pCon).UpdateRow(nId, tData);

		CChampionshipTeamCategoriesTable cTable(m_pCon);
		CChampionshipTeamCategoriesTable::tTableMap cStored;
		CChampionshipTeamCategoriesTable::tDATA cFilter = {0};
		cFilter.teamId = nId;
		cTable.Find(cStored, cFilter);

		CChampionshipTeamCategoriesTable::tTableIt cListIt = cStored.begin();
		while(cListIt != cStored.end())
		{
			CChampionshipTeamCategoriesTable::tTableIt cRLstIt = m_CsTmCats.find(cListIt->first);
			if(cRLstIt == m_CsTmCats.end())
			{
				cTable.DelRow(cListIt->first);
			}
			else if(cRLstIt != m_CsTmCats.end() && cRLstIt->first == cListIt->first)
			{
				CChampionshipTeamCategoriesTable::tDATA& cSData = cListIt->second;
				CChampionshipTeamCategoriesTable::tDATA& cData = cRLstIt->second;
				if( cSData.csCatId != cData.csCatId
				 || cSData.compositionName != cData.compositionName
				)
				{
					cSData.csCatId = cData.csCatId;
					cSData.compositionName = cData.compositionName;
					cTable.UpdateRow(cListIt->first, cSData);
				}
				m_CsTmCats.erase(cRLstIt);
			}
			cListIt++;
		}

		if(m_CsTmCats.size() > 0)
		{
			//insert data here
			CChampionshipTeamCategoriesTable::tTableIt cRLstIt = m_CsTmCats.begin();
			while(cRLstIt != m_CsTmCats.end())
			{
				CChampionshipTeamCategoriesTable::tDATA& cData = cRLstIt->second;
				cTable.AddRow(cData);
				cRLstIt++;
			}
		}

		CChampionshipTeamDancersTable dTable(m_pCon);
		CChampionshipTeamDancersTable::tTableMap dStored;
		CChampionshipTeamDancersTable::tDATA dFilter = {0};
		dFilter.teamId = nId;
		dTable.Find(dStored, dFilter);

		CChampionshipTeamDancersTable::tTableIt dListIt = dStored.begin();
		while(dListIt != dStored.end())
		{
			CChampionshipTeamDancersTable::tTableIt dRLstIt = m_CsTmDancers.find(dListIt->first);
			if(dRLstIt == m_CsTmDancers.end())
			{
				dTable.DelRow(dListIt->first);
			}
			else if(dRLstIt != m_CsTmDancers.end() && dRLstIt->first == dListIt->first)
			{
				CChampionshipTeamDancersTable::tDATA& dSData = dListIt->second;
				CChampionshipTeamDancersTable::tDATA& dData = dRLstIt->second;
				if( dSData.dancerId != dData.dancerId)
				{
					dSData.dancerId = dData.dancerId;
					dTable.UpdateRow(dListIt->first, dSData);
				}
				m_CsTmDancers.erase(dRLstIt);
			}
			dListIt++;
		}

		if(m_CsTmDancers.size() > 0)
		{
			//insert data here
			CChampionshipTeamDancersTable::tTableIt dRLstIt = m_CsTmDancers.begin();
			while(dRLstIt != m_CsTmDancers.end())
			{
				CChampionshipTeamDancersTable::tDATA& dData = dRLstIt->second;
				dTable.AddRow(dData);
				dRLstIt++;
			}
		}

	}while(0);
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
		data.csCatId = *(int*)m_comboCsCategories->GetClientData(nCat);
		data.teamId = *(int*)m_listTeams->GetClientData(nTeam);

		wxString cat = GetCsCategoryNameById(data.csCatId);


		wxArrayString names = m_listTeamCategories->GetStrings();
		int i = 0;
		bool found = false;
		for(i = 0; i < names.GetCount(); ++i)
		{
			if(names[i].StartsWith(cat))
			{
				found = true;
				break;
			}
		}
		if(found)
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
		m_listTeamCategories->Insert(STR_FORMAT(STR_FORMAT_TEAM_CATEGORY_NAME, cat, data.compositionName)
			, nPos, (void*)&item->first);
		//*/
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

		int nId = *(int*)m_listTeamCategories->GetClientData(nCat);
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

		if(m_listDancers->GetCount())
			m_comboClub->Disable();
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

		if(m_listDancers->GetCount())
			m_comboClub->Disable();
		else
			m_comboClub->Enable();

	}while(0);
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
	int res = -1;
	do
	{
		wxString value = m_comboClub->GetValue();
		res = m_comboClub->FindString(value);
		if(-1 == res)
		{
			ShowWarning(STR_FORMAT(STR_NOT_IN_DB, STR_CLUB));
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
			ShowWarning(STR_FORMAT(STR_NOT_IN_DB, STR_CATEGORY));
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
			ShowWarning(STR_FORMAT(STR_NOT_IN_DB, STR_DANCER));
			break;
		}
	}while(0);

	return res;
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
		cListIt++;
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
		dListIt++;
	}
}

void udfDancersTeamMngr::OnClubChanged(wxCommandEvent& event)
{
	do
	{
		int nClub = GetSelectedClub();
		if(-1 == nClub)
			break;
		int nClubId = *(int*)m_comboClub->GetClientData(nClub);

		RefreshDancers(nClubId);

	}while(0);
}
