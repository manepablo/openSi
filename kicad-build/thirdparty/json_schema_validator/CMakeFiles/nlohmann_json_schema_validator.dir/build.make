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
include thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/compiler_depend.make

# Include the progress variables for this target.
include thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/progress.make

# Include the compile flags for this target's objects.
include thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/flags.make

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.o: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/flags.make
thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.o: /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-schema-draft7.json.cpp
thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.o: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.o"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.o -MF CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.o.d -o CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.o -c /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-schema-draft7.json.cpp

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.i"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-schema-draft7.json.cpp > CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.i

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.s"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-schema-draft7.json.cpp -o CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.s

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.o: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/flags.make
thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.o: /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-uri.cpp
thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.o: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.o"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.o -MF CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.o.d -o CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.o -c /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-uri.cpp

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.i"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-uri.cpp > CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.i

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.s"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-uri.cpp -o CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.s

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.o: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/flags.make
thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.o: /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-validator.cpp
thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.o: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.o"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.o -MF CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.o.d -o CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.o -c /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-validator.cpp

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.i"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-validator.cpp > CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.i

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.s"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-validator.cpp -o CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.s

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.o: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/flags.make
thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.o: /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-patch.cpp
thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.o: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.o"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.o -MF CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.o.d -o CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.o -c /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-patch.cpp

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.i"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-patch.cpp > CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.i

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.s"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/json-patch.cpp -o CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.s

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.o: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/flags.make
thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.o: /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/string-format-check.cpp
thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.o: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.o"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.o -MF CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.o.d -o CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.o -c /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/string-format-check.cpp

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.i"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/string-format-check.cpp > CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.i

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.s"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator/string-format-check.cpp -o CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.s

# Object files for target nlohmann_json_schema_validator
nlohmann_json_schema_validator_OBJECTS = \
"CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.o" \
"CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.o" \
"CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.o" \
"CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.o" \
"CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.o"

# External object files for target nlohmann_json_schema_validator
nlohmann_json_schema_validator_EXTERNAL_OBJECTS =

thirdparty/json_schema_validator/libnlohmann_json_schema_validator.a: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-schema-draft7.json.cpp.o
thirdparty/json_schema_validator/libnlohmann_json_schema_validator.a: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-uri.cpp.o
thirdparty/json_schema_validator/libnlohmann_json_schema_validator.a: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-validator.cpp.o
thirdparty/json_schema_validator/libnlohmann_json_schema_validator.a: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/json-patch.cpp.o
thirdparty/json_schema_validator/libnlohmann_json_schema_validator.a: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/string-format-check.cpp.o
thirdparty/json_schema_validator/libnlohmann_json_schema_validator.a: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/build.make
thirdparty/json_schema_validator/libnlohmann_json_schema_validator.a: thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vboxuser/Desktop/openSi/kicad-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libnlohmann_json_schema_validator.a"
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && $(CMAKE_COMMAND) -P CMakeFiles/nlohmann_json_schema_validator.dir/cmake_clean_target.cmake
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nlohmann_json_schema_validator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/build: thirdparty/json_schema_validator/libnlohmann_json_schema_validator.a
.PHONY : thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/build

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/clean:
	cd /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator && $(CMAKE_COMMAND) -P CMakeFiles/nlohmann_json_schema_validator.dir/cmake_clean.cmake
.PHONY : thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/clean

thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/depend:
	cd /home/vboxuser/Desktop/openSi/kicad-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vboxuser/Desktop/openSi/kicad-source /home/vboxuser/Desktop/openSi/kicad-source/thirdparty/json_schema_validator /home/vboxuser/Desktop/openSi/kicad-build /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator /home/vboxuser/Desktop/openSi/kicad-build/thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : thirdparty/json_schema_validator/CMakeFiles/nlohmann_json_schema_validator.dir/depend

