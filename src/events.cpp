#include <cstdint>
#include <events.h>
#include <dpp/dpp.h>
#include <commands.h>
#include <string>
#include <vector>
#include <iostream>
#include <utils.h>

void e_message_create(dpp::cluster& bot, dpp::cache<dpp::message>& message_cache)
{
    bot.on_message_create([&] (const dpp::message_create_t& event)
    {
        dpp::message* message_ptr = new dpp::message();
        *message_ptr = event.msg;

        message_cache.store(message_ptr);
    });
}

void e_slashcommand_use(dpp::cluster& bot, dpp::cache<dpp::message>& message_cache)
{
    bot.on_slashcommand([&] (const dpp::slashcommand_t& event) 
    {
        if (event.command.get_command_name() == "get")
        {
            std::string param = std::get<std::string>(event.get_parameter("messageid"));
            event.reply(dc_comm_test(param, message_cache));
        }
        else if (event.command.get_command_name() == "cachesize")
        {
            event.reply(dc_comm_cache_size(message_cache));
        }
        else if (event.command.get_command_name() == "cachecount")
        {
            event.reply(dc_comm_cache_count(message_cache));
        }
        else if (event.command.get_command_name() == "iterate")
        {
            event.reply(dc_comm_cache_iterate(message_cache));
        }
    });
}

void e_on_ready(dpp::cluster& bot, std::vector<dpp::slashcommand> command_array)
{
    if (dpp::run_once<struct register_bot_commands>())
    {
        bot.global_bulk_command_create(command_array);
    }
}

void e_message_delete(dpp::cluster& bot, dpp::cache<dpp::message>& message_cache)
{
    bot.on_message_delete([&] (const dpp::message_delete_t& event)
    {
        /* Get Message ID of Deleted Message */
        std::string message_id = std::to_string( event.deleted->id );
        // bot.log(dpp::loglevel::ll_info, message_id);
        
        /* Search Cache for deleted message */
        dpp::message* message_ptr = search_cache(message_cache, message_id);

        if (message_ptr != NULL)
        {
            bot.log(dpp::loglevel::ll_info, "The message had the following content: "
            + message_ptr->content
            );
        }
        else 
        {
            bot.log(dpp::loglevel::ll_error, "The message cannot be found within the cache");
        }
    });
}

void e_message_update(dpp::cluster &bot, dpp::cache<dpp::message> &message_cache)
{
    // Store in Postgres DB
    // bot.on_message_update([&] (const dpp::message_update_t& event)
    // {
    //     dpp::message* message_ptr = new dpp::message();
    //     *message_ptr = event.msg; 
    //
    //     message_cache.store(message_ptr);
    // });
}




