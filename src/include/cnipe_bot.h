#pragma once
#ifndef CNIPE_BOT_H
#define CNIPE_BOT_H

#include <cstdint>
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
    std::vector<uint64_t> delete_queue;
    dpp::cluster bot;
    dpp::cache<dpp::message> message_delete_cache;
    dpp::cache<dpp::message> message_edit_cache;
public:
    cnipe_bot() : bot(BOT_TOKEN, INTENTS)
    {
        commands_array.insert(commands_array.end(), {
           g_comm_cache_size(),
           g_comm_cache_count(),
           g_comm_test()
        });
    }

    void run() 
    {
        bot.on_log(dpp::utility::cout_logger());

        e_message_create(bot, message_delete_cache);
        e_message_delete(bot, message_delete_cache);
        
        e_slashcommand_use(bot, message_delete_cache);

        e_on_ready(bot, commands_array);

        bot.start(dpp::st_wait);
    }
};

#endif 
