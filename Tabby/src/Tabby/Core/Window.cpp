#include "tbpch.h"
#include "Tabby/Core/Window.h"

#ifdef TB_PLATFORM_MACOS
	#include "Platform/OSX/MacWindow.h"
#elif defined(TB_PLATFORM_WINDOWS)
    #include "Platform/Windows/WindowsWindow.h"
#endif

namespace Tabby
{

	Scope<Window> Window::Create(const WindowProps& props)
	{

    #ifdef TB_PLATFORM_MACOS
        return CreateScope<MacWindow>(props);
	#elif defined(TB_PLATFORM_WINDOWS)
		return CreateScope<WindowsWindow>(props);
	#else
		TB_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}