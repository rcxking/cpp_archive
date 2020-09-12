# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

project(RealTimeCPP)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Blink Example
add_executable(Blink
  src/blink.cpp
)
target_compile_options(Blink PRIVATE -Wall -Wextra -pedantic)
target_include_directories(Blink PUBLIC
  inc
)

# Blink with LED Template
add_executable(BlinkTemplate
  src/blink_template.cpp
)
target_compile_options(BlinkTemplate PRIVATE -Wall -Wextra -pedantic)
target_include_directories(BlinkTemplate PUBLIC
  inc
)

# Factorial Template Metaprogramming Example
add_executable(TemplateFactorial
  src/template_factorial.cpp
)
target_compile_options(TemplateFactorial PRIVATE -Wall -Wextra -pedantic)

# Linear Interpolation
add_executable(LinearInterpolation
  src/linear_interpolation.cpp
)
target_compile_options(LinearInterpolation PRIVATE -Wall -Wextra -pedantic)
target_include_directories(LinearInterpolation PUBLIC
  inc
)

# Circular Buffer
add_executable(CB
  src/cb.cpp
)
target_compile_options(CB PRIVATE -Wall -Wextra -pedantic)
target_include_directories(CB PUBLIC
  inc
)
