#include <cstddef>
#include <cstdint>
#include <dpp/dpp.h>
#include <unordered_map>
#include <utils.h>
#include <shared_mutex>

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

uint64_t manage_cache(dpp::cache<dpp::message> &message_cache)
{
    uint64_t total = 0;
    std::unordered_map<dpp::snowflake, dpp::message*>& mc_container = message_cache.get_container();
    std::shared_lock l(message_cache.get_mutex());

    for (auto i = mc_container.begin(); i != mc_container.end(); i++)
    {
        dpp::message* mp = (dpp::message*)i->second;
        total++;
    }
    return total;
}
