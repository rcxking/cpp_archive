# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

project(MPIPrograms)

# OpenMPI Definitions
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

# MPI Hello World
add_executable(MpiHelloWorld
  src/MpiHelloWorld.cpp
)
target_link_libraries(MpiHelloWorld
  ${MPI_LIBRARIES}
)
