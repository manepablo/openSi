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
include qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/compiler_depend.make

# Include the progress variables for this target.
include qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/progress.make

# Include the compile flags for this target's objects.
include qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/flags.make

qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.o: qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/flags.make
qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.o: /home/vboxuser/Desktop/openSi/kicad-source/qa/pcbnew_utils/board_construction_utils.cpp
qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.o: qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.o"
	cd /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.o -MF CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.o.d -o CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.o -c /home/vboxuser/Desktop/openSi/kicad-source/qa/pcbnew_utils/board_construction_utils.cpp

qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.i"
	cd /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vboxuser/Desktop/openSi/kicad-source/qa/pcbnew_utils/board_construction_utils.cpp > CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.i

qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.s"
	cd /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vboxuser/Desktop/openSi/kicad-source/qa/pcbnew_utils/board_construction_utils.cpp -o CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.s

qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.o: qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/flags.make
qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.o: /home/vboxuser/Desktop/openSi/kicad-source/qa/pcbnew_utils/board_file_utils.cpp
qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.o: qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.o"
	cd /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils && /usr/bin/c++ $(CXX_DEFINES) -DQA_PCBNEW_DATA_LOCATION="(\"/home/vboxuser/Desktop/openSi/kicad-source/qa/data/pcbnew\")" $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.o -MF CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.o.d -o CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.o -c /home/vboxuser/Desktop/openSi/kicad-source/qa/pcbnew_utils/board_file_utils.cpp

qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.i"
	cd /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils && /usr/bin/c++ $(CXX_DEFINES) -DQA_PCBNEW_DATA_LOCATION="(\"/home/vboxuser/Desktop/openSi/kicad-source/qa/data/pcbnew\")" $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vboxuser/Desktop/openSi/kicad-source/qa/pcbnew_utils/board_file_utils.cpp > CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.i

qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.s"
	cd /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils && /usr/bin/c++ $(CXX_DEFINES) -DQA_PCBNEW_DATA_LOCATION="(\"/home/vboxuser/Desktop/openSi/kicad-source/qa/data/pcbnew\")" $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vboxuser/Desktop/openSi/kicad-source/qa/pcbnew_utils/board_file_utils.cpp -o CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.s

qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.o: qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/flags.make
qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.o: /home/vboxuser/Desktop/openSi/kicad-source/qa/pcbnew_utils/board_test_utils.cpp
qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.o: qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.o"
	cd /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.o -MF CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.o.d -o CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.o -c /home/vboxuser/Desktop/openSi/kicad-source/qa/pcbnew_utils/board_test_utils.cpp

qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.i"
	cd /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vboxuser/Desktop/openSi/kicad-source/qa/pcbnew_utils/board_test_utils.cpp > CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.i

qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.s"
	cd /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vboxuser/Desktop/openSi/kicad-source/qa/pcbnew_utils/board_test_utils.cpp -o CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.s

# Object files for target qa_pcbnew_utils
qa_pcbnew_utils_OBJECTS = \
"CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.o" \
"CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.o" \
"CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.o"

# External object files for target qa_pcbnew_utils
qa_pcbnew_utils_EXTERNAL_OBJECTS =

qa/pcbnew_utils/libqa_pcbnew_utils.a: qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_construction_utils.cpp.o
qa/pcbnew_utils/libqa_pcbnew_utils.a: qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_file_utils.cpp.o
qa/pcbnew_utils/libqa_pcbnew_utils.a: qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/board_test_utils.cpp.o
qa/pcbnew_utils/libqa_pcbnew_utils.a: qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/build.make
qa/pcbnew_utils/libqa_pcbnew_utils.a: qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libqa_pcbnew_utils.a"
	cd /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils && $(CMAKE_COMMAND) -P CMakeFiles/qa_pcbnew_utils.dir/cmake_clean_target.cmake
	cd /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qa_pcbnew_utils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/build: qa/pcbnew_utils/libqa_pcbnew_utils.a
.PHONY : qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/build

qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/clean:
	cd /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils && $(CMAKE_COMMAND) -P CMakeFiles/qa_pcbnew_utils.dir/cmake_clean.cmake
.PHONY : qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/clean

qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/depend:
	cd /home/vboxuser/Desktop/openSi/kicad-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vboxuser/Desktop/openSi/kicad-source /home/vboxuser/Desktop/openSi/kicad-source/qa/pcbnew_utils /home/vboxuser/Desktop/openSi/kicad-build /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils /home/vboxuser/Desktop/openSi/kicad-build/qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : qa/pcbnew_utils/CMakeFiles/qa_pcbnew_utils.dir/depend

