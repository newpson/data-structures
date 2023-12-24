#pragma once
#include <cstddef>

class Matrix
{
protected:
	std::size_t mrows;
	std::size_t mcols;
	double **data;

	bool swap(std::size_t i, std::size_t j);

public:
	Matrix();
	Matrix(std::size_t mrows, std::size_t mcols = 1);
	Matrix(const Matrix &obj);
	Matrix(std::size_t mrows, std::size_t mcols, const double &value);
	~Matrix();

	double *operator[](std::size_t i);
	const double *operator[](std::size_t i) const;
	std::size_t rows() const;
	std::size_t cols() const;

	Matrix operator+(const Matrix &obj) const;
	Matrix operator*(const Matrix &obj) const;
	Matrix operator*(const double &k) const;
	Matrix transpose() const;
	double determinant() const;

	friend bool addable(const Matrix &obja, const Matrix &objb);
	friend bool multipliable(const Matrix &obja, const Matrix &objb);
};

