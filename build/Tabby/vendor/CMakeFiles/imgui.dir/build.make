# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tabby/Desktop/projects/C++/Tabby

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tabby/Desktop/projects/C++/Tabby/build

# Include any dependencies generated for this target.
include Tabby/vendor/CMakeFiles/imgui.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Tabby/vendor/CMakeFiles/imgui.dir/compiler_depend.make

# Include the progress variables for this target.
include Tabby/vendor/CMakeFiles/imgui.dir/progress.make

# Include the compile flags for this target's objects.
include Tabby/vendor/CMakeFiles/imgui.dir/flags.make

Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o: Tabby/vendor/CMakeFiles/imgui.dir/flags.make
Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o: /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/imgui_draw.cpp
Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o: Tabby/vendor/CMakeFiles/imgui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tabby/Desktop/projects/C++/Tabby/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o -MF CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o.d -o CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o -c /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/imgui_draw.cpp

Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.i"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/imgui_draw.cpp > CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.i

Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.s"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/imgui_draw.cpp -o CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.s

Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui.cpp.o: Tabby/vendor/CMakeFiles/imgui.dir/flags.make
Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui.cpp.o: /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/imgui.cpp
Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui.cpp.o: Tabby/vendor/CMakeFiles/imgui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tabby/Desktop/projects/C++/Tabby/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui.cpp.o"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui.cpp.o -MF CMakeFiles/imgui.dir/imgui/imgui.cpp.o.d -o CMakeFiles/imgui.dir/imgui/imgui.cpp.o -c /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/imgui.cpp

Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui/imgui.cpp.i"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/imgui.cpp > CMakeFiles/imgui.dir/imgui/imgui.cpp.i

Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui/imgui.cpp.s"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/imgui.cpp -o CMakeFiles/imgui.dir/imgui/imgui.cpp.s

Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o: Tabby/vendor/CMakeFiles/imgui.dir/flags.make
Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o: /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/imgui_demo.cpp
Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o: Tabby/vendor/CMakeFiles/imgui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tabby/Desktop/projects/C++/Tabby/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o -MF CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o.d -o CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o -c /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/imgui_demo.cpp

Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.i"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/imgui_demo.cpp > CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.i

Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.s"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/imgui_demo.cpp -o CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.s

Tabby/vendor/CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.o: Tabby/vendor/CMakeFiles/imgui.dir/flags.make
Tabby/vendor/CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.o: /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/backends/imgui_impl_glfw.cpp
Tabby/vendor/CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.o: Tabby/vendor/CMakeFiles/imgui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tabby/Desktop/projects/C++/Tabby/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Tabby/vendor/CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.o"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Tabby/vendor/CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.o -MF CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.o.d -o CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.o -c /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/backends/imgui_impl_glfw.cpp

Tabby/vendor/CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.i"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/backends/imgui_impl_glfw.cpp > CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.i

Tabby/vendor/CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.s"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/imgui/backends/imgui_impl_glfw.cpp -o CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.s

# Object files for target imgui
imgui_OBJECTS = \
"CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o" \
"CMakeFiles/imgui.dir/imgui/imgui.cpp.o" \
"CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o" \
"CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.o"

# External object files for target imgui
imgui_EXTERNAL_OBJECTS =

Tabby/vendor/libimgui.a: Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_draw.cpp.o
Tabby/vendor/libimgui.a: Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui.cpp.o
Tabby/vendor/libimgui.a: Tabby/vendor/CMakeFiles/imgui.dir/imgui/imgui_demo.cpp.o
Tabby/vendor/libimgui.a: Tabby/vendor/CMakeFiles/imgui.dir/imgui/backends/imgui_impl_glfw.cpp.o
Tabby/vendor/libimgui.a: Tabby/vendor/CMakeFiles/imgui.dir/build.make
Tabby/vendor/libimgui.a: Tabby/vendor/CMakeFiles/imgui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tabby/Desktop/projects/C++/Tabby/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libimgui.a"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && $(CMAKE_COMMAND) -P CMakeFiles/imgui.dir/cmake_clean_target.cmake
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imgui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tabby/vendor/CMakeFiles/imgui.dir/build: Tabby/vendor/libimgui.a
.PHONY : Tabby/vendor/CMakeFiles/imgui.dir/build

Tabby/vendor/CMakeFiles/imgui.dir/clean:
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor && $(CMAKE_COMMAND) -P CMakeFiles/imgui.dir/cmake_clean.cmake
.PHONY : Tabby/vendor/CMakeFiles/imgui.dir/clean

Tabby/vendor/CMakeFiles/imgui.dir/depend:
	cd /Users/tabby/Desktop/projects/C++/Tabby/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tabby/Desktop/projects/C++/Tabby /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor /Users/tabby/Desktop/projects/C++/Tabby/build /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor/CMakeFiles/imgui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tabby/vendor/CMakeFiles/imgui.dir/depend

