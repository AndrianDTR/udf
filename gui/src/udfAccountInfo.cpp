#include "udfAccountInfo.h"

udfAccountInfo::udfAccountInfo( wxWindow* parent )
:
AccountInfo( parent )
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
