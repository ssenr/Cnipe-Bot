#include "main.h"

namespace fs = std::filesystem;

int main() 
{
    // Retrieve Token from Header
    const std::string bot_token = BOT_TOKEN;
    
    // Create Bot
    uint64_t intents = dpp::i_default_intents | 
                       dpp::i_message_content |
                       dpp::i_guild_members;

    dpp::cluster bot(bot_token, intents);
 
    bot.on_log(dpp::utility::cout_logger());
 
    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
         if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
    });
    
    
    
    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            
            // PING
            bot.global_command_create(
                dpp::slashcommand(
                    "ping", 
                    "Ping pong!", 
                    bot.me.id
                )
            );
            
            // SNIPE
            // SNIPE WITH IMAGE IF ATTACHMENT
            // INCLUDES A MESSAGE IF REPLY
            bot.global_command_create(
                dpp::slashcommand(
                    "Snipe", 
                    "Snipe a recently deleted message",
                    bot.me.id
                )
            );

            // EDIT SNIPE
            bot.global_command_create(
                dpp::slashcommand(
                    "EditSnipe", 
                    "Snipe a recently edited message",
                    bot.me.id
                )
            );

            // IMAGE SNIPE
            bot.global_command_create(
                dpp::slashcommand(
                    "ImgSnipe", 
                    "Snipe a recently deleted image",
                    bot.me.id
                )
            );
        }
    });

    /*
    * Sort by Discord Unique ID
    */
    
    bot.on_message_create([&bot] (const dpp::message_create_t& event) {
        bot.log(dpp::loglevel::ll_info, event.msg.content);
        bot.log(dpp::loglevel::ll_info, "\n");
        std::cout<<event.msg.id;
    });

    bot.on_message_delete([&bot](const dpp::message_delete_t& event) {
        // log dereferenced pointer
        bot.log(dpp::loglevel::ll_info, event.deleted->content);
        bot.log(dpp::loglevel::ll_info, "\n");
        std::cout<<event.deleted->id;
    });
 
    bot.start(dpp::st_wait);
}