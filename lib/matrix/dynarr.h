#ifndef MATRIX_DYNARR_H
#define MATRIX_DYNARR_H

#include <stdbool.h>

typedef struct
{
	int rows;
	int cols;
	double **data;
} matrix_t;

matrix_t *matrix_init(int rows, int cols);
void matrix_free(matrix_t *mx);
void matrix_fill(matrix_t *mx, double a);

bool matrix_addable(matrix_t *mxa, matrix_t *mxb);
void matrix_add(matrix_t *mxa, matrix_t *mxb);

void matrix_scale(matrix_t *mx, double k);

bool matrix_multipliable(matrix_t *mxa, matrix_t *mxb);
void matrix_multiply(matrix_t *mxa, matrix_t *mxb);

void matrix_transpose(matrix_t *mx);

#endif /* MATRIX_DYNARR_H */
