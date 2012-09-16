#include "udfCsTours.h"

udfCsTours::udfCsTours( wxWindow* parent, unsigned int nCsId )
: CsTours( parent )
, m_pCon(NULL)
, m_nCsId(nCsId)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshList();
}

void udfCsTours::RefreshList()
{
	m_Tours.clear();
	m_listTours->Clear();
	CChampionshipToursTable(m_pCon).GetTable(m_Tours);
	/*
	CChampionshipToursTable::tTableIt it = m_Tours.begin();
	while(it != m_Tours.end())
	{
		CChampionshipToursTable::tDATA& data = it->second;
		int nPos = m_listTours->GetCount();
		m_listTours->Insert(data.name, nPos, (void*)&it->first);
		it++;
	}
	//*/
}

void udfCsTours::OnSelectTour( wxCommandEvent& event )
{
	// TODO: Implement OnSelectTour
}

void udfCsTours::OnAddTour( wxCommandEvent& event )
{
	// TODO: Implement OnAddTour
}

void udfCsTours::OnRemoveTour( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveTour
}

void udfCsTours::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfCsTours::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

