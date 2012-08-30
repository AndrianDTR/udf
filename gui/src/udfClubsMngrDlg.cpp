#include "udfClubsMngrDlg.h"
#include "udfAccountInfo.h"
#include "udfDancersMngrDlg.h"
#include "udfTarinersMngrDlg.h"
#include "udfDirectorInfo.h"

#include "string_def.h"

udfClubsMngrDlg::udfClubsMngrDlg( wxWindow* parent )
: ClubsMngrDlg( parent )
, m_pCon(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
	
	RefreshList();
	RefreshCities();
}

void udfClubsMngrDlg::RefreshCities()
{
	RefreshCountries();
	
	CCitiesTable table(m_pCon);
	table.GetTable(m_Cities);
	
	m_comboCity->Clear();
	
	CCitiesTable::tTableIt it = m_Cities.begin();
	while(it != m_Cities.end())
	{
		CCitiesTable::tDATA& data = it->second;
		int nPos = m_comboCity->GetCount();
		
		CCountriesTable::tTableIt cIt = m_Countries.find(data.countryId);
		if(cIt != m_Countries.end())
		{
			CCountriesTable::tDATA& cData = cIt->second;
			wxString city = wxString::Format(STR_FORMAT_CITY_NAME, data.Name, cData.name);
			m_comboCity->Insert(city, nPos, (void*)&it->first);
		}
		it++;
	}
	m_comboCity->AutoComplete(m_comboCity->GetStrings());
}

void udfClubsMngrDlg::RefreshCountries()
{
	CCountriesTable table(m_pCon);
	table.GetTable(m_Countries);
}

void udfClubsMngrDlg::RefreshList()
{
	CClubsTable table(m_pCon);
	table.GetTable(m_Clubs);
	
	m_listClubs->Clear();
	CClubsTable::tTableIt it = m_Clubs.begin();
	while(it != m_Clubs.end())
	{
		CClubsTable::tDATA& data = it->second;
		int nPos = m_listClubs->GetCount();
		m_listClubs->Insert(data.name, nPos, (void*)&it->first);
		
		it++;
	}
}

void udfClubsMngrDlg::OnAddClub( wxCommandEvent& event )
{
	
}

void udfClubsMngrDlg::OnRemoveClub( wxCommandEvent& event )
{
	// TODO: Implement OnRemoveClub
}

void udfClubsMngrDlg::OnAccountInfo( wxCommandEvent& event )
{
	udfAccountInfo dlg(this);
	dlg.ShowModal();
}

void udfClubsMngrDlg::OnDirectorInfo( wxCommandEvent& event )
{
	udfDirectorInfo dlg(this);
	dlg.ShowModal();
}

void udfClubsMngrDlg::OnTrainersMngr( wxCommandEvent& event )
{
	udfTarinersMngrDlg dlg(this);
	dlg.ShowModal();
}

void udfClubsMngrDlg::OnDancersMngr( wxCommandEvent& event )
{
	udfDancersMngrDlg dlg(this);
	dlg.ShowModal();
}

void udfClubsMngrDlg::OnSave( wxCommandEvent& event )
{
	EndModal(wxID_OK);
}

void udfClubsMngrDlg::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

int udfClubsMngrDlg::GetSelectedCity()
{
}


