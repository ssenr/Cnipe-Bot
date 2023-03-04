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
        bool cond = has_bot_role(event.msg);
        if (!cond)
        {
            auto* message_ptr = new dpp::message();
            *message_ptr = event.msg;

            message_cache.store(message_ptr);
        }

        manage_cache(message_cache);
    });
}

void e_slashcommand_use(dpp::cluster& bot, dpp::cache<dpp::message>& delete_cache, dpp::cache<dpp::message>& update_cache ,std::vector<uint64_t>& delete_queue, std::vector<uint64_t>& update_queue)
{
    bot.on_slashcommand([&] (const dpp::slashcommand_t& event) 
    {
        if (event.command.get_command_name() == "get")
        {
            std::string param = std::get<std::string>(event.get_parameter("messageid"));
            event.reply(dc_comm_test(param, delete_cache));
        }
        else if (event.command.get_command_name() == "cachesize")
        {
            event.reply(dc_comm_cache_size(delete_cache));
        }
        else if (event.command.get_command_name() == "cachecount")
        {
            event.reply(dc_comm_cache_count(delete_cache));
        }
        else if (event.command.get_command_name() == "queuesize")
        {
            bool param = std::get<bool>(event.get_parameter("vector"));

            if (param)
            {
                event.reply(dc_comm_queue_size(delete_queue));
            }
            else
            {
                event.reply(dc_comm_queue_size(update_queue));
            }

        }
        else if (event.command.get_command_name() == "editsnipe")
        {
            event.reply(dc_comm_edit_snipe(delete_queue, delete_cache, update_cache));
        }
    });
}

void e_on_ready(dpp::cluster& bot, const std::vector<dpp::slashcommand>& command_array)
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
        std::string message_id = std::to_string( event.deleted->id );
        
        dpp::message* message_ptr = search_cache(message_cache, message_id);

        if (message_ptr != nullptr)
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

void e_message_update(dpp::cluster &bot, dpp::cache<dpp::message> &message_update_cache, std::vector<uint64_t>& update_queue)
{
    bot.on_message_update([&] (const dpp::message_update_t& event)
    {
        auto* message_ptr = new dpp::message();
        *message_ptr = event.msg;

        message_update_cache.store(message_ptr);

        update_queue.insert(update_queue.begin(), message_ptr->id);
    });
}