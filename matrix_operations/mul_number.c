#include "../matrix.h"

int mul_number(matrix_t *A, double number, matrix_t *result) {
  int answer = SUCCESS;

  if (!correct_matrix(A)) {
    create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else {
    answer = NOT_CORRECT;
  }

  return answer;
}