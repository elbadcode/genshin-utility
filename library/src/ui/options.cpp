#include <ui/options.hpp>
#include <ini_file.hpp>

#include <shlobj.h>

void ui::options::load() {
  if (!std::filesystem::is_directory(ui::options::folder)) {
    std::filesystem::remove(ui::options::folder);

    if (!std::filesystem::create_directories(ui::options::folder))
      return;
  }

  const ini_file& config = ini_file::load_cache(ui::options::path);

  const auto config_get = [&config](const std::string& section, const std::string& key, auto& values) {
      if (config.get(section, key, values))
	  return true;
      };


  try {

      
    ui::options::menu::open_on_start = config_get("Menu", "opened", ui::options::menu::opened);
    ui::options::tools::fps_counter = config_get("Menu", "open_on_start", ui::options::menu::open_on_start);
    ui::options::tools::enable_vsync = config_get("Tools", "enable_vsync", ui::options::tools::enable_vsync);
    ui::options::tools::disable_fog = config_get("Tools", "disable_fog", ui::options::tools::disable_fog);
    ui::options::tools::fps_limit = config_get("Tools", "fps_limit", ui::options::tools::fps_limit);
    ui::options::tools::camera_fov = config_get("Tools", "camera_fov", ui::options::tools::camera_fov);
  }
  catch (std::exception&) {
      ui::options::menu::open_on_start = false;
      ui::options::tools::fps_counter = false;
      ui::options::tools::enable_vsync = false;
      ui::options::tools::disable_fog = true;
      ui::options::tools::fps_limit = 360;
      ui::options::tools::camera_fov = 65;
  }
}


    
   
void ui::options::save()
{
    ini_file& config = ini_file::load_cache(ui::options::path);

    config.set("Menu", "opened", ui::options::menu::opened);
    config.set("Menu", "open_on_start", ui::options::menu::open_on_start);
    config.set("Tools", "fpsCounter", ui::options::tools::fps_counter);
    config.set("Tools", "enable_vsync", ui::options::tools::enable_vsync);
    config.set("Tools", "disable_fog", ui::options::tools::disable_fog);
    config.set("Tools", "fps_limit", ui::options::tools::fps_limit);
    config.set("Tools", "camera_fov", ui::options::tools::camera_fov);

}

std::filesystem::path ui::options::get_working_path() {
  std::filesystem::path working_path;

  if (wchar_t* path_to_documents; SUCCEEDED(SHGetKnownFolderPath(FOLDERID_Documents, 0, nullptr, &path_to_documents))) {
    working_path.assign(path_to_documents);
    working_path.append("genshin-utility");
    CoTaskMemFree(path_to_documents);
  }

  return working_path;
}