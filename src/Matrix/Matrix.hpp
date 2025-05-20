#pragma once
#include <cstddef>
#include <tuple>

class Matrix
{
    using size_t = std::size_t;
protected:
    size_t m_elements;
    double *data1d;

    size_t m_rows;
    size_t m_cols;
    double **data2d;

    bool swap_columns(const size_t i, const size_t j);
    bool swap_rows(const size_t i, const size_t j);
    Matrix add(const Matrix &A, const double k) const;

public:
    Matrix() = delete;
    Matrix(const size_t r, const size_t c = 1);
    Matrix(const size_t r, const size_t c, const double v);
    Matrix(const Matrix &A);
    ~Matrix();

    double *operator[](const size_t i);
    const double *operator[](const size_t i) const;
    size_t rows() const;
    size_t cols() const;

    Matrix operator+(const Matrix &A) const;
    Matrix operator-(const Matrix &A) const;
    Matrix operator*(const Matrix &A) const;
    Matrix operator*(const double &k) const;

    Matrix transpose() const;
    std::tuple<Matrix, Matrix> LU() const;
    Matrix inverse() const;
    double determinant() const;
};

