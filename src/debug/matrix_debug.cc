/**
 * @file debug.cc
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief 
 * @version 1.0
 * @date 2024-06-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iomanip>
#include "./matrix_debug.h"
#include <iostream>
#include <random>

void MatrixDebug::PrintMatrix(const char *name, const S21Matrix& matrix) const {
  std::cout << name  << this->get_wolfram_notation() <<std::endl;
  std::cout << std::fixed << std::setprecision(7);
  for(int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      
      std::cout << matrix(i, j) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void MatrixDebug::FillRandom(S21Matrix& matrix) noexcept {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dis(-100.0, 100.0);

  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      double random = dis(gen);
      random = std::round(random * 10000.) / 10000.;
      matrix(i, j) = random;
    }
  }
}

void MatrixDebug::UpdateWolframNotation(const S21Matrix& matrix) noexcept {
  wolfram_notation.clear();

  wolfram_notation += "{";

  for (int i = 0; i < matrix.get_rows(); i++) {
    wolfram_notation += "{";

    for (int j = 0; j < matrix.get_cols(); j++) {
      wolfram_notation += std::to_string(matrix(i, j));

      if (j < matrix.get_cols() - 1) {
        wolfram_notation += ", ";
      }
    }
    wolfram_notation += "}";

    if (i < matrix.get_rows() - 1) {
      wolfram_notation += ", ";
    }

  }
  wolfram_notation += "}";

}

double **MatrixDebug::WolframNotationParse(std::string src, int rows, int cols) noexcept {
  double **matrix{AllocateMatrix(rows, cols)};
  src.erase(src.length() - 1);
  src.erase(0, 1);
  src.erase(std::remove(src.begin(), src.end(), ' '), src.end());

  std::stringstream ss(src);
  std::string item;
  std::vector<double> values;

  while (std::getline(ss, item, ',')) {
    item.erase(std::remove(item.begin(), item.end(), '{'), item.end());
    item.erase(std::remove(item.begin(), item.end(), '}'), item.end());

    values.push_back(std::stod(item));
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = values[i * cols + j];
      std::cout << matrix[i][j] <<  ' ';
    }
      std::cout << std::endl;

  }

  return matrix;
}

double **MatrixDebug::AllocateMatrix(int rows, int cols) noexcept {
  double **matrix = new double*[rows];

  for (int i = 0; i < rows; i++) {
    matrix[i] = new double[cols]{};
  }

  return matrix;
}

void MatrixDebug::Free(double **matrix, int rows) noexcept {
  if(matrix){
    for (int i = 0; i < rows; i++) {
      if(matrix[i]) {
        delete[] matrix[i];
        matrix[i] = nullptr;
      }
    }
    delete[] matrix;
    matrix = nullptr;
  }
}

std::string MatrixDebug::get_wolfram_notation() const noexcept { return wolfram_notation; }