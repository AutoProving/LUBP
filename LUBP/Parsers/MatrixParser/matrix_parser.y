//Copyright 2020 Mateus de Oliveira Oliveira, Farhad Vadiee and CONTRIBUTORS.
%defines
%define api.prefix {matrix_}

%code requires {
    // include required headers
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
    using namespace std::complex_literals;
    using namespace boost::numeric::ublas;
}
%{
    // include required headers
   
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
    using namespace std::complex_literals;
    using namespace boost::numeric::ublas;
    // this function will be generated
    // using flex
    extern int yylex();
    extern int matrix_lineno;

    extern void yyerror(int &matdim, int &l, int &s,int &c, vector<int> &Indices, vector<matrix<std::complex<double>>> &instructions ,char const* msg);
%}
%locations
%union{
     double number;
     char* string;
     vector<std::complex<double> >* vec;
     matrix<std::complex<double>>* mat;
     std::complex<double>* complexnum;

}

// define parameters which are passed 
%parse-param {int &matdim}
%parse-param {int &l}
%parse-param {int &s}
%parse-param {int &c}
%parse-param {vector<int> &Indices}
%parse-param {vector<matrix<std::complex<double>>> &instructions}

%token  MATRIX_NEWLINE MATRIX_WORD MATRIX_LEFT_PARENTHESIS MATRIX_DOUBLE MATRIX_COMMA MATRIX_RIGHT_PARENTHESIS MATRIX_PARAMETERS_WORD MATRIX_INDICES_WORD
%type<number> MATRIX_DOUBLE
%type<vec> MATRIX_ROW
%type<complexnum> MATRIX_COMPLEX_PAIR
%type<mat> MATRIX_ROWS MATRIX_MATRIX
%type<string> MATRIX_COMMA MATRIX_RIGHT_PARENTHESIS MATRIX_NEWLINE MATRIX_WORD MATRIX_LEFT_PARENTHESIS MATRIX_PARAMETERS_WORD MATRIX_INDICES_WORD


%start MATRIX_START

%%

MATRIX_START		:   MATRIX_PARAMETERS MATRIX_INDICES_WORD  MATRIX_INDICES MATRIX_NEWLINE MATRIX_MATRICES {if(Indices.size()!= l){std::cout<<"Indices dimension is not correct"<<std::endl; YYERROR;}
												if(instructions.size()!= l*s+c){std::cout<<"Instructions dimension is not correct: "<<instructions.size()<<std::endl; YYERROR;}
											  	for(int i=0 ; i < l*s+c ; i++){
											  		if(instructions(i).size1()!= matdim or instructions(i).size2()!= matdim ){
											  			std::cout<<"matrix dimension error"<<std::endl;
											  			YYERROR;
											  		}
											  	}
											  }
			;
MATRIX_PARAMETERS	:  MATRIX_PARAMETERS_WORD MATRIX_DOUBLE MATRIX_NEWLINE MATRIX_DOUBLE MATRIX_NEWLINE MATRIX_DOUBLE MATRIX_NEWLINE MATRIX_DOUBLE MATRIX_NEWLINE{
				matdim = (int)($2); l = (int)($4); s = (int)($6); c=(int)($8);
			}
			;
MATRIX_INDICES		:  MATRIX_INDICES MATRIX_NEWLINE MATRIX_DOUBLE {Indices.resize(Indices.size()+1,true); Indices(Indices.size()-1) = (int)($3);}
			|  MATRIX_DOUBLE {Indices.resize(Indices.size()+1,true); Indices(Indices.size()-1) = (int)($1);}
			;
MATRIX_MATRICES		: MATRIX_MATRICES MATRIX_MATRIX   {instructions.resize(instructions.size()+1,true);
							   instructions(instructions.size()-1)= *$2;
							   }
			| MATRIX_MATRIX {instructions.resize(instructions.size()+1,true); instructions(instructions.size()-1)= *$1;}
			;
MATRIX_MATRIX		: MATRIX_WORD MATRIX_ROWS MATRIX_NEWLINE {$$ = new matrix<std::complex<double>>(matdim,matdim); $$ = $2;}
			;
MATRIX_ROWS		: MATRIX_ROWS MATRIX_NEWLINE MATRIX_ROW {if($1->size2()!= matdim or $3->size() != matdim){std::cout<<"dimenstion" <<std::endl; YYERROR;}
										$$ = new  matrix<std::complex<double>>($1->size1()+1,matdim);
										for(int i=0; i< $1->size1() ; i++) {
											for(int j=0 ; j < matdim ; j++){
												(*$$)(i,j) = (*$1)(i,j);
											}
										}
										for(int i=0; i < matdim ; i++){ (*$$)($$->size1()-1,i) = (*$3)(i);}

										}
			| MATRIX_ROW {
				if ($1->size()!=matdim){std::cout<<" matrix row dimention"<<std::endl; YYERROR;} $$ = new matrix<std::complex<double>>(1,matdim);
				for(int i=0; i < matdim ; i++){ (*$$)($$->size1()-1,i) = (*$1)(i);}
			}
			;
MATRIX_ROW		:  MATRIX_ROW MATRIX_COMPLEX_PAIR {$$ = new vector<std::complex<double> >($1->size()); $$ = $1; $$->resize($$->size()+1,true);
 								(*$$)($$->size()-1)=(*$2); }
			|  MATRIX_COMPLEX_PAIR {$$ = new vector<std::complex<double> >(1); (*$$)(0) = *$1;}
			;
MATRIX_COMPLEX_PAIR 	: MATRIX_LEFT_PARENTHESIS MATRIX_DOUBLE MATRIX_COMMA MATRIX_DOUBLE MATRIX_RIGHT_PARENTHESIS { $$ = new std::complex<double>($2,$4);}
			;
%%

void yyerror(int &matdim, int &l,  int &s,int &c, vector<int> &Indices, vector<matrix<std::complex<double>>> &instructions ,char const* msg){
  std::cout<<"Syntax Error: " << msg <<" " << matrix_lineno << std::endl;
  // error printing  disabled, it is handeled in main.cpp 
}

