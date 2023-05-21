#pragma once

namespace unity::sdk {
  enum class game_type {
    genshin_impact,
    star_rail
  };

  // UnityEngine.Camera
  inline utils::fn<void> set_field_of_view;

  // UnityEngine.Application
  inline utils::fn<void> set_target_frame_rate;
  inline utils::fn<void> quit;

  // UnityEngine.QualitySettings
  inline utils::fn<void> set_vsync_count;

  // UnityEngine.RenderSettings
  inline utils::fn<void> set_fog;

  inline unity::sdk::game_type game;

  void initialize_genshin_impact();
  void initialize_star_rail();

  bool is_genshin_impact();
}