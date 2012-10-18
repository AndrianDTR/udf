#include "udfCsTours.h"

udfCsTours::udfCsTours( wxWindow* parent, unsigned int type, int limit)
: CsTours( parent )
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshTypes();
	
	if(m_comboType->GetCount())
	{
		if(-1 != type)
			m_comboType->SetSelection(type);
		else
			m_comboType->SetSelection(0);
	}
	
	m_textLimit->SetValue(wxString::Format(_("%d"), limit));
}

void udfCsTours::RefreshTypes()
{
	m_types.clear();
	m_comboType->Clear();
	
	CTourTypesTable(m_pCon).GetTable(m_types);
	
	CTourTypesTable::tTableIt it = m_types.begin();
	while(it != m_types.end())
	{
		CTourTypesTable::tDATA& data = it->second;
		int nPos = m_comboType->GetCount();
		
		m_comboType->Insert(data.name, nPos, (void*)&it->first);
		it++;
	}
}

unsigned int udfCsTours::GetTypeId()
{
	unsigned int res = -1;
	
	do
	{
	}while(0);
	
	return res;
}

int udfCsTours::GetLimit()
{
	int limit = -1;
	
	return limit;
}

void udfCsTours::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfCsTours::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
