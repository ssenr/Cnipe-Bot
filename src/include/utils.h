#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <dpp/dpp.h>
#include <string>

dpp::message*  search_cache(dpp::cache<dpp::message>& message_cache, std::string message_id);

#endif
