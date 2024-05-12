#include "../matrix.h"

void minor_matrix(int rows, int columns, matrix_t *matrix, matrix_t *minor) {
  int rows_i = 0;
  int columns_j = 0;
  create_matrix(matrix->rows - 1, matrix->columns - 1, minor);

  for (int i = 0; i < minor->rows; ++i) {
    if (i == rows) rows_i++;
    columns_j = 0;
    for (int j = 0; j < minor->columns; ++j) {
      if (j == columns) columns_j++;
      minor->matrix[i][j] = matrix->matrix[i + rows_i][j + columns_j];
    }
  }
}