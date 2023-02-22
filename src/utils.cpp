#include <dpp/dpp.h>
#include <utils.h>

dpp::message* search_cache(dpp::cache<dpp::message>& message_cache, std::string message_id)
{
    dpp::message* target_ptr = message_cache.find(message_id);
    return (target_ptr);
}
