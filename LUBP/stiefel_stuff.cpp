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
   //mani1.ChooseParamsSet1();
 	integer numoftypes = 1; // kinds of manifolds
    //  integer numofmani1 = 2; // the first one has two
    ProductManifold Domain(numoftypes, &mani1, static_cast<integer>(lsize));//, &mani2, numofmani2);
   // Vector CStieX(numoftypes, &mani1, static_cast<integer>(w));	
//	Domain.SetIsIntrApproach(false);
	
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

				// CStieXptr[nn*k+mm].r = static_cast<realdp> (localmatrices(matrix_idx)(mm,nn).real());
				// CStieXptr[nn*k+mm].i = static_cast<realdp> (localmatrices(matrix_idx)(mm,nn).imag());
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
   
 //   Prob.CheckGradHessian(CStieX);
   
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

				// result(matrix_idx)(mm,nn).real(local_result_ptr[nn*k+mm].r);
				// result(matrix_idx)(mm,nn).imag(local_result_ptr[nn*k+mm].i);
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
    integer numoftypes = 1; // one kind of manifolds
    //integer numofmani1 = 2; // the first one has two

    // Define the Stiefel manifold
    CStiefel mani1(k, k);

    mani1.ChooseParamsSet1();

    ProductManifold Domain(numoftypes, &mani1, static_cast<integer>(c));//, &mani2, numofmani2);
	//Vector CStieX(numoftypes, &mani1, static_cast<integer>(c));	

	Vector X(k, k, "complex");
	Vector CStieX(1, &X, static_cast<integer>(c));

    //Variable CStieX(k,k, "complex"); //= Domain.RandominManifold();	
	realdpcomplex *CStieXptr = (realdpcomplex *) CStieX.ObtainWriteEntireData();	

	for(int matrix_idx=0; matrix_idx<c; matrix_idx++){	
		for(int mm=0; mm<k; mm++)
		{
			for(int nn=0; nn<k; nn++)
			{   
				CStieXptr[mm*k+nn].r = static_cast<realdp> (localmatrices(matrix_idx)(mm,nn).real());
				CStieXptr[mm*k+nn].i = static_cast<realdp> (localmatrices(matrix_idx)(mm,nn).imag());				

				// CStieXptr[nn*k+mm].r = static_cast<realdp> (localmatrices(matrix_idx)(mm,nn).real());
				// CStieXptr[nn*k+mm].i = static_cast<realdp> (localmatrices(matrix_idx)(mm,nn).imag());				
			}
		}
		CStieXptr+=k*k;
	}

	ClassesProblem Prob(s, l, c, k, maxiter, localmatrices, instructions, D1, evaluatedMatrices);
	Prob.SetDomain(&Domain);		
	
	LRBFGS *RSDsolver = new LRBFGS(&Prob, &CStieX);
	RSDsolver->Verbose =  NOOUTPUT;//---ITERRESULT;

	RSDsolver->Max_Iteration = MAXITERATION;
	//RSDsolver->OutputGap = 1;
	// RSDsolver->CheckParams();
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

				// result(matrix_idx)(mm,nn).real(local_result_ptr[nn*k+mm].r);
				// result(matrix_idx)(mm,nn).imag(local_result_ptr[nn*k+mm].i);
			}
		}	
		local_result_ptr+=k*k;		
	}

	delete RSDsolver;	

	return result;
}