# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

project(GrokkingAlgorithms)

# Binary Search
add_executable(BinarySearch
  src/BinarySearch.cpp
)

# Selection Sort
add_executable(SelectionSort
  src/SelectionSort.cpp
)

# Quick Sort
add_executable(QuickSort
  src/QuickSort.cpp
)

# Breadth-First Search
add_executable(BreadthFirstSearch
  src/BreadthFirstSearch.cpp
)

# Dijkstra's
add_executable(Dijkstras
  src/Dijkstras.cpp
)

# Radio Stations Set Covering
add_executable(SetCovering
  src/SetCovering.cpp
)
