#include "udfAccountInfo.h"

udfAccountInfo::udfAccountInfo( wxWindow* parent )
: AccountInfo( parent )
{

}

void udfAccountInfo::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfAccountInfo::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

wxString udfAccountInfo::GetLogin()
{
	return m_textLogin->GetValue();
}

wxString udfAccountInfo::GetPass()
{
	return m_textPass->GetValue();
}

void udfAccountInfo::OnShowPass(wxCommandEvent& event)
{
	long sf = m_textPass->GetWindowStyleFlag();
	sf |= wxTE_PASSWORD;
	if(m_checkShowPass->GetValue())
	{
		sf &= ~wxTE_PASSWORD; 
	}
	m_textPass->SetWindowStyleFlag(sf);
}

void udfAccountInfo::SetLogin(wxString login)
{
	m_textLogin->SetValue(login);
}

void udfAccountInfo::SetPass(wxString pass)
{
	m_textPass->SetValue(pass);
}

