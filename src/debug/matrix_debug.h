/**
 * @file debug.h 
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief 
 * @version 1.0
 * @date 2024-06-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef SRC_DEBUG_DEBUG_H_
#define SRC_DEBUG_DEBUG_H_

#include "../include/matrix.h"
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

class MatrixDebug {
 public:
  void PrintMatrix(const char *name, const S21Matrix& matrix) const;
  void FillRandom(S21Matrix& matrix) noexcept;
  std::string get_wolfram_notation() const noexcept;
  void UpdateWolframNotation(const S21Matrix& matrix) noexcept;
  void WolframNotationToArray(const std::string wolfram_notation) noexcept;
  double **WolframNotationParse(std::string src, int rows, int cols) noexcept;
  void Free(double **matrix, int rows) noexcept;
 private:
  std::string wolfram_notation;
  double **AllocateMatrix(int rows, int cols) noexcept;
};

#endif // SRC_DEBUG_DEBUG_H_
