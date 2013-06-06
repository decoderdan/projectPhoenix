cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

rosbuild_add_executable(sonar_scanner src/sonar_scanner/sonar_scanner.cpp)
rosbuild_add_executable(sonar_interface src/sonar_interface/sonar_interface.cpp)

#Sonar depends on serial_port library
target_link_libraries(sonar_interface serial_port)

#Scanner depends on the following
target_link_libraries(sonar_scanner glfw)
target_link_libraries(sonar_scanner GL)
target_link_libraries(sonar_scanner GLU)
target_link_libraries(sonar_scanner X11)
target_link_libraries(sonar_scanner pthread)
target_link_libraries(sonar_scanner m)
