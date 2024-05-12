#include "../matrix.h"

int mul_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int answer = SUCCESS;

  if (!correct_matrix(A) && !correct_matrix(B)) {
    if (A->columns == B->rows) {
      create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < B->columns; ++j) {
          for (int k = 0; k < B->rows; ++k) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
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