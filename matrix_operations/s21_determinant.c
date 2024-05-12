#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int answer = S21_SUCCESS;

  if (!s21_correct_matrix(A)) {
    if (!s21_square_matrix(A)) {
      s21_determinant_matrix(A, result);
    } else {
      answer = S21_FAILURE;
    }
  } else {
    answer = S21_NOTCORRECT;
  }

  return answer;
}