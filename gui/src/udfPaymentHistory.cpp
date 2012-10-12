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
	m_listPayments->DeleteAllItems();
	
	CPaymentHistoryTable table(m_pCon);
	CPaymentHistoryTable::tDATA filter = {0};
	filter.personId = m_nPersonId;
	filter.type = m_cType;
	table.AddOrder("pay_date", CPaymentHistoryTable::ST_ASCENDING);
	table.AddOrder("exp_date", CPaymentHistoryTable::ST_ASCENDING);
	table.Find(m_payments, filter);

	CPaymentHistoryTable::tTableIt it = m_payments.begin();
	while(it != m_payments.end())
	{
		CPaymentHistoryTable::tDATA data = it->second;
		int nPos = m_listPayments->GetItemCount();
		
		int nCol = 1;
		wxListItem info;
		info.SetId(nPos);
		info.SetData((void*)&it->first);
		info.SetText(wxString::Format(STR_FORMAT_DATE, data.payDate));
		
		m_listPayments->InsertItem(info);
		
		info.SetColumn(nCol++);
		info.SetText(wxString::Format(STR_FORMAT_DATE, data.expDate));
		m_listPayments->SetItem(info);
		
		info.SetColumn(nCol++);
		info.SetText(wxString::Format(STR_FORMAT_SUM, data.sum));
		m_listPayments->SetItem(info);
		
		it++;
	}
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

