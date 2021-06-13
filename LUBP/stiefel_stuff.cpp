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






#include "stiefel_stuff.h"

vector < matrix< std::complex<double> > > lubpInstructionProblemSolve(const int& s, const int& l, const int& c,
			const int& k, const int& maxiter, const vector < matrix<int> >& D1, 
			const vector<int>& Indices, vector<matrix<std::complex<double>>> instructions, 
			const vector<int>& listpositions,
			const vector < matrix< std::complex<double> > >& localmatrices, 
			const vector < vector <matrix< std::complex<double> > > >& leftMatrices,
			const vector < vector <matrix< std::complex<double> > > >& rightMatrices)
{	
	int lsize = localmatrices.size();
	//int w = listpositions.size();
	vector < matrix< std::complex<double> > > result(lsize);

	// Define the Stiefel manifold
	CStiefel mani1(k, k);
 	integer numoftypes = 1; // One type of manifold
	ProductManifold Domain(numoftypes, &mani1, static_cast<integer>(lsize));//, &mani2, numofmani2);
	
   	Vector X(k, k, "complex");
	Variable CStieX (1, &X, static_cast<integer>(lsize));//l matices of dimension KxK

	realdpcomplex *CStieXptr = (realdpcomplex *) CStieX.ObtainWriteEntireData();	
	
	for(int matrix_idx=0; matrix_idx<lsize; matrix_idx++)
	{	
		for(int mm=0; mm<k; mm++)
		{
			for(int nn=0; nn<k; nn++)
			{   
				CStieXptr[mm*k+nn].r = static_cast<realdp> (localmatrices(matrix_idx)(mm,nn).real());
				CStieXptr[mm*k+nn].i = static_cast<realdp> (localmatrices(matrix_idx)(mm,nn).imag());

				CStieX.RemoveAllFromFields();
			}
		}
		CStieXptr+=k*k;
	}

	InstructionsProblem Prob(s, l, c, k, maxiter, D1, Indices, instructions, 
			listpositions, localmatrices, leftMatrices, rightMatrices);

	Prob.SetDomain(&Domain);
	LRBFGS *LRBFGSsolver = new LRBFGS(&Prob, &CStieX);

	LRBFGSsolver->Verbose = NOOUTPUT; //ITERRESULT;//
	LRBFGSsolver->Max_Iteration = MAXITERATION;
   
   
    LRBFGSsolver->Run();
	
	Variable local_result = LRBFGSsolver->GetXopt();//--

	realdpcomplex *local_result_ptr = (realdpcomplex *) local_result.ObtainReadData();
	
	for(int matrix_idx=0; matrix_idx<lsize; matrix_idx++){		
		result(matrix_idx) = matrix< std::complex<double> > (k,k);	
		for(int mm=0; mm<k; mm++)
		{
			for(int nn=0; nn<k; nn++)
			{   
				result(matrix_idx)(mm,nn).real(local_result_ptr[mm*k+nn].r);
				result(matrix_idx)(mm,nn).imag(local_result_ptr[mm*k+nn].i);

			}
		}		
		local_result_ptr+=k*k;
	}

	delete LRBFGSsolver;
	
	return result;
}

vector < matrix< std::complex<double> > > lubpClassesProblemSolve(const int& s, const int& l, const int& c, 
			const int& k, const int& maxiter,	vector<matrix<std::complex<double>>> &localmatrices,
			const vector<matrix<std::complex<double>>> instructions, const vector < matrix<int> > D1, 
			const vector < vector <matrix< std::complex<double> > > >& evaluatedMatrices)
{
	vector < matrix< std::complex<double> > > result(c);
    integer numoftypes = 1; // one type of manifold

    // Define the Stiefel manifold
    CStiefel mani1(k, k);

    mani1.ChooseParamsSet1();

    ProductManifold Domain(numoftypes, &mani1, static_cast<integer>(c));//, &mani2, numofmani2);

	Vector X(k, k, "complex");
	Vector CStieX(1, &X, static_cast<integer>(c));

	realdpcomplex *CStieXptr = (realdpcomplex *) CStieX.ObtainWriteEntireData();	

	for(int matrix_idx=0; matrix_idx<c; matrix_idx++){	
		for(int mm=0; mm<k; mm++)
		{
			for(int nn=0; nn<k; nn++)
			{   
				CStieXptr[mm*k+nn].r = static_cast<realdp> (localmatrices(matrix_idx)(mm,nn).real());
				CStieXptr[mm*k+nn].i = static_cast<realdp> (localmatrices(matrix_idx)(mm,nn).imag());				

			}
		}
		CStieXptr+=k*k;
	}

	ClassesProblem Prob(s, l, c, k, maxiter, localmatrices, instructions, D1, evaluatedMatrices);
	Prob.SetDomain(&Domain);		
	
	LRBFGS *RSDsolver = new LRBFGS(&Prob, &CStieX);
	RSDsolver->Verbose =  NOOUTPUT;//---ITERRESULT;

	RSDsolver->Max_Iteration = MAXITERATION;
	RSDsolver->Run();

	Variable local_result = RSDsolver->GetXopt();//--
	realdpcomplex *local_result_ptr = (realdpcomplex *) local_result.ObtainReadData();
	
	for(int matrix_idx=0; matrix_idx<c; matrix_idx++){		
		result(matrix_idx) = matrix< std::complex<double> > (k,k);	
		for(int mm=0; mm<k; mm++)
		{
			for(int nn=0; nn<k; nn++)
			{   
				result(matrix_idx)(mm,nn).real(local_result_ptr[mm*k+nn].r);
				result(matrix_idx)(mm,nn).imag(local_result_ptr[mm*k+nn].i);

			}
		}	
		local_result_ptr+=k*k;		
	}

	delete RSDsolver;	

	return result;
}
