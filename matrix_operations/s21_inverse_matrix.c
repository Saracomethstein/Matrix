#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int answer = S21_SUCCESS;
  double determinant = 0.0;
  matrix_t complements = {0};
  matrix_t transpose = {0};

  if (!s21_correct_matrix(A)) {
    if (s21_determinant(A, &determinant) == 0 && determinant != 0) {
      if (s21_calc_complements(A, &complements) == 0) {
        s21_transpose(&complements, &transpose);
        s21_mult_number(&transpose, 1. / determinant, result);
        s21_remove_matrix(&complements);
        s21_remove_matrix(&transpose);
      }
    } else {
      answer = S21_FAILURE;
    }
  } else {
    answer = S21_NOTCORRECT;
  }
  return answer;
}