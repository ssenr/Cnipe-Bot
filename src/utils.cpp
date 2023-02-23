#include <cstddef>
#include <config.h>
#include <cstdint>
#include <cstdio>
#include <dpp/dpp.h>
#include <string>
#include <unordered_map>
#include <utils.h>
#include <shared_mutex>
#include <vector>
#include <iostream>
#include <algorithm>

dpp::message* search_cache(dpp::cache<dpp::message>& message_cache, std::string message_id)
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

/* Comparing Casted ID is more accurate than Sent Timestamp */
/* Off by One Errors */
/* ID Increments whereas it is possible that two messages could be sent at the same time */
/* Optimization (probably) removes all off by one errors due to incrementation */
bool compare_ptr(dpp::message* a, dpp::message* b) 
{
    return ( (uint64_t) a->id < (uint64_t) b->id );
}

void manage_cache(dpp::cache<dpp::message> &message_cache)
{
    /* Vars */
    std::vector<dpp::message*> arr_rmv;
    uint64_t total = 0;

    /* Scope for Iterating Through Cache */
    {
        std::unordered_map<dpp::snowflake, dpp::message*>& mc_container = message_cache.get_container();
        std::shared_lock l(message_cache.get_mutex());

        for (auto i = mc_container.begin(); i != mc_container.end(); i++)
        {
            dpp::message* mp = (dpp::message*)i->second;
            total++;
            arr_rmv.insert(arr_rmv.begin(), mp);
        }
    }

    /* Sort List by ID */
    std::sort(arr_rmv.begin(), arr_rmv.end(), compare_ptr);
    
    /* Conditions for Message Removal */
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
