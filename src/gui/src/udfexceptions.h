#ifndef __udf_exceptions_h__
#define __udf_exceptions_h__

#include "wx/string.h"
#include "wx/window.h"

#define TEST_BREAK(val, expr, MSG)		if(val != expr){ShowError(MSG); break;}

int ShowError(wxString msg, int style = wxOK|wxICON_ERROR, wxWindow* parent = NULL);
int ShowWarning(wxString msg, int style = wxOK|wxICON_WARNING, wxWindow* parent = NULL);
int ShowQuestion(wxString msg, wxString title, int style = wxYES|wxNO|wxICON_QUESTION, wxWindow* parent = NULL);

#endif // __udf_exceptions_h__
