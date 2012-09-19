#ifndef __udf_exceptions_h__
#define __udf_exceptions_h__

#include "wx/string.h"

#define TEST_BREAK(val, expr, MSG)		if(val != expr){ShowError(MSG); break;}

int ShowError(wxString msg, int style = wxOK|wxICON_ERROR);
int ShowWarning(wxString msg, int style = wxOK|wxICON_WARNING);

#endif // __udf_exceptions_h__
