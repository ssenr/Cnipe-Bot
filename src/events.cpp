#include <events.h>
#include <dpp/dpp.h>

void e_message_create(dpp::cluster& bot, dpp::cache<dpp::message>& message_cache, const dpp::message_create_t& event)
{
    dpp::message* message_ptr = new dpp::message();
    *message_ptr = event.msg;

    message_cache.store(message_ptr);
}