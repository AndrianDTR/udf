
#include "dbmgr.h"
/* MySQL Connector/C++ specific headers */

int dbmgr_test(void)
{
	Driver *driver;
	Connection *con;
	Statement *stmt;
	ResultSet *res;
	PreparedStatement *prep_stmt;
	Savepoint *savept;

	int updatecount = 0;

	// initiate url, user, password and database variables */
	//string url(DBHOST);
	//const string user(USER);
	//const string password(PASSWORD);
	//const string database(DATABASE);

	try {
		driver = get_driver_instance();
		/*
		// create a database connection using the Driver 
		con = driver -> connect(url, user, password);

		// alternate syntax using auto_ptr to create the db connection 
		//auto_ptr  con (driver -> connect(url, user, password));

		// turn off the autocommit 
		con -> setAutoCommit(0);
		
		// select appropriate database schema 
		con -> setSchema(database);
		
		// retrieve and display the database metadata 
		//retrieve_dbmetadata_and_print (con);

		// create a statement object 
		stmt = con -> createStatement();

		cout << "Executing the Query: \"SELECT * FROM cities\" .." << endl;

		//res = stmt -> executeQuery ("set character_set_client='utf8'");
		//res = stmt -> executeQuery ("set character_set_results='utf8'");
		//res = stmt -> executeQuery ("set collation_connection='utf8_general_ci'");
		// run a query which returns exactly one result set 
		res = stmt->executeQuery("SELECT * FROM age_category");

		cout << "Retrieving the result set ..." << endl;
		while (res->next())
		{
			cout<<res->getString(1)<<" "<<res->getString(2)<<endl;
		}
		//retrieve_rsmetadata_and_print(res);

		// retrieve the data from the result set and display on stdout 
		//retrieve_data_and_print (res, NUMOFFSET, 1, string("CityName"));

		// retrieve and display the result set metadata 
		//retrieve_rsmetadata_and_print (res);

		//cout << "Demonstrating Prepared Statements .. " << endl << endl;

		// insert couple of rows of data into City table using Prepared Statements 
		//prep_stmt = con -> prepareStatement ("INSERTmysql_query ("set character_set_client='cp1251'");

		//cout << "\tInserting \"London, UK\" into the table, City .." << endl;

		//prep_stmt -> setString (1, "London, UK");
		//updatecount = prep_stmt -> executeUpdate();

		//cout << "\tCreating a save point \"SAVEPT1\" .." << endl;
		//savept = con -> setSavepoint ("SAVEPT1");

		//cout << "\tInserting \"Paris, France\" into the table, City .." << endl;

		//prep_stmt -> setString (1, "Paris, France");
		//updatecount = prep_stmt -> executeUpdate();

		//cout << "\tRolling back until the last save point \"SAVEPT1\" .." << endl;
		//con -> rollback (savept);
		//con -> releaseSavepoint (savept);

		//cout << "\tCommitting outstanding updates to the database .." << endl;
		//con -> commit();

		//cout << "\nQuerying the City table again .." << endl;

		// re-use result set object 
		res = NULL;
		//res = stmt -> executeQuery ("SELECT * FROM City");

		// retrieve the data from the result set and display on stdout 
		//retrieve_data_and_print (res, COLNAME, 1, string ("CityName"));

		cout << "Cleaning up the resources ... exit!" << endl;

		// Clean up 
		delete res;
		delete stmt;
		delete prep_stmt;
		con -> close();
		delete con;
		//*/
	} catch (SQLException &e) {
		cout << "ERROR: SQLException in " << __FILE__;
		cout << " (" << __func__<< ") on line " << __LINE__ << endl;
		cout << "ERROR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << ")" << endl;

		if (e.getErrorCode() == 1047) {
			/*
			Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
			*/
			cout << "\nYour server does not seem to support Prepared Statements at all. ";
			cout << "Perhaps MYSQL < 4.1?" << endl;
		}

		return EXIT_FAILURE;
	} catch (std::runtime_error &e) {

		cout << "ERROR: runtime_error in " << __FILE__;
		cout << " (" << __func__ << ") on line " << __LINE__ << endl;
		cout << "ERROR: " << e.what() << endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;

}

