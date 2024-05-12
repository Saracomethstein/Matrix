#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;


typedef enum Answer {
    SUCCESS = 0,
    FAILURE = 2,
} Answer;

typedef enum EqualAns {
    EQ_SUCCESS = 1,
    EQ_FAILURE = 0,
} EqualAns;

typedef enum Correct {
    CORRECT = 0,
    NOT_CORRECT = 1,
} Correct;

int create_matrix(int rows, int columns, matrix_t *result);
void remove_matrix(matrix_t *A);

int eq_matrix(matrix_t *A, matrix_t *B);

int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int mul_number(matrix_t *A, double number, matrix_t *result);
int mul_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int transpose(matrix_t *A, matrix_t *result);
int calc_complements(matrix_t *A, matrix_t *result);
int determinant(matrix_t *A, double *result);
int inverse_matrix(matrix_t *A, matrix_t *result);


// TOOLS
void minor_matrix(int rows, int columns, matrix_t *matrix, matrix_t *minor);
int correct_matrix(matrix_t *matrix);
int square_matrix(matrix_t *matrix);
int equal_size_matrix(matrix_t *A, matrix_t *B);
void determinant_matrix(matrix_t *A, double *result);

#endif
