#include "udfTarinersMngrDlg.h"

#include "common.h"
#include "tcountries.h"
#include "tcities.h"
#include "string_def.h"

#include "wx/msgdlg.h"

#include "udfexceptions.h"
#include "udfClubsMngrDlg.h"

udfTarinersMngrDlg::udfTarinersMngrDlg( wxWindow* parent, unsigned int nClubId )
: TarinersMngrDlg( parent )
, m_nClubId(nClubId)
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshList();
	RefreshClubs();
}

void udfTarinersMngrDlg::RefreshClubs()
{
	CClubsTable table(m_pCon);
	table.GetTable(m_Clubs);
		
	m_comboClub->Clear();
	CClubsTable::tTableIt it = m_Clubs.begin();
	while(it != m_Clubs.end())
	{
		int nPos = m_comboClub->GetCount();
		wxString club;
		if(GetClubNameById(it->first, club))
			m_comboClub->Insert(club, nPos, (void*)&it->first);
		
		it++;
	}
	m_comboClub->AutoComplete(m_comboClub->GetStrings());
}

void udfTarinersMngrDlg::RefreshList()
{
	CTrainersTable table(m_pCon);
	CTrainersTable::tDATA filter = {0};
	filter.clubId = m_nClubId;
	table.Find(m_Trainers, filter);
	
	m_listTrainers->Clear();
	
	CTrainersTable::tTableIt it = m_Trainers.begin();
	while(it != m_Trainers.end())
	{
		CTrainersTable::tDATA& data = it->second;
		int nPos = m_listTrainers->GetCount();
		m_listTrainers->Insert(data.name, nPos, (void*)&it->first);
		
		it++;
	}
}

void udfTarinersMngrDlg::OnSelectTrainer(wxCommandEvent& event)
{
	do
	{
		int nItem = m_listTrainers->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listTrainers->GetClientData(nItem);
		
		CTrainersTable::tTableIt it = m_Trainers.find(nId);
		if(it == m_Trainers.end())
			break;
		
		CTrainersTable::tDATA& data = it->second;
		m_textName->SetValue(data.name);
		m_textEmail->SetValue(data.email);
		m_textInfo->SetValue(data.additionalInfo);
		m_textPhone->SetValue(data.phone);
		
		wxString clubName;
		if(GetClubNameById(data.clubId, clubName))
			m_comboClub->SetValue(clubName);
		
		m_dateBd->SetValue(wxDateTime(data.bd));
		m_datePay->SetValue(wxDateTime(data.pay_date));
		m_dateExp->SetValue(wxDateTime(data.exp_date));
		
	}while(0);
}

void udfTarinersMngrDlg::OnAddTrainer( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listTrainers->GetCount();
		
		if(! ValidateData())
			break;
		
		CTrainersTable::tDATA data = {0};
		data.id = -nItem;
		data.clubId = *(int*)m_comboClub->GetClientData(GetSelectedClub());
		
		data.name = m_textName->GetValue();
		data.additionalInfo = m_textInfo->GetValue();
		data.email = m_textEmail->GetValue();
		data.bd = m_dateBd->GetValue().GetTicks();
		data.phone = m_textPhone->GetValue();
		data.pay_date = m_datePay->GetValue().GetTicks();
		data.exp_date = m_dateExp->GetValue().GetTicks();
		
		CTrainersTable::tTableIt it = m_Trainers.insert(std::make_pair(data.id, data)).first;
		m_listTrainers->Insert(data.name, nItem, (void*)&it->first);
		m_listTrainers->SetSelection(nItem);
	}while(0);
}

void udfTarinersMngrDlg::OnRemoveTrainer( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listTrainers->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listTrainers->GetClientData(nItem);
				
		m_Trainers.erase(nId);
		m_listTrainers->Delete(nItem);
	}while(0);
}

void udfTarinersMngrDlg::OnUpdate(wxCommandEvent& event)
{
	do
	{
		CTrainersTable::tDATA* pData = NULL;
		if(! GetSelectedItemData(pData))
			break;
		
		if(! ValidateData())
			break;
		
		int nItem = m_listTrainers->FindString(pData->name, true);
		pData->clubId = *(int*)m_comboClub->GetClientData(GetSelectedClub());
		pData->name = m_textName->GetValue();
		pData->additionalInfo = m_textInfo->GetValue();
		pData->phone = m_textPhone->GetValue();
		pData->email = m_textEmail->GetValue();
		pData->bd = m_dateBd->GetValue().GetTicks();
		
		pData->pay_date = m_datePay->GetValue().GetTicks();
		pData->exp_date = m_dateExp->GetValue().GetTicks();
		
		m_listTrainers->SetString(nItem, pData->name);
		
	}while(0);
}

void udfTarinersMngrDlg::OnSave( wxCommandEvent& event )
{
	CTrainersTable table(m_pCon);
	CTrainersTable::tTableMap stored;
	table.GetTable(stored);
		
	CTrainersTable::tTableIt listIt = stored.begin();
	while(listIt != stored.end())
	{
		CTrainersTable::tTableIt rLstIt = m_Trainers.find(listIt->first);
		if(rLstIt == m_Trainers.end())
		{
			table.DelRow(listIt->first);
		}
		else if(rLstIt != m_Trainers.end() && rLstIt->first == listIt->first)
		{
			CTrainersTable::tDATA& data = listIt->second;
			CTrainersTable::tDATA& cData = rLstIt->second;
			if( data.name != cData.name
			||  data.clubId != cData.clubId
			||  data.email != cData.email
			||  data.phone != cData.phone
			||  data.bd != cData.bd
			||  data.additionalInfo != cData.additionalInfo
			||  data.pay_date != cData.pay_date
			||  data.exp_date != cData.exp_date
			)
			{
				data.name = cData.name;
				data.clubId = cData.clubId;
				data.email = cData.email;
				data.bd = cData.bd;
				data.phone = cData.phone;
				data.additionalInfo = cData.additionalInfo;
				data.pay_date = cData.pay_date;
				data.exp_date = cData.exp_date;
				
				table.UpdateRow(listIt->first, data);
			}
			m_Trainers.erase(rLstIt);
		}
		listIt++;
	}
	
	if(m_Trainers.size() > 0)
	{
		CTrainersTable::tTableIt rLstIt = m_Trainers.begin();
		while(rLstIt != m_Trainers.end())
		{
			CTrainersTable::tDATA& data = rLstIt->second;
			table.AddRow(data);
			rLstIt++;
		}
	}
	
	EndModal(wxID_OK);
}

void udfTarinersMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfTarinersMngrDlg::OnSearch(wxCommandEvent& event)
{
	wxString search = m_textSearch->GetValue().Upper();
	CTrainersTable::tTableIt item;
	
	m_listTrainers->Clear();
	for(item = m_Trainers.begin(); item != m_Trainers.end(); item++)
	{
		CTrainersTable::tDATA& data = item->second;
		
		if(wxString(data.name).Upper().Contains(search)
		|| wxString(data.additionalInfo).Upper().Contains(search)
		|| wxString(data.email).Upper().Contains(search)
		|| wxString(data.phone).Upper().Contains(search)
		)
		{
			int pos = m_listTrainers->GetCount();
			m_listTrainers->Insert(data.name, pos, (void*)&item->first);
		}
	}
}

bool udfTarinersMngrDlg::ValidateData()
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

bool udfTarinersMngrDlg::GetClubNameById(unsigned int id, wxString& name)
{
	bool res = false;
	do
	{
		CCountriesTable 		tCountries(m_pCon);
		CCountriesTable::tDATA 	country = {0};
		
		CCitiesTable 			tCities(m_pCon);
		CCitiesTable::tDATA		city = {0};
		
		CClubsTable 			tClubs(m_pCon);
		CClubsTable::tDATA 		club = {0};
		
		if(UDF_OK != tClubs.GetRow(id, club))
			break;
		
		if(UDF_OK != tCities.GetRow(club.city, city))
			break;
		
		if(UDF_OK != tCountries.GetRow(city.countryId, country))
			break;
		
		name = wxString::Format(STR_FORMAT_CLUB_NAME, club.name, city.Name, country.name);
		res = true;
	}while(0);
	return res;
}

int udfTarinersMngrDlg::GetSelectedClub()
{
	int res = -1;
	do
	{
		wxString value = m_comboClub->GetValue();
		res = m_comboClub->FindString(value);
		if(-1 == res)
		{
			ShowWarning(wxString::Format(STR_NOT_IN_DB_INSERT, STR_CLUB));
			break;
		}
	}while(0);
	
	return res;
}

bool udfTarinersMngrDlg::GetSelectedItemData(CTrainersTable::tDATA*& pData)
{
	bool res = false;
	do{
		int nItem = m_listTrainers->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listTrainers->GetClientData(nItem);
		
		CTrainersTable::tTableIt it = m_Trainers.find(nId);
		if(it == m_Trainers.end())
			break;
			
		pData = &it->second;
		res = true;
	}while(0);
	
	return res;
}
