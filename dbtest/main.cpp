#include <stdio.h>

#include "connection_data.h"

#include "dberrors.h"
#include "dbconnection.h"
#include "tagecategory.h"
#include "tagecode.h"

int main(int argc, char **argv)
{
	long res = UDF_E_FAIL;
	do
	{
		CDbConnection* m_pCon = new CDbConnection();
		res = m_pCon->Open(szUrl, szUser, szPass, szSchema);
		if(UDF_OK != res)
			break;
		
		/*
		 * CAgeCategory
		 */ 
		CAgeCategoryTable ageCatTbl(m_pCon);
		CAgeCategoryTable::tAgeCategoryMap* m;
		CAgeCategoryTable::tAgeCategoryMapIterator it;
		
		CAgeCategoryTable::tDATA ageCatData;
		ageCatData.descr = string("Test Дорослі-8");
		
		// Add row
		res = ageCatTbl.AddRow(ageCatData);
		if(UDF_OK != res)
			break;
		printf("CAgeCategoryTable::AddRow ID = %d, res = %d, %s\n", ageCatData.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = ageCatTbl.GetRow(ageCatData.id, ageCatData);
		if(UDF_OK != res)
			break;
		printf("CAgeCategoryTable::GetRow ID = %d, res = %d, %s\n", ageCatData.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = ageCatTbl.Find(&m, ageCatData);
		if(UDF_OK != res)
			break;
		printf("CAgeCategoryTable::Find res = %d, %s\n", res, GetErrorMsg(res).c_str());
		
		it = m->begin();
		while(it != m->end())
		{
			printf("%d = %s\n", it->first, it->second.descr.c_str());
			it++;
		}
		
		// Get table
		res = ageCatTbl.GetTable(&m);
		if(UDF_OK != res)
			break;
		printf("CAgeCategoryTable::GetTable res = %d, %s\n", res, GetErrorMsg(res).c_str());
		
		it = m->begin();
		while(it != m->end())
		{
			printf("%d = %s\n", it->first, it->second.descr.c_str());
			it++;
		}
		
		// Remove row
		res = ageCatTbl.DelRow(ageCatData.id);
		if(UDF_OK != res)
			break;
		printf("CAgeCategoryTable::DelRow ID = %d, res = %d, %s\n", ageCatData.id, res, GetErrorMsg(res).c_str());
		
		/*
		 * CAgeCode
		 */ 
		CAgeCodeTable ageCodeTbl(m_pCon);
		CAgeCodeTable::tAgeCodeMap* ageCodeM;
		CAgeCodeTable::tAgeCodeMapIterator ageCodeIt;
		
		CAgeCodeTable::tDATA ageCodeData;
		ageCodeData.descr = string("Test Дорослі-8");
		
		// Add row
		res = ageCodeTbl.AddRow(ageCodeData);
		if(UDF_OK != res)
			break;
		printf("CAgeCodeTable::AddRow ID = %d, res = %d, %s\n", ageCodeData.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = ageCodeTbl.GetRow(ageCodeData.id, ageCodeData);
		if(UDF_OK != res)
			break;
		printf("CAgeCodeTable::GetRow ID = %d, res = %d, %s\n", ageCodeData.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = ageCodeTbl.Find(&ageCodeM, ageCodeData);
		if(UDF_OK != res)
			break;
		printf("CAgeCodeTable::Find res = %d, %s\n", res, GetErrorMsg(res).c_str());
		
		ageCodeIt = ageCodeM->begin();
		while(ageCodeIt != ageCodeM->end())
		{
			printf("%d = %s\n", ageCodeIt->first, ageCodeIt->second.descr.c_str());
			ageCodeIt++;
		}
		
		// Get table
		res = ageCodeTbl.GetTable(&ageCodeM);
		if(UDF_OK != res)
			break;
		printf("CAgeCodeTable::GetTable res = %d, %s\n", res, GetErrorMsg(res).c_str());
		
		ageCodeIt = ageCodeM->begin();
		while(ageCodeIt != ageCodeM->end())
		{
			printf("%d = %s\n", ageCodeIt->first, ageCodeIt->second.descr.c_str());
			ageCodeIt++;
		}
		
		// Remove row
		res = ageCodeTbl.DelRow(ageCodeData.id);
		if(UDF_OK != res)
			break;
		printf("CAgeCodeTable::DelRow ID = %d, res = %d, %s\n", ageCodeData.id, res, GetErrorMsg(res).c_str());
		
		
		
	}while(0);
	
	printf("Open OK, res = %d, %s\n", res, GetErrorMsg(res).c_str());
	
	return 0;
}
