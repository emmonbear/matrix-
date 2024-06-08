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

class S21Matrix {
 public:
  /// @brief Default constructor for the S21Matrix class.
  S21Matrix() noexcept;  // C.44: Prefer default constructors to be simple and
                         // non-throwing (C++ Core Guidelines)
                         // C.45: Don't define a default constructor that only
                         // initializes data members; use default member
                         // initializers instead (C++ Core Guidelines)

  /**
   * @brief Square matrix constructor
   *
   * @param n The number of rows and columns of the matrix.
   *
   * @throw std::invalid_argument exception description If n is less than 0.
   * @throw std::bad_alloc If it was not possible to allocate memory for the
   * S21Matrix.
   */
  explicit S21Matrix(int n);  // C.46: By default, declare single-argument
                              // constructors explicit (C++ Core Guidelines)
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
  S21Matrix(int n, int m);

  /**
   * @brief Destroy the S21Matrix object
   * 
   */
  ~S21Matrix() noexcept;  // C.37: Make destructors noexcept (C++ Core
                          // Guidelines)
                          // C.36: A destructor must not fail (C++ Core
                          // Guidelines)

  /**
   * @brief Get the _rows object
   * 
   * @return int rows_
   */
  inline int get_rows() const noexcept { return rows_; }

  /**
   * @brief Get the _cols object
   * 
   * @return int cols_
   */
  inline int get_cols() const noexcept { return cols_; }

 private:
  int rows_{}, cols_{};  // C.45 (C++ Core Guidelines)
  double **matrix_{};

  /**
   * @brief Allocate memory for a 2D matrix.
   *
   * @throw std::bad_alloc If it was not possible to allocate memory for the
   * S21Matrix.
   */
  void AllocateMatrix();
};

#endif  // SRC_INCLUDE_MATRIX_H_
