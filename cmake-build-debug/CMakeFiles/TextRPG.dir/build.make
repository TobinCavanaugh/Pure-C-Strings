# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = C:\Users\tobin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\tobin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\tobin\Documents\_Repos\Pure-C-Strings

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tobin\Documents\_Repos\Pure-C-Strings\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TextRPG.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TextRPG.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TextRPG.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TextRPG.dir/flags.make

CMakeFiles/TextRPG.dir/main.c.obj: CMakeFiles/TextRPG.dir/flags.make
CMakeFiles/TextRPG.dir/main.c.obj: C:/Users/tobin/Documents/_Repos/Pure-C-Strings/main.c
CMakeFiles/TextRPG.dir/main.c.obj: CMakeFiles/TextRPG.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tobin\Documents\_Repos\Pure-C-Strings\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TextRPG.dir/main.c.obj"
	C:\Users\tobin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TextRPG.dir/main.c.obj -MF CMakeFiles\TextRPG.dir\main.c.obj.d -o CMakeFiles\TextRPG.dir\main.c.obj -c C:\Users\tobin\Documents\_Repos\Pure-C-Strings\main.c

CMakeFiles/TextRPG.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TextRPG.dir/main.c.i"
	C:\Users\tobin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\tobin\Documents\_Repos\Pure-C-Strings\main.c > CMakeFiles\TextRPG.dir\main.c.i

CMakeFiles/TextRPG.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TextRPG.dir/main.c.s"
	C:\Users\tobin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\tobin\Documents\_Repos\Pure-C-Strings\main.c -o CMakeFiles\TextRPG.dir\main.c.s

CMakeFiles/TextRPG.dir/PureCStrings.c.obj: CMakeFiles/TextRPG.dir/flags.make
CMakeFiles/TextRPG.dir/PureCStrings.c.obj: C:/Users/tobin/Documents/_Repos/Pure-C-Strings/PureCStrings.c
CMakeFiles/TextRPG.dir/PureCStrings.c.obj: CMakeFiles/TextRPG.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tobin\Documents\_Repos\Pure-C-Strings\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TextRPG.dir/PureCStrings.c.obj"
	C:\Users\tobin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TextRPG.dir/PureCStrings.c.obj -MF CMakeFiles\TextRPG.dir\PureCStrings.c.obj.d -o CMakeFiles\TextRPG.dir\PureCStrings.c.obj -c C:\Users\tobin\Documents\_Repos\Pure-C-Strings\PureCStrings.c

CMakeFiles/TextRPG.dir/PureCStrings.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TextRPG.dir/PureCStrings.c.i"
	C:\Users\tobin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\tobin\Documents\_Repos\Pure-C-Strings\PureCStrings.c > CMakeFiles\TextRPG.dir\PureCStrings.c.i

CMakeFiles/TextRPG.dir/PureCStrings.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TextRPG.dir/PureCStrings.c.s"
	C:\Users\tobin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\tobin\Documents\_Repos\Pure-C-Strings\PureCStrings.c -o CMakeFiles\TextRPG.dir\PureCStrings.c.s

CMakeFiles/TextRPG.dir/PureStringTests.c.obj: CMakeFiles/TextRPG.dir/flags.make
CMakeFiles/TextRPG.dir/PureStringTests.c.obj: C:/Users/tobin/Documents/_Repos/Pure-C-Strings/PureStringTests.c
CMakeFiles/TextRPG.dir/PureStringTests.c.obj: CMakeFiles/TextRPG.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tobin\Documents\_Repos\Pure-C-Strings\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TextRPG.dir/PureStringTests.c.obj"
	C:\Users\tobin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TextRPG.dir/PureStringTests.c.obj -MF CMakeFiles\TextRPG.dir\PureStringTests.c.obj.d -o CMakeFiles\TextRPG.dir\PureStringTests.c.obj -c C:\Users\tobin\Documents\_Repos\Pure-C-Strings\PureStringTests.c

CMakeFiles/TextRPG.dir/PureStringTests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TextRPG.dir/PureStringTests.c.i"
	C:\Users\tobin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\tobin\Documents\_Repos\Pure-C-Strings\PureStringTests.c > CMakeFiles\TextRPG.dir\PureStringTests.c.i

CMakeFiles/TextRPG.dir/PureStringTests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TextRPG.dir/PureStringTests.c.s"
	C:\Users\tobin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\tobin\Documents\_Repos\Pure-C-Strings\PureStringTests.c -o CMakeFiles\TextRPG.dir\PureStringTests.c.s

# Object files for target TextRPG
TextRPG_OBJECTS = \
"CMakeFiles/TextRPG.dir/main.c.obj" \
"CMakeFiles/TextRPG.dir/PureCStrings.c.obj" \
"CMakeFiles/TextRPG.dir/PureStringTests.c.obj"

# External object files for target TextRPG
TextRPG_EXTERNAL_OBJECTS =

TextRPG.exe: CMakeFiles/TextRPG.dir/main.c.obj
TextRPG.exe: CMakeFiles/TextRPG.dir/PureCStrings.c.obj
TextRPG.exe: CMakeFiles/TextRPG.dir/PureStringTests.c.obj
TextRPG.exe: CMakeFiles/TextRPG.dir/build.make
TextRPG.exe: CMakeFiles/TextRPG.dir/linkLibs.rsp
TextRPG.exe: CMakeFiles/TextRPG.dir/objects1.rsp
TextRPG.exe: CMakeFiles/TextRPG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\tobin\Documents\_Repos\Pure-C-Strings\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable TextRPG.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TextRPG.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TextRPG.dir/build: TextRPG.exe
.PHONY : CMakeFiles/TextRPG.dir/build

CMakeFiles/TextRPG.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TextRPG.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TextRPG.dir/clean

CMakeFiles/TextRPG.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tobin\Documents\_Repos\Pure-C-Strings C:\Users\tobin\Documents\_Repos\Pure-C-Strings C:\Users\tobin\Documents\_Repos\Pure-C-Strings\cmake-build-debug C:\Users\tobin\Documents\_Repos\Pure-C-Strings\cmake-build-debug C:\Users\tobin\Documents\_Repos\Pure-C-Strings\cmake-build-debug\CMakeFiles\TextRPG.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TextRPG.dir/depend

