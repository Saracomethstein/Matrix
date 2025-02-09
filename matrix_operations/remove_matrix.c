#include "../matrix.h"

void remove_matrix(matrix_t *A) {
  if (!correct_matrix(A)) {
    for (int i = 0; i < A->rows; ++i) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->columns = 0;
    A->rows = 0;
  }
}