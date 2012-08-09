#ifndef __UDFDATATYPES_H__
#define __UDFDATATYPES_H__

#include <memory>
#include <sstream>
#include <stdexcept>

#include "cppconn/connection.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"
#include "cppconn/resultset.h"
#include "cppconn/exception.h"
#include "cppconn/warning.h"

#include "map"
#include "string"

using namespace std;
using namespace sql;

#define udfRegisterMap(keytype, valueType, tname)	\
typedef map< keytype, valueType > tUDF_##tname; \
typedef map< keytype, valueType >::iterator tUDF_##tname##Iterator;


typedef	ResultSet			tUDF_RESULTS;
typedef	ResultSet*			tUDF_LPRESULTS;

typedef	Statement			tUDF_STATEMENT;
typedef	Statement*			tUDF_LPSTATEMENT;

typedef	PreparedStatement	tUDF_PREPAREDSTATEMENT;
typedef	PreparedStatement*	tUDF_LPPREPAREDSTATEMENT;

typedef	Savepoint			tUDF_SAVEPOINT;
typedef	Savepoint*			tUDF_LPSAVEPOINT;

/*
 * AgeCategory datatype and API
 */
typedef struct{
	int				id;
	string			descr;
} tUDF_AGE_CATEGORY;
udfRegisterMap(int, tUDF_AGE_CATEGORY, AgeCategory);

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

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	championship_id;
	unsigned long	category_id;
} tUDF_CHAMPIONSHIP_CATEGORIES;
udfRegisterMap(int, tUDF_CHAMPIONSHIP_CATEGORIES, ChampionshipCategories);

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

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	championship_id;
	unsigned long	judge_id;
} tUDF_CHAMPIONSHIP_JUDGES_TEAM;
udfRegisterMap(int, tUDF_CHAMPIONSHIP_JUDGES_TEAM, ChampionshipJudgesTeam);

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

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned int	id;
	string			name;
} tUDF_CHAMPIONSHIP_TYPE;
udfRegisterMap(int, tUDF_CHAMPIONSHIP_TYPE, ChampionshipType);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	team_id;
	unsigned long	category_id;
} tUDF_CHAMPIONSHIP_TEAM_CATEGORIES;
udfRegisterMap(int, tUDF_CHAMPIONSHIP_TEAM_CATEGORIES, ChampionshipTeamCategories);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned int	id;
	unsigned int	country_id;
	string			name;
} tUDF_CITIES;
udfRegisterMap(int, tUDF_CITIES, Cities);

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

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned int	id;
	string			name;
} tUDF_COUNTRIES;
udfRegisterMap(int, tUDF_COUNTRIES, Counties);

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned int	id;
	string			name;
} tUDF_DANCE_TYPES;
udfRegisterMap(int, tUDF_DANCE_TYPES, DanceTypes);

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

/*
 * Championship datatype and API
 */
typedef struct{
	int				id;
	string			name;
} tUDF_GENDER;
udfRegisterMap(int, tUDF_GENDER, Gender);

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

/*
 * Championship datatype and API
 */
typedef struct{
	unsigned long	judge_id;
	int				cat_id;
} tUDF_JUDGES_CATEGORIES_HAVE;
udfRegisterMap(int, tUDF_JUDGES_CATEGORIES_HAVE, JudgesCategoriesHave);

/*
 * Championship datatype and API
 */
typedef struct{
	int				id;
	string			name;
} tUDF_JUDGES_CATEGORIES_NAME;
udfRegisterMap(int, tUDF_JUDGES_CATEGORIES_NAME, JudgesCategoriesName);

/*
 * Championship datatype and API
 */
typedef struct{
	int				id;
	string			name;
} tUDF_LIGA;
udfRegisterMap(int, tUDF_LIGA, Liga);

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

#endif //__UDFDATATYPES_H__