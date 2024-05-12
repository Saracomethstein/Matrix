#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int answer = S21_SUCCESS;

  if (!s21_correct_matrix(A) && !s21_correct_matrix(B)) {
    if (!s21_equal_size_matrix(A, B)) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }

    } else {
      answer = S21_FAILURE;
    }
  } else {
    answer = S21_NOTCORRECT;
  }

  return answer;
}