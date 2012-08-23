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
		unsigned int nNextId = m_listItems->GetCount();
		tDATA* data = new tDATA();
		data->nId = nNextId;
		data->name = name;
		code.ToLong(&data->code);
			
		m_listItems->Insert(name, nNextId, data);
	}
}

void udfCodeDialog::OnRemove( wxCommandEvent& event )
{
	int nItem = m_listItems->GetSelection();
	if(nItem > -1)
	{
		tDATA* data = (tDATA*)m_listItems->GetClientData(nItem);
		if(data)
		{
			delete data;
			data = NULL;
		}
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
	unsigned int nNextId = m_listItems->GetCount();
	tDATA* data = new tDATA();
	data->code = code;
	data->nId = nId;
	data->name = name;
	
	DEBUG_PRINTF("Add data: %d", data);
	//int n = m_listItems->Append(name);
	//m_listItems->SetClientData(n, (void*)data);
	m_listItems->Insert(name, nNextId, (void*)data);
}

udfCodeDialog::tListMap udfCodeDialog::GetResultList()
{
	tListMap listMap;
	int it = 0;
	for(it = 0; it < m_listItems->GetCount(); ++it)
	{
		
		tDATA* data = (tDATA*)m_listItems->GetClientData(it);
		listMap.insert(std::make_pair(data->nId, *data));
	}
	return listMap;
}

void udfCodeDialog::OnSelectItem(wxCommandEvent& event)
{
	unsigned int nItem = m_listItems->GetSelection();
	m_bpRemove->Disable();
	tDATA* data = (tDATA*)m_listItems->GetClientData(nItem);
	
	DEBUG_PRINTF("Select data: %d", data);
	if(data)
	{
		wxString code = wxString::Format(wxT("%ld"), data->code);
		m_textCode->SetValue(code);
		m_textName->SetValue(data->name);
		m_bpRemove->Enable();
	}
}

void udfCodeDialog::OnUpdateCode(wxCommandEvent& event)
{
	unsigned int nItem = m_listItems->GetSelection();
	wxString code = m_textCode->GetValue();
	wxString name = m_textName->GetValue();
	tDATA* data = (tDATA*)m_listItems->GetClientData(nItem);
	
	if(data && !name.empty() && !code.empty())
	{
		data->name = name;
		code.ToLong(&data->code);
		m_listItems->SetString(nItem, name);
	}
}

void udfCodeDialog::SetListName(wxString listName)
{
	m_sbListSizer->GetStaticBox()->SetLabel(listName);
}
