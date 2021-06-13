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



#include <iostream>
#include <iomanip>
#include <complex>
#include <fstream>
#include <chrono>
#include <stdio.h>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>
#include <boost/numeric/ublas/vector_expression.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <boost/optional.hpp>
#include <boost/convert/lexical_cast.hpp>
#include <experimental/filesystem>

#include "mat_operations.h"
#include "randn.h"
#include "Parsers/InputParser/input_parser.hpp"
#include "Parsers/MatrixParser/matrix_parser.hpp"
#include "Parsers/CommandParser/command_parser.hpp"

using namespace std::complex_literals;
using namespace boost::numeric::ublas;
extern FILE *input_in;
extern FILE *matrix_in;
extern FILE *command_in;

//using namespace LUBPP;

void __assert(const bool& expression, std::string strerr){
    if(!expression)
    {
        std::cerr << strerr << std::endl;
        exit(0);
    }
}

bool loadFile(const std::string filename, int* parameters, vector< matrix<int> >& M) {
    std::ifstream inputfile(filename);

    if (inputfile.fail()) return false;
    // parameters[0]= number of strings, parameters[1] = length of a string, parameters[2]= alphabet's size, parameters[3]= number of classes
    std::string line; int param_counter = 0;
    while (param_counter < 4)
    {
        inputfile >> parameters[param_counter++];
    }

    int mat_size_col = parameters[1];
    int num_classes = parameters[2];
    int mat_size_row = parameters[0] / num_classes;

    M.resize(num_classes, true);
    for (int i = 0; i < num_classes; i++)
    {
            M(i).resize(mat_size_row, mat_size_col, true);

    }

    int k = mat_size_row-1, classes = num_classes-1;
    while (getline(inputfile, line))
    {
        int str_length = line.length() - 5;
        if (str_length > 0) {
            int j = 0;

            for (int i = 0; i < str_length; i++) {
                if (line[i] == ' ') {
                    continue;
                }
                else {
                    M(classes)(k,j++) = static_cast<int>(line[i] - 48);
                }
            }
            k--;
        }
        if (k < 0) {
            k = mat_size_row-1;
            classes--;
        }
    }
    return true;
}

template <class T>
void populateVect(T& V, const int &start = 0, const int &finish = 0, const int &startvalue=0, const int &step = 1) {
    int length = finish ? finish : V.size();
    for (int i = start; i < length; i += step) V(i) = static_cast<int>(i+startvalue);
}



// default values
    const char *parameters_name[] = {"-f"/*infile*/, "-o"/*outfile*/, "-ao"/*AutomaticOutfile*/, "-d"/*MatDim*/,
                                     "-w"/*WindowSize*/, "-ma" /*MinAccur*/, "-t" /*KillTime*/, "-mi"/*MaxIter*/,
                                     "-mti"/*MaxTotalIters*/, "-h"/*Help*/} ;
    double parametersArr[] = { 2/*MatDim*/, 1/*WindowSize*/, 0/*MinAccur*/, 1000 /*KillTime*/,
                                20/*MaxIter*/, 100000/*MaxTotalIters*/};
    const int par_size = sizeof(parameters_name)/sizeof(const char *) -1;

    int MAXITERATION;
// end default

void printBranchingProgram(int &d, int &l, int &s, int &c, vector<int> &indices, vector<matrix<std::complex<double>>> &instructions,std::string fileName){
    std::ofstream inputfile(fileName);
    inputfile.precision(17);
    inputfile<<"PARAMETERS"<<std::endl;
    inputfile<< d <<std::endl;
    inputfile<< l <<std::endl;
    inputfile<< s <<std::endl;
    inputfile<< c<<std::endl;
    inputfile<< "INDICES"<<std::endl;
    for(auto item:indices ){
        inputfile<< item <<std::endl;
    }
    for(auto item:instructions ){
        inputfile<<"Matrix"<<std::endl;
        for(int i=0; i < item.size1() ; i++){
            for(int j=0; j < item.size2(); j++){
                inputfile<<item(i,j)<< " ";
            }
            inputfile<<std::endl;
        }
    }
    inputfile.close();
}

void readBranchingProgram(int &matdim, int &l, int &s, int &c, vector<int> &Indices, vector<matrix<std::complex<double>>> &instructions,std::string fileName){
    // length of the vector instructions is l*s+c
    matrix_in = fopen(fileName.c_str(), "r");
    if (!matrix_in) {
    std::cout<<fileName<<std::endl;
    std::perror("Branching Program file opening failed");
        exit(20);
    }
    int  result_arg=10;
    Indices.resize(0,true);
    instructions.resize(0,true);
    result_arg = matrix_parse(matdim,l,s,c,Indices,instructions);
    if(result_arg!=0){
        std::cout<<"Branching Program error!"<<std::endl;
        exit(20);
    }
    // for testing purposes
    //printBranchingProgram(matdim,l,s,c,Indices,instructions,"resultTest.txt");
}


void learnUBP(vector< matrix<int> > &D, int &matdim,int &l,int &s,int &c, vector<int> &Indices, vector<matrix<std::complex<double>>> &instructions,
                int &windowSize, int &killingtime, int &maxiter,int &maxtotaliterations, double &minaccuracy, std::string ubpFileName){
    // D = dataSet
    // d = dimension of matrices
    // l = number of instructions
    // s = size of the alphabet
    // c = number of classes
    // Indices = vector of indices of size l
    // initialInstruction = vector of matrices contains l*s matrices corresponding to instructions plus c matrices corresponding to classes. The size of this vector is l*s+c.
    // windowSize = number of instructions to be optimized at each iteration
    // killingtime = maximum number of seconds for the learn algorithm
    // maxiter = maximum number of iterations in the gradient descent algorithm (This should be a small number, say between 10 and 100)
    // maxtotaliterations = total number of windows being optimized, this number should be very large and should depend on the number of instructions, say 10*l.
    // minaccuracy = the minimum accepted accuracy, this should be a number between 0 and 1. 0 means 0 error, and 0.1 means that the branching program makes at most 10% mistake in each class.

    auto starttime = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
    int totaliterations = 0, initialposition = 0 ;
    int totaliterationsForMiddleBranchigProgramOfLastFile=0;

    double discreteDist = DiscreteDistance(s, D, Indices, instructions);

    auto updatetime = std::chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(updatetime - starttime).count();

    time_taken *= 1e-9;

    double realDist = 0, minDist = 1.0;

    std::cout << "Iteration" <<  "\tTime" << "\t\tD. Distance" <<
    "\tR. Distance" << std::fixed << std::setprecision(17) << std::endl;

    vector < vector <matrix< std::complex<double> > > > leftMatrices, rightMatrices, evaluatedMatrices;
    vector < matrix< std::complex<double> > > localmatrices;
    vector <int> listpositions;

    while (discreteDist > minaccuracy && totaliterations < maxtotaliterations && time_taken <= killingtime) {

        listpositions = vector <int>(windowSize);
        populateVect(listpositions, 0, 0, initialposition);

        leftMatrices = ConstructLeft(s, matdim, c, D, Indices, instructions, initialposition);
        rightMatrices = ConstructRight(s, matdim, c, D, Indices, instructions, initialposition, windowSize);

        localmatrices = localOptimizerInstructionsOptimized(s, l, c, matdim, maxiter, listpositions,
                                                        instructions, D, Indices, leftMatrices, rightMatrices);

        for (int pos = 0; pos < listpositions.size(); pos++)
        {
            for (int symbol = 0; symbol < s; symbol++)
            {
                instructions( listpositions(pos) * s + symbol ) = localmatrices(pos*s + symbol );
            }
        }

        listpositions = vector <int>(c - 1);
        populateVect(listpositions, 0, 0,  l * s);

        evaluatedMatrices = ConstructEvaluatedMatrices(s, c, D, Indices, instructions);
        localmatrices = localOptimizerClassesOptimized(s, l, c, matdim, maxiter, instructions, D, evaluatedMatrices);

        for (int pos = 0; pos < listpositions.size(); pos++)
        {
            instructions(listpositions(pos)) = localmatrices(pos);
        }

        totaliterations = totaliterations + 1;
        initialposition = initialposition + 1;

        if (initialposition == (l - windowSize + 1))
            initialposition = 0;

        discreteDist = DiscreteDistance(s, D, Indices, instructions);
        realDist = Distance(s, D, Indices, instructions);

        updatetime = std::chrono::high_resolution_clock::now();
        time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(updatetime - starttime).count();
        time_taken *= 1e-9;

        if (discreteDist < minDist) {
            minDist = discreteDist;
            std::cout << totaliterations << "\t\t" << time_taken <<
            "\t\t" << discreteDist << "\t\t" <<minDist<<"\t\t" << realDist << std::endl;//std::setprecision(4) << std::fixed <<
            printBranchingProgram(matdim,l,s,c,Indices,instructions,ubpFileName+std::to_string(totaliterations)+".txt");
            std::remove((ubpFileName+std::to_string(totaliterationsForMiddleBranchigProgramOfLastFile)+".txt").c_str());
            totaliterationsForMiddleBranchigProgramOfLastFile = totaliterations;
        }else if(totaliterations%50==0){
            std::cout << totaliterations << "*\t\t" << time_taken <<
            "\t\t" << discreteDist << "\t\t"<<minDist<<"\t\t" << realDist << std::endl;
        }
    }

    discreteDist = DiscreteDistance(s, D, Indices, instructions);
    realDist = Distance(s, D, Indices, instructions);
    std::cout << "Discrete distance: " << discreteDist << std::endl;
    std::cout << "Real distance: " << realDist << std::endl;
    std::cout << "Time taken by program is : " << std::setprecision(17) << std::fixed
    << time_taken << std::setprecision(17);
    std::cout << " sec" << std::endl;
}

int main(int argc, char *argv[])
{
    std::string helpStr ="";
    helpStr = helpStr+".\/LUBP.exe -mode learn -data [dataSetFilename] -d [Dimension] -w [Window Size] "
              + "-t [Time] -ma [Accuracy] -mi [Max Iterations] -mti [Max Total Iterations] -ubp [ubpFileName]"
              + "\t-f    Input Filename (MANDATORY)(requires formated input file)\n"
              + "\t-d    Matrix Dimension (positive integer)\n"
              + "\t-w    Window Size (positive integer)\n"
              + "\t-t    Killing Time (positive integer)\n"
              + "\t-ma   Minimum Accuracy (positive float)\n"
              + "\t-mi   Maximum Iterations (positive integer)\n"
              + "\t-mti  Maximum Total Iterations (positive integer)\n"
              + "\t-ubp  Starts the iterations with a branching program given in file <ubpFileName>\n"
              + "-mode evaluate -data <dataSetFileName> -ubp <ubpFileName>\n"
              + "-help    Shows this help\n";
    std::string _all_arg;
    for (int i = 1 ; i < argc; i++) {
        _all_arg += argv[i];
        if(i != argc-1){
            _all_arg += "\n";
        }else{
            _all_arg +="\n;";
        }
    }
    // Create and open a text file
    char filename1[L_tmpnam];
    tmpnam(filename1);
    std::ofstream MyFile(filename1);
    // Write to the file
    MyFile << _all_arg;
    // Close the file
    MyFile.close();
    command_in = fopen(filename1, "r");
    if (!command_in) {
        std::perror("Command file opening failed");
        return EXIT_FAILURE;
    }
    int result=10;
    int mode;
    std::string inputFileName;
    int d;
    int windowSize;
    int killingtime;
    double minaccuracy;
    int maxiter;
    int maxtotaliterations;
    std::string ubpFile;

    result = command_parse(mode, inputFileName, d, windowSize,killingtime, minaccuracy, maxiter, maxtotaliterations,ubpFile,helpStr);
    if(result!=0){
        std::cout<<"run .\/LUBP.exe -help"<<std::endl;
        exit(20);
    }
    std::cout<<"mode "<<mode<<"\tinputFileName "<<inputFileName<<" \td "<<d<<" \twindowSize "
    <<windowSize<<"\tkillingtime "<<killingtime<<"\tminaccuracy " <<minaccuracy<<"\tmaxiter "<<maxiter<<"\tmaxtotaliterations "<<maxtotaliterations<<"\tubpFile "<<ubpFile<<std::endl;
    if(result!=0){
        std::cout<<"error"<<std::endl;
        exit(20);
    }
    inputFileName.erase(std::remove(inputFileName.begin(), inputFileName.end(), '\n'), inputFileName.end());
    ubpFile.erase(std::remove(ubpFile.begin(), ubpFile.end(), '\n'), ubpFile.end());
    fclose(command_in);
    /////////////////////////////////////////////////////////////////////
    std::string baseName = std::experimental::filesystem::path(inputFileName).stem();
    std::string filename = inputFileName;
    int matdim = d;
    std::string fileNameStatistics = baseName + "_d_"+std::to_string(matdim)+"_w_"+std::to_string(windowSize)+"_ma_"+std::to_string(minaccuracy)+"_Statistics.txt";
    std::string fileNameBranchingProgram = baseName + "_d_"+std::to_string(matdim)+"_w_"+std::to_string(windowSize)+"_ma_"+std::to_string(minaccuracy)+"_BranchingProgram.txt";
    std::string fileNameInitialBranchingProgram = baseName + "_d_"+std::to_string(matdim)+"_w_"+std::to_string(windowSize)+"_ma_"+std::to_string(minaccuracy)+"_InitialBranchingProgram.txt";
    std::string fileNameMiddleBranchingProgram = baseName + "_d_"+std::to_string(matdim)+"_w_"+std::to_string(windowSize)+"_ma_"+std::to_string(minaccuracy)+"_MiddleBranchingProgram_";

    input_in = fopen(filename.c_str(), "r");
    if (!input_in) {
        std::perror("Data Set File opening failed");
        std::perror(filename.c_str());
        return EXIT_FAILURE;
    }
    int result_arg=10;
    int l=0;
    int s=0;
    int c=0;
    vector< matrix<int> > D;
    result_arg = input_parse(l,s,c,D);
    if(result_arg!=0){
        std::cout<<"Data Set File error!"<<std::endl;
        exit(20);
    }
    std::cout<<" parameters"<<std::endl;
    std::cout<<"d: "<<matdim<<" l: " <<l<<" s: "<<s <<" c: "<< c<<std::endl;
    /////////////////////////////////////////////////////////////////////
    if(mode==1){
        freopen(fileNameStatistics.c_str(), "w", stdout);
        vector<int> Indices(l);
        populateVect(Indices);
        // Instruction matrices
        int instructions_length = l * s + c;
        vector<matrix<std::complex<double>>> instructions(instructions_length);
        if(ubpFile==""){
            std::cout<<"learn random"<<std::endl;
            matrix< std::complex<double> > randorthM(matdim,matdim);
            for (int i = 0; i < instructions_length; i++)
            {
                getRandOrthMatrix(randorthM);
                instructions(i) = randorthM;
            }
        }else{
            std::cout<<"learn from input"<<std::endl;
            instructions.resize(0);
            readBranchingProgram(matdim, l, s, c, Indices, instructions,ubpFile);
        }

        MAXITERATION = maxiter; // This is a global parameter which is used by the solver
        printBranchingProgram(matdim,l,s,c,Indices,instructions,fileNameInitialBranchingProgram);

        learnUBP(D,d,l,s,c, Indices,instructions,windowSize,killingtime, maxiter,maxtotaliterations,minaccuracy,fileNameMiddleBranchingProgram);

        printBranchingProgram(matdim,l,s,c,Indices,instructions,fileNameBranchingProgram);

    }else if(mode == 2){
        std::string ubpFileEvaluate = std::experimental::filesystem::path(ubpFile).stem();

        freopen((baseName+"_Evaluate"+"_"+ubpFileEvaluate+".txt").c_str(), "w", stdout);
        vector<int> Indices(l);
        populateVect(Indices);
        // Instruction matrices
        int instructions_length = l * s + c;
        vector<matrix<std::complex<double>>> instructions(instructions_length);
        instructions.resize(0);
        readBranchingProgram(matdim, l, s, c, Indices, instructions, ubpFile);
        double discreteDist = DiscreteDistance(s, D, Indices, instructions);
        double realDist = Distance(s, D, Indices, instructions);
        std::cout<< " discreteDist: " << discreteDist  << "  realDist: " << realDist<<std::endl;
    }
    return 0;
}
