#include "udfPayment.h"

udfPayment::udfPayment( wxWindow* parent )
:
Payment( parent )
{

}

void udfPayment::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfPayment::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
