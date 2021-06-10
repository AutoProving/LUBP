# Makefile for LUBP.

# set compiler
CC = g++
CXXFLAGS:= -O3 -ffastmath -march=native -ggdb3 -I ./

# default test problem is the Brockett cost function on the Stiefel manifold
TP?=DriverCpp

#the path of LUBP and ROPTLIB
ROOTPATH:=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

# directories of ROPTLIB header files
INCDIRS = -I$(ROOTPATH)/ROPTLIB/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/BinaryFiles/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/Julia/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/Manifolds/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/Matlab/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/Matlab/ForCpp/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/Matlab/ForMatlab/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/Others/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/Others/SparseBLAS/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/Others/fftw/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/Others/wavelet/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/Problems/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/Solvers/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/cwrapper/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/cwrapper/blas/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/cwrapper/lapack/
INCDIRS += -I$(ROOTPATH)/ROPTLIB/test/
# ROPTLIB C++ files
CPPS += $(ROOTPATH)/ROPTLIB/Manifolds/CFixedRankQ2F.cpp $(ROOTPATH)/ROPTLIB/Manifolds/CStiefel.cpp $(ROOTPATH)/ROPTLIB/Manifolds/CSymFixedRankQ.cpp $(ROOTPATH)/ROPTLIB/Manifolds/Element.cpp $(ROOTPATH)/ROPTLIB/Manifolds/Euclidean.cpp $(ROOTPATH)/ROPTLIB/Manifolds/FixedRankE.cpp $(ROOTPATH)/ROPTLIB/Manifolds/FixedRankQ2F.cpp $(ROOTPATH)/ROPTLIB/Manifolds/Grassmann.cpp $(ROOTPATH)/ROPTLIB/Manifolds/Manifold.cpp $(ROOTPATH)/ROPTLIB/Manifolds/MultiManifolds.cpp $(ROOTPATH)/ROPTLIB/Manifolds/SPDManifold.cpp $(ROOTPATH)/ROPTLIB/Manifolds/SmartSpace.cpp $(ROOTPATH)/ROPTLIB/Manifolds/Sphere.cpp $(ROOTPATH)/ROPTLIB/Manifolds/SphereTx.cpp $(ROOTPATH)/ROPTLIB/Manifolds/Stiefel.cpp $(ROOTPATH)/ROPTLIB/Manifolds/SymFixedRankQ.cpp
CPPS += $(ROOTPATH)/ROPTLIB/Others/BlasLapackCppWrapper.cpp $(ROOTPATH)/ROPTLIB/Others/ForDebug.cpp $(ROOTPATH)/ROPTLIB/Others/MinPNormConHull.cpp $(ROOTPATH)/ROPTLIB/Others/SparseMatrix.cpp $(ROOTPATH)/ROPTLIB/Others/Spline.cpp $(ROOTPATH)/ROPTLIB/Others/Timer.cpp $(ROOTPATH)/ROPTLIB/Others/randgen.cpp
CPPS += $(ROOTPATH)/ROPTLIB/Others/SparseBLAS/nist_spblas.cpp
CPPS += $(ROOTPATH)/ROPTLIB/Others/wavelet/wavelet.cpp
CPPS += $(ROOTPATH)/ROPTLIB/Problems/CFRankQ2FBlindDecon2D.cpp $(ROOTPATH)/ROPTLIB/Problems/CSFRQPhaseRetrieval.cpp $(ROOTPATH)/ROPTLIB/Problems/CStieBrockett.cpp $(ROOTPATH)/ROPTLIB/Problems/EucQuadratic.cpp $(ROOTPATH)/ROPTLIB/Problems/FRankESparseApprox.cpp $(ROOTPATH)/ROPTLIB/Problems/FRankEWeightApprox.cpp $(ROOTPATH)/ROPTLIB/Problems/FRankQ2FMatCompletion.cpp $(ROOTPATH)/ROPTLIB/Problems/GrassRQ.cpp $(ROOTPATH)/ROPTLIB/Problems/Problem.cpp $(ROOTPATH)/ROPTLIB/Problems/ProdStieSumBrockett.cpp $(ROOTPATH)/ROPTLIB/Problems/SFRQLyapunov.cpp $(ROOTPATH)/ROPTLIB/Problems/SPDKarcherMean.cpp $(ROOTPATH)/ROPTLIB/Problems/SphereConvexHull.cpp $(ROOTPATH)/ROPTLIB/Problems/SphereSparsestVector.cpp $(ROOTPATH)/ROPTLIB/Problems/SphereTxRQ.cpp $(ROOTPATH)/ROPTLIB/Problems/StieBrockett.cpp $(ROOTPATH)/ROPTLIB/Problems/StieSPCA.cpp $(ROOTPATH)/ROPTLIB/Problems/mexProblem.cpp $(ROOTPATH)/ROPTLIB/Problems/juliaProblem.cpp
CPPS += $(ROOTPATH)/ROPTLIB/Solvers/AManPG.cpp $(ROOTPATH)/ROPTLIB/Solvers/LRBFGS.cpp $(ROOTPATH)/ROPTLIB/Solvers/LRBFGSSub.cpp $(ROOTPATH)/ROPTLIB/Solvers/LRTRSR1.cpp $(ROOTPATH)/ROPTLIB/Solvers/ManPG.cpp $(ROOTPATH)/ROPTLIB/Solvers/RBFGS.cpp $(ROOTPATH)/ROPTLIB/Solvers/RBFGSSub.cpp $(ROOTPATH)/ROPTLIB/Solvers/RBroydenFamily.cpp $(ROOTPATH)/ROPTLIB/Solvers/RCG.cpp $(ROOTPATH)/ROPTLIB/Solvers/RGS.cpp $(ROOTPATH)/ROPTLIB/Solvers/RNewton.cpp $(ROOTPATH)/ROPTLIB/Solvers/RSD.cpp $(ROOTPATH)/ROPTLIB/Solvers/RTRNewton.cpp $(ROOTPATH)/ROPTLIB/Solvers/RTRSD.cpp $(ROOTPATH)/ROPTLIB/Solvers/RTRSR1.cpp $(ROOTPATH)/ROPTLIB/Solvers/RWRBFGS.cpp $(ROOTPATH)/ROPTLIB/Solvers/Solvers.cpp $(ROOTPATH)/ROPTLIB/Solvers/SolversNSM.cpp $(ROOTPATH)/ROPTLIB/Solvers/SolversNSMPGLS.cpp $(ROOTPATH)/ROPTLIB/Solvers/SolversNSMSub.cpp $(ROOTPATH)/ROPTLIB/Solvers/SolversNSMSubLS.cpp $(ROOTPATH)/ROPTLIB/Solvers/SolversSMLS.cpp $(ROOTPATH)/ROPTLIB/Solvers/SolversSMTR.cpp $(ROOTPATH)/ROPTLIB/Solvers/SolversSM.cpp
CPPS += $(ROOTPATH)/ROPTLIB/test/DriverMexProb.cpp $(ROOTPATH)/ROPTLIB/test/TestCFRankQ2FBlindDecon2D.cpp $(ROOTPATH)/ROPTLIB/test/TestCSFRQPhaseRetrieval.cpp $(ROOTPATH)/ROPTLIB/test/TestCStieBrockett.cpp $(ROOTPATH)/ROPTLIB/test/TestElement.cpp $(ROOTPATH)/ROPTLIB/test/TestEucQuadratic.cpp $(ROOTPATH)/ROPTLIB/test/TestFRankESparseApprox.cpp $(ROOTPATH)/ROPTLIB/test/TestFRankEWeightApprox.cpp $(ROOTPATH)/ROPTLIB/test/TestFRankQ2FMatCompletion.cpp $(ROOTPATH)/ROPTLIB/test/TestGrassRQ.cpp $(ROOTPATH)/ROPTLIB/test/TestProdStieSumBrockett.cpp $(ROOTPATH)/ROPTLIB/test/TestSFRQLyapunov.cpp $(ROOTPATH)/ROPTLIB/test/TestSPDKarcherMean.cpp $(ROOTPATH)/ROPTLIB/test/TestSphereSparsestVector.cpp $(ROOTPATH)/ROPTLIB/test/TestStieBrockett.cpp $(ROOTPATH)/ROPTLIB/test/TestStieSPCA.cpp
# convert a string to upper case.
UPPER_TP  = $(shell echo $(TP) | tr a-z A-Z)
LUBPCPPS := $(ROOTPATH)/LUBP/ClassesProblem.cpp  $(ROOTPATH)/LUBP/LUBP.cpp  $(ROOTPATH)/LUBP/InstructionsProblem.cpp  $(ROOTPATH)/LUBP/mat_operations.cpp  $(ROOTPATH)/LUBP/randn.cpp  $(ROOTPATH)/LUBP/stiefel_stuff.cpp

PARSER :=  $(ROOTPATH)/LUBP/Parsers/CommandParser/command_parser.cpp $(ROOTPATH)/LUBP/Parsers/CommandParser/command_lexer.cpp  $(ROOTPATH)/LUBP/Parsers/InputParser/input_parser.cpp $(ROOTPATH)/LUBP/Parsers/InputParser/input_lexer.cpp $(ROOTPATH)/LUBP/Parsers/MatrixParser/matrix_parser.cpp $(ROOTPATH)/LUBP/Parsers/MatrixParser/matrix_lexer.cpp
LUBPRUN:
	$(CC) -O3 -w -std=c++0x  $(PARSER) $(LUBPCPPS)  $(CPPS)   $(INCDIRS) -D$(UPPER_TP) -DROPTLIB_WITH_FFTW  -static -llapack -lblas -lfftw3 -lm -static -lpthread -lgfortran -lquadmath -lstdc++fs   -o LUBP.exe -std=c++14
