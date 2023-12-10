#include <dpp/dpp.h>
#include "include/Config.h"
#include "include/sqlite3pp/sqlite3pp.h"
// #include <SQLiteCpp/SQLiteCpp.h>

/**
 *  TRACKING:
 *  Droplet Specs
 *  1 GB Memory - 1 Intel VCPU - 25 GB SSD 
 *  Note: DPP won't have as big of a memory footprint
 **/

namespace snipe
{
    std::string db_connect()
    {
        std::string s = "Uninitialized";
        try 
        {
            sqlite3pp::database db("sharks.db");
            s = "Connected!";
            return s;
        } 
        catch (const std::exception&) {return s;}
    }
    /* void db_connect() */
    /* { */
    /*     try  */
    /*     { */
    /*         SQLite::Database db("sharks.db", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);                 */
    /*     } */
    /*     catch (const std::exception&) {} */
    /*     remove("sharks.db"); */
    /* } */
}

int main()
{
    const std::string BOT_TOKEN = BOT_TOKEN_H;
    dpp::cluster bot(BOT_TOKEN);

    const dpp::snowflake BOT_ID = bot.me.id; 

    dpp::slashcommand ping("ping", "Ping pong!", BOT_ID);

    std::vector<dpp::slashcommand> slashcommand_list = {ping};

    const auto register_commands = [&bot, &slashcommand_list](const dpp::ready_t& event) 
    {
        if (dpp::run_once<struct register_bot_commands>()) 
        {
            bot.global_bulk_command_create(slashcommand_list);
        }
    };

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([] (const dpp::slashcommand_t& event) 
    {
        if (event.command.get_command_name() == "ping") 
        {
            std::string x = snipe::db_connect();
            event.reply(x);
        }
    });

    bot.on_ready(register_commands);

    bot.start(dpp::st_wait);
}
