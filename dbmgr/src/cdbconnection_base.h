#ifndef __CDBCONNECTION__H__
#define __CDBCONNECTION__H__

#include "datatypes.h"


#define CDbException	SQLException

class CDbConnection 
{
	CDbConnection(const CDbConnection &){};
	void operator=(CDbConnection &){};
	
public:
	CDbConnection() {};
	virtual ~CDbConnection(){};
	
	virtual long								Connect(std::string url, std::string dbName, std::string user, std::string pass) = 0;
	virtual	void								Close() = 0;

	virtual std::string 						GetVersion() = 0;
	virtual std::string 						GetName() = 0;
	
	virtual tUDF_LPRESULTS						ExecureQuery(string query) = 0;
	virtual tUDF_LPSTATEMENT					PrepareStatement(string statement) = 0;
	virtual void								PreparedStatementSetString(tUDF_LPSTATEMENT statement, string str) = 0;
	virtual int									PreparedStatementExecute(tUDF_LPSTATEMENT statement) = 0;
	virtual tUDF_LPSAVEPOINT					SetSavepoint(string name) = 0;
	virtual void								ReleaseSavepoint(tUDF_LPSAVEPOINT save) = 0;
	virtual void								Rollback(tUDF_LPSAVEPOINT save) = 0;
	virtual void								Commit() = 0;
	
	virtual long								GetAutocommitStatus(bool& status) = 0;
	virtual long								SetAutocommitStatus(bool status) = 0;
	
	
	virtual tUDF_AgeCategory*					GetAgeCategoryList(tUDF_AgeCategory* filter) = 0;
	virtual tUDF_AgeCategory*					FindAgeCategory(tUDF_AgeCategory* filter) = 0;
	virtual long								AddAgeCategory(tUDF_AgeCategory* data) = 0;
	virtual long								RemoveAgeCategory(tUDF_AgeCategory* item) = 0;

	virtual tUDF_Category*						GetCategoryList(tUDF_Category* filter) = 0;
	virtual tUDF_Category*						FindCategory(tUDF_Category* filter) = 0;
	virtual long								AddCategory(tUDF_Category* data) = 0;
	virtual long								RemoveCategory(tUDF_Category* item) = 0;

	virtual tUDF_Championship*					GetChampionshipList(tUDF_Championship* filter) = 0;
	virtual tUDF_Championship*					FindChampionship(tUDF_Championship* filter) = 0;
	virtual long								AddChampionship(tUDF_Championship* data) = 0;
	virtual long								RemoveChampionship(tUDF_Championship* item) = 0;

	virtual tUDF_ChampionshipCategories*		GetChampionshipCategoriesList(tUDF_ChampionshipCategories* filter) = 0;
	virtual tUDF_ChampionshipCategories*		FindChampionshipCategories(tUDF_ChampionshipCategories* filter) = 0;
	virtual long								AddChampionshipCategories(tUDF_ChampionshipCategories* data) = 0;
	virtual long								RemoveChampionshipCategories(tUDF_ChampionshipCategories* item) = 0;

	virtual tUDF_ChampionshipJudgesMark*		GetChampionshipJudgesMarkList(tUDF_ChampionshipJudgesMark* filter) = 0;
	virtual tUDF_ChampionshipJudgesMark*		FindChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* filter) = 0;
	virtual long								AddChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* data) = 0;
	virtual long								RemoveChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* item) = 0;

	virtual tUDF_ChampionshipJudgesTeam*		GetChampionshipJudgesTeamList(tUDF_ChampionshipJudgesTeam* filter) = 0;
	virtual tUDF_ChampionshipJudgesTeam*		FindChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* filter) = 0;
	virtual long								AddChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* data) = 0;
	virtual long								RemoveChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* item) = 0;

	virtual tUDF_ChampionshipTeam*				GetChampionshipTeamList(tUDF_ChampionshipTeam* filter) = 0;
	virtual tUDF_ChampionshipTeam*				FindChampionshipTeam(tUDF_ChampionshipTeam* filter) = 0;
	virtual long								AddChampionshipTeam(tUDF_ChampionshipTeam* data) = 0;
	virtual long								RemoveChampionshipTeam(tUDF_ChampionshipTeam* item) = 0;

	virtual tUDF_ChampionshipType*				GetChampionshipTypeList(tUDF_ChampionshipType* filter) = 0;
	virtual tUDF_ChampionshipType*				FindChampionshipType(tUDF_ChampionshipType* filter) = 0;
	virtual long								AddChampionshipType(tUDF_ChampionshipType* data) = 0;
	virtual long								RemoveChampionshipType(tUDF_ChampionshipType* item) = 0;

	virtual tUDF_ChampionshipTeamCategories*	GetChampionshipTeamCategoriesList(tUDF_ChampionshipTeamCategories* filter) = 0;
	virtual tUDF_ChampionshipTeamCategories*	FindChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* filter) = 0;
	virtual long								AddChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* data) = 0;
	virtual long								RemoveChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* item) = 0;

	virtual tUDF_Cities*						GetCitiesList(tUDF_Cities* filter) = 0;
	virtual tUDF_Cities*						FindCities(tUDF_Cities* filter) = 0;
	virtual long								AddCities(tUDF_Cities* data) = 0;
	virtual long								RemoveCities(tUDF_Cities* item) = 0;

	virtual tUDF_Clubs*							GetClubsList(tUDF_Clubs* filter) = 0;
	virtual tUDF_Clubs*							FindClubs(tUDF_Clubs* filter) = 0;
	virtual long								AddClubs(tUDF_Clubs* data) = 0;
	virtual long								RemoveClubs(tUDF_Clubs* item) = 0;

	virtual tUDF_Counties*						GetCountiesList(tUDF_Counties* filter) = 0;
	virtual tUDF_Counties*						FindCounties(tUDF_Counties* filter) = 0;
	virtual long								AddCounties(tUDF_Counties* data) = 0;
	virtual long								RemoveCounties(tUDF_Counties* item) = 0;

	virtual tUDF_DanceTypes*					GetDanceTypesyList(tUDF_DanceTypes* filter) = 0;
	virtual tUDF_DanceTypes*					FindDanceTypes(tUDF_DanceTypes* filter) = 0;
	virtual long								AddDanceTypes(tUDF_DanceTypes* data) = 0;
	virtual long								RemoveDanceTypes(tUDF_DanceTypes* item) = 0;

	virtual tUDF_Dancers*						GetDancersList(tUDF_Dancers* filter) = 0;
	virtual tUDF_Dancers*						FindDancers(tUDF_Dancers* filter) = 0;
	virtual long								AddDancers(tUDF_Dancers* data) = 0;
	virtual long								RemoveDancers(tUDF_Dancers* item) = 0;

	virtual tUDF_Gender*						GetGenderList(tUDF_Gender* filter) = 0;
	virtual tUDF_Gender*						FindGender(tUDF_Gender* filter) = 0;
	virtual long								AddGender(tUDF_Gender* data) = 0;
	virtual long								RemoveGender(tUDF_Gender* item) = 0;

	virtual tUDF_Judges*						GetJudgesList(tUDF_Judges* filter) = 0;
	virtual tUDF_Judges*						FindJudges(tUDF_Judges* filter) = 0;
	virtual long								AddJudges(tUDF_Judges* data) = 0;
	virtual long								RemoveJudges(tUDF_Judges* item) = 0;

	virtual tUDF_JudgesCategoriesHave*			GetJudgesCategoriesHaveList(tUDF_JudgesCategoriesHave* filter) = 0;
	virtual tUDF_JudgesCategoriesHave*			FindJudgesCategoriesHave(tUDF_JudgesCategoriesHave* filter) = 0;
	virtual long								AddJudgesCategoriesHave(tUDF_JudgesCategoriesHave* data) = 0;
	virtual long								RemoveJudgesCategoriesHave(tUDF_JudgesCategoriesHave* item) = 0;

	virtual tUDF_JudgesCategoriesName*			GetJudgesCategoriesNameList(tUDF_JudgesCategoriesName* filter) = 0;
	virtual tUDF_JudgesCategoriesName*			FindJudgesCategoriesName(tUDF_JudgesCategoriesName* filter) = 0;
	virtual long								AddJudgesCategoriesName(tUDF_JudgesCategoriesName* data) = 0;
	virtual long								RemoveJudgesCategoriesName(tUDF_JudgesCategoriesName* item) = 0;

	virtual tUDF_Liga*							GetLigaList(tUDF_Liga* filter) = 0;
	virtual tUDF_Liga*							FindLiga(tUDF_Liga* filter) = 0;
	virtual long								AddLiga(tUDF_Liga* data) = 0;
	virtual long								RemoveLiga(tUDF_Liga* item) = 0;

	virtual tUDF_Treners*						GetTrenersList(tUDF_Treners* filter) = 0;
	virtual tUDF_Treners*						FindTreners(tUDF_Treners* filter) = 0;
	virtual long								AddTreners(tUDF_Treners* data) = 0;
	virtual long								RemoveTreners(tUDF_Treners* item) = 0;
};

#ifdef __cplusplus
extern "C" {
#endif

CDbConnection*		getConnection();

#ifdef __cplusplus
}
#endif

#endif // __CDBCONNECTION__H__
