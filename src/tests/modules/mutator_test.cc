#include "../../debug/matrix_debug.h"
#include "../main_test.h"

TEST(Mutator, TestSetRowsNormal1) {
  S21Matrix matrix{3, 3};
  matrix.set_rows(3);

  S21Matrix expected{matrix};
  EXPECT_TRUE(matrix == expected);
}

TEST(Mutator, TestSetRowsNormal2) {
  std::string example{
      "{{6.911500, -51.304000, 68.043000}, {26.923900, 69.038200, 43.520100}, "
      "{28.967800, -39.073600, 82.461800}}"};
  std::string expected{
      "{{6.911500, -51.304000, 68.043000}, {26.923900, 69.038200, 43.520100}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  matrix_1.set_rows(2);

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("res", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(Mutator, TestSetRowsNormal3) {
  std::string example{
      "{{1.804700, -27.997900, 42.520000}, {97.171500, -90.264100, 38.950100}, "
      "{66.009200, -47.650600, -27.595300}}"};
  std::string expected{
      "{{1.804700, -27.997900, 42.520000}, {97.171500, -90.264100, 38.950100}, "
      "{66.009200, -47.650600, -27.595300}, {0, 0, 0}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  matrix_1.set_rows(4);

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("res", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(Mutator, TestSetRowsFail1) {
  std::string example{
      "{{1.804700, -27.997900, 42.520000}, {97.171500, -90.264100, 38.950100}, "
      "{66.009200, -47.650600, -27.595300}}"};
  S21Matrix matrix_1{example};

  EXPECT_ANY_THROW(matrix_1.set_rows(-14));
}

TEST(Mutator, TestSetColsNormal1) {
  S21Matrix matrix{3, 3};
  matrix.set_cols(3);

  S21Matrix expected{matrix};
  EXPECT_TRUE(matrix == expected);
}

TEST(Mutator, TestSetColsNormal2) {
  std::string example{
      "{{6.911500, -51.304000, 68.043000}, {26.923900, 69.038200, 43.520100}, "
      "{28.967800, -39.073600, 82.461800}}"};
  std::string expected{
      "{{6.911500, -51.304000}, {26.923900, 69.038200}, {28.967800, "
      "-39.073600}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  matrix_1.set_cols(2);

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("res", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(Mutator, TestSetColsNormal3) {
  std::string example{
      "{{1.804700, -27.997900, 42.520000}, {97.171500, -90.264100, 38.950100}, "
      "{66.009200, -47.650600, -27.595300}}"};
  std::string expected{
      "{{1.804700, -27.997900, 42.520000, 0}, {97.171500, -90.264100, "
      "38.950100, 0}, {66.009200, -47.650600, -27.595300, 0}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  matrix_1.set_cols(4);

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("res", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(Mutator, TestSetColsFail1) {
  std::string example{
      "{{1.804700, -27.997900, 42.520000}, {97.171500, -90.264100, 38.950100}, "
      "{66.009200, -47.650600, -27.595300}}"};
  S21Matrix matrix_1{example};

  EXPECT_ANY_THROW(matrix_1.set_cols(-14));
}