# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jagen31/Robotics/HotTarget/HotTarget

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jagen31/Robotics/HotTarget/HotTarget

# Include any dependencies generated for this target.
include CMakeFiles/run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run.dir/flags.make

CMakeFiles/run.dir/run.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/run.cpp.o: run.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jagen31/Robotics/HotTarget/HotTarget/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/run.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/run.cpp.o -c /home/jagen31/Robotics/HotTarget/HotTarget/run.cpp

CMakeFiles/run.dir/run.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/run.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jagen31/Robotics/HotTarget/HotTarget/run.cpp > CMakeFiles/run.dir/run.cpp.i

CMakeFiles/run.dir/run.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/run.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jagen31/Robotics/HotTarget/HotTarget/run.cpp -o CMakeFiles/run.dir/run.cpp.s

CMakeFiles/run.dir/run.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/run.cpp.o.requires

CMakeFiles/run.dir/run.cpp.o.provides: CMakeFiles/run.dir/run.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/run.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/run.cpp.o.provides

CMakeFiles/run.dir/run.cpp.o.provides.build: CMakeFiles/run.dir/run.cpp.o

CMakeFiles/run.dir/ImageAnalyzer.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/ImageAnalyzer.cpp.o: ImageAnalyzer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jagen31/Robotics/HotTarget/HotTarget/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/ImageAnalyzer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/ImageAnalyzer.cpp.o -c /home/jagen31/Robotics/HotTarget/HotTarget/ImageAnalyzer.cpp

CMakeFiles/run.dir/ImageAnalyzer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/ImageAnalyzer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jagen31/Robotics/HotTarget/HotTarget/ImageAnalyzer.cpp > CMakeFiles/run.dir/ImageAnalyzer.cpp.i

CMakeFiles/run.dir/ImageAnalyzer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/ImageAnalyzer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jagen31/Robotics/HotTarget/HotTarget/ImageAnalyzer.cpp -o CMakeFiles/run.dir/ImageAnalyzer.cpp.s

CMakeFiles/run.dir/ImageAnalyzer.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/ImageAnalyzer.cpp.o.requires

CMakeFiles/run.dir/ImageAnalyzer.cpp.o.provides: CMakeFiles/run.dir/ImageAnalyzer.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/ImageAnalyzer.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/ImageAnalyzer.cpp.o.provides

CMakeFiles/run.dir/ImageAnalyzer.cpp.o.provides.build: CMakeFiles/run.dir/ImageAnalyzer.cpp.o

CMakeFiles/run.dir/ScoreAnalyzer.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/ScoreAnalyzer.cpp.o: ScoreAnalyzer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jagen31/Robotics/HotTarget/HotTarget/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/ScoreAnalyzer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/ScoreAnalyzer.cpp.o -c /home/jagen31/Robotics/HotTarget/HotTarget/ScoreAnalyzer.cpp

CMakeFiles/run.dir/ScoreAnalyzer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/ScoreAnalyzer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jagen31/Robotics/HotTarget/HotTarget/ScoreAnalyzer.cpp > CMakeFiles/run.dir/ScoreAnalyzer.cpp.i

CMakeFiles/run.dir/ScoreAnalyzer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/ScoreAnalyzer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jagen31/Robotics/HotTarget/HotTarget/ScoreAnalyzer.cpp -o CMakeFiles/run.dir/ScoreAnalyzer.cpp.s

CMakeFiles/run.dir/ScoreAnalyzer.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/ScoreAnalyzer.cpp.o.requires

CMakeFiles/run.dir/ScoreAnalyzer.cpp.o.provides: CMakeFiles/run.dir/ScoreAnalyzer.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/ScoreAnalyzer.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/ScoreAnalyzer.cpp.o.provides

CMakeFiles/run.dir/ScoreAnalyzer.cpp.o.provides.build: CMakeFiles/run.dir/ScoreAnalyzer.cpp.o

# Object files for target run
run_OBJECTS = \
"CMakeFiles/run.dir/run.cpp.o" \
"CMakeFiles/run.dir/ImageAnalyzer.cpp.o" \
"CMakeFiles/run.dir/ScoreAnalyzer.cpp.o"

# External object files for target run
run_EXTERNAL_OBJECTS =

run: CMakeFiles/run.dir/run.cpp.o
run: CMakeFiles/run.dir/ImageAnalyzer.cpp.o
run: CMakeFiles/run.dir/ScoreAnalyzer.cpp.o
run: CMakeFiles/run.dir/build.make
run: /usr/lib/libopencv_videostab.so.2.4.8
run: /usr/lib/libopencv_video.so.2.4.8
run: /usr/lib/libopencv_ts.a
run: /usr/lib/libopencv_superres.so.2.4.8
run: /usr/lib/libopencv_stitching.so.2.4.8
run: /usr/lib/libopencv_photo.so.2.4.8
run: /usr/lib/libopencv_ocl.so.2.4.8
run: /usr/lib/libopencv_objdetect.so.2.4.8
run: /usr/lib/libopencv_nonfree.so.2.4.8
run: /usr/lib/libopencv_ml.so.2.4.8
run: /usr/lib/libopencv_legacy.so.2.4.8
run: /usr/lib/libopencv_imgproc.so.2.4.8
run: /usr/lib/libopencv_highgui.so.2.4.8
run: /usr/lib/libopencv_gpu.so.2.4.8
run: /usr/lib/libopencv_flann.so.2.4.8
run: /usr/lib/libopencv_features2d.so.2.4.8
run: /usr/lib/libopencv_core.so.2.4.8
run: /usr/lib/libopencv_contrib.so.2.4.8
run: /usr/lib/libopencv_calib3d.so.2.4.8
run: /lib64/libGLU.so
run: /lib64/libGL.so
run: /lib64/libSM.so
run: /lib64/libICE.so
run: /lib64/libX11.so
run: /lib64/libXext.so
run: /usr/lib/libopencv_nonfree.so.2.4.8
run: /usr/lib/libopencv_ocl.so.2.4.8
run: /usr/lib/libopencv_gpu.so.2.4.8
run: /usr/lib/libopencv_photo.so.2.4.8
run: /usr/lib/libopencv_objdetect.so.2.4.8
run: /usr/lib/libopencv_legacy.so.2.4.8
run: /usr/lib/libopencv_video.so.2.4.8
run: /usr/lib/libopencv_ml.so.2.4.8
run: /usr/lib/libopencv_calib3d.so.2.4.8
run: /usr/lib/libopencv_features2d.so.2.4.8
run: /usr/lib/libopencv_highgui.so.2.4.8
run: /usr/lib/libopencv_imgproc.so.2.4.8
run: /usr/lib/libopencv_flann.so.2.4.8
run: /usr/lib/libopencv_core.so.2.4.8
run: CMakeFiles/run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run.dir/build: run
.PHONY : CMakeFiles/run.dir/build

CMakeFiles/run.dir/requires: CMakeFiles/run.dir/run.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/ImageAnalyzer.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/ScoreAnalyzer.cpp.o.requires
.PHONY : CMakeFiles/run.dir/requires

CMakeFiles/run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run.dir/clean

CMakeFiles/run.dir/depend:
	cd /home/jagen31/Robotics/HotTarget/HotTarget && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jagen31/Robotics/HotTarget/HotTarget /home/jagen31/Robotics/HotTarget/HotTarget /home/jagen31/Robotics/HotTarget/HotTarget /home/jagen31/Robotics/HotTarget/HotTarget /home/jagen31/Robotics/HotTarget/HotTarget/CMakeFiles/run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run.dir/depend
