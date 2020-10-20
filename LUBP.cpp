#include <iostream>
#include <iomanip>
#include <complex>
#include <fstream>
#include <chrono>

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

using namespace std::complex_literals;
using namespace boost::numeric::ublas;
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

    std::string line; int param_counter = 0;
    while (param_counter < 4)
    {
        inputfile >> parameters[param_counter++];
    }

    int mat_size_col = parameters[1], num_classes = parameters[2];
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

/*
matrix< std::complex<double> > orth(matrix< std::complex<double> > M) {

    const int length = M.size1();
    matrix< std::complex<double> > r(length, length);
    matrix< std::complex<double> > q(length, length);
    
    int k, i, j;
    for (k = 0; k < length; k++) {
        r(k,k) = 0; // equivalent to sum = 0
        for (i = 0; i < length; i++)
            r(k,k) = r(k,k) + M(i,k) * M(i,k); // rkk = sqr(a0k) + sqr(a1k) + sqr(a2k) 
        r(k,k) = sqrt(r(k,k));  

        for (i = 0; i < length; i++) {
            q(i,k) = M(i,k) / r(k,k);
        }

        for (j = k + 1; j < length; j++) {
            r(k,j) = 0;
            for (i = 0; i < length; i++) 
                r(k,j) += q(i,k) * M(i,j);
            
            for (i = 0; i < length; i++) 
                M(i,j) = M(i,j) - r(k,j) * q(i,k);
        }
    }
    return M;
}
*/

template <class T>
void populateVect(T& V, const int &start = 0, const int &finish = 0, const int &startvalue=0, const int &step = 1) {
    int length = finish ? finish : V.size();
    for (int i = start; i < length; i += step) V(i) = static_cast<int>(i+startvalue);
}

std::string helpStr(const char * exename){
   return std::string(++(++exename))+ " -f [filename] -o [output] -ao [startstr] -d [Dimension] - w [Window Size] " 
                                    + "-t [Time] -ma [Accuracy] -mi [Max Iterations] -mti [Max Total Iterations]"
                                    + "\t-o    Output filename\n"
                                    + "\t-ao   Automatic file naming (requieres str to start the file name)\n"
                                    + "\t-f    Input Filename (MANDATORY)(requires formated input file)\n"
                                    + "\t-d    Matrix Dimension (positive integer)\n"
                                    + "\t-w    Window Size (positive integer)\n"
                                    + "\t-t    Killing Time (positive integer)\n"
                                    + "\t-ma   Minimum Accuracy (positive float)\n"
                                    + "\t-mi   Maximum Iterations (positive integer)\n"
                                    + "\t-mti  Maximum Total Iterations (positive integer)\n"
                                    + "\t-h    Shows this help\n";
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

int main(int argc, char *argv[])
{   
	__assert(argc != 2 || strcmp(argv[1], parameters_name[par_size]), helpStr(argv[0]));
    __assert(argc > 2 && (argc+1)%2==0, "Wrong number of arguments.\n Type -h to see help.");
    
    std::string filename;   bool automatic_naming = false; char *an_str;
    for (int i = 1; i < argc; i+=2)
    {
        bool param_exist = false;
        for (int j = 0; j < par_size; j++)
        {
            if (!strcmp(parameters_name[j], argv[i])){                     
                param_exist = true;
                
                if(j==0) { filename = argv[i+1]; break; } 
                if(j==1) { __assert(freopen(argv[i+1], "w", stdout)!=NULL, "Can't open output file."); break; }
                if(j==2) { automatic_naming = true; an_str = argv[i+1]; break; }

                try { parametersArr[j-3] = boost::lexical_cast<double>(argv[i+1]); }
                catch (boost::bad_lexical_cast const &){
                    __assert(false, "Wrong \"" + std::string(parameters_name[j])+ "\" argument. Type " +
                                        std::string(argv[0]) + " -h command to see help." );
                }
            }
        }            
        __assert(param_exist, "Wrong \"" + std::string(argv[i]) + "\" parameter. Type "+
                         std::string(argv[0]) +" -h command to see help.");
    }
    
    int matdim = parametersArr[0], windowSize = parametersArr[1], killingtime=parametersArr[3],
            maxiter = parametersArr[4], maxtotaliterations = parametersArr[5]; 
    double minaccuracy = parametersArr[2];

    MAXITERATION = maxiter;

    if(automatic_naming){ 
        sprintf(an_str,"%s_%s_dim_%d_win_%d.dat", an_str,
                        std::experimental::filesystem::path(filename).filename().c_str(), matdim, windowSize);
        __assert(freopen(an_str, "w", stdout)!=NULL, "Can't open output file."); 
    }

    int* parameters = new int[4];
    vector< matrix<int> > D;
    
    auto starttime = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);

    __assert(loadFile(filename, parameters, D), "Wrong filename arg -f [filename].\n Type -h arg to see help.");
    
    int l = parameters[1], s = parameters[2], c = parameters[3];
    int instructions_length = l * s + c;
    
    vector<matrix<std::complex<double>>> instructions(instructions_length);
    matrix< std::complex<double> > randorthM(matdim,matdim);
    for (int i = 0; i < instructions_length; i++)
    {
        getRandOrthMatrix(randorthM);
        instructions(i) = randorthM;
    }
    
    vector<int> Indices(l);
    populateVect(Indices);

    int totaliterations = 0, initialposition = 0;

    double discreteDist = DiscreteDistance(s, D, Indices, instructions);

    auto updatetime = std::chrono::high_resolution_clock::now();

    // Calculating total time taken by the program. 
    double time_taken =
        std::chrono::duration_cast<std::chrono::nanoseconds>(updatetime - starttime).count();

    time_taken *= 1e-9;

    double realDist = 0, minDist = 1.0;

    std::cout << "Iteration" <<  "\tTime" << "\t\tD. Distance" << 
                 "\tR. Distance" << std::fixed << std::setprecision(4) << std::endl;

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
            "\t\t" << discreteDist << "\t\t" << realDist << std::endl;//std::setprecision(4) << std::fixed <<
        }
        else if(totaliterations%50==0){
            std::cout << totaliterations << "*\t\t" << time_taken << 
            "\t\t" << discreteDist << "\t\t" << realDist << std::endl;
        }
    }

    std::cout << "Discrete distance: " << minDist << std::endl;
    std::cout << "Time taken by program is : " << std::setprecision(4) << std::fixed
        << time_taken << std::setprecision(9);
    std::cout << " sec" << std::endl;
}
