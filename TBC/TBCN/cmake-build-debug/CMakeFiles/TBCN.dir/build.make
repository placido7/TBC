# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\github\TBC\TBC\TBC\TBC\TBCN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\github\TBC\TBC\TBC\TBC\TBCN\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TBCN.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/TBCN.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TBCN.dir/flags.make

CMakeFiles/TBCN.dir/main.cpp.obj: CMakeFiles/TBCN.dir/flags.make
CMakeFiles/TBCN.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\TBC\TBC\TBC\TBC\TBCN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TBCN.dir/main.cpp.obj"
	D:\MingW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TBCN.dir\main.cpp.obj -c D:\github\TBC\TBC\TBC\TBC\TBCN\main.cpp

CMakeFiles/TBCN.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TBCN.dir/main.cpp.i"
	D:\MingW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\github\TBC\TBC\TBC\TBC\TBCN\main.cpp > CMakeFiles\TBCN.dir\main.cpp.i

CMakeFiles/TBCN.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TBCN.dir/main.cpp.s"
	D:\MingW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\github\TBC\TBC\TBC\TBC\TBCN\main.cpp -o CMakeFiles\TBCN.dir\main.cpp.s

CMakeFiles/TBCN.dir/bipartite_graph.cpp.obj: CMakeFiles/TBCN.dir/flags.make
CMakeFiles/TBCN.dir/bipartite_graph.cpp.obj: ../bipartite_graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\TBC\TBC\TBC\TBC\TBCN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TBCN.dir/bipartite_graph.cpp.obj"
	D:\MingW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TBCN.dir\bipartite_graph.cpp.obj -c D:\github\TBC\TBC\TBC\TBC\TBCN\bipartite_graph.cpp

CMakeFiles/TBCN.dir/bipartite_graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TBCN.dir/bipartite_graph.cpp.i"
	D:\MingW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\github\TBC\TBC\TBC\TBC\TBCN\bipartite_graph.cpp > CMakeFiles\TBCN.dir\bipartite_graph.cpp.i

CMakeFiles/TBCN.dir/bipartite_graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TBCN.dir/bipartite_graph.cpp.s"
	D:\MingW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\github\TBC\TBC\TBC\TBC\TBCN\bipartite_graph.cpp -o CMakeFiles\TBCN.dir\bipartite_graph.cpp.s

# Object files for target TBCN
TBCN_OBJECTS = \
"CMakeFiles/TBCN.dir/main.cpp.obj" \
"CMakeFiles/TBCN.dir/bipartite_graph.cpp.obj"

# External object files for target TBCN
TBCN_EXTERNAL_OBJECTS =

TBCN.exe: CMakeFiles/TBCN.dir/main.cpp.obj
TBCN.exe: CMakeFiles/TBCN.dir/bipartite_graph.cpp.obj
TBCN.exe: CMakeFiles/TBCN.dir/build.make
TBCN.exe: CMakeFiles/TBCN.dir/linklibs.rsp
TBCN.exe: CMakeFiles/TBCN.dir/objects1.rsp
TBCN.exe: CMakeFiles/TBCN.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\github\TBC\TBC\TBC\TBC\TBCN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TBCN.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TBCN.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TBCN.dir/build: TBCN.exe
.PHONY : CMakeFiles/TBCN.dir/build

CMakeFiles/TBCN.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TBCN.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TBCN.dir/clean

CMakeFiles/TBCN.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\github\TBC\TBC\TBC\TBC\TBCN D:\github\TBC\TBC\TBC\TBC\TBCN D:\github\TBC\TBC\TBC\TBC\TBCN\cmake-build-debug D:\github\TBC\TBC\TBC\TBC\TBCN\cmake-build-debug D:\github\TBC\TBC\TBC\TBC\TBCN\cmake-build-debug\CMakeFiles\TBCN.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TBCN.dir/depend

