#include "udfDancersMngrDlg.h"

#include "string_def.h"
#include "udfexceptions.h"

#include "udfClubsMngrDlg.h"
#include "udfTrainersMngrDlg.h"

#include "wx/msgdlg.h"

udfDancersMngrDlg::udfDancersMngrDlg( wxWindow* parent, unsigned int nClubId )
: DancersMngrDlg( parent )
, m_nClubId(nClubId)
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshList();
	RefreshClubs();
	RefreshTrainers();
	RefreshLigues();
	RefreshGenders();
}

void udfDancersMngrDlg::RefreshList()
{
	CDancersTable table(m_pCon);
	CDancersTable::tDATA filter = {0};
	filter.clubId = m_nClubId;
	table.Find(m_Dancers, filter);
	
	m_listDancers->Clear();
	
	CDancersTable::tTableIt it = m_Dancers.begin();
	while(it != m_Dancers.end())
	{
		CDancersTable::tDATA& data = it->second;
		int nPos = m_listDancers->GetCount();
		m_listDancers->Insert(data.name, nPos, (void*)&it->first);
		
		it++;
	}
}

void udfDancersMngrDlg::RefreshClubs()
{
	udfClubsMngrDlg* pClubs = (udfClubsMngrDlg*)GetParent();
	CClubsTable table(m_pCon);
	table.GetTable(m_Clubs);
		
	m_comboClub->Clear();
	CClubsTable::tTableIt it = m_Clubs.begin();
	while(it != m_Clubs.end())
	{
		int nPos = m_comboClub->GetCount();
		wxString club;
		if(pClubs->GetNameById(it->first, club))
			m_comboClub->Insert(club, nPos, (void*)&it->first);
		
		it++;
	}
	m_comboClub->AutoComplete(m_comboClub->GetStrings());
}

void udfDancersMngrDlg::RefreshLigues()
{
	CLigaTable(m_pCon).GetTable(m_Ligues);
	
	m_comboLiga->Clear();
	
	CLigaTable::tTableIt it = m_Ligues.begin();
	while(it != m_Ligues.end())
	{
		CLigaTable::tDATA& data = it->second;
		int nPos = m_comboLiga->GetCount();
		m_comboLiga->Insert(data.name, nPos, (void*)&it->first);
		
		it++;
	}
	m_comboLiga->AutoComplete(m_comboLiga->GetStrings());
}

void udfDancersMngrDlg::RefreshTrainers()
{
	udfTrainersMngrDlg pTrainer(GetParent(), m_nClubId);
	CTrainersTable::tDATA filter = {0};
	filter.clubId = m_nClubId;
	CTrainersTable(m_pCon).Find(m_Trainers, filter);
	
	m_comboTrainer->Clear();
	CTrainersTable::tTableIt it = m_Trainers.begin();
	while(it != m_Trainers.end())
	{
		int nPos = m_comboTrainer->GetCount();
		wxString name;
		if(pTrainer.GetNameById(it->first, name))
			m_comboTrainer->Insert(name, nPos, (void*)&it->first);
		
		it++;
	}
	m_comboTrainer->AutoComplete(m_comboTrainer->GetStrings());
}

void udfDancersMngrDlg::RefreshGenders()
{
	CGenderTable(m_pCon).GetTable(m_Gender);
	
	m_comboGender->Clear();
	
	CGenderTable::tTableIt it = m_Gender.begin();
	while(it != m_Gender.end())
	{
		CGenderTable::tDATA& data = it->second;
		int nPos = m_comboGender->GetCount();
		m_comboGender->Insert(data.name, nPos, (void*)&it->first);
		
		it++;
	}
	m_comboGender->AutoComplete(m_comboGender->GetStrings());
}

void udfDancersMngrDlg::OnSearch( wxCommandEvent& event )
{
	wxString search = m_textSearch->GetValue().Upper();
	CDancersTable::tTableIt item;
	
	m_listDancers->Clear();
	for(item = m_Dancers.begin(); item != m_Dancers.end(); item++)
	{
		CDancersTable::tDATA& data = item->second;
		
		if(wxString(data.name).Upper().Contains(search)
		|| wxString(data.regBook).Upper().Contains(search)
		|| wxString(data.additionalInfo).Upper().Contains(search)
		)
		{
			int pos = m_listDancers->GetCount();
			m_listDancers->Insert(data.name, pos, (void*)&item->first);
		}
	}
}

void udfDancersMngrDlg::OnDancerSelect( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listDancers->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listDancers->GetClientData(nItem);
		
		CDancersTable::tTableIt it = m_Dancers.find(nId);
		if(it == m_Dancers.end())
			break;
		
		CDancersTable::tDATA& data = it->second;
		m_textName->SetValue(data.name);
		m_textRegbook->SetValue(data.regBook);
		m_textInfo->SetValue(data.additionalInfo);
		m_staticRaiting->SetLabel(wxString::Format(_("%d"), data.raiting));
		
		wxString clubName;
		udfClubsMngrDlg* pClubs = (udfClubsMngrDlg*)GetParent();
		if(pClubs->GetNameById(data.clubId, clubName))
			m_comboClub->SetValue(clubName);
		
		wxString	trainerName;
		udfTrainersMngrDlg pTrainers(pClubs, m_nClubId);
		if(pTrainers.GetNameById(data.trainerId, trainerName))
			m_comboTrainer->SetValue(trainerName);
			
		CLigaTable::tDATA ligaData = {0};
		CLigaTable(m_pCon).GetRow(data.liga, ligaData);
		m_comboLiga->SetValue(ligaData.name);
		
		CGenderTable::tDATA genderData = {0};
		CGenderTable(m_pCon).GetRow(data.gender, genderData);
		m_comboGender->SetValue(genderData.name);
				
		m_dateBd->SetValue(wxDateTime(data.bd));
		m_datePay->SetValue(wxDateTime(data.pay_date));
		m_dateExp->SetValue(wxDateTime(data.exp_date));
		
		m_textReg->SetValue(wxDateTime(data.reg_date).Format(_("%d %m %Y")));
		
	}while(0);
}

void udfDancersMngrDlg::OnAddDancer( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listDancers->GetCount();
		
		if(! ValidateData())
			break;
		
		CDancersTable::tDATA data = {0};
		data.id = -nItem;
		data.clubId = *(int*)m_comboClub->GetClientData(GetSelectedClub());
		data.trainerId = *(int*)m_comboTrainer->GetClientData(GetSelectedTrainer());
		data.liga = *(int*)m_comboLiga->GetClientData(GetSelectedLigue());
		data.gender = *(int*)m_comboGender->GetClientData(GetSelectedGender());
		
		data.regBook = m_textRegbook->GetValue();
		data.name = m_textName->GetValue();
		data.additionalInfo = m_textInfo->GetValue();
		data.bd = m_dateBd->GetValue().GetTicks();
		data.pay_date = m_datePay->GetValue().GetTicks();
		data.exp_date = m_dateExp->GetValue().GetTicks();
		
		CDancersTable::tTableIt it = m_Dancers.insert(std::make_pair(data.id, data)).first;
		m_listDancers->Insert(data.name, nItem, (void*)&it->first);
		m_listDancers->SetSelection(nItem);
	}while(0);
}

void udfDancersMngrDlg::OnRemoveDancer( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listDancers->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listDancers->GetClientData(nItem);
				
		m_Dancers.erase(nId);
		m_listDancers->Delete(nItem);
	}while(0);
}

void udfDancersMngrDlg::OnUpdate( wxCommandEvent& event )
{
	do
	{
		CDancersTable::tDATA* pData = NULL;
		if(! GetSelectedItemData(pData))
			break;
		
		if(! ValidateData())
			break;
		
		int nItem = m_listDancers->FindString(pData->name, true);
		pData->clubId = *(int*)m_comboClub->GetClientData(GetSelectedClub());
		pData->trainerId = *(int*)m_comboTrainer->GetClientData(GetSelectedTrainer());
		pData->liga = *(int*)m_comboLiga->GetClientData(GetSelectedLigue());
		pData->gender = *(int*)m_comboGender->GetClientData(GetSelectedGender());
		
		pData->regBook = m_textRegbook->GetValue();
		pData->name = m_textName->GetValue();
		pData->additionalInfo = m_textInfo->GetValue();
		pData->bd = m_dateBd->GetValue().GetTicks();
		pData->pay_date = m_datePay->GetValue().GetTicks();
		pData->exp_date = m_dateExp->GetValue().GetTicks();
		
		m_listDancers->SetString(nItem, pData->name);
		
	}while(0);
}

void udfDancersMngrDlg::OnSave( wxCommandEvent& event )
{
	CDancersTable table(m_pCon);
	CDancersTable::tTableMap stored;
	table.GetTable(stored);
		
	CDancersTable::tTableIt listIt = stored.begin();
	while(listIt != stored.end())
	{
		CDancersTable::tTableIt rLstIt = m_Dancers.find(listIt->first);
		if(rLstIt == m_Dancers.end())
		{
			table.DelRow(listIt->first);
		}
		else if(rLstIt != m_Dancers.end() && rLstIt->first == listIt->first)
		{
			CDancersTable::tDATA& data = listIt->second;
			CDancersTable::tDATA& cData = rLstIt->second;
			if( data.name != cData.name
			||  data.additionalInfo != cData.additionalInfo
			||  data.regBook != cData.regBook
			||  data.clubId != cData.clubId
			||  data.trainerId != cData.trainerId
			||  data.liga != cData.liga
			||  data.gender != cData.gender
			||  data.bd != cData.bd
			||  data.pay_date != cData.pay_date
			||  data.exp_date != cData.exp_date
			)
			{
				data.name = cData.name;
				data.additionalInfo = cData.additionalInfo;
				data.regBook = cData.regBook;
				data.clubId = cData.clubId;
				data.trainerId = cData.trainerId;
				data.liga = cData.liga;
				data.gender = cData.gender;
				data.bd = cData.bd;
				data.pay_date = cData.pay_date;
				data.exp_date = cData.exp_date;
				
				table.UpdateRow(listIt->first, data);
			}
			m_Dancers.erase(rLstIt);
		}
		listIt++;
	}
	
	if(m_Dancers.size() > 0)
	{
		CDancersTable::tTableIt rLstIt = m_Dancers.begin();
		while(rLstIt != m_Dancers.end())
		{
			CDancersTable::tDATA& data = rLstIt->second;
			table.AddRow(data);
			rLstIt++;
		}
	}
	
	EndModal(wxID_OK);
}

void udfDancersMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

int udfDancersMngrDlg::GetSelectedClub()
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

int udfDancersMngrDlg::GetSelectedLigue()
{
	int res = -1;
	do
	{
		wxString value = m_comboLiga->GetValue();
		res = m_comboLiga->FindString(value);
		if(-1 == res)
		{
			ShowWarning(wxString::Format(STR_NOT_IN_DB, STR_LIGUE));
			break;
		}
	}while(0);
	
	return res;
}

int udfDancersMngrDlg::GetSelectedTrainer()
{
	int res = -1;
	do
	{
		wxString value = m_comboTrainer->GetValue();
		res = m_comboTrainer->FindString(value);
		if(-1 == res)
		{
			ShowWarning(wxString::Format(STR_NOT_IN_DB, STR_TRAINER));
			break;
		}
	}while(0);
	
	return res;
}

int udfDancersMngrDlg::GetSelectedGender()
{
	int res = -1;
	do
	{
		wxString value = m_comboGender->GetValue();
		res = m_comboGender->FindString(value);
		if(-1 == res)
		{
			ShowWarning(wxString::Format(STR_NOT_IN_DB, STR_GENDER));
			break;
		}
	}while(0);
	
	return res;
}

bool udfDancersMngrDlg::GetSelectedItemData(CDancersTable::tDATA*& pData)
{
	bool res = false;
	do{
		int nItem = m_listDancers->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listDancers->GetClientData(nItem);
		
		CDancersTable::tTableIt it = m_Dancers.find(nId);
		if(it == m_Dancers.end())
			break;
			
		pData = &it->second;
		res = true;
	}while(0);
	
	return res;
}

bool udfDancersMngrDlg::ValidateData()
{
		bool res = false;
	do
	{
		if(-1 == GetSelectedClub())
			break;
		
		if(m_datePay->GetValue() >= m_dateExp->GetValue())
		{
			ShowWarning(STR_WARN_PAY_GREATTHEN_EXP);
			break;
		}
		
		res = true;
	}while(0);
	
	return res;
}

bool udfDancersMngrDlg::GetNameById(unsigned int id, wxString& name)
{
	bool res = false;
	do
	{
		CDancersTable 			table(m_pCon);
		CDancersTable::tDATA 	dancer = {0};
		
		if(UDF_OK != table.GetRow(id, dancer))
		{
			break;
		}
		
		name = dancer.name;
		res = true;
	}while(0);
	return res;
}
