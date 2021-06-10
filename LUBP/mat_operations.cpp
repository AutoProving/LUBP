#include "mat_operations.h"

double DiscreteDistance(const int& s, const vector< matrix<int> > D,
	const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions)

{
	int c = D.size(), r;	
	double maxWrongRatio = 0, wrong;

	double Epsilon = std::numeric_limits<double>::epsilon();
	matrix< std::complex<double> > M;

	for (int classes = 0; classes < c; classes++)
	{
		r = D(classes).size1();
		wrong = 0;
		for (int a = 0; a < r; a++)
		{
			M = Evaluate(s, row(D(classes), a), Indices, instructions);
			if (std::abs(static_cast<double>(classes) - Classification(M, c, Indices.size(), s, instructions)) > Epsilon) {
				wrong = wrong + 1;
			}
		}
		maxWrongRatio = std::max(wrong/r, maxWrongRatio);
	}

	return maxWrongRatio;
}

void getRandOrthMatrix(matrix<std::complex<double>>& M){
	int sz1 = M.size1(); int sz2 = M.size2();
	Variable Q(sz1, sz2, "complex");

	Q.RandGaussian();
	Q = Q.GetOrth();

	realdpcomplex *QXptr = (realdpcomplex *) Q.ObtainReadData();	
	
	for(int mm=0; mm<sz1; mm++)
	{
		for(int nn=0; nn<sz2; nn++)
		{   
				M(mm,nn).real(QXptr[mm*sz1+nn].r);
				M(mm,nn).imag(QXptr[mm*sz1+nn].i);
		}
	}
}

matrix< std::complex<double> > Evaluate(const int& s, const vector<double>& w,
	const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions)
{
	matrix<std::complex<double>> M = identity_matrix<double>(instructions(0).size1());
	int indices_length = Indices.size();

	for (int i = 0; i < indices_length; i++)
	{
		M = prod(M, instructions((i)*s + w(Indices(i))));
	}

	return M;
}

double Classification(const matrix<std::complex<double>> M, const int& c, const int& l,
	const int& s, vector<matrix<std::complex<double>>> instructions)
{
	int closestclass = 0;
	double dist = DistanceMatrices(M, instructions(s * l )), auxdist;
	for (int i = 1; i < c; i++)
	{
		auxdist = DistanceMatrices(M, instructions( s * l + i));
		if(auxdist < dist){
			dist = auxdist;
			closestclass = i;
		}
	}

	return closestclass;
}

double DistanceMatrices(const matrix<std::complex<double>> M1, const matrix<std::complex<double>> M2)
{
	//c = sum(conj(a).*b); sum of conjugate of M1, element wise product b;

	matrix<std::complex<double>> p = element_prod(conj(M1), M2);
	vector<std::complex<double>> s = vector<double>(M1.size2(), 1) - 
										prod(scalar_vector<double>(p.size1(), 1), p);

	return norm_2_square(s);
	
}

double Distance(const int& s, const vector< matrix<int> > D,
	const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions)
{
	const int c = D.size();
	matrix< std::complex<double> > M;

	const int index_length = Indices.size();
	double dist = 0, S;
	int r = 0;

	for (int classes = 0; classes < c; classes++)
	{
		r = D(classes).size1();
		S = 0;
		for (int j = 0; j < r; j++)
		{
			M = Evaluate(s, row(D(classes), j), Indices, instructions);
			S = S + DistanceMatrices(M, instructions(index_length*s + classes));
		}
		dist = dist + (1.0 / static_cast<double>(r)) * S;
	}

	return dist;
}

vector < vector <matrix< std::complex<double> > > > ConstructRight(const int& s, const int& k, const int& c,
	const vector < matrix<int> > D, const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions,
	const int& position, const int& windowSize)
{
	vector < vector <matrix< std::complex<double> > > > rightMatrices(c);
	for (int i = 0; i < c; i++)
	{
		rightMatrices(i) = vector< matrix< std::complex<double> > > (D(i).size1(), identity_matrix<double>(k));
		if (position + windowSize - 1 < Indices.size())
		{
			for (int j = 0; j < D(i).size1(); j++)
			{			
				rightMatrices(i)(j) = EvaluateFromPosition(s, row(D(i), j), Indices, instructions, position + windowSize);
			}
		}
	}

	return rightMatrices;
}

vector < vector <matrix< std::complex<double> > > > ConstructLeft(const int& s, const int& k, const int& c,
	const vector < matrix<int> > D, const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions,
	const int& position)
{
	vector < vector <matrix< std::complex<double> > > > leftMatrices(c);
	for (int i = 0; i < c; i++)
	{
		leftMatrices(i) = vector< matrix< std::complex<double> > >(D(i).size1(), identity_matrix<double>(k));		
		if (position > 0)
		{
			for (int j = 0; j < D(i).size1(); j++)
			{
				leftMatrices(i)(j) = EvaluateUntilPosition(s, row(D(i), j), Indices, instructions, position);			
			}
		}
	}

	return leftMatrices;
}

vector < vector <matrix< std::complex<double> > > > ConstructEvaluatedMatrices(const int& s,
	const int& c, const vector < matrix<int> > D, const vector<int> Indices,
	const vector< matrix< std::complex<double> > > instructions)
{
	vector < vector <matrix< std::complex<double> > > > evaluatedMatrices(c);
	for (int i = 0; i < c; i++)
	{
		evaluatedMatrices(i) = vector< matrix< std::complex<double> > >(D(i).size1());
		for (int j = 0; j < D(i).size1(); j++)
		{
			evaluatedMatrices(i)(j) = Evaluate(s, row(D(i), j), Indices, instructions);
		}
	}
	return evaluatedMatrices;
}

matrix< std::complex<double> > EvaluateFromPosition(const int& s, const vector<double>& w,
	const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions, const int& fromposition)

{
	matrix< std::complex<double> > M1 = identity_matrix<double>(instructions(0).size1());
	
	for (int i = fromposition; i < Indices.size(); i++)
	{
		M1 = prod(M1, instructions(i*s + w(Indices(i))));
	} 

	return M1;
}

matrix< std::complex<double> > EvaluateUntilPosition(const int& s, const vector<double>& w,
	const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions, const int& untilposition)
{
	matrix< std::complex<double> > M1 = identity_matrix<double>(instructions(0).size1());
	for (int i = 0; i < untilposition; i++)
	{
		M1 = prod(M1, instructions(i * s + w(Indices(i))));
	}

	return M1;
}

vector < matrix< std::complex<double> > > localOptimizerInstructionsOptimized(const int& s, const int& l,
	const int& c, const int& k, const int& maxiter, const vector<int>& listpositions,
	const vector<matrix<std::complex<double>>> instructions, const vector < matrix<int> > D,
	const vector<int>& Indices, const vector < vector <matrix< std::complex<double> > > >& leftMatrices,
	const vector < vector <matrix< std::complex<double> > > >& rightMatrices)

{
	vector <matrix< std::complex<double> > > initlocalmatrices(listpositions.size()*s);
	
	for (int x = 0; x < listpositions.size(); x++)
	{
		for (int symbol = 0; symbol < s; symbol++)
		{
			initlocalmatrices(x * s + symbol) = instructions(listpositions(x) * s + symbol);
		}
	}

	return 	lubpInstructionProblemSolve(s, l, c, k, maxiter, D, Indices, instructions, listpositions,
					initlocalmatrices, leftMatrices, rightMatrices);

}

vector < matrix< std::complex<double> > > localOptimizerClassesOptimized(
	const int& s, const int& l, const int& c, const int& k, const int& maxiter,
	const vector<matrix<std::complex<double>>> instructions, const vector < matrix<int> > D,
	const vector < vector <matrix< std::complex<double> > > >& evaluatedMatrices)
{
	vector<matrix<std::complex<double>>> initlocalmatrices(c);

	for (int x = 0; x < c; x++)
	{
		initlocalmatrices(x) = instructions(l * s + x);
	}
	
	return lubpClassesProblemSolve(s, l, c, k, maxiter, initlocalmatrices, instructions, D, evaluatedMatrices);
}

double DistanceLocalInstructionsOptimized(const int& s, const int& l, const int& c,
	const vector< matrix<int> > D, const vector<int>& Indices,
	vector< matrix< std::complex<double> > > instructions, const vector<int>& listpositions,
	const vector< matrix< std::complex<double> > >& localmatrices, const vector< vector<matrix< std::complex<double> > > >& leftMatrices,
	const vector< vector <matrix< std::complex<double> > > >& rightMatrices)
{
	
	for (int x = 0; x < listpositions.size(); x++)
	{
		for (int symbol = 0; symbol < s; symbol++)
		{
			instructions((listpositions(x) - 1) * s + symbol) = localmatrices(x * s + symbol);
		}
	}
	
	matrix< std::complex<double> > M;
	double dist = 0, S; 
	int r;
	for (int classes = 0; classes < c; classes++)
	{
		r = D(classes).size2();
		S = 0;
		for (int a = 0; a < r; a++)
		{
			M = EvaluateInstructionsOptimized(s, D, classes, a, instructions, Indices,
				leftMatrices, rightMatrices, listpositions);
			S = S + DistanceMatrices(M, instructions(l * s + classes));
		}
		dist = dist + (1.0 / static_cast<double>(r)) * S;
	}
	
	return dist;
}

matrix< std::complex<double> > EvaluateInstructionsOptimized(const int& s, const vector < matrix<int> >& D,
	const int& classes, const int& a, const vector<matrix<std::complex<double>>>& instructions,
	const vector<int>& Indices, const vector < vector <matrix< std::complex<double> > > >& leftMatrices,
	const vector < vector <matrix< std::complex<double> > > >& rightMatrices, const vector<int>& listpositions)
{
	vector<double> w = row(D(classes), a);
	matrix<std::complex<double>> M = leftMatrices(classes)(a);

	for (int i = 0; i < listpositions.size(); i++)
	{
		M = prod(M, instructions((listpositions(i) - 1) * s + w(Indices(listpositions(i)))));
	}

	return prod(M, rightMatrices(classes)(a));
}
