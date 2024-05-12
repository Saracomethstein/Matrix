#include "../matrix.h"

int calc_complements(matrix_t *A, matrix_t *result) {
  int answer = SUCCESS;
  matrix_t minor;

  if (!correct_matrix(A)) {
    if (!square_matrix(A)) {
      create_matrix(A->rows, A->columns, result);
      if (A->columns == 1) {
        result->matrix[0][0] = A->matrix[0][0];
      } else {
        for (int i = 0; i < A->rows; ++i) {
          for (int j = 0; j < A->columns; ++j) {
            minor_matrix(i, j, A, &minor);
            determinant(&minor, &result->matrix[i][j]);
            result->matrix[i][j] *= pow(-1, (i + j));
            remove_matrix(&minor);
          }
        }
      }
    } else {
      answer = FAILURE;
    }
  } else {
    answer = NOT_CORRECT;
  }

  return answer;
}