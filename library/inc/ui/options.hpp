#pragma once

#include <filesystem>

namespace ui::options {
  void load();
  void save();
  std::filesystem::path get_working_path();

  inline const std::filesystem::path folder = ui::options::get_working_path();
  inline const std::filesystem::path path = ui::options::folder / "library.ini";
}


namespace ui::options::menu {
  inline bool opened = false;
  inline bool open_on_start = false;
}

namespace ui::options::tools {
  inline bool fps_counter = false;
  inline bool enable_vsync = false;
  inline bool disable_fog = true;
  inline int fps_limit = 360;
  inline int camera_fov = 64;
}