#include <events.h>
#include <dpp/dpp.h>

/* Master Function for Event Handling */
void e_message_create(dpp::cluster& bot, dpp::cache<dpp::message>& message_cache)
{
    bot.on_message_create([&] (const dpp::message_create_t& event)
    {
        dpp::message* message_ptr = new dpp::message();
        *message_ptr = event.msg;

        message_cache.store(message_ptr);
    });
}