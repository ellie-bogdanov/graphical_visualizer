# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/princess-ellie/Documents/cpp_projects/graphical_visualizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/princess-ellie/Documents/cpp_projects/graphical_visualizer/build

# Include any dependencies generated for this target.
include CMakeFiles/graphical_visualizer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/graphical_visualizer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/graphical_visualizer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graphical_visualizer.dir/flags.make

CMakeFiles/graphical_visualizer.dir/main.cpp.o: CMakeFiles/graphical_visualizer.dir/flags.make
CMakeFiles/graphical_visualizer.dir/main.cpp.o: ../main.cpp
CMakeFiles/graphical_visualizer.dir/main.cpp.o: CMakeFiles/graphical_visualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/princess-ellie/Documents/cpp_projects/graphical_visualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graphical_visualizer.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graphical_visualizer.dir/main.cpp.o -MF CMakeFiles/graphical_visualizer.dir/main.cpp.o.d -o CMakeFiles/graphical_visualizer.dir/main.cpp.o -c /home/princess-ellie/Documents/cpp_projects/graphical_visualizer/main.cpp

CMakeFiles/graphical_visualizer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphical_visualizer.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/princess-ellie/Documents/cpp_projects/graphical_visualizer/main.cpp > CMakeFiles/graphical_visualizer.dir/main.cpp.i

CMakeFiles/graphical_visualizer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphical_visualizer.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/princess-ellie/Documents/cpp_projects/graphical_visualizer/main.cpp -o CMakeFiles/graphical_visualizer.dir/main.cpp.s

CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.o: CMakeFiles/graphical_visualizer.dir/flags.make
CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.o: ../graphical_visualizer.cpp
CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.o: CMakeFiles/graphical_visualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/princess-ellie/Documents/cpp_projects/graphical_visualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.o -MF CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.o.d -o CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.o -c /home/princess-ellie/Documents/cpp_projects/graphical_visualizer/graphical_visualizer.cpp

CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/princess-ellie/Documents/cpp_projects/graphical_visualizer/graphical_visualizer.cpp > CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.i

CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/princess-ellie/Documents/cpp_projects/graphical_visualizer/graphical_visualizer.cpp -o CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.s

# Object files for target graphical_visualizer
graphical_visualizer_OBJECTS = \
"CMakeFiles/graphical_visualizer.dir/main.cpp.o" \
"CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.o"

# External object files for target graphical_visualizer
graphical_visualizer_EXTERNAL_OBJECTS =

graphical_visualizer: CMakeFiles/graphical_visualizer.dir/main.cpp.o
graphical_visualizer: CMakeFiles/graphical_visualizer.dir/graphical_visualizer.cpp.o
graphical_visualizer: CMakeFiles/graphical_visualizer.dir/build.make
graphical_visualizer: CMakeFiles/graphical_visualizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/princess-ellie/Documents/cpp_projects/graphical_visualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable graphical_visualizer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graphical_visualizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graphical_visualizer.dir/build: graphical_visualizer
.PHONY : CMakeFiles/graphical_visualizer.dir/build

CMakeFiles/graphical_visualizer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graphical_visualizer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graphical_visualizer.dir/clean

CMakeFiles/graphical_visualizer.dir/depend:
	cd /home/princess-ellie/Documents/cpp_projects/graphical_visualizer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/princess-ellie/Documents/cpp_projects/graphical_visualizer /home/princess-ellie/Documents/cpp_projects/graphical_visualizer /home/princess-ellie/Documents/cpp_projects/graphical_visualizer/build /home/princess-ellie/Documents/cpp_projects/graphical_visualizer/build /home/princess-ellie/Documents/cpp_projects/graphical_visualizer/build/CMakeFiles/graphical_visualizer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graphical_visualizer.dir/depend

