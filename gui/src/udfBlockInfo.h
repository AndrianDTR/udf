#ifndef __udfBlockInfo__
#define __udfBlockInfo__

/**
@file
Subclass of BlockInfo, which is generated by wxFormBuilder.
*/

#include "udf.h"
#include "cdbmanager.h"

class udfMainFrameBase;

/** Implementing BlockInfo */
//// end generated include
class udfBlockInfo : public BlockInfo
{
protected:
typedef std::map<int, unsigned int>				tI2UiMap;
typedef std::map<unsigned int, int>				tUi2IMap;

protected:
	// Handlers for BlockInfo events.
	void OnUpdateBlock( wxCommandEvent& event );
	void OnBlockCategories( wxCommandEvent& event );
	void OnJudgesTemManager( wxCommandEvent& event );
	void OnCellChange( wxGridEvent& event );
	void OnCellLeftClick( wxGridEvent& event );
	void OnLabelClick( wxGridEvent& event );
	void OnRemove( wxCommandEvent& event );
	void OnScaleChange(wxSpinEvent& event);
	
public:
	/** Constructor */
	udfBlockInfo( wxWindow* parent);
//// end generated class members

protected:
	
	tI2UiMap				m_RowIdMap;
	tI2UiMap				m_ColIdMap;
	tUi2IMap				m_IdRowMap;
	tUi2IMap				m_IdColMap;
	
private:
	int						m_fntSize;
	CDbConnection*			m_pCon;
	udfMainFrameBase*		m_pMainWindow;
	wxTreeCtrl*				m_pTree;
	wxTreeItemId			m_parentItem;
	wxTreeItemId			m_itemId;

private:
	bool 			ValidateData();
	void			CreateNewBlock();
	void			FillData();

public:
	bool			Show(bool show = true);
	void			SetMainWindow(udfMainFrameBase* pMain) {m_pMainWindow = pMain;};
	void			SetCsTreeItem(wxTreeCtrl* pTree, wxTreeItemId& parentItem, wxTreeItemId& itemId) {m_pTree = pTree; m_parentItem = parentItem; m_itemId = itemId;};
};

#endif // __udfBlockInfo__
