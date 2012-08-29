#include "udfexceptions.h"

#include "string_def.h"
#include "wx/msgdlg.h"

void ShowError(wxString msg)
{
	wxMessageBox(msg, STR_ERROR, wxOK|wxICON_ERROR);
}

void ShowWarning(wxString msg)
{
	wxMessageBox(msg, STR_WARNING, wxOK|wxICON_WARNING);
}

