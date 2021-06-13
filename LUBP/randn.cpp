/**************************************************************************
LUBP: Learning Unitary Branching Programs

Copyright 2021 Mateus de Oliveira Oliveira and Farhad Vadiee.

Copyright 2020 Mateus de Oliveira Oliveira and Fidel Ernesto Diaz Andino

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/




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
