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

#include <algorithm>  // std::copy
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

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  AllocateMatrix();
  for (int i = 0; i < rows_; i++) {
    std::copy(other.matrix_[i], other.matrix_[i] + cols_, matrix_[i]);
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_{other.rows_}, cols_{other.cols_}, matrix_{other.matrix_} {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::out_of_range("Matrix index out of range");
  }
  return matrix_[i][j];
}

const double& S21Matrix::operator()(int i, int j) const {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::out_of_range("Matrix index out of range");
  }
  return matrix_[i][j];
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (std::abs(other(i, j) - (*this)(i, j)) > kEpsilon) {
        return false;
      }
    }
  }

  return true;
}

// int S21Matrix::get_cols() const noexcept { return cols_;}

// int S21Matrix::get_rows() const noexcept { return rows_;}
