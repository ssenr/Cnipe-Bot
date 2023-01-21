#include "main.h"

int main() 
{
    // Retrieve Token from Header
    const std::string bot_token = BOT_TOKEN;
    
    // Create Bot
    uint64_t intents = dpp::i_default_intents | 
                       dpp::i_message_content |
                       dpp::i_guild_members;

    // Initialize Cluster
    dpp::cluster bot(bot_token, intents);

    // Initialize Cache
    dpp::cache<dpp::message> message_cache;

    bot.on_log(dpp::utility::cout_logger());
    
    bot.on_ready([&bot](const dpp::ready_t& event) 
    {
        if (dpp::run_once<struct register_bot_commands>()) {
            /* Command Arrays */
            std::vector<dpp::slashcommand> no_commands;
            std::vector<dpp::slashcommand> command_array;
            
            // TEST COMMAND
            // dpp::slashcommand test_cmd("test", "Placeholder command to test functionality", bot.me.id);
            // test_cmd.add_option(
            //     dpp::command_option(dpp::co_integer, "Message ID", true)
            // );
            
            // bot.global_command_create(test_cmd);

            // PING
            // bot.global_command_create(
            //     dpp::slashcommand(
            //         "ping", 
            //         "Ping pong!", 
            //         bot.me.id
            //     )
            // );
            
            // SNIPE
            // SNIPE WITH IMAGE IF ATTACHMENT
            // INCLUDES A MESSAGE IF REPLY
            // bot.global_command_create(
            //     dpp::slashcommand(
            //         "Snipe", 
            //         "Snipe a recently deleted message",
            //         bot.me.id
            //     )
            // );

            // EDIT SNIPE
            // bot.global_command_create(
            //     dpp::slashcommand(
            //         "EditSnipe", 
            //         "Snipe a recently edited message",
            //         bot.me.id
            //     )
            // );

            // IMAGE SNIPE
            // bot.global_command_create(
            //     dpp::slashcommand(
            //         "ImgSnipe", 
            //         "Snipe a recently deleted image",
            //         bot.me.id
            //     )
            // );

            /* GET */
            // Initialize
            dpp::slashcommand get_message("Get", "Retrieves a message from Cache", bot.me.id);
            get_message.add_option(
                    dpp::command_option(dpp::co_string, "messageid", "Integer ID", true)
            );
            
            /* Add Commands to Array */
            command_array.push_back(get_message);

            /* Register Commands */
            bot.global_bulk_command_create(command_array);
        }
    });

    /*
    * Sort by Discord Unique ID
    */
    
    bot.on_message_create([&] (const dpp::message_create_t& event) 
    {
        dpp::message* message_ptr = new dpp::message();
        *message_ptr = event.msg;
        
        message_cache.store(message_ptr);

        /* Delete Pointer */
        delete message_ptr;
    });

    bot.on_slashcommand([&](const dpp::slashcommand_t& event) 
    {
         if (event.command.get_command_name() == "get") 
         {
            auto message_id = std::get<std::string>(event.get_parameter("messageid"));
            dpp::message* target_ptr = message_cache.find(message_id);

            if (target_ptr != NULL)
            {
                event.reply("This message had the following content: " + target_ptr->content);
            } 
            else
            {
                event.reply("There is no messagecached with this ID");
            }
        }
    });

    bot.on_message_delete([&bot](const dpp::message_delete_t& event) 
    {
        // log dereferenced pointer
        bot.log(dpp::loglevel::ll_info, event.deleted->content);
        bot.log(dpp::loglevel::ll_info, "\n");
        std::cout<<event.deleted->id;
    });

    bot.on_message_update([&bot] (const dpp::message_update_t& event) 
    {
        bot.log(dpp::loglevel::ll_info, event.msg.content);
    });
 
    bot.start(dpp::st_wait);
}