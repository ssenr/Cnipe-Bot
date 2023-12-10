#include <cstdint>
#include <dpp/dpp.h>
#include "include/Config.h"
#include "include/sqlite3pp/sqlite3pp.h"

/**
 *  TRACKING:
 *  Droplet Specs
 *  1 GB Memory - 1 Intel VCPU - 25 GB SSD 
 *  Note: DPP won't have as big of a memory footprint
 **/

namespace snipe
{
    void db_connect()
    {
        try 
        {
            sqlite3pp::database db(SNIPE_DB_NAME);
        } 
        catch (const std::exception&) {}
    }
}

int main()
{
    const std::string BOT_TOKEN = BOT_TOKEN_H;
    dpp::cluster bot(BOT_TOKEN, BOT_INTENTS);

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

    /**
     *  Cache
    **/
    dpp::cache<dpp::message> message_cache;

    const auto store = [&bot, &message_cache](const dpp::message_create_t& event)
    {
        dpp::message* event_message = new dpp::message();
        *event_message = event.msg;

        /**
         *  Check Channel ID 
         *  Only one check for DEBUG purposes atm.
         *  UPDATE TO CHANNEL ID VECTOR LATER (This way you can specify what channels to avoid)
         **/
        uint64_t channel_id = event_message->channel_id;
        if (channel_id == GENERAL_CHANNEL_ID)
        {
            message_cache.store(event_message);
        }
        else 
        {
            bot.log(dpp::loglevel::ll_critical, "Please type message in #general channel!");
        }
    };
    bot.on_message_create(store);

    // END
    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([] (const dpp::slashcommand_t& event) 
    {
        if (event.command.get_command_name() == "ping") 
        {
            event.reply("Pong!");
        }
    });

    bot.on_ready(register_commands);

    bot.start(dpp::st_wait);
}
