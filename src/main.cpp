#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

int main() {

    // Get Token
    std::string s = "/Users/duranr/Documents/Cnipe-Bot/src/config.json";
    std::ifstream i(s);
    std::string current_path = std::filesystem::current_path().string()
    json data = json::parse(i);
    const std::string bot_token = data.at("token");

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
 
    bot.start(dpp::st_wait);
}