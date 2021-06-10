#include "randn.h"

void randn(int row, int col, matrix<double> &M)
{
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    std::random_device rd;
    std::default_random_engine generator(rd());

    M.resize(row, col, true);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            M(i,j) = distribution(generator);
        }
    }
}

void randn(int row, int col, matrix< std::complex<double> > &M)
{
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    std::random_device rd;
    std::default_random_engine generator(rd());

    M.resize(row, col, true);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            M(i,j) = 0. + distribution(generator)*1i;
        }
    }
}
