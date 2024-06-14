#include "../../debug/matrix_debug.h"
#include "../main_test.h"

TEST(Operators, AssignmentOperatorTest1) {
  std::string example{
      "{{53.194500, -99.057700, -31.281100}, {-46.393200, -15.022800, "
      "-70.678500}, {65.970800, -56.264000, 34.949800}}"};
  S21Matrix matrix{example};
  S21Matrix res{};

  res = matrix;

  EXPECT_TRUE(res == matrix);
}

TEST(Operators, IndexOperatorTest1) {
  S21Matrix matrix(3, 3);

  EXPECT_ANY_THROW(matrix(-1, -1));
  EXPECT_ANY_THROW(matrix(-1, 0));
  EXPECT_ANY_THROW(matrix(0, -1));
  EXPECT_ANY_THROW(matrix(3, 4));
  EXPECT_ANY_THROW(matrix(4, 0));
  EXPECT_ANY_THROW(matrix(4, 4));
}

TEST(Operators, AddAssignmentTest1) {
  std::string example{"{{1, 2}, {3, 4}}"};
  std::string expected{"{{2, 4}, {6, 8}}"};
  S21Matrix matrix_1{example};
  S21Matrix res{example};
  S21Matrix matrix_2{expected};

  res += matrix_1;

  EXPECT_TRUE(res == matrix_2);
}

TEST(Operators, SubAssignmentTest1) {
  std::string example{"{{2, 4}, {6, 8}}"};
  std::string expected{"{{0, 0}, {0, 0}}"};
  S21Matrix matrix_1{example};
  S21Matrix res{example};
  S21Matrix matrix_2{expected};

  res -= matrix_1;

  EXPECT_TRUE(res == matrix_2);
}

TEST(Operators, MulNumberAssignmentTest1) {
  std::string example{"{{2, 4}, {6, 8}}"};
  std::string expected{"{{6, 12}, {18, 24}}"};
  S21Matrix matrix_1{example};
  S21Matrix res{example};
  S21Matrix matrix_2{expected};

  res *= 3;

  EXPECT_TRUE(res == matrix_2);
}

TEST(Operators, MulMatrixAssignmentTest1) {
  std::string example_1{"{{1, 2, 3}, {4, 5, 6}}"};
  std::string example_2{"{{1, 2}, {3, 4}, {5, 6}}"};
  std::string expected{"{{22, 28}, {49, 64}}"};

  S21Matrix matrix_1{example_1};
  S21Matrix matrix_2{example_2};
  S21Matrix res{expected};
  matrix_1 *= matrix_2;

  EXPECT_TRUE(res == matrix_1);
}