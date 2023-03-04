#pragma once
#ifndef EVENTS_H
#define EVENTS_H

#include <dpp/dpp.h>
#include <vector>

void e_message_create(dpp::cluster& bot, dpp::cache<dpp::message>& message_cache);
void e_message_delete(dpp::cluster& bot, dpp::cache<dpp::message>& message_cache);
void e_message_update(dpp::cluster& bot, dpp::cache<dpp::message>& message_update_cache, std::vector<uint64_t>& update_queue);
void e_slashcommand_use(dpp::cluster& bot, dpp::cache<dpp::message>& delete_cache, dpp::cache<dpp::message>& update_cache, std::vector<uint64_t>& delete_queue, std::vector<uint64_t>& update_queue);
void e_on_ready(dpp::cluster& bot, const std::vector<dpp::slashcommand>& command_array);

#endif 
