#include "udfdbconnection.h"

#include "cppconn/driver.h"

#include "version.h"
#include "errorcodes.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

CDbConnection*		getConnection()
{
	return new udfDbConnection();
}

#ifdef __cplusplus
}
#endif

udfDbConnection::udfDbConnection()
: CDbConnection()
, m_pConnection(NULL)
{
}

udfDbConnection::~udfDbConnection()
{
	Close();
}

std::string udfDbConnection::GetName()
{
	std::string Name;
	Name += std::string("DBManager ver") + std::string("0.1.X");
	Name += std::string(__FILE__) + std::string(", ") + std::string(" line: 41");
	return Name;
}

std::string udfDbConnection::GetVersion()
{
	std::string Ver;
	
	Ver += std::string("0");
	Ver += std::string(".");
	Ver += std::string("1");
	Ver += std::string(".");
	Ver += std::string("X");
	return Ver;
}

long udfDbConnection::Connect(std::string url, std::string dbName, std::string user, std::string pass)
{
	long result = UDF_FAIL;
	
	do{
		Driver* pDriver = get_driver_instance();
		if (!pDriver)
		{
			result = UDF_NO_DRIVER_FOUND;
			break;
		}
		
		m_pConnection = pDriver->connect(url, user, pass);
		if(! m_pConnection)
		{
			result = UDF_NO_CONNECTION_OPENED;
			break;
		}
		
		m_pConnection->setAutoCommit(0);
		
		m_pConnection->setSchema(dbName);
				
		Statement* stmt = m_pConnection->createStatement();
		if(! stmt)
		{
			result = UDF_NO_STATEMENT;
			break;
		}
		
		delete stmt;
		
		result = UDF_OK;
		
	}while(0);
	
	return result;
}

void udfDbConnection::Close()
{
	if (m_pConnection)
	{
		m_pConnection->close();
		delete m_pConnection;
		m_pConnection = NULL;
	}
}

void udfDbConnection::Commit()
{
}

tUDF_LPRESULTS udfDbConnection::ExecureQuery(string query)
{
	// Reinit list
	Statement* 		stmt = NULL;
	tUDF_LPRESULTS 	res = NULL;

	do{
		stmt = m_pConnection->createStatement();
		if(!stmt)
			break;
		
		res = stmt->executeQuery (query);
		
	}while(0);
	
	if(stmt)
		delete stmt;
	
	return res;
}

long udfDbConnection::GetAutocommitStatus(bool& status)
{
	long result = UDF_FAIL;
	
	do
	{
		if(! m_pConnection)
		{
			result = UDF_NO_CONNECTION;
			break;
		}
		
		status = m_pConnection->getAutoCommit();
		result = UDF_OK;
	}while(0);
	
	return result;
}

long udfDbConnection::SetAutocommitStatus(bool status)
{
	long result = UDF_FAIL;
	
	do
	{
		if(! m_pConnection)
		{
			result = UDF_NO_CONNECTION;
			break;
		}
		
		//m_pConnection->setAutoCommit(status);
		result = UDF_OK;
	}while(0);
	
	return result;
}


tUDF_LPSTATEMENT udfDbConnection::PrepareStatement(string statement)
{
}

int udfDbConnection::PreparedStatementExecute(tUDF_LPSTATEMENT statement)
{
}

void udfDbConnection::PreparedStatementSetString(tUDF_LPSTATEMENT statement, string str)
{
}

tUDF_LPSAVEPOINT udfDbConnection::SetSavepoint(string name)
{
}

void udfDbConnection::ReleaseSavepoint(tUDF_LPSAVEPOINT save)
{
}

void udfDbConnection::Rollback(tUDF_LPSAVEPOINT save)
{
}

/*****************************************************************/

tUdfAgeCategoryMap* udfDbConnection::GetAgeCategoryList(tUdfAgeCategory* filter)
{
	Statement*	stmt = NULL;
	ResultSet*	res = NULL;
	char		query[500] = {0};
	do{
		stmt = m_pConnection->createStatement();
		if(!stmt)
			break;
		
		sprintf(query,"select * from age_category");
		if(filter)
			sprintf(query, "%s where id like %d and descr like %s", query, filter->id, filter->descr.c_str());
		
		res = stmt->executeQuery (query);
		if(!res)
			break;
		
		m_mapAgeCategory.clear();
		
		while( res && res->next())
		{
			tUdfAgeCategory cat = {0};
			
			cat.id = res->getInt(1);
			cat.descr = res->getString(2);
		
			m_mapAgeCategory.insert(make_pair(cat.id, cat));
		}
		
		delete stmt;
		
	}while(0);
	
	return &m_mapAgeCategory;
}

long udfDbConnection::AddAgeCategory(tUdfAgeCategory* data)
{
}

long udfDbConnection::RemoveAgeCategory(tUdfAgeCategory* item)
{
}

tUdfAgeCategoryMap* udfDbConnection::FindAgeCategory(tUdfAgeCategory* filter)
{
}

/*****************************************************************/

tUDF_Category* udfDbConnection::GetCategoryList(tUDF_Category* filter)
{
	// Reinit list
	
	return &m_mapCategory;
}

long udfDbConnection::AddCategory(tUDF_Category* data)
{
}

long udfDbConnection::RemoveCategory(tUDF_Category* item)
{
}

tUDF_Category* udfDbConnection::FindCategory(tUDF_Category* filter)
{
}

/******************************************************************/

long udfDbConnection::AddChampionship(tUDF_Championship* data)
{
}

long udfDbConnection::AddChampionshipCategories(tUDF_ChampionshipCategories* data)
{
}

long udfDbConnection::AddChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* data)
{
}

long udfDbConnection::AddChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* data)
{
}

long udfDbConnection::AddChampionshipTeam(tUDF_ChampionshipTeam* data)
{
}

long udfDbConnection::AddChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* data)
{
}

long udfDbConnection::AddChampionshipType(tUDF_ChampionshipType* data)
{
}

long udfDbConnection::AddCities(tUDF_Cities* data)
{
}

long udfDbConnection::AddClubs(tUDF_Clubs* data)
{
}

long udfDbConnection::AddCounties(tUDF_Counties* data)
{
}

long udfDbConnection::AddDanceTypes(tUDF_DanceTypes* data)
{
}

long udfDbConnection::AddDancers(tUDF_Dancers* data)
{
}

long udfDbConnection::AddGender(tUDF_Gender* data)
{
}

long udfDbConnection::AddJudges(tUDF_Judges* data)
{
}

long udfDbConnection::AddJudgesCategoriesHave(tUDF_JudgesCategoriesHave* data)
{
}

long udfDbConnection::AddJudgesCategoriesName(tUDF_JudgesCategoriesName* data)
{
}

long udfDbConnection::AddLiga(tUDF_Liga* data)
{
}

long udfDbConnection::AddTreners(tUDF_Treners* data)
{
}

tUDF_Championship* udfDbConnection::FindChampionship(tUDF_Championship* filter)
{
}

tUDF_ChampionshipCategories* udfDbConnection::FindChampionshipCategories(tUDF_ChampionshipCategories* filter)
{
}

tUDF_ChampionshipJudgesMark* udfDbConnection::FindChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* filter)
{
}

tUDF_ChampionshipJudgesTeam* udfDbConnection::FindChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* filter)
{
}

tUDF_ChampionshipTeam* udfDbConnection::FindChampionshipTeam(tUDF_ChampionshipTeam* filter)
{
}

tUDF_ChampionshipTeamCategories* udfDbConnection::FindChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* filter)
{
}

tUDF_ChampionshipType* udfDbConnection::FindChampionshipType(tUDF_ChampionshipType* filter)
{
}

tUDF_Cities* udfDbConnection::FindCities(tUDF_Cities* filter)
{
}

tUDF_Clubs* udfDbConnection::FindClubs(tUDF_Clubs* filter)
{
}

tUDF_Counties* udfDbConnection::FindCounties(tUDF_Counties* filter)
{
}

tUDF_DanceTypes* udfDbConnection::FindDanceTypes(tUDF_DanceTypes* filter)
{
}

tUDF_Dancers* udfDbConnection::FindDancers(tUDF_Dancers* filter)
{
}

tUDF_Gender* udfDbConnection::FindGender(tUDF_Gender* filter)
{
}

tUDF_Judges* udfDbConnection::FindJudges(tUDF_Judges* filter)
{
}

tUDF_JudgesCategoriesHave* udfDbConnection::FindJudgesCategoriesHave(tUDF_JudgesCategoriesHave* filter)
{
}

tUDF_JudgesCategoriesName* udfDbConnection::FindJudgesCategoriesName(tUDF_JudgesCategoriesName* filter)
{
}

tUDF_Liga* udfDbConnection::FindLiga(tUDF_Liga* filter)
{
}

tUDF_Treners* udfDbConnection::FindTreners(tUDF_Treners* filter)
{
}

tUDF_ChampionshipCategories* udfDbConnection::GetChampionshipCategoriesList(tUDF_ChampionshipCategories* filter)
{
}

tUDF_ChampionshipJudgesMark* udfDbConnection::GetChampionshipJudgesMarkList(tUDF_ChampionshipJudgesMark* filter)
{
}

tUDF_ChampionshipJudgesTeam* udfDbConnection::GetChampionshipJudgesTeamList(tUDF_ChampionshipJudgesTeam* filter)
{
}

tUDF_Championship* udfDbConnection::GetChampionshipList(tUDF_Championship* filter)
{
}

tUDF_ChampionshipTeamCategories* udfDbConnection::GetChampionshipTeamCategoriesList(tUDF_ChampionshipTeamCategories* filter)
{
}

tUDF_ChampionshipTeam* udfDbConnection::GetChampionshipTeamList(tUDF_ChampionshipTeam* filter)
{
}

tUDF_ChampionshipType* udfDbConnection::GetChampionshipTypeList(tUDF_ChampionshipType* filter)
{
}

tUDF_Cities* udfDbConnection::GetCitiesList(tUDF_Cities* filter)
{
}

tUDF_Clubs* udfDbConnection::GetClubsList(tUDF_Clubs* filter)
{
}

tUDF_Counties* udfDbConnection::GetCountiesList(tUDF_Counties* filter)
{
}

tUDF_DanceTypes* udfDbConnection::GetDanceTypesyList(tUDF_DanceTypes* filter)
{
}

tUDF_Dancers* udfDbConnection::GetDancersList(tUDF_Dancers* filter)
{
}

tUDF_Gender* udfDbConnection::GetGenderList(tUDF_Gender* filter)
{
}

tUDF_JudgesCategoriesHave* udfDbConnection::GetJudgesCategoriesHaveList(tUDF_JudgesCategoriesHave* filter)
{
}

tUDF_JudgesCategoriesName* udfDbConnection::GetJudgesCategoriesNameList(tUDF_JudgesCategoriesName* filter)
{
}

tUDF_Judges* udfDbConnection::GetJudgesList(tUDF_Judges* filter)
{
}

tUDF_Liga* udfDbConnection::GetLigaList(tUDF_Liga* filter)
{
}

tUDF_Treners* udfDbConnection::GetTrenersList(tUDF_Treners* filter)
{
}

long udfDbConnection::RemoveChampionship(tUDF_Championship* item)
{
}

long udfDbConnection::RemoveChampionshipCategories(tUDF_ChampionshipCategories* item)
{
}

long udfDbConnection::RemoveChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* item)
{
}

long udfDbConnection::RemoveChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* item)
{
}

long udfDbConnection::RemoveChampionshipTeam(tUDF_ChampionshipTeam* item)
{
}

long udfDbConnection::RemoveChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* item)
{
}

long udfDbConnection::RemoveChampionshipType(tUDF_ChampionshipType* item)
{
}

long udfDbConnection::RemoveCities(tUDF_Cities* item)
{
}

long udfDbConnection::RemoveClubs(tUDF_Clubs* item)
{
}

long udfDbConnection::RemoveCounties(tUDF_Counties* item)
{
}

long udfDbConnection::RemoveDanceTypes(tUDF_DanceTypes* item)
{
}

long udfDbConnection::RemoveDancers(tUDF_Dancers* item)
{
}

long udfDbConnection::RemoveGender(tUDF_Gender* item)
{
}

long udfDbConnection::RemoveJudges(tUDF_Judges* item)
{
}

long udfDbConnection::RemoveJudgesCategoriesHave(tUDF_JudgesCategoriesHave* item)
{
}

long udfDbConnection::RemoveJudgesCategoriesName(tUDF_JudgesCategoriesName* item)
{
}

long udfDbConnection::RemoveLiga(tUDF_Liga* item)
{
}

long udfDbConnection::RemoveTreners(tUDF_Treners* item)
{
}
