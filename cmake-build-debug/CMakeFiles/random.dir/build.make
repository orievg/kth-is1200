# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Orievg\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.6494.38\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Orievg\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.6494.38\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Orievg\Documents\GitHub\kth-is1200

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Orievg\Documents\GitHub\kth-is1200\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/random.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/random.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/random.dir/flags.make

CMakeFiles/random.dir/project/test/random.c.obj: CMakeFiles/random.dir/flags.make
CMakeFiles/random.dir/project/test/random.c.obj: CMakeFiles/random.dir/includes_C.rsp
CMakeFiles/random.dir/project/test/random.c.obj: ../project/test/random.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Orievg\Documents\GitHub\kth-is1200\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/random.dir/project/test/random.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\random.dir\project\test\random.c.obj   -c C:\Users\Orievg\Documents\GitHub\kth-is1200\project\test\random.c

CMakeFiles/random.dir/project/test/random.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/random.dir/project/test/random.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Orievg\Documents\GitHub\kth-is1200\project\test\random.c > CMakeFiles\random.dir\project\test\random.c.i

CMakeFiles/random.dir/project/test/random.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/random.dir/project/test/random.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Orievg\Documents\GitHub\kth-is1200\project\test\random.c -o CMakeFiles\random.dir\project\test\random.c.s

# Object files for target random
random_OBJECTS = \
"CMakeFiles/random.dir/project/test/random.c.obj"

# External object files for target random
random_EXTERNAL_OBJECTS =

random.exe: CMakeFiles/random.dir/project/test/random.c.obj
random.exe: CMakeFiles/random.dir/build.make
random.exe: CMakeFiles/random.dir/linklibs.rsp
random.exe: CMakeFiles/random.dir/objects1.rsp
random.exe: CMakeFiles/random.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Orievg\Documents\GitHub\kth-is1200\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable random.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\random.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/random.dir/build: random.exe

.PHONY : CMakeFiles/random.dir/build

CMakeFiles/random.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\random.dir\cmake_clean.cmake
.PHONY : CMakeFiles/random.dir/clean

CMakeFiles/random.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Orievg\Documents\GitHub\kth-is1200 C:\Users\Orievg\Documents\GitHub\kth-is1200 C:\Users\Orievg\Documents\GitHub\kth-is1200\cmake-build-debug C:\Users\Orievg\Documents\GitHub\kth-is1200\cmake-build-debug C:\Users\Orievg\Documents\GitHub\kth-is1200\cmake-build-debug\CMakeFiles\random.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/random.dir/depend

