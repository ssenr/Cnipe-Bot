#include <database.h>
#include <pqxx/pqxx>
#include <config.h>
#include <string>
#include <dpp/dpp.h>

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
