#include <events.h>
#include <dpp/dpp.h>
#include <commands.h>
#include <string>
#include <vector>

/*
 * Add Master Event Handler
 */

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
    });
}

void e_on_ready(dpp::cluster& bot, std::vector<dpp::slashcommand> command_array)
{
    if (dpp::run_once<struct register_bot_commands>())
    {
        bot.global_bulk_command_create(command_array);
    }
}
