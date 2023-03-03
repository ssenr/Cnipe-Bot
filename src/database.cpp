#include <database.h>
#include <pqxx/pqxx>
#include <config.h>
#include <string>
#include <dpp/dpp.h>

/* Forward Declarations */
std::string message_delete_table();

/* Creating a Custom Datatype */
void db_connect(dpp::cluster& bot)
{
    try 
    {
        pqxx::connection C(CONN_STRING);
        if (C.is_open())
        {
           /*  std::cout << "Opened database successfully: " << C.dbname() << std::endl; */
            bot.log(dpp::loglevel::ll_info, "Opened database successfully!");
        }
        else 
        {
            /* std::cout << "Can't open database" << std::endl; */
            bot.log(dpp::loglevel::ll_critical, "Cannot Open Database!");
        }
        C.close();
    }
    catch (const std::exception &e)
    {
        /* std::cerr << e.what() << std::endl; */
        bot.log(dpp::loglevel::ll_error, e.what());
    }
}

/* Message Delete Schema */
std::string message_delete_table()
{
    table = "CREATE TABLE IF NOT EXISTS MESSAGE_DELETE(" \
             "ID            INT         PRIMARY KEY     NOT NULL," \
             "CHANNEL_ID    CHAR(64)," \
             "GUILD_ID      CHAR(64)                    NOTNULL," \
             "TRUE_NAME     VARCHAR(255)                NOT NULL," \
             ""
             ");";

    return table;
}
