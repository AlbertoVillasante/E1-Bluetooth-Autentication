# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alberto/Desktop/uni/TFG/implementacion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alberto/Desktop/uni/TFG/implementacion/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/implementacion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/implementacion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/implementacion.dir/flags.make

CMakeFiles/implementacion.dir/main.c.o: CMakeFiles/implementacion.dir/flags.make
CMakeFiles/implementacion.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alberto/Desktop/uni/TFG/implementacion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/implementacion.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/implementacion.dir/main.c.o -c /Users/alberto/Desktop/uni/TFG/implementacion/main.c

CMakeFiles/implementacion.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/implementacion.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alberto/Desktop/uni/TFG/implementacion/main.c > CMakeFiles/implementacion.dir/main.c.i

CMakeFiles/implementacion.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/implementacion.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alberto/Desktop/uni/TFG/implementacion/main.c -o CMakeFiles/implementacion.dir/main.c.s

CMakeFiles/implementacion.dir/saferplus.c.o: CMakeFiles/implementacion.dir/flags.make
CMakeFiles/implementacion.dir/saferplus.c.o: ../saferplus.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alberto/Desktop/uni/TFG/implementacion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/implementacion.dir/saferplus.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/implementacion.dir/saferplus.c.o -c /Users/alberto/Desktop/uni/TFG/implementacion/saferplus.c

CMakeFiles/implementacion.dir/saferplus.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/implementacion.dir/saferplus.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alberto/Desktop/uni/TFG/implementacion/saferplus.c > CMakeFiles/implementacion.dir/saferplus.c.i

CMakeFiles/implementacion.dir/saferplus.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/implementacion.dir/saferplus.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alberto/Desktop/uni/TFG/implementacion/saferplus.c -o CMakeFiles/implementacion.dir/saferplus.c.s

CMakeFiles/implementacion.dir/aux.c.o: CMakeFiles/implementacion.dir/flags.make
CMakeFiles/implementacion.dir/aux.c.o: ../aux.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alberto/Desktop/uni/TFG/implementacion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/implementacion.dir/aux.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/implementacion.dir/aux.c.o -c /Users/alberto/Desktop/uni/TFG/implementacion/aux.c

CMakeFiles/implementacion.dir/aux.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/implementacion.dir/aux.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/alberto/Desktop/uni/TFG/implementacion/aux.c > CMakeFiles/implementacion.dir/aux.c.i

CMakeFiles/implementacion.dir/aux.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/implementacion.dir/aux.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/alberto/Desktop/uni/TFG/implementacion/aux.c -o CMakeFiles/implementacion.dir/aux.c.s

# Object files for target implementacion
implementacion_OBJECTS = \
"CMakeFiles/implementacion.dir/main.c.o" \
"CMakeFiles/implementacion.dir/saferplus.c.o" \
"CMakeFiles/implementacion.dir/aux.c.o"

# External object files for target implementacion
implementacion_EXTERNAL_OBJECTS =

implementacion: CMakeFiles/implementacion.dir/main.c.o
implementacion: CMakeFiles/implementacion.dir/saferplus.c.o
implementacion: CMakeFiles/implementacion.dir/aux.c.o
implementacion: CMakeFiles/implementacion.dir/build.make
implementacion: CMakeFiles/implementacion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alberto/Desktop/uni/TFG/implementacion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable implementacion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/implementacion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/implementacion.dir/build: implementacion

.PHONY : CMakeFiles/implementacion.dir/build

CMakeFiles/implementacion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/implementacion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/implementacion.dir/clean

CMakeFiles/implementacion.dir/depend:
	cd /Users/alberto/Desktop/uni/TFG/implementacion/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alberto/Desktop/uni/TFG/implementacion /Users/alberto/Desktop/uni/TFG/implementacion /Users/alberto/Desktop/uni/TFG/implementacion/cmake-build-debug /Users/alberto/Desktop/uni/TFG/implementacion/cmake-build-debug /Users/alberto/Desktop/uni/TFG/implementacion/cmake-build-debug/CMakeFiles/implementacion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/implementacion.dir/depend
