#include "udfexceptions.h"

#include "string_def.h"
#include "wx/msgdlg.h"

int ShowError(wxString msg, int style)
{
	wxMessageBox(msg, STR_ERROR, style);
}

int ShowWarning(wxString msg, int style)
{
	return wxMessageBox(msg, STR_WARNING, style);
}

