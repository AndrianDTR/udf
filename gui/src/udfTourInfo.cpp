#include "udfTourInfo.h"
#include "udfMainFrameBase.h"

#include "db.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

udfTourInfo::udfTourInfo( wxWindow* parent )
: TourInfo( parent )
, m_pCon(NULL)
, m_pMainWindow(NULL)
, m_pTree(NULL)
, m_pParentItem(NULL)
, m_pTreeItemId(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();
}

bool udfTourInfo::Show(bool show)
{
	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		if(!pCon)
			break;
			
		if(!m_pMainWindow || !m_pTree || m_pParentItem || !m_pTreeItemId)
			break;
		

	}while(0);
	
	wxPanel::Show(show);
}