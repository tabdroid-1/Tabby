cmake_minimum_required(VERSION 3.20)
project(Tabby)
set(CMAKE_CXX_STANDARD 17)

###################################################################
# Local variables
###################################################################
set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(PROJECT_VENDOR_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor")


# For GTK
# The `pkg_check_modules` function is created with this call
find_package(PkgConfig REQUIRED)

# These calls create special `PkgConfig::<MODULE>` variables
pkg_check_modules(GTKMM_PKG IMPORTED_TARGET gtkmm-3.0)


# Vendor/Libraries
set(IMGUI "${PROJECT_VENDOR_DIR}/imgui")
set(GLAD "${PROJECT_VENDOR_DIR}/Glad")
set(GLFW "${PROJECT_VENDOR_DIR}/GLFW")
set(GLM "${PROJECT_VENDOR_DIR}/glm")
set(SPDLOG "${PROJECT_VENDOR_DIR}/spdlog")
set(STB "${PROJECT_VENDOR_DIR}/stb_image")
set(ENTT "${PROJECT_VENDOR_DIR}/entt")
set(YAML "${PROJECT_VENDOR_DIR}/yaml-cpp")

###################################################################
# Project Sources and add library
###################################################################
file(GLOB_RECURSE PROJECT_SOURCES
        "${PROJECT_SOURCE_DIR}/*.h"
        "${PROJECT_SOURCE_DIR}/*.cpp"
        )

# Additional project sources (vendors, etc.)
list(APPEND PROJECT_SOURCES
        # Vendor sources --------------------------
        "${IMGUI}/imconfig.h"
        "${IMGUI}/imgui.cpp"
        "${IMGUI}/imgui_draw.cpp"
        "${IMGUI}/imgui_widgets.cpp"
        "${IMGUI}/imgui_tables.cpp"
        "${IMGUI}/imgui_demo.cpp"

        "${SPDLOG}/include/spdlog/spdlog.h" # For logging

        "${ENTT}/include/entt.hpp" # entity component system

        "${STB}/stb_image.h"
        "${STB}/stb_image.cpp"
        # -----------------------------------------
        )

# Add library
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
        "${PROJECT_SOURCE_DIR}"
        "${PROJECT_VENDOR_DIR}"
        )

###################################################################
# Libraries
###################################################################
add_subdirectory(${GLFW})
add_subdirectory(${SPDLOG})
add_subdirectory(${GLAD})
add_subdirectory(${GLM})
add_subdirectory(${PROJECT_VENDOR_DIR}) # ImGui
add_subdirectory(${YAML})

target_link_libraries(${PROJECT_NAME} PUBLIC
        "spdlog"
        "Glad"
        "glfw"
        "glm"
        "imgui"
        "yaml-cpp"
        PkgConfig::GTKMM_PKG
        )
# target_link_libraries()

###################################################################
# Compiler options
###################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_NONE=1)

if (APPLE)
#    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
    target_compile_definitions(${PROJECT_NAME} PUBLIC TB_DEBUG=1 TB_PLATFORM_MACOS=1)
elseif (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC TB_DEBUG=1 TB_PLATFORM_WINDOWS=1 TB_BUILD_DLL=1 BUILD_SHARED_LIBS=1)
endif ()

###################################################################
# Precompiled header
###################################################################
target_precompile_headers(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/tbpch.h")