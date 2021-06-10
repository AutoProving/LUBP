//Copyright 2020 Mateus de Oliveira Oliveira, Farhad Vadiee and CONTRIBUTORS.
%defines
%define api.prefix {input_}

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
    extern int input_lineno;

    extern void yyerror(int &l, int &s, int &c, vector< matrix<int> > &M,char const* msg);
%}
%locations
%union{
     int number;
     char* string;
     vector<int>* vec;
}

// define parameters which are passed 
%parse-param {int &l}
%parse-param {int &s}
%parse-param {int &c}
%parse-param {vector<matrix<int>> &M}

%token  INPUT_INT INPUT_NEWLINE  INPUT_DASH
%type<number> INPUT_INT 
%type<vec> INPUT_ELEMENTS


%start START

%%

START   : INPUT_PARAMETERS INPUT_MATRICES_STRING INPUT_NEWLINES { }
        ;
INPUT_PARAMETERS	: INPUT_INT INPUT_NEWLINE INPUT_INT INPUT_NEWLINE INPUT_INT INPUT_NEWLINE INPUT_INT  {  l=$3; s=$5; c=$7;   M.resize(c, true);}
 			;
INPUT_MATRICES_STRING       : INPUT_MATRICES_STRING INPUT_NEWLINE INPUT_ELEMENTS INPUT_DASH INPUT_INT  { if($5 >= c or $3->size()!=l){std::cout<<"Dimention Error"<<std::endl; YYERROR;} M($5).resize(M($5).size1()+1,l,true);
                                                                    for(int i = 0 ; i < $3->size(); i++){ M($5)(M($5).size1()-1,i) = (*($3))(i); }
                                                                    }
                            |
                            ;
                                                                   

INPUT_ELEMENTS              :  INPUT_ELEMENTS INPUT_INT {$$ = new vector<int>; $$ = $1 ; $$->resize($$->size()+1,true); (*$$)($$->size()-1)=$2;}
                            | INPUT_INT { $$ = new vector<int>; $$->resize($$->size()+1,true); (*$$)($$->size()-1)= $1;}
                            ;
INPUT_NEWLINES		    : INPUT_NEWLINE
			     |
			     ;
%%

void yyerror(int &l, int &s, int &c, vector< matrix<int> > &M,char const* msg){
  std::cout<<"Syntax Error: " << msg <<" " <<input_lineno << std::endl;
  // error printing  disabled, it is handeled in main.cpp 
}

