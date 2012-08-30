#include "udfDirectorInfo.h"

udfDirectorInfo::udfDirectorInfo( wxWindow* parent )
: DirectorInfo( parent )
{

}

void udfDirectorInfo::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfDirectorInfo::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

time_t udfDirectorInfo::GetBd()
{
	return m_dateBd->GetValue().GetTicks();
}

wxString udfDirectorInfo::GetEmail()
{
	return m_textEmail->GetValue();
}

wxString udfDirectorInfo::GetName()
{
	return m_textName->GetValue();
}

wxString udfDirectorInfo::GetPhone()
{
	return m_textPhone->GetValue();
}

void udfDirectorInfo::SetBd(time_t date)
{
	m_dateBd->SetValue(wxDateTime(date));
}

void udfDirectorInfo::SetEmail(wxString value)
{
	m_textEmail->SetValue(value);
}

void udfDirectorInfo::SetName(wxString value)
{
	m_textName->SetValue(value);
}

void udfDirectorInfo::SetPhone(wxString value)
{
	m_textPhone->SetValue(value);
}

