#include "array.hpp"
#include <iostream>

arr_t * arr_init(int m, int n)
{
	arr_t *a = new arr_t;
	a->m = m;
	a->n = n;
	a->data = new int*[m];
	for (int i = 0; i < m; ++i)
	{
		a->data[i] = new int[n];
	}
	return a;
}

void arr_free(arr_t *a)
{
	if (a)
	{
		if (a->data)
		{
			for (int i = 0; i < a->m; ++i)
			{
				delete[] a->data[i];
			}
			delete[] a->data;
		}
		delete a;
	}
}

void arr_fill(arr_t *a)
{
	for (int i = 0; i < a->m; ++i)
	{
		for (int j = 0; j < a->n; ++j)
		{
			std::cin >> a->data[i][j];
		}
	}
}

void arr_print(arr_t *a)
{
	for (int i = 0; i < a->m; ++i)
	{
		for (int j = 0; j < a->n; ++j)
		{
			std::cout << a->data[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void arr_sum(arr_t *a, arr_t *b)
{
	if (a->m == b->m || a->n == b->n)
	{
		for (int i = 0; i < a->m; ++i)
		{
			for (int j = 0; j < a->n; ++j)
			{
				a->data[i][j] += b->data[i][j];
			}
		}
	}
	else
	{
		std::cerr << "size" << std::endl;
	}
}

arr_t * arr_transpose(arr_t *a)
{
	arr_t *b = arr_init(a->n, a->m);
	for (int i = 0; i < a->m; ++i)
	{
		for (int j = 0; j < a->n; ++j)
		{
			b->data[j][i] = a->data[i][j];
		}
	}
	return b;
}

void arr_scalar(arr_t *a, int s)
{
	for (int i = 0; i < a->m; ++i)
	{
		for (int j = 0; j < a->n; ++j)
		{
			a->data[i][j] *= s;
		}
	}
}
