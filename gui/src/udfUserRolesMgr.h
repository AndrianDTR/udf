#ifndef __udfUserRolesMgr__
#define __udfUserRolesMgr__

/**
@file
Subclass of UserRolesMgr, which is generated by wxFormBuilder.
*/

#include "udf.h"

//// end generated include

/** Implementing UserRolesMgr */
class udfUserRolesMgr : public UserRolesMgr
{
	protected:
		// Handlers for UserRolesMgr events.
		void OnAdd( wxCommandEvent& event );
		void OnUpdate( wxCommandEvent& event );
		void OnRemove( wxCommandEvent& event );
		void OnSave( wxCommandEvent& event );
		void OnDiscard( wxCommandEvent& event );
		void OnSelectRole( wxListEvent& event );
	public:
		/** Constructor */
		udfUserRolesMgr( wxWindow* parent );
	//// end generated class members
	
};

#endif // __udfUserRolesMgr__
