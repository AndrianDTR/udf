#include "udfClubsMngrDlg.h"
#include "udfAccountInfo.h"
#include "udfDancersMngrDlg.h"
#include "udfTarinersMngrDlg.h"
#include "udfDirectorInfo.h"
#include "udfCitiesMngr.h"
<<<<<<< HEAD
=======

#include "wx/msgdlg.h"

#include "string_def.h"
#include "udfexceptions.h"
>>>>>>> origin/develop

#include "wx/msgdlg.h"

<<<<<<< HEAD
=======
#include "string_def.h"
#include "udfexceptions.h"

>>>>>>> 3cca194... Manage Clubs functional has been implemented
udfClubsMngrDlg::udfClubsMngrDlg( wxWindow* parent )
: ClubsMngrDlg( parent )
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshList();
	RefreshCities();
}

void udfClubsMngrDlg::RefreshCities()
{
	RefreshCountries();
	
	CCitiesTable table(m_pCon);
	table.GetTable(m_Cities);
	
	m_comboCity->Clear();
	
	CCitiesTable::tTableIt it = m_Cities.begin();
	while(it != m_Cities.end())
	{
		CCitiesTable::tDATA& data = it->second;
		int nPos = m_comboCity->GetCount();
		
		CCountriesTable::tTableIt cIt = m_Countries.find(data.countryId);
		if(cIt != m_Countries.end())
		{
			CCountriesTable::tDATA& cData = cIt->second;
			wxString city = wxString::Format(STR_FORMAT_CITY_NAME, data.Name, cData.name);
			m_comboCity->Insert(city, nPos, (void*)&it->first);
		}
		it++;
	}
	m_comboCity->AutoComplete(m_comboCity->GetStrings());
}

void udfClubsMngrDlg::RefreshCountries()
{
	CCountriesTable table(m_pCon);
	table.GetTable(m_Countries);
}

<<<<<<< HEAD
bool udfClubsMngrDlg::ValidateData()
{
	bool res = false;
	do
	{
		if(-1 == GetSelectedCity())
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

void udfClubsMngrDlg::OnSearch(wxCommandEvent& event)
{
	wxString search = m_textSearch->GetValue().Upper();
	CClubsTable::tTableIt item;
	
	m_listClubs->Clear();
	for(item = m_Clubs.begin(); item != m_Clubs.end(); item++)
	{
		CClubsTable::tDATA& data = item->second;
		
		if(wxString(data.name).Upper().Contains(search)
		|| wxString(data.contacts).Upper().Contains(search)
		|| wxString(data.additionalInfo).Upper().Contains(search)
		|| wxString(data.email).Upper().Contains(search)
		|| wxString(data.web).Upper().Contains(search)
		)
		{
			int pos = m_listClubs->GetCount();
			m_listClubs->Insert(data.name, pos, (void*)&item->first);
		}
	}
}

void udfClubsMngrDlg::OnAddClub( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listClubs->GetCount();
		
		if(! ValidateData())
			break;
		
		CClubsTable::tDATA data = {0};
		data.id = -nItem;
		data.city = *(int*)m_comboCity->GetClientData(GetSelectedCity());
		
		data.name = m_textName->GetValue();
		data.additionalInfo = m_textInfo->GetValue();
		data.contacts = m_textAddress->GetValue();
		data.email = m_textEmail->GetValue();
		data.web = m_textWeb->GetValue();
		data.pay_date = m_datePay->GetValue().GetTicks();
		data.exp_date = m_dateExp->GetValue().GetTicks();
		
		CClubsTable::tTableIt it = m_Clubs.insert(std::make_pair(data.id, data)).first;
		m_listClubs->Insert(data.name, nItem, (void*)&it->first);
		m_listClubs->SetSelection(nItem);
	}while(0);
=======
void udfClubsMngrDlg::RefreshList()
{
	CClubsTable table(m_pCon);
	table.GetTable(m_Clubs);
	
	m_listClubs->Clear();
	CClubsTable::tTableIt it = m_Clubs.begin();
	while(it != m_Clubs.end())
	{
		CClubsTable::tDATA& data = it->second;
		int nPos = m_listClubs->GetCount();
		m_listClubs->Insert(data.name, nPos, (void*)&it->first);
		
		it++;
	}
>>>>>>> origin/develop
}

bool udfClubsMngrDlg::ValidateData()
{
<<<<<<< HEAD
	do
	{
		int nItem = m_listClubs->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listClubs->GetClientData(nItem);
				
		m_Clubs.erase(nId);
		m_listClubs->Delete(nItem);
	}while(0);
}

void udfClubsMngrDlg::OnUpdate(wxCommandEvent& event)
{
	do
	{
		CClubsTable::tDATA* pData = NULL;
		if(! GetSelectedItemData(pData))
			break;
		
		if(! ValidateData())
			break;
		
		int nItem = m_listClubs->FindString(pData->name, true);
		pData->city = *(int*)m_comboCity->GetClientData(GetSelectedCity());
		pData->name = m_textName->GetValue();
		pData->additionalInfo = m_textInfo->GetValue();
		pData->contacts = m_textAddress->GetValue();
		pData->email = m_textEmail->GetValue();
		pData->web = m_textWeb->GetValue();
		
		pData->pay_date = m_datePay->GetValue().GetTicks();
		pData->exp_date = m_dateExp->GetValue().GetTicks();
		
		m_listClubs->SetString(nItem, pData->name);
		
	}while(0);
}

void udfClubsMngrDlg::OnSave( wxCommandEvent& event )
{
<<<<<<< HEAD
	// TODO: Implement OnSave
=======
	CClubsTable table(m_pCon);
	CClubsTable::tTableMap storedCats;
	table.GetTable(storedCats);
		
	CClubsTable::tTableIt listIt = storedCats.begin();
	while(listIt != storedCats.end())
	{
		CClubsTable::tTableIt rLstIt = m_Clubs.find(listIt->first);
		if(rLstIt == m_Clubs.end())
		{
			table.DelRow(listIt->first);
		}
		else if(rLstIt != m_Clubs.end() && rLstIt->first == listIt->first)
		{
			CClubsTable::tDATA& data = listIt->second;
			CClubsTable::tDATA& cData = rLstIt->second;
			if( data.name != cData.name
			||  data.city != cData.city
			||  data.email != cData.email
			||  data.web != cData.web
			||  data.additionalInfo != cData.additionalInfo
			||  data.contacts != cData.contacts
			||  data.pay_date != cData.pay_date
			||  data.exp_date != cData.exp_date
			||  data.login != cData.login
			||  data.pass != cData.pass
			||  data.director != cData.director
			||  data.director_bd != cData.director_bd
			||  data.director_phone != cData.director_phone
			||  data.director_email != cData.director_email
			)
			{
				data.name = cData.name;
				data.city = cData.city;
				data.email = cData.email;
				data.web = cData.web;
				data.additionalInfo = cData.additionalInfo;
				data.contacts = cData.contacts;
				data.pay_date = cData.pay_date;
				data.exp_date = cData.exp_date;
				
				data.login = cData.login;
				data.pass = cData.pass;
				
				data.director = cData.director;
				data.director_bd = cData.director_bd;
				data.director_phone = cData.director_phone;
				data.director_email = cData.director_email;
			
				table.UpdateRow(listIt->first, data);
			}
			m_Clubs.erase(rLstIt);
		}
		listIt++;
	}
	
	if(m_Clubs.size() > 0)
	{
		CClubsTable::tTableIt rLstIt = m_Clubs.begin();
		while(rLstIt != m_Clubs.end())
		{
			CClubsTable::tDATA& data = rLstIt->second;
			table.AddRow(data);
			rLstIt++;
		}
	}
	
	EndModal(wxID_OK);
>>>>>>> 3cca194... Manage Clubs functional has been implemented
}

void udfClubsMngrDlg::OnDiscard( wxCommandEvent& event )
{
	// TODO: Implement OnDiscard
}

<<<<<<< HEAD
=======
void udfClubsMngrDlg::OnSelectClub(wxCommandEvent& event)
=======
	bool res = false;
	do
	{
		if(-1 == GetSelectedCity())
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

void udfClubsMngrDlg::OnSearch(wxCommandEvent& event)
{
	wxString search = m_textSearch->GetValue().Upper();
	CClubsTable::tTableIt item;
	
	m_listClubs->Clear();
	for(item = m_Clubs.begin(); item != m_Clubs.end(); item++)
	{
		CClubsTable::tDATA& data = item->second;
		
		if(wxString(data.name).Upper().Contains(search)
		|| wxString(data.contacts).Upper().Contains(search)
		|| wxString(data.additionalInfo).Upper().Contains(search)
		|| wxString(data.email).Upper().Contains(search)
		|| wxString(data.web).Upper().Contains(search)
		)
		{
			int pos = m_listClubs->GetCount();
			m_listClubs->Insert(data.name, pos, (void*)&item->first);
		}
	}
}

void udfClubsMngrDlg::OnAddClub( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listClubs->GetCount();
		
		if(! ValidateData())
			break;
		
		CClubsTable::tDATA data = {0};
		data.id = -nItem;
		data.city = *(int*)m_comboCity->GetClientData(GetSelectedCity());
		
		data.name = m_textName->GetValue();
		data.additionalInfo = m_textInfo->GetValue();
		data.contacts = m_textAddress->GetValue();
		data.email = m_textEmail->GetValue();
		data.web = m_textWeb->GetValue();
		data.pay_date = m_datePay->GetValue().GetTicks();
		data.exp_date = m_dateExp->GetValue().GetTicks();
		
		CClubsTable::tTableIt it = m_Clubs.insert(std::make_pair(data.id, data)).first;
		m_listClubs->Insert(data.name, nItem, (void*)&it->first);
		m_listClubs->SetSelection(nItem);
	}while(0);
}

void udfClubsMngrDlg::OnRemoveClub( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listClubs->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listClubs->GetClientData(nItem);
				
		m_Clubs.erase(nId);
		m_listClubs->Delete(nItem);
	}while(0);
}

void udfClubsMngrDlg::OnUpdate(wxCommandEvent& event)
>>>>>>> origin/develop
{
	do
	{
		CClubsTable::tDATA* pData = NULL;
<<<<<<< HEAD
		if(!GetSelectedItemData(pData))
			break;
		
		m_textName->SetValue(pData->name);
		m_textAddress->SetValue(pData->contacts);
		m_textInfo->SetValue(pData->additionalInfo);
		m_textEmail->SetValue(pData->email);
		m_textWeb->SetValue(pData->web);
		
		CCitiesTable::tTableIt cityIt = m_Cities.find(pData->city);
		if(cityIt == m_Cities.end())
			break;
		CCitiesTable::tDATA& cityData = cityIt->second;
		CCountriesTable::tTableIt countryIt = m_Countries.find(cityData.countryId);
		if(countryIt == m_Countries.end())
			break;
		CCountriesTable::tDATA& countryData = countryIt->second;
		wxString city = wxString::Format(STR_FORMAT_CITY_NAME, cityData.Name, countryData.name);
		m_comboCity->SetValue(city);
		
		wxDateTime pay = wxDateTime::Now();
		pay.Set(pData->pay_date);
		m_datePay->SetValue(pay);
		
		wxDateTime exp = wxDateTime::Now();
		exp.Set(pData->exp_date);
		m_dateExp->SetValue(exp);
=======
		if(! GetSelectedItemData(pData))
			break;
		
		if(! ValidateData())
			break;
		
		int nItem = m_listClubs->FindString(pData->name, true);
		pData->city = *(int*)m_comboCity->GetClientData(GetSelectedCity());
		pData->name = m_textName->GetValue();
		pData->additionalInfo = m_textInfo->GetValue();
		pData->contacts = m_textAddress->GetValue();
		pData->email = m_textEmail->GetValue();
		pData->web = m_textWeb->GetValue();
		
		pData->pay_date = m_datePay->GetValue().GetTicks();
		pData->exp_date = m_dateExp->GetValue().GetTicks();
		
		m_listClubs->SetString(nItem, pData->name);
		
>>>>>>> origin/develop
	}while(0);
}

int udfClubsMngrDlg::GetSelectedCity()
{
<<<<<<< HEAD
	int res = -1;
	while(1)
	{
		wxString value = m_comboCity->GetValue();
		res = m_comboCity->FindString(value);
		if(-1 != res)
			break;
		if(wxNO == wxMessageBox(
			  wxString::Format(STR_NOT_IN_DB_INSERT, STR_CITY)
			, STR_INCORRECT_VALUE
			, wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION
			, this)
		)
			break;
		
		udfCitiesMngr dlg(this);
		if(wxID_OK != dlg.ShowModal())
			break;
		
		RefreshCountries();
		m_comboCity->SetValue(value);
	}
	
	return res;
=======
	CClubsTable table(m_pCon);
	CClubsTable::tTableMap storedCats;
	table.GetTable(storedCats);
		
	CClubsTable::tTableIt listIt = storedCats.begin();
	while(listIt != storedCats.end())
	{
		CClubsTable::tTableIt rLstIt = m_Clubs.find(listIt->first);
		if(rLstIt == m_Clubs.end())
		{
			table.DelRow(listIt->first);
		}
		else if(rLstIt != m_Clubs.end() && rLstIt->first == listIt->first)
		{
			CClubsTable::tDATA& data = listIt->second;
			CClubsTable::tDATA& cData = rLstIt->second;
			if( data.name != cData.name
			||  data.city != cData.city
			||  data.email != cData.email
			||  data.web != cData.web
			||  data.additionalInfo != cData.additionalInfo
			||  data.contacts != cData.contacts
			||  data.pay_date != cData.pay_date
			||  data.exp_date != cData.exp_date
			||  data.login != cData.login
			||  data.pass != cData.pass
			||  data.director != cData.director
			||  data.director_bd != cData.director_bd
			||  data.director_phone != cData.director_phone
			||  data.director_email != cData.director_email
			)
			{
				data.name = cData.name;
				data.city = cData.city;
				data.email = cData.email;
				data.web = cData.web;
				data.additionalInfo = cData.additionalInfo;
				data.contacts = cData.contacts;
				data.pay_date = cData.pay_date;
				data.exp_date = cData.exp_date;
				
				data.login = cData.login;
				data.pass = cData.pass;
				
				data.director = cData.director;
				data.director_bd = cData.director_bd;
				data.director_phone = cData.director_phone;
				data.director_email = cData.director_email;
			
				table.UpdateRow(listIt->first, data);
			}
			m_Clubs.erase(rLstIt);
		}
		listIt++;
	}
	
	if(m_Clubs.size() > 0)
	{
		CClubsTable::tTableIt rLstIt = m_Clubs.begin();
		while(rLstIt != m_Clubs.end())
		{
			CClubsTable::tDATA& data = rLstIt->second;
			table.AddRow(data);
			rLstIt++;
		}
	}
	
	EndModal(wxID_OK);
>>>>>>> origin/develop
}

bool udfClubsMngrDlg::GetSelectedItemData(CClubsTable::tDATA*& pData)
{
<<<<<<< HEAD
=======
	EndModal(wxID_CANCEL);
}

void udfClubsMngrDlg::OnSelectClub(wxCommandEvent& event)
{
	do
	{
		CClubsTable::tDATA* pData = NULL;
		if(!GetSelectedItemData(pData))
			break;
		
		m_textName->SetValue(pData->name);
		m_textAddress->SetValue(pData->contacts);
		m_textInfo->SetValue(pData->additionalInfo);
		m_textEmail->SetValue(pData->email);
		m_textWeb->SetValue(pData->web);
		
		CCitiesTable::tTableIt cityIt = m_Cities.find(pData->city);
		if(cityIt == m_Cities.end())
			break;
		CCitiesTable::tDATA& cityData = cityIt->second;
		CCountriesTable::tTableIt countryIt = m_Countries.find(cityData.countryId);
		if(countryIt == m_Countries.end())
			break;
		CCountriesTable::tDATA& countryData = countryIt->second;
		wxString city = wxString::Format(STR_FORMAT_CITY_NAME, cityData.Name, countryData.name);
		m_comboCity->SetValue(city);
		
		wxDateTime pay = wxDateTime::Now();
		pay.Set(pData->pay_date);
		m_datePay->SetValue(pay);
		
		wxDateTime exp = wxDateTime::Now();
		exp.Set(pData->exp_date);
		m_dateExp->SetValue(exp);
	}while(0);
}

int udfClubsMngrDlg::GetSelectedCity()
{
	int res = -1;
	while(1)
	{
		wxString value = m_comboCity->GetValue();
		res = m_comboCity->FindString(value);
		if(-1 != res)
			break;
		if(wxNO == wxMessageBox(
			  wxString::Format(STR_NOT_IN_DB_INSERT, STR_CITY)
			, STR_INCORRECT_VALUE
			, wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION
			, this)
		)
			break;
		
		udfCitiesMngr dlg(this);
		if(wxID_OK != dlg.ShowModal())
			break;
		
		RefreshCountries();
		m_comboCity->SetValue(value);
	}
	
	return res;
}

bool udfClubsMngrDlg::GetSelectedItemData(CClubsTable::tDATA*& pData)
{
>>>>>>> origin/develop
	bool res = false;
	do{
		int nItem = m_listClubs->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listClubs->GetClientData(nItem);
		
		CClubsTable::tTableIt it = m_Clubs.find(nId);
		if(it == m_Clubs.end())
			break;
			
		pData = &it->second;
		res = true;
	}while(0);
	
	return res;
}

void udfClubsMngrDlg::OnAccountInfo( wxCommandEvent& event )
{
	do
	{
		CClubsTable::tDATA* pData = NULL;
		if(!GetSelectedItemData(pData))
			break;
		
		udfAccountInfo dlg(this);
		dlg.SetLogin(pData->login);
		dlg.SetPass(pData->pass);
		if(wxID_OK != dlg.ShowModal())
			break;
			
		pData->login = dlg.GetLogin();
		pData->pass = dlg.GetPass();
	}while(0);
}

void udfClubsMngrDlg::OnDirectorInfo( wxCommandEvent& event )
{
	do
	{
		CClubsTable::tDATA* pData = NULL;
		if(!GetSelectedItemData(pData))
			break;
		
		udfDirectorInfo dlg(this);
		dlg.SetName(pData->director);
		dlg.SetBd(pData->director_bd);
		dlg.SetEmail(pData->director_email);
		dlg.SetPhone(pData->director_phone);
		if(wxID_OK != dlg.ShowModal())
			break;
		
		pData->director = dlg.GetName();
		pData->director_bd = dlg.GetBd();
		pData->director_email = dlg.GetEmail();
		pData->director_phone = dlg.GetPhone();
	}while(0);
}

void udfClubsMngrDlg::OnTrainersMngr( wxCommandEvent& event )
{
	do
	{
		CClubsTable::tDATA* pData = NULL;
		if(!GetSelectedItemData(pData))
			break;
		
		udfTarinersMngrDlg dlg(this);
		if(wxID_OK != dlg.ShowModal())
			break;
			
	}while(0);
}

void udfClubsMngrDlg::OnDancersMngr( wxCommandEvent& event )
{
	do
	{
		CClubsTable::tDATA* pData = NULL;
		if(!GetSelectedItemData(pData))
			break;
		
		udfDancersMngrDlg dlg(this);
		if(wxID_OK != dlg.ShowModal())
			break;
			
	}while(0);
}
<<<<<<< HEAD
>>>>>>> 3cca194... Manage Clubs functional has been implemented
=======
>>>>>>> origin/develop
