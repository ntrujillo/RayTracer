# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.24.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.24.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ntrujillo/Classes/CSCE_441/assignment_05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ntrujillo/Classes/CSCE_441/assignment_05/build

# Include any dependencies generated for this target.
include CMakeFiles/ray.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ray.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ray.dir/flags.make

CMakeFiles/ray.dir/src/BVH.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/BVH.cpp.o: /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/BVH.cpp
CMakeFiles/ray.dir/src/BVH.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ntrujillo/Classes/CSCE_441/assignment_05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ray.dir/src/BVH.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/BVH.cpp.o -MF CMakeFiles/ray.dir/src/BVH.cpp.o.d -o CMakeFiles/ray.dir/src/BVH.cpp.o -c /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/BVH.cpp

CMakeFiles/ray.dir/src/BVH.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/BVH.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/BVH.cpp > CMakeFiles/ray.dir/src/BVH.cpp.i

CMakeFiles/ray.dir/src/BVH.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/BVH.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/BVH.cpp -o CMakeFiles/ray.dir/src/BVH.cpp.s

CMakeFiles/ray.dir/src/BVHtree.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/BVHtree.cpp.o: /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/BVHtree.cpp
CMakeFiles/ray.dir/src/BVHtree.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ntrujillo/Classes/CSCE_441/assignment_05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ray.dir/src/BVHtree.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/BVHtree.cpp.o -MF CMakeFiles/ray.dir/src/BVHtree.cpp.o.d -o CMakeFiles/ray.dir/src/BVHtree.cpp.o -c /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/BVHtree.cpp

CMakeFiles/ray.dir/src/BVHtree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/BVHtree.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/BVHtree.cpp > CMakeFiles/ray.dir/src/BVHtree.cpp.i

CMakeFiles/ray.dir/src/BVHtree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/BVHtree.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/BVHtree.cpp -o CMakeFiles/ray.dir/src/BVHtree.cpp.s

CMakeFiles/ray.dir/src/Camera.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Camera.cpp.o: /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Camera.cpp
CMakeFiles/ray.dir/src/Camera.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ntrujillo/Classes/CSCE_441/assignment_05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ray.dir/src/Camera.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Camera.cpp.o -MF CMakeFiles/ray.dir/src/Camera.cpp.o.d -o CMakeFiles/ray.dir/src/Camera.cpp.o -c /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Camera.cpp

CMakeFiles/ray.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Camera.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Camera.cpp > CMakeFiles/ray.dir/src/Camera.cpp.i

CMakeFiles/ray.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Camera.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Camera.cpp -o CMakeFiles/ray.dir/src/Camera.cpp.s

CMakeFiles/ray.dir/src/Light.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Light.cpp.o: /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Light.cpp
CMakeFiles/ray.dir/src/Light.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ntrujillo/Classes/CSCE_441/assignment_05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ray.dir/src/Light.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Light.cpp.o -MF CMakeFiles/ray.dir/src/Light.cpp.o.d -o CMakeFiles/ray.dir/src/Light.cpp.o -c /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Light.cpp

CMakeFiles/ray.dir/src/Light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Light.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Light.cpp > CMakeFiles/ray.dir/src/Light.cpp.i

CMakeFiles/ray.dir/src/Light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Light.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Light.cpp -o CMakeFiles/ray.dir/src/Light.cpp.s

CMakeFiles/ray.dir/src/Plane.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Plane.cpp.o: /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Plane.cpp
CMakeFiles/ray.dir/src/Plane.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ntrujillo/Classes/CSCE_441/assignment_05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ray.dir/src/Plane.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Plane.cpp.o -MF CMakeFiles/ray.dir/src/Plane.cpp.o.d -o CMakeFiles/ray.dir/src/Plane.cpp.o -c /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Plane.cpp

CMakeFiles/ray.dir/src/Plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Plane.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Plane.cpp > CMakeFiles/ray.dir/src/Plane.cpp.i

CMakeFiles/ray.dir/src/Plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Plane.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Plane.cpp -o CMakeFiles/ray.dir/src/Plane.cpp.s

CMakeFiles/ray.dir/src/Scene.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Scene.cpp.o: /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Scene.cpp
CMakeFiles/ray.dir/src/Scene.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ntrujillo/Classes/CSCE_441/assignment_05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ray.dir/src/Scene.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Scene.cpp.o -MF CMakeFiles/ray.dir/src/Scene.cpp.o.d -o CMakeFiles/ray.dir/src/Scene.cpp.o -c /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Scene.cpp

CMakeFiles/ray.dir/src/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Scene.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Scene.cpp > CMakeFiles/ray.dir/src/Scene.cpp.i

CMakeFiles/ray.dir/src/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Scene.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Scene.cpp -o CMakeFiles/ray.dir/src/Scene.cpp.s

CMakeFiles/ray.dir/src/Shape.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Shape.cpp.o: /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Shape.cpp
CMakeFiles/ray.dir/src/Shape.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ntrujillo/Classes/CSCE_441/assignment_05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ray.dir/src/Shape.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Shape.cpp.o -MF CMakeFiles/ray.dir/src/Shape.cpp.o.d -o CMakeFiles/ray.dir/src/Shape.cpp.o -c /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Shape.cpp

CMakeFiles/ray.dir/src/Shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Shape.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Shape.cpp > CMakeFiles/ray.dir/src/Shape.cpp.i

CMakeFiles/ray.dir/src/Shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Shape.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Shape.cpp -o CMakeFiles/ray.dir/src/Shape.cpp.s

CMakeFiles/ray.dir/src/Sphere.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Sphere.cpp.o: /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Sphere.cpp
CMakeFiles/ray.dir/src/Sphere.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ntrujillo/Classes/CSCE_441/assignment_05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ray.dir/src/Sphere.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Sphere.cpp.o -MF CMakeFiles/ray.dir/src/Sphere.cpp.o.d -o CMakeFiles/ray.dir/src/Sphere.cpp.o -c /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Sphere.cpp

CMakeFiles/ray.dir/src/Sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Sphere.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Sphere.cpp > CMakeFiles/ray.dir/src/Sphere.cpp.i

CMakeFiles/ray.dir/src/Sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Sphere.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Sphere.cpp -o CMakeFiles/ray.dir/src/Sphere.cpp.s

CMakeFiles/ray.dir/src/Triangle.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Triangle.cpp.o: /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Triangle.cpp
CMakeFiles/ray.dir/src/Triangle.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ntrujillo/Classes/CSCE_441/assignment_05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ray.dir/src/Triangle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Triangle.cpp.o -MF CMakeFiles/ray.dir/src/Triangle.cpp.o.d -o CMakeFiles/ray.dir/src/Triangle.cpp.o -c /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Triangle.cpp

CMakeFiles/ray.dir/src/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Triangle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Triangle.cpp > CMakeFiles/ray.dir/src/Triangle.cpp.i

CMakeFiles/ray.dir/src/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Triangle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/Triangle.cpp -o CMakeFiles/ray.dir/src/Triangle.cpp.s

CMakeFiles/ray.dir/src/main.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/main.cpp.o: /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/main.cpp
CMakeFiles/ray.dir/src/main.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ntrujillo/Classes/CSCE_441/assignment_05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ray.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/main.cpp.o -MF CMakeFiles/ray.dir/src/main.cpp.o.d -o CMakeFiles/ray.dir/src/main.cpp.o -c /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/main.cpp

CMakeFiles/ray.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/main.cpp > CMakeFiles/ray.dir/src/main.cpp.i

CMakeFiles/ray.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ntrujillo/Classes/CSCE_441/assignment_05/src/main.cpp -o CMakeFiles/ray.dir/src/main.cpp.s

# Object files for target ray
ray_OBJECTS = \
"CMakeFiles/ray.dir/src/BVH.cpp.o" \
"CMakeFiles/ray.dir/src/BVHtree.cpp.o" \
"CMakeFiles/ray.dir/src/Camera.cpp.o" \
"CMakeFiles/ray.dir/src/Light.cpp.o" \
"CMakeFiles/ray.dir/src/Plane.cpp.o" \
"CMakeFiles/ray.dir/src/Scene.cpp.o" \
"CMakeFiles/ray.dir/src/Shape.cpp.o" \
"CMakeFiles/ray.dir/src/Sphere.cpp.o" \
"CMakeFiles/ray.dir/src/Triangle.cpp.o" \
"CMakeFiles/ray.dir/src/main.cpp.o"

# External object files for target ray
ray_EXTERNAL_OBJECTS =

ray: CMakeFiles/ray.dir/src/BVH.cpp.o
ray: CMakeFiles/ray.dir/src/BVHtree.cpp.o
ray: CMakeFiles/ray.dir/src/Camera.cpp.o
ray: CMakeFiles/ray.dir/src/Light.cpp.o
ray: CMakeFiles/ray.dir/src/Plane.cpp.o
ray: CMakeFiles/ray.dir/src/Scene.cpp.o
ray: CMakeFiles/ray.dir/src/Shape.cpp.o
ray: CMakeFiles/ray.dir/src/Sphere.cpp.o
ray: CMakeFiles/ray.dir/src/Triangle.cpp.o
ray: CMakeFiles/ray.dir/src/main.cpp.o
ray: CMakeFiles/ray.dir/build.make
ray: /Users/ntrujillo/Classes/CSCE_441/glfw/release/src/libglfw3.a
ray: /Users/ntrujillo/Classes/CSCE_441/glew/lib/libGLEW.a
ray: CMakeFiles/ray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ntrujillo/Classes/CSCE_441/assignment_05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable ray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ray.dir/build: ray
.PHONY : CMakeFiles/ray.dir/build

CMakeFiles/ray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ray.dir/clean

CMakeFiles/ray.dir/depend:
	cd /Users/ntrujillo/Classes/CSCE_441/assignment_05/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ntrujillo/Classes/CSCE_441/assignment_05 /Users/ntrujillo/Classes/CSCE_441/assignment_05 /Users/ntrujillo/Classes/CSCE_441/assignment_05/build /Users/ntrujillo/Classes/CSCE_441/assignment_05/build /Users/ntrujillo/Classes/CSCE_441/assignment_05/build/CMakeFiles/ray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ray.dir/depend

