#ifndef STIEFELSTUFF_H
#define STIEFELSTUFF_H

#include <iostream>
#include "Others/randgen.h"

#include <ctime>

#include "Problems/Problem.h"
#include "Problems/SphereTxRQ.h"

/*Manifold related classes*/
#include "Manifolds/Manifold.h"
#include "Manifolds/MultiManifolds.h"
#include "Manifolds/CStiefel.h"
#include "Manifolds/SphereTx.h"

/*Linesearch based solvers*/
#include "Solvers/RSD.h"
#include "Solvers/RNewton.h"
#include "Solvers/RCG.h"
#include "Solvers/RBroydenFamily.h"
#include "Solvers/RWRBFGS.h"
#include "Solvers/RBFGS.h"
#include "Solvers/LRBFGS.h"
#include "Solvers/RGS.h"
#include "Solvers/LRBFGSSub.h"
#include "Solvers/ManPG.h"
#include "Solvers/AManPG.h"
//#include "Solvers/RBFGSLPSub.h"

/*Trust-region based solvers*/
#include "Solvers/SolversSMTR.h"
#include "Solvers/RTRSD.h"
#include "Solvers/RTRNewton.h"
#include "Solvers/RTRSR1.h"
#include "Solvers/LRTRSR1.h"

#include "Others/def.h"

#include "InstructionsProblem.h"
#include "ClassesProblem.h"

using namespace ROPTLIB;

/*The main test function*/
extern int MAXITERATION;

extern vector < matrix< std::complex<double> > > lubpInstructionProblemSolve(const int& s, const int& l, const int& c,
			const int& k, const int& maxiter, const vector < matrix<int> >& D1, 
			const vector<int>& Indices, vector<matrix<std::complex<double>>> instructions, 
			const vector<int>& listpositions,
			const vector < matrix< std::complex<double> > >& localmatrices, 
			const vector < vector <matrix< std::complex<double> > > >& leftMatrices,
			const vector < vector <matrix< std::complex<double> > > >& rightMatrices);

extern vector < matrix< std::complex<double> > > lubpClassesProblemSolve(const int& s, const int& l, const int& c, 
			const int& k, const int& maxiter,	vector<matrix<std::complex<double>>> &localmatrices,
			const vector<matrix<std::complex<double>>> instructions, const vector < matrix<int> > D1, 
			const vector < vector <matrix< std::complex<double> > > >& evaluatedMatrices);

#endif // end of TESTCSTIEBROCKETT_H
