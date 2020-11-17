#include "linear_interpolation.h"

#include <array>
#include <iostream>

int main() {
  const std::array<point<std::uint16_t>, 6U> points {
    {
      point<std::uint16_t> { 0U, 0U },
      point<std::uint16_t> { 10U, 44U },
      point<std::uint16_t> { 20U, 53U },
      point<std::uint16_t> { 30U, 28U },
      point<std::uint16_t> { 40U, 22U },
      point<std::uint16_t> { 50U, 47U }
    }
  };

  const std::uint16_t y = linear_interpolate(points.begin(), points.end(),
                                              std::uint16_t(15U),
                                              std::uint16_t(0U));

  std::cout << "Linear Interpolation with x = 15: is y: " << y << std::endl;

  return 0;
}
