#ifndef ARRAY_HPP
#define ARRAY_HPP

typedef struct arr
{
	int m;
	int n;
	int **data;
} arr_edu;

arr_edu * arr_init(int m, int n);
void arr_free(arr_edu *a);

void arr_fill(arr_edu *a);
void arr_print(arr_edu *a);
void arr_sum(arr_edu *a, arr_edu *b);
arr_edu *arr_eduranspose(arr_edu *a);
void arr_scalar(arr_edu *a, int s);

#endif /* ARRAY_HPP */
