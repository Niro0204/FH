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
CMAKE_SOURCE_DIR = /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Buffer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Buffer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Buffer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Buffer.dir/flags.make

CMakeFiles/Buffer.dir/main.cpp.o: CMakeFiles/Buffer.dir/flags.make
CMakeFiles/Buffer.dir/main.cpp.o: /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/main.cpp
CMakeFiles/Buffer.dir/main.cpp.o: CMakeFiles/Buffer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Buffer.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Buffer.dir/main.cpp.o -MF CMakeFiles/Buffer.dir/main.cpp.o.d -o CMakeFiles/Buffer.dir/main.cpp.o -c /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/main.cpp

CMakeFiles/Buffer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Buffer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/main.cpp > CMakeFiles/Buffer.dir/main.cpp.i

CMakeFiles/Buffer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Buffer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/main.cpp -o CMakeFiles/Buffer.dir/main.cpp.s

CMakeFiles/Buffer.dir/Buffer.cpp.o: CMakeFiles/Buffer.dir/flags.make
CMakeFiles/Buffer.dir/Buffer.cpp.o: /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/Buffer.cpp
CMakeFiles/Buffer.dir/Buffer.cpp.o: CMakeFiles/Buffer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Buffer.dir/Buffer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Buffer.dir/Buffer.cpp.o -MF CMakeFiles/Buffer.dir/Buffer.cpp.o.d -o CMakeFiles/Buffer.dir/Buffer.cpp.o -c /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/Buffer.cpp

CMakeFiles/Buffer.dir/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Buffer.dir/Buffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/Buffer.cpp > CMakeFiles/Buffer.dir/Buffer.cpp.i

CMakeFiles/Buffer.dir/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Buffer.dir/Buffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/Buffer.cpp -o CMakeFiles/Buffer.dir/Buffer.cpp.s

# Object files for target Buffer
Buffer_OBJECTS = \
"CMakeFiles/Buffer.dir/main.cpp.o" \
"CMakeFiles/Buffer.dir/Buffer.cpp.o"

# External object files for target Buffer
Buffer_EXTERNAL_OBJECTS =

Buffer: CMakeFiles/Buffer.dir/main.cpp.o
Buffer: CMakeFiles/Buffer.dir/Buffer.cpp.o
Buffer: CMakeFiles/Buffer.dir/build.make
Buffer: CMakeFiles/Buffer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Buffer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Buffer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Buffer.dir/build: Buffer
.PHONY : CMakeFiles/Buffer.dir/build

CMakeFiles/Buffer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Buffer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Buffer.dir/clean

CMakeFiles/Buffer.dir/depend:
	cd /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/cmake-build-debug /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/cmake-build-debug /home/nico/Dev/FH/Clion_projects/semeseter_3/OOP/Lab_05/UE/Buffer/cmake-build-debug/CMakeFiles/Buffer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Buffer.dir/depend

