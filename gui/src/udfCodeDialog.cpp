#include "udfCodeDialog.h"
#include "common.h"

udfCodeDialog::udfCodeDialog( wxWindow* parent )
:
CodeDialog( parent )
{
	m_bpRemove->Disable();
}

void udfCodeDialog::OnAdd( wxCommandEvent& event )
{
	wxString code = m_textCode->GetValue();
	wxString name = m_textName->GetValue();
	
	if(!name.empty() && !code.empty())
	{
		unsigned int nNextId = -m_listItems->GetCount();
		tDATA data;
		data.nId = nNextId;
		data.name = name;
		code.ToLong(&data.code);
			
		m_listMap.insert(std::make_pair(nNextId, data));
		
		RefreshList();
	}
}

void udfCodeDialog::OnRemove( wxCommandEvent& event )
{
	int nItem = m_listItems->GetSelection();
	int* pnId = (int*)m_listItems->GetClientData(nItem);
	
	m_listMap.erase(*pnId);
	
	RefreshList();
}

void udfCodeDialog::OnUpdateCode(wxCommandEvent& event)
{
	unsigned int nItem = m_listItems->GetSelection();
	wxString code = m_textCode->GetValue();
	wxString name = m_textName->GetValue();
	
	int* pnId = (int*)m_listItems->GetClientData(nItem);
	tListIt it = m_listMap.find(*pnId);
	
	if(it != m_listMap.end() && !name.empty() && !code.empty())
	{
		tDATA data = it->second;
		data.name = name;
		code.ToLong(&data.code);
		m_listItems->SetString(nItem, name);
	}
}

void udfCodeDialog::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfCodeDialog::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfCodeDialog::AddListItem(unsigned int nId, wxString name, long code)
{
	tDATA data;
	data.code = code;
	data.nId = nId;
	data.name = name;
	
	m_listMap.insert(std::make_pair(data.nId, data));
}

udfCodeDialog::tListMap udfCodeDialog::GetResultList()
{
	return m_listMap;
}

void udfCodeDialog::OnSelectItem(wxCommandEvent& event)
{
	unsigned int nItem = m_listItems->GetSelection();
	int* pnId = (int*)m_listItems->GetClientData(nItem);

	m_bpRemove->Disable();
	
	tListIt it = m_listMap.find(*pnId);
	if(it != m_listMap.end())
	{
		tDATA data = it->second;
		wxString code = wxString::Format(wxT("%ld"), data.code);
		m_textCode->SetValue(code);
		m_textName->SetValue(data.name);
		m_bpRemove->Enable();
	}
}

void udfCodeDialog::SetListName(wxString listName)
{
	m_sbListSizer->GetStaticBox()->SetLabel(listName);
}

void udfCodeDialog::OnSearch(wxCommandEvent& event)
{
	wxString search = m_textSearch->GetValue().Upper();
	tListIt		item;
	
	m_listItems->Clear();
	for(item = m_listMap.begin(); item != m_listMap.end(); item++)
	{
		tDATA data = item->second;
		if(data.name.Upper().Contains(search))
		{
			int* pnId = new int();
			*pnId = item->first;
			int pos = m_listItems->GetCount();
			m_listItems->Insert(data.name, pos, (void*)pnId);
		}
	}
}

void udfCodeDialog::RefreshList()
{
	tListIt		item;
	
	m_listItems->Clear();
	for(item = m_listMap.begin(); item != m_listMap.end(); item++)
	{
		tDATA data = item->second;
		int pos = m_listItems->GetCount();
		int* pnId = new int();
		*pnId = item->first;
		m_listItems->Insert(data.name, pos, (void*)pnId);
	}
}
