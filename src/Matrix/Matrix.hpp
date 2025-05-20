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

public:
    Matrix() = delete;
    Matrix(size_t m_rows, size_t m_cols = 1);
    Matrix(size_t m_rows, size_t m_cols, double v);
    Matrix(const Matrix &obj);
    ~Matrix();

    double *operator[](const size_t i);
    const double *operator[](const size_t i) const;
    size_t rows() const;
    size_t cols() const;

    Matrix operator+(const Matrix &obj) const;
    Matrix operator*(const Matrix &obj) const;
    Matrix operator*(const double &k) const;

    Matrix transpose() const;
    std::tuple<Matrix, Matrix> LU() const;
    double determinant() const;
};

