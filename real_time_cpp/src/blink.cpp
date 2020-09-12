/*
 * blink.cpp
 *
 * Example program of how to use C++ to blink an LED.
 * This code will not compile because certain headers do not exist.
 */
#include <cstdint>
// Header containing registers for microcontroller (does not exist)
#include "mcal_reg.h"

// Class for an LED object
class led {
 public:
  // Typedefs for convenience
  typedef std::uint8_t port_type;
  typedef std::uint8_t bval_type;

  // LED Constructor
  led(const port_type p, const bval_type b) :
    port(p), bval(b) {
    /*
     * Set port pin value to low BEFORE setting the port pin direction as an
     * output.  This is to prevent potential electrical spikes on the I/O pins.
     */
    *reinterpret_cast<volatile bval_type*>(port) &=
      static_cast<bval_type>(~bval);

    /*
     * Set the port pin direction to output.  Note that the address of the port
     * direction register is one less than the address of the port value
     * register.
     */
    const port_type pdir = port - 1U;
    *reinterpret_cast<volatile bval_type*>(pdir) |= bval;
  }

  // Toggle the LED via direct memory access
  void toggle() const {
    *reinterpret_cast<volatile bval_type*>(port) ^= bval;
  }

 private:
  /*
   * Register and pin number LED is assigned to.  const member variables must be
   * initialized in the constructor's initializer list.
   *
   * Member variables also need to be in the same order as they are declared,
   * because the compiler initializes them in that order.
   */
  const port_type port;
  const bval_type bval;
};

/*
 * This is an anonymous namespace; it limits the scope of anything inside to
 * within this file.  The equivalent of this is using C's static keyword.
 */
namespace {
  /*
   * Create led_b5 on Port B bit value 5.  This object is constructed using C++'s
   * uniform initialization syntax, so don't need to explicitly call the led's
   * constructor (introduced in C++11).
   */
  const led led_b5 {
    mcal::reg::portb,
    mcal::reg::bval5
  };
}

/*
 * Because no explicit return value is provided, the compiler will automatically
 * generate a return 0.
 */
int main() {
  // Toggle led_b5 in a loop forever
  for(;;) {
    led_b5.toggle();
  }
}
