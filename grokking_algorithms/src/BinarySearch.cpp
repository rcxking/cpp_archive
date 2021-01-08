/*
 * BinarySearch.cpp
 *
 * Implementation of binary search for an array of integers.
 *
 * Bryant Pong
 * 12/23/20
 */
#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief  Implementation of a binary search on an array of integers.
 */
bool BinarySearch(const std::vector<int>& searchArray, const int searchVal,
                    int &foundPos) {
  // Binary search range
  int low = 0;
  int high = searchArray.size() - 1;

  while (low <= high) {
    const int mid = (low + high) / 2;
    const int guess = searchArray[mid];

    if (guess == searchVal) {
      // Found value
      foundPos = mid;
      return true;
    } else if (guess < searchVal) {
      // Too low; update lower bound
      low = mid + 1;
    } else {
      // Too high; update upper bound
      high = mid - 1;
    }
  }

  return false;
}


int main(void) {
  // Search this array for specified values.
  const std::vector<int> searchArray {-5,-4,-3,-2,-1,0,1,2,3,4,5};

  int pos1, pos2, pos3;
  const bool found1 = BinarySearch(searchArray, 0, pos1);
  const bool found2 = BinarySearch(searchArray, 5, pos2);
  const bool notFound1 = BinarySearch(searchArray, 6, pos3);

  if (found1)
    std::cout << "Found 0 at position: " << pos1 << std::endl;
  else
    std::cout << "0 was not found" << std::endl;

  if (found2)
    std::cout << "Found 5 at position: " << pos2 << std::endl;
  else
    std::cout << "5 was not found" << std::endl;

  if (notFound1)
    std::cout << "Found 6 at position: " << pos3 << std::endl;
  else
    std::cout << "6 was not found" << std::endl;

  return 0;
}
