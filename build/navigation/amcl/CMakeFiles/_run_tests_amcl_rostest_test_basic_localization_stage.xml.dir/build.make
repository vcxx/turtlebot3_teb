# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vincy/vin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vincy/vin_ws/build

# Utility rule file for _run_tests_amcl_rostest_test_basic_localization_stage.xml.

# Include the progress variables for this target.
include navigation/amcl/CMakeFiles/_run_tests_amcl_rostest_test_basic_localization_stage.xml.dir/progress.make

navigation/amcl/CMakeFiles/_run_tests_amcl_rostest_test_basic_localization_stage.xml:
	cd /home/vincy/vin_ws/build/navigation/amcl && ../../catkin_generated/env_cached.sh /usr/bin/python /opt/ros/kinetic/share/catkin/cmake/test/run_tests.py /home/vincy/vin_ws/build/test_results/amcl/rostest-test_basic_localization_stage.xml "/opt/ros/kinetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/vincy/vin_ws/src/navigation/amcl --package=amcl --results-filename test_basic_localization_stage.xml --results-base-dir \"/home/vincy/vin_ws/build/test_results\" /home/vincy/vin_ws/src/navigation/amcl/test/basic_localization_stage.xml "

_run_tests_amcl_rostest_test_basic_localization_stage.xml: navigation/amcl/CMakeFiles/_run_tests_amcl_rostest_test_basic_localization_stage.xml
_run_tests_amcl_rostest_test_basic_localization_stage.xml: navigation/amcl/CMakeFiles/_run_tests_amcl_rostest_test_basic_localization_stage.xml.dir/build.make

.PHONY : _run_tests_amcl_rostest_test_basic_localization_stage.xml

# Rule to build all files generated by this target.
navigation/amcl/CMakeFiles/_run_tests_amcl_rostest_test_basic_localization_stage.xml.dir/build: _run_tests_amcl_rostest_test_basic_localization_stage.xml

.PHONY : navigation/amcl/CMakeFiles/_run_tests_amcl_rostest_test_basic_localization_stage.xml.dir/build

navigation/amcl/CMakeFiles/_run_tests_amcl_rostest_test_basic_localization_stage.xml.dir/clean:
	cd /home/vincy/vin_ws/build/navigation/amcl && $(CMAKE_COMMAND) -P CMakeFiles/_run_tests_amcl_rostest_test_basic_localization_stage.xml.dir/cmake_clean.cmake
.PHONY : navigation/amcl/CMakeFiles/_run_tests_amcl_rostest_test_basic_localization_stage.xml.dir/clean

navigation/amcl/CMakeFiles/_run_tests_amcl_rostest_test_basic_localization_stage.xml.dir/depend:
	cd /home/vincy/vin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vincy/vin_ws/src /home/vincy/vin_ws/src/navigation/amcl /home/vincy/vin_ws/build /home/vincy/vin_ws/build/navigation/amcl /home/vincy/vin_ws/build/navigation/amcl/CMakeFiles/_run_tests_amcl_rostest_test_basic_localization_stage.xml.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : navigation/amcl/CMakeFiles/_run_tests_amcl_rostest_test_basic_localization_stage.xml.dir/depend

