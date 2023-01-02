/*
 * L1DT.cpp
 *
 * An example of computing the L1/Manhattan distance transform for a binary
 * input grid.
 */
#include <algorithm>
#include <iostream>
#include <vector>

// Typedefs
typedef std::vector<unsigned char> Row;
typedef std::vector<Row> Grid;

/**
 * Helper function to output a Grid.
 */
void PrintGrid(const Grid& grid) {
  for (size_t row = 0; row < grid.size(); ++row) {
    for (size_t col = 0; col < grid[row].size(); ++col) {
      std::cout << static_cast<int>(grid[row][col]) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

/**
 * Computes the Manhattan distance transform.
 */
void L1DT(const Grid& input, Grid* output) {
  if (output == nullptr) {
    std::cerr << "ERROR: output is NULL" << std::endl;
    return;
  }

  // Pass 1 - initialization
  for (size_t row = 0; row < output->size(); ++row) {
    for (size_t col = 0; col < (*output)[row].size(); ++col) {
      if (input[row][col] == 0)
        (*output)[row][col] = 255;
    }
  }

  // Pass 2 - Dynamic Programming Forward Pass
  for (size_t row = 1; row < output->size(); ++row) {
    for (size_t col = 1; col < (*output)[row].size(); ++col) {
      /*
       * Take the minimum of:
       * 1) output[row][col] (current value)
       * 2) output[row][col-1] + 1 (left neighbor + 1)
       * 3) output[row-1][col] + 1 (top neighbor + 1)
       */
      int val = (*output)[row][col];
      val = std::min(val, (*output)[row][col - 1] + 1);
      val = std::min(val, (*output)[row-1][col] + 1);

      (*output)[row][col] = val;
    }
  }

  // Pass 3 - Dynamic Programming Backward Pass
  for (int row = static_cast<int>(output->size()) - 1; row >= 0; --row) {
    for (int col = static_cast<int>((*output)[row].size()); col >= 0; --col) {
      /*
       * Take the minimum of:
       * 1) output[row][col] (current value)
       * 2) output[row][col+1] + 1 (right neighbor + 1 if applicable)
       * 3) output[row+1][col] + 1 (bottom neighbor + 1 if applicable)
       */
      int val = (*output)[row][col];
      if ((col + 1) < (*output)[row].size())
        val = std::min(val, (*output)[row][col + 1] + 1);
      if ((row + 1) < output->size())
        val = std::min(val, (*output)[row+1][col] + 1);

      (*output)[row][col] = val;
    }
  }
}

int main() {
  // Construct an input grid (in this case 5x5).  255 = occupied; 0 = empty.
  const Grid input = {{0, 0,   0, 0,   0},
                      {0, 255, 0, 0,   0},
                      {0, 0,   0, 0,   0},
                      {0, 0,   0, 255, 0},
                      {0, 0,   0, 0,   0}};

  // Output is the same size as the input grid
  Grid output = {{0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0}};

  std::cout << "Input grid: " << std::endl;
  PrintGrid(input);

  // Run Manhattan distance transform
  L1DT(input, &output);

  std::cout << "Output: " << std::endl;
  PrintGrid(output);

  return 0;
}
