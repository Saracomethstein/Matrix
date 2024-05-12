#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int answer = S21_SUCCESS;
  matrix_t minor;

  if (!s21_correct_matrix(A)) {
    if (!s21_square_matrix(A)) {
      s21_create_matrix(A->rows, A->columns, result);
      if (A->columns == 1) {
        result->matrix[0][0] = A->matrix[0][0];
      } else {
        for (int i = 0; i < A->rows; ++i) {
          for (int j = 0; j < A->columns; ++j) {
            s21_minor_matrix(i, j, A, &minor);
            s21_determinant(&minor, &result->matrix[i][j]);
            result->matrix[i][j] *= pow(-1, (i + j));
            s21_remove_matrix(&minor);
          }
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