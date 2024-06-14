#include "../../debug/matrix_debug.h"
#include "../main_test.h"

TEST(Constructor, DefaultConstructor) {
  S21Matrix matrix;

  EXPECT_EQ(matrix.get_cols(), 0);
  EXPECT_EQ(matrix.get_rows(), 0);
}

TEST(Constructor, SingleConstructorNormal) {
  int n = 5;
  S21Matrix matrix(n);

  EXPECT_EQ(matrix.get_rows(), n);
  EXPECT_EQ(matrix.get_cols(), n);
}

TEST(Constructor, SingleConstructorNegative) {
  int n = -1;

  EXPECT_THROW(S21Matrix matrix(n), std::invalid_argument);
}

TEST(Constructor, DoubleConstructorPositive) {
  int n = 2;
  int m = 3;
  S21Matrix matrix(n, m);

  EXPECT_EQ(matrix.get_rows(), n);
  EXPECT_EQ(matrix.get_cols(), m);
}

TEST(Constructor, DoubleConstructorNegative) {
  int n = -2;
  int m = -3;

  EXPECT_THROW(S21Matrix matrix(n, m), std::invalid_argument);
}

TEST(Constructor, DoubleConstructorMixed) {
  int n = 2;
  int m = -3;

  EXPECT_THROW(S21Matrix matrix(n, m), std::invalid_argument);
}

TEST(Constructor, CopyConstructor1) {
  S21Matrix matrix_1(100, 100);
  MatrixDebug debug;
  debug.FillRandom(matrix_1);

  S21Matrix matrix_2(matrix_1);

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(Constructor, CopyConstructor2) {
  S21Matrix matrix_1(1000, 90);
  MatrixDebug debug;
  debug.FillRandom(matrix_1);

  S21Matrix matrix_2(matrix_1);

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(Constructor, MoveConstructor1) {
  int n = 15, m = 23;
  S21Matrix matrix_1{n, m};
  MatrixDebug debug;
  debug.FillRandom(matrix_1);

  S21Matrix matrix_2 = std::move(matrix_1);

  EXPECT_EQ(matrix_1.get_rows(), 0);
  EXPECT_EQ(matrix_1.get_cols(), 0);

  EXPECT_EQ(matrix_2.get_rows(), n);
  EXPECT_EQ(matrix_2.get_cols(), m);
}
