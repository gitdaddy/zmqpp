# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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


# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dmarsden/dev/zmqpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmarsden/dev/zmqpp

# Include any dependencies generated for this target.
include CMakeFiles/zmqpp-example-strawhouse.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zmqpp-example-strawhouse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zmqpp-example-strawhouse.dir/flags.make

CMakeFiles/zmqpp-example-strawhouse.dir/examples/strawhouse.cpp.o: CMakeFiles/zmqpp-example-strawhouse.dir/flags.make
CMakeFiles/zmqpp-example-strawhouse.dir/examples/strawhouse.cpp.o: examples/strawhouse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmarsden/dev/zmqpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zmqpp-example-strawhouse.dir/examples/strawhouse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zmqpp-example-strawhouse.dir/examples/strawhouse.cpp.o -c /home/dmarsden/dev/zmqpp/examples/strawhouse.cpp

CMakeFiles/zmqpp-example-strawhouse.dir/examples/strawhouse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmqpp-example-strawhouse.dir/examples/strawhouse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmarsden/dev/zmqpp/examples/strawhouse.cpp > CMakeFiles/zmqpp-example-strawhouse.dir/examples/strawhouse.cpp.i

CMakeFiles/zmqpp-example-strawhouse.dir/examples/strawhouse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmqpp-example-strawhouse.dir/examples/strawhouse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmarsden/dev/zmqpp/examples/strawhouse.cpp -o CMakeFiles/zmqpp-example-strawhouse.dir/examples/strawhouse.cpp.s

# Object files for target zmqpp-example-strawhouse
zmqpp__example__strawhouse_OBJECTS = \
"CMakeFiles/zmqpp-example-strawhouse.dir/examples/strawhouse.cpp.o"

# External object files for target zmqpp-example-strawhouse
zmqpp__example__strawhouse_EXTERNAL_OBJECTS =

zmqpp-example-strawhouse: CMakeFiles/zmqpp-example-strawhouse.dir/examples/strawhouse.cpp.o
zmqpp-example-strawhouse: CMakeFiles/zmqpp-example-strawhouse.dir/build.make
zmqpp-example-strawhouse: libzmqpp.so
zmqpp-example-strawhouse: /usr/local/lib/libzmq.so
zmqpp-example-strawhouse: CMakeFiles/zmqpp-example-strawhouse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmarsden/dev/zmqpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable zmqpp-example-strawhouse"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zmqpp-example-strawhouse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zmqpp-example-strawhouse.dir/build: zmqpp-example-strawhouse

.PHONY : CMakeFiles/zmqpp-example-strawhouse.dir/build

CMakeFiles/zmqpp-example-strawhouse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zmqpp-example-strawhouse.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zmqpp-example-strawhouse.dir/clean

CMakeFiles/zmqpp-example-strawhouse.dir/depend:
	cd /home/dmarsden/dev/zmqpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmarsden/dev/zmqpp /home/dmarsden/dev/zmqpp /home/dmarsden/dev/zmqpp /home/dmarsden/dev/zmqpp /home/dmarsden/dev/zmqpp/CMakeFiles/zmqpp-example-strawhouse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zmqpp-example-strawhouse.dir/depend
