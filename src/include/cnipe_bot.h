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
        e_message_create(bot, message_cache);
        
        /* Command Handling */ 
        e_slashcommand_use(bot, message_cache);

        /* On Ready Event */
        e_on_ready(bot, commands_array);

        /* Start Bot */
        bot.start(dpp::st_wait);
    }
};

#endif 
