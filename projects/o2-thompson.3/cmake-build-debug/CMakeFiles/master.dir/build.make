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
CMAKE_SOURCE_DIR = /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/master.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/master.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/master.dir/flags.make

CMakeFiles/master.dir/main.c.o: CMakeFiles/master.dir/flags.make
CMakeFiles/master.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/master.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/master.dir/main.c.o   -c /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/main.c

CMakeFiles/master.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/master.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/main.c > CMakeFiles/master.dir/main.c.i

CMakeFiles/master.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/master.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/main.c -o CMakeFiles/master.dir/main.c.s

CMakeFiles/master.dir/main.c.o.requires:

.PHONY : CMakeFiles/master.dir/main.c.o.requires

CMakeFiles/master.dir/main.c.o.provides: CMakeFiles/master.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/master.dir/build.make CMakeFiles/master.dir/main.c.o.provides.build
.PHONY : CMakeFiles/master.dir/main.c.o.provides

CMakeFiles/master.dir/main.c.o.provides.build: CMakeFiles/master.dir/main.c.o


CMakeFiles/master.dir/shared.c.o: CMakeFiles/master.dir/flags.make
CMakeFiles/master.dir/shared.c.o: ../shared.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/master.dir/shared.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/master.dir/shared.c.o   -c /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/shared.c

CMakeFiles/master.dir/shared.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/master.dir/shared.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/shared.c > CMakeFiles/master.dir/shared.c.i

CMakeFiles/master.dir/shared.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/master.dir/shared.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/shared.c -o CMakeFiles/master.dir/shared.c.s

CMakeFiles/master.dir/shared.c.o.requires:

.PHONY : CMakeFiles/master.dir/shared.c.o.requires

CMakeFiles/master.dir/shared.c.o.provides: CMakeFiles/master.dir/shared.c.o.requires
	$(MAKE) -f CMakeFiles/master.dir/build.make CMakeFiles/master.dir/shared.c.o.provides.build
.PHONY : CMakeFiles/master.dir/shared.c.o.provides

CMakeFiles/master.dir/shared.c.o.provides.build: CMakeFiles/master.dir/shared.c.o


# Object files for target master
master_OBJECTS = \
"CMakeFiles/master.dir/main.c.o" \
"CMakeFiles/master.dir/shared.c.o"

# External object files for target master
master_EXTERNAL_OBJECTS =

master: CMakeFiles/master.dir/main.c.o
master: CMakeFiles/master.dir/shared.c.o
master: CMakeFiles/master.dir/build.make
master: CMakeFiles/master.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable master"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/master.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/master.dir/build: master

.PHONY : CMakeFiles/master.dir/build

CMakeFiles/master.dir/requires: CMakeFiles/master.dir/main.c.o.requires
CMakeFiles/master.dir/requires: CMakeFiles/master.dir/shared.c.o.requires

.PHONY : CMakeFiles/master.dir/requires

CMakeFiles/master.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/master.dir/cmake_clean.cmake
.PHONY : CMakeFiles/master.dir/clean

CMakeFiles/master.dir/depend:
	cd /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3 /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3 /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/cmake-build-debug /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/cmake-build-debug /Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.3/cmake-build-debug/CMakeFiles/master.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/master.dir/depend
