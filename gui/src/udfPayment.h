#ifndef __udfPayment__
#define __udfPayment__

/**
@file
Subclass of Payment, which is generated by wxFormBuilder.
*/

#include "udf.h"
#include "string_def.h"

//// end generated include

/** Implementing Payment */
class udfPayment : public Payment
{
protected:
	// Handlers for Payment events.
	void OnSave( wxCommandEvent& event );
	void OnDiscard( wxCommandEvent& event );
public:
	/** Constructor */
	udfPayment( wxWindow* parent );
//// end generated class members
	
public:
	void				SetPayDate(wxDateTime pay){m_datePay->SetValue(pay);};
	const wxDateTime	GetPayDate(){return m_datePay->GetValue();};
	void				SetExpDate(wxDateTime pay){m_dateExpire->SetValue(pay);};
	const wxDateTime	GetExpDate(){return m_dateExpire->GetValue();};
	
	void				SetSum(double sum){m_textSum->SetValue(wxString::Format(STR_FORMAT_SUM, sum));};
	const double		GetSum(){double val = 0; m_textSum->GetValue().ToDouble(&val); return val;};
	
};

#endif // __udfPayment__
