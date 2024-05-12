#include "../s21_matrix.h"

// int s21_print_matrix(matrix_t matrix) {
//     int answer = S21_SUCCESS;
//
//     if (!s21_correct_matrix(&matrix)) {
//         for (int i = 0; i < matrix.rows; ++i) {
//             for (int j = 0; j < matrix.columns; ++j) {
//                 printf("%lf  ", matrix.matrix[i][j]);
//                 if (j == matrix.columns - 1) {
//                     putchar('\n');
//                 }
//             }
//         }
//     } else
//         answer = S21_FAILURE;
//
//     return answer;
// }
//
//  int main() {
//     return 0;
//  }