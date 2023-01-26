#include <connector.h>
#include <config.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>

void conn_DB() 
{
    sql::mysql::MySQL_Driver *driver;
    try
    {
        sql::Connection *conn;
        sql::Statement *stmt;
        sql::ResultSet *res;
        sql::PreparedStatement *pstmt;

        /* Establish a Connection */
        driver = get_driver_instance();
        conn = driver->connect(CONN_STRING, USER_NAME, PASS_WORD);
        std::cout << "Connected to database\n";
    }
    catch (int Age) 
    {
        std::cout<<"Cannot connect to database\n";
    }
}