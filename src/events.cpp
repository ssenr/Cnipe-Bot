#include <events.h>
#include <dpp/dpp.h>
#include <commands.h>
#include <string>

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
    bot.on_slashcommand([&] (const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "Get")
        {
            std::string param = std::get<std::string>(event.get_parameter("messageid"));
            std::string response = dc_comm_test(param, message_cache);
            event.reply(response);
        }
    });
}


