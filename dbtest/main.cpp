#include <stdio.h>

#include "dberrors.h"
#include "dbconnection.h"
#include "tagecategory.h"

int main(int argc, char **argv)
{
	long res = UDF_E_FAIL;
	do
	{
		CDbConnection* m_pCon = new CDbConnection();
		res = m_pCon->Open("192.169.10.17","andrian","dataNet","udf");
		if(UDF_OK != res)
			break;
		
		CAgeCategoryTable tbl(m_pCon);
		CAgeCategoryTable::tAgeCategoryMap* m;
		
		CAgeCategoryTable::tDATA data;
		data.descr = string("Test Дорослі-8");
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("AddRow ID = %d, res = %d, %s\n", data.id, res, GetErrorMsg(res).c_str());
		
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("DelRow ID = %d, res = %d, %s\n", data.id, res, GetErrorMsg(res).c_str());
		
		res = tbl.GetRow(2, data);
		if(UDF_OK != res)
			break;
		printf("GetRow ID = %d, res = %d, %s\n", data.id, res, GetErrorMsg(res).c_str());
		
		
		res = tbl.GetTable(&m);
		if(UDF_OK != res)
			break;
		printf("GetTable res = %d, %s\n", res, GetErrorMsg(res).c_str());
		
		CAgeCategoryTable::tAgeCategoryMapIterator it = m->begin();
		while(it != m->end())
		{
			printf("%d = %s\n", it->first, it->second.descr.c_str());
			it++;
		}
		
		CAgeCategoryTable::tDATA filter;
		filter.descr = string("Дорослі");
		res = tbl.Find(&m, filter);
		if(UDF_OK != res)
			break;
		printf("Find res = %d, %s\n", res, GetErrorMsg(res).c_str());
		
		it = m->begin();
		while(it != m->end())
		{
			printf("%d = %s\n", it->first, it->second.descr.c_str());
			it++;
		}
		
		printf("Finish res = %d, %s\n", res, GetErrorMsg(res).c_str());
	}while(0);
	
	printf("Open OK, res = %d, %s\n", res, GetErrorMsg(res).c_str());
	
	return 0;
}
