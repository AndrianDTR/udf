#include "dbaccessmgr.h"

#include "mysql/mysql.h"
#include <stdio.h>
#include <stdlib.h>

void DBA_test()
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char *server = "localhost";
	char *user = "root";
	char *password = "PASSWORD"; /* set me first */
	char *database = "mysql";
	
	conn = mysql_init(0);
	/* Connect to database */
	if (!mysql_real_connect(conn, server,
		user, password, database, 0, 0, 0)) 
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	/* send SQL query */
	if (mysql_query(conn, "show tables")) 
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	
	res = mysql_use_result(conn);
	/* output table name */
	printf("MySQL Tables in mysql database:\n");
	while ((row = mysql_fetch_row(res)) != 0)
		printf("%s \n", row[0]);
		
	/* close connection */
	mysql_free_result(res);
	mysql_close(conn);
}
