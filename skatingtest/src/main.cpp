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
	int teams = 6;
	int juds = 5;
	
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
			marks[t][j] = rand()%teams + 1;
		}
	}
	for(j = 0; j < juds; j++)
	{
		for(t = 0; t < teams; t++)
		{
			int m = 0;
			for(m = 0; m < t; m++)
			{
				while(marks[t][j] == marks[m][j])
				{
					marks[t][j] = rand()%teams + 1;
				}
			}
		}
		
	}  
	
	printMarks(teams, juds, marks);
	
	udfSkatingRules rules(teams, juds, marks);
	
	int nTeams;
	int **ppRes = 0;
		
	rules.GetMarks(nTeams, &ppRes);
	if(ppRes)
		printPlaces(teams, ppRes);
		
	return 0;
}
