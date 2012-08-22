#ifndef __udfCategoriesData_h__
#define __udfCategoriesData_h__

#include "tagecategory.h"
#include "tcategories.h"
#include "tdancetypes.h"
#include "tliga.h"

#include "dbconnection.h"
#include "cdbmanager.h"

class udfCategoriesData 
{
	CDbConnection* m_pCon;
	
	CAgeCategoryTable::tTableMap	m_mapAgeCategories;
	CDanceTypesTable::tTableMap		m_mapDanceTypes;
	CLigaTable::tTableMap			m_mapLigues;
	CCategoriesTable::tTableMap		m_mapCategories;
	
public:
	udfCategoriesData();
	virtual ~udfCategoriesData();

	virtual void RealoadAgeCategories();
	virtual void RealoadDanceTypes();
	virtual void RealoadLigues();
	virtual void RealoadCategories();
	virtual void RealoadAll();
	
	virtual bool IsInListOfAgeCategories(wxString name);
	virtual bool IsInListOfDanceTypes(wxString name);
	virtual bool IsInListOfLugues(wxString name);
	
};

#endif // __udfCategoriesData_h__
