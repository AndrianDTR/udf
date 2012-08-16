#ifndef __UDFDBCONNECTION_H__
#define __UDFDBCONNECTION_H__

#include "cdbconnection_base.h" // Base class: CDbConnection::CDbConnection


#include "cppconn/connection.h"


using namespace sql;

class udfDbConnection : public CDbConnection 
{
	Connection*		m_pConnection;
	
	tUdfAgeCategoryMap					m_mapAgeCategory;
	tUDF_Category						m_mapCategory;
	tUDF_Championship					m_mapChanlionship;
	tUDF_ChampionshipCategories			m_mapChanlionshipCategories;
	tUDF_ChampionshipJudgesMark			m_mapChanlionshipJudgesMark;
	tUDF_ChampionshipJudgesTeam			m_mapChanlionshipJudgesTeam;
	tUDF_ChampionshipTeam				m_mapChanlionshipTeam;
	tUDF_ChampionshipType				m_mapChanlionshipType;
	tUDF_ChampionshipTeamCategories		m_mapChanlionshipteamCategories;
	tUDF_Cities							m_mapCities;
	tUDF_Clubs							m_mapClubs;
	tUDF_Counties						m_mapCountries;
	tUDF_DanceTypes						m_mapDanceTypes;
	tUDF_Dancers						m_mapDancers;
	tUDF_Gender							m_mapGender;
	tUDF_Judges							m_mapJudges;
	tUDF_JudgesCategoriesHave			m_mapJudgesCategoriesHave;
	tUDF_JudgesCategoriesName			m_mapJudgesCategoriesName;
	tUDF_Liga							m_mapLiga;
	tUDF_Treners						m_mapTreners;
	
public:
	udfDbConnection();
	virtual ~udfDbConnection();

	virtual std::string 						GetVersion();
	virtual std::string 						GetName();
	
	virtual long								Connect(std::string url, std::string dbName, std::string user, std::string pass);
	virtual void								Close();

	virtual tUDF_LPRESULTS						ExecureQuery(string query);
	virtual tUDF_LPSTATEMENT					PrepareStatement(string statement);
	virtual void								PreparedStatementSetString(tUDF_LPSTATEMENT statement, string str);
	virtual int									PreparedStatementExecute(tUDF_LPSTATEMENT statement);
	virtual tUDF_LPSAVEPOINT					SetSavepoint(string name);
	virtual void								ReleaseSavepoint(tUDF_LPSAVEPOINT save);
	virtual void								Rollback(tUDF_LPSAVEPOINT save);
	virtual void								Commit();
	
	virtual long								GetAutocommitStatus(bool& status);
	virtual long								SetAutocommitStatus(bool status);
	
	virtual tUdfAgeCategoryMap*					GetAgeCategoryList(tUdfAgeCategory* filter);
	virtual tUdfAgeCategoryMap*					FindAgeCategory(tUdfAgeCategory* filter);
	virtual long								AddAgeCategory(tUdfAgeCategory* data);
	virtual long								RemoveAgeCategory(tUdfAgeCategory* item);

	virtual tUDF_Category*						GetCategoryList(tUDF_Category* filter);
	virtual tUDF_Category*						FindCategory(tUDF_Category* filter);
	virtual long								AddCategory(tUDF_Category* data);
	virtual long								RemoveCategory(tUDF_Category* item);

	virtual tUDF_Championship*					GetChampionshipList(tUDF_Championship* filter);
	virtual tUDF_Championship*					FindChampionship(tUDF_Championship* filter);
	virtual long								AddChampionship(tUDF_Championship* data);
	virtual long								RemoveChampionship(tUDF_Championship* item);

	virtual tUDF_ChampionshipCategories*		GetChampionshipCategoriesList(tUDF_ChampionshipCategories* filter);
	virtual tUDF_ChampionshipCategories*		FindChampionshipCategories(tUDF_ChampionshipCategories* filter);
	virtual long								AddChampionshipCategories(tUDF_ChampionshipCategories* data);
	virtual long								RemoveChampionshipCategories(tUDF_ChampionshipCategories* item);

	virtual tUDF_ChampionshipJudgesMark*		GetChampionshipJudgesMarkList(tUDF_ChampionshipJudgesMark* filter);
	virtual tUDF_ChampionshipJudgesMark*		FindChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* filter);
	virtual long								AddChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* data);
	virtual long								RemoveChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* item);

	virtual tUDF_ChampionshipJudgesTeam*		GetChampionshipJudgesTeamList(tUDF_ChampionshipJudgesTeam* filter);
	virtual tUDF_ChampionshipJudgesTeam*		FindChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* filter);
	virtual long								AddChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* data);
	virtual long								RemoveChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* item);

	virtual tUDF_ChampionshipTeam*				GetChampionshipTeamList(tUDF_ChampionshipTeam* filter);
	virtual tUDF_ChampionshipTeam*				FindChampionshipTeam(tUDF_ChampionshipTeam* filter);
	virtual long								AddChampionshipTeam(tUDF_ChampionshipTeam* data);
	virtual long								RemoveChampionshipTeam(tUDF_ChampionshipTeam* item);

	virtual tUDF_ChampionshipType*				GetChampionshipTypeList(tUDF_ChampionshipType* filter);
	virtual tUDF_ChampionshipType*				FindChampionshipType(tUDF_ChampionshipType* filter);
	virtual long								AddChampionshipType(tUDF_ChampionshipType* data);
	virtual long								RemoveChampionshipType(tUDF_ChampionshipType* item);

	virtual tUDF_ChampionshipTeamCategories*	GetChampionshipTeamCategoriesList(tUDF_ChampionshipTeamCategories* filter);
	virtual tUDF_ChampionshipTeamCategories*	FindChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* filter);
	virtual long								AddChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* data);
	virtual long								RemoveChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* item);

	virtual tUDF_Cities*						GetCitiesList(tUDF_Cities* filter);
	virtual tUDF_Cities*						FindCities(tUDF_Cities* filter);
	virtual long								AddCities(tUDF_Cities* data);
	virtual long								RemoveCities(tUDF_Cities* item);

	virtual tUDF_Clubs*							GetClubsList(tUDF_Clubs* filter);
	virtual tUDF_Clubs*							FindClubs(tUDF_Clubs* filter);
	virtual long								AddClubs(tUDF_Clubs* data);
	virtual long								RemoveClubs(tUDF_Clubs* item);

	virtual tUDF_Counties*						GetCountiesList(tUDF_Counties* filter);
	virtual tUDF_Counties*						FindCounties(tUDF_Counties* filter);
	virtual long								AddCounties(tUDF_Counties* data);
	virtual long								RemoveCounties(tUDF_Counties* item);

	virtual tUDF_DanceTypes*					GetDanceTypesyList(tUDF_DanceTypes* filter);
	virtual tUDF_DanceTypes*					FindDanceTypes(tUDF_DanceTypes* filter);
	virtual long								AddDanceTypes(tUDF_DanceTypes* data);
	virtual long								RemoveDanceTypes(tUDF_DanceTypes* item);

	virtual tUDF_Dancers*						GetDancersList(tUDF_Dancers* filter);
	virtual tUDF_Dancers*						FindDancers(tUDF_Dancers* filter);
	virtual long								AddDancers(tUDF_Dancers* data);
	virtual long								RemoveDancers(tUDF_Dancers* item);

	virtual tUDF_Gender*						GetGenderList(tUDF_Gender* filter);
	virtual tUDF_Gender*						FindGender(tUDF_Gender* filter);
	virtual long								AddGender(tUDF_Gender* data);
	virtual long								RemoveGender(tUDF_Gender* item);

	virtual tUDF_Judges*						GetJudgesList(tUDF_Judges* filter);
	virtual tUDF_Judges*						FindJudges(tUDF_Judges* filter);
	virtual long								AddJudges(tUDF_Judges* data);
	virtual long								RemoveJudges(tUDF_Judges* item);

	virtual tUDF_JudgesCategoriesHave*			GetJudgesCategoriesHaveList(tUDF_JudgesCategoriesHave* filter);
	virtual tUDF_JudgesCategoriesHave*			FindJudgesCategoriesHave(tUDF_JudgesCategoriesHave* filter);
	virtual long								AddJudgesCategoriesHave(tUDF_JudgesCategoriesHave* data);
	virtual long								RemoveJudgesCategoriesHave(tUDF_JudgesCategoriesHave* item);

	virtual tUDF_JudgesCategoriesName*			GetJudgesCategoriesNameList(tUDF_JudgesCategoriesName* filter);
	virtual tUDF_JudgesCategoriesName*			FindJudgesCategoriesName(tUDF_JudgesCategoriesName* filter);
	virtual long								AddJudgesCategoriesName(tUDF_JudgesCategoriesName* data);
	virtual long								RemoveJudgesCategoriesName(tUDF_JudgesCategoriesName* item);

	virtual tUDF_Liga*							GetLigaList(tUDF_Liga* filter);
	virtual tUDF_Liga*							FindLiga(tUDF_Liga* filter);
	virtual long								AddLiga(tUDF_Liga* data);
	virtual long								RemoveLiga(tUDF_Liga* item);

	virtual tUDF_Treners*						GetTrenersList(tUDF_Treners* filter);
	virtual tUDF_Treners*						FindTreners(tUDF_Treners* filter);
	virtual long								AddTreners(tUDF_Treners* data);
	virtual long								RemoveTreners(tUDF_Treners* item);

};

#endif // __UDFDBCONNECTION_H__
