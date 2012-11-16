#ifndef __udfSkatingRules_h__
#define __udfSkatingRules_h__

#include "map"

using namespace std;

typedef map<int,int>				iiMap;
typedef map<int,int>::iterator			iiIt;
typedef map<int,int>::reverse_iterator	iiRit;

class udfSkatingRules
{
private:
	int 	m_nTeams;
	int 	m_nJudges;
	int** 	m_ppnMarks;
	int** 	m_ppnResults;

	/*
	 * Precalculate tables
	 */
	int** 	m_ppnPlacesCount;
	int** 	m_ppnPlacesRange;
	int** 	m_ppnPlacesSums;

public:
	udfSkatingRules(int teams, int judges, int** marks);
	virtual ~udfSkatingRules();

	bool	GetMarks(int& nTeams, int*** marks);

protected:
	virtual bool Rule1();
	virtual bool Rule2();
	virtual bool Rule3();
	virtual bool Rule4();
	virtual bool Rule5();
	virtual bool Rule6();
	virtual bool Rule7();
	iiMap		 Rule7B(int place, iiMap tList, int** sumTable, int** rngTable);
	virtual bool Rule8();
	virtual bool Rule9();
	virtual bool Rule10();
	virtual bool Rule11();

	int**		CreateMarkTable();
	void		FreeMarkTable(int**& tbl);

	void 		printTable(int teams, int** marks);

	int**		CalculatePlacesCount(int** marksTbl);
	int**		CalculatePlacesRange(int** countTbl);
	int**		CalculatePlacesSum(int** marksTbl);
};

#endif // __udfSkatingRules_h__
