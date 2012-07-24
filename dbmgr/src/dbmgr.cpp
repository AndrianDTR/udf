
#include "dbmgr.h"
#include "stdio.h"

#include <mysql/mysql.h>

void dbmgr_test(void)
{
	printf("This is a test lib call");
	
	do{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char *server = "192.169.10.17";
	char *user = "andrian";
	char *password = "dataNet"; /* set me first */
	char *database = "udf";
	conn = mysql_init(NULL);
	/* Connect to database */
	if (!mysql_real_connect(conn, server,
	user, password, database, 0, NULL, 0)) {
	fprintf(stderr, "%s\n", mysql_error(conn));
	break;
	}
	/* send SQL query */
	if (mysql_query(conn, "show tables")) {
	fprintf(stderr, "%s\n", mysql_error(conn));
	break;
	}
	res = mysql_use_result(conn);
	/* output table name */
	printf("MySQL Tables in mysql database:\n");
	while ((row = mysql_fetch_row(res)) != NULL)
	printf("%s \n", row[0]);
	/* close connection */
	mysql_free_result(res);
	mysql_close(conn);
	}while(0);

}