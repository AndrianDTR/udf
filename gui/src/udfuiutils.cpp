#include "udfuiutils.h"

#include "cdbmanager.h"
#include "tclubs.h"
#include "tcountries.h"
#include "tcities.h"
#include "tcategories.h"
#include "tdancers.h"
#include "tjudges.h"
#include "ttreiners.h"
#include "tchampionshipteam.h"

#include "string_def.h"

wxString	GetClubNameById(int nId)
{
	wxString res;
	
	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CCountriesTable::tDATA 	country = {0};
		CCitiesTable::tDATA		city = {0};
		CClubsTable::tDATA 		club = {0};
		
		if(UDF_OK != CClubsTable(pCon).GetRow(nId, club))
		{
			break;
		}
		
		if(UDF_OK != CCitiesTable(pCon).GetRow(club.city, city))
		{
			break;
		}
		
		if(UDF_OK != CCountriesTable(pCon).GetRow(city.countryId, country))
		{
			break;
		}
		
		res = wxString::Format(STR_FORMAT_CLUB_NAME, club.name, city.Name, country.name);
	}while(0);
	
	return res;
}

wxString	GetCityNameById(int nId)
{
	wxString res;
	
	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CCountriesTable::tDATA 	country = {0};
		CCitiesTable::tDATA		city = {0};
		
		if(UDF_OK != CCitiesTable(pCon).GetRow(nId, city))
		{
			break;
		}
		
		if(UDF_OK != CCountriesTable(pCon).GetRow(city.countryId, country))
		{
			break;
		}
		
		res = wxString::Format(STR_FORMAT_CITY_NAME, city.Name, country.name);
	}while(0);
	
	return res;
}

wxString	GetDancerNameById(int nId)
{
	wxString res;
	
	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CDancersTable::tDATA 	dancer = {0};
		
		if(UDF_OK != CDancersTable(pCon).GetRow(nId, dancer))
		{
			break;
		}
		
		res = dancer.name;
	}while(0);
	
	return res;
}

wxString	GetJudgeNameById(int nId)
{
	wxString res;
	
	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CJudgesTable::tDATA 	data = {0};
		
		if(UDF_OK != CJudgesTable(pCon).GetRow(nId, data))
		{
			break;
		}
		
		res = data.name;
	}while(0);
	
	return res;
}

wxString	GetTrainerNameById(int nId)
{
	wxString res;
	
	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CTrainersTable::tDATA 	data = {0};
		
		if(UDF_OK != CTrainersTable(pCon).GetRow(nId, data))
		{
			break;
		}
		
		res = data.name;
	}while(0);
	
	return res;
}

wxString	GetCategoryNameById(int nId)
{
	wxString res;
	
	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CCategoriesTable::tDATA	data = {0};
		
		if(UDF_OK != CCategoriesTable(pCon).GetRow(nId, data))
		{
			break;
		}
		
		res = data.shortName;
	}while(0);
	
	return res;
}

wxString	GetTeamNameById(int nId)
{
	wxString res;
	
	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CChampionshipTeamsTable::tDATA	data = {0};
		
		if(UDF_OK != CChampionshipTeamsTable(pCon).GetRow(nId, data))
		{
			break;
		}
		
		res = data.name;
	}while(0);
	
	return res;
}