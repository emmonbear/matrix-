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
  S21Matrix(const S21Matrix& other);

  S21Matrix(S21Matrix&& other) noexcept;
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

  /**
   * @brief A method for writeable indexing:
   *
   * @param i
   * @param j
   * @return double&
   *
   * @throw std::out_of_range
   */
  double& operator()(int i, int j);

  /**
   * @brief A method for read-only indexing:
   *
   * @param i
   * @param j
   * @return const double&
   *
   * @throw std::out_of_range
   */
  const double& operator()(int i, int j) const;

  bool operator==(const S21Matrix& other) const;

  bool EqMatrix(const S21Matrix& other) const;

 private:
  int rows_{}, cols_{};  // C.45 (C++ Core Guidelines)
  double** matrix_{};

  double kEpsilon = 1e-7;
  /**
   * @brief Allocate memory for a 2D matrix.
   *
   * @throw std::bad_alloc If it was not possible to allocate memory for the
   * S21Matrix.
   */
  void AllocateMatrix();
};

#endif  // SRC_INCLUDE_MATRIX_H_
