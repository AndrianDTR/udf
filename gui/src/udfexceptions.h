#ifndef __udf_exceptions_h__
#define __udf_exceptions_h__

#include "wx/string.h"

#define TEST_BREAK(val, expr, MSG)		if(val != expr){ShowError(MSG); break;}

void ShowError(wxString msg);
void ShowWarning(wxString msg);

#endif // __udf_exceptions_h__
