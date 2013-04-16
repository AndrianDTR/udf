#ifndef __udfutils_h__
#define __udfutils_h__

#include "dbmgr.h"

typedef std::list<unsigned char> 				tCList;
typedef std::list<unsigned char>::iterator 		tCListIt;

typedef struct{
	unsigned int	id;
	unsigned int 	startNum;
	int 			sum;
	tCList			marksList;
}tTourMarks;

typedef std::list<tTourMarks> 					tTourMarksList;
typedef std::list<tTourMarks>::iterator 		tTourMarksIt;

typedef std::list<unsigned int> 				tUIList;
typedef std::list<unsigned int>::iterator 		tUIListIt;
typedef std::list<unsigned int>::const_iterator tUIListCIt;

void dbmgr_version();

std::string date2str(time_t date);
time_t str2date(std::string str);

std::string time2str(time_t tTime);
time_t str2time(std::string str);

void SetGlobalDbConnection(CDbConnection* pCon);
CDbConnection* GetGlobalDbConnection();

long GetTeamsCountForChampionship(unsigned int nId, int& count);

long GetBlockLenById(unsigned int nId, time_t& len);
long GetTeamsInCategory(unsigned int nId, tUIList& teamsList);
long IsCategoryUsedOnCsById(unsigned int nId, unsigned int blockId);
long GetBlockCategories(unsigned int nId, tUIList& cats);

long JudgeHaveCategory(unsigned int judId, unsigned int catId, unsigned int& rowId);
long JudgeHaveCsCategory(unsigned int judId, unsigned int csId);

std::string 	GetTourTypeNameById(unsigned int nId);
long 			GetTourTypeByDancersCount(unsigned int nDancers, unsigned int& typeId);

long GetJudgesForCategory(unsigned int catId, tUIList& judges);

long GetTeamStartNumber(unsigned int teamId, unsigned int& startNum);

long GetTourTeams(unsigned int catId, unsigned int tourId, tUIList& teamsList);

long GetTourMarks(unsigned int tourId, const tUIList& judges, tTourMarksList& marks, bool final = false);
long GetTourCategoryId(unsigned int tourId, unsigned int& catId);

long GetPrevTourId(unsigned int tourId, unsigned int& prevTourId);

bool GetTeamPassTour(unsigned int teamId, unsigned int tourId);
long SetTeamPassTour(unsigned int teamId, unsigned int tourId, bool pass);

#endif // __udfutils_h__
