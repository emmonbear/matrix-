#include "../../debug/matrix_debug.h"
#include "../main_test.h"

TEST(SumMatrix, TestNormal1) {
  S21Matrix matrix_1(3);
  S21Matrix matrix_2(3);
  MatrixDebug debug;

  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 3;
  matrix_1(1, 0) = 4;
  matrix_1(1, 1) = 5;
  matrix_1(1, 2) = 6;
  matrix_1(2, 0) = 7;
  matrix_1(2, 1) = 8;
  matrix_1(2, 2) = 9;

  matrix_2(0, 0) = 9;
  matrix_2(0, 1) = 8;
  matrix_2(0, 2) = 7;
  matrix_2(1, 0) = 6;
  matrix_2(1, 1) = 5;
  matrix_2(1, 2) = 4;
  matrix_2(2, 0) = 3;
  matrix_2(2, 1) = 2;
  matrix_2(2, 2) = 1;

  S21Matrix expected(3);

  expected(0, 0) = 10;
  expected(0, 1) = 10;
  expected(0, 2) = 10;
  expected(1, 0) = 10;
  expected(1, 1) = 10;
  expected(1, 2) = 10;
  expected(2, 0) = 10;
  expected(2, 1) = 10;
  expected(2, 2) = 10;

  S21Matrix res = matrix_1 + matrix_2;

#ifdef ENABLE_DEBUG_PRINTS
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("matrix_2", matrix_2);

  debug.UpdateWolframNotation(expected);
  debug.PrintMatrix("expected", expected);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(SumMatrix, TestNormal2) {
  S21Matrix matrix_1(3);
  S21Matrix matrix_2(3);
  MatrixDebug debug;

  debug.FillRandom(matrix_1);
  debug.FillRandom(matrix_2);

  S21Matrix expected = matrix_1 + matrix_2;
  S21Matrix res = matrix_1 + matrix_2;

#ifdef ENABLE_DEBUG_PRINTS
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("matrix_2", matrix_2);

  debug.UpdateWolframNotation(expected);
  debug.PrintMatrix("expected", expected);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(SumMatrix, TestNormal3) {
  S21Matrix matrix_1(10);
  S21Matrix matrix_2(10);
  MatrixDebug debug;

  debug.FillRandom(matrix_1);
  debug.FillRandom(matrix_2);

  S21Matrix expected = matrix_1 + matrix_2;
  S21Matrix res = matrix_1 + matrix_2;

#ifdef ENABLE_DEBUG_PRINTS
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("matrix_2", matrix_2);

  debug.UpdateWolframNotation(expected);
  debug.PrintMatrix("expected", expected);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(SumMatrix, TestFail1) {
  S21Matrix matrix_1(3);
  S21Matrix matrix_2(2);
  MatrixDebug debug;

  debug.FillRandom(matrix_1);
  debug.FillRandom(matrix_2);

  EXPECT_THROW((matrix_1 + matrix_2), std::invalid_argument);
}

TEST(SumMatrix, TestFail2) {
  S21Matrix matrix_1(3, 1);
  S21Matrix matrix_2(3, 2);
  MatrixDebug debug;

  debug.FillRandom(matrix_1);
  debug.FillRandom(matrix_2);

  EXPECT_THROW((matrix_1 + matrix_2), std::invalid_argument);
}

TEST(SumMatrix, TestFail3) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 2);
  MatrixDebug debug;

  debug.FillRandom(matrix_1);
  debug.FillRandom(matrix_2);

  EXPECT_THROW((matrix_1 + matrix_2), std::invalid_argument);
}

TEST(SumMatrix, TestFail4) {
  S21Matrix matrix_1(4, 3);
  S21Matrix matrix_2(3, 3);
  MatrixDebug debug;

  debug.FillRandom(matrix_1);
  debug.FillRandom(matrix_2);

  EXPECT_THROW((matrix_1 + matrix_2), std::invalid_argument);
}

TEST(SumMatrix, TestFail5) {
  S21Matrix matrix_1(4, 3);
  S21Matrix matrix_2(5, 3);
  MatrixDebug debug;

  debug.FillRandom(matrix_1);
  debug.FillRandom(matrix_2);

  EXPECT_THROW((matrix_1 + matrix_2), std::invalid_argument);
}