#ifndef __UDF_DBMGR_H__
#define __UDF_DBMGR_H__

#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>

#include "cppconn/driver.h"
#include "cppconn/connection.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"
#include "cppconn/resultset.h"
#include "cppconn/exception.h"
#include "cppconn/warning.h"

#include "map"

using namespace std;
using namespace sql;

#ifdef __cplusplus
extern "C" {
#endif

typedef	Driver				tUDF_DRIVER;
typedef	Driver*				tUDF_LPDRIVER;

typedef	ResultSet			tUDF_RESULTS;
typedef	ResultSet*			tUDF_LPRESULTS;

typedef Connection			tUDF_CONNECTION;
typedef Connection*			tUDF_LPCONNECTION;

typedef	Statement			tUDF_STATEMENT;
typedef	Statement*			tUDF_LPSTATEMENT;

typedef	PreparedStatement	tUDF_PREPAREDSTATEMENT;
typedef	PreparedStatement*	tUDF_LPPREPAREDSTATEMENT;

typedef	Savepoint			tUDF_SAVEPOINT;
typedef	Savepoint*			tUDF_LPSAVEPOINT;

#define udfRegisterMap(keytype, valueType, tname)	\
typedef map< keytype, valueType > tUDF_##tname; \
typedef map< keytype, valueType >::iterator tUDF_##tname##Iterator;

/*
 * AgeCategory datatype and API
 */
typedef struct{
	int				id;
	string			descr;
} tUDF_AGE_CATEGORY;
udfRegisterMap(int, tUDF_AGE_CATEGORY, AgeCategory);

tUDF_AgeCategory*	GetAgeCategoryList(tUDF_AgeCategory* filter);
tUDF_AgeCategory*	FindAgeCategory(tUDF_AgeCategory* filter);
long				AddAgeCategory(tUDF_AgeCategory* data);
long				RemoveAgeCategory(tUDF_AgeCategory* item);

/*
 * Category datatype and API
 */
typedef struct{
	unsigned long 	id;
	int				dance;
	int				liga;
	int				gender;
} tUDF_CATEGORY;
udfRegisterMap(int, tUDF_CATEGORY, Category);

tUDF_Category*		GetCategoryList(tUDF_Category* filter);
tUDF_Category*		FindCategory(tUDF_Category* filter);
long				AddCategory(tUDF_Category* data);
long				RemoveCategory(tUDF_Category* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	id;
	int				type;
	string 			name;
	string 			additional_info;
	int				city;
} tUDF_CHAMPIONSHIP;
udfRegisterMap(int, tUDF_CHAMPIONSHIP, Championship);

tUDF_Championship*	GetChampionshipList(tUDF_Championship* filter);
tUDF_Championship*	FindChampionship(tUDF_Championship* filter);
long				AddChampionship(tUDF_Championship* data);
long				RemoveChampionship(tUDF_Championship* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	championship_id;
	unsigned long	category_id;
} tUDF_CHAMPIONSHIP_CATEGORIES;
udfRegisterMap(int, tUDF_CHAMPIONSHIP_CATEGORIES, ChampionshipCategories);

tUDF_ChampionshipCategories*	GetChampionshipCategoriesList(tUDF_ChampionshipCategories* filter);
tUDF_ChampionshipCategories*	FindChampionshipCategories(tUDF_ChampionshipCategories* filter);
long							AddChampionshipCategories(tUDF_ChampionshipCategories* data);
long							RemoveChampionshipCategories(tUDF_ChampionshipCategories* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	championship_id;
	unsigned long	judge_id;
	unsigned long	team_id;
	unsigned long	category_id;
	int				mark;
} tUDF_CHAMPIONSHIP_JUDGES_MARK;
udfRegisterMap(int, tUDF_CHAMPIONSHIP_JUDGES_MARK, ChampionshipJudgesMark);

tUDF_ChampionshipJudgesMark*	GetChampionshipJudgesMarkList(tUDF_ChampionshipJudgesMark* filter);
tUDF_ChampionshipJudgesMark*	FindChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* filter);
long							AddChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* data);
long							RemoveChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	championship_id;
	unsigned long	judge_id;
} tUDF_CHAMPIONSHIP_JUDGES_TEAM;
udfRegisterMap(int, tUDF_CHAMPIONSHIP_JUDGES_TEAM, ChampionshipJudgesTeam);

tUDF_ChampionshipJudgesTeam*	GetChampionshipJudgesTeamList(tUDF_ChampionshipJudgesTeam* filter);
tUDF_ChampionshipJudgesTeam*	FindChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* filter);
long							AddChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* data);
long							RemoveChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	id;
	unsigned long	dancer_id;
	unsigned long	championship_id;
	string			composition_name;
	unsigned long	start_number;
} tUDF_CHAMPIONSHIP_TEAM;
udfRegisterMap(int, tUDF_CHAMPIONSHIP_TEAM, ChampionshipTeam);

tUDF_ChampionshipTeam*		GetChampionshipTeamList(tUDF_ChampionshipTeam* filter);
tUDF_ChampionshipTeam*		FindChampionshipTeam(tUDF_ChampionshipTeam* filter);
long						AddChampionshipTeam(tUDF_ChampionshipTeam* data);
long						RemoveChampionshipTeam(tUDF_ChampionshipTeam* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned int	id;
	string			name;
} tUDF_CHAMPIONSHIP_TYPE;
udfRegisterMap(int, tUDF_CHAMPIONSHIP_TYPE, ChampionshipType);

tUDF_ChampionshipType*		GetChampionshipTypeList(tUDF_ChampionshipType* filter);
tUDF_ChampionshipType*		FindChampionshipType(tUDF_ChampionshipType* filter);
long						AddChampionshipType(tUDF_ChampionshipType* data);
long						RemoveChampionshipType(tUDF_ChampionshipType* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	team_id;
	unsigned long	category_id;
} tUDF_CHAMPIONSHIP_TEAM_CATEGORIES;
udfRegisterMap(int, tUDF_CHAMPIONSHIP_TEAM_CATEGORIES, ChampionshipTeamCategories);

tUDF_ChampionshipTeamCategories*	GetChampionshipTeamCategoriesList(tUDF_ChampionshipTeamCategories* filter);
tUDF_ChampionshipTeamCategories*	FindChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* filter);
long								AddChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* data);
long								RemoveChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned int	id;
	unsigned int	country_id;
	string			name;
} tUDF_CITIES;
udfRegisterMap(int, tUDF_CITIES, Cities);

tUDF_Cities*		GetCitiesList(tUDF_Cities* filter);
tUDF_Cities*		FindCities(tUDF_Cities* filter);
long				AddCities(tUDF_Cities* data);
long				RemoveCities(tUDF_Cities* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	id;
	string			name;
	unsigned int	city;
	string			login;
	string			pass;
	string			email;
	string			contacts;
	string			web;
	string			location;
	int64_t			pay_date;
	int64_t			expire_date;
	string			director_name;
	int64_t			director_bd;
	string			director_phone;
	string			director_email;
} tUDF_CLUBS;
udfRegisterMap(int, tUDF_CLUBS, Clubs);

tUDF_Clubs*			GetClubsList(tUDF_Clubs* filter);
tUDF_Clubs*			FindClubs(tUDF_Clubs* filter);
long				AddClubs(tUDF_Clubs* data);
long				RemoveClubs(tUDF_Clubs* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned int	id;
	string			name;
} tUDF_COUNTRIES;
udfRegisterMap(int, tUDF_COUNTRIES, Counties);

tUDF_Counties*		GetCountiesList(tUDF_Counties* filter);
tUDF_Counties*		FindCounties(tUDF_Counties* filter);
long				AddCounties(tUDF_Counties* data);
long				RemoveCounties(tUDF_Counties* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned int	id;
	string			name;
} tUDF_DANCE_TYPES;
udfRegisterMap(int, tUDF_DANCE_TYPES, DanceTypes);

tUDF_DanceTypes*	GetDanceTypesyList(tUDF_DanceTypes* filter);
tUDF_DanceTypes*	FindDanceTypes(tUDF_DanceTypes* filter);
long				AddDanceTypes(tUDF_DanceTypes* data);
long				RemoveDanceTypes(tUDF_DanceTypes* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	id;
	unsigned long	club_id;
	unsigned long	trener_id;
	string			reg_book_num;
	string			name;
	unsigned long	raiting;
	int				liga;
	int64_t			bd;
	int				gender;
	unsigned int	city;
	int64_t			pay_date;
	int64_t			expire_date;
	int64_t			reg_date;
} tUDF_DANCERS;
udfRegisterMap(int, tUDF_DANCERS, Dancers);

tUDF_Dancers*		GetDancersList(tUDF_Dancers* filter);
tUDF_Dancers*		FindDancers(tUDF_Dancers* filter);
long				AddDancers(tUDF_Dancers* data);
long				RemoveDancers(tUDF_Dancers* item);

/*
 * Championship datatype and API
 */
typedef struct{
	int				id;
	string			name;
} tUDF_GENDER;
udfRegisterMap(int, tUDF_GENDER, Gender);

tUDF_Gender*		GetGenderList(tUDF_Gender* filter);
tUDF_Gender*		FindGender(tUDF_Gender* filter);
long				AddGender(tUDF_Gender* data);
long				RemoveGender(tUDF_Gender* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	id;
	string			name;
	unsigned 		country;
	unsigned 		city;
	unsigned 		club;
	string			attestation_info;
	int64_t			pay_date;
	int64_t			expire_date;
} tUDF_JUDGES;
udfRegisterMap(int, tUDF_JUDGES, Judges);

tUDF_Judges*		GetJudgesList(tUDF_Judges* filter);
tUDF_Judges*		FindJudges(tUDF_Judges* filter);
long				AddJudges(tUDF_Judges* data);
long				RemoveJudges(tUDF_Judges* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	judge_id;
	int				cat_id;
} tUDF_JUDGES_CATEGORIES_HAVE;
udfRegisterMap(int, tUDF_JUDGES_CATEGORIES_HAVE, JudgesCategoriesHave);

tUDF_JudgesCategoriesHave*		GetJudgesCategoriesHaveList(tUDF_JudgesCategoriesHave* filter);
tUDF_JudgesCategoriesHave*		FindJudgesCategoriesHave(tUDF_JudgesCategoriesHave* filter);
long							AddJudgesCategoriesHave(tUDF_JudgesCategoriesHave* data);
long							RemoveJudgesCategoriesHave(tUDF_JudgesCategoriesHave* item);

/*
 * Championship datatype and API
 */
typedef struct{
	int				id;
	string			name;
} tUDF_JUDGES_CATEGORIES_NAME;
udfRegisterMap(int, tUDF_JUDGES_CATEGORIES_NAME, JudgesCategoriesName);

tUDF_JudgesCategoriesName*		GetJudgesCategoriesNameList(tUDF_JudgesCategoriesName* filter);
tUDF_JudgesCategoriesName*		FindJudgesCategoriesName(tUDF_JudgesCategoriesName* filter);
long							AddJudgesCategoriesName(tUDF_JudgesCategoriesName* data);
long							RemoveJudgesCategoriesName(tUDF_JudgesCategoriesName* item);

/*
 * Championship datatype and API
 */
typedef struct{
	int				id;
	string			name;
} tUDF_LIGA;
udfRegisterMap(int, tUDF_LIGA, Liga);

tUDF_Liga*			GetLigaList(tUDF_Liga* filter);
tUDF_Liga*			FindLiga(tUDF_Liga* filter);
long				AddLiga(tUDF_Liga* data);
long				RemoveLiga(tUDF_Liga* item);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	id;
	unsigned long	club_id;
	string			name;
	int64_t			bd;
	int				city;
	string			phone;
	string			cantact_info;
	string			email;
	int64_t			pay_date;
	int64_t			expire_date;
} tUDF_TRENERS;
udfRegisterMap(int, tUDF_TRENERS, Treners);

tUDF_Treners*		GetTrenersList(tUDF_Treners* filter);
tUDF_Treners*		FindTreners(tUDF_Treners* filter);
long				AddTreners(tUDF_Treners* data);
long				RemoveTreners(tUDF_Treners* item);

/*******************************************************************************
 * DB Manager API
 *******************************************************************************/
//
// General API
// 
void				ConnectionOpen(string host, int port, string user, string pass);
void				ConnectionClose();
tUDF_LPCONNECTION	GetConnection();
tUDF_LPRESULTS		ExecureQuery(string query);
tUDF_LPSTATEMENT	PrepareStatement(string statement);
void				PreparedStatementSetString(tUDF_LPSTATEMENT statement, string str);
int					PreparedStatementExecute(tUDF_LPSTATEMENT statement);
tUDF_LPSAVEPOINT	SetSavepoint(string name);
void				ReleaseSavepoint(tUDF_LPSAVEPOINT save);
void				Rollback(tUDF_LPSAVEPOINT save);
void				Commit();

int dbmgr_test();

#ifdef __cplusplus
}
#endif

#endif //__UDF_DBMGR_H__