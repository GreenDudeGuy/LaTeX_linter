# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/max/projects_code/LaTeX_linter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/max/projects_code/LaTeX_linter/build

# Include any dependencies generated for this target.
include linterTest/CMakeFiles/STATIC.dir/depend.make

# Include the progress variables for this target.
include linterTest/CMakeFiles/STATIC.dir/progress.make

# Include the compile flags for this target's objects.
include linterTest/CMakeFiles/STATIC.dir/flags.make

linterTest/CMakeFiles/STATIC.dir/clean:
	cd /home/max/projects_code/LaTeX_linter/build/linterTest && $(CMAKE_COMMAND) -P CMakeFiles/STATIC.dir/cmake_clean.cmake
.PHONY : linterTest/CMakeFiles/STATIC.dir/clean

linterTest/CMakeFiles/STATIC.dir/depend:
	cd /home/max/projects_code/LaTeX_linter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/max/projects_code/LaTeX_linter /home/max/projects_code/LaTeX_linter/linterTest /home/max/projects_code/LaTeX_linter/build /home/max/projects_code/LaTeX_linter/build/linterTest /home/max/projects_code/LaTeX_linter/build/linterTest/CMakeFiles/STATIC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : linterTest/CMakeFiles/STATIC.dir/depend
