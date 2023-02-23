#pragma once
#ifndef COMMANDS_H
#define COMMANDS_H

#include <dpp/dpp.h>
#include <string>

/* Command Statements (Metadata) */
/* Dev Commands */
dpp::slashcommand g_comm_test();
dpp::slashcommand g_comm_cache_size();
dpp::slashcommand g_comm_cache_count();
dpp::slashcommand g_comm_cache_iterate();

/* Command Definitions */
std::string dc_comm_test(std::string param, dpp::cache<dpp::message>& message_cache);
std::string dc_comm_cache_size(dpp::cache<dpp::message>& message_cache);
std::string dc_comm_cache_count(dpp::cache<dpp::message>& message_cache);
std::string dc_comm_cache_iterate(dpp::cache<dpp::message>& message_cache);

#endif 
