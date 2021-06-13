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


#ifndef CLASSESPROBLEM_H
#define CLASSESPROBLEM_H

#include "Manifolds/CStiefel.h"
#include "Problems/Problem.h"
#include "Others/def.h"

#include <complex>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>
#include <boost/numeric/ublas/vector_expression.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include <boost/numeric/ublas/operations.hpp>

#include <boost/numeric/ublas/io.hpp>

using namespace std::complex_literals;
using namespace boost::numeric::ublas;

namespace ROPTLIB{
    
    class ClassesProblem : public Problem{
		int s;
		int l; 
	    int c;
		int k;
		int maxiter;
		vector< matrix<int> > D1;
		vector<int> Indices;
		vector<matrix<std::complex<double>>> instructions;
		vector<int> listpositions;
		vector< matrix< std::complex<double> > > localmatrices; 
		vector< vector <matrix< std::complex<double> > > > leftMatrices;
		vector< vector <matrix< std::complex<double> > > > rightMatrices;		
		vector < vector <matrix< std::complex<double> > > > evaluatedMatrices;
		
	public:		
		ClassesProblem(const int& s, const int& l, const int& c, const int& k, 
					const int& maxiter,	const vector < matrix< std::complex<double> > >& localmatrices, 
					const vector<matrix<std::complex<double>>>& instructions, const vector < matrix<int> >& D1,
					const vector < vector <matrix< std::complex<double> > > >& evaluatedMatrices);

		virtual realdp f(const Variable &x) const;

		//cost function of classes
		double DistanceLocalClassesOptimized(vector<matrix<std::complex<double>>> instructions, vector<matrix<std::complex<double>>> lm) const;
																	
		double DistanceMatrices(const matrix<std::complex<double>>& M1, const matrix<std::complex<double>>& M2) const;

		virtual ~ClassesProblem();
	};
};

#endif
