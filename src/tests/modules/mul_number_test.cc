#include "../../debug/matrix_debug.h"
#include "../main_test.h"

TEST(MulNumber, TestNormal1) {
  S21Matrix matrix_1(5);
  double num = 0.;
  S21Matrix expected(5);
  MatrixDebug debug;

  debug.FillRandom(matrix_1);

  S21Matrix res = matrix_1 * num;

#ifdef ENABLE_DEBUG_PRINTS
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(expected);
  debug.PrintMatrix("expected", expected);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(MulNumber, TestNormal2) {
  S21Matrix matrix_1(5);
  double num = 2.1;
  MatrixDebug debug;

  debug.FillRandom(matrix_1);
  S21Matrix matrix_2(matrix_1);

  S21Matrix expected = matrix_1 * num;
  S21Matrix res = matrix_2 * num;

#ifdef ENABLE_DEBUG_PRINTS
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(expected);
  debug.PrintMatrix("expected", expected);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("expected", res);
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}