/*
 * QuickSort.cpp
 *
 * Implementation of the quicksort algorithm.
 *
 * Bryant Pong
 * 12/26/20
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

template <typename T> std::vector<T> Quicksort(const std::vector<T> &vec) {
  // Base case: Vectors with 0 or 1 elements are already sorted
  if (vec.size() < 2)
    return vec;
  else {
    // Select a pivot point (a random pivot will make Quicksort n log n time)
    srand(time(NULL));
    const int pivotPoint = rand() % vec.size();
    const int pivot = vec[pivotPoint];

    // Divide remaining elements into elements greater or less than pivot
    std::vector<T> less, greater;
    for (size_t i = 0; i < vec.size(); ++i) {
      if (i == pivotPoint)
        continue;
      else if (vec[i] > pivot)
        greater.push_back(vec[i]);
      else
        less.push_back(vec[i]);
    }

    // Recursive calls to sort less and greater
    const std::vector<T> sortedLess = Quicksort<T>(less);
    const std::vector<T> sortedGreater = Quicksort<T>(greater);

    // Reconstruct sorted array
    std::vector<T> sorted(sortedLess);
    sorted.push_back(pivot);
    sorted.insert(sorted.end(), sortedGreater.begin(), sortedGreater.end());

    return sorted;
  }
}

int main(void) {
  const std::vector<int> unsorted {5, 4, 3, 2, 1};
  const std::vector<int> sorted = Quicksort<int>(unsorted);

  std::cout << "Sorted vector: " << std::endl;
  for (size_t i = 0; i < sorted.size(); ++i)
    std::cout << sorted[i] << " ";
  std::cout << std::endl;

  return 0;
}
