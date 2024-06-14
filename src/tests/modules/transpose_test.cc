#include "../../debug/matrix_debug.h"
#include "../main_test.h"

TEST(TransposeMatrix, Test1) {
  std::string example{"{{-3.352800}, {36.843100}, {88.291900}}"};
  std::string expected{"{{-3.3528, 36.8431, 88.2919}}"};

  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.Transpose();

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

  EXPECT_TRUE(res == matrix_2);
}

TEST(TransposeMatrix, Test2) {
  std::string example{
      "{{-33.798700, -88.766700, 63.536600}, {-33.404400, -83.070100, "
      "-12.139200}}"};
  std::string expected{
      "{{-33.7987, -33.4044}, {-88.7667, -83.0701}, {63.5366, -12.1392}}"};

  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.Transpose();

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

  EXPECT_TRUE(res == matrix_2);
}

TEST(TransposeMatrix, Test3) {
  std::string example{
      "{{37.939500, 32.947600, -30.739500}, {38.158700, 93.199000, 32.925200}, "
      "{-13.945500, -17.882700, -32.172400}}"};
  std::string expected{
      "{{37.9395, 38.1587, -13.9455}, {32.9476, 93.199, -17.8827}, {-30.7395, "
      "32.9252, -32.1724}}"};

  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.Transpose();

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

  EXPECT_TRUE(res == matrix_2);
}

TEST(TransposeMatrix, Test4) {
  std::string example{
      "{{62.430500, -21.709600, 59.144000}, {-62.507800, -48.114300, "
      "29.299100}, {48.374300, -7.030400, -9.312800}, {65.033300, 95.523500, "
      "75.993500}}"};
  std::string expected{
      "{{62.4305, -62.5078, 48.3743, 65.0333}, {-21.7096, -48.1143, -7.0304, "
      "95.5235}, {59.144, 29.2991, -9.3128, 75.9935}}"};

  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.Transpose();

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

  EXPECT_TRUE(res == matrix_2);
}
