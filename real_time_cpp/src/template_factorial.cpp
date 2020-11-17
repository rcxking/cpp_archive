/*
 * template_factorial.cpp
 *
 * Example of using template metaprogramming to compute the factorial value
 * of an unsigned integer at compile time.
 */
#include <iostream>

/*
 * At compile time, the compiler will call this template specialization without
 * producing any intermediate code to evaluate the factorial.
 */
template<const std::uint32_t N>
struct factorial
{
  // Multiple N * (N - 1U) with template recursion
  static constexpr std::uint32_t value = N * factorial<N - 1U>::value;
};

/*
 * Base case.
 */
template<>
struct factorial<0U>
{
  // Zeroth specialization terminates the recursion.
  static constexpr std::uint32_t value = 1U;
};

int main() {
  // Compute factorials by passing in the argument as a template parameter
  constexpr std::uint32_t fact5 = factorial<5U>::value;
  std::cout << "fact5: " << fact5 << std::endl;

  return 0;
}
