#include "../s21_matrix.h"

int s21_correct_matrix(matrix_t *matrix) {
  return matrix == NULL || matrix->rows <= 0 || matrix->columns <= 0 ||
                 matrix->matrix == NULL
             ? S21_NOTCORRECT
             : S21_CORRECT;
}

int s21_square_matrix(matrix_t *matrix) {
  return matrix->rows == matrix->columns ? S21_CORRECT : S21_NOTCORRECT;
}

int s21_equal_size_matrix(matrix_t *A, matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns ? S21_CORRECT
                                                        : S21_NOTCORRECT;
}