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
CMAKE_SOURCE_DIR = /Users/tkvitko/c/netology/cpp_async/thread_safe_queue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tkvitko/c/netology/cpp_async/thread_safe_queue

# Include any dependencies generated for this target.
include CMakeFiles/thread_safe_queue.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/thread_safe_queue.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/thread_safe_queue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/thread_safe_queue.dir/flags.make

CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.o: CMakeFiles/thread_safe_queue.dir/flags.make
CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.o: thread_safe_queue/main.cpp
CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.o: CMakeFiles/thread_safe_queue.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/tkvitko/c/netology/cpp_async/thread_safe_queue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.o -MF CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.o.d -o CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.o -c /Users/tkvitko/c/netology/cpp_async/thread_safe_queue/thread_safe_queue/main.cpp

CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tkvitko/c/netology/cpp_async/thread_safe_queue/thread_safe_queue/main.cpp > CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.i

CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tkvitko/c/netology/cpp_async/thread_safe_queue/thread_safe_queue/main.cpp -o CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.s

# Object files for target thread_safe_queue
thread_safe_queue_OBJECTS = \
"CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.o"

# External object files for target thread_safe_queue
thread_safe_queue_EXTERNAL_OBJECTS =

thread_safe_queue: CMakeFiles/thread_safe_queue.dir/thread_safe_queue/main.cpp.o
thread_safe_queue: CMakeFiles/thread_safe_queue.dir/build.make
thread_safe_queue: CMakeFiles/thread_safe_queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/tkvitko/c/netology/cpp_async/thread_safe_queue/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable thread_safe_queue"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thread_safe_queue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/thread_safe_queue.dir/build: thread_safe_queue
.PHONY : CMakeFiles/thread_safe_queue.dir/build

CMakeFiles/thread_safe_queue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/thread_safe_queue.dir/cmake_clean.cmake
.PHONY : CMakeFiles/thread_safe_queue.dir/clean

CMakeFiles/thread_safe_queue.dir/depend:
	cd /Users/tkvitko/c/netology/cpp_async/thread_safe_queue && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tkvitko/c/netology/cpp_async/thread_safe_queue /Users/tkvitko/c/netology/cpp_async/thread_safe_queue /Users/tkvitko/c/netology/cpp_async/thread_safe_queue /Users/tkvitko/c/netology/cpp_async/thread_safe_queue /Users/tkvitko/c/netology/cpp_async/thread_safe_queue/CMakeFiles/thread_safe_queue.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/thread_safe_queue.dir/depend

