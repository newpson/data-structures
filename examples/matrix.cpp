#include "Matrix.hpp"
#include <iostream>
#include <cstddef>

std::ostream &operator<<(std::ostream &out, const Matrix &obj)
{
    for (std::size_t i = 0; i < obj.rows(); ++i)
    {
        for (std::size_t j = 0; j < obj.cols(); ++j)
        {
            out << obj[i][j];
            if (j+1 < obj.cols())
            {
                out << "\t";
            }
        }
        out << std::endl;
    }
    return out;
}

int main()
{
    Matrix A(3, 3);
    Matrix B(3, 3);
    std::initializer_list<std::initializer_list<double>> list_A =
    {{1, 2, 3},
     {4, 5, 6},
     {2, 4, 6}};
    std::initializer_list<std::initializer_list<double>> list_B =
    {{1, 0, 0},
     {0, 1, 0},
     {0, 0, 1}};

    int i = 0;
    for (auto li: list_A) {
        int j = 0;
        for (auto lj: li) {
            A[i][j] = lj;
            ++j;
        }
        ++i;
    }
    i = 0;
    for (auto li: list_B) {
        int j = 0;
        for (auto lj: li) {
            B[i][j] = lj;
            ++j;
        }
        ++i;
    }

    std::cout << A - B << std::endl << std::endl;
    // std::cout << A.inverse() << std::endl << std::endl;
    return 0;
}
