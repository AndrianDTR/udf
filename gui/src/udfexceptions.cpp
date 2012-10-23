#include "udfexceptions.h"

#include "string_def.h"
#include "wx/msgdlg.h"

int ShowError(wxString msg, int style, wxWindow* parent)
{
	return wxMessageBox(msg, STR_ERROR, style, parent);
}

int ShowWarning(wxString msg, int style, wxWindow* parent)
{
	return wxMessageBox(msg, STR_WARNING, style, parent);
}

int ShowQuestion(wxString msg, wxString title, int style, wxWindow* parent)
{
	return wxMessageBox(msg, title, style, parent);
}
