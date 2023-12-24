#include "Matrix.hpp"
#include <cstddef>
#include <algorithm>

Matrix::Matrix():
	mrows(1), mcols(1), data(new double*[1])
{
	*data = new double[1];
	**data = 0;
}

Matrix::Matrix(std::size_t mrows, std::size_t mcols):
	mrows(mrows), mcols(mcols)
{
	if (mrows < 1)
	{
		mrows = 1;
	}
	if (mcols < 1)
	{
		mcols = 1;
	}
	data = new double*[mrows];
	for (std::size_t i = 0; i < mrows; ++i)
	{
		data[i] = new double[mcols];
	}
}

Matrix::Matrix(const Matrix &obj):
	Matrix(obj.mrows, obj.mcols)
{
	for (std::size_t i = 0; i < mrows; ++i)
	{
		std::copy_n(obj[i], mcols, data[i]);
	}
}

Matrix::Matrix(std::size_t mrows, std::size_t mcols, const double &value):
	Matrix(mrows, mcols)
{
	for (std::size_t i = 0; i < mrows; ++i)
	{
		for (std::size_t j = 0; j < mcols; ++j)
		{
			data[i][j] = value;
		}
	}
}

Matrix::~Matrix()
{
	for (std::size_t i = 0; i < mrows; ++i)
	{
		delete[] data[i];
	}
	delete[] data;
	data = nullptr;
}

double *Matrix::operator[](std::size_t i)
{
	return data[i];
}

const double *Matrix::operator[](std::size_t i) const
{
	return data[i];
}

std::size_t Matrix::rows() const
{
	return mrows;
}

std::size_t Matrix::cols() const
{
	return mcols;
}

Matrix Matrix::operator+(const Matrix &obj) const
{
	if (addable(*this, obj))
	{
		Matrix tobj(mrows, mcols);
		for (std::size_t i = 0; i < mrows; ++i)
		{
			for (std::size_t j = 0; j < mcols; ++j)
			{
				tobj[i][j] = data[i][j] + obj[i][j];
			}
		}
		return tobj;
	}
	return Matrix();
}

Matrix Matrix::operator*(const Matrix &obj) const
{
	if (multipliable(*this, obj))
	{
		Matrix tobj(mrows, obj.mcols, 0);
		for (int j = 0; j < tobj.mcols; ++j)
		{
			for (int i = 0; i < tobj.mrows; ++i)
			{
				for (int k = 0; k < mcols; ++k)
				{
					tobj[i][j] += data[i][k] * obj[k][j];
				}
			}
		}
		return tobj;
	}
	return Matrix();
}

Matrix Matrix::operator*(const double &k) const
{
	Matrix tobj(mrows, mcols);
	for (std::size_t i = 0; i < mrows; ++i)
	{
		for (std::size_t j = 0; j < mcols; ++j)
		{
			tobj[i][j] = k*data[i][j];
		}
	}
	return tobj;
}

Matrix Matrix::transpose() const
{
	Matrix tobj(mcols, mrows);
	for (std::size_t i = 0; i < mrows; ++i)
	{
		for (std::size_t j = 0; j < mcols; ++j)
		{
			tobj[j][i] = data[i][j];
		}
	}
	return tobj;
}

bool Matrix::swap(std::size_t i, std::size_t j)
{
	if (i != j)
	{
		double *temp = data[i];
		data[i] = data[j];
		data[j] = temp;
		return true;
	}
	return false;
}

double Matrix::determinant() const
{
	if (mrows != mcols)
	{
		return 0;
	}

	double D = 1;
	Matrix m(*this);

	// Modified Gaussian algorithm.
	// "Recursive" determinant calculating (see Block matrices).
	for (std::size_t k = 0; k < m.mcols-1; ++k)
	{
		// Look for first non-zero element.
		for (std::size_t i = k; i < m.mrows; ++i)
		{
			if (m[i][k] != 0)
			{
				// Swap row containing non-zero element with first row.
				// Invert determinant if lines actually been swapped.
				D *= (m.swap(k, i) ? -m[k][k] : m[k][k]);
				break;
			}
		}
		if (m[k][k] == 0)
		{
			// First element will be zero only if the whole column is null.
			return 0;
		}

		// Actually, we don't use any elements outside current square submatrix,
		// so we can just firstly divide whole row by its first element...
		double denominator = m[k][k];
		for (std::size_t j = k; j < m.mcols; ++j)
		{
			m[k][j] /= denominator;
		}

		for (std::size_t i = k+1; i < m.mrows; ++i)
		{
			// ...and then add first row multiplied by first element of every row
			// below to every row below.
			double numerator = -m[i][k];
			for (std::size_t j = k; j < m.mcols; ++j)
			{
				m[i][j] += numerator * m[k][j];
			}
		}
	}

	// The last bottom right element is remaining to be multiplied by D.
	return D*m[m.mrows-1][m.mrows-1];
}

bool addable(const Matrix &obja, const Matrix &objb)
{
	return (obja.mrows == objb.mrows && obja.mcols == objb.mcols);
}

bool multipliable(const Matrix &obja, const Matrix &objb)
{
	return (obja.mcols == objb.mrows);
}
