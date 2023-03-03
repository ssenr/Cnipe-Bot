#pragma once
#ifndef COMMANDS_H
#define COMMANDS_H

#include <dpp/dpp.h>
#include <string>

dpp::slashcommand g_comm_test();
dpp::slashcommand g_comm_cache_size();
dpp::slashcommand g_comm_cache_count();

std::string dc_comm_test(const std::string& param, dpp::cache<dpp::message>& message_cache);
std::string dc_comm_cache_size(dpp::cache<dpp::message>& message_cache);
std::string dc_comm_cache_count(dpp::cache<dpp::message>& message_cache);

#endif 
