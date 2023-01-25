#pragma once
#ifndef EVENTS_H
#define EVENTS_H

#include <dpp/dpp.h>

void e_message_create(dpp::cluster& bot, dpp::cache<dpp::message>& message_cache, const dpp::message_create_t& event);

#endif 