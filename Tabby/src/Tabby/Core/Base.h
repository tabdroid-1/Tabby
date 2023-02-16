// #pragma once

// #include <memory> // for std::unique_ptr and std::shared_ptr

// #if defined(__clang__)
// #define DEBUG_BREAK __builtin_debugtrap()
// #elif defined(_MSC_VER)
// #define DEBUG_BREAK __debugbreak()
// #endif

// #ifdef TB_ENABLE_ASSERTS
// #define TB_ASSERT(x, ...) { if(!x) { TB_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK; } }
// #define TB_CORE_ASSERT(x, ...) { if(!x) { TB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK; } }
// #else
// #define TB_ASSERT(x, ...)
// #define TB_CORE_ASSERT(x, ...)
// #endif

// #define BIT(x) (1 << x)

// #define TB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

// namespace Tabby {

//     template<typename T>
//     using Scope = std::unique_ptr<T>;

//     template<typename T>
//     using Ref = std::shared_ptr<T>;

// }

#pragma once

#include <memory>




#if defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	/* TARGET_OS_MAC exists on all the platforms
	 * so we must check all of them (in this order)
	 * to ensure that we're running on MAC
	 * and not some other Apple platform */
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define TB_PLATFORM_IOS
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define TB_PLATFORM_MACOS
	#else
		#error "Unknown Apple platform!"
	#endif
/* We also have to check __ANDROID__ before __linux__
 * since android is based on the linux kernel
 * it has __linux__ defined */
#elif defined(__ANDROID__)
	#define TB_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)
	#define TB_PLATFORM_LINUX
	#error "Linux is not supported!"
#else
	/* Unknown compiler/platform */
	#error "Unknown platform!"
#endif // End of platform detection


#ifdef TB_PLATFORM_MACOS
    #define TABBY_API
#else
	#error Tabby does not support this OS!
#endif // End of DLL support

#ifdef TB_DEBUG
	#define TB_ENABLE_ASSERTS
#endif

#if defined(__clang__)
#define DEBUG_BREAK __builtin_debugtrap()
#elif defined(_MSC_VER)
#define DEBUG_BREAK __debugbreak()
#endif

#ifdef TB_ENABLE_ASSERTS
	#define TB_ASSERT(x, ...) { if(!(x)) { TB_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK; } }
	#define TB_CORE_ASSERT(x, ...) { if(!(x)) { TB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK; } }
#else
	#define TB_ASSERT(x, ...)
	#define TB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define TB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Tabby {

	template<typename T>
	using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
    template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}