#pragma once
#ifndef CNIPE_BOT_H
#define CNIPE_BOT_H

#include <string>
#include <dpp/dpp.h>
#include <vector>
#include <iostream>
#include <config.h>
#include <events.h>
#include <commands.h>

class cnipe_bot
{
private:
    /* Member Variables */
    std::vector<dpp::slashcommand> commands_array;
    dpp::cluster bot;
    dpp::cache<dpp::message> message_cache;
public:
    /* Constructor */
    cnipe_bot() : bot(BOT_TOKEN, INTENTS)
    {
        commands_array.push_back(
            g_comm_test()
        );
    }

    /* Run Command for Bot */
    void run() 
    {
        /* Initialize Logger Event */
        bot.on_log(dpp::utility::cout_logger());

        /* Initialize DB */

        /* Event Handling */
        e_message_create(bot,message_cache);
        
        /* Command Handling */ 
        bot.on_slashcommand([&] (const dpp::slashcommand_t& event) {
            if (event.command.get_command_name() == "Get")
            {
                auto param = event.get_parameter("messageid");
                event.reply(
                    dc_comm_test(param, message_cache)        
                );
            }

        }); 

        /* On Ready Event */
        bot.on_ready([&](const dpp::ready_t& event)
        {
            if (dpp::run_once<struct register_bot_commands>())
            {
                bot.global_bulk_command_create(commands_array);
            }
        });

        /* Start Bot */
        bot.start(dpp::st_wait);
    }
};

#endif 
