#include "matrix/dynarr.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

matrix_t *matrix_init(int rows, int cols)
{
	matrix_t *mx = malloc(sizeof(matrix_t));
	mx->rows = rows;
	mx->cols = cols;

	mx->data = malloc(rows*sizeof(double *));
	while (rows--)
	{
		mx->data[rows] = malloc(cols*sizeof(double));
	}

	return mx;
}

void matrix_fill(matrix_t *mx, double a)
{
	for (int r = 0; r < mx->rows; ++r)
	{
		for (int c = 0; c < mx->cols; ++c)
		{
			mx->data[r][c] = a;
		}
	}
}

static
void matrix_free_data(matrix_t *mx)
{
	while (mx->rows--)
	{
		free(mx->data[mx->rows]);
	}
	free(mx->data);
	mx->data = NULL;
}

static
void matrix_clone(matrix_t *dst, matrix_t *src)
{
	if (dst->data)
	{
		matrix_free_data(dst);
	}
	dst->rows = src->rows;
	dst->cols = src->cols;
	dst->data = src->data;
}


void matrix_free(matrix_t *mx)
{
	if (mx)
	{
		matrix_free_data(mx);
		free(mx);
	}
}

bool matrix_addable(matrix_t *mxa, matrix_t *mxb)
{
	return (mxa->rows == mxb->rows && mxa->cols == mxb->cols);
}

void matrix_add(matrix_t *mxa, matrix_t *mxb)
{
	for (int r = 0; r < mxa->rows; ++r)
	{
		for (int c = 0; c < mxa->cols; ++c)
		{
			mxa->data[r][c] += mxb->data[r][c];
		}
	}
}

void matrix_scale(matrix_t *mx, double k)
{
	for (int r = 0; r < mx->rows; ++r)
	{
		for (int c = 0; c < mx->cols; ++c)
		{
			mx->data[r][c] *= k;
		}
	}
}

bool matrix_multipliable(matrix_t *mxa, matrix_t *mxb)
{
	return mxa->cols == mxb->rows;
}

void matrix_multiply(matrix_t *mxa, matrix_t *mxb)
{
	matrix_t *mx = matrix_init(mxa->rows, mxb->cols);
	matrix_fill(mx, 0);

	for (int c = 0; c < mx->cols; ++c)
	{
		for (int r = 0; r < mx->rows; ++r)
		{
			for (int i = 0; i < mxa->cols; ++i)
			{
				mx->data[r][c] += mxa->data[r][i] * mxb->data[i][c];
			}
		}
	}

	matrix_clone(mxa, mx);
	free(mx);
}

void matrix_transpose(matrix_t *mx)
{
	matrix_t *mxt = matrix_init(mx->cols, mx->rows);

	for (int r = 0; r < mx->rows; ++r)
	{
		for (int c = 0; c < mx->cols; ++c)
		{
			mxt->data[c][r] = mx->data[r][c];
		}
	}

	matrix_clone(mx, mxt);
	free(mxt);
}

