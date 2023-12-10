#include <cstdint>
#include <dpp/dpp.h>
#include <exception>
#include <optional>
#include <stdexcept>
#include "include/Config.h"
#include "include/sqlite3pp/sqlite3pp.h"

/**
 *  TRACKING:
 *  Droplet Specs
 *  1 GB Memory - 1 Intel VCPU - 25 GB SSD 
 *  Note: DPP won't have as big of a memory footprint
 **/

namespace snipe
{
  inline std::optional<sqlite3pp::database> db_connect() 
  {
    try 
    {
      sqlite3pp::database db(SNIPE_DB_NAME);
      return db;
    }
    catch (const std::exception&) { return std::nullopt;};
  }

  /* Run Once */
  void init()
  {

  }
}

int main()
{
  /** INIT **/
  // Cluster
  const std::string BOT_TOKEN = BOT_TOKEN_H;
  dpp::cluster bot(BOT_TOKEN, BOT_INTENTS);

  // Database
  std::optional<sqlite3pp::database> snipe_db_connect = snipe::db_connect();
  if (!snipe_db_connect.has_value())
  {
    throw std::runtime_error("Database has not connected!");
  }
  sqlite3pp::database& snipe_db = snipe_db_connect.value(); 
  /** INIT END **/

  const dpp::snowflake BOT_ID = bot.me.id; 

  dpp::slashcommand ping("ping", "Ping pong!", BOT_ID);

  std::vector<dpp::slashcommand> slashcommand_list = {ping};

  /**
   *  Cache
   **/
  dpp::cache<dpp::message> message_cache;

  const auto store = [&bot, &message_cache](const dpp::message_create_t& event)
  {
    dpp::message* event_message = new dpp::message();
    *event_message = event.msg;

    /**
     *  Check Channel ID 
     *  Only one check for DEBUG purposes atm.
     *  UPDATE TO CHANNEL ID VECTOR LATER (This way you can specify what channels to avoid)
     **/
    uint64_t channel_id = event_message->channel_id;
    if (channel_id == GENERAL_CHANNEL_ID)
    {
      message_cache.store(event_message);
    }
    else 
    {
      bot.log(dpp::loglevel::ll_critical, "Please type message in #general channel!");
    }
  };
  bot.on_message_create(store);

  // END
  bot.on_log(dpp::utility::cout_logger());

  bot.on_slashcommand([] (const dpp::slashcommand_t& event) 
      {
      if (event.command.get_command_name() == "ping") 
      {
      event.reply("Pong!");
      }
      });

  /** 
   * INIT Function
   * Handles:
   * Database Status (Realistically if it reaches this point without a crash, and status is fine, can probably scan FS for .db file though)
   * Slash Command Registration
   **/
  const auto init = [&](const dpp::ready_t& event) 
  {
    // Register Commands
    if (dpp::run_once<struct register_bot_commands>()) 
    {
      bot.global_bulk_command_create(slashcommand_list);
    }
  };

  bot.on_ready(init);

  bot.start(dpp::st_wait);
}
