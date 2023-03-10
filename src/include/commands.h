#pragma once
#ifndef COMMANDS_H
#define COMMANDS_H

#include <dpp/dpp.h>
#include <string>
#include <vector>

dpp::slashcommand g_comm_test();
dpp::slashcommand g_comm_cache_size();
dpp::slashcommand g_comm_cache_count();
dpp::slashcommand g_comm_queue_size();
dpp::slashcommand g_comm_edit_snipe();

std::string dc_comm_test(const std::string& param, dpp::cache<dpp::message>& message_cache);
std::string dc_comm_cache_size(dpp::cache<dpp::message>& message_cache);
std::string dc_comm_cache_count(dpp::cache<dpp::message>& message_cache);
std::string dc_comm_queue_size(std::vector<uint64_t>& vec);
std::string dc_comm_edit_snipe(std::vector<uint64_t>& delete_queue, dpp::cache<dpp::message>& delete_cache, dpp::cache<dpp::message>& update_cache);

#endif 
