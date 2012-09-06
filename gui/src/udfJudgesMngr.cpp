#include "udfJudgesMngr.h"

#include "wx/msgdlg.h"

#include "common.h"
#include "string_def.h"
#include "udfexceptions.h"
#include "udfCitiesMngr.h"

udfJudgesMngr::udfJudgesMngr( wxWindow* parent )
: JudgesMngr( parent )
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshList();
	RefreshCities();
}

void udfJudgesMngr::RefreshCities()
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

void udfJudgesMngr::RefreshCountries()
{
	CCountriesTable table(m_pCon);
	table.GetTable(m_Countries);
}

void udfJudgesMngr::RefreshList()
{
	CJudgesTable(m_pCon).GetTable(m_Judges);
	
	m_listJudges->Clear();
	CJudgesTable::tTableIt it = m_Judges.begin();
	while(it != m_Judges.end())
	{
		CJudgesTable::tDATA& data = it->second;
		int nPos = m_listJudges->GetCount();
		m_listJudges->Insert(data.name, nPos, (void*)&it->first);
		
		it++;
	}
}

void udfJudgesMngr::OnSearch( wxCommandEvent& event )
{
	wxString search = m_textSearch->GetValue().Upper();
	CJudgesTable::tTableIt item;
	
	m_listJudges->Clear();
	for(item = m_Judges.begin(); item != m_Judges.end(); item++)
	{
		CJudgesTable::tDATA& data = item->second;
		
		if(wxString(data.name).Upper().Contains(search)
		|| wxString(data.additionalInfo).Upper().Contains(search)
		|| wxString(data.email).Upper().Contains(search)
		|| wxString(data.phone).Upper().Contains(search)
		)
		{
			int pos = m_listJudges->GetCount();
			m_listJudges->Insert(data.name, pos, (void*)&item->first);
		}
	}
}

void udfJudgesMngr::OnSelectJudge( wxCommandEvent& event )
{
	do
	{
		CJudgesTable::tDATA* pData = NULL;
		if(!GetSelectedItemData(pData))
			break;
		
		m_textName->SetValue(pData->name);
		m_textAttestation->SetValue(pData->attestationInfo);
		m_textInfo->SetValue(pData->additionalInfo);
		m_textEmail->SetValue(pData->email);
		m_textPhone->SetValue(pData->phone);
		
		CCitiesTable::tTableIt cityIt = m_Cities.find(pData->cityId);
		if(cityIt == m_Cities.end())
			break;
		CCitiesTable::tDATA& cityData = cityIt->second;
		CCountriesTable::tTableIt countryIt = m_Countries.find(cityData.countryId);
		if(countryIt == m_Countries.end())
			break;
		CCountriesTable::tDATA& countryData = countryIt->second;
		wxString city = wxString::Format(STR_FORMAT_CITY_NAME, cityData.Name, countryData.name);
		m_comboCity->SetValue(city);
		
		DEBUG_PRINTF("PRACTICER %c - %d", pData->practicer, pData->practicer == 'Y');
		m_checkPracticer->SetValue(pData->practicer == 'Y');
		
		m_datePay->SetValue(wxDateTime(pData->pay_date));
		m_dateExp->SetValue(wxDateTime(pData->exp_date));
	}while(0);
}

void udfJudgesMngr::OnAddJudge( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listJudges->GetCount();
		
		if(! ValidateData())
			break;
		
		CJudgesTable::tDATA data = {0};
		data.id = -nItem;
		data.cityId = *(int*)m_comboCity->GetClientData(GetSelectedCity());
		
		data.name = m_textName->GetValue();
		data.additionalInfo = m_textInfo->GetValue();
		data.attestationInfo = m_textAttestation->GetValue();
		data.email = m_textEmail->GetValue();
		data.phone = m_textPhone->GetValue();
		data.pay_date = m_datePay->GetValue().GetTicks();
		data.exp_date = m_dateExp->GetValue().GetTicks();
		data.practicer = m_checkPracticer->GetValue() ? 'Y' : 'N';
		
		CJudgesTable::tTableIt it = m_Judges.insert(std::make_pair(data.id, data)).first;
		m_listJudges->Insert(data.name, nItem, (void*)&it->first);
		m_listJudges->SetSelection(nItem);
	}while(0);
}

void udfJudgesMngr::OnRemoveJudge( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listJudges->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listJudges->GetClientData(nItem);
				
		m_Judges.erase(nId);
		m_listJudges->Delete(nItem);
	}while(0);
}

void udfJudgesMngr::OnUpdate(wxCommandEvent& event)
{
	do
	{
		CJudgesTable::tDATA* pData = NULL;
		if(! GetSelectedItemData(pData))
			break;
		
		if(! ValidateData())
			break;
		
		int nItem = m_listJudges->FindString(pData->name, true);
		pData->cityId = *(int*)m_comboCity->GetClientData(GetSelectedCity());
		pData->name = m_textName->GetValue();
		pData->additionalInfo = m_textInfo->GetValue();
		pData->attestationInfo = m_textAttestation->GetValue();
		pData->email = m_textEmail->GetValue();
		pData->phone = m_textPhone->GetValue();
		pData->practicer = m_checkPracticer->GetValue() ? 'Y' : 'N';
		
		pData->pay_date = m_datePay->GetValue().GetTicks();
		pData->exp_date = m_dateExp->GetValue().GetTicks();
		
		m_listJudges->SetString(nItem, pData->name);
		
	}while(0);
}

void udfJudgesMngr::OnSave( wxCommandEvent& event )
{
	CJudgesTable table(m_pCon);
	CJudgesTable::tTableMap stored;
	table.GetTable(stored);
		
	CJudgesTable::tTableIt listIt = stored.begin();
	while(listIt != stored.end())
	{
		CJudgesTable::tTableIt rLstIt = m_Judges.find(listIt->first);
		if(rLstIt == m_Judges.end())
		{
			if( UDF_OK != table.DelRow(listIt->first))
			{
				ShowWarning(STR_ERR_DEL_JUDGE_FAILED);
			}
		}
		else if(rLstIt != m_Judges.end() && rLstIt->first == listIt->first)
		{
			CJudgesTable::tDATA& data = listIt->second;
			CJudgesTable::tDATA& cData = rLstIt->second;
			if( data.name != cData.name
			||  data.cityId != cData.cityId
			||  data.practicer != cData.practicer
			||  data.email != cData.email
			||  data.phone != cData.phone
			||  data.additionalInfo != cData.additionalInfo
			||  data.attestationInfo != cData.attestationInfo
			||  data.pay_date != cData.pay_date
			||  data.exp_date != cData.exp_date
			)
			{
				data.name = cData.name;
				data.cityId = cData.cityId;
				data.email = cData.email;
				data.phone = cData.phone;
				data.additionalInfo = cData.additionalInfo;
				data.attestationInfo = cData.attestationInfo;
				data.practicer = cData.practicer;
				data.pay_date = cData.pay_date;
				data.exp_date = cData.exp_date;
				
				if( UDF_OK != table.UpdateRow(listIt->first, data))
				{
					ShowWarning(STR_ERR_DEL_JUDGE_FAILED);
				}
			}
			m_Judges.erase(rLstIt);
		}
		listIt++;
	}
	
	if(m_Judges.size() > 0)
	{
		CJudgesTable::tTableIt rLstIt = m_Judges.begin();
		while(rLstIt != m_Judges.end())
		{
			CJudgesTable::tDATA& data = rLstIt->second;
			if( UDF_OK != table.AddRow(data))
			{
				ShowWarning(STR_ERR_DEL_JUDGE_FAILED);
			}
			rLstIt++;
		}
	}
	
	EndModal(wxID_OK);
}

void udfJudgesMngr::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

int udfJudgesMngr::GetSelectedCity()
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

bool udfJudgesMngr::ValidateData()
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

bool udfJudgesMngr::GetSelectedItemData(CJudgesTable::tDATA*& pData)
{
	bool res = false;
	do{
		int nItem = m_listJudges->GetSelection();
		if(nItem == -1)
			break;
		
		int nId = *(int*)m_listJudges->GetClientData(nItem);
		
		CJudgesTable::tTableIt it = m_Judges.find(nId);
		if(it == m_Judges.end())
			break;
			
		pData = &it->second;
		res = true;
	}while(0);
	
	return res;
}