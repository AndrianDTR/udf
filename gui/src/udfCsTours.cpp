#include "udfCsTours.h"

udfCsTours::udfCsTours( wxWindow* parent, unsigned int nCsId )
: CsTours( parent )
, m_pCon(NULL)
, m_nCsId(nCsId)
{
	m_pCon = CDbManager::Instance()->GetConnection();
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
