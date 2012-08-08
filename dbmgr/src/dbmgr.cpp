
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

tUDF_AgeCategory* GetAgeCategoryList(tUDF_AgeCategory* filter)
{
}

tUDF_AgeCategory* FindAgeCategory(tUDF_AgeCategory* filter)
{
}

long AddAgeCategory(tUDF_AgeCategory* data)
{
}

long RemoveAgeCategory(tUDF_AgeCategory* item)
{
}

tUDF_Category* GetCategoryList(tUDF_Category* filter)
{
}

tUDF_Category* FindCategory(tUDF_Category* filter)
{
}

long AddCategory(tUDF_Category* data)
{
}

long RemoveCategory(tUDF_Category* item)
{
}

tUDF_Championship* GetChampionshipList(tUDF_Championship* filter)
{
}

tUDF_Championship* FindChampionship(tUDF_Championship* filter)
{
}

long AddChampionship(tUDF_Championship* data)
{
}

long RemoveChampionship(tUDF_Championship* item)
{
}

tUDF_ChampionshipCategories* GetChampionshipCategoriesList(tUDF_ChampionshipCategories* filter)
{
}

tUDF_ChampionshipCategories* FindChampionshipCategories(tUDF_ChampionshipCategories* filter)
{
}

long AddChampionshipCategories(tUDF_ChampionshipCategories* data)
{
}

long RemoveChampionshipCategories(tUDF_ChampionshipCategories* item)
{
}

tUDF_ChampionshipJudgesMark* GetChampionshipJudgesMarkList(tUDF_ChampionshipJudgesMark* filter)
{
}

tUDF_ChampionshipJudgesMark* FindChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* filter)
{
}

long AddChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* data)
{
}

long RemoveChampionshipJudgesMark(tUDF_ChampionshipJudgesMark* item)
{
}

tUDF_ChampionshipJudgesTeam* GetChampionshipJudgesTeamList(tUDF_ChampionshipJudgesTeam* filter)
{
}

tUDF_ChampionshipJudgesTeam* FindChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* filter)
{
}

long AddChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* data)
{
}

long RemoveChampionshipJudgesTeam(tUDF_ChampionshipJudgesTeam* item)
{
}

tUDF_ChampionshipTeam* GetChampionshipTeamList(tUDF_ChampionshipTeam* filter)
{
}

tUDF_ChampionshipTeam* FindChampionshipTeam(tUDF_ChampionshipTeam* filter)
{
}

long AddChampionshipTeam(tUDF_ChampionshipTeam* data)
{
}

long RemoveChampionshipTeam(tUDF_ChampionshipTeam* item)
{
}

tUDF_ChampionshipType* GetChampionshipTypeList(tUDF_ChampionshipType* filter)
{
}

long AddChampionshipType(tUDF_ChampionshipType* data)
{
}

long RemoveChampionshipType(tUDF_ChampionshipType* item)
{
}

tUDF_ChampionshipTeamCategories* GetChampionshipTeamCategoriesList(tUDF_ChampionshipTeamCategories* filter)
{
}

tUDF_ChampionshipTeamCategories* FindChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* filter)
{
}

long AddChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* data)
{
}

long RemoveChampionshipTeamCategories(tUDF_ChampionshipTeamCategories* item)
{
}

tUDF_Cities* GetCitiesList(tUDF_Cities* filter)
{
}

tUDF_Cities* FindCities(tUDF_Cities* filter)
{
}

long AddCities(tUDF_Cities* data)
{
}

long RemoveCities(tUDF_Cities* item)
{
}

tUDF_Clubs* GetClubsList(tUDF_Clubs* filter)
{
}

tUDF_Clubs* FindClubs(tUDF_Clubs* filter)
{
}

long AddClubs(tUDF_Clubs* data)
{
}

long RemoveClubs(tUDF_Clubs* item)
{
}

tUDF_Counties* GetCountiesList(tUDF_Counties* filter)
{
}

tUDF_Counties* FindCounties(tUDF_Counties* filter)
{
}

long AddCounties(tUDF_Counties* data)
{
}

long RemoveCounties(tUDF_Counties* item)
{
}

tUDF_DanceTypes* GetDanceTypesyList(tUDF_DanceTypes* filter)
{
}

tUDF_DanceTypes* FindDanceTypes(tUDF_DanceTypes* filter)
{
}

long AddDanceTypes(tUDF_DanceTypes* data)
{
}

long RemoveDanceTypes(tUDF_DanceTypes* item)
{
}

tUDF_Dancers* GetDancersList(tUDF_Dancers* filter)
{
}

tUDF_Dancers* FindDancers(tUDF_Dancers* filter)
{
}

long AddDancers(tUDF_Dancers* data)
{
}

long RemoveDancers(tUDF_Dancers* item)
{
}

tUDF_Gender* GetGenderList(tUDF_Gender* filter)
{
}

tUDF_Gender* FindGender(tUDF_Gender* filter)
{
}

long AddGender(tUDF_Gender* data)
{
}

long RemoveGender(tUDF_Gender* item)
{
}

tUDF_Judges* GetJudgesList(tUDF_Judges* filter)
{
}

tUDF_Judges* FindJudges(tUDF_Judges* filter)
{
}

long AddJudges(tUDF_Judges* data)
{
}

long RemoveJudges(tUDF_Judges* item)
{
}

tUDF_JudgesCategoriesHave* GetJudgesCategoriesHaveList(tUDF_JudgesCategoriesHave* filter)
{
}

tUDF_JudgesCategoriesHave* FindJudgesCategoriesHave(tUDF_JudgesCategoriesHave* filter)
{
}

long AddJudgesCategoriesHave(tUDF_JudgesCategoriesHave* data)
{
}

long RemoveJudgesCategoriesHave(tUDF_JudgesCategoriesHave* item)
{
}

tUDF_JudgesCategoriesName* GetJudgesCategoriesNameList(tUDF_JudgesCategoriesName* filter)
{
}

tUDF_JudgesCategoriesName* FindJudgesCategoriesName(tUDF_JudgesCategoriesName* filter)
{
}

long AddJudgesCategoriesName(tUDF_JudgesCategoriesName* data)
{
}

long RemoveJudgesCategoriesName(tUDF_JudgesCategoriesName* item)
{
}

tUDF_Liga* GetLigaList(tUDF_Liga* filter)
{
}

tUDF_Liga* FindLiga(tUDF_Liga* filter)
{
}

long AddLiga(tUDF_Liga* data)
{
}

long RemoveLiga(tUDF_Liga* item)
{
}

tUDF_Treners* GetTrenersList(tUDF_Treners* filter)
{
}

tUDF_Treners* FindTreners(tUDF_Treners* filter)
{
}

long AddTreners(tUDF_Treners* data)
{
}

long RemoveTreners(tUDF_Treners* item)
{
}

void ConnectionOpen(string host, int port, string user, string pass)
{
}

void ConnectionClose()
{
}

tUDF_LPCONNECTION GetConnection()
{
}

tUDF_LPRESULTS ExecureQuery(string query)
{
}

tUDF_LPSTATEMENT PrepareStatement(string statement)
{
}

void PreparedStatementSetString(tUDF_LPSTATEMENT statement, string str)
{
}

int PreparedStatementExecute(tUDF_LPSTATEMENT statement)
{
}

tUDF_LPSAVEPOINT SetSavepoint(string name)
{
}

void ReleaseSavepoint(tUDF_LPSAVEPOINT save)
{
}

void Rollback(tUDF_LPSAVEPOINT save)
{
}

void Commit()
{
}
