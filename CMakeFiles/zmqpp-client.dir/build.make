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
include CMakeFiles/zmqpp-client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zmqpp-client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zmqpp-client.dir/flags.make

CMakeFiles/zmqpp-client.dir/src/client/main.cpp.o: CMakeFiles/zmqpp-client.dir/flags.make
CMakeFiles/zmqpp-client.dir/src/client/main.cpp.o: src/client/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmarsden/dev/zmqpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zmqpp-client.dir/src/client/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zmqpp-client.dir/src/client/main.cpp.o -c /home/dmarsden/dev/zmqpp/src/client/main.cpp

CMakeFiles/zmqpp-client.dir/src/client/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmqpp-client.dir/src/client/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmarsden/dev/zmqpp/src/client/main.cpp > CMakeFiles/zmqpp-client.dir/src/client/main.cpp.i

CMakeFiles/zmqpp-client.dir/src/client/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmqpp-client.dir/src/client/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmarsden/dev/zmqpp/src/client/main.cpp -o CMakeFiles/zmqpp-client.dir/src/client/main.cpp.s

CMakeFiles/zmqpp-client.dir/src/client/options.cpp.o: CMakeFiles/zmqpp-client.dir/flags.make
CMakeFiles/zmqpp-client.dir/src/client/options.cpp.o: src/client/options.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmarsden/dev/zmqpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zmqpp-client.dir/src/client/options.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zmqpp-client.dir/src/client/options.cpp.o -c /home/dmarsden/dev/zmqpp/src/client/options.cpp

CMakeFiles/zmqpp-client.dir/src/client/options.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmqpp-client.dir/src/client/options.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmarsden/dev/zmqpp/src/client/options.cpp > CMakeFiles/zmqpp-client.dir/src/client/options.cpp.i

CMakeFiles/zmqpp-client.dir/src/client/options.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmqpp-client.dir/src/client/options.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmarsden/dev/zmqpp/src/client/options.cpp -o CMakeFiles/zmqpp-client.dir/src/client/options.cpp.s

# Object files for target zmqpp-client
zmqpp__client_OBJECTS = \
"CMakeFiles/zmqpp-client.dir/src/client/main.cpp.o" \
"CMakeFiles/zmqpp-client.dir/src/client/options.cpp.o"

# External object files for target zmqpp-client
zmqpp__client_EXTERNAL_OBJECTS =

zmqpp-client: CMakeFiles/zmqpp-client.dir/src/client/main.cpp.o
zmqpp-client: CMakeFiles/zmqpp-client.dir/src/client/options.cpp.o
zmqpp-client: CMakeFiles/zmqpp-client.dir/build.make
zmqpp-client: libzmqpp.so
zmqpp-client: /opt/extern/externpro-20.06.1-gcc750-64-Linux/lib/libboost_program_options-gcc75-mt-s-x64-1_67.a
zmqpp-client: /usr/local/lib/libzmq.so
zmqpp-client: CMakeFiles/zmqpp-client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmarsden/dev/zmqpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable zmqpp-client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zmqpp-client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zmqpp-client.dir/build: zmqpp-client

.PHONY : CMakeFiles/zmqpp-client.dir/build

CMakeFiles/zmqpp-client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zmqpp-client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zmqpp-client.dir/clean

CMakeFiles/zmqpp-client.dir/depend:
	cd /home/dmarsden/dev/zmqpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmarsden/dev/zmqpp /home/dmarsden/dev/zmqpp /home/dmarsden/dev/zmqpp /home/dmarsden/dev/zmqpp /home/dmarsden/dev/zmqpp/CMakeFiles/zmqpp-client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zmqpp-client.dir/depend

