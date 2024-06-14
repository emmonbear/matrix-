#include "../../debug/matrix_debug.h"
#include "../main_test.h"

TEST(CalcComplements, TestNormal1) {
  std::string example{
      "{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}"};

  S21Matrix matrix_1{example};

  S21Matrix matrix_2 = matrix_1.CalcComplements();;
  S21Matrix res = matrix_1.CalcComplements();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == matrix_2);
}

TEST(CalcComplements, TestNormal2) {
  std::string example{"{{-3.185900, 88.634700, -93.955500}, {-77.807700, 93.453200, 61.064900}, {53.230400, 99.598900, -62.699400}}"};

  S21Matrix matrix_1{example};

  S21Matrix matrix_2 = matrix_1.CalcComplements();;
  S21Matrix res = matrix_1.CalcComplements();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == matrix_2);
}

TEST(CalcComplements, TestNormal3) {
  std::string example{"{{44.907900, 63.327700, -16.760800}, {25.051700, 95.210700, -47.156000}, {1.099600, -68.811000, 46.637200}}"};

  S21Matrix matrix_1{example};

  S21Matrix matrix_2 = matrix_1.CalcComplements();;
  S21Matrix res = matrix_1.CalcComplements();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == matrix_2);
}

TEST(CalcComplements, TestNormal4) {
  std::string example{"{{-42.370200, 81.928800, -20.553100}, {93.742000, -52.847100, 27.552100}, {76.109400, 69.529600, -98.597800}}"};

  S21Matrix matrix_1{example};

  S21Matrix matrix_2 = matrix_1.CalcComplements();;
  S21Matrix res = matrix_1.CalcComplements();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == matrix_2);
}

TEST(CalcComplements, TestNormal5) {
  std::string example{"{{26.309400, -50.007000, -55.091600}, {90.245700, 67.032200, 60.560600}, {-47.478600, -77.570100, -40.338300}}"};

  S21Matrix matrix_1{example};

  S21Matrix matrix_2 = matrix_1.CalcComplements();;
  S21Matrix res = matrix_1.CalcComplements();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == matrix_2);
}

TEST(CalcComplements, TestNormal6) {
  std::string example{"{{-13.500000, -59.313200, -18.087200}, {-38.832200, 52.716800, 95.370900}, {-17.019600, 24.618100, -45.950300}}"};

  S21Matrix matrix_1{example};

  S21Matrix matrix_2 = matrix_1.CalcComplements();;
  S21Matrix res = matrix_1.CalcComplements();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == matrix_2);
}

TEST(CalcComplements, TestNormal7) {
  std::string example{"{{-77.872600, 39.407800, 9.225500}, {18.056000, -76.554600, -30.364500}, {17.194300, -13.874000, -87.178400}}"};

  S21Matrix matrix_1{example};

  S21Matrix matrix_2 = matrix_1.CalcComplements();;
  S21Matrix res = matrix_1.CalcComplements();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == matrix_2);
}

TEST(CalcComplements, TestNormal8) {
  std::string example{"{{71.929600, -15.236900, -54.115000}, {-91.856700, 70.799800, 72.558700}, {19.145200, -39.202200, -39.640300}}"};

  S21Matrix matrix_1{example};

  S21Matrix matrix_2 = matrix_1.CalcComplements();;
  S21Matrix res = matrix_1.CalcComplements();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == matrix_2);
}

TEST(CalcComplements, TestNormal9) {
  std::string example{"{{-38.662400, -1.177800, -9.613100}, {-33.827200, 89.388100, -97.665900}, {60.983700, -32.974700, -1.819300}}"};

  S21Matrix matrix_1{example};

  S21Matrix matrix_2 = matrix_1.CalcComplements();;
  S21Matrix res = matrix_1.CalcComplements();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == matrix_2);
}

TEST(CalcComplements, TestNormal10) {
  std::string example{"{{49.083100, 59.054500, -45.700200}, {88.674600, 98.274500, -93.679900}, {85.684400, 28.447800, -69.795200}}"};

  S21Matrix matrix_1{example};

  S21Matrix matrix_2 = matrix_1.CalcComplements();;
  S21Matrix res = matrix_1.CalcComplements();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == matrix_2);
}

TEST(CalcComplements, TestNormal11) {
  std::string example{"{{-11.842000, 21.485300, 38.214000}, {-97.368600, 6.569500, 41.888000}, {22.617400, 44.740100, 14.759000}}"};

  S21Matrix matrix_1{example};

  S21Matrix matrix_2 = matrix_1.CalcComplements();;
  S21Matrix res = matrix_1.CalcComplements();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == matrix_2);
}