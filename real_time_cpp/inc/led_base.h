/*
 * led_base.h
 */
class led_base {
public:
  // Derived classes provides its own version of toggle() and ~led_base.
  virtual void toggle() = 0; // Pure abstract
  /* Destructor should always be virtual so derived class calls its own
   * destructor when destroying an object via a base class pointer.
   */
  virtual ~led_base() {}     // Virtual destructor

  // Interface for querying the LED state.
  inline bool state_is_on() const { return is_on; }

protected:
  bool is_on;

  /*
   * A protected default constructor.  This prevents the default constructor
   * from being called except by classes derived from led_base.
   */
  led_base() : is_on(false) {}

private:
  // Private non-implemented copy constructor
  led_base(const led_base&) = delete;

  // Private non-implemented copy assignment operator
  const led_base &operator=(const led_base&) = delete;
};
