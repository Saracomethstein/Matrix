#include <check.h>

#include "../matrix.h"

START_TEST(create_matrix_test1) {
  matrix_t m1;
  int result;
  result = create_matrix(1, 3, &m1);
  ck_assert_int_eq(result, 0);
  remove_matrix(&m1);
}
END_TEST

START_TEST(create_matrix_test2) {
  matrix_t m1 = {NULL, 0, 0};
  int result = 0;
  result = create_matrix(3, 1, &m1);
  ck_assert_int_eq(result, 0);
  remove_matrix(&m1);
}
END_TEST

START_TEST(create_matrix_test3) {
  matrix_t m1 = {NULL, 0, 0};
  int result = 0;
  result = create_matrix(0, 3, &m1);
  ck_assert_int_eq(result, 1);
  remove_matrix(&m1);
}
END_TEST

START_TEST(create_matrix_test4) {
  matrix_t m1 = {NULL, 0, 0};
  int result = 0;
  result = create_matrix(-1, -3, &m1);
  ck_assert_int_eq(result, 1);
  remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix_test) {
  matrix_t m1, m2;
  int result;

  create_matrix(3, 3, &m1);
  create_matrix(3, 3, &m2);
  result = eq_matrix(&m1, &m2);
  ck_assert_int_eq(result, 1);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      m1.matrix[i][j] = i + j;
      m2.matrix[i][j] = i + j;
    }
  }

  result = eq_matrix(&m1, &m2);
  ck_assert_int_eq(result, 1);

  m1.matrix[0][0] = 10;

  result = eq_matrix(&m1, &m2);
  ck_assert_int_eq(result, 0);

  remove_matrix(&m1);
  remove_matrix(&m2);

  create_matrix(3, 4, &m1);
  create_matrix(4, 3, &m2);
  result = eq_matrix(&m1, &m2);
  ck_assert_int_eq(result, 1);

  remove_matrix(&m1);
  remove_matrix(&m2);
}
END_TEST

START_TEST(sum_matrix_test) {
  matrix_t m1 = {NULL, 0, 0}, m2 = {NULL, 0, 0}, m3 = {NULL, 0, 0};
  int result;

  create_matrix(2, 2, &m1);
  create_matrix(2, 2, &m2);

  result = sum_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 0);
  remove_matrix(&m3);

  m1.matrix[0][0] = 5;

  result = sum_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 0);
  remove_matrix(&m1);
  remove_matrix(&m2);
  remove_matrix(&m3);

  create_matrix(2, 3, &m1);
  create_matrix(3, 2, &m2);

  result = sum_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 2);
  remove_matrix(&m1);
  remove_matrix(&m2);

  create_matrix(-2, 3, &m1);
  create_matrix(3, 2, &m2);

  result = sum_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 1);
  remove_matrix(&m1);
  remove_matrix(&m2);
}
END_TEST

START_TEST(sub_matrix_test) {
  matrix_t m1 = {NULL, 0, 0}, m2 = {NULL, 0, 0}, m3 = {NULL, 0, 0};
  int result;

  create_matrix(2, 2, &m1);
  create_matrix(2, 2, &m2);
  result = sub_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 0);
  remove_matrix(&m3);

  m1.matrix[0][0] = 5;
  result = sub_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 0);
  remove_matrix(&m1);
  remove_matrix(&m2);
  remove_matrix(&m3);

  create_matrix(2, 3, &m1);
  create_matrix(3, 2, &m2);
  result = sub_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 2);
  remove_matrix(&m1);
  remove_matrix(&m2);

  create_matrix(-2, 3, &m1);
  create_matrix(3, 2, &m2);
  result = sub_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 1);
  remove_matrix(&m1);
  remove_matrix(&m2);
}
END_TEST

START_TEST(mul_number_test) {
  int result;
  matrix_t m1, m2;

  create_matrix(3, 3, &m1);
  result = mul_number(&m1, 5, &m2);
  ck_assert_int_eq(result, 0);
  remove_matrix(&m1);
  remove_matrix(&m2);

  create_matrix(3, 0, &m1);
  result = mul_number(&m1, 0, &m2);
  ck_assert_int_eq(result, 1);
  remove_matrix(&m1);
  remove_matrix(&m2);
}
END_TEST

START_TEST(mul_matrix_test) {
  int result;
  matrix_t m1, m2, m3;

  // // Default test 1
  create_matrix(3, 3, &m1);
  create_matrix(3, 3, &m2);
  result = mul_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 0);
  remove_matrix(&m1);
  remove_matrix(&m2);
  remove_matrix(&m3);

  // Default test 2
  create_matrix(3, 4, &m1);
  create_matrix(4, 3, &m2);
  result = mul_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 0);
  remove_matrix(&m1);
  remove_matrix(&m2);
  remove_matrix(&m3);

  // Default test 3
  create_matrix(1, 5, &m1);
  create_matrix(5, 3, &m2);
  result = mul_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 0);
  remove_matrix(&m1);
  remove_matrix(&m2);
  remove_matrix(&m3);

  // Incorrect test 1
  create_matrix(-3, 4, &m1);
  create_matrix(4, 3, &m2);
  result = mul_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 1);
  remove_matrix(&m1);
  remove_matrix(&m2);
  remove_matrix(&m3);

  // Incorrect test 2
  create_matrix(3, 4, &m1);
  create_matrix(5, -3, &m2);
  result = mul_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 1);
  remove_matrix(&m1);
  remove_matrix(&m2);
  remove_matrix(&m3);

  // Arth error test 1
  create_matrix(1, 5, &m1);
  create_matrix(2, 4, &m2);
  result = mul_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 2);
  remove_matrix(&m1);
  remove_matrix(&m2);
  remove_matrix(&m3);

  // Functional test 1
  create_matrix(1, 3, &m1);
  create_matrix(3, 2, &m2);
  m1.matrix[0][0] = 1;
  m1.matrix[0][1] = 2;
  m1.matrix[0][2] = 3;

  m2.matrix[0][0] = 1;
  m2.matrix[0][1] = 2;
  m2.matrix[1][0] = 3;
  m2.matrix[1][1] = 4;
  m2.matrix[2][0] = 5;
  m2.matrix[2][1] = 6;

  double res1[1][2] = {{22, 28}};
  result = mul_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 2; j++) {
      ck_assert_double_eq_tol(m3.matrix[i][j], res1[i][j], 1e-7);
    }
  }
  remove_matrix(&m1);
  remove_matrix(&m2);
  remove_matrix(&m3);

  // Functional test 2
  create_matrix(2, 2, &m1);
  create_matrix(2, 3, &m2);
  m1.matrix[0][0] = 1;
  m1.matrix[0][1] = 2;
  m1.matrix[1][0] = 3;
  m1.matrix[1][1] = 1;

  m2.matrix[0][0] = 5;
  m2.matrix[0][1] = 2;
  m2.matrix[0][2] = 5;
  m2.matrix[1][0] = 2;
  m2.matrix[1][1] = 5;
  m2.matrix[1][2] = 2;

  double res2[2][3] = {{9, 12, 9}, {17, 11, 17}};

  result = mul_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(m3.matrix[i][j], res2[i][j], 1e-7);
    }
  }
  remove_matrix(&m1);
  remove_matrix(&m2);
  remove_matrix(&m3);
}
END_TEST

START_TEST(transpose_test) {
  int result;
  matrix_t m1 = {NULL, 0, 0}, m2 = {NULL, 0, 0};

  // Default test
  create_matrix(3, 3, &m1);
  result = transpose(&m1, &m2);
  ck_assert_int_eq(result, 0);
  remove_matrix(&m1);
  remove_matrix(&m2);

  // Incorrect test
  create_matrix(3, -3, &m1);
  result = transpose(&m1, &m2);
  ck_assert_int_eq(result, 1);
  remove_matrix(&m1);
  remove_matrix(&m2);

  // Non-square matrix test 1
  create_matrix(2, 4, &m1);
  m1.matrix[0][0] = 1;
  m1.matrix[0][1] = 2;
  m1.matrix[0][2] = 3;
  m1.matrix[0][3] = 4;
  m1.matrix[1][0] = 5;
  m1.matrix[1][1] = 6;
  m1.matrix[1][2] = 7;
  m1.matrix[1][3] = 8;
  double res1[4][2] = {
      {1, 5},
      {2, 6},
      {3, 7},
      {4, 8},
  };
  result = transpose(&m1, &m2);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      ck_assert_double_eq_tol(m2.matrix[i][j], res1[i][j], 1e-7);
    }
  }
  remove_matrix(&m1);
  remove_matrix(&m2);

  // //     Non-square matrix test 2
  create_matrix(4, 2, &m1);
  m1.matrix[0][0] = 1;
  m1.matrix[0][1] = 2;
  m1.matrix[1][0] = 3;
  m1.matrix[1][1] = 4;
  m1.matrix[2][0] = 5;
  m1.matrix[2][1] = 6;
  m1.matrix[3][0] = 7;
  m1.matrix[3][1] = 8;
  double res2[2][4] = {{1, 3, 5, 7}, {2, 4, 6, 8}};
  result = transpose(&m1, &m2);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_double_eq_tol(m2.matrix[i][j], res2[i][j], 1e-7);
    }
  }
  remove_matrix(&m1);
  remove_matrix(&m2);
}
END_TEST

START_TEST(determinant_test) {
  int result;
  double output;
  matrix_t m1 = {NULL, 0, 0};

  create_matrix(3, 3, &m1);
  m1.matrix[0][0] = 1;
  m1.matrix[0][1] = 3;
  m1.matrix[0][2] = 2;
  m1.matrix[1][0] = 4;
  m1.matrix[1][1] = 6;
  m1.matrix[1][2] = 7;
  m1.matrix[2][0] = 3;
  m1.matrix[2][1] = 4;
  m1.matrix[2][2] = 0;

  result = determinant(&m1, &output);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(output, 31, 1e-4);
  remove_matrix(&m1);

  create_matrix(-1, 3, &m1);
  result = determinant(&m1, &output);
  ck_assert_int_eq(result, 1);
  remove_matrix(&m1);

  create_matrix(4, 3, &m1);
  result = determinant(&m1, &output);
  ck_assert_int_eq(result, 2);
  remove_matrix(&m1);

  create_matrix(3, 4, &m1);
  result = determinant(&m1, &output);
  ck_assert_int_eq(result, 2);
  remove_matrix(&m1);

  // One more
  create_matrix(2, 2, &m1);
  m1.matrix[0][0] = 3;
  m1.matrix[0][1] = 2;
  m1.matrix[1][0] = 7;
  m1.matrix[1][1] = -1;
  result = determinant(&m1, &output);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(output, -17, 1e-7);
  remove_matrix(&m1);

  // One more
  create_matrix(1, 1, &m1);
  m1.matrix[0][0] = 5;
  result = determinant(&m1, &output);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(output, 5, 1e-7);
  remove_matrix(&m1);
}
END_TEST

START_TEST(calc_complements_test) {
  matrix_t m1 = {NULL, 0, 0}, m2 = {NULL, 0, 0};
  int result = 1;

  // Test for incorrect sizes

  // // Test 1
  create_matrix(0, 3, &m1);
  result = calc_complements(&m1, &m2);
  ck_assert_int_eq(result, 1);

  // // Test 2
  create_matrix(3, -1, &m1);
  result = calc_complements(&m1, &m2);
  ck_assert_int_eq(result, 1);

  // // Test for non-square matrix

  // // Test 3
  create_matrix(2, 3, &m1);
  result = calc_complements(&m1, &m2);
  ck_assert_int_eq(result, 2);
  remove_matrix(&m1);

  // // Test 4
  create_matrix(3, 2, &m1);
  result = calc_complements(&m1, &m2);
  ck_assert_int_eq(result, 2);
  remove_matrix(&m1);

  // // Test 5
  create_matrix(1, 1, &m1);
  result = calc_complements(&m1, &m2);
  ck_assert_int_eq(result, 0);
  remove_matrix(&m1);

  // Functional test

  // Test 5 (3x3)
  create_matrix(3, 3, &m1);
  m1.matrix[0][0] = 1;
  m1.matrix[0][1] = 2;
  m1.matrix[0][2] = 3;
  m1.matrix[1][0] = 0;
  m1.matrix[1][1] = 4;
  m1.matrix[1][2] = 2;
  m1.matrix[2][0] = 5;
  m1.matrix[2][1] = 2;
  m1.matrix[2][2] = 1;

  double res1[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};

  result = calc_complements(&m1, &m2);
  ck_assert_int_eq(result, 0);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(m2.matrix[i][j], res1[i][j], 1e-7);
    }
  }
  remove_matrix(&m1);
  remove_matrix(&m2);

  //   Test 6 (2x2)
  create_matrix(2, 2, &m1);
  m1.matrix[0][0] = 1;
  m1.matrix[0][1] = -5;
  m1.matrix[1][0] = 3;
  m1.matrix[1][1] = -4;

  double res2[2][2] = {{-4, -3}, {5, 1}};

  result = calc_complements(&m1, &m2);
  ck_assert_int_eq(result, 0);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ck_assert_double_eq_tol(m2.matrix[i][j], res2[i][j], 1e-7);
    }
  }
  remove_matrix(&m1);
  remove_matrix(&m2);
}
END_TEST

START_TEST(inverse_matrix_test) {
  matrix_t m1 = {NULL, 0, 0}, m2 = {NULL, 0, 0};
  int result;

  // Test for incorrect sizes

  // Test 1
  create_matrix(0, 3, &m1);
  result = inverse_matrix(&m1, &m2);
  ck_assert_int_eq(result, 1);

  // Test 2
  create_matrix(3, -1, &m1);
  result = inverse_matrix(&m1, &m2);
  ck_assert_int_eq(result, 1);

  // Test 3
  create_matrix(2, 3, &m1);
  result = inverse_matrix(&m1, &m2);
  ck_assert_int_eq(result, 2);
  remove_matrix(&m1);

  // Test 4
  create_matrix(3, 2, &m1);
  result = inverse_matrix(&m1, &m2);
  ck_assert_int_eq(result, 2);
  remove_matrix(&m1);

  // Functional test

  // Test 5 (3x3)
  create_matrix(3, 3, &m1);
  m1.matrix[0][0] = 2;
  m1.matrix[0][1] = 5;
  m1.matrix[0][2] = 7;
  m1.matrix[1][0] = 6;
  m1.matrix[1][1] = 3;
  m1.matrix[1][2] = 4;
  m1.matrix[2][0] = 5;
  m1.matrix[2][1] = -2;
  m1.matrix[2][2] = -3;

  double res1[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};

  result = inverse_matrix(&m1, &m2);
  ck_assert_int_eq(result, 0);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(m2.matrix[i][j], res1[i][j], 1e-7);
    }
  }
  remove_matrix(&m1);
  remove_matrix(&m2);

  //   Test 6 (2x2)
  create_matrix(2, 2, &m1);
  m1.matrix[0][0] = 1;
  m1.matrix[0][1] = 2;
  m1.matrix[1][0] = 3;
  m1.matrix[1][1] = 4;

  double res2[2][2] = {{-2, 1}, {3.0 / 2.0, -1.0 / 2.0}};

  result = inverse_matrix(&m1, &m2);
  ck_assert_int_eq(result, 0);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ck_assert_double_eq_tol(m2.matrix[i][j], res2[i][j], 1e-7);
    }
  }

  remove_matrix(&m1);
  remove_matrix(&m2);
}
END_TEST

Suite *matrix_tests_create() {
  Suite *matrix = suite_create("matrix");
  TCase *matrix_tests = tcase_create("MATRIX");

  tcase_add_test(matrix_tests, create_matrix_test1);
  tcase_add_test(matrix_tests, create_matrix_test2);
  tcase_add_test(matrix_tests, create_matrix_test3);
  tcase_add_test(matrix_tests, create_matrix_test4);
  tcase_add_test(matrix_tests, eq_matrix_test);
  tcase_add_test(matrix_tests, sum_matrix_test);
  tcase_add_test(matrix_tests, sub_matrix_test);
  tcase_add_test(matrix_tests, mul_number_test);
  tcase_add_test(matrix_tests, mul_matrix_test);
  tcase_add_test(matrix_tests, transpose_test);
  tcase_add_test(matrix_tests, determinant_test);
  tcase_add_test(matrix_tests, calc_complements_test);
  tcase_add_test(matrix_tests, inverse_matrix_test);

  suite_add_tcase(matrix, matrix_tests);
  return matrix;
}

int main() {
  Suite *matrix = matrix_tests_create();
  SRunner *matrix_runner = srunner_create(matrix);
  float number_failed;
  srunner_run_all(matrix_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(matrix_runner);
  srunner_free(matrix_runner);

  return number_failed == 0 ? 0 : 1;
}
