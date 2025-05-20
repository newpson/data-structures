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
    Matrix ma(3, 3);
    std::initializer_list<std::initializer_list<double>> list =
    {
        {1, 2, 3},
        {4, 5, 6},
        {2, 4, 6},
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
    std::cout << ma.inverse() << std::endl << std::endl;
    return 0;
}
