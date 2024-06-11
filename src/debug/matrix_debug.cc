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
#include <random>

void debug::PrintMatrix(const char *name, const S21Matrix& matrix) {
  std::cout << name << "[" << matrix.get_rows() << "][" << matrix.get_cols() << "]" << std::endl;

  for(int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      std::cout << matrix(i, j) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void debug::FillRandom(S21Matrix& matrix) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dis(-100.0, 100.0);

  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      matrix(i, j) = dis(gen);
    }
  }
}
