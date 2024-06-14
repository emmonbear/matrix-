#include "../../debug/matrix_debug.h"
#include "../main_test.h"

TEST(Determinant, TestNormal1) {
  std::string example{"{{62.278500}}"};
  double expected{62.278500};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Determinant, TestNormal2) {
  std::string example{"{{91.328700, 2.563000}, {-93.984300, -79.757100}}"};
  double expected{-7043.23049787};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal3) {
  std::string example{
      "{{-34.633200, -8.943600, 4.923900}, {76.314600, -73.805300, "
      "-56.137300}, {81.866200, -73.961300, 58.954800}}"};
  double expected{377791.464540587832};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal4) {
  std::string example{
      "{{10.052200, -88.425800, -48.801600}, {40.127700, 51.863900, "
      "46.623900}, {16.537200, 64.694400, -97.913000}}"};
  double expected{-581807.409720293416};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal5) {
  std::string example{
      "{{-39.162500, -47.691200, 27.521200}, {-62.353100, -15.441200, "
      "-10.208700}, {-28.123500, 19.488200, -94.960000}}"};
  double expected{158080.717147410266};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal6) {
  std::string example{
      "{{69.637200, 36.758000, -80.002500}, {-64.501600, 3.434900, "
      "-79.435500}, {-5.601600, -18.899800, -12.991800}}"};
  double expected{-221169.581677559424};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal7) {
  std::string example{
      "{{7.449700, -37.627800, -34.334900}, {-62.769500, 61.056600, 4.873800}, "
      "{-0.004000, 96.276200, 74.946900}}"};
  double expected{61064.092893414326};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal8) {
  std::string example{
      "{{-89.184500, -72.202800, -9.775800}, {23.581600, -37.996700, "
      "-25.693700}, {-69.550600, -35.766000, 22.212300}}"};
  double expected{100100.451334627329};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal9) {
  std::string example{
      "{{-28.705000, -49.655400, 1.170900}, {-16.620800, -5.248000, "
      "99.515300}, {38.107500, -75.532700, 65.186600}}"};
  double expected{-446348.074503277268};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal10) {
  std::string example{
      "{{60.723600, -2.499800, 66.581000}, {23.959000, 11.036100, 57.037300}, "
      "{21.055500, 55.378500, 18.764100}}"};
  double expected{-108238.403109267744};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal11) {
  std::string example{
      "{{-61.423600, 83.662500, -86.066600, -85.852200}, {-83.577500, "
      "-83.363300, -58.308900, 0.517000}, {-74.843300, 40.610500, 35.083200, "
      "-3.364700}, {-2.889100, 37.264700, 12.960500, -35.957600}}"};
  double expected{-3.8950269547963838205018e7};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal12) {
  std::string example{
      "{{35.844100, -53.637400, 86.199200, 2.609500}, {15.580200, -91.578800, "
      "-30.327800, 82.587500}, {24.735100, 37.132100, 42.465900, -37.359500}, "
      "{-66.740300, 39.818500, -51.093400, -99.066400}}"};
  double expected{-1.63950253455135849902745e7};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal13) {
  std::string example{
      "{{5.124500, 59.868000, -29.871000, -33.431900}, {-76.503000, 55.822600, "
      "-61.539600, -89.500200}, {-81.272100, 96.145000, 17.327000, 14.969700}, "
      "{-60.351200, 90.715000, -0.995700, 19.775100}}"};
  double expected{1.25686415242411970479012e7};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal14) {
  std::string example{
      "{{54.870400, -67.354500, 28.178800, -81.173500}, {-98.491000, "
      "70.726900, -87.293000, 81.628400}, {-31.509600, -3.612600, 92.492500, "
      "-24.953700}, {20.568300, -46.448100, 68.902300, 74.210100}}"};
  double expected{-5.41966981913509698370239e7};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal15) {
  std::string example{
      "{{-37.870200, -43.535200, 92.932500, 19.989000}, {-27.716800, "
      "-24.315700, 64.582300, 8.130600}, {-25.016200, 59.875700, -64.764000, "
      "77.681400}, {75.292300, -24.608000, 13.665400, -75.665100}}"};
  double expected{2.7207021652300390517658e6};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal16) {
  std::string example{
      "{{-25.300000, -49.080600, -31.809600, -63.102800}, {-96.125000, "
      "40.946700, 15.080300, 53.365200}, {17.714100, 21.318400, 63.159000, "
      "36.396400}, {32.575500, 45.403700, 27.803400, -21.876300}}"};
  double expected{2.23338804805301561593466e7};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal17) {
  std::string example{
      "{{-39.991100, -96.878900, -81.888100, 59.121600}, {35.231000, "
      "81.055200, 6.804600, -62.275800}, {-31.075100, -79.006000, -65.274600, "
      "-1.474900}, {-76.331600, -8.205900, -58.093400, -57.549900}}"};
  double expected{-2.27348742969199497891116e7};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal18) {
  std::string example{
      "{{-58.300600, -7.499600, -15.809600, 78.636300}, {35.793700, "
      "-51.058600, 3.795400, -96.362900}, {35.256600, -44.485000, 74.731200, "
      "26.557500}, {-30.998200, -98.094400, -41.012000, 59.254900}}"};
  double expected{3.10960611666445300953472e7};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal19) {
  std::string example{
      "{{-88.562300, -45.436300, -42.231700, -76.568000}, {-22.386400, "
      "-43.628100, -13.388900, 96.834400}, {56.303500, -5.632400, -71.354900, "
      "88.089600}, {92.769700, 3.436300, 72.847000, -87.839700}}"};
  double expected{9.67398029301263759289681e7};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestNormal20) {
  std::string example{
      "{{-73.574300, -15.000700, -9.532300, -64.045500}, {21.499800, "
      "23.822600, -98.539900, -61.388100}, {67.576900, -85.789400, 34.239700, "
      "-85.666800}, {-31.182700, -14.534600, 20.172700, -57.912300}}"};
  double expected{-3.08925269466223244474745e7};

  S21Matrix matrix_1{example};

  double res = matrix_1.Determinant();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);
  debug.std::cout << "expected = " << res << std::endl;
  std::cout << "res = " << res << std::endl;
#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(std::abs(res - expected) < 1e-7);
}

TEST(Determinant, TestFail1) {
  std::string example{"{{47.808300, 57.148700, 48.518100}, {9.230100, -56.311400, 94.235300}}"};
  S21Matrix matrix_1{example};
  
  EXPECT_ANY_THROW(matrix_1.Determinant(););
}