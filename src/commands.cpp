#include "include/commands.h"
#include <commands.h>
#include <config.h>
#include <dpp/dpp.h>
#include <iostream>
#include <string>
#include <utils.h>

uint64_t bot_id = BOT_ID;

/* Create Commands */
dpp::slashcommand g_comm_test() 
{
    dpp::slashcommand get_message("Get", "Retrieves a message from Cache", bot_id);
    get_message.add_option(
        dpp::command_option(dpp::co_string, "messageid", "Integer ID", true)
    );
    return get_message;
}

dpp::slashcommand g_comm_cache_size()
{
    dpp::slashcommand get_cache_size("CacheSize", "Returns the size of the cache in memory", bot_id);
    return get_cache_size;
}

dpp::slashcommand g_comm_cache_count()
{
    dpp::slashcommand cache_count("CacheCount", "Returns the number of items in cache", bot_id);
    return cache_count;
}

/* Define Commands */
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

std::string dc_comm_cache_size(dpp::cache<dpp::message>& message_cache)
{
    /* Log Size of Cache in Memory */
    size_t cache_size = sizeof_cache(message_cache);
    std::string cache_size_str = std::to_string(cache_size);

    return cache_size_str + " bytes";
}

std::string dc_comm_cache_count(dpp::cache<dpp::message> &message_cache)
{
    /* Log Number of Items in Cache */
    std::string item_count = std::to_string(items_in_cache(message_cache));
    std::string fmt_item_count = "There are currently " + item_count + " messages stored.";
    return fmt_item_count;
}
