# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /home/nico/Apps/Clion/clion-2024.2.2/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/nico/Apps/Clion/clion-2024.2.2/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Lab.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab.dir/flags.make

CMakeFiles/Lab.dir/main.cpp.o: CMakeFiles/Lab.dir/flags.make
CMakeFiles/Lab.dir/main.cpp.o: /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab/main.cpp
CMakeFiles/Lab.dir/main.cpp.o: CMakeFiles/Lab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Lab.dir/main.cpp.o -MF CMakeFiles/Lab.dir/main.cpp.o.d -o CMakeFiles/Lab.dir/main.cpp.o -c /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab/main.cpp

CMakeFiles/Lab.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Lab.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab/main.cpp > CMakeFiles/Lab.dir/main.cpp.i

CMakeFiles/Lab.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Lab.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab/main.cpp -o CMakeFiles/Lab.dir/main.cpp.s

# Object files for target Lab
Lab_OBJECTS = \
"CMakeFiles/Lab.dir/main.cpp.o"

# External object files for target Lab
Lab_EXTERNAL_OBJECTS =

Lab: CMakeFiles/Lab.dir/main.cpp.o
Lab: CMakeFiles/Lab.dir/build.make
Lab: CMakeFiles/Lab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab.dir/build: Lab
.PHONY : CMakeFiles/Lab.dir/build

CMakeFiles/Lab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab.dir/clean

CMakeFiles/Lab.dir/depend:
	cd /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab/cmake-build-debug /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab/cmake-build-debug /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_09/Lab/cmake-build-debug/CMakeFiles/Lab.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Lab.dir/depend

