/*
 * linear_interpolation.h
 *
 * Template implementation of linear interpolation.
 */
#ifndef _LINEAR_INTERPOLATION_H_
#define _LINEAR_INTERPOLATION_H_

#include <algorithm> // For std::lower_bound()

template<typename x_type,
         typename y_type = x_type>
class point {
public:
  x_type x;
  y_type y;

  point(const x_type &x_ = x_type(),
        const y_type &y_ = y_type()) : x(x_), y(y_) {}

  bool operator<(const point &other) const {
    return x < other.x;
  }
};

/*
 * This function performs linear interpolation.
 *
 * Given two known points (x0, y0) and (x1, y1), if we want to find the
 * corresponding y-value given an x-value such that x0 <= x <= y0, we can use
 * the following equation:
 *
 * y - y0   y1 - y0    y = y0 + (x - x0) * y1 - y0
 * ------ = ------- ->                     -------
 * x - x0   x1 - x0                        x1 - x0
 *
 * @param offset: allows users to specify a non-zero offset to be applied to the
 * linear interpolation.
 */
template<typename point_iterator,
         typename x_type,
         typename y_type = x_type>
y_type linear_interpolate(point_iterator pts_begin,
                          point_iterator pts_end,
                          const x_type &x,
                          const y_type &offset) {
  if (pts_begin == pts_end) {
    // There are no data points to interpolate
    return y_type();
  } else if ( (x <= pts_begin->x) || (pts_begin + 1U == pts_end)) {
    // We are beneath the lower x-range or there is only one data point to
    // interpolate.
    return pts_begin->y;
  } else if (x >= (pts_end - 1U)->x) {
    // We are above the upper x-range
    return (pts_end - 1U)->y;
  } else {
    /*
     * Perform the linear interpolation.  First find the point in the data
     * structure that is at least of value x, then perform the linear
     * interpolation equation as described above (std::lower_bound() uses a
     * binary search to efficiently find the lower bound).
     */
    point_iterator it = std::lower_bound(pts_begin, pts_end, point<x_type>(x));
    const x_type xn = (it - 1U)->x;
    const x_type delta_xn = it->x - xn;
    const x_type delta_x = x - xn;
    const y_type yn = (it - 1U)->y;
    const y_type delta_yn = it->y - yn;
    const y_type delta_y = (delta_x * delta_yn) / delta_xn;
    return (yn + delta_y) + offset;
  }
}
#endif

