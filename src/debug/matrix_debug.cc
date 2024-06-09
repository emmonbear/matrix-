/**
 * @file debug.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief 
 * @version 1.0
 * @date 2024-06-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "./matrix_debug.h"
#include <iostream>

void debug::PrintMatrix(const S21Matrix& matrix) {
  std::cout << "M[" << matrix.get_rows() << "][" << matrix.get_cols() << "]" << std::endl;

  for(int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      std::cout << matrix(i, j) << " ";
    }
    std::cout << std::endl;
  }
}
