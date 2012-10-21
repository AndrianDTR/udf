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
#include "tchampionshipcategories.h"
#include "tchampionshipjudgesmark.h"
#include "tchampionshiptour.h"
#include "tagecategory.h"
#include "tliga.h"
#include "tdancetypes.h"
#include "ttourtypes.h"

#include "string_def.h"

wxString	GetClubNameById(unsigned int nId)
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

wxString	GetCityNameById(unsigned int nId)
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

wxString	GetDancerNameById(unsigned int nId)
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

wxString	GetJudgeNameById(unsigned int nId)
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

wxString	GetTrainerNameById(unsigned int nId)
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

wxString	GetCategoryNameById(unsigned int nId)
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

		res = wxString::Format(STR_FORMAT_CATEGORY_LIST_ITEM
			, data.shortName
			, data.name);
	}while(0);

	return res;
}

wxString	GetCsCategoryNameById(unsigned int nId)
{
	wxString res;

	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CChampionshipCategoriesTable::tDATA	data = {0};

		if(UDF_OK != CChampionshipCategoriesTable(pCon).GetRow(nId, data))
		{
			break;
		}

		res = GetCategoryNameById(data.catId);
	}while(0);

	return res;
}

wxString	GetTeamNameById(unsigned int nId)
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

wxString	GetTourTypeNameById(unsigned int nId)
{
	wxString res;

	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CTourTypesTable::tDATA	data = {0};

		if(UDF_OK != CTourTypesTable(pCon).GetRow(nId, data))
		{
			break;
		}

		res = data.name;
	}while(0);

	return res;
}

void	GetTourTypeLimitsById(unsigned int nId, int& min, int& max)
{
	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CTourTypesTable::tDATA	data = {0};

		if(UDF_OK != CTourTypesTable(pCon).GetRow(nId, data))
		{
			break;
		}

		min = data.min;
		max = data.max;
	}while(0);
}

int GetJudgeMark(unsigned int nChId, unsigned int nChTourId, unsigned int nJudgeId, unsigned int nTeamId)
{
	int res = -1;

	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CChampionshipJudgesMarkTable::tDATA	filter = {0};

		CChampionshipJudgesMarkTable::tTableMap	data;

		if(UDF_OK != CChampionshipJudgesMarkTable(pCon).Find(data, filter))
		{
			break;
		}

		if(1 != data.size())
		{
			break;
		}

		CChampionshipJudgesMarkTable::tDATA& mark = data.begin()->second;
		res = mark.nMark;
	}while(0);

	return res;
}

int GetTourLimit(unsigned int nTourId)
{
	int res = -1;

	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CChampionshipToursTable::tDATA data = {0};

		if(UDF_OK != CChampionshipToursTable(pCon).GetRow(nTourId, data))
		{
			break;
		}

		res = data.limit;
	}while(0);

	return res;
}

int	GetAgeCodeById(unsigned int nAgeId)
{
	int res = -1;

	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CAgeCategoryTable::tDATA data = {0};

		if(UDF_OK != CAgeCategoryTable(pCon).GetRow(nAgeId, data))
		{
			break;
		}

		res = data.code;
	}while(0);

	return res;
}

std::string	GetAgeNameById(unsigned int nAgeId)
{
	std::string res;

	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CAgeCategoryTable::tDATA data = {0};

		if(UDF_OK != CAgeCategoryTable(pCon).GetRow(nAgeId, data))
		{
			break;
		}

		res = data.name;
	}while(0);

	return res;
}

int	GetLigueCodeById(unsigned int nLigueId)
{
	int res = -1;

	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CLigaTable::tDATA data = {0};

		if(UDF_OK != CLigaTable(pCon).GetRow(nLigueId, data))
		{
			break;
		}

		res = data.code;
	}while(0);

	return res;
}

std::string	GetLigueNameById(unsigned int nLigueId)
{
	std::string res;

	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CLigaTable::tDATA data = {0};

		if(UDF_OK != CLigaTable(pCon).GetRow(nLigueId, data))
		{
			break;
		}

		res = data.name;
	}while(0);

	return res;
}

int	GetDanceCodeById(unsigned int nDanceId)
{
	int res = -1;

	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CDanceTypesTable::tDATA data = {0};

		if(UDF_OK != CDanceTypesTable(pCon).GetRow(nDanceId, data))
		{
			break;
		}

		res = data.code;
	}while(0);

	return res;
}

std::string	GetDanceNameById(unsigned int nDanceId)
{
	std::string res;

	do
	{
		CDbConnection* pCon = CDbManager::Instance()->GetConnection();
		CDanceTypesTable::tDATA data = {0};

		if(UDF_OK != CDanceTypesTable(pCon).GetRow(nDanceId, data))
		{
			break;
		}

		res = data.name;
	}while(0);

	return res;
}
