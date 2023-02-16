#include "tbpch.h"
#include "Tabby/Core/Input.h"

#ifdef TB_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsInput.h"
#elif defined(TB_PLATFORM_MACOS)
	#include "Platform/OSX/MacInput.h"
#endif

namespace Tabby {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
	#ifdef TB_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
    #elif defined(TB_PLATFORM_MACOS)
        return CreateScope<MacInput>();
	#else
		TB_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
    #endif
	}
} 