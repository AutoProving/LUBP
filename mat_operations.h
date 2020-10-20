#ifndef MAT_OPERATIONS_H
#define MAT_OPERATIONS_H

#include "stiefel_stuff.h"
#include <complex>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>
#include <boost/numeric/ublas/vector_expression.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include <boost/numeric/ublas/operations.hpp>

#include <boost/numeric/ublas/io.hpp>

#include "Manifolds/Manifold.h"

using namespace std::complex_literals;
using namespace boost::numeric::ublas;


extern double DiscreteDistance(const int& s, const vector< matrix<int> > D,
	const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions);

extern void getRandOrthMatrix(matrix<std::complex<double>>& M);

extern matrix< std::complex<double> > Evaluate(const int &s, const vector<double>& w, 
	const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions);

extern double Classification(const matrix<std::complex<double>> M, const int& c, const int& l,
	const int& s, vector<matrix<std::complex<double>>> instructions);

extern double DistanceMatrices(const matrix<std::complex<double>> M1, const matrix<std::complex<double>> M2);

extern double Distance(const int& s, const vector< matrix<int> > D,
	const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions);

extern vector < vector <matrix< std::complex<double> > > > ConstructRight(const int& s, const int& k, const int& c,
	const vector < matrix<int> > D, const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions,
	const int& position, const int& windowSize);

extern vector < vector <matrix< std::complex<double> > > > ConstructLeft(const int& s, const int& k, const int& c,
	const vector < matrix<int> > D, const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions,
	const int& position);

extern vector < vector <matrix< std::complex<double> > > > ConstructEvaluatedMatrices(const int& s,
	const int& c, const vector < matrix<int> > D, const vector<int> Indices,
	const vector< matrix< std::complex<double> > > instructions);

extern matrix< std::complex<double> > EvaluateFromPosition(const int& s, const vector<double>& w,
	const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions, const int& fromposition);

extern matrix< std::complex<double> > EvaluateUntilPosition(const int& s, const vector<double>& w,
	const vector<int> Indices, const vector<matrix<std::complex<double>>> instructions, const int& untilposition);


extern vector < matrix< std::complex<double> > > localOptimizerInstructionsOptimized(const int& s, const int& l,
	const int& c, const int& k, const int& maxiter, const vector<int>& listpositions,
	const vector<matrix<std::complex<double>>> instructions, const vector < matrix<int> > D,
	const vector<int>& Indices, const vector < vector <matrix< std::complex<double> > > >& leftMatrices,
	const vector < vector <matrix< std::complex<double> > > >& rightMatrices);

extern vector < matrix< std::complex<double> > > localOptimizerClassesOptimized(
	const int& s, const int& l, const int& c, const int& k, const int& maxiter,
	const vector<matrix<std::complex<double>>> instructions, const vector < matrix<int> > D,
	const vector < vector <matrix< std::complex<double> > > >& evaluatedMatrices);

extern double DistanceLocalInstructionsOptimized(const int& s, const int& l, const int& c,
	const vector < matrix<int> > D, const vector<int>& Indices,
	vector<matrix<std::complex<double>>> instructions, const vector<int>& listpositions,
	const vector < matrix< std::complex<double> > >& localmatrices, 
	const vector < vector <matrix< std::complex<double> > > >& leftMatrices,
	const vector < vector <matrix< std::complex<double> > > >& rightMatrices);

extern matrix< std::complex<double> > EvaluateInstructionsOptimized(const int& s, const vector <matrix<int>>& D,
	const int& classes, const int& a, const vector<matrix<std::complex<double>>>& instructions,
	const vector<int> &Indices, const vector < vector <matrix< std::complex<double> > > >& leftMatrices,
	const vector < vector <matrix< std::complex<double> > > >& rightMatrices, const vector<int>& listpositions);

#endif