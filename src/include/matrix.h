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

#include <algorithm>  // std::copy
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

/**
 * @brief Class for working with matrices
 *
 * @details
 *
 * The class is implemented in accordance with the Google C++ Style Guide[1] and
 * C++ Core Guidelines[2].
 *
 * According to [1] the class definition usually starts with the public:
 * section, followed by protected:, then private:. Sections that remain empty
 * should be omitted.
 * Within each section, prefer grouping similar kinds of declarations together,
 * and prefer the following order:
 *  1. Types and type aliases (typedef, using, enum, nested structs and classes,
 * and friend types;
 *  2. (Optionally, for structs only) non-static data members;
 *  3. Static constants;
 *  4. Factory functions;
 *  5. Constructors and assignment operators;
 *  6. Destructor;
 *  7. All other functions (static and non-static member functions, and friend
 * functions);
 *  8. All other data members (static and non-static)
 *
 * Do not put large method definitions inline in the class definition. Usually,
 * only trivial or performance-critical, and very short, methods may be defined
 * inline. See Inline Functions for more details.
 */
class S21Matrix {
 public:
  // Constructors and assignment operators
  S21Matrix() noexcept;
  explicit S21Matrix(int n);
  S21Matrix(int n, int m);
  S21Matrix(std::string src) noexcept;
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);

  // Destructor
  ~S21Matrix() noexcept;

  // Operators
  double& operator()(int i, int j);
  const double& operator()(int i, int j) const;
  bool operator==(const S21Matrix& other) const;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*(const double num) const noexcept;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*=(const double num) noexcept;
  S21Matrix operator*=(const S21Matrix& other) noexcept;

  void set_rows(int rows);
  void set_cols(int cols);
  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const noexcept;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  /// @brief Get the _rows object
  /// @return int rows_
  inline int get_rows() const noexcept { return rows_; }

  /// @brief Get the _cols object
  /// @return int cols_
  inline int get_cols() const noexcept { return cols_; }

 private:
  double kEpsilon = 1e-7;

  int rows_{};
  int cols_{};  // C.45 (C++ Core Guidelines)
  double** matrix_{};

  void AllocateMatrix();
  void Free() noexcept;
  bool IsSquareMatrix() const;
  double LaplaceExpansion() const;
  S21Matrix GetMinor(int row, int col) const;
};

#endif  // SRC_INCLUDE_MATRIX_H_
