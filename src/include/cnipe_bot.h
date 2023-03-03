/**
 *  The Cnipe_Bot Header File
 *  This header controls all the initialization of the various utilities the bot needs to function
 *  ex. Command handling, Cache Management, Log Management etc.
 *  No explicit logic is used here, however the class, especially the .run() method is how the bot is used.
 */

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
#include <database.h>

class cnipe_bot
{
private:
    std::vector<dpp::slashcommand> commands_array;
    dpp::cluster bot;
    dpp::cache<dpp::message> message_cache;
public:
    /* Constructor */
    cnipe_bot() : bot(BOT_TOKEN, INTENTS)
    {
        commands_array.insert(commands_array.end(), {
           g_comm_cache_size(),
           g_comm_cache_count(),
           g_comm_test()
        });
    }

    /* Run Command for Bot */
    void run() 
    {
        /**
         * @param standard output for dpp cluster
         */
        bot.on_log(dpp::utility::cout_logger());

        /* Initialize DB */
        db_connect(bot);

        /* Event Handling */
        e_message_create(bot, message_cache);
        e_message_delete(bot, message_cache);
        
        /* Command Handling */ 
        e_slashcommand_use(bot, message_cache);

        /* On Ready Event */
        e_on_ready(bot, commands_array);

        /* Start Bot */
        bot.start(dpp::st_wait);
    }
};

#endif 
