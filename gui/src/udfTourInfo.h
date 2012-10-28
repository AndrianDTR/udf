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

class CTourCellAttrProvider : public wxGridCellAttrProvider
{
public:
    CTourCellAttrProvider();
    virtual ~CTourCellAttrProvider();

    virtual wxGridCellAttr *GetAttr(int row, int col,
        wxGridCellAttr::wxAttrKind  kind) const;

private:
    wxGridCellAttr *m_attrForOddRows;
};

/** Implementing TourInfo */
class udfTourInfo : public TourInfo
{
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

protected:
	void			OnCellLeftClick(wxGridEvent& event);

protected:
	void			CreateNewTour();
	void			FillData();

public:
	bool			Show(bool show = true);
	void			SetMainWindow(udfMainFrameBase* pMain) {m_pMainWindow = pMain;};
	void			SetCsTreeItem(wxTreeCtrl* pTree, wxTreeItemId& parentItem, wxTreeItemId& itemId) {m_pTree = pTree; m_parentItem = parentItem; m_itemId = itemId;};

};

#endif // __udfTourInfo__
