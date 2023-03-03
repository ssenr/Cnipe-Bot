#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <dpp/dpp.h>
#include <string>
#include <cstddef>

dpp::message*  search_cache(dpp::cache<dpp::message>& message_cache, const std::string& message_id);
size_t sizeof_cache(dpp::cache<dpp::message>& message_cache);
uint64_t items_in_cache(dpp::cache<dpp::message>& message_cache);
void manage_cache(dpp::cache<dpp::message>& message_cache);
bool has_bot_role(const dpp::message& msg);

#endif
