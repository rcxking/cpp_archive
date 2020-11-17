#ifndef __LED_TEMPLATE_H__
#define __LED_TEMPLATE_H__
#include <cstdint>

typedef std::uint8_t port_type;
typedef std::uint8_t bval_type;

// Template parameters are known at compile time.
template<typename port_type,
         typename bval_type,
         const port_type port,
         const bval_type bval>
class led_template {
 public:
  led_template() {
    // Set the port pin value to low.
    *reinterpret_cast<volatile bval_type*>(port) &=
      static_cast<bval_type>(~bval);

    // Set the port pin direction to output.
    *reinterpret_cast<volatile bval_type*>(pdir) |= bval;
  }

  static void toggle() {
    // Toggle the LED.
    *reinterpret_cast<volatile bval_type*>(port) ^= bval;
  }

 private:
  static constexpr port_type pdir = port - 1U;
};
#endif
