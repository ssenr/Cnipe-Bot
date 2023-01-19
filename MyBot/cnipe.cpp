#include "cnipe.h"
#include <dpp/dpp.h>
#include "json.h"
#include <fstream>

using json = nlohmann::json;

int main()
{
    // Get Token
    std::ifstream f("config.json");
    json data = json::parse(f);
    const std::string bot_token = data.at("token");

    // Bot Operations
    dpp::cluster bot(bot_token);

    /* Output simple log messages to stdout */
    bot.on_log(dpp::utility::cout_logger());

    /* Handle slash command */
    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
         if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
    });

    /* Register slash command here in on_ready */
    bot.on_ready([&bot](const dpp::ready_t& event) {
        /* Wrap command registration in run_once to make sure it doesnt run on every full reconnection */
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));
        }
    });
    
    /* Start the bot */
    bot.start(false);

    return 0;
}
