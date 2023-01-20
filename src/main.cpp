#include "main.h"

int main() 
{
    const std::string bot_token = BOT_TOKEN;

    dpp::cluster bot(bot_token);
 
    bot.on_log(dpp::utility::cout_logger());
 
    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
         if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
    });
 
    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(
                dpp::slashcommand("ping", "Ping pong!", bot.me.id)
            );
        }
    });

    bot.on_message_delete([&bot](const dpp::message_delete_t& event) {
        bot.log(dpp::loglevel::ll_info, "Message Deleted");
    });
 
    bot.start(dpp::st_wait);
}