#pragma once

#define TB_ENABLE_ASSERTS

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <array>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Tabby/Core/Log.h"

#ifdef TB_PLATFORM_WINDOWS
#include <Windows.h>
#endif