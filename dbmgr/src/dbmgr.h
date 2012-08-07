#ifndef __DBMGR_H__
#define __DBMGR_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>

#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <cppconn/warning.h>

using namespace std;
using namespace sql;

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

#include "string"
#include "map"

#define udfRegisterMap(keytype, valueType, name)	\
typedef map<keytype, valueType> tUDF_Map##name; \
typedef map<keytype, valueType>::iterator tUDF_MapIterator##name; 


typedef struct{
	int				id;
	string			descr;
} tUDF_AGE_CATEGORY;
typedef map<int, tUDF_AGE_CATEGORY> tUDF_AgeCategoryMap;
typedef map<int, tUDF_AGE_CATEGORY>::iterator tUDF_AgeCategoryMapIterator;

typedef struct{
	unsigned long 	id;
	int				dance;
	int				liga;
	int				gender;
} tUDF_CATEGORY;
udfRegisterMap(unsigned long, tUDF_CATEGORY, tUDF_Category)

typedef struct{
	unsigned long	id;
	int				type;
	string 			name;
	string 			additional_info;
	int				city;
} tUDF_CHAMPIONSHIP;
typedef tUDF_CHAMPIONSHIP* tUDF_LPCHAMPIONSHIP;

typedef struct{
	unsigned long	championship_id;
	unsigned long	category_id;
} tUDF_CHAMPIONSHIP_CATEGORIES;
typedef tUDF_CHAMPIONSHIP_CATEGORIES* tUDF_LPCHAMPIONSHIP_CATEGORIES;

typedef struct{
	unsigned long	championship_id;
	unsigned long	judge_id;
	unsigned long	team_id;
	unsigned long	category_id;
	int				mark;
} tUDF_CHAMPIONSHIP_JUDGES_MARK;
typedef tUDF_CHAMPIONSHIP_JUDGES_MARK* tUDF_LPCHAMPIONSHIP_JUDGES_MARK;

typedef struct{
	unsigned long	championship_id;
	unsigned long	judge_id;
} tUDF_CHAMPIONSHIP_JUDGES_TEAM;
typedef tUDF_CHAMPIONSHIP_JUDGES_TEAM* tUDF_LPCHAMPIONSHIP_JUDGES_TEAM;

typedef struct{
	unsigned long	id;
	unsigned long	dancer_id;
	unsigned long	championship_id;
	string			composition_name;
	unsigned long	start_number;
} tUDF_CHAMPIONSHIP_TEAM;
typedef tUDF_CHAMPIONSHIP_TEAM* tUDF_LPCHAMPIONSHIP_TEAM;

typedef struct{
	unsigned int	id;
	string			name;
} tUDF_CHAMPIONSHIP_TYPE;
typedef tUDF_CHAMPIONSHIP_TYPE* tUDF_LPCHAMPIONSHIP_TYPE;

typedef struct{
	unsigned long	team_id;
	unsigned long	category_id;
} tUDF_CHAMPIONSHIP_TEAM_CATEGORIES;
typedef tUDF_CHAMPIONSHIP_TEAM_CATEGORIES* tUDF_LPCHAMPIONSHIP_TEAM_CATEGORIES;

typedef struct{
	unsigned int	id;
	unsigned int	country_id;
	string			name;
} tUDF_CITIES;
typedef tUDF_CITIES* tUDF_LPCITIES;

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
typedef tUDF_CLUBS* tUDF_LPCLUBS;

typedef struct{
	unsigned int	id;
	string			name;
} tUDF_COUNTRIES;
typedef tUDF_COUNTRIES* tUDF_LPCOUNTRIES;

typedef struct{
	unsigned int	id;
	string			name;
} tUDF_DANCE_TYPES;
typedef tUDF_DANCE_TYPES* tUDF_LPDANCE_TYPES;

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
typedef tUDF_DANCERS* tUDF_LPDANCERS;

typedef struct{
	int				id;
	string			name;
} tUDF_GENDER;
typedef tUDF_GENDER* tUDF_LPGENDER;

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
typedef tUDF_JUDGES* tUDF_LPJUDGES;

typedef struct{
	unsigned long	judge_id;
	int				cat_id;
} tUDF_JUDGES_CATEGORIES_HAVE;
typedef tUDF_JUDGES_CATEGORIES_HAVE* tUDF_LPJUDGES_CATEGORIES_HAVE;

typedef struct{
	int				id;
	string			name;
} tUDF_JUDGES_CATEGORIES_NAME;
typedef tUDF_JUDGES_CATEGORIES_NAME* tUDF_LPJUDGES_CATEGORIES_NAME;

typedef struct{
	int				id;
	string			name;
} tUDF_LIGA;
typedef tUDF_LIGA*	tUDF_LPLIGA;

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
typedef tUDF_TRENERS* tUDF_LPTRENERS;

/*******************************************************************************
 * DB Manager API
 *******************************************************************************/
//
// General API
// 
void				ConnectionOpen(string host, int port, string user, string pass);
void				ConnectionClose();
tUDF_LPCONNECTION	GetConnection();

// 
// Age categories
// 
long	AgeCategoryGetFirst(tUDF_LPAGE_CATEGORY data);
long	AgeCategoryGetNext(tUDF_LPAGE_CATEGORY data);
long	AgeCategoryGetAll(tUDF_LPAGE_CATEGORY* data);

int dbmgr_test();

#ifdef __cplusplus
}
#endif

#endif //__DBMGR_H__