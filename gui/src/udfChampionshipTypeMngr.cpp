#include "udfChampionshipTypeMngr.h"

udfChampionshipTypeMngr::udfChampionshipTypeMngr( wxWindow* parent )
: ChampionshipTypeMngr( parent )
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	CChampionshipTypeTable table(m_pCon);
	table.GetTable(m_Types);

	CChampionshipTypeTable::tTableIt it = m_Types.begin();
	while(it != m_Types.end())
	{
		CChampionshipTypeTable::tDATA data = it->second;
		int nPos = m_listItems->GetCount();
		m_listItems->Insert(data.name, nPos, (void*)&it->first);
		it++;
	}
}

void udfChampionshipTypeMngr::OnSearch( wxCommandEvent& event )
{
	wxString search = m_textSearch->GetValue().Upper();
	CChampionshipTypeTable::tTableIt item;
	
	m_listItems->Clear();
	for(item = m_Types.begin(); item != m_Types.end(); item++)
	{
		CChampionshipTypeTable::tDATA data = item->second;
		wxString name(data.name);
		
		if(name.Upper().Contains(search))
		{
			int pos = m_listItems->GetCount();
			m_listItems->Insert(data.name, pos, (void*)&item->first);
		}
	}
}

void udfChampionshipTypeMngr::OnSelectItem( wxCommandEvent& event )
{
	int nItem = m_listItems->GetSelection();
	int nId = *(int*)m_listItems->GetClientData(nItem);
	CChampionshipTypeTable::tTableIt it = m_Types.find(nId);
	
	if(it != m_Types.end())
	{
		CChampionshipTypeTable::tDATA data = it->second;
		m_textName->SetValue(data.name);
	}
}

void udfChampionshipTypeMngr::OnAdd( wxCommandEvent& event )
{
	int nItem = m_listItems->GetCount();
	
	CChampionshipTypeTable::tDATA data = {0};
	data.id = -nItem;
	data.name = m_textName->GetValue();
	
	CChampionshipTypeTable::tTableIt it = m_Types.insert(std::make_pair(data.id, data)).first;
	m_listItems->Insert(data.name, nItem, (void*)&it->first);
	m_listItems->SetSelection(nItem);
}

void udfChampionshipTypeMngr::OnRemove( wxCommandEvent& event )
{
	int nItem = m_listItems->GetSelection();
	int nId = *(int*)m_listItems->GetClientData(nItem);
	m_Types.erase(nId);
	m_listItems->Delete(nItem);
}

void udfChampionshipTypeMngr::OnUpdateCode( wxCommandEvent& event )
{
	do
	{
		int nItem = m_listItems->GetSelection();
		
		if(-1 == nItem)
			break;
			
		int nId = *(int*)m_listItems->GetClientData(nItem);
		CChampionshipTypeTable::tTableIt it = m_Types.find(nId);
		
		if(it == m_Types.end())
			break;
			
		CChampionshipTypeTable::tDATA& data = it->second;
		
		data.name = m_textName->GetValue();
		m_listItems->SetString(nItem, data.name);

	}while(0);
}

void udfChampionshipTypeMngr::OnSave( wxCommandEvent& event )
{
	OnUpdateCode(event);
	
	CChampionshipTypeTable table(m_pCon);
	CChampionshipTypeTable::tTableMap storedCats;
	table.GetTable(storedCats);
		
	CChampionshipTypeTable::tTableIt listIt = storedCats.begin();
	while(listIt != storedCats.end())
	{
		CChampionshipTypeTable::tTableIt rLstIt = m_Types.find(listIt->first);
		if(rLstIt == m_Types.end())
		{
			table.DelRow(listIt->first);
		}
		else if(rLstIt != m_Types.end() && rLstIt->first == listIt->first)
		{
			CChampionshipTypeTable::tDATA& data = listIt->second;
			CChampionshipTypeTable::tDATA& cData = rLstIt->second;
			if( data.name != cData.name )
			{
				data.name = cData.name;
				table.UpdateRow(listIt->first, data);
			}
			m_Types.erase(rLstIt);
		}
		listIt++;
	}
	
	if(m_Types.size() > 0)
	{
		//insert data here
		CChampionshipTypeTable::tTableIt rLstIt = m_Types.begin();
		while(rLstIt != m_Types.end())
		{
			CChampionshipTypeTable::tDATA& data = rLstIt->second;
			table.AddRow(data);
			rLstIt++;
		}
	}
	
	EndDialog(wxID_OK);
}

void udfChampionshipTypeMngr::OnDiscard( wxCommandEvent& event )
{
	EndDialog(wxID_CANCEL);
}
