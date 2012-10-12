#include "udfPayment.h"

udfPayment::udfPayment( wxWindow* parent )
: Payment( parent )
{
	wxDateTime dt = m_datePay->GetValue();
	dt.Add(wxDateSpan(1));
	m_dateExpire->SetValue(dt);
}

void udfPayment::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfPayment::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
