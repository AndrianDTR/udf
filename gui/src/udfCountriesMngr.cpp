#include "udfCountriesMngr.h"

#include "common.h"

udfCountriesMngr::udfCountriesMngr( wxWindow* parent )
: CountriesMngr( parent )
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	CCountriesTable table(m_pCon);
	table.GetTable(m_Countries);

	CCountriesTable::tTableIt it = m_Countries.begin();
	while(it != m_Countries.end())
	{
		CCountriesTable::tDATA data = it->second;
		int nPos = m_listItems->GetCount();
		m_listItems->Insert(data.name, nPos, (void*)&it->first);
		__debug("Pos: %d, %d, %s", nPos, data.id, data.name.c_str());
		it++;
	}
}

void udfCountriesMngr::OnSearch( wxCommandEvent& event )
{
	wxString search = m_textSearch->GetValue().Upper();
	CCountriesTable::tTableIt item;
	
	m_listItems->Clear();
	for(item = m_Countries.begin(); item != m_Countries.end(); item++)
	{
		CCountriesTable::tDATA data = item->second;
		wxString name(data.name);
		
		if(name.Upper().Contains(search))
		{
			int pos = m_listItems->GetCount();
			m_listItems->Insert(data.name, pos, (void*)&item->first);
		}
	}
}

void udfCountriesMngr::OnSelectItem( wxCommandEvent& event )
{
	int nItem = m_listItems->GetSelection();
	int nId = *(int*)m_listItems->GetClientData(nItem);
	CCountriesTable::tTableIt it = m_Countries.find(nId);
	
	if(it != m_Countries.end())
	{
		CCountriesTable::tDATA data = it->second;
		m_textName->SetValue(data.name);
	}
}

void udfCountriesMngr::OnAdd( wxCommandEvent& event )
{
	int nItem = m_listItems->GetCount();
	
	CCountriesTable::tDATA data = {0};
	data.id = -nItem;
	data.name = m_textName->GetValue();
	
	CCountriesTable::tTableIt it = m_Countries.insert(std::make_pair(data.id, data)).first;
	m_listItems->Insert(data.name, nItem, (void*)&it->first);
	m_listItems->SetSelection(nItem);
}

void udfCountriesMngr::OnRemove( wxCommandEvent& event )
{
	int nItem = m_listItems->GetSelection();
	int nId = *(int*)m_listItems->GetClientData(nItem);
	m_Countries.erase(nId);
	m_listItems->Delete(nItem);
}

void udfCountriesMngr::OnUpdateCode( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listItems->GetSelection();
		
		if(-1 == nItem)
			break;
			
		int nId = *(int*)m_listItems->GetClientData(nItem);
		CCountriesTable::tTableIt it = m_Countries.find(nId);
		
		if(it == m_Countries.end())
			break;
			
		CCountriesTable::tDATA& data = it->second;
		
		data.name = m_textName->GetValue();
		m_listItems->SetString(nItem, data.name);

	}while(0);
}

void udfCountriesMngr::OnSave( wxCommandEvent& event )
{
	OnUpdateCode(event);
	
	CCountriesTable table(m_pCon);
	CCountriesTable::tTableMap storedCats;
	table.GetTable(storedCats);
		
	CCountriesTable::tTableIt listIt = storedCats.begin();
	while(listIt != storedCats.end())
	{
		CCountriesTable::tTableIt rLstIt = m_Countries.find(listIt->first);
		if(rLstIt == m_Countries.end())
		{
			table.DelRow(listIt->first);
		}
		else if(rLstIt != m_Countries.end() && rLstIt->first == listIt->first)
		{
			CCountriesTable::tDATA& data = listIt->second;
			CCountriesTable::tDATA& cData = rLstIt->second;
			if( data.name != cData.name )
			{
				data.name = cData.name;
				table.UpdateRow(listIt->first, data);
			}
			m_Countries.erase(rLstIt);
		}
		listIt++;
	}
	
	if(m_Countries.size() > 0)
	{
		//insert data here
		CCountriesTable::tTableIt rLstIt = m_Countries.begin();
		while(rLstIt != m_Countries.end())
		{
			CCountriesTable::tDATA& data = rLstIt->second;
			table.AddRow(data);
			rLstIt++;
		}
	}
	
	EndDialog(wxID_OK);
}

void udfCountriesMngr::OnDiscard( wxCommandEvent& event )
{
	EndDialog(wxID_CANCEL);
}
