#include "udfBlockInfo.h"
#include "udfMainFrameBase.h"

#include "db.h"

#include "udfexceptions.h"
#include "udfuiutils.h"
#include "string_def.h"

udfBlockInfo::udfBlockInfo( wxWindow* parent )
: BlockInfo( parent )
, m_pCon(NULL)
, m_pMainWindow(NULL)
, m_pTree(NULL)
, m_pParentItem(NULL)
, m_pTreeItemId(NULL)
{
	m_pCon = CDbManager::Instance()->GetConnection();

}

bool udfBlockInfo::Show(bool show)
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

void udfBlockInfo::OnUpdateBlock( wxCommandEvent& event )
{
// TODO: Implement OnUpdateBlock
}

void udfBlockInfo::OnBlockCategories( wxCommandEvent& event )
{
// TODO: Implement OnBlockCategories
}

void udfBlockInfo::OnCellChange( wxGridEvent& event )
{
// TODO: Implement OnCellChange
}

void udfBlockInfo::OnCellLeftClick( wxGridEvent& event )
{
// TODO: Implement OnCellLeftClick
}

void udfBlockInfo::OnSelectCell( wxGridEvent& event )
{
// TODO: Implement OnSelectCell
}
