#include "../main_test.h"

TEST(constructor, default_constructor) {
  S21Matrix matrix;
  EXPECT_EQ(matrix.get_cols(), 0);
  EXPECT_EQ(matrix.get_rows(), 0);
}

TEST(constructor, single_constructor_normal) {
  int n = 5;

  S21Matrix matrix(n);

  EXPECT_EQ(matrix.get_rows(), n);
  EXPECT_EQ(matrix.get_cols(), n);
}

TEST(constructor, single_constructor_negative) {
  int n = -1;

  EXPECT_THROW(S21Matrix matrix(n), std::invalid_argument);
}

TEST(constructor, double_constructor_positive) {
  int n = 2;
  int m = 3;
  S21Matrix matrix(n, m);
  
  EXPECT_EQ(matrix.get_rows(), n);
  EXPECT_EQ(matrix.get_cols(), m);
}

TEST(constructor, double_constructor_negative) {
  int n = -2;
  int m = -3;
  
  EXPECT_THROW(S21Matrix matrix(n, m), std::invalid_argument);

}

TEST(constructor, double_constructor_mixed) {
  int n = 2;
  int m = -3;
  
  EXPECT_THROW(S21Matrix matrix(n, m), std::invalid_argument);

}



