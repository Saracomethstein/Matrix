#include "../matrix.h"

int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int answer = SUCCESS;

  if (!correct_matrix(A) && !correct_matrix(B)) {
    if (!equal_size_matrix(A, B)) {
      create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
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