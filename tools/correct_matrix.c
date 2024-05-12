#include "../matrix.h"

int correct_matrix(matrix_t *matrix) {
  return matrix == NULL || matrix->rows <= 0 || matrix->columns <= 0 ||
                 matrix->matrix == NULL
             ? NOT_CORRECT
             : CORRECT;
}

int square_matrix(matrix_t *matrix) {
  return matrix->rows == matrix->columns ? CORRECT : NOT_CORRECT;
}

int equal_size_matrix(matrix_t *A, matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns ? CORRECT : NOT_CORRECT;
}