#include "../../debug/matrix_debug.h"
#include "../main_test.h"

TEST(MatrixEqual, Test1) {
  int n = 3, m = 4;
  S21Matrix matrix_1(n, m);
  S21Matrix matrix_2(matrix_1);

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(MatrixEqual, 2) {
  S21Matrix matrix_1(2);
  S21Matrix matrix_2(2);

  matrix_1(0, 1) = 2;
  matrix_2(0, 1) = 2;

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("matrix_2", matrix_2);
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(MatrixEqual, 3) {
  S21Matrix matrix_1(2);
  S21Matrix matrix_2(2);

  matrix_1(0, 1) = 2;
  matrix_2(0, 1) = 1;

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("matrix_2", matrix_2);
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_FALSE(matrix_1 == matrix_2);
}
