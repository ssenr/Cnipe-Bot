#pragma once
#ifndef COMMANDS_H
#define COMMANDS_H

#include <dpp/dpp.h>
#include <string>

dpp::slashcommand g_comm_test();
std::string dc_comm_test(std::string param, dpp::cache<dpp::message>& message_cache);

#endif 
