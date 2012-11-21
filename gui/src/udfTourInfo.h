#ifndef __udfTourInfo__
#define __udfTourInfo__

/**
@file
Subclass of TourInfo, which is generated by wxFormBuilder.
*/

#include "udf.h"
#include "cdbmanager.h"

//// end generated include

class udfMainFrameBase;

/** Implementing TourInfo */
class udfTourInfo : public TourInfo
{
protected:
	typedef std::map<int, unsigned int>				tI2UiMap;
	typedef std::map<unsigned int, int>				tUi2IMap;

public:
	/** Constructor */
	udfTourInfo( wxWindow* parent );
//// end generated class members

private:
	CDbConnection*			m_pCon;
	udfMainFrameBase*		m_pMainWindow;
	wxTreeCtrl*				m_pTree;
	wxTreeItemId			m_parentItem;
	wxTreeItemId			m_itemId;
	unsigned int 			m_tourType;

	tUi2IMap				m_id2row;
	tI2UiMap				m_row2id;
	tUi2IMap				m_id2col;
	tI2UiMap				m_col2id;
	
	int						m_fntSize;

protected:
	void			OnCellLeftClick(wxGridEvent& event);
	void			OnUpdate(wxCommandEvent& event);
	void			OnResults(wxCommandEvent& event);
	void			OnRemove(wxCommandEvent& event);
	void			OnAddNext(wxCommandEvent& event);
	void			OnScaleChange(wxSpinEvent& event);

protected:
	void			CreateNewTour();
	void			CalculatePlaces();

public:
	bool			Show(bool show = true);
	void			SetMainWindow(udfMainFrameBase* pMain) {m_pMainWindow = pMain;};
	void			SetCsTreeItem(wxTreeCtrl* pTree, wxTreeItemId& parentItem, wxTreeItemId& itemId) {m_pTree = pTree; m_parentItem = parentItem; m_itemId = itemId;};

};

#endif // __udfTourInfo__
