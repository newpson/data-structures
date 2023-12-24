#include "matrix-extended.h"
#include <stdio.h>

int main(void)
{
	matrix_t *a = matrix_init(3, 1);
	matrix_t *b = matrix_init(1, 3);

	printf("Enter 3x1 matrix:\n");
	matrix_fscan(stdin, a);
	printf("Enter 1x3 matrix:\n");
	matrix_fscan(stdin, b);

	printf("You entered (A):\n");
	matrix_fprint(stdout, a);
	printf("You entered (B):\n");
	matrix_fprint(stdout, b);

	if (matrix_addable(a, b))
	{
		printf("A and B are addable.\n");
		matrix_add(a, b);
		printf("A+B:\n");
		matrix_fprint(stdout, a);
	}
	else
	{
		printf("A and B are not addable.\n");
	}

	matrix_transpose(a);
	printf("Transposed A:\n");
	matrix_fprint(stdout, a);
	printf("Transposed A back.\n");
	matrix_transpose(a);

	printf("You entered (A):\n");
	matrix_fprint(stdout, a);
	printf("You entered (B):\n");
	matrix_fprint(stdout, b);
	if (matrix_multipliable(b, a))
	{
		printf("B and A are multipliable.\n");
		matrix_multiply(b, a);
		printf("B*A:\n");
		matrix_fprint(stdout, b);
	}
	else
	{
		printf("B and A are not multipliable.\n");
	}

	matrix_free(a);
	matrix_free(b);
	return 0;
}
