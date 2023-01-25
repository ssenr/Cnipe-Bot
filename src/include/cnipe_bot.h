#pragma once
#ifndef CNIPE_BOT_H
#define CNIPE_BOT_H

#include <string>
#include <dpp/dpp.h>
#include <vector>
#include <iostream>
#include <config.h>

class cnipe_bot
{
private:
    /* Member Variables */
    std::vector<dpp::slashcommand> commands_array;
    dpp::cluster bot;
public:
    /* Constructor */
    cnipe_bot(std::string bot_token) : bot(bot_token)
    {
        /* Empty Constructor */
    }

    /* Member Function to Add Command to List */
    void add_command(dpp::slashcommand command)
    {
        commands_array.push_back(command);
    }

    /* Run Command for Bot */
    void run() 
    {
        /* Initialize Logger Event */
        bot.on_log(dpp::utility::cout_logger());

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