/*
 * blink_template.cpp
 *
 * Blinks an LED using the led_template.h header.
 */
#include <cstdint>
#include "led_template.h"
#include "mcal_reg.h"

namespace {
  // Create led_b5 at Port B, Bit-Position 5.
  const led_template<std::uint8_t, std::uint8_t,
                      mcal::reg::portb, mcal::reg::bval5> led_b5;
}

int main() {
  // Toggle led_b5 forever
  for(;;) {
    led_b5.toggle();
  }
  return 0;
}
