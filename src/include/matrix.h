/**
 * @file matrix.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-06-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MATRIX_H_
#define SRC_INCLUDE_MATRIX_H_

#include <cmath>
#include <sstream>

/// @todo Отсортировать согласно кодстайлу
class S21Matrix {
 public:
  S21Matrix() noexcept;
  explicit S21Matrix(int n);
  S21Matrix(int n, int m);
  S21Matrix(std::string wolfram_notation);
  ~S21Matrix() noexcept;

  S21Matrix(const S21Matrix& other);

  S21Matrix(S21Matrix&& other) noexcept;

  /// @brief Get the _rows object
  /// @return int rows_
  inline int get_rows() const noexcept { return rows_; }

  /// @brief Get the _cols object
  /// @return int cols_
  inline int get_cols() const noexcept { return cols_; }

  double& operator()(int i, int j);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  const double& operator()(int i, int j) const;
  bool operator==(const S21Matrix& other) const;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*(const double num) noexcept;
  S21Matrix operator*(const S21Matrix& other) const;

  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const noexcept;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

 private:
  int rows_{}, cols_{};  // C.45 (C++ Core Guidelines)
  double** matrix_{};

  double kEpsilon = 1e-7;
  void AllocateMatrix();
  void Free() noexcept;
  bool IsSquareMatrix() const;
  double LaplaceExpansion() const;
  S21Matrix GetMinor(int row, int col) const;
};

#endif  // SRC_INCLUDE_MATRIX_H_
