/*
 * EigenTest.cpp
 *
 * Example of performing matrix multiplication with the Eigen matrix library.
 */
#include <cmath>
#include <iostream>
#include <Eigen/Dense>

int main() {
  // Rotate point (3, 0) around the origin 45 degrees
  Eigen::Matrix2d rot;
  rot << cos(M_PI/4), -sin(M_PI/4),
         sin(M_PI/4),  cos(M_PI/4);

  std::cout << "Rotation matrix is a " << rot.rows() << " by " << rot.cols()
    << std::endl << rot << std::endl << std::endl;

  // Column vector denoting point (3, 0)
  Eigen::Vector2d pt;
  pt << 3.0, 0.0;

  std::cout << "Point:\n" << pt << std::endl << std::endl;

  std::cout << "Rotating pt by 45 degrees:\n" << rot * pt << std::endl;
  return 0;
}
