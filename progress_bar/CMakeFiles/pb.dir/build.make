# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.28.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.28.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tkvitko/c/netology/cpp_async/progress_bar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tkvitko/c/netology/cpp_async/progress_bar

# Include any dependencies generated for this target.
include CMakeFiles/pb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pb.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pb.dir/flags.make

CMakeFiles/pb.dir/progress_bar/main.cpp.o: CMakeFiles/pb.dir/flags.make
CMakeFiles/pb.dir/progress_bar/main.cpp.o: progress_bar/main.cpp
CMakeFiles/pb.dir/progress_bar/main.cpp.o: CMakeFiles/pb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/tkvitko/c/netology/cpp_async/progress_bar/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pb.dir/progress_bar/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pb.dir/progress_bar/main.cpp.o -MF CMakeFiles/pb.dir/progress_bar/main.cpp.o.d -o CMakeFiles/pb.dir/progress_bar/main.cpp.o -c /Users/tkvitko/c/netology/cpp_async/progress_bar/progress_bar/main.cpp

CMakeFiles/pb.dir/progress_bar/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pb.dir/progress_bar/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tkvitko/c/netology/cpp_async/progress_bar/progress_bar/main.cpp > CMakeFiles/pb.dir/progress_bar/main.cpp.i

CMakeFiles/pb.dir/progress_bar/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pb.dir/progress_bar/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tkvitko/c/netology/cpp_async/progress_bar/progress_bar/main.cpp -o CMakeFiles/pb.dir/progress_bar/main.cpp.s

# Object files for target pb
pb_OBJECTS = \
"CMakeFiles/pb.dir/progress_bar/main.cpp.o"

# External object files for target pb
pb_EXTERNAL_OBJECTS =

pb: CMakeFiles/pb.dir/progress_bar/main.cpp.o
pb: CMakeFiles/pb.dir/build.make
pb: CMakeFiles/pb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/tkvitko/c/netology/cpp_async/progress_bar/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pb.dir/build: pb
.PHONY : CMakeFiles/pb.dir/build

CMakeFiles/pb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pb.dir/clean

CMakeFiles/pb.dir/depend:
	cd /Users/tkvitko/c/netology/cpp_async/progress_bar && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tkvitko/c/netology/cpp_async/progress_bar /Users/tkvitko/c/netology/cpp_async/progress_bar /Users/tkvitko/c/netology/cpp_async/progress_bar /Users/tkvitko/c/netology/cpp_async/progress_bar /Users/tkvitko/c/netology/cpp_async/progress_bar/CMakeFiles/pb.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pb.dir/depend

