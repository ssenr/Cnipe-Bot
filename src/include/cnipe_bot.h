#pragma once
#ifndef CNIPE_BOT_H
#define CNIPE_BOT_H

#include <string>
#include <dpp/dpp.h>
#include <vector>
#include <iostream>
#include <config.h>
#include <events.h>

class cnipe_bot
{
private:
    /* Member Variables */
    std::vector<dpp::slashcommand> commands_array;
    dpp::cluster bot;
    dpp::cache<dpp::message> message_cache;
public:
    /* Constructor */
    cnipe_bot(std::string bot_token, uint64_t intents) : bot(bot_token, intents)
    {
        /* Empty Constructor */
    }

    /* Member Function to Add Command to List */
    void add_command(std::vector<dpp::slashcommand> commands)
    {
        /* Research Usage */
        commands_array.insert(commands_array.end(), commands.begin(), commands.end());
    }

    /* Run Command for Bot */
    void run() 
    {
        /* Initialize Logger Event */
        bot.on_log(dpp::utility::cout_logger());

        /* Event Handling */
        e_message_create(bot,message_cache);
        
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