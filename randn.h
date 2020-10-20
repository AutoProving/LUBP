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