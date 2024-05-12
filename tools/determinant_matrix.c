#include "../matrix.h"

void determinant_matrix(matrix_t *A, double *result) {
  double determinant_tmp = 0.0;
  matrix_t minor;
  *result = 0.0;

  if (A->rows == 1)
    *result = A->matrix[0][0];
  else if (A->rows == 2)
    *result = (A->matrix[0][0] * A->matrix[1][1]) -
              (A->matrix[0][1] * A->matrix[1][0]);
  else {
    for (int i = 0; i < A->columns; ++i) {
      minor_matrix(0, i, A, &minor);
      if (determinant(&minor, &determinant_tmp) == 0) {
        *result += A->matrix[0][i] * determinant_tmp * pow(-1, i);
      }
      remove_matrix(&minor);
    }
  }
}