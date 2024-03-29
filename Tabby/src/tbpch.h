#pragma once

#include "Tabby/Core/PlatformDetection.h"

#ifdef TB_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#elif defined(TB_PLATFORM_MACOS)
    #ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif


#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Tabby/Core/Base.h"
#include "Tabby/Core/Log.h"

#include "Tabby/Debug/Instrumentor.h"

#ifdef TB_PLATFORM_WINDOWS
#include <Windows.h>
#endif