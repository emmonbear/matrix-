/**
 * @file matrix.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-06-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/matrix.h"

#include <iostream>

S21Matrix::S21Matrix() noexcept = default;

S21Matrix::S21Matrix(int n) : rows_{n}, cols_{n} {
  if (n < 0) {
    throw std::invalid_argument(
        "Matrix dimensions must be greater or equal than zero.");
  }

  AllocateMatrix();
}

S21Matrix::S21Matrix(int n, int m) : rows_{n}, cols_{m} {
  if (n < 0 || m < 0) {
    throw std::invalid_argument("Matrix dimensions must be positive");
  }
  AllocateMatrix();
}

void S21Matrix::AllocateMatrix() {
  matrix_ = new double*[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]{};
  }
}

S21Matrix::~S21Matrix() noexcept {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }

  delete[] matrix_;
}
// int S21Matrix::get_cols() const noexcept { return cols_;}

// int S21Matrix::get_rows() const noexcept { return rows_;}
