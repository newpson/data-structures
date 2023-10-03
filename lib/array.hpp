#ifndef ARRAY_HPP
#define ARRAY_HPP

typedef struct arr
{
	int m;
	int n;
	int **data;
} arr_t;

arr_t * arr_init(int m, int n);
void arr_free(arr_t *a);

void arr_fill(arr_t *a);
void arr_print(arr_t *a);
void arr_sum(arr_t *a, arr_t *b);
arr_t *arr_transpose(arr_t *a);
void arr_scalar(arr_t *a, int s);

#endif /* ARRAY_HPP */
