#include "udfPaymentHistory.h"
#include "udfPayment.h"

#include "string_def.h"

udfPaymentHistory::udfPaymentHistory( wxWindow* parent, unsigned long nId, char cType )
: PaymentHistory( parent )
, m_nPersonId(nId)
, m_cType(cType)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshHeaders();
	RefreshList();
}

void udfPaymentHistory::RefreshHeaders()
{
	int index = 0;
	m_listPayments->InsertColumn(index++, STR_PAY_DATE, wxLIST_FORMAT_LEFT, 100);
	m_listPayments->InsertColumn(index++, STR_EXP_DATE, wxLIST_FORMAT_LEFT, 100);
	m_listPayments->InsertColumn(index++, STR_SUM, wxLIST_FORMAT_LEFT, -1);
}

void udfPaymentHistory::RefreshList()
{
	m_listPayments->ClearAll();
	
	
}

void udfPaymentHistory::OnAdd( wxCommandEvent& event )
{
	udfPayment	dlg(this);
	if(dlg.ShowModal() == wxID_OK)
	{
		//get info from dlg and store it
	}
}

void udfPaymentHistory::OnUpdate( wxCommandEvent& event )
{
	udfPayment	dlg(this);
	// fill dialog fields
	if(dlg.ShowModal() == wxID_OK)
	{
		//get info from dlg and store it
	}
}

void udfPaymentHistory::OnRemove( wxCommandEvent& event )
{
// TODO: Implement OnRemove
}

void udfPaymentHistory::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfPaymentHistory::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

