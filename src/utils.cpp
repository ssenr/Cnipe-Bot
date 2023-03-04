#include <cstddef>
#include <config.h>
#include <cstdint>
#include <dpp/dpp.h>
#include <string>
#include <unordered_map>
#include <utils.h>
#include <vector>
#include <algorithm>

dpp::message* search_cache(dpp::cache<dpp::message>& message_cache, const std::string& message_id)
{
    dpp::message* target_ptr = message_cache.find(message_id);
    return (target_ptr);
}

size_t sizeof_cache(dpp::cache<dpp::message>& message_cache)
{
    return message_cache.bytes();
}

uint64_t items_in_cache(dpp::cache<dpp::message> &message_cache)
{
    return message_cache.count();
}

bool has_bot_role(const dpp::message& msg)
{
    dpp::guild_member member = msg.member;
    std::vector<dpp::snowflake> role_vector = member.roles;

    for (dpp::snowflake i : role_vector) 
    {
        if ( (uint64_t) i == (uint64_t) BOT_ROLE)
        {
            return true;
        }
    }
    return false;
}

bool compare_ptr(dpp::message* a, dpp::message* b) 
{
    return ( (uint64_t) a->id < (uint64_t) b->id );
}

void manage_cache(dpp::cache<dpp::message> &message_cache)
{
    std::vector<dpp::message*> arr_rmv;

    {
        std::unordered_map<dpp::snowflake, dpp::message*>& mc_container = message_cache.get_container();
        std::shared_lock l(message_cache.get_mutex());

        for (auto & i : mc_container)
        {
            auto* mp = (dpp::message*)i.second;
            arr_rmv.insert(arr_rmv.begin(), mp);
        }
    }

    std::sort(arr_rmv.begin(), arr_rmv.end(), compare_ptr);
    
    size_t max_items = 5;
    int remove_amount = 2;

    if (arr_rmv.size() > max_items)
    {
        for (dpp::message* msg_ptr : arr_rmv)
        {
            message_cache.remove(msg_ptr);
        }
    }
}

int queue_size(std::vector<uint64_t>& vec)
{
    return vec.size();
}
