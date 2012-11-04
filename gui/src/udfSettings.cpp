#include "udfSettings.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

udfSettings::udfSettings( wxWindow* parent )
: Settings( parent )
, m_pCon(NULL)
{
	Refresh();
}

void udfSettings::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfSettings::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfSettings::Refresh()
{
	/*
	 * 1. Read connection data
	 * 2. Read tour type data
	 */
}

