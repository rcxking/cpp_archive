#ifndef __CIRCULAR_BUFFER_H__
#define __CIRCULAR_BUFFER_H__
/*
 * circular_buffer.h
 *
 * Template class implementation for a circular buffer.
 */
#include <cstdlib> // std::size_t
#include <algorithm> // std::fill, std::copy

template<typename T, const std::size_t N>
class circular_buffer {
public:
  typedef T value_type;
  typedef value_type* pointer;
  typedef const value_type* const_pointer;
  typedef std::size_t size_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;

  /**
   * @brief Constructor taking in a data type and an optional size.
   */
  circular_buffer(const T& value = value_type(),
                  const size_type count = size_type(0U)) :
                    in_ptr(buffer), out_ptr(buffer) {
    const size_type the_count = (std::min)(N, count);
    std::fill(in_ptr, in_ptr + the_count, value);
    in_ptr += the_count;
  }

  /**
   * @brief  Copy constructor
   */
  circular_buffer(const circular_buffer &other) :
                    in_ptr(other.in_ptr),
                    out_ptr(other.out_ptr) {
    std::copy(other.buffer,
              other.buffer + N,
              buffer);
  }

  /**
   * @brief  Assignment operator=
   */
  circular_buffer &operator=(const circular_buffer &other) {
    // Check for self-assignment
    if (this != &other) {
      in_ptr(other.in_ptr);
      out_ptr(other.out_ptr);
      std::copy(other.buffer, other.buffer + N, buffer);
    }
    return *this;
  }

  /**
   * @brief  Get the maximum number of elements this buffer can hold.
   */
  inline size_type capacity() const { return N; }

  /**
   * @brief  Checks if this buffer is empty.
   */
  inline bool empty() const { return (in_ptr == out_ptr); }

  size_type size() const {
    const bool is_wrap = (in_ptr < out_ptr);
    return size_type((is_wrap == false) ? size_type(in_ptr - out_ptr) :
      N - size_type(out_ptr - in_ptr));
  }

  /**
   * @brief  Removes all values in the buffer.
   */
  void clear() {
    in_ptr = buffer;
    out_ptr = buffer;
  }

  /**
   * @brief  Adds the specified value to the buffer.  If the buffer is at the
   * end, override the values starting at the beginning.
   */
  void in(const value_type value) {
    if (in_ptr >= (buffer + N)) {
      in_ptr = buffer;
    }

    *in_ptr = value;
    ++in_ptr;
  }

  value_type out() {
    if (out_ptr >= (buffer + N)) {
      out_ptr = buffer;
    }
    const value_type value = *out_ptr;
    ++out_ptr;
    return value;
  }

  reference front() {
    return ((out_ptr >= (buffer + N)) ? buffer[N - 1U] : *out_ptr);
  }

  const_reference front() const {
    return ((out_ptr >= (buffer + N)) ? buffer[N - 1U] : *out_ptr);
  }

  reference back() {
    return ((in_ptr >= (buffer + N)) ? buffer[N - 1U] : *in_ptr);
  }

  const_reference back() const {
    return ((in_ptr >= (buffer + N)) ? buffer[N - 1U] : *in_ptr);
  }

private:
  value_type buffer[N];
  pointer in_ptr;
  pointer out_ptr;
};
#endif
