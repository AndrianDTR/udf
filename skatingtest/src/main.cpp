#include "udfcommon.h"
#include "udfskatingrules.h"

#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void printMarks(int teams, int juds, int** marks)
{
	int t,j;
	char formath[200] = {0};
	char formatb[200] = {0};
	char tmp[100] = {0};

	strcpy(formath, "team");
	strcpy(formatb, "%%d");
	for(j = 0; j < juds; j++)
	{
		sprintf(tmp, "\tJ%d ", j+1);
		strcat(formath, tmp);
	}

	printf(formath);
	for(t = 0; t < teams; t++)
	{
		printf("\n%d", t+1);
		for(j = 0; j < juds; j++)
		{
			printf("\t%d ", marks[t][j]);
		}
	}
	printf("\n\n");
}

void printPlaces(int teams, int** marks)
{
	int t,j;
	char formath[200] = {0};
	char formatb[200] = {0};
	char tmp[100] = {0};

	strcpy(formath, "team");
	strcpy(formatb, "%%d");
	for(j = 0; j <= teams; j++)
	{
		if(j==0)
			sprintf(tmp, "\t%d ", j+1);
		else if(j == teams)
			sprintf(tmp, "\tPlace ", 1, j+1);
		else
			sprintf(tmp, "\t%d-%d ", 1, j+1);
		strcat(formath, tmp);
	}

	printf(formath);
	for(t = 0; t < teams; t++)
	{
		printf("\n%d", t+1);
		for(j = 0; j < teams+1; j++)
		{
			if(marks[t][j])
				printf("\t%d ", marks[t][j]);
			else
				printf("\t- ");
		}
	}
	printf("\n\n");
}

int main(int argc, char **argv)
{
	const int teams = 9;
	const int juds = 32;

	srand(time(0));

	int** marks = new int*[teams];
	int t = 0;
	int j = 0;

	for(; t < teams; t++)
	{
		marks[t] = new int[juds];
		j = 0;
		for(; j < juds; j++)
		{
			marks[t][j] = -1;
		}
	}

	for(j = 0; j < juds; j++)
	{
		int i=0, n=0, flag=-1;
		while(i < teams)
		{
			n = rand() % teams + 1;
			for(t = 0; t < teams; t++)
			{
				if(n == marks[t][j])
				{
					flag = 0;
					break;
				}
				else
				{
					flag = 1;
				}
			}
			if(flag == 1)
			{
				marks[i][j] = n;
				i++;
			}
		}
	}

	int m[teams][juds] =
	{
		/*
		{1,1,1,4,4},
		{6,6,6,6,5},
		{2,2,5,4,1},
		{4,4,2,3,4},
		{1,5,1,1,2},
		{5,1,4,5,6}
		//*/
		/*
		{1,1,1,4,4},
		{3,2,2,1,1},
		{2,5,5,2,2},
		{4,3,4,5,3},
		{5,4,3,3,5},
		{6,6,6,6,6}
		//*/
		/*
		{4,6,6,6,6},
		{5,5,1,1,1},
		{6,1,3,3,4},
		{1,4,2,2,5},
		{2,2,5,5,2},
		{3,3,4,4,3}
		//*/
		/*
		{5,3,5,4,6,5,2},	// 5
		{3,1,4,3,5,1,1},	// 3
		{1,4,2,2,2,3,4},	// 2
		{2,2,3,1,4,2,3},	// 1
		{4,5,1,5,1,4,6},	// 4
		{6,6,6,6,3,6,5}		// 6
		//*/
		/*
		{2,1,5,1,1},
		{1,2,2,5,5},
		{5,6,1,2,2},
		{3,3,3,3,6},
		{4,4,4,6,4},
		{6,5,6,4,3}
		//*/
		
		/*
		// My test
		// Marks				  1		1-2		1-3		1-4		1-5		1-6		R
		{4, 4, 1, 2, 1, 6, 6}, // 2		3		3		5(12)	-		-		3
		{2, 6, 6, 3, 3, 5, 4}, // 0		1		3		4		5		-		5
		{6, 3, 4, 4, 2, 2, 5}, // 0		2		3		5(15)	-		-		4
		{5, 1, 5, 5, 6, 1, 3}, // 2		2		3		3		6		-		6
		{3, 5, 3, 1, 4, 3, 2}, // 1		2		5		-		-		-		2
		{1, 2, 2, 6, 5, 4, 1}, // 2		4		-		-		-		-		1
		//*/

		/*
		{4, 3, 5, 3, 2}, //	- 	1 		3(8) 	4(12) 	5(17) 	5(17) 	3,5
		{3, 2, 2, 4, 1}, //	1 	3(5) 	- 		 -		-		-		2
		{2, 1, 1, 5, 4}, //	2 	3(4) 	- 		-		-		-		1
		{5, 4, 3, 2, 3}, //	- 	1 		3(8)	4(12) 	5(17) 	5(17) 	3,5
		{1, 5, 4, 1, 6}, //	2 	2 		2 		3 		-		-		5
		{6, 6, 6, 6, 5}  //	- 	- 		- 		- 		1 		5 		6
		//*/
		
		/*
		{4, 4, 6, 2, 4}  // 4
		{1, 1, 1, 1, 6}  // 1
		{5, 3, 5, 4, 5}  // 5
		{2, 6, 2, 3, 1}  // 2
		{3, 2, 3, 5, 2}  // 3
		{6, 5, 4, 6, 3}  // 6
		//*/
		
		/*
		team	J1 	J2 	J3 	J4 	J5 	J6 	J7 	J8 	J9 	J10 	J11 	J12 	J13 	J14 	J15 	Place
		1		1 	9 	5 	4 	8 	7 	2 	1 	2 	7 		7 		2 		3 		8 		8 		6
		2		3 	4 	3 	6 	4 	1 	6 	6 	4 	8 		1 		8 		6 		3 		1 		1.5
		3		7 	2 	4 	8 	1 	2 	7 	8 	8 	6 		3 		4 		8 		7 		2 		8
		4		4 	6 	6 	3 	2 	3 	9 	2 	7 	1 		8 		9 		2 		4 		3 		1.5
		5		2 	8 	7 	5 	7 	5 	5 	3 	6 	5 		9 		6 		9 		6 		7 		7
		6		5 	7 	2 	1 	6 	9 	1 	4 	9 	2 		4 		3 		5 		5 		4 		4
		7		9 	1 	9 	9 	3 	4 	4 	9 	1 	4 		6 		7 		1 		2 		6 		3
		8		6 	5 	8 	2 	5 	6 	3 	5 	3 	3 		5 		5 		7 		1 		5 		5
		9		8 	3 	1 	7 	9 	8 	8 	7 	5 	9 		2 		1 		4 		9 		9 		9
		//*/
	};

	/********** COPY ************/
	/*
	for(t = 0; t < teams; t++)
	{
		for(j = 0; j < juds; j++)
		{
			marks[t][j] = m[t][j];
		}
	}
	/******** END COPY **********/

	printMarks(teams, juds, marks);

	udfSkatingRules rules(teams, juds, marks);

	iiMap ppRes;
	rules.GetMarks(ppRes);
	
	printf("\n\n====================================");
	printf("\nTeam\t=\tPlace");
	iiIt place = ppRes.begin();
	for(; place != ppRes.end(); place++)
	{
		if(place->second % 10)
			printf("\n%d\t=\t%.1f", place->first+1, place->second/10.0);
		else
			printf("\n%d\t=\t%.0f", place->first+1, place->second/10.0);
	}
	printf("\n====================================\n");

	return 0;
}
