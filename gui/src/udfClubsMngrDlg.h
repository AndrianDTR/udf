#ifndef __udfClubsMngrDlg__
#define __udfClubsMngrDlg__

/**
@file
Subclass of ClubsMngrDlg, which is generated by wxFormBuilder.
*/

#include "udf.h"

/** Implementing ClubsMngrDlg */
class udfClubsMngrDlg : public ClubsMngrDlg
{
protected:
	// Handlers for ClubsMngrDlg events.
	void OnAddClub( wxCommandEvent& event );
	void OnRemoveClub( wxCommandEvent& event );
	void OnAccountInfo( wxCommandEvent& event );
	void OnDirectorInfo( wxCommandEvent& event );
	void OnTrainersMngr( wxCommandEvent& event );
	void OnDancersMngr( wxCommandEvent& event );
	void OnSave( wxCommandEvent& event );
	void OnDiscard( wxCommandEvent& event );
	
public:
	/** Constructor */
	udfClubsMngrDlg( wxWindow* parent );
};

#endif // __udfClubsMngrDlg__
