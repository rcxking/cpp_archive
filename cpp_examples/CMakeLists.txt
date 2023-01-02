# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

project(CPPExamples)

# Eigen matrix library
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# BacktrackCrash
add_executable(BacktraceCrash
  src/BacktraceCrash.cpp
)

# ChangeDP
add_executable(ChangeDP
  src/ChangeDP.cpp
)

# EigenTest
add_executable(EigenTest
  src/EigenTest.cpp
)
target_link_libraries(EigenTest Eigen3::Eigen)
