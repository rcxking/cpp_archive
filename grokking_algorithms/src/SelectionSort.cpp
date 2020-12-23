/*
 * SelectionSort.cpp
 *
 * Implementation of selection sort for a vector of integers from smallest to
 * largest.
 *
 * Bryant Pong
 * 12/23/20
 */
#include <cstring>
#include <iostream>
#include <limits>
#include <vector>

/**
 * @brief Performs a selection sort on a vector of integers from smallest to
 * largest.
 */
std::vector<int> SelectionSort(const std::vector<int>& input) {
  std::vector<int> sorted;

  // Elements already selected
  bool *visited = new bool[input.size()];
  memset(visited, false, sizeof(bool) * input.size());

  for (size_t i = 0; i < input.size(); ++i) {
    // Find next smallest value
    int smallest = std::numeric_limits<int>::max();
    size_t smallestIdx = 0;
    for (size_t j = 0; j < input.size(); ++j) {
      if (!visited[j] && (input[j] < smallest)) {
        smallest = input[j];
        smallestIdx = j;
      }
    }

    std::cout << "Smallest value: " << smallest << " found at index: " <<
      smallestIdx << " for iteration: " << i << std::endl;
    sorted.push_back(smallest);
    visited[smallestIdx] = true;
  }

  delete [] visited;

  return sorted;
}

int main(void) {
  // Vector of unsorted integers
  std::vector<int> unsorted {5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5};

  const std::vector<int> sorted = SelectionSort(unsorted);

  std::cout << "Sorted vector: " << std::endl;
  for (size_t i = 0; i < sorted.size(); ++i)
    std::cout << sorted[i] << " ";
  std::cout << std::endl;

  return 0;
}
