#ifndef __udfAddTeamCategory__
#define __udfAddTeamCategory__

/**
@file
Subclass of AddTeamCategory, which is generated by wxFormBuilder.
*/

#include "udf.h"

/** Implementing AddTeamCategory */
class udfAddTeamCategory : public AddTeamCategory
{
protected:
	// Handlers for AddTeamCategory events.
	void OnSave( wxCommandEvent& event );
	void OnDiscard( wxCommandEvent& event );
	
public:
	/** Constructor */
	udfAddTeamCategory( wxWindow* parent, wxString name);
	
public:
	wxString	GetCompisitionName() { return m_textComposition->GetValue();};
};

#endif // __udfAddTeamCategory__
