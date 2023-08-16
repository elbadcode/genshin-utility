#include <common.hpp>

void sdk::initialize_genshin_impact() {
  auto unity_player = (unsigned long long)(GetModuleHandleA("UnityPlayer.dll"));

  sdk::set_field_of_view = unity_player + 0xcdea80;

  sdk::set_target_frame_rate = unity_player + 0xa88f70;
  sdk::quit = unity_player + 0xcd6750;

  sdk::set_vsync_count = unity_player + 0x135ec30;

  sdk::set_fog = unity_player + 0x1363240;

  sdk::game = sdk::game_type::genshin_impact;
}

void sdk::initialize_star_rail() {
  auto game_assembly = (unsigned long long)(GetModuleHandleA("GameAssembly.dll"));
  auto unity_player = (unsigned long long)(GetModuleHandleA("UnityPlayer.dll"));

  sdk::set_field_of_view = unity_player + 0xd28c20;

  sdk::set_target_frame_rate = unity_player + 0xd18100;
  sdk::quit = unity_player + 0xd17b20;

  sdk::set_vsync_count = unity_player + 0xd75c50;

  sdk::set_fog = unity_player + 0xd80af0;

  sdk::ult_fov_ret = game_assembly + 0x2c43a21;

  sdk::game = sdk::game_type::star_rail;
}

bool sdk::is_genshin_impact() {
  return sdk::game == sdk::game_type::genshin_impact;
}