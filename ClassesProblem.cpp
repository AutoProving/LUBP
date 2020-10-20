#include "ClassesProblem.h"

namespace ROPTLIB{

	ClassesProblem::ClassesProblem(const int& s, const int& l, const int& c, const int& k, 
					const int& maxiter,	const vector < matrix< std::complex<double> > >& localmatrices, 
					const vector<matrix<std::complex<double>>>& instructions, const vector < matrix<int> >& D1,
					const vector < vector <matrix< std::complex<double> > > >& evaluatedMatrices)
	{
		
		ClassesProblem::s=s;
		ClassesProblem::l=l;
		ClassesProblem::c=c;
		ClassesProblem::k=k;
		ClassesProblem::maxiter=maxiter;
		
		ClassesProblem::localmatrices = localmatrices;
		ClassesProblem::instructions = instructions;
		ClassesProblem::D1=D1;
		ClassesProblem::evaluatedMatrices = evaluatedMatrices;		
	}

	ClassesProblem::~ClassesProblem(void)
	{
	}

	realdp ClassesProblem::f(const Variable &x) const
	{
		realdpcomplex *xptr = (realdpcomplex *) x.ObtainReadData();
		vector < matrix< std::complex<double> > > lm(c);

		for(int matrix_idx=0; matrix_idx<c; matrix_idx++){		
			lm(matrix_idx) = matrix< std::complex<double> > (k,k);	
			for(int mm=0; mm<k; mm++)
			{
				for(int nn=0; nn<k; nn++)
				{   
					lm(matrix_idx)(mm,nn).real(xptr[mm*k+nn].r);
					lm(matrix_idx)(mm,nn).imag(xptr[mm*k+nn].i);

					// lm(matrix_idx)(mm,nn).real(xptr[nn*k+mm].r);
					// lm(matrix_idx)(mm,nn).imag(xptr[nn*k+mm].i);
				}
			}
			xptr+=k*k;
		}

		realdp result = DistanceLocalClassesOptimized(instructions, lm);
//		std::cout << "Classes cost function call, result = " << result << std::endl;

        return result;
	}

	double ClassesProblem::DistanceLocalClassesOptimized(vector<matrix<std::complex<double>>> instructions, 
																	vector<matrix<std::complex<double>>> lm)const
	{
		for (int x = 0; x < c; x++){
			instructions(l*s + x) = lm(x);
		}
		
		double dist = 0, r, S;
		for (int classes = 0; classes < c; classes++){
			r = D1(classes).size1();
			S = 0;
			for (int a = 0; a < r; a++){
				S = S + DistanceMatrices(evaluatedMatrices(classes)(a), instructions(l*s + classes));
			}
		   dist = dist + (1.0/r)*S;
		}
		
		return dist;
	}

    double ClassesProblem::DistanceMatrices(const matrix<std::complex<double>>& M1, const matrix<std::complex<double>>& M2) const
	{
		//c = sum(conj(a).*b); sum of conjugate of M1, element wise product b;

		matrix<std::complex<double>> p = element_prod(conj(M1), M2);
		vector<std::complex<double>> s = vector<double>(M1.size2(), 1) - 
											prod(scalar_vector<double>(p.size1(), 1), p);

		return norm_2_square(s);
		
	}
}