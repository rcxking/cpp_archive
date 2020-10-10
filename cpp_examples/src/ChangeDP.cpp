/*
 * ChangeDP.cpp
 *
 * Dynamic programming implementation of an algorithm used to find the minimum
 * number of coins needed to make a requested amount.
 */
#include <iostream>
#include <array>
#include <limits>

/*
 * The denominations of the coins to use.  For this example we will be using 1
 * cent, 2 cent, and 5 cent coins.
 */
constexpr std::array<int, 3> COINS = { 1, 2, 5 };

int MakeChange(const int total) {
  unsigned int numCoinsUsed[total + 1];
  numCoinsUsed[0] = 0;

  for (size_t i = 1; i <= total; ++i) {
    unsigned int minCoinsUsed = std::numeric_limits<unsigned int>::max();

    for (size_t j = 0; j < COINS.size(); ++j) {
      if (static_cast<int>(i - COINS[j]) < 0)
        continue;

      const int nextChoice = numCoinsUsed[i - COINS[j]] + 1;
      if (nextChoice < minCoinsUsed)
        minCoinsUsed = nextChoice;
    }
    numCoinsUsed[i] = minCoinsUsed;
  }

  return numCoinsUsed[total];
}

int main() {
  for (size_t i = 0; i <= 10; ++i) {
    std::cout << "MakeChange(" << i << "): " << MakeChange(i) << std::endl;
  }

  return 0;
}
