# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ypc/xiaoc/code/data_structure/ch9_sort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ypc/xiaoc/code/data_structure/ch9_sort/build

# Include any dependencies generated for this target.
include CMakeFiles/sort_algorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sort_algorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sort_algorithm.dir/flags.make

CMakeFiles/sort_algorithm.dir/src/main.cpp.o: CMakeFiles/sort_algorithm.dir/flags.make
CMakeFiles/sort_algorithm.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ypc/xiaoc/code/data_structure/ch9_sort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sort_algorithm.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sort_algorithm.dir/src/main.cpp.o -c /home/ypc/xiaoc/code/data_structure/ch9_sort/src/main.cpp

CMakeFiles/sort_algorithm.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sort_algorithm.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ypc/xiaoc/code/data_structure/ch9_sort/src/main.cpp > CMakeFiles/sort_algorithm.dir/src/main.cpp.i

CMakeFiles/sort_algorithm.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sort_algorithm.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ypc/xiaoc/code/data_structure/ch9_sort/src/main.cpp -o CMakeFiles/sort_algorithm.dir/src/main.cpp.s

CMakeFiles/sort_algorithm.dir/src/SortAlgorithm.cpp.o: CMakeFiles/sort_algorithm.dir/flags.make
CMakeFiles/sort_algorithm.dir/src/SortAlgorithm.cpp.o: ../src/SortAlgorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ypc/xiaoc/code/data_structure/ch9_sort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sort_algorithm.dir/src/SortAlgorithm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sort_algorithm.dir/src/SortAlgorithm.cpp.o -c /home/ypc/xiaoc/code/data_structure/ch9_sort/src/SortAlgorithm.cpp

CMakeFiles/sort_algorithm.dir/src/SortAlgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sort_algorithm.dir/src/SortAlgorithm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ypc/xiaoc/code/data_structure/ch9_sort/src/SortAlgorithm.cpp > CMakeFiles/sort_algorithm.dir/src/SortAlgorithm.cpp.i

CMakeFiles/sort_algorithm.dir/src/SortAlgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sort_algorithm.dir/src/SortAlgorithm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ypc/xiaoc/code/data_structure/ch9_sort/src/SortAlgorithm.cpp -o CMakeFiles/sort_algorithm.dir/src/SortAlgorithm.cpp.s

# Object files for target sort_algorithm
sort_algorithm_OBJECTS = \
"CMakeFiles/sort_algorithm.dir/src/main.cpp.o" \
"CMakeFiles/sort_algorithm.dir/src/SortAlgorithm.cpp.o"

# External object files for target sort_algorithm
sort_algorithm_EXTERNAL_OBJECTS =

../bin/sort_algorithm: CMakeFiles/sort_algorithm.dir/src/main.cpp.o
../bin/sort_algorithm: CMakeFiles/sort_algorithm.dir/src/SortAlgorithm.cpp.o
../bin/sort_algorithm: CMakeFiles/sort_algorithm.dir/build.make
../bin/sort_algorithm: CMakeFiles/sort_algorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ypc/xiaoc/code/data_structure/ch9_sort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/sort_algorithm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sort_algorithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sort_algorithm.dir/build: ../bin/sort_algorithm

.PHONY : CMakeFiles/sort_algorithm.dir/build

CMakeFiles/sort_algorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sort_algorithm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sort_algorithm.dir/clean

CMakeFiles/sort_algorithm.dir/depend:
	cd /home/ypc/xiaoc/code/data_structure/ch9_sort/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ypc/xiaoc/code/data_structure/ch9_sort /home/ypc/xiaoc/code/data_structure/ch9_sort /home/ypc/xiaoc/code/data_structure/ch9_sort/build /home/ypc/xiaoc/code/data_structure/ch9_sort/build /home/ypc/xiaoc/code/data_structure/ch9_sort/build/CMakeFiles/sort_algorithm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sort_algorithm.dir/depend

