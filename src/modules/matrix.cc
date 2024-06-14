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
#include <string>

/**
 * @brief Default constructor for the S21Matrix class.
 *
 * @details
 *
 * C.44: Prefer default constructors to be simple and non-throwing (C++ Core
 * Guidelines) C.45: Don't define a default constructor that only initializes
 * data members; use default member initializers instead (C++ Core Guidelines)
 *
 */
S21Matrix::S21Matrix() noexcept = default;

/**
 * @brief Square matrix constructor
 *
 * @details
 *
 * C.46: By default, declare single-argument constructors explicit (C++ Core
 * Guidelines)
 *
 * @param n The number of rows and columns of the matrix.
 *
 * @throw std::invalid_argument exception description If n is less than 0.
 * @throw std::bad_alloc If it was not possible to allocate memory for the
 * S21Matrix.
 */
S21Matrix::S21Matrix(int n) : rows_{n}, cols_{n} {
  if (n < 0) {
    throw std::invalid_argument(
        "Matrix dimensions must be greater or equal than zero.");
  }

  AllocateMatrix();
}

/**
 * @brief Construct a new S21Matrix object.
 *
 * @param n The number of rows of the matrix.
 * @param m The number of cols of the matrix.
 *
 * @throw std::invalid_argument exception description If n is less than 0.
 * @throw std::bad_alloc If it was not possible to allocate memory for the
 * S21Matrix.
 */
S21Matrix::S21Matrix(int n, int m) : rows_{n}, cols_{m} {
  if (n < 0 || m < 0) {
    throw std::invalid_argument("Matrix dimensions must be positive");
  }
  AllocateMatrix();
}

/// @todo Добавить исключения
S21Matrix::S21Matrix(std::string src) {
  src.erase(std::remove(src.begin(), src.end(), ' '), src.end());

  std::stringstream ss(src);
  std::string item;
  std::vector<double> values;

  rows_ = 0;
  cols_ = 0;
  bool cnt_cols = true;

  while (std::getline(ss, item, ',')) {
    item.erase(std::remove(item.begin(), item.end(), '{'), item.end());
    item.erase(std::remove(item.begin(), item.end(), '}'), item.end());

    values.push_back(std::stod(item));
    if (cnt_cols) {
      ++cols_;
    }

    if (ss.peek() == '{') {
      ++rows_;
      cnt_cols = false;
    }
  }

  if (!item.empty() && item.find('}') == std::string::npos) {
    ++rows_;
  }
  AllocateMatrix();

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = values[i * cols_ + j];
    }
  }
}

/**
 * @brief Allocate memory for a 2D matrix.
 *
 * @throw std::bad_alloc If it was not possible to allocate memory for the
 * S21Matrix.
 */
void S21Matrix::AllocateMatrix() {
  matrix_ = new double*[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]{};
  }
}

/**
 * @brief Destroy the S21Matrix object
 *
 * @details
 *
 * C.37: Make destructors noexcept (C++ Core Guidelines)
 * C.36: A destructor must not fail (C++ Core Guidelines)
 */
S21Matrix::~S21Matrix() noexcept { Free(); }

/**
 * @brief Copy constructor of the S21Matrix class.
 *
 * @details
 *
 * Copying array elements is done using the std::copy method, as it is a bit
 * faster than element-by-element assignment. I tested it on the example of an
 * array of Matrix[10000][10000] dimension. The results are as follows: using
 * std::copy 6542 ms and element-by-element assignment 6801 ms
 *
 * @param other
 */
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

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (&other != this) {
    Free();
    rows_ = other.rows_;
    cols_ = other.cols_;
    AllocateMatrix();
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }

  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  if (this != &other) {
    Free();
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }

  return *this;
}

void S21Matrix::Free() noexcept {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      if (matrix_[i]) {
        delete[] matrix_[i];
        matrix_[i] = nullptr;
      }
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

/**
 * @brief A method for writeable indexing:
 *
 * @param i
 * @param j
 * @return double&
 *
 * @throw std::out_of_range
 */
double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::out_of_range("Matrix index out of range");
  }
  return matrix_[i][j];
}

/**
 * @brief A method for read-only indexing:
 *
 * @param i
 * @param j
 * @return const double&
 *
 * @throw std::out_of_range
 */
const double& S21Matrix::operator()(int i, int j) const {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::out_of_range("Matrix index out of range");
  }
  return matrix_[i][j];
}

/**
 * @brief Compare this matrix with another matrix for equality.
 *
 * @param other The matrix to compare with.
 *
 * @retval true If the matrices are equal.
 * @retval false If the matrices are not equal.
 */
bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix res{*this};
  res.SumMatrix(other);

  return res;
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);

  return (*this);
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix res{*this};
  res.SubMatrix(other);

  return res;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);

  return (*this);
}

S21Matrix S21Matrix::operator*(const double num) noexcept {
  MulNumber(num);

  return (*this);
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix res(*this);
  res.MulMatrix(other);

  return res;
}

/**
 * @brief Compare this matrix with another matrix for equality.
 *
 * @param other The matrix to compare with.
 *
 * @retval true If the matrices are equal.
 * @retval false If the matrices are not equal.
 */
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

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Matrix dimensions must match for addition.");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) += other(i, j);
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument(
        "Matrix dimensions must match for subtraction.");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) -= other(i, j);
    }
  }
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "The number of columns of the first matrix is not equal to the number "
        "of rows of the second matrix.");
  }

  S21Matrix res{rows_, other.cols_};
  for (int i = 0; i < res.rows_; i++) {
    for (int j = 0; j < res.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        res(i, j) += (*this)(i, k) * other(k, j);
      }
    }
  }

  *this = std::move(res);
}

S21Matrix S21Matrix::Transpose() const noexcept {
  S21Matrix tmp{cols_, rows_};

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      tmp.matrix_[j][i] = matrix_[i][j];
    }
  }

  return tmp;
}

double S21Matrix::Determinant() const {
  if (!this->IsSquareMatrix()) {
    throw std::invalid_argument(
        "Matrix must be square to calculate determinant.");
  }

  double res;

  if (rows_ == 1 && cols_ == 1) {
    res = **matrix_;
  } else {
    res = LaplaceExpansion();
  }

  return res;
}

bool S21Matrix::IsSquareMatrix() const { return rows_ == cols_; }

S21Matrix S21Matrix::CalcComplements() const {
  if (!this->IsSquareMatrix()) {
    throw std::invalid_argument(
        "Matrix must be square to calculate complements.");
  }
  S21Matrix res{rows_, cols_};

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix tmp{GetMinor(i, j)};
      res.matrix_[i][j] = tmp.Determinant() * std::pow(-1, i + j);
    }
  }

  return res;
}

double S21Matrix::LaplaceExpansion() const {
  double res = 0.;

  if (cols_ == 2) {
    res = ((*this)(0, 0) * (*this)(1, 1)) - ((*this)(1, 0) * (*this)(0, 1));
  } else {
    for (int i = 0; i < cols_; i++) {
      S21Matrix tmp{(*this).GetMinor(0, i)};
      res += std::pow(-1, i) * (*this)(0, i) * tmp.LaplaceExpansion();
    }
  }

  return res;
}

S21Matrix S21Matrix::GetMinor(int row, int col) const {
  S21Matrix res{rows_ - 1, cols_ - 1};

  for (int i = 0, i_tmp = 0; i < rows_; i++) {
    if (i == row) {
      continue;
    }

    for (int j = 0, j_tmp = 0; j < cols_; j++) {
      if (j == col) {
        continue;
      }

      res(i_tmp, j_tmp) = (*this)(i, j);
      j_tmp++;
    }
    i_tmp++;
  }

  return res;
}

S21Matrix S21Matrix::InverseMatrix() const {
  if (!IsSquareMatrix()) {
    throw std::invalid_argument(
        "Matrix must be square to calculate inverse matrix.");
  }

  double determinant = Determinant();

  if (std::abs(determinant) < kEpsilon) {
    throw std::invalid_argument("The determinant must not be equal to zero.");
  }

  return Transpose().CalcComplements() * (1. / determinant);
}
