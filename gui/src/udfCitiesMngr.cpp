#include "udfCitiesMngr.h"

#include "wx/msgdlg.h"

#include "string_def.h"
#include "udfcommon.h"
#include "udfCountriesMngr.h"

udfCitiesMngr::udfCitiesMngr( wxWindow* parent )
: CitiesMngr( parent )
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	CCitiesTable tableCities(m_pCon);
	tableCities.GetTable(m_Cities);
	
	CCitiesTable::tTableIt it = m_Cities.begin();
	m_listItems->Clear();
	while(it != m_Cities.end())
	{
		CCitiesTable::tDATA& city = it->second;
		int nPos = m_listItems->GetCount();
		m_listItems->Insert(city.Name, nPos, (void*)&it->first);
		it++;
	}
	RefreshCountries();
}

void udfCitiesMngr::RefreshCountries()
{
	CCountriesTable tableCountries(m_pCon);
	tableCountries.GetTable(m_Countries);

	m_comboCounty->Clear();
	CCountriesTable::tTableIt it = m_Countries.begin();
	while(it != m_Countries.end())
	{
		CCountriesTable::tDATA data = it->second;
		int nPos = m_comboCounty->GetCount();
		m_comboCounty->Insert(data.name, nPos, (void*)&it->first);
		__debug("Pos: %d, %d, %s", nPos, data.id, data.name.c_str());
		it++;
	}
	m_comboCounty->AutoComplete(m_comboCounty->GetStrings());
}

void udfCitiesMngr::OnSearch( wxCommandEvent& event )
{
	wxString search = m_textSearch->GetValue().Upper();
	CCitiesTable::tTableIt item;
	
	m_listItems->Clear();
	for(item = m_Cities.begin(); item != m_Cities.end(); item++)
	{
		CCitiesTable::tDATA& data = item->second;
		wxString name(data.Name);
		
		if(name.Upper().Contains(search))
		{
			int pos = m_listItems->GetCount();
			m_listItems->Insert(data.Name, pos, (void*)&item->first);
		}
	}
}

void udfCitiesMngr::OnSelectItem( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listItems->GetSelection();
		int nId = *(int*)m_listItems->GetClientData(nItem);
		CCitiesTable::tTableIt it = m_Cities.find(nId);
		
		if(it == m_Cities.end())
			break;
		
		CCitiesTable::tDATA& data = it->second;
		CCountriesTable::tTableIt cIt = m_Countries.find(data.countryId);
		if(cIt == m_Countries.end())
			break;
			
		CCountriesTable::tDATA& country = cIt->second;
		int nCountry = m_comboCounty->FindString(country.name);
		m_comboCounty->SetSelection(nCountry);
		m_textName->SetValue(data.Name);
	}while(0);
}

void udfCitiesMngr::OnAdd( wxCommandEvent& event )
{
	int nItem = m_listItems->GetCount();
		
	CCitiesTable::tDATA data = {0};
	data.id = -nItem;
	int nCountry = GetSelectedCountry();
	data.countryId = *(int*)m_comboCounty->GetClientData(nCountry);
	data.Name = m_textName->GetValue();
	
	CCitiesTable::tTableIt it = m_Cities.insert(std::make_pair(data.id, data)).first;
	m_listItems->Insert(data.Name, nItem, (void*)&it->first);
	m_listItems->SetSelection(nItem);
}

void udfCitiesMngr::OnRemove( wxCommandEvent& event )
{
	int nItem = m_listItems->GetSelection();
	int nId = *(int*)m_listItems->GetClientData(nItem);
	m_Cities.erase(nId);
	m_listItems->Delete(nItem);
}

void udfCitiesMngr::OnUpdateCode( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listItems->GetSelection();
		
		if(-1 == nItem)
			break;
			
		int nId = *(int*)m_listItems->GetClientData(nItem);
		CCitiesTable::tTableIt it = m_Cities.find(nId);
		
		if(it == m_Cities.end())
			break;
		
		int nCountry = GetSelectedCountry();
					
		CCitiesTable::tDATA& data = it->second;
		data.countryId = *(int*)m_comboCounty->GetClientData(nCountry);
		data.Name = m_textName->GetValue();
		m_listItems->SetString(nItem, data.Name);

	}while(0);
}

void udfCitiesMngr::OnSave( wxCommandEvent& event )
{
	OnUpdateCode(event);
	
	CCitiesTable table(m_pCon);
	CCitiesTable::tTableMap stored;
	table.GetTable(stored);
		
	CCitiesTable::tTableIt listIt = stored.begin();
	while(listIt != stored.end())
	{
		CCitiesTable::tTableIt rLstIt = m_Cities.find(listIt->first);
		if(rLstIt == m_Cities.end())
		{
			table.DelRow(listIt->first);
		}
		else if(rLstIt != m_Cities.end() && rLstIt->first == listIt->first)
		{
			CCitiesTable::tDATA& data = listIt->second;
			CCitiesTable::tDATA& cData = rLstIt->second;
			if( data.Name != cData.Name
				||  data.countryId != cData.countryId)
			{
				data.Name = cData.Name;
				data.countryId = cData.countryId;
				table.UpdateRow(listIt->first, data);
			}
			m_Cities.erase(rLstIt);
		}
		listIt++;
	}
	
	if(m_Cities.size() > 0)
	{
		CCitiesTable::tTableIt rLstIt = m_Cities.begin();
		while(rLstIt != m_Cities.end())
		{
			CCitiesTable::tDATA& data = rLstIt->second;
			table.AddRow(data);
			rLstIt++;
		}
	}
	
	EndModal(wxID_OK);
}

void udfCitiesMngr::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

int udfCitiesMngr::GetSelectedCountry()
{
	int res = -1;
	while(1)
	{
		wxString value = m_comboCounty->GetValue();
		res = m_comboCounty->FindString(value);
		if(-1 != res)
			break;
		
		if(wxNO == wxMessageBox(
			  wxString::Format(STR_NOT_IN_DB_INSERT, STR_COUNTRY)
			, STR_INCORRECT_VALUE
			, wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION
			, this)
		)
			break;
		
		udfCountriesMngr dlg(this);
		if(wxID_OK != dlg.ShowModal())
			break;
		
		RefreshCountries();
		m_comboCounty->SetValue(value);
	}
	
	return res;
}
