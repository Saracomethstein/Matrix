#include "../matrix.h"

int transpose(matrix_t *A, matrix_t *result) {
  int answer = SUCCESS;

  if (!correct_matrix(A)) {
    create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  } else {
    answer = NOT_CORRECT;
  }

  return answer;
}