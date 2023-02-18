#include <commands.h>
#include <config.h>
#include <dpp/dpp.h>
#include <iostream>
#include <string>

uint64_t bot_id = BOT_ID;

dpp::slashcommand g_comm_test() 
{
    dpp::slashcommand get_message("Get", "Retrieves a message from Cache", bot_id);
    get_message.add_option(
        dpp::command_option(dpp::co_string, "messageid", "Integer ID", true)
    );

    return get_message;
}

std::string dc_comm_test(std::string param, dpp::cache<dpp::message>& message_cache)
{
    dpp::message* target_ptr = message_cache.find(param);

    if (target_ptr != NULL)
    {
        return ("The message had the following content: " + target_ptr->content);
    }
    else 
    {
        return ("There is no message cached with this ID");
    }
}


