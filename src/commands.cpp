#include <commands.h>
#include <config.h>
#include <dpp/dpp.h>
#include <iostream>

uint64_t bot_id = BOT_ID;

dpp::slashcommand g_comm_test() 
{
    dpp::slashcommand get_message("Get", "Retrieves a message from Cache", bot_id);
    get_message.add_option(
        dpp::command_option(dpp::co_string, "messageid", "Integer ID", true)
    );

    return get_message;
}

dpp::slashcommand g_comm_test2() 
{
    dpp::slashcommand test("test", "does nothing", bot_id);
    return test;
}