/*********************************************************************
 * Name:      	main.cpp
 * Purpose:   	Implements simple wxWidgets application with GUI
 * 				created using wxFormBuilder.
 * Author:
 * Created:
 * Copyright:
 * License:   	wxWidgets license (www.wxwidgets.org)
 *
 * Notes:		Note that all GUI creation code is implemented in
 * 				gui.cpp source file which is generated by wxFormBuilder.
 *********************************************************************/

#include "main.h"

#include "cdbmanager.h"
#include "dbutils.h"

#include "locale.h"
// initialize the application
IMPLEMENT_APP(MainApp);

////////////////////////////////////////////////////////////////////////////////
// application class implementation
////////////////////////////////////////////////////////////////////////////////

bool MainApp::OnInit()
{
	bool res = false;
	do{
		setlocale(LC_ALL, "C");
		try
		{
			CDbConnection* pCon = CDbManager::Instance()->GetConnection();
			SetGlobalDbConnection(pCon);
		}
		catch(...)
		{
			wxMessageBox(_("ERROR. Open MySQL connection fail. Program will be closed."), _("Error"),wxOK|wxCENTRE|wxICON_STOP);
			break;
		}

		SetTopWindow( new udfMainFrameBase( NULL ) );
		GetTopWindow()->Show();
		res = true;
	}while(0);
	// true = enter the main loop
	return res;
}
