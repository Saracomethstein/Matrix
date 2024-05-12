#include "../matrix.h"

int determinant(matrix_t *A, double *result) {
  int answer = SUCCESS;

  if (!correct_matrix(A)) {
    if (!square_matrix(A)) {
      determinant_matrix(A, result);
    } else {
      answer = FAILURE;
    }
  } else {
    answer = NOT_CORRECT;
  }

  return answer;
}