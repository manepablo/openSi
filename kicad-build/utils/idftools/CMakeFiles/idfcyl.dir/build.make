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
include utils/idftools/CMakeFiles/idfcyl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include utils/idftools/CMakeFiles/idfcyl.dir/compiler_depend.make

# Include the progress variables for this target.
include utils/idftools/CMakeFiles/idfcyl.dir/progress.make

# Include the compile flags for this target's objects.
include utils/idftools/CMakeFiles/idfcyl.dir/flags.make

utils/idftools/CMakeFiles/idfcyl.dir/idf_cylinder.cpp.o: utils/idftools/CMakeFiles/idfcyl.dir/flags.make
utils/idftools/CMakeFiles/idfcyl.dir/idf_cylinder.cpp.o: /home/vboxuser/Desktop/openSi/kicad-source/utils/idftools/idf_cylinder.cpp
utils/idftools/CMakeFiles/idfcyl.dir/idf_cylinder.cpp.o: utils/idftools/CMakeFiles/idfcyl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object utils/idftools/CMakeFiles/idfcyl.dir/idf_cylinder.cpp.o"
	cd /home/vboxuser/Desktop/openSi/kicad-build/utils/idftools && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT utils/idftools/CMakeFiles/idfcyl.dir/idf_cylinder.cpp.o -MF CMakeFiles/idfcyl.dir/idf_cylinder.cpp.o.d -o CMakeFiles/idfcyl.dir/idf_cylinder.cpp.o -c /home/vboxuser/Desktop/openSi/kicad-source/utils/idftools/idf_cylinder.cpp

utils/idftools/CMakeFiles/idfcyl.dir/idf_cylinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/idfcyl.dir/idf_cylinder.cpp.i"
	cd /home/vboxuser/Desktop/openSi/kicad-build/utils/idftools && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vboxuser/Desktop/openSi/kicad-source/utils/idftools/idf_cylinder.cpp > CMakeFiles/idfcyl.dir/idf_cylinder.cpp.i

utils/idftools/CMakeFiles/idfcyl.dir/idf_cylinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/idfcyl.dir/idf_cylinder.cpp.s"
	cd /home/vboxuser/Desktop/openSi/kicad-build/utils/idftools && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vboxuser/Desktop/openSi/kicad-source/utils/idftools/idf_cylinder.cpp -o CMakeFiles/idfcyl.dir/idf_cylinder.cpp.s

# Object files for target idfcyl
idfcyl_OBJECTS = \
"CMakeFiles/idfcyl.dir/idf_cylinder.cpp.o"

# External object files for target idfcyl
idfcyl_EXTERNAL_OBJECTS =

utils/idftools/idfcyl: utils/idftools/CMakeFiles/idfcyl.dir/idf_cylinder.cpp.o
utils/idftools/idfcyl: utils/idftools/CMakeFiles/idfcyl.dir/build.make
utils/idftools/idfcyl: utils/idftools/CMakeFiles/idfcyl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable idfcyl"
	cd /home/vboxuser/Desktop/openSi/kicad-build/utils/idftools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/idfcyl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
utils/idftools/CMakeFiles/idfcyl.dir/build: utils/idftools/idfcyl
.PHONY : utils/idftools/CMakeFiles/idfcyl.dir/build

utils/idftools/CMakeFiles/idfcyl.dir/clean:
	cd /home/vboxuser/Desktop/openSi/kicad-build/utils/idftools && $(CMAKE_COMMAND) -P CMakeFiles/idfcyl.dir/cmake_clean.cmake
.PHONY : utils/idftools/CMakeFiles/idfcyl.dir/clean

utils/idftools/CMakeFiles/idfcyl.dir/depend:
	cd /home/vboxuser/Desktop/openSi/kicad-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vboxuser/Desktop/openSi/kicad-source /home/vboxuser/Desktop/openSi/kicad-source/utils/idftools /home/vboxuser/Desktop/openSi/kicad-build /home/vboxuser/Desktop/openSi/kicad-build/utils/idftools /home/vboxuser/Desktop/openSi/kicad-build/utils/idftools/CMakeFiles/idfcyl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : utils/idftools/CMakeFiles/idfcyl.dir/depend

