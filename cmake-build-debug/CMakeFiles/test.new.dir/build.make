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
include CMakeFiles/test.new.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.new.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.new.dir/flags.make

CMakeFiles/test.new.dir/project/test/test.new.c.obj: CMakeFiles/test.new.dir/flags.make
CMakeFiles/test.new.dir/project/test/test.new.c.obj: CMakeFiles/test.new.dir/includes_C.rsp
CMakeFiles/test.new.dir/project/test/test.new.c.obj: ../project/test/test.new.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Orievg\Documents\GitHub\kth-is1200\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test.new.dir/project/test/test.new.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.new.dir\project\test\test.new.c.obj   -c C:\Users\Orievg\Documents\GitHub\kth-is1200\project\test\test.new.c

CMakeFiles/test.new.dir/project/test/test.new.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.new.dir/project/test/test.new.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Orievg\Documents\GitHub\kth-is1200\project\test\test.new.c > CMakeFiles\test.new.dir\project\test\test.new.c.i

CMakeFiles/test.new.dir/project/test/test.new.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.new.dir/project/test/test.new.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Orievg\Documents\GitHub\kth-is1200\project\test\test.new.c -o CMakeFiles\test.new.dir\project\test\test.new.c.s

# Object files for target test.new
test_new_OBJECTS = \
"CMakeFiles/test.new.dir/project/test/test.new.c.obj"

# External object files for target test.new
test_new_EXTERNAL_OBJECTS =

test.new.exe: CMakeFiles/test.new.dir/project/test/test.new.c.obj
test.new.exe: CMakeFiles/test.new.dir/build.make
test.new.exe: CMakeFiles/test.new.dir/linklibs.rsp
test.new.exe: CMakeFiles/test.new.dir/objects1.rsp
test.new.exe: CMakeFiles/test.new.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Orievg\Documents\GitHub\kth-is1200\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test.new.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test.new.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.new.dir/build: test.new.exe

.PHONY : CMakeFiles/test.new.dir/build

CMakeFiles/test.new.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test.new.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test.new.dir/clean

CMakeFiles/test.new.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Orievg\Documents\GitHub\kth-is1200 C:\Users\Orievg\Documents\GitHub\kth-is1200 C:\Users\Orievg\Documents\GitHub\kth-is1200\cmake-build-debug C:\Users\Orievg\Documents\GitHub\kth-is1200\cmake-build-debug C:\Users\Orievg\Documents\GitHub\kth-is1200\cmake-build-debug\CMakeFiles\test.new.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.new.dir/depend

