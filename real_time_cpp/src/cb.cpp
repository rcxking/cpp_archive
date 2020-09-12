/*
 * cb.cpp
 *
 * Test program to exercise the circular_buffer class defined in
 * circular_buffer.h.
 */
#include "circular_buffer.h"
#include <iostream>

// The circular buffer will hold up to 4 elements
typedef circular_buffer<std::uint8_t, 4U> buffer_type;

int main() {
  // Create a circular buffer holding up to 4 bytes
  buffer_type buffer;

  // Insert 3 bytes into the buffer
  buffer.in(1U);
  buffer.in(2U);
  buffer.in(3U);

  // Request buffer size
  const buffer_type::size_type count = buffer.size();
  std::cout << "Buffer size is: " << count << std::endl;

  // Check if buffer is empty
  const bool is_empty = buffer.empty();
  std::cout << "Buffer empty?: " << is_empty << std::endl;

  // Get first element
  const buffer_type::value_type value = buffer.out();
  std::cout << "First element: " << value << std::endl;

  // Check buffer size
  std::cout << "Buffer size is now: " << buffer.size() << std::endl;

  return 0;
}
