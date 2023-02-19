#include <db_connection.h>
#include <mysql/mysqld_error.h>
#include <mysql/mysql.h>
#include <string>
#include <tuple>
#include <iostream>
#include <config.h>
/*
 * Make Class
 * 
 */

struct SQLConnection {
    std::string server, user, password, database;
    
    SQLConnection(std::string server, std::string user, std::string password, std::string database)
    {
        this->server = server;
        this->user = user;
        this->password = password;
        this->database = database;
    }
};

std::tuple<bool, MSQL *> sqlConnectionSetup(struct SQLConnection mysql_details)
{
    MYSQL *connection = mysql_init(NULL);
    bool success = true;

    if (!mysql_real_connect(connection, mysql_details.server.c_str(), mysql_details.user.c_str(), mysql_details.password.c_str(), mysql_details.database.c_str(), 0, NULL, 0))
    {
        success = false;
        /* This Will Not Log (Use Bot Logger)*/
        std::cout << "Connection Error: " << mysql_error(connection) << std::endl;
    } 

    return std::make_tuple(success, connection);
}

int db_connect()
{
    bool success;

    MYSQL *con;
    
    struct SQLConnection sql_details(HOST, USER_NAME, PASS_WORD, DATABASE);

    std::tie(success, con) = sqlConnectionSetup(sql_details);

    if (!success)
    {
        return 1;
    }
}
