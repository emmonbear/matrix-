#include "../../debug/matrix_debug.h"
#include "../main_test.h"

TEST(Inverse, TestNormal1) {
  std::string example{"{{-22.096200, 68.906700}, {80.946900, -71.946600}}"};
  std::string expected{"{{0.0180406, 0.0172783}, {0.0202974, 0.00554062}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal2) {
  std::string example{"{{16.428700, -74.583200}, {-17.888400, -82.656700}}"};
  std::string expected{"{{0.0307032, -0.0277043}, {-0.00664474, -0.00610252}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal3) {
  std::string example{"{{43.743200, 78.977200}, {-95.131400, 3.791900}}"};
  std::string expected{"{{0.000493796, -0.0102847}, {0.0123884, 0.00569641}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal4) {
  std::string example{"{{-11.311100, 14.732800}, {42.547500, 23.752600}}"};
  std::string expected{"{{-0.026524, 0.0164518}, {0.0475119, 0.0126309}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal5) {
  std::string example{"{{-9.802400, -15.582000}, {-18.117400, 26.216900}}"};
  std::string expected{"{{-0.0486134, -0.0288933}, {-0.0335947, 0.0181764}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal6) {
  std::string example{"{{-82.508100, 41.249900}, {36.273900, -28.434100}}"};
  std::string expected{"{{-0.0334618, -0.0485436}, {-0.0426878, -0.097097}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal7) {
  std::string example{"{{49.642900, -52.662600}, {-14.713100, -52.847400}}"};
  std::string expected{"{{0.015551, -0.0154966}, {-0.00432951, -0.014608}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal8) {
  std::string example{"{{1.473700, 34.726400}, {86.622600, -99.837800}}"};
  std::string expected{"{{0.0316421, 0.011006}, {0.0274537, -0.000467067}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal9) {
  std::string example{"{{68.041800, -29.750100}, {79.026000, -5.159100}}"};
  std::string expected{"{{-0.00257955, 0.0148751}, {-0.0395131, 0.034021}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal10) {
  std::string example{"{{-68.094600, 26.983300}, {11.856300, -46.160900}}"};
  std::string expected{
      "{{-0.0163495, -0.00955707}, {-0.00419932, -0.0241181}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal11) {
  std::string example{
      "{{14.589400, 81.664200, -60.590200}, {67.179100, -79.936700, "
      "-5.124400}, {-3.132400, 83.403100, -13.155900}}"};
  std::string expected{
      "{{-0.00645165, 0.0173569, 0.0229527}, {-0.00392524, 0.00166514, "
      "0.0174293}, {-0.0233483, 0.00642363, 0.0290181}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal12) {
  std::string example{
      "{{71.195200, 46.499600, -94.802100}, {-16.666200, 45.579300, "
      "-32.549700}, {-66.711600, -87.042000, -5.740300}}"};
  std::string expected{
      "{{0.00563104, -0.0154997, -0.00510818}, {-0.00377687, 0.0122508, "
      "-0.00709127}, {-0.00817197, -0.00563119, -0.00731439}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal13) {
  std::string example{
      "{{75.733500, 35.625600, -15.346400}, {15.366100, -76.033000, "
      "67.981100}, {82.864300, -86.123500, -91.066900}}"};
  std::string expected{
      "{{0.0111904, 0.00399843, 0.00109903}, {0.00615839, -0.00492593, "
      "-0.00471498}, {0.00435838, 0.00829682, -0.00552186}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal14) {
  std::string example{
      "{{88.609200, -62.486200, -55.839900}, {92.871500, -76.946300, "
      "-89.920300}, {12.440600, -82.535100, 78.333100}}"};
  std::string expected{
      "{{0.045955, -0.0324732, -0.0045176}, {0.0286807, -0.0260911, "
      "-0.00950546}, {0.0229208, -0.0223334, 0.00346811}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal15) {
  std::string example{
      "{{1.625100, 28.896300, -10.263700}, {-66.294100, -2.024900, "
      "-35.593800}, {99.222200, -24.484700, -69.000700}}"};
  std::string expected{
      "{{0.00287939, -0.00883418, 0.00412878}, {0.0318952, -0.00356588, "
      "-0.00290489}, {-0.0071774, -0.0114381, -0.00752467}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal16) {
  std::string example{
      "{{53.134500, 88.506400, 48.251000}, {-36.700800, 19.843800, "
      "-83.752100}, {-63.414700, -14.202000, 41.845100}}"};
  std::string expected{
      "{{-0.000533728, -0.00652341, -0.012441}, {0.010177, 0.00785285, "
      "0.0039824}, {0.00264517, -0.00722077, 0.00639533}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal17) {
  std::string example{
      "{{95.675900, -18.431900, -25.504800}, {93.952200, 58.871700, "
      "-26.039700}, {-36.457300, -20.885900, -60.750400}}"};
  std::string expected{
      "{{0.00789925, 0.00112546, -0.00379875}, {-0.0127623, 0.0129257, "
      "-0.000182396}, {-0.000352805, -0.00511924, -0.0141184}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal18) {
  std::string example{
      "{{19.965700, -52.581600, -76.243400}, {-65.222900, 9.979100, "
      "-34.156600}, {30.718400, 10.896200, 6.585600}}"};
  std::string expected{
      "{{0.00368337, -0.00407523, 0.021507}, {-0.00521266, 0.0208064, "
      "0.0475653}, {-0.0085564, -0.0154164, -0.0271716}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal19) {
  std::string example{
      "{{-37.620700, -52.942300, 84.506400}, {-89.829300, -97.750900, "
      "21.871000}, {60.789900, -4.613600, -54.126400}}"};
  std::string expected{
      "{{0.0103418, -0.00624413, 0.0136233}, {-0.00677571, -0.00594761, "
      "-0.012982}, {0.0121925, -0.00650588, -0.00206826}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal20) {
  std::string example{
      "{{28.965400, 38.139000, -15.838700}, {31.365000, 43.724200, 93.971600}, "
      "{-20.243300, 44.500400, -0.061500}}"};
  std::string expected{
      "{{0.0182085, 0.00305681, -0.018609}, {0.00826934, 0.00140294, "
      "0.014006}, {-0.00992511, 0.00896846, -0.000305729}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal21) {
  std::string example{
      "{{21.104000, 9.885600, 96.671500, 56.441800}, {29.026700, -99.886800, "
      "-35.192800, 99.947400}, {32.005200, 41.917600, 79.719300, 58.443200}, "
      "{9.111600, -84.540300, 21.638200, 8.797500}}"};
  std::string expected{
      "{{-0.0705178, -0.00610905, 0.0732388, 0.0352861}, {-0.00199948, "
      "-0.00073237, 0.00453083, -0.00895065}, {0.0125689, -0.00418186, "
      "-0.00553842, 0.0036646}, {0.0229072, 0.00957504, -0.0186921, "
      "-0.0179026}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal22) {
  std::string example{
      "{{-98.709300, 4.660600, 59.382800, -59.657300}, {36.101800, 5.922100, "
      "22.213400, -42.118100}, {-21.469300, -39.349800, 27.606300, 32.496100}, "
      "{39.432600, 71.345300, 56.164200, -4.041100}}"};

  std::string expected{
      "{{-0.00631582, 0.010952, 0.00272528, 0.0010066}, {0.00158255, "
      "-0.0118564, -0.0113905, 0.00861481}, {0.00213137, 0.00646432, "
      "0.0131061, 0.00655272}, {-0.00406703, -0.0126129, 0.00764666, "
      "0.00553007}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal23) {
  std::string example{
      "{{-67.645100, -62.838900, -36.537900, 16.250100}, {-12.872800, "
      "10.298600, 3.981300, 97.707600}, {-44.336700, 24.682400, 95.077800, "
      "12.671700}, {43.063000, -59.670300, 96.013300, -62.084600}}"};
  std::string expected{
      "{{-0.00719382, 0.0055259, -0.00818882, 0.00514228}, {-0.00736945, "
      "-0.00428755, 0.00506539, -0.00764269}, {-0.00142645, 0.00218044, "
      "0.00562962, 0.0042072}, {-0.000112893, 0.0113257, -0.00184216, "
      "0.00131161}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal24) {
  std::string example{
      "{{-52.302400, 1.281600, 92.424900, -45.972900}, {-90.435900, 52.683900, "
      "-49.689100, -95.785100}, {54.131100, 43.970800, 48.945200, 47.521700}, "
      "{-28.814500, -32.358100, -44.160700, -38.335000}}"};
  std::string expected{
      "{{0.00325878, -0.00256417, 0.0548873, 0.0705395}, {-0.00326359, "
      "0.00831858, 0.00518526, -0.0104434}, {0.00817599, -0.00260668, "
      "0.00527029, 0.00324144}, {-0.00911318, -0.00209143, -0.051704, "
      "-0.0740257}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal25) {
  std::string example{
      "{{56.823600, -84.780800, 30.968500, 18.434600}, {-12.049300, 33.472400, "
      "78.123900, -5.623800}, {-59.560700, -56.200300, -0.264300, 55.316400}, "
      "{-87.405200, -33.646200, 53.429000, -57.055300}}"};
  std::string expected{
      "{{0.00558328, 0.000430782, -0.00583424, -0.00389493}, {-0.00689733, "
      "0.00562713, -0.00150011, -0.00423758}, {0.00374591, 0.0109043, "
      "0.000482486, 0.000603271}, {-0.000977974, 0.00623298, 0.0102742, "
      "-0.00849619}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal26) {
  std::string example{
      "{{-7.249700, -74.768200, -77.531700, -77.198700}, {26.872900, "
      "99.441200, 51.670700, -58.437800}, {65.843100, 20.840800, 23.722400, "
      "81.254500}, {-52.769500, -26.932800, -18.482400, 53.353300}}"};
  std::string expected{
      "{{0.00400967, -0.00131111, 0.008855, -0.00912007}, {0.0147611, "
      "0.0259773, 0.0139352, 0.0285886}, {-0.0289057, -0.0272837, -0.0222996, "
      "-0.0377473}, {0.00140385, 0.0023651, 0.00806771, 0.011078}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal27) {
  std::string example{
      "{{94.115900, 87.878000, 14.385000, -52.967000}, {-39.465100, "
      "-69.394400, -20.375300, -30.746700}, {-51.404600, 89.109100, 16.828200, "
      "11.516800}, {89.610000, 57.272000, 2.778000, -4.014300}}"};
  std::string expected{
      "{{0.000886111, -0.00473433, -0.00715639, 0.00403851}, {-0.00409029, "
      "0.00971704, 0.0126483, 0.0158311}, {0.0344502, -0.0600336, -0.029574, "
      "-0.0795869}, {-0.0147353, -0.00859489, 0.000237002, 0.0118269}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal28) {
  std::string example{
      "{{-1.829800, 94.267600, 41.400300, 89.133500}, {-16.344500, -62.685200, "
      "46.462300, 45.824900}, {51.463400, -96.470400, -4.749800, 77.263000}, "
      "{20.755900, 1.155200, -57.214400, 28.310400}}"};
  std::string expected{
      "{{0.00297086, -0.026052, 0.0195842, -0.0206323}, {0.00497889, "
      "-0.00656736, -0.00125276, -0.00162645}, {0.00337795, -0.00521328, "
      "0.0064512, -0.019803}, {0.00444546, 0.00883226, -0.00126946, "
      "0.0104946}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal29) {
  std::string example{
      "{{-92.573800, -51.524000, -71.589400, -12.923500}, {-95.587700, "
      "7.686700, 62.864100, -5.033900}, {91.045500, -32.826000, -82.464300, "
      "82.543100}, {36.684000, -49.162900, 4.556300, -83.394000}}"};
  std::string expected{
      "{{-0.00467736, -0.00270427, 0.00216658, 0.00303256}, {-0.000380063, "
      "-0.0184775, -0.014483, -0.0131609}, {-0.00724418, 0.0148969, 0.0058509, "
      "0.00601461}, {-0.00222925, 0.0105173, 0.00981081, -0.00256995}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestNormal30) {
  std::string example{
      "{{-7.202100, 62.191700, -97.467500, 66.164300}, {90.467100, -85.586000, "
      "63.182100, 36.045000}, {-38.470100, -45.895000, 31.844200, 78.174300}, "
      "{34.419900, -10.803500, -82.554200, 26.297700}}"};
  std::string expected{
      "{{0.00604783, 0.0092503, -0.00828798, -0.00325771}, {0.0129544, "
      "0.00368863, -0.00749676, -0.0153633}, {0.00371497, 0.00488067, "
      "-0.000974426, -0.0131398}, {0.00906821, 0.00472954, 0.00470905, "
      "-0.00527021}}"};
  S21Matrix matrix_1{example};
  S21Matrix matrix_2{expected};

  S21Matrix res = matrix_1.InverseMatrix();

#ifdef ENABLE_DEBUG_PRINTS
  MatrixDebug debug;
  debug.UpdateWolframNotation(matrix_1);
  debug.PrintMatrix("matrix_1", matrix_1);

  debug.UpdateWolframNotation(res);
  debug.PrintMatrix("res", res);

  debug.UpdateWolframNotation(matrix_2);
  debug.PrintMatrix("expected", matrix_2);

#endif  // ENABLE_DEBUG_PRINTS

  EXPECT_TRUE(res == expected);
}

TEST(Inverse, TestFail1) {
  std::string example{"{{47.808300, 57.148700, 48.518100}, {9.230100, -56.311400, 94.235300}}"};
  S21Matrix matrix_1{example};
  
  EXPECT_ANY_THROW(matrix_1.InverseMatrix(););
}

TEST(Inverse, InverseMatrixThrowsIfNotSquare) {
  S21Matrix nonSquareMatrix(2, 3);
  
  try {
    nonSquareMatrix.InverseMatrix();
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument& e) {
    EXPECT_EQ(e.what(), std::string("Matrix must be square to calculate inverse matrix."));
  } catch (...) {
    FAIL() << "Expected std::invalid_argument";
  }
}

TEST(Inverse, InverseMatrixThrowsIfDeterminantZero) {
  S21Matrix singularMatrix(2, 2);
  singularMatrix(0, 0) = 1;
  singularMatrix(0, 1) = 2;
  singularMatrix(1, 0) = 2;
  singularMatrix(1, 1) = 4;
  
  try {
    singularMatrix.InverseMatrix();
    FAIL() << "Expected std::invalid_argument";
  } catch (const std::invalid_argument& e) {
    EXPECT_EQ(e.what(), std::string("The determinant must not be equal to zero."));
  } catch (...) {
    FAIL() << "Expected std::invalid_argument";
  }
}