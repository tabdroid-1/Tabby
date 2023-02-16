#pragma once

#include "Tabby/Core/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Tabby {

    class  Log {
    public:
        static void Init();

        static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static Ref<spdlog::logger> s_CoreLogger;
        static Ref<spdlog::logger> s_ClientLogger;

    };
} // End Tabby namespace

// Core log macros
#define TB_CORE_TRACE(...)    ::Tabby::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TB_CORE_INFO(...)     ::Tabby::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TB_CORE_WARN(...)     ::Tabby::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TB_CORE_ERROR(...)    ::Tabby::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TB_CORE_FATAL(...)    ::Tabby::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define TB_TRACE(...)         ::Tabby::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TB_INFO(...)          ::Tabby::Log::GetClientLogger()->info(__VA_ARGS__)
#define TB_WARN(...)          ::Tabby::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TB_ERROR(...)         ::Tabby::Log::GetClientLogger()->error(__VA_ARGS__)
#define TB_FATAL(...)         ::Tabby::Log::GetClientLogger()->fatal(__VA_ARGS__)