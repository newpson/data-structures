#include "matrix/dynarr.h"
#include "matrix/dynarr-extended.h"
#include <stdio.h>

void matrix_fscan(FILE *in, matrix_t *mx)
{
	for (int r = 0; r < mx->rows; ++r)
	{
		for (int c = 0; c < mx->cols; ++c)
		{
			fscanf(in, "%lf", &mx->data[r][c]);
		}
	}
}

void matrix_fprint(FILE *out, matrix_t *mx)
{
	for (int r = 0; r < mx->rows; ++r)
	{
		for (int c = 0; c < mx->cols; ++c)
		{
			fprintf(out, "%lf\t", mx->data[r][c]);
		}
		fprintf(out, "\n");
	}
}
