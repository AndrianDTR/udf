#include "udfPayment.h"
#include "udfexceptions.h"
#include "wx/regex.h"

udfPayment::udfPayment( wxWindow* parent )
: Payment( parent )
{
	wxDateTime dt = m_datePay->GetValue();
	dt.Add(wxDateSpan(1));
	m_dateExpire->SetValue(dt);
}

void udfPayment::OnSave( wxCommandEvent& event )
{
	do
	{
		wxRegEx reSum(wxT("[0-9]+(\.([0-9])+)?"));
		if (!m_checkFree->GetValue() && !reSum.Matches(m_textSum->GetValue()) )
		{
			ShowWarning(STR_ERR_INVALID_SUM);
			break;
		}
		
		EndModal(wxID_OK);
	}while(0);
}

void udfPayment::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
