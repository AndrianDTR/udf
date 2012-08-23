#include "udfCodeDialog.h"

udfCodeDialog::udfCodeDialog( wxWindow* parent )
:
CodeDialog( parent )
{

}

void udfCodeDialog::RefreshList()
{
	m_listItems->Clear();
	
	tListIt it;
	for(it = m_listMap.begin(); it != m_listMap.end(); it++)
	{
		unsigned int nNextId = m_listItems->GetCount();
		
		m_listItems->Insert(it->second.name, nNextId, (void*)it->first);
	}
}

void udfCodeDialog::OnAdd( wxCommandEvent& event )
{
	wxString code = m_textCode->GetValue();
	wxString name = m_textName->GetValue();
	
	if(!name.empty() && !code.empty())
	{
		tDATA data;
		data.name = name;
		code.ToLong(&data.code);
		unsigned int nNextId = m_listMap.size() + 1;
		
		m_listMap.insert(std::make_pair(nNextId, data));
	}
	RefreshList();
}

void udfCodeDialog::OnRemove( wxCommandEvent& event )
{
	int nItem = m_listItems->GetSelection();
	if(nItem > -1)
	{
		unsigned int nId = (unsigned int)(m_listItems->GetClientData(nItem));
		m_listMap.erase(nId);
		m_listItems->Delete(nItem);
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
	tDATA	data;
	data.nId = nId;
	data.code = code;
	data.name = name;
	m_listMap.insert(std::make_pair(nId, data));
	RefreshList();
	m_listItems->Insert(it->second.name, nNextId, (void*)it->first);
}

udfCodeDialog::tListMap udfCodeDialog::GetResultList()
{
	return m_listMap;
}

