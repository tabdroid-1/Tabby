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
include Tabby/vendor/Glad/CMakeFiles/Glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Tabby/vendor/Glad/CMakeFiles/Glad.dir/compiler_depend.make

# Include the progress variables for this target.
include Tabby/vendor/Glad/CMakeFiles/Glad.dir/progress.make

# Include the compile flags for this target's objects.
include Tabby/vendor/Glad/CMakeFiles/Glad.dir/flags.make

Tabby/vendor/Glad/CMakeFiles/Glad.dir/src/glad.c.o: Tabby/vendor/Glad/CMakeFiles/Glad.dir/flags.make
Tabby/vendor/Glad/CMakeFiles/Glad.dir/src/glad.c.o: /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/Glad/src/glad.c
Tabby/vendor/Glad/CMakeFiles/Glad.dir/src/glad.c.o: Tabby/vendor/Glad/CMakeFiles/Glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tabby/Desktop/projects/C++/Tabby/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Tabby/vendor/Glad/CMakeFiles/Glad.dir/src/glad.c.o"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor/Glad && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Tabby/vendor/Glad/CMakeFiles/Glad.dir/src/glad.c.o -MF CMakeFiles/Glad.dir/src/glad.c.o.d -o CMakeFiles/Glad.dir/src/glad.c.o -c /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/Glad/src/glad.c

Tabby/vendor/Glad/CMakeFiles/Glad.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Glad.dir/src/glad.c.i"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor/Glad && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/Glad/src/glad.c > CMakeFiles/Glad.dir/src/glad.c.i

Tabby/vendor/Glad/CMakeFiles/Glad.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Glad.dir/src/glad.c.s"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor/Glad && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/Glad/src/glad.c -o CMakeFiles/Glad.dir/src/glad.c.s

# Object files for target Glad
Glad_OBJECTS = \
"CMakeFiles/Glad.dir/src/glad.c.o"

# External object files for target Glad
Glad_EXTERNAL_OBJECTS =

Tabby/vendor/Glad/libGlad.dylib: Tabby/vendor/Glad/CMakeFiles/Glad.dir/src/glad.c.o
Tabby/vendor/Glad/libGlad.dylib: Tabby/vendor/Glad/CMakeFiles/Glad.dir/build.make
Tabby/vendor/Glad/libGlad.dylib: Tabby/vendor/Glad/CMakeFiles/Glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tabby/Desktop/projects/C++/Tabby/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libGlad.dylib"
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor/Glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tabby/vendor/Glad/CMakeFiles/Glad.dir/build: Tabby/vendor/Glad/libGlad.dylib
.PHONY : Tabby/vendor/Glad/CMakeFiles/Glad.dir/build

Tabby/vendor/Glad/CMakeFiles/Glad.dir/clean:
	cd /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor/Glad && $(CMAKE_COMMAND) -P CMakeFiles/Glad.dir/cmake_clean.cmake
.PHONY : Tabby/vendor/Glad/CMakeFiles/Glad.dir/clean

Tabby/vendor/Glad/CMakeFiles/Glad.dir/depend:
	cd /Users/tabby/Desktop/projects/C++/Tabby/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tabby/Desktop/projects/C++/Tabby /Users/tabby/Desktop/projects/C++/Tabby/Tabby/vendor/Glad /Users/tabby/Desktop/projects/C++/Tabby/build /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor/Glad /Users/tabby/Desktop/projects/C++/Tabby/build/Tabby/vendor/Glad/CMakeFiles/Glad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tabby/vendor/Glad/CMakeFiles/Glad.dir/depend

