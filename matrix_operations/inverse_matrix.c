#include "../matrix.h"

int inverse_matrix(matrix_t *A, matrix_t *result) {
  int answer = SUCCESS;
  double determinant_tmp = 0.0;
  matrix_t complements = {0};
  matrix_t transpose_tmp = {0};

  if (!correct_matrix(A)) {
    if (determinant(A, &determinant_tmp) == 0 && determinant_tmp != 0) {
      if (calc_complements(A, &complements) == 0) {
        transpose(&complements, &transpose_tmp);
        mul_number(&transpose_tmp, 1. / determinant_tmp, result);
        remove_matrix(&complements);
        remove_matrix(&transpose_tmp);
      }
    } else {
      answer = FAILURE;
    }
  } else {
    answer = NOT_CORRECT;
  }
  return answer;
}