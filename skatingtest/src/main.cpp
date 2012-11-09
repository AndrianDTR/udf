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
	const int teams = 6;
	const int juds = 5;
	
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
		int a[10];
		int i=0, k=0, n=0, flag=-1;
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
		*/
		/*
		{1,1,1,4,4},
		{3,2,2,1,1},
		{2,5,5,2,2},
		{4,3,4,5,3},
		{5,4,3,3,5},
		{6,6,6,6,6}
		*/
		{4,6,6,6,6},
		{5,5,1,1,1},
		{6,1,3,3,4},
		{1,4,2,2,5},
		{2,2,5,5,2},
		{3,3,4,4,3}
		
	};
	
	/********** COPY ************/
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
	
	int nTeams;
	int **ppRes = 0;
		
	rules.GetMarks(nTeams, &ppRes);
	if(ppRes)
		printPlaces(teams, ppRes);

	return 0;
}
