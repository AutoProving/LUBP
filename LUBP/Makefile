# Makefile for LUBP

CC = g++
CXXFLAGS:=-std=c++11 -O3 

ROOTPATH:=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

INCDIRS = -I $(ROOTPATH)boost_1_74_0
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/BinaryFiles
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/Julia
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/Matlab
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/Matlab/ForCpp
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/Matlab/ForMatlab
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/Others
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/Others/SparseBLAS
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/Others/fftw
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/Others/wavelet
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/Problems
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/Solvers
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/cwrapper
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/cwrapper/blas
INCDIRS += -I $(ROOTPATH)ROPTLIB_2020-08-11/cwrapper/lapack

TP?=LUBP

output:
	$(CC) $(CXXFLAGS) -o $(ROOTPATH)$(TP) $(ROOTPATH)LUBP/LUBP.o $(ROOTPATH)LUBP/mat_operations.o $(ROOTPATH)LUBP/stiefel_stuff.o $(ROOTPATH)LUBP/ClassesProblem.o $(ROOTPATH)LUBP/InstructionsProblem.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/CFixedRankQ2F.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/CStiefel.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/CSymFixedRankQ.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/Element.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/Euclidean.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/FixedRankE.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/FixedRankQ2F.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/Grassmann.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/Manifold.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/MultiManifolds.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/SPDManifold.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/SmartSpace.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/Sphere.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/SphereTx.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/Stiefel.o $(ROOTPATH)ROPTLIB_2020-08-11/Manifolds/SymFixedRankQ.o $(ROOTPATH)ROPTLIB_2020-08-11/Others/BlasLapackCppWrapper.o $(ROOTPATH)ROPTLIB_2020-08-11/Others/ForDebug.o $(ROOTPATH)ROPTLIB_2020-08-11/Others/MinPNormConHull.o $(ROOTPATH)ROPTLIB_2020-08-11/Others/SparseMatrix.o $(ROOTPATH)ROPTLIB_2020-08-11/Others/Spline.o $(ROOTPATH)ROPTLIB_2020-08-11/Others/Timer.o $(ROOTPATH)ROPTLIB_2020-08-11/Others/randgen.o $(ROOTPATH)ROPTLIB_2020-08-11/Others/SparseBLAS/nist_spblas.o $(ROOTPATH)ROPTLIB_2020-08-11/Others/wavelet/wavelet.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/CFRankQ2FBlindDecon2D.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/CSFRQPhaseRetrieval.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/CStieBrockett.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/EucQuadratic.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/FRankESparseApprox.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/FRankEWeightApprox.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/FRankQ2FMatCompletion.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/GrassRQ.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/Problem.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/ProdStieSumBrockett.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/SFRQLyapunov.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/SPDKarcherMean.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/SphereConvexHull.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/SphereSparsestVector.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/SphereTxRQ.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/StieBrockett.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/StieSPCA.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/mexProblem.o $(ROOTPATH)ROPTLIB_2020-08-11/Problems/juliaProblem.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/AManPG.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/LRBFGS.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/LRBFGSSub.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/LRTRSR1.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/ManPG.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/RBFGS.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/RBFGSSub.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/RBroydenFamily.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/RCG.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/RGS.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/RNewton.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/RSD.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/RTRNewton.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/RTRSD.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/RTRSR1.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/RWRBFGS.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/Solvers.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/SolversNSM.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/SolversNSMPGLS.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/SolversNSMSub.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/SolversNSMSubLS.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/SolversSMLS.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/SolversSMTR.o $(ROOTPATH)ROPTLIB_2020-08-11/Solvers/SolversSM.o $(ROOTPATH)ROPTLIB_2020-08-11/test/DriverMexProb.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestCFRankQ2FBlindDecon2D.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestCSFRQPhaseRetrieval.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestCStieBrockett.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestElement.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestEucQuadratic.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestFRankESparseApprox.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestFRankEWeightApprox.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestFRankQ2FMatCompletion.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestGrassRQ.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestProdStieSumBrockett.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestSFRQLyapunov.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestSPDKarcherMean.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestSphereSparsestVector.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestStieBrockett.o $(ROOTPATH)ROPTLIB_2020-08-11/test/TestStieSPCA.o -static -llapack -lgfortran -lquadmath -lblas -static -lfftw3 -lstdc++fs -lm


LUBP.o: 
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)LUBP/LUBP.o $(ROOTPATH)LUBP/LUBP.cpp
mat_operations.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)LUBP/mat_operations.o $(ROOTPATH)LUBP/mat_operations.cpp
stiefel_stuff.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)LUBP/stiefel_stuff.o $(ROOTPATH)LUBP/stiefel_stuff.cpp
ClassesProblem.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)LUBP/ClassesProblem.o $(ROOTPATH)LUBP/ClassesProblem.cpp
InstructionsProblem.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)LUBP/InstructionsProblem.o $(ROOTPATH)LUBP/InstructionsProblem.cpp
CFixedRankQ2F.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11CFixedRankQ2F.o $(ROOTPATH)CFixedRankQ2F.cpp
CStiefel.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11CStiefel.o $(ROOTPATH)CStiefel.cpp
CSymFixedRankQ.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11CSymFixedRankQ.o $(ROOTPATH)CSymFixedRankQ.cpp
Element.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11Element.o $(ROOTPATH)Element.cpp
Euclidean.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11Euclidean.o $(ROOTPATH)Euclidean.cpp
FixedRankE.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11FixedRankE.o $(ROOTPATH)FixedRankE.cpp
FixedRankQ2F.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11FixedRankQ2F.o $(ROOTPATH)FixedRankQ2F.cpp
Grassmann.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11Grassmann.o $(ROOTPATH)Grassmann.cpp
Manifold.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11Manifold.o $(ROOTPATH)Manifold.cpp
MultiManifolds.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11MultiManifolds.o $(ROOTPATH)MultiManifolds.cpp
SPDManifold.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SPDManifold.o $(ROOTPATH)SPDManifold.cpp
SmartSpace.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SmartSpace.o $(ROOTPATH)SmartSpace.cpp
Sphere.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11Sphere.o $(ROOTPATH)Sphere.cpp
SphereTx.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SphereTx.o $(ROOTPATH)SphereTx.cpp
Stiefel.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11Stiefel.o $(ROOTPATH)Stiefel.cpp
SymFixedRankQ.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SymFixedRankQ.o $(ROOTPATH)SymFixedRankQ.cpp
BlasLapackCppWrapper.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11BlasLapackCppWrapper.o $(ROOTPATH)BlasLapackCppWrapper.cpp
ForDebug.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11ForDebug.o $(ROOTPATH)ForDebug.cpp
MinPNormConHull.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11MinPNormConHull.o $(ROOTPATH)MinPNormConHull.cpp
SparseMatrix.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SparseMatrix.o $(ROOTPATH)SparseMatrix.cpp
Spline.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11Spline.o $(ROOTPATH)Spline.cpp
Timer.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11Timer.o $(ROOTPATH)Timer.cpp
randgen.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11randgen.o $(ROOTPATH)randgen.cpp
nist_spblas.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SparseBLAS/nist_spblas.o $(ROOTPATH)SparseBLAS/nist_spblas.cpp
wavelet.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11wavelet/wavelet.o $(ROOTPATH)wavelet/wavelet.cpp
CFRankQ2FBlindDecon2D.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11CFRankQ2FBlindDecon2D.o $(ROOTPATH)CFRankQ2FBlindDecon2D.cpp
CSFRQPhaseRetrieval.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11CSFRQPhaseRetrieval.o $(ROOTPATH)CSFRQPhaseRetrieval.cpp
CStieBrockett.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11CStieBrockett.o $(ROOTPATH)CStieBrockett.cpp
EucQuadratic.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11EucQuadratic.o $(ROOTPATH)EucQuadratic.cpp
FRankESparseApprox.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11FRankESparseApprox.o $(ROOTPATH)FRankESparseApprox.cpp
FRankEWeightApprox.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11FRankEWeightApprox.o $(ROOTPATH)FRankEWeightApprox.cpp
FRankQ2FMatCompletion.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11FRankQ2FMatCompletion.o $(ROOTPATH)FRankQ2FMatCompletion.cpp
GrassRQ.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11GrassRQ.o $(ROOTPATH)GrassRQ.cpp
Problem.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11Problem.o $(ROOTPATH)Problem.cpp
ProdStieSumBrockett.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11ProdStieSumBrockett.o $(ROOTPATH)ProdStieSumBrockett.cpp
SFRQLyapunov.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SFRQLyapunov.o $(ROOTPATH)SFRQLyapunov.cpp
SPDKarcherMean.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SPDKarcherMean.o $(ROOTPATH)SPDKarcherMean.cpp
SphereConvexHull.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SphereConvexHull.o $(ROOTPATH)SphereConvexHull.cpp
SphereSparsestVector.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SphereSparsestVector.o $(ROOTPATH)SphereSparsestVector.cpp
SphereTxRQ.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SphereTxRQ.o $(ROOTPATH)SphereTxRQ.cpp
StieBrockett.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11StieBrockett.o $(ROOTPATH)StieBrockett.cpp
StieSPCA.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11StieSPCA.o $(ROOTPATH)StieSPCA.cpp
mexProblem.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11mexProblem.o $(ROOTPATH)mexProblem.cpp
juliaProblem.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11juliaProblem.o $(ROOTPATH)juliaProblem.cpp
AManPG.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11AManPG.o $(ROOTPATH)AManPG.cpp
LRBFGS.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11LRBFGS.o: $(ROOTPATH)LRBFGS.cpp
LRBFGSSub.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11LRBFGSSub.o $(ROOTPATH)LRBFGSSub.cpp
LRTRSR1.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11LRTRSR1.o $(ROOTPATH)LRTRSR1.cpp
ManPG.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11ManPG.o $(ROOTPATH)ManPG.cpp
RBFGS.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11RBFGS.o $(ROOTPATH)RBFGS.cpp
RBFGSSub.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11RBFGSSub.o $(ROOTPATH)RBFGSSub.cpp
RBroydenFamily.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11RBroydenFamily.o $(ROOTPATH)RBroydenFamily.cpp
RCG.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11RCG.o $(ROOTPATH)RCG.cpp
RGS.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11RGS.o $(ROOTPATH)RGS.cpp
RNewton.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11RNewton.o $(ROOTPATH)RNewton.cpp
RSD.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11RSD.o $(ROOTPATH)RSD.cpp
RTRNewton.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11RTRNewton.o $(ROOTPATH)RTRNewton.cpp
RTRSD.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11RTRSD.o $(ROOTPATH)RTRSD.cpp
RTRSR1.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11RTRSR1.o $(ROOTPATH)RTRSR1.cpp
RWRBFGS.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11RWRBFGS.o $(ROOTPATH)RWRBFGS.cpp
Solvers.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11Solvers.o $(ROOTPATH)Solvers.cpp
SolversNSM.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SolversNSM.o $(ROOTPATH)SolversNSM.cpp
SolversNSMPGLS.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SolversNSMPGLS.o $(ROOTPATH)SolversNSMPGLS.cpp
SolversNSMSub.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SolversNSMSub.o $(ROOTPATH)SolversNSMSub.cpp
SolversNSMSubLS.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SolversNSMSubLS.o $(ROOTPATH)SolversNSMSubLS.cpp
SolversSMLS.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SolversSMLS.o $(ROOTPATH)SolversSMLS.cpp
SolversSMTR.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SolversSMTR.o $(ROOTPATH)SolversSMTR.cpp
SolversSM.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11SolversSM.o $(ROOTPATH)SolversSM.cpp
DriverMexProb.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11DriverMexProb.o $(ROOTPATH)DriverMexProb.cpp
TestCFRankQ2FBlindDecon2D.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestCFRankQ2FBlindDecon2D.o $(ROOTPATH)TestCFRankQ2FBlindDecon2D.cpp
TestCSFRQPhaseRetrieval.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestCSFRQPhaseRetrieval.o $(ROOTPATH)TestCSFRQPhaseRetrieval.cpp
TestCStieBrockett.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestCStieBrockett.o $(ROOTPATH)TestCStieBrockett.cpp
TestElement.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestElement.o $(ROOTPATH)TestElement.cpp
TestEucQuadratic.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestEucQuadratic.o $(ROOTPATH)TestEucQuadratic.cpp
TestFRankESparseApprox.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestFRankESparseApprox.o $(ROOTPATH)TestFRankESparseApprox.cpp
TestFRankEWeightApprox.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestFRankEWeightApprox.o $(ROOTPATH)TestFRankEWeightApprox.cpp
TestFRankQ2FMatCompletion.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestFRankQ2FMatCompletion.o $(ROOTPATH)TestFRankQ2FMatCompletion.cpp
TestGrassRQ.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestGrassRQ.o $(ROOTPATH)TestGrassRQ.cpp
TestProdStieSumBrockett.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestProdStieSumBrockett.o $(ROOTPATH)TestProdStieSumBrockett.cpp
TestSFRQLyapunov.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestSFRQLyapunov.o $(ROOTPATH)TestSFRQLyapunov.cpp
TestSPDKarcherMean.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestSPDKarcherMean.o $(ROOTPATH)TestSPDKarcherMean.cpp
TestSphereSparsestVector.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestSphereSparsestVector.o $(ROOTPATH)TestSphereSparsestVector.cpp
TestStieBrockett.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestStieBrockett.o $(ROOTPATH)TestStieBrockett.cpp
TestStieSPCA.o:
	$(CC) $(CXXFLAGS) -c $(INCDIRS)  -o $(ROOTPATH)ROPTLIB_2020-08-11TestStieSPCA.o $(ROOTPATH)TestStieSPCA.cpp
	
clean:
	rm *.o output