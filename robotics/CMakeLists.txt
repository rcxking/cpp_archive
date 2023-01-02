# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

project(Robotics)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# L1/Manhattan Distance Transform
add_executable(L1DT
  src/L1DT.cpp
)

# Kinematics Unit Tests
#find_package(Catch2 REQUIRED)
#add_executable(KinematicTests
#  tests/kinematic_tests.cpp
#)
#target_link_libraries(KinematicTests Catch2::Catch2)
#include(CTest)
#include(Catch)
#catch_discover_tests(KinematicTests)
