#include "../matrix.h"

int create_matrix(int rows, int columns, matrix_t *result) {
  int answer = SUCCESS;

  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL)
      answer = FAILURE;
    else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
      }
    }
  } else
    answer = NOT_CORRECT;

  return answer;
}
