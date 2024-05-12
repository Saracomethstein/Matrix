#ifndef S21_MATRIX_H
#define S21_MATRIX_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;


typedef enum Answer {
    S21_SUCCESS = 0,
    S21_FAILURE = 2,
} Answer;

typedef enum EqualAns {
    S21_EQSUCCESS = 1,
    S21_EQFAILURE = 0,
} EqualAns;

typedef enum Correct {
    S21_CORRECT = 0,
    S21_NOTCORRECT = 1,
} Correct;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);


// TOOLS
void s21_minor_matrix(int rows, int columns, matrix_t *matrix, matrix_t *minor);
int s21_correct_matrix(matrix_t *matrix);
int s21_square_matrix(matrix_t *matrix);
int s21_equal_size_matrix(matrix_t *A, matrix_t *B);
void s21_determinant_matrix(matrix_t *A, double *result);

#endif
