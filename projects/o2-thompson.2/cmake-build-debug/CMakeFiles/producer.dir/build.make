# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/producer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/producer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/producer.dir/flags.make

CMakeFiles/producer.dir/common.c.o: CMakeFiles/producer.dir/flags.make
CMakeFiles/producer.dir/common.c.o: ../common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/producer.dir/common.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/producer.dir/common.c.o   -c /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/common.c

CMakeFiles/producer.dir/common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/producer.dir/common.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/common.c > CMakeFiles/producer.dir/common.c.i

CMakeFiles/producer.dir/common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/producer.dir/common.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/common.c -o CMakeFiles/producer.dir/common.c.s

CMakeFiles/producer.dir/common.c.o.requires:

.PHONY : CMakeFiles/producer.dir/common.c.o.requires

CMakeFiles/producer.dir/common.c.o.provides: CMakeFiles/producer.dir/common.c.o.requires
	$(MAKE) -f CMakeFiles/producer.dir/build.make CMakeFiles/producer.dir/common.c.o.provides.build
.PHONY : CMakeFiles/producer.dir/common.c.o.provides

CMakeFiles/producer.dir/common.c.o.provides.build: CMakeFiles/producer.dir/common.c.o


CMakeFiles/producer.dir/producer.c.o: CMakeFiles/producer.dir/flags.make
CMakeFiles/producer.dir/producer.c.o: ../producer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/producer.dir/producer.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/producer.dir/producer.c.o   -c /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/producer.c

CMakeFiles/producer.dir/producer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/producer.dir/producer.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/producer.c > CMakeFiles/producer.dir/producer.c.i

CMakeFiles/producer.dir/producer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/producer.dir/producer.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/producer.c -o CMakeFiles/producer.dir/producer.c.s

CMakeFiles/producer.dir/producer.c.o.requires:

.PHONY : CMakeFiles/producer.dir/producer.c.o.requires

CMakeFiles/producer.dir/producer.c.o.provides: CMakeFiles/producer.dir/producer.c.o.requires
	$(MAKE) -f CMakeFiles/producer.dir/build.make CMakeFiles/producer.dir/producer.c.o.provides.build
.PHONY : CMakeFiles/producer.dir/producer.c.o.provides

CMakeFiles/producer.dir/producer.c.o.provides.build: CMakeFiles/producer.dir/producer.c.o


# Object files for target producer
producer_OBJECTS = \
"CMakeFiles/producer.dir/common.c.o" \
"CMakeFiles/producer.dir/producer.c.o"

# External object files for target producer
producer_EXTERNAL_OBJECTS =

producer: CMakeFiles/producer.dir/common.c.o
producer: CMakeFiles/producer.dir/producer.c.o
producer: CMakeFiles/producer.dir/build.make
producer: CMakeFiles/producer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable producer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/producer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/producer.dir/build: producer

.PHONY : CMakeFiles/producer.dir/build

CMakeFiles/producer.dir/requires: CMakeFiles/producer.dir/common.c.o.requires
CMakeFiles/producer.dir/requires: CMakeFiles/producer.dir/producer.c.o.requires

.PHONY : CMakeFiles/producer.dir/requires

CMakeFiles/producer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/producer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/producer.dir/clean

CMakeFiles/producer.dir/depend:
	cd /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2 /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2 /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug/CMakeFiles/producer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/producer.dir/depend

