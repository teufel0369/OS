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
include CMakeFiles/o2_thompson_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/o2_thompson_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/o2_thompson_2.dir/flags.make

CMakeFiles/o2_thompson_2.dir/consumer.c.o: CMakeFiles/o2_thompson_2.dir/flags.make
CMakeFiles/o2_thompson_2.dir/consumer.c.o: ../consumer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/o2_thompson_2.dir/consumer.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/o2_thompson_2.dir/consumer.c.o   -c /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/consumer.c

CMakeFiles/o2_thompson_2.dir/consumer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/o2_thompson_2.dir/consumer.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/consumer.c > CMakeFiles/o2_thompson_2.dir/consumer.c.i

CMakeFiles/o2_thompson_2.dir/consumer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/o2_thompson_2.dir/consumer.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/consumer.c -o CMakeFiles/o2_thompson_2.dir/consumer.c.s

CMakeFiles/o2_thompson_2.dir/consumer.c.o.requires:

.PHONY : CMakeFiles/o2_thompson_2.dir/consumer.c.o.requires

CMakeFiles/o2_thompson_2.dir/consumer.c.o.provides: CMakeFiles/o2_thompson_2.dir/consumer.c.o.requires
	$(MAKE) -f CMakeFiles/o2_thompson_2.dir/build.make CMakeFiles/o2_thompson_2.dir/consumer.c.o.provides.build
.PHONY : CMakeFiles/o2_thompson_2.dir/consumer.c.o.provides

CMakeFiles/o2_thompson_2.dir/consumer.c.o.provides.build: CMakeFiles/o2_thompson_2.dir/consumer.c.o


CMakeFiles/o2_thompson_2.dir/common.c.o: CMakeFiles/o2_thompson_2.dir/flags.make
CMakeFiles/o2_thompson_2.dir/common.c.o: ../common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/o2_thompson_2.dir/common.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/o2_thompson_2.dir/common.c.o   -c /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/common.c

CMakeFiles/o2_thompson_2.dir/common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/o2_thompson_2.dir/common.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/common.c > CMakeFiles/o2_thompson_2.dir/common.c.i

CMakeFiles/o2_thompson_2.dir/common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/o2_thompson_2.dir/common.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/common.c -o CMakeFiles/o2_thompson_2.dir/common.c.s

CMakeFiles/o2_thompson_2.dir/common.c.o.requires:

.PHONY : CMakeFiles/o2_thompson_2.dir/common.c.o.requires

CMakeFiles/o2_thompson_2.dir/common.c.o.provides: CMakeFiles/o2_thompson_2.dir/common.c.o.requires
	$(MAKE) -f CMakeFiles/o2_thompson_2.dir/build.make CMakeFiles/o2_thompson_2.dir/common.c.o.provides.build
.PHONY : CMakeFiles/o2_thompson_2.dir/common.c.o.provides

CMakeFiles/o2_thompson_2.dir/common.c.o.provides.build: CMakeFiles/o2_thompson_2.dir/common.c.o


CMakeFiles/o2_thompson_2.dir/main.c.o: CMakeFiles/o2_thompson_2.dir/flags.make
CMakeFiles/o2_thompson_2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/o2_thompson_2.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/o2_thompson_2.dir/main.c.o   -c /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/main.c

CMakeFiles/o2_thompson_2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/o2_thompson_2.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/main.c > CMakeFiles/o2_thompson_2.dir/main.c.i

CMakeFiles/o2_thompson_2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/o2_thompson_2.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/main.c -o CMakeFiles/o2_thompson_2.dir/main.c.s

CMakeFiles/o2_thompson_2.dir/main.c.o.requires:

.PHONY : CMakeFiles/o2_thompson_2.dir/main.c.o.requires

CMakeFiles/o2_thompson_2.dir/main.c.o.provides: CMakeFiles/o2_thompson_2.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/o2_thompson_2.dir/build.make CMakeFiles/o2_thompson_2.dir/main.c.o.provides.build
.PHONY : CMakeFiles/o2_thompson_2.dir/main.c.o.provides

CMakeFiles/o2_thompson_2.dir/main.c.o.provides.build: CMakeFiles/o2_thompson_2.dir/main.c.o


CMakeFiles/o2_thompson_2.dir/producer.c.o: CMakeFiles/o2_thompson_2.dir/flags.make
CMakeFiles/o2_thompson_2.dir/producer.c.o: ../producer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/o2_thompson_2.dir/producer.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/o2_thompson_2.dir/producer.c.o   -c /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/producer.c

CMakeFiles/o2_thompson_2.dir/producer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/o2_thompson_2.dir/producer.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/producer.c > CMakeFiles/o2_thompson_2.dir/producer.c.i

CMakeFiles/o2_thompson_2.dir/producer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/o2_thompson_2.dir/producer.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/producer.c -o CMakeFiles/o2_thompson_2.dir/producer.c.s

CMakeFiles/o2_thompson_2.dir/producer.c.o.requires:

.PHONY : CMakeFiles/o2_thompson_2.dir/producer.c.o.requires

CMakeFiles/o2_thompson_2.dir/producer.c.o.provides: CMakeFiles/o2_thompson_2.dir/producer.c.o.requires
	$(MAKE) -f CMakeFiles/o2_thompson_2.dir/build.make CMakeFiles/o2_thompson_2.dir/producer.c.o.provides.build
.PHONY : CMakeFiles/o2_thompson_2.dir/producer.c.o.provides

CMakeFiles/o2_thompson_2.dir/producer.c.o.provides.build: CMakeFiles/o2_thompson_2.dir/producer.c.o


# Object files for target o2_thompson_2
o2_thompson_2_OBJECTS = \
"CMakeFiles/o2_thompson_2.dir/consumer.c.o" \
"CMakeFiles/o2_thompson_2.dir/common.c.o" \
"CMakeFiles/o2_thompson_2.dir/main.c.o" \
"CMakeFiles/o2_thompson_2.dir/producer.c.o"

# External object files for target o2_thompson_2
o2_thompson_2_EXTERNAL_OBJECTS =

o2_thompson_2: CMakeFiles/o2_thompson_2.dir/consumer.c.o
o2_thompson_2: CMakeFiles/o2_thompson_2.dir/common.c.o
o2_thompson_2: CMakeFiles/o2_thompson_2.dir/main.c.o
o2_thompson_2: CMakeFiles/o2_thompson_2.dir/producer.c.o
o2_thompson_2: CMakeFiles/o2_thompson_2.dir/build.make
o2_thompson_2: CMakeFiles/o2_thompson_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable o2_thompson_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/o2_thompson_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/o2_thompson_2.dir/build: o2_thompson_2

.PHONY : CMakeFiles/o2_thompson_2.dir/build

CMakeFiles/o2_thompson_2.dir/requires: CMakeFiles/o2_thompson_2.dir/consumer.c.o.requires
CMakeFiles/o2_thompson_2.dir/requires: CMakeFiles/o2_thompson_2.dir/common.c.o.requires
CMakeFiles/o2_thompson_2.dir/requires: CMakeFiles/o2_thompson_2.dir/main.c.o.requires
CMakeFiles/o2_thompson_2.dir/requires: CMakeFiles/o2_thompson_2.dir/producer.c.o.requires

.PHONY : CMakeFiles/o2_thompson_2.dir/requires

CMakeFiles/o2_thompson_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/o2_thompson_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/o2_thompson_2.dir/clean

CMakeFiles/o2_thompson_2.dir/depend:
	cd /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2 /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2 /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug /Users/christhompson/Desktop/Notes/OS/projects/o2-thompson.2/cmake-build-debug/CMakeFiles/o2_thompson_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/o2_thompson_2.dir/depend

