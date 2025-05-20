#include "Matrix.hpp"
#include <algorithm>
#include <stdexcept>

bool addable(const Matrix &A, const Matrix &B)
{
    return (A.rows() == B.rows() && A.cols() == B.cols());
}

bool multipliable(const Matrix &A, const Matrix &B)
{
    return (A.cols() == B.rows());
}

Matrix::Matrix(const size_t r, const size_t c)
    : m_rows(r), m_cols(c), m_elements(r * c)
{
    if (m_elements == 0)
        throw std::runtime_error("invalid dimensions");
    data1d = new double[m_elements];
    data2d = new double*[m_rows];
    for (size_t i = 0; i < m_rows; ++i)
        data2d[i] = data1d + i*m_cols;
}

Matrix::Matrix(const size_t r, const size_t c, const double v)
    : Matrix(r, c)
{
    std::fill_n(data1d, m_elements, v);
}


Matrix::Matrix(const Matrix &A)
    : Matrix(A.m_rows, A.m_cols)
{
    std::copy_n(A.data1d, A.m_elements, data1d);
}

Matrix::~Matrix()
{
    delete[] data2d;
    delete[] data1d;
}

double *Matrix::operator[](const size_t i)
{
    return data2d[i];
}

const double *Matrix::operator[](const size_t i) const
{
    return data2d[i];
}

size_t Matrix::rows() const
{
    return m_rows;
}

size_t Matrix::cols() const
{
    return m_cols;
}

Matrix Matrix::add(const Matrix &A, const double k) const
{
    if (!addable(*this, A))
        throw std::invalid_argument("matrices are not addable");

    Matrix R(m_rows, m_cols);
    for (size_t i = 0; i < m_elements; ++i)
        R.data1d[i] = data1d[i] + k * A.data1d[i];
    return R;
}

Matrix Matrix::operator+(const Matrix &A) const
{
    return add(A, 1.0);
}

Matrix Matrix::operator-(const Matrix &A) const
{
    return add(A, -1.0);
}

Matrix Matrix::operator*(const Matrix &A) const
{
    if (!multipliable(*this, A))
        throw std::invalid_argument("matrices are not addable");

    Matrix R(m_rows, A.m_cols);
    for (int j = 0; j < R.m_cols; ++j)
        for (int i = 0; i < R.m_rows; ++i) {
            R[i][j] = 0.0;
            for (int k = 0; k < m_cols; ++k)
                R[i][j] += data2d[i][k] * A[k][j];
        }

    return R;
}

Matrix Matrix::operator*(const double &k) const
{
    Matrix R(m_rows, m_cols);
    for (size_t i = 0; i < m_elements; ++i)
        R.data1d[i] = k*data1d[i];
    return R;
}

Matrix Matrix::transpose() const
{
    Matrix R(m_cols, m_rows);
    for (size_t i = 0; i < m_rows; ++i)
        for (size_t j = 0; j < m_cols; ++j)
            R[j][i] = data2d[i][j];
    return R;
}

bool Matrix::swap_columns(const size_t i, const size_t j)
{
    if (i == j)
        return false;
    if (i > m_cols || j > m_cols)
        throw std::invalid_argument("are you dumb?");
    for (size_t k = 0; k < m_rows; ++k) {
        const double temp = data2d[k][i];
        data2d[k][i] = data2d[k][j];
        data2d[k][j] = temp;
    }
    return true;
}

bool Matrix::swap_rows(const size_t i, const size_t j)
{
    if (i == j)
        return false;
    if (i > m_rows || j > m_rows)
        throw std::invalid_argument("are you dumb?");
    for (size_t k = 0; k < m_cols; ++k) {
        const double temp = data2d[i][k];
        data2d[i][k] = data2d[j][k];
        data2d[j][k] = temp;
    }
    return true;
}

double Matrix::determinant() const
{
    if (m_rows != m_cols)
        throw std::invalid_argument("can't calculate det of non-square matrix");

    double D = 1;
    Matrix m(*this);

    // Modified Gaussian algorithm.
    // "Recursive" determinant calculating (see Block matrices).
    for (size_t k = 0; k < m.m_cols-1; ++k) {
        // Look for first non-zero element.
        for (size_t i = k; i < m.m_rows; ++i) {
            if (m[i][k] != 0) {
                // Swap row containing non-zero element with first row.
                // Invert determinant if lines actually been swapped.
                D *= (m.swap_rows(k, i) ? -m[k][k] : m[k][k]);
                break;
            }
        }
        if (m[k][k] == 0)
            // First element will be zero only if the whole column is null.
            return 0;

        // Actually, we don't use any elements outside current square submatrix,
        // so we can just firstly divide whole row by its first element...
        double denominator = m[k][k];
        for (size_t j = k; j < m.m_cols; ++j)
            m[k][j] /= denominator;

        for (size_t i = k+1; i < m.m_rows; ++i) {
            // ...and then add first row multiplied by first element of every row
            // below to every row below.
            double numerator = -m[i][k];
            for (size_t j = k; j < m.m_cols; ++j)
                m[i][j] += numerator * m[k][j];
        }
    }

    // The last bottom right element is remaining to be multiplied by D.
    return D*m[m.m_rows-1][m.m_rows-1];
}

std::tuple<Matrix, Matrix> Matrix::LU() const
{
    if (m_rows != m_cols)
        throw std::invalid_argument("can't decompose a non-square matrix");
    Matrix L(m_rows, m_cols, 0.0);
    Matrix U(m_rows, m_cols, 0.0);

    for (size_t i = 0; i < m_rows; ++i) {
        L[i][i] = 1.0;
        for (size_t j = 0; j < m_cols; ++j) {
            double sum = 0.0;
            if (i <= j) {
                for (size_t k = 0; k < i; ++k)
                    sum += L[i][k] * U[k][j];
                U[i][j] = data2d[i][j] - sum;
            } else {
                for (size_t k = 0; k < j; ++k)
                    sum += L[i][k] * U[k][j];
                L[i][j] = (data2d[i][j] - sum) / U[j][j];
            }
        }
    }

    return {L, U};
}

Matrix Matrix::inverse() const
{
    if (m_rows != m_cols)
        throw std::invalid_argument("can't inverse a non-square matrix");

    // augmented (A | I)
    Matrix aug(m_rows, 2 * m_cols);
    for (size_t i = 0; i < m_rows; ++i) {
        for (size_t j = 0; j < m_cols; ++j)
            aug[i][j] = data2d[i][j];
        aug[i][i + m_cols] = 1.0;
    }

    for (size_t col = 0; col < m_cols; ++col) {
        // find leader
        int max_row = col;
        for (size_t row = col + 1; row < m_rows; ++row)
            if (std::abs(aug[row][col]) > std::abs(aug[max_row][col]))
                max_row = row;
        if (aug[max_row][col] == 0.0)
            throw std::invalid_argument("matrix is singular");
        if (max_row != col)
            aug.swap_rows(col, max_row);

        // normalize row
        const double pivot = aug[col][col];
        for (size_t j = col; j < aug.cols(); ++j)
            aug[col][j] /= pivot;

        // zero current column
        for (size_t i = 0; i < m_rows; ++i)
            if (i != col && aug[i][col] != 0.0) {
                const double factor = aug[i][col];
                for (size_t j = col; j < aug.cols(); ++j)
                    aug[i][j] -= aug[col][j] * factor;
            }
    }

    Matrix R(m_rows, m_cols);
    for (size_t i = 0; i < m_rows; ++i)
        for (size_t j = 0; j < m_cols; ++j)
            R[i][j] = aug[i][j + m_cols];

    return R;
}
