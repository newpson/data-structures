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
    Matrix ma(5, 5);
    std::initializer_list<std::initializer_list<double>> list =
    {
        {1, 2, 3, 4, 5},
        {4, 5, 4, 6, 7},
        {3, 2, 1, 8, 9},
        {1, 2, 2, 4, 5},
        {1, 5, 3, 2, 1}
    };

    int i = 0;
    for (auto li: list) {
        int j = 0;
        for (auto lj: li) {
            ma[i][j] = lj;
            ++j;
        }
        ++i;
    }

    std::cout << ma << std::endl << std::endl;
    auto [L, U] = ma.LU();
    std::cout << L << std::endl << std::endl;
    std::cout << U << std::endl << std::endl;
    return 0;
}
