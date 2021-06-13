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


#include "InstructionsProblem.h"

/*Define the namespace*/
namespace ROPTLIB{

	InstructionsProblem::InstructionsProblem(const int& s, const int& l, const int& c,
					const int& k, const int& maxiter, const vector < matrix<int> >& D1, 
					const vector<int>& Indices, vector<matrix<std::complex<double>>>& instructions, 
					const vector<int>& listpositions,
					const vector < matrix< std::complex<double> > >& localmatrices, 
					const vector < vector <matrix< std::complex<double> > > >& leftMatrices,
					const vector < vector <matrix< std::complex<double> > > >& rightMatrices)
	{
		InstructionsProblem::s=s;
		InstructionsProblem::l=l;
		InstructionsProblem::c=c;
		InstructionsProblem::k=k;
		InstructionsProblem::maxiter=maxiter;
		
		InstructionsProblem::D1=D1;
		InstructionsProblem::Indices=Indices;
		InstructionsProblem::instructions = instructions;
		InstructionsProblem::listpositions = listpositions;
		InstructionsProblem::localmatrices = localmatrices;
		InstructionsProblem::leftMatrices = leftMatrices;
		InstructionsProblem::rightMatrices = rightMatrices;
	}

	InstructionsProblem::~InstructionsProblem(void)
	{
	}

	realdp InstructionsProblem::f(const Variable &x) const
	{

		realdpcomplex *xptr = (realdpcomplex *) x.ObtainReadData();
		vector < matrix< std::complex<double> > > lm(localmatrices.size());

		for(int matrix_idx=0; matrix_idx<localmatrices.size(); matrix_idx++){		
			lm(matrix_idx) = matrix< std::complex<double> > (k,k);	
			for(int mm=0; mm<k; mm++)
			{
				for(int nn=0; nn<k; nn++)
				{   
					lm(matrix_idx)(mm,nn).real(xptr[mm*k+nn].r);
					lm(matrix_idx)(mm,nn).imag(xptr[mm*k+nn].i);
				}
			}
			xptr+=k*k;
		}


		realdp result = DistanceLocalInstructionsOptimized(instructions, lm);
		//std::cout << "Instruction cost function call, result = " << result << std::endl;
        
	    return result;
	}

	double InstructionsProblem::DistanceLocalInstructionsOptimized(vector<matrix<std::complex<double>>> instructions, 
															vector<matrix<std::complex<double>>> lm) const
	{

		for (int x = 0; x < listpositions.size(); x++)
		{
			for (int symbol = 0; symbol < s; symbol++)
			{
				instructions(listpositions(x) * s + symbol) = lm(x * s + symbol);
			}
		}
		
		matrix< std::complex<double> > M;
		double dist = 0, S; 
		int r;
	
		for (int classes = 0; classes < c; classes++)
		{
			r = D1(classes).size1();
			S = 0;
			for (int a = 0; a < r; a++)
			{
				M = EvaluateInstructionsOptimized(classes, a, instructions);
				S = S + DistanceMatrices(M, instructions(l * s + classes));
			}
			dist = dist + (1.0 / static_cast<double>(r)) * S;
		}
		
		return dist;
	}

	double InstructionsProblem::DistanceMatrices(const matrix<std::complex<double>>& M1, const matrix<std::complex<double>>& M2) const
	{

		matrix<std::complex<double>> p = element_prod(conj(M1), M2);
		vector<std::complex<double>> s = vector<double>(M1.size2(), 1) - prod(scalar_vector<double>(p.size1(), 1), p);

		return norm_2_square(s);
		
	}

	matrix< std::complex<double> > InstructionsProblem::EvaluateInstructionsOptimized(const int& classes, 
											const int& a, vector<matrix<std::complex<double>>>& instructions) const
	{
		vector<double> w = row(D1(classes), a);
		matrix<std::complex<double>> M = leftMatrices(classes)(a);

		for (int i = 0; i < listpositions.size(); i++)
		{
			M = prod(M, instructions(listpositions(i) * s + w(Indices(listpositions(i)))));
		}

		return prod(M, rightMatrices(classes)(a));
	}
}
