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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vboxuser/Desktop/openSi/kicad-source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vboxuser/Desktop/openSi/kicad-build

# Include any dependencies generated for this target.
include thirdparty/libcontext/CMakeFiles/libcontext.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include thirdparty/libcontext/CMakeFiles/libcontext.dir/compiler_depend.make

# Include the progress variables for this target.
include thirdparty/libcontext/CMakeFiles/libcontext.dir/progress.make

# Include the compile flags for this target's objects.
include thirdparty/libcontext/CMakeFiles/libcontext.dir/flags.make

thirdparty/libcontext/CMakeFiles/libcontext.dir/libcontext.cpp.o: thirdparty/libcontext/CMakeFiles/libcontext.dir/flags.make
thirdparty/libcontext/CMakeFiles/libcontext.dir/libcontext.cpp.o: /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/libcontext/libcontext.cpp
thirdparty/libcontext/CMakeFiles/libcontext.dir/libcontext.cpp.o: thirdparty/libcontext/CMakeFiles/libcontext.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object thirdparty/libcontext/CMakeFiles/libcontext.dir/libcontext.cpp.o"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/libcontext && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -fno-lto -MD -MT thirdparty/libcontext/CMakeFiles/libcontext.dir/libcontext.cpp.o -MF CMakeFiles/libcontext.dir/libcontext.cpp.o.d -o CMakeFiles/libcontext.dir/libcontext.cpp.o -c /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/libcontext/libcontext.cpp

thirdparty/libcontext/CMakeFiles/libcontext.dir/libcontext.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcontext.dir/libcontext.cpp.i"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/libcontext && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -fno-lto -E /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/libcontext/libcontext.cpp > CMakeFiles/libcontext.dir/libcontext.cpp.i

thirdparty/libcontext/CMakeFiles/libcontext.dir/libcontext.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcontext.dir/libcontext.cpp.s"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/libcontext && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -fno-lto -S /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/libcontext/libcontext.cpp -o CMakeFiles/libcontext.dir/libcontext.cpp.s

# Object files for target libcontext
libcontext_OBJECTS = \
"CMakeFiles/libcontext.dir/libcontext.cpp.o"

# External object files for target libcontext
libcontext_EXTERNAL_OBJECTS =

thirdparty/libcontext/liblibcontext.a: thirdparty/libcontext/CMakeFiles/libcontext.dir/libcontext.cpp.o
thirdparty/libcontext/liblibcontext.a: thirdparty/libcontext/CMakeFiles/libcontext.dir/build.make
thirdparty/libcontext/liblibcontext.a: thirdparty/libcontext/CMakeFiles/libcontext.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblibcontext.a"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/libcontext && $(CMAKE_COMMAND) -P CMakeFiles/libcontext.dir/cmake_clean_target.cmake
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/libcontext && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libcontext.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
thirdparty/libcontext/CMakeFiles/libcontext.dir/build: thirdparty/libcontext/liblibcontext.a
.PHONY : thirdparty/libcontext/CMakeFiles/libcontext.dir/build

thirdparty/libcontext/CMakeFiles/libcontext.dir/clean:
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/libcontext && $(CMAKE_COMMAND) -P CMakeFiles/libcontext.dir/cmake_clean.cmake
.PHONY : thirdparty/libcontext/CMakeFiles/libcontext.dir/clean

thirdparty/libcontext/CMakeFiles/libcontext.dir/depend:
	cd /home/vboxuser/Desktop/openSi/kicad-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vboxuser/Desktop/openSi/kicad-source /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/libcontext /home/vboxuser/Desktop/openSi/kicad-build /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/libcontext /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/libcontext/CMakeFiles/libcontext.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : thirdparty/libcontext/CMakeFiles/libcontext.dir/depend

