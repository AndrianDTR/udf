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
	m_listPayments->InsertColumn(index++, STR_PAY_DATE, wxLIST_FORMAT_LEFT, 150);
	m_listPayments->InsertColumn(index++, STR_EXP_DATE, wxLIST_FORMAT_LEFT, 150);
	m_listPayments->InsertColumn(index++, STR_SUM, wxLIST_FORMAT_LEFT, -1);
}

void udfPaymentHistory::RefreshList()
{
	m_listPayments->DeleteAllItems();

	CPaymentHistoryTable table(m_pCon);
	CPaymentHistoryTable::tDATA filter = {0};
	filter.personId = m_nPersonId;
	filter.type = m_cType;
	table.AddOrder("pay_date", CPaymentHistoryTable::ST_DESCENDING);
	table.Find(m_payments, filter);

	CPaymentHistoryTable::tTableIt it = m_payments.begin();
	while(it != m_payments.end())
	{
		AddListItem(it);

		it++;
	}
}

void udfPaymentHistory::OnAdd( wxCommandEvent& event )
{
	do
	{
		CPaymentHistoryTable::tDATA data = {0};
		int nPos = m_listPayments->GetItemCount();

		udfPayment	dlg(this);
		if(dlg.ShowModal() == wxID_OK)
		{
			data.id = -nPos;
			data.personId = m_nPersonId;
			data.type = m_cType;
			data.payDate = dlg.GetPayDate().GetTicks();
			data.expDate = dlg.GetExpDate().GetTicks();
			if(dlg.GetFreeCheck())
				data.sum = -1.0;
			else
				data.sum = dlg.GetSum();

			if(UDF_OK != CPaymentHistoryTable(m_pCon).AddRow(data))
				break;

			CPaymentHistoryTable::tTableIt it = m_payments.insert(make_pair(data.id, data)).first;

			AddListItem(it);
		}
	}while(0);
}

void udfPaymentHistory::OnUpdate( wxCommandEvent& event )
{
	do
	{
		unsigned int nItem = m_listPayments->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
		if(-1 == nItem)
			break;
		unsigned int nId = *(int*)m_listPayments->GetItemData(nItem);

		CPaymentHistoryTable::tTableIt it = m_payments.find(nId);
		if(it == m_payments.end())
			break;

		CPaymentHistoryTable::tDATA& data = it->second;

		udfPayment	dlg(this);
		dlg.SetPayDate(data.payDate);
		dlg.SetExpDate(data.expDate);
		if (data.sum == -1.0)
			dlg.SetFreeCheck(true);
		else
			dlg.SetSum(data.sum);
		// fill dialog fields
		if(dlg.ShowModal() == wxID_OK)
		{
			data.payDate = dlg.GetPayDate().GetTicks();
			data.expDate = dlg.GetExpDate().GetTicks();
			if(dlg.GetFreeCheck())
				data.sum = -1.0;
			else
				data.sum = dlg.GetSum();

			if(UDF_OK != CPaymentHistoryTable(m_pCon).UpdateRow(nId, data))
				break;

			int nCol = 1;
			wxListItem info;
			info.SetId(nItem);
			info.SetText(wxDateTime(data.payDate).Format(STR_FORMAT_DATE));
			m_listPayments->SetItem(info);

			info.SetColumn(nCol++);
			info.SetText(wxDateTime(data.expDate).Format(STR_FORMAT_DATE));
			m_listPayments->SetItem(info);

			info.SetColumn(nCol++);
			if (data.sum == -1.0)
				info.SetText(STR_FREE);
			else
				info.SetText(STR_FORMAT(STR_FORMAT_SUM, data.sum));
			m_listPayments->SetItem(info);
		}
	}while(0);
}

void udfPaymentHistory::OnRemove( wxCommandEvent& event )
{
	do
	{
		unsigned int nItem = m_listPayments->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
		if(-1 == nItem)
			break;
		unsigned int nId = *(int*)m_listPayments->GetItemData(nItem);

		if(UDF_OK != CPaymentHistoryTable(m_pCon).DelRow(nId))
			break;

		m_payments.erase(nId);
		m_listPayments->DeleteItem(nItem);
	}while(0);
}

void udfPaymentHistory::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfPaymentHistory::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void udfPaymentHistory::AddListItem(CPaymentHistoryTable::tTableIt& it)
{
	int nCol = 1;
	wxListItem info;
	CPaymentHistoryTable::tDATA& data = it->second;
	int nPos = m_listPayments->GetItemCount();

	info.SetId(nPos);
	info.SetData((void*)&it->first);
	info.SetText(wxDateTime(data.payDate).Format(STR_FORMAT_DATE));

	m_listPayments->InsertItem(info);

	info.SetColumn(nCol++);
	info.SetText(wxDateTime(data.expDate).Format(STR_FORMAT_DATE));
	m_listPayments->SetItem(info);

	info.SetColumn(nCol++);
	if (data.sum == -1.0)
		info.SetText(STR_FREE);
	else
		info.SetText(STR_FORMAT(STR_FORMAT_SUM, data.sum));
	m_listPayments->SetItem(info);
}
