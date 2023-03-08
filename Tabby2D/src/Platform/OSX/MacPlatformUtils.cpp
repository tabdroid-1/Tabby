#include "tbpch.h"
#include "Tabby/Utils/PlatformUtils.h"
#include "Tabby/Core/Application.h"

#include <GLFW/glfw3.h>

namespace Tabby {

  std::optional<std::string> FileDialogs::OpenFile(const char* filter, const char* filePath)
  { 
    return filePath;
  }

  std::optional<std::string> FileDialogs::SaveFile(const char* filter, const char* filePath)
  { 
    return filePath;
  }


}
