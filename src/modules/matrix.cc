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

/**
 * @brief Default constructor for the S21Matrix class.
 *
 * @details
 *
 * C.44: Prefer default constructors to be simple and non-throwing[2]
 * C.45: Don't define a default constructor that only initializes
 * data members; use default member initializers instead[2]
 *
 */
S21Matrix::S21Matrix() noexcept = default;

/**
 * @brief Square matrix constructor
 *
 * @details
 *
 * C.46: By default, declare single-argument constructors explicit[2]
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
 */
S21Matrix::S21Matrix(int n, int m) : rows_{n}, cols_{m} {
  if (n < 0 || m < 0) {
    throw std::invalid_argument("Matrix dimensions must be positive");
  }
  AllocateMatrix();
}

/**
 * @brief Constructor that creates an object of class S21Matrix from a string,
 * in Wolfram Language code format.
 *
 * @details
 *
 * The data constructor is designed to simplify the testing of class methods.
 * The record form is a string with the following format: {{1, 2, 3}, {4, 5, 6},
 * {7, 8, 9}}. This will create a 3x3 two-dimensional array: 1 2 3 4 5 6 7 8 9
 *
 * I did not process exceptions, because this process is very tedious, and I
 * spent a lot of time on writing the algorithm.
 *
 */
S21Matrix::S21Matrix(std::string src) noexcept {
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

/**
 * @brief Move constructor for S21Matrix.
 *
 * @details
 *
 * This constructor initializes an S21Matrix object by transferring ownership of
 * the data from another S21Matrix object (`other`). The `other` object is left
 * in a valid but unspecified state, typically with its internal pointers set to
 * nullptr and sizes set to zero.
 *
 * @param other An rvalue reference to another S21Matrix object to be moved.
 */
S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_{other.rows_}, cols_{other.cols_}, matrix_{other.matrix_} {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

/**
 * @brief Copy assignment operator for S21Matrix.
 *
 * @details
 *
 * This operator assigns the contents of another S21Matrix object (`other`) to
 * this object by creating a deep copy of the data. If the current object
 * already contains data, it is freed before copying the new data.
 *
 * @param other A constant reference to another S21Matrix object to be copied.
 * @return A reference to the current S21Matrix object.
 */
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

/**
 * @brief Move assignment operator for S21Matrix.
 *
 * @details
 *
 * This operator assigns the contents of another S21Matrix object (`other`) to
 * this object by transferring ownership of the data. The `other` object is left
 * in a valid but unspecified state, typically with its internal pointers set to
 * nullptr and sizes set to zero.
 *
 * @param other An rvalue reference to another S21Matrix object to be moved.
 * @return A reference to the current S21Matrix object.
 */
S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  if (this != &other) {
    Free();
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }

  return *this;
}

/**
 * @brief Destructor for S21Matrix.
 *
 * @details
 *
 * This destructor frees the dynamically allocated memory used by the matrix.
 * It ensures that all resources are properly released when the S21Matrix object
 * goes out of scope.
 * C.37: Make destructors noexcept[2]
 * C.36: A destructor must not fail[2]
 */
S21Matrix::~S21Matrix() noexcept { Free(); }

/**
 * @brief Overloaded function call operator for element access (non-const).
 *
 * @details
 *
 * This operator allows access to matrix elements using the (i, j) syntax.
 * It performs bounds checking and throws an exception if the indices are out of
 * range.
 *
 * @param i The row index.
 * @param j The column index.
 * @return A reference to the element at the specified (i, j) position.
 * @throw std::out_of_range if the indices are out of range.
 */
double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::out_of_range("Matrix index out of range");
  }
  return matrix_[i][j];
}

/**
 * @brief Overloaded function call operator for element access (const).
 *
 * @details
 *
 * This operator allows access to matrix elements using the (i, j) syntax in
 * const contexts. It performs bounds checking and throws an exception if the
 * indices are out of range.
 *
 * @param i The row index.
 * @param j The column index.
 * @return A const reference to the element at the specified (i, j) position.
 * @throw std::out_of_range if the indices are out of range.
 */
const double& S21Matrix::operator()(int i, int j) const {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::out_of_range("Matrix index out of range");
  }
  return matrix_[i][j];
}

/**
 * @brief Equality operator for S21Matrix.
 *
 * @details
 *
 * This operator checks if two S21Matrix objects are equal by comparing their
 * elements. It utilizes the EqMatrix function to perform the comparison.
 *
 * @param other A constant reference to another S21Matrix object to be compared.
 * @return True if the matrices are equal, false otherwise.
 */
bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

/**
 * @brief Addition operator for S21Matrix.
 *
 * @details
 *
 * This operator returns a new S21Matrix that is the result of adding another
 * S21Matrix object (`other`) to the current S21Matrix object. It utilizes the
 * SumMatrix function to perform the addition.
 *
 * @param other A constant reference to another S21Matrix object to be added.
 * @return A new S21Matrix object representing the sum of the two matrices.
 */
S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix res{*this};
  res.SumMatrix(other);

  return res;
}

/**
 * @brief Addition assignment operator for S21Matrix.
 *
 * @details
 *
 * This operator adds another S21Matrix object (`other`) to the current
 * S21Matrix object and modifies the current object. It utilizes the SumMatrix
 * function to perform the addition.
 *
 * @param other A constant reference to another S21Matrix object to be added.
 * @return A reference to the current S21Matrix object after addition.
 */
S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);

  return (*this);
}

/**
 * @brief Subtraction operator for S21Matrix.
 *
 * @details
 *
 * This operator returns a new S21Matrix that is the result of subtracting
 * another S21Matrix object (`other`) from the current S21Matrix object. It
 * utilizes the SubMatrix function to perform the subtraction.
 *
 * @param other A constant reference to another S21Matrix object to be
 * subtracted.
 * @return A new S21Matrix object representing the result of the subtraction.
 */
S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix res{*this};
  res.SubMatrix(other);

  return res;
}

/**
 * @brief Subtraction assignment operator for S21Matrix.
 *
 * @details
 *
 * This operator subtracts another S21Matrix object (`other`) from the current
 * S21Matrix object and modifies the current object. It utilizes the SubMatrix
 * function to perform the subtraction.
 *
 * @param other A constant reference to another S21Matrix object to be
 * subtracted.
 * @return A reference to the current S21Matrix object after subtraction.
 */
S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);

  return (*this);
}

/**
 * @brief Scalar multiplication operator for S21Matrix.
 *
 * @details
 *
 * This operator returns a new S21Matrix that is the result of multiplying the
 * current S21Matrix object by a scalar value (`num`). It utilizes the MulNumber
 * function to perform the scalar multiplication.
 *
 * @param num The scalar value to multiply the matrix by.
 * @return A new S21Matrix object representing the result of the scalar
 * multiplication.
 */
S21Matrix S21Matrix::operator*(const double num) const noexcept {
  S21Matrix tmp{*this};

  tmp.MulNumber(num);

  return tmp;
}

/**
 * @brief Matrix multiplication operator for S21Matrix.
 *
 * @details
 *
 * This operator returns a new S21Matrix that is the result of multiplying the
 * current S21Matrix object by another S21Matrix object (`other`). It utilizes
 * the MulMatrix function to perform the matrix multiplication.
 *
 * @param other A constant reference to another S21Matrix object to be
 * multiplied.
 * @return A new S21Matrix object representing the result of the matrix
 * multiplication.
 */
S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix res(*this);
  res.MulMatrix(other);

  return res;
}

/**
 * @brief Scalar multiplication assignment operator for S21Matrix.
 *
 * @details
 *
 * This operator multiplies the current S21Matrix object by a scalar value
 * (`num`) and modifies the current object. It utilizes the MulNumber function
 * to perform the scalar multiplication.
 *
 * @param num The scalar value to multiply the matrix by.
 * @return A reference to the current S21Matrix object after scalar
 * multiplication.
 */
S21Matrix S21Matrix::operator*=(const double num) noexcept {
  MulNumber(num);
  return *this;
}

/**
 * @brief Matrix multiplication assignment operator for S21Matrix.
 *
 * @details
 *
 * This operator multiplies the current S21Matrix object by another S21Matrix
 * object (`other`) and modifies the current object. It utilizes the MulMatrix
 * function to perform the matrix multiplication.
 *
 * @param other A constant reference to another S21Matrix object to be
 * multiplied.
 * @return A reference to the current S21Matrix object after matrix
 * multiplication.
 */
S21Matrix S21Matrix::operator*=(const S21Matrix& other) noexcept {
  MulMatrix(other);
  return *this;
}

/**
 * @brief Setter for the number of rows in the S21Matrix.
 *
 * @details
 *
 * This function sets the number of rows in the S21Matrix object. If the
 * specified number of rows is different from the current number of rows
 * (`rows_`), the matrix is resized accordingly. If the new number of rows is
 * less than the current number, the existing data is preserved up to the
 * minimum of old and new rows.
 *
 * @param rows The new number of rows for the matrix.
 * @throw std::invalid_argument if the number of rows is negative.
 */
void S21Matrix::set_rows(int rows) {
  if (rows < 0) {
    throw std::invalid_argument("The number of rows cannot be negative");
  }

  if (rows != rows_) {
    S21Matrix tmp{rows, cols_};
    int min = std::min(rows, rows_);

    for (int i = 0; i < min; i++) {
      for (int j = 0; j < cols_; j++) {
        tmp.matrix_[i][j] = matrix_[i][j];
      }
    }

    *this = std::move(tmp);
  }
}

/**
 * @brief Setter for the number of columns in the S21Matrix.
 *
 * @details
 *
 * This function sets the number of columns in the S21Matrix object. If the
 * specified number of columns is different from the current number of columns
 * (`cols_`), the matrix is resized accordingly. If the new number of columns is
 * less than the current number, the existing data is preserved up to the
 * minimum of old and new columns.
 *
 * @param cols The new number of columns for the matrix.
 * @throw std::invalid_argument if the number of columns is negative.
 */
void S21Matrix::set_cols(int cols) {
  if (cols < 0) {
    throw std::invalid_argument("The number of cols cannot be negative");
  }

  if (cols != cols_) {
    S21Matrix tmp{rows_, cols};
    int min = std::min(cols, cols_);

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < min; j++) {
        tmp.matrix_[i][j] = matrix_[i][j];
      }
    }

    *this = std::move(tmp);
  }
}

/**
 * @brief Equality comparison function for S21Matrix.
 *
 * @details
 *
 * This function compares the current S21Matrix object with another S21Matrix
 * object (`other`) to check if they are equal. It compares each element of the
 * matrices with a tolerance defined by `kEpsilon`.
 *
 * @param other A constant reference to another S21Matrix object to compare
 * with.
 * @return True if the matrices are equal within the tolerance defined by
 * `kEpsilon`, false otherwise.
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

/**
 * @brief Matrix addition function.
 *
 * @details
 *
 * This function adds another S21Matrix object (`other`) to the current
 * S21Matrix object. It modifies the current object by performing element-wise
 * addition.
 *
 * @param other A constant reference to another S21Matrix object to be added.
 * @throw std::invalid_argument if the dimensions of the matrices do not match.
 */
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

/**
 * @brief Matrix subtraction function.
 *
 * @details
 *
 * This function subtracts another S21Matrix object (`other`) from the current
 * S21Matrix object. It modifies the current object by performing element-wise
 * subtraction.
 *
 * @param other A constant reference to another S21Matrix object to be
 * subtracted.
 * @throw std::invalid_argument if the dimensions of the matrices do not match.
 */
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

/**
 * @brief Scalar multiplication function for S21Matrix.
 *
 * @details
 *
 * This function multiplies each element of the current S21Matrix object by a
 * scalar value (`num`). It modifies the current object in place.
 *
 * @param num The scalar value to multiply the matrix elements by.
 */
void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) *= num;
    }
  }
}

/**
 * @brief Matrix multiplication function for S21Matrix.
 *
 * @details
 *
 * This function multiplies the current S21Matrix object by another S21Matrix
 * object (`other`). It modifies the current object by assigning the result of
 * the multiplication.
 *
 * @param other A constant reference to another S21Matrix object to be
 * multiplied.
 * @throw std::invalid_argument if the number of columns of the first matrix
 * does not equal the number of rows of the second matrix.
 */
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

/**
 * @brief Transpose function for S21Matrix.
 *
 * @details
 *
 * This function computes the transpose of the current S21Matrix object.
 *
 * @return A new S21Matrix object representing the transpose of the current
 * matrix.
 */
S21Matrix S21Matrix::Transpose() const noexcept {
  S21Matrix tmp{cols_, rows_};

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      tmp.matrix_[j][i] = matrix_[i][j];
    }
  }

  return tmp;
}

/**
 * @brief Determinant calculation function for S21Matrix.
 *
 * @details
 *
 * This function calculates the determinant of the current S21Matrix object.
 * It checks if the matrix is square and throws an exception if it is not.
 * For square matrices, it uses either direct computation for 1x1 matrices
 * or Laplace expansion for larger matrices.
 *
 * @return The determinant value of the matrix.
 * @throw std::invalid_argument if the matrix is not square.
 */
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

/**
 * @brief Complement matrix calculation function for S21Matrix.
 *
 * @details
 *
 * This function calculates the matrix of cofactors (complements) for the
 * current S21Matrix object. It checks if the matrix is square and throws an
 * exception if it is not. For each element in the matrix, it computes the minor
 * matrix, calculates its determinant, and applies the sign according to the
 * position (i, j) to determine the complement value.
 *
 * @return A new S21Matrix object representing the matrix of complements.
 * @throw std::invalid_argument if the matrix is not square.
 */
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

/**
 * @brief Inverse matrix calculation function for S21Matrix.
 *
 * @details
 *
 * This function calculates the inverse matrix of the current S21Matrix object.
 * It checks if the matrix is square and throws an exception if it is not.
 * It also checks if the determinant is non-zero within a tolerance defined by
 * `kEpsilon`. It computes the inverse using the formula: inverse =
 * (transpose(complements) / determinant).
 *
 * @return A new S21Matrix object representing the inverse matrix.
 * @throw std::invalid_argument if the matrix is not square or if the
 * determinant is zero.
 */
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

/**
 * @brief Matrix allocation function.
 *
 * @details
 *
 * This function allocates memory for the matrix based on the current number of
 * rows and columns (`rows_` and `cols_`). It initializes each element of the
 * matrix to zero. Note: The function assumes that `rows_` and `cols_` are
 * properly set before calling.
 */
void S21Matrix::AllocateMatrix() {
  matrix_ = new double*[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]{};
  }
}

/**
 * @brief Matrix deallocation function.
 *
 * @details
 *
 * This function deallocates the memory allocated for the matrix.
 * It safely checks if the matrix pointer (`matrix_`) is not null before freeing
 * memory. Note: It sets the `matrix_` pointer to null after deallocation to
 * prevent dangling pointers. The function assumes that memory was previously
 * allocated for the matrix.
 */
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
 * @brief Check if the matrix is square.
 *
 * @details
 *
 * This function checks if the current S21Matrix object is a square matrix,
 * meaning it has an equal number of rows and columns.
 *
 * @return true if the matrix is square, false otherwise.
 */
bool S21Matrix::IsSquareMatrix() const { return rows_ == cols_; }

/**
 * @brief Laplace expansion function for calculating determinant recursively.
 *
 * @details
 *
 * This function calculates the determinant of the current S21Matrix object
 * using Laplace expansion (cofactor expansion) method. It recursively computes
 * the determinant for submatrices until it reaches base cases (2x2 matrix).
 *
 * @return The determinant value of the matrix.
 */
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

/**
 * @brief Get the minor matrix by removing a specified row and column.
 *
 * @details
 *
 * This function constructs and returns the minor matrix of the current
 * S21Matrix object by removing the specified row and column indices (`row` and
 * `col`).
 *
 * @param row The index of the row to be removed from the matrix.
 * @param col The index of the column to be removed from the matrix.
 * @return A new S21Matrix object representing the minor matrix.
 */
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
