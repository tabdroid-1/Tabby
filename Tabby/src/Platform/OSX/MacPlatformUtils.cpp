#include "tbpch.h"
#include "Tabby/Utils/PlatformUtils.h"
#include "Tabby/Core/Application.h"
#include "Platform/OSX/MacDialogWindow.h"

#include <GLFW/glfw3.h>

namespace Tabby {

  std::optional<std::string> FileDialogs::OpenFile(const char* filter)
  { 
    std::string res;
    auto app = Gtk::Application::create("Tabby File Selector");
    MacDialogWindow window;
    window.SubmitTabbyFilter(filter);
    app->run(window);
    res = window.GetFileName();

    if (!res.empty())
      return res;

    return std::nullopt;
  }

  std::optional<std::string> FileDialogs::SaveFile(const char* filter)
  {
    std::string res;
    auto app = Gtk::Application::create("Tabby File Selector");
    MacDialogWindow window;
    window.SubmitTabbyFilter(filter);
    app->run(window);
    res = window.GetFileName();

    if (!res.empty())
      return res;
    
    return std::nullopt;
  }

}
