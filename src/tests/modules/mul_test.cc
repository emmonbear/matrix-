#include "../../debug/matrix_debug.h"
#include "../main_test.h"

TEST(MulMatrix, TestNormal1) {
  S21Matrix matrix_1(2, 3);
  S21Matrix matrix_2(3, 2);
  S21Matrix expected(2);

  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 3;
  matrix_1(1, 0) = 4;
  matrix_1(1, 1) = 5;
  matrix_1(1, 2) = 6;

  matrix_2(0, 0) = 1;
  matrix_2(0, 1) = 2;
  matrix_2(1, 0) = 3;
  matrix_2(1, 1) = 4;
  matrix_2(2, 0) = 5;
  matrix_2(2, 1) = 6;

  expected(0, 0) = 22;
  expected(0, 1) = 28;
  expected(1, 0) = 49;
  expected(1, 1) = 64;

  S21Matrix res = matrix_1 * matrix_2;

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("matrix_2", matrix_2);

  debug.UpdateWolframNotation(expected);
  debug.PrintMatrix("expected", expected);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);
#endif  // ENABLE_DEBUG_PRINTS
}

TEST(MulMatrix, TestNormal2) {
  S21Matrix matrix_1(4, 3);
  S21Matrix matrix_2(3, 4);

  MatrixDebug debug;
  debug.FillRandom(matrix_1);
  debug.FillRandom(matrix_2);

  S21Matrix res = matrix_1 * matrix_2;
  S21Matrix expected = matrix_1 * matrix_2;

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
}

TEST(MulMatrix, TestFail1) {
  S21Matrix matrix_1(3, 1);
  S21Matrix matrix_2(2, 1);
  MatrixDebug debug;

  debug.FillRandom(matrix_1);
  debug.FillRandom(matrix_2);

  EXPECT_ANY_THROW(matrix_1 * matrix_2);
}

TEST(MulMatrix, TestFail2) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(2, 2);
  MatrixDebug debug;

  debug.FillRandom(matrix_1);
  debug.FillRandom(matrix_2);

  EXPECT_ANY_THROW(matrix_1 * matrix_2);
}