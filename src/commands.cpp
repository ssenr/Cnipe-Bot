#include <commands.h>
#include <config.h>
#include <dpp/dpp.h>
#include <iostream>
#include <string>
#include <vector>
#include <utils.h>

uint64_t bot_id = BOT_ID;

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

dpp::slashcommand g_comm_queue_size()
{
    dpp::slashcommand queue_size("QueueSize", "Returns size of the snipe queue", bot_id);
    queue_size.add_option(
        dpp::command_option(dpp::co_boolean, "vector", "True -> Delete", true)
    );
    return queue_size;
}

dpp::slashcommand g_comm_edit_snipe()
{
    dpp::slashcommand edit_snipe("EditSnipe", "Snipes the most recently edited message", bot_id);
    return edit_snipe;
}

std::string dc_comm_test(const std::string& param, dpp::cache<dpp::message>& message_cache)
{
    dpp::message* target_ptr = message_cache.find(param);

    if (target_ptr != nullptr)
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
    size_t cache_size = sizeof_cache(message_cache);
    std::string cache_size_str = std::to_string(cache_size);

    return cache_size_str + " bytes";
}

std::string dc_comm_cache_count(dpp::cache<dpp::message> &message_cache)
{
    std::string item_count = std::to_string(items_in_cache(message_cache));
    std::string fmt_item_count = "There are currently " + item_count + " messages stored.";
    return fmt_item_count;
}

std::string dc_comm_queue_size(std::vector<uint64_t>& vec)
{
    return std::to_string(queue_size(vec));
}

std::string dc_comm_edit_snipe(std::vector<uint64_t>& update_queue,dpp::cache<dpp::message>& delete_cache, dpp::cache<dpp::message>& update_cache)
{
    if (update_queue.size() > 0)
    {
        std::string message_id = std::to_string(update_queue[0]);
        dpp::message* old_message = search_cache(delete_cache, message_id);
        dpp::message* new_message = search_cache(update_cache, message_id);

        if (old_message != nullptr && new_message != nullptr)
        {            
            return "Old Message: " + old_message->content + " New Message: " + new_message->content;
        }
        else 
        {
            return "null";
        }
    }
    else 
    {
        return "null";
    }
}