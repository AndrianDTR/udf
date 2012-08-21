#include <stdio.h>

#include "dberrors.h"
#include "dbconnection.h"
#include "connection_data.h"

#include "tagecategory.h"
#include "tcategories.h"
#include "tchampionship.h"
#include "tchampionshipcategories.h"
#include "tchampionshipjudgesmark.h"
#include "tchampionshipjudgesteam.h"
#include "tchampionshipteam.h"
#include "tchampionshipteamcategories.h"
#include "tchampionshipteamdancers.h"
#include "tchampionshiptype.h"
#include "tcities.h"
#include "tclubs.h"
#include "tcountries.h"
#include "tdancers.h"
#include "tdancetypes.h"
#include "tgender.h"
#include "tjudges.h"
#include "tjudgescategorieshave.h"
#include "tjudgescategoriesname.h"
#include "tliga.h"
#include "ttreiners.h"

long testTAgeCategory(CDbConnection* pCon);
long testTCategories(CDbConnection* pCon);
long testTChampionship(CDbConnection* pCon);
long testTChampionshipCategories(CDbConnection* pCon);
long testTChampionshipJudgesMark(CDbConnection* pCon);
long testTChampionshipJudgesTeam(CDbConnection* pCon);
long testTChampionshipTeams(CDbConnection* pCon);
long testTChampionshipTeamCategories(CDbConnection* pCon);
long testTChampionshipTeamDancers(CDbConnection* pCon);
long testTChampionshipType(CDbConnection* pCon);
long testTCities(CDbConnection* pCon);
long testTClubs(CDbConnection* pCon);
long testTCountries(CDbConnection* pCon);
long testTDancers(CDbConnection* pCon);		
long testTDanceTypes(CDbConnection* pCon);
long testTGender(CDbConnection* pCon);
long testTJudges(CDbConnection* pCon);
long testTJudgesCategoriesHave(CDbConnection* pCon);
long testTJudgesCategoriesName(CDbConnection* pCon);
long testTLiga(CDbConnection* pCon);
long testTTrainers(CDbConnection* pCon);

int main(int argc, char **argv)
{
	long res = UDF_E_FAIL;
	do
	{
		CDbConnection* pCon = new CDbConnection();
		res = pCon->Open(szUrl, szUser, szPass, szSchema);
		if(UDF_OK != res)
		{
			printf("Connection open error. ErrCODE: %ld, MSG %s\n", res, GetErrorMsg(res).c_str());
			break;
		}
		
		if(UDF_OK == testTAgeCategory(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTCategories(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTChampionship(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTChampionshipCategories(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTChampionshipJudgesMark(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		//if(UDF_OK == testTChampionshipJudgesTeam(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		//if(UDF_OK == testTChampionshipTeams(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		//if(UDF_OK == testTChampionshipTeamCategories(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		//if(UDF_OK == testTChampionshipTeamDancers(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTChampionshipType(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTCities(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTClubs(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTCountries(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTDancers(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTDanceTypes(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTGender(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTJudges(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTJudgesCategoriesHave(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTJudgesCategoriesName(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTLiga(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
		if(UDF_OK == testTTrainers(pCon)) printf("\n\n====== PASSED\n\n"); else printf("\n\n====== FAIL\n\n");
			
		printf("\n\n------------- FINISH -------------\n\n\n");
	}while(0);
	
	return 0;
}

long testTAgeCategory(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CAgeCategoryTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CAgeCategoryTable tbl(pCon);
		CAgeCategoryTable::tTableMap* tmap;
		CAgeCategoryTable::tTableIt it;
		
		CAgeCategoryTable::tDATA data = {0};
		data.code = 90;
		data.descr = string("Test Дорослі-8");
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u = %s\n", it->first, it->second.descr.c_str());
			it++;
		}
		
		// Update row
		data.descr = string("XXXXX-8");
		data.code = 99;
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%d = %s\n", it->first, it->second.descr.c_str());
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTCategories(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CCategoriesTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CCategoriesTable tbl(pCon);
		CCategoriesTable::tTableMap* tmap;
		CCategoriesTable::tTableIt it;
		
		CCategoriesTable::tDATA data = {0};
		data.dance = 1;
		data.liga = 2;
		data.age_category = 2;
				
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %ld, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %ld, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u, %d\n", it->first
				, it->second.dance
				, it->second.liga
				, it->second.age_category);
			it++;
		}
		
		// Update row
		data.dance = 3;
		//data.liga = 300;
		data.age_category = 3;
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %ld, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u, %d\n", it->first
				, it->second.dance
				, it->second.liga
				, it->second.age_category);
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %ld, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTChampionship(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CChampionshipTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CChampionshipTable tbl(pCon);
		CChampionshipTable::tTableMap* tmap;
		CChampionshipTable::tTableIt it;
		
		CChampionshipTable::tDATA data = {0};
		data.type = 1;
		data.name = string("Test Дорослі-8");
		data.city = 1;
		data.additionalInfo = string("AdditionalInfo 1");
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %ld, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %ld, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %d, %s, %d, %s\n"
				, it->first
				, it->second.type
				, it->second.name.c_str()
				, it->second.city
				, it->second.additionalInfo.c_str());
			it++;
		}
		
		// Update row
		data.type = 2;
		data.name = string("XXXXXX-8");
		data.city = 2;
		data.additionalInfo = string("AdditionalInfo 2");
		
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %ld, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %d, %s, %d, %s\n"
				, it->first
				, it->second.type
				, it->second.name.c_str()
				, it->second.city
				, it->second.additionalInfo.c_str());
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %ld, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTChampionshipCategories(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CChampionshipCategotiesTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CChampionshipCategotiesTable tbl(pCon);
		CChampionshipCategotiesTable::tTableMap* tmap;
		CChampionshipCategotiesTable::tTableIt it;
		
		CChampionshipCategotiesTable::tDATA data = {0};
		data.catId = 10;
		data.championshipId = 3;
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u\n"
				, it->first
				, it->second.catId
				, it->second.championshipId);
			it++;
		}
		
		// Update row
		data.catId = 10;
		data.championshipId = 4;
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u\n"
				, it->first
				, it->second.catId
				, it->second.championshipId);
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTChampionshipJudgesMark(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CChampionshipJudgesMarkTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CChampionshipJudgesMarkTable tbl(pCon);
		CChampionshipJudgesMarkTable::tTableMap* tmap;
		CChampionshipJudgesMarkTable::tTableIt it;
		
		CChampionshipJudgesMarkTable::tDATA data = {0};
		data.catId = 9;
		data.championshipId = 3;
		data.judgeId = 4;
		data.teamId = 14;
		data.nMark = 15;
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u, %u, %u, %u\n"
				, it->first
				, it->second.championshipId
				, it->second.teamId
				, it->second.catId
				, it->second.judgeId
				, it->second.nMark);
			it++;
		}
		
		// Update row
		data.catId = 10;
		data.championshipId = 3;
		data.judgeId = 6;
		data.teamId = 24;
		data.nMark = 5;
		
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u, %u, %u, %u\n"
				, it->first
				, it->second.championshipId
				, it->second.teamId
				, it->second.catId
				, it->second.judgeId
				, it->second.nMark);
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTChampionshipJudgesTeam(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CChampionshipJudgesTeamTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CChampionshipJudgesTeamTable tbl(pCon);
		CChampionshipJudgesTeamTable::tTableMap* tmap;
		CChampionshipJudgesTeamTable::tTableIt it;
		
		CChampionshipJudgesTeamTable::tDATA data = {0};
		data.championshipId = 11;
		data.judjeId = 12;
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u\n"
				, it->first
				, it->second.championshipId
				, it->second.judjeId);
			it++;
		}
		
		// Update row
		data.championshipId = 21;
		data.judjeId = 22;
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u\n"
				, it->first
				, it->second.championshipId
				, it->second.judjeId);
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTChampionshipTeams(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CChampionshipTeamsTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CChampionshipTeamsTable tbl(pCon);
		CChampionshipTeamsTable::tTableMap* tmap;
		CChampionshipTeamsTable::tTableIt it;
		
		CChampionshipTeamsTable::tDATA data = {0};
		data.championshipId = 3;
		data.clubId = 4;
		data.startNumber =10;
		data.name = string("Test Дорослі-8");
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u, %u, %s\n"
				, it->first
				, it->second.championshipId
				, it->second.clubId
				, it->second.startNumber
				, it->second.name.c_str());
			it++;
		}
		
		// Update row
		data.championshipId = 4;
		data.clubId = 6;
		data.startNumber =20;
		data.name = string("Test Дорослі-8");
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u, %u, %s\n"
				, it->first
				, it->second.championshipId
				, it->second.clubId
				, it->second.startNumber
				, it->second.name.c_str());
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTChampionshipTeamCategories(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CChampionshipTeamCategoriesTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CChampionshipTeamCategoriesTable tbl(pCon);
		CChampionshipTeamCategoriesTable::tTableMap* tmap;
		CChampionshipTeamCategoriesTable::tTableIt it;
		
		CChampionshipTeamCategoriesTable::tDATA data = {0};
		data.teamId = 11;
		data.catId = 12;
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u\n"
				, it->first
				, it->second.teamId
				, it->second.catId);
			it++;
		}
		
		// Update row
		data.teamId = 21;
		data.catId = 22;
		
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u\n"
				, it->first
				, it->second.teamId
				, it->second.catId);
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTChampionshipTeamDancers(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CChampionshipTeamDancersTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CChampionshipTeamDancersTable tbl(pCon);
		CChampionshipTeamDancersTable::tTableMap* tmap;
		CChampionshipTeamDancersTable::tTableIt it;
		
		CChampionshipTeamDancersTable::tDATA data = {0};
		data.teamId = 1;
		data.dancerId = 10;
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u\n"
				, it->first
				, it->second.teamId
				, it->second.dancerId);
			it++;
		}
		
		// Update row
		data.teamId = 2;
		data.dancerId = 5;
		
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u\n"
				, it->first
				, it->second.teamId
				, it->second.dancerId);
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTChampionshipType(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CChampionshipTypeTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CChampionshipTypeTable tbl(pCon);
		CChampionshipTypeTable::tTableMap* tmap;
		CChampionshipTypeTable::tTableIt it;
		
		CChampionshipTypeTable::tDATA data = {0};
		data.name = string("Test Дорослі-8");
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u = %s\n", it->first, it->second.name.c_str());
			it++;
		}
		
		// Update row
		data.name = string("XXXXX-8");
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%d = %s\n", it->first, it->second.name.c_str());
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTCities(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CCitiesTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CCitiesTable tbl(pCon);
		CCitiesTable::tTableMap* tmap;
		CCitiesTable::tTableIt it;
		
		CCitiesTable::tDATA data = {0};
		data.countryId = 1;
		data.Name = string("Test Дорослі-8");
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %d, %s\n", it->first, it->second.countryId, it->second.Name.c_str());
			it++;
		}
		
		// Update row
		data.countryId = 2;
		data.Name = string("XXXXX-8");
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %d, %s\n", it->first, it->second.countryId, it->second.Name.c_str());
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTClubs(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CClubsTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CClubsTable tbl(pCon);
		CClubsTable::tTableMap* tmap;
		CClubsTable::tTableIt it;
		
		CClubsTable::tDATA data = {0};
		data.city = 11;
		data.name = string("Test Дорослі-8");
		data.login = string("Test login1");
		data.pass = string("Test pass1");
		data.email = string("Test email1");
		data.contacts = string("Test contacts1");
		data.web = string("Test web1");
		data.location = string("Test location1");
		data.pay_date = string("Test pay1");
		data.exp_date = string("Test exp1");
		data.director = string("Test director1");
		data.director_bd = string("Test dir bd1");
		data.director_email = string("Test dir em1");
		data.director_phone = string("Test dir ph1");
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n"
				, it->first
				, it->second.city
				, it->second.name.c_str()
				, it->second.login.c_str()
				, it->second.pass.c_str()
				, it->second.email.c_str()
				, it->second.contacts.c_str()
				, it->second.web.c_str()
				, it->second.location.c_str()
				, it->second.pay_date.c_str()
				, it->second.exp_date.c_str()
				, it->second.director.c_str()
				, it->second.director_bd.c_str()
				, it->second.director_email.c_str()
				, it->second.director_phone.c_str()
				);
			it++;
		}
		
		// Update row
		data.city = 4;
		data.name = string("Test XXXX");
		data.login = string("Test login2");
		data.pass = string("Test pass2");
		data.email = string("Test email2");
		data.contacts = string("Test contacts2");
		data.web = string("Test web2");
		data.location = string("Test location2");
		data.pay_date = string("Test pay2");
		data.exp_date = string("Test exp2");
		data.director = string("Test director2");
		data.director_bd = string("Test dir bd2");
		data.director_email = string("Test dir em2");
		data.director_phone = string("Test dir ph2");
		
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n"
				, it->first
				, it->second.city
				, it->second.name.c_str()
				, it->second.login.c_str()
				, it->second.pass.c_str()
				, it->second.email.c_str()
				, it->second.contacts.c_str()
				, it->second.web.c_str()
				, it->second.location.c_str()
				, it->second.pay_date.c_str()
				, it->second.exp_date.c_str()
				, it->second.director.c_str()
				, it->second.director_bd.c_str()
				, it->second.director_email.c_str()
				, it->second.director_phone.c_str()
				);
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTCountries(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CCountriesTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CCountriesTable tbl(pCon);
		CCountriesTable::tTableMap* tmap;
		CCountriesTable::tTableIt it;
		
		CCountriesTable::tDATA data = {0};
		data.name = string("Test Дорослі-8");
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u = %s\n", it->first, it->second.name.c_str());
			it++;
		}
		
		// Update row
		data.name = string("XXXXX-8");
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%d = %s\n", it->first, it->second.name.c_str());
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTDancers(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CDancersTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CDancersTable tbl(pCon);
		CDancersTable::tTableMap* tmap;
		CDancersTable::tTableIt it;
		
		CDancersTable::tDATA data = {0};
		data.clubId = 3;
		data.trainerId = 3;
		data.raiting = 1;
		data.liga = 1;
		data.gender = 9;
		data.regBook = string("Test RB1");
		data.name = string("Test name1");
		data.bd = string("Test bd1");
		data.pay_date = string("Test pay1");
		data.exp_date = string("Test exp1");
		data.reg_date = string("Test reg1");
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u, %u, %u, %u, %u, %s, %s, %s, %s, %s\n"
				, it->first
				, it->second.clubId
				, it->second.trainerId
				, it->second.raiting
				, it->second.gender
				, it->second.liga
				, it->second.regBook.c_str()
				, it->second.name.c_str()
				, it->second.bd.c_str()
				, it->second.pay_date.c_str()
				, it->second.exp_date.c_str()
				, it->second.reg_date.c_str());
			it++;
		}
		
		// Update row
		data.clubId = 2;
		data.trainerId = 4;
		data.raiting = 2;
		data.liga = 2;
		data.gender = 10;
		data.regBook = string("Test RB2");
		data.name = string("Test name2");
		data.bd = string("Test bd2");
		data.pay_date = string("Test pay2");
		data.exp_date = string("Test exp2");
		data.reg_date = string("Test reg2");
		
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u, %u, %u, %u, %s, %s, %s, %s, %s, %s\n"
				, it->first
				, it->second.clubId
				, it->second.trainerId
				, it->second.raiting
				, it->second.gender
				, it->second.liga
				, it->second.regBook.c_str()
				, it->second.name.c_str()
				, it->second.bd.c_str()
				, it->second.pay_date.c_str()
				, it->second.exp_date.c_str()
				, it->second.reg_date.c_str());
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTDanceTypes(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CDanceTypesTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CDanceTypesTable tbl(pCon);
		CDanceTypesTable::tTableMap* tmap;
		CDanceTypesTable::tTableIt it;
		
		CDanceTypesTable::tDATA data = {0};
		data.name = string("Test Дорослі-8");
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u = %s\n", it->first, it->second.name.c_str());
			it++;
		}
		
		// Update row
		data.name = string("XXXXX-8");
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%d = %s\n", it->first, it->second.name.c_str());
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTGender(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CGenderTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CGenderTable tbl(pCon);
		CGenderTable::tTableMap* tmap;
		CGenderTable::tTableIt it;
		
		CGenderTable::tDATA data = {0};
		data.name = string("Test Дорослі-8");
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u = %s\n", it->first, it->second.name.c_str());
			it++;
		}
		
		// Update row
		data.name = string("XXXXX-8");
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%d = %s\n", it->first, it->second.name.c_str());
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTJudges(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CJudgesTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CJudgesTable tbl(pCon);
		CJudgesTable::tTableMap* tmap;
		CJudgesTable::tTableIt it;
		
		CJudgesTable::tDATA data = {0};
		data.countryId = 1;
		data.cityId = 2;
		data.clubId = 3;
		data.name = string("Test name1");
		data.attestationInfo = string("Test attestation inf1");
		data.pay_date = string("Test pay1");
		data.exp_date = string("Test exp1");

		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u, %u, %s, %s, %s, %s\n"
				, it->first
				, it->second.countryId
				, it->second.cityId
				, it->second.clubId
				, it->second.name.c_str()
				, it->second.attestationInfo.c_str()
				, it->second.pay_date.c_str()
				, it->second.exp_date.c_str());
			it++;
		}
		
		// Update row
		data.countryId = 21;
		data.cityId = 22;
		data.clubId = 23;
		data.name = string("Test name2");
		data.attestationInfo = string("Test attestation inf2");
		data.pay_date = string("Test pay2");
		data.exp_date = string("Test exp2");
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u, %u, %s, %s, %s, %s\n"
				, it->first
				, it->second.countryId
				, it->second.cityId
				, it->second.clubId
				, it->second.name.c_str()
				, it->second.attestationInfo.c_str()
				, it->second.pay_date.c_str()
				, it->second.exp_date.c_str());
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTJudgesCategoriesHave(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CJudgesCategoriesHaveTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CJudgesCategoriesHaveTable tbl(pCon);
		CJudgesCategoriesHaveTable::tTableMap* tmap;
		CJudgesCategoriesHaveTable::tTableIt it;
		
		CJudgesCategoriesHaveTable::tDATA data = {0};
		data.judgeId = 1;
		data.judCatId = 3;
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u\n"
				, it->first
				, it->second.judgeId
				, it->second.judCatId);
			it++;
		}
		
		// Update row
		data.judgeId = 2;
		data.judCatId = 7;
		
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %u\n"
				, it->first
				, it->second.judgeId
				, it->second.judCatId);
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTJudgesCategoriesName(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CJudgesCategoriesNameTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CJudgesCategoriesNameTable tbl(pCon);
		CJudgesCategoriesNameTable::tTableMap* tmap;
		CJudgesCategoriesNameTable::tTableIt it;
		
		CJudgesCategoriesNameTable::tDATA data = {0};
		data.name = string("Test Дорослі-8");
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u = %s\n", it->first, it->second.name.c_str());
			it++;
		}
		
		// Update row
		data.name = string("XXXXX-8");
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%d = %s\n", it->first, it->second.name.c_str());
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTLiga(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CLigaTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CLigaTable tbl(pCon);
		CLigaTable::tTableMap* tmap;
		CLigaTable::tTableIt it;
		
		CLigaTable::tDATA data = {0};
		data.name = string("Test Дорослі-8");
		
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u = %s\n", it->first, it->second.name.c_str());
			it++;
		}
		
		// Update row
		data.name = string("XXXXX-8");
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%d = %s\n", it->first, it->second.name.c_str());
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
	}while(0);
	
	return res;
}

long testTTrainers(CDbConnection* pCon)
{
	long res = UDF_E_FAIL;
	const char*	cName = "CTarinersTable::";
	printf("\n\nEnter to %s\n", cName);
	do
	{
		CTrainersTable tbl(pCon);
		CTrainersTable::tTableMap* tmap;
		CTrainersTable::tTableIt it;
		
		CTrainersTable::tDATA data = {0};
		data.clubId = 2;
		data.name = string("Test name1");
		data.bd = string("Test bd1");
		data.phone = string("Test ph1");
		data.contactInfo = string("Test contactinfo1");
		data.email = string("Test em1");
		data.pay_date = string("Test pay1");
		data.exp_date = string("Test exp1");
				
		// Add row
		res = tbl.AddRow(data);
		if(UDF_OK != res)
			break;
		printf("%sAddRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get row
		res = tbl.GetRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sGetRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Find record
		res = tbl.Find(&tmap, data);
		if(UDF_OK != res)
			break;
		printf("%sFind res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %s, %s, %s, %s, %s, %s, %s\n"
				, it->first
				, it->second.clubId
				, it->second.name.c_str()
				, it->second.bd.c_str()
				, it->second.phone.c_str()
				, it->second.contactInfo.c_str()
				, it->second.email.c_str()
				, it->second.pay_date.c_str()
				, it->second.exp_date.c_str());
			it++;
		}
		
		// Update row
		data.clubId = 3;
		data.name = string("Test name2");
		data.bd = string("Test bd2");
		data.phone = string("Test ph2");
		data.contactInfo = string("Test contactinfo2");
		data.email = string("Test em2");
		data.pay_date = string("Test pay2");
		data.exp_date = string("Test exp2");
		res = tbl.UpdateRow(data.id, data);
		if(UDF_OK != res)
			break;
		printf("%sUpdateRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		
		// Get table
		res = tbl.GetTable(&tmap);
		if(UDF_OK != res)
			break;
		printf("%sGetTable res = %ld, %s\n", cName, res, GetErrorMsg(res).c_str());
		
		it = tmap->begin();
		while(it != tmap->end())
		{
			printf("%u, %u, %s, %s, %s, %s, %s, %s, %s\n"
				, it->first
				, it->second.clubId
				, it->second.name.c_str()
				, it->second.bd.c_str()
				, it->second.phone.c_str()
				, it->second.contactInfo.c_str()
				, it->second.email.c_str()
				, it->second.pay_date.c_str()
				, it->second.exp_date.c_str());
			it++;
		}
		
		// Remove row
		res = tbl.DelRow(data.id);
		if(UDF_OK != res)
			break;
		printf("%sDelRow ID = %u, res = %ld, %s\n", cName, data.id, res, GetErrorMsg(res).c_str());
		//*/
	}while(0);
	
	return res;
}
