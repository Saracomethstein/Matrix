#include "../matrix.h"

int eq_matrix(matrix_t *A, matrix_t *B) {
  int answer = EQ_SUCCESS;

  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) {
        answer = EQ_FAILURE;
        break;
      }
    }
  }

  return answer;
}
