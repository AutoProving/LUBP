/**************************************************************************
LUBP: Learning Unitary Branching Programs

Copyright 2021 Mateus de Oliveira Oliveira and Farhad Vadiee.

Copyright 2020 Mateus de Oliveira Oliveira and Fidel Ernesto Dias Andino

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




#ifndef RANDN_H
#define RANDN_H

// Include Files
#include <stddef.h>
#include <stdlib.h>

#include <random>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/date_time/c_time.hpp>

using namespace boost::numeric::ublas;
using namespace std::complex_literals;

// Function Declarations
extern void randn(int row, int col, matrix<double> &M);
extern void randn(int row, int col, matrix< std::complex<double> >& M);

#endif
