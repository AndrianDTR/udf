#ifndef __CTestBase_h__
#define __CTestBase_h__

#include "dberrors.h"
#include "dbconnection.h"

namespace udf_testing
{

class CTestBase {

public:
	CTestBase(CDbConnection* m_pCon);
	virtual ~CTestBase();
	
	virtual void test() = 0;

};

}

#endif // __CTestBase_h__
