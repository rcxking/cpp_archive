#ifndef __MCAL_REG_H__
#define __MCAL_REG_H__
namespace mcal {
  // Compile-time constant register addresses
  namespace reg {
    /*
     * Values defined as const can be initialized at either compile-time or at
     * run-time.  Values defined with constexpr will be initialized at
     * compile-time only.
     */

    // The address of portb
    constexpr std::uint8_t portb = 0x25U;

    // The values of bit0 through bit7
    constexpr std::uint8_t bval0 = 1U;
    constexpr std::uint8_t bval1 = 1U << 1U;
    constexpr std::uint8_t bval2 = 1U << 2U;
    constexpr std::uint8_t bval3 = 1U << 3U;
    constexpr std::uint8_t bval4 = 1U << 4U;
    constexpr std::uint8_t bval5 = 1U << 5U;
    constexpr std::uint8_t bval6 = 1U << 6U;
    constexpr std::uint8_t bval7 = 1U << 7U;
  }
}
#endif
