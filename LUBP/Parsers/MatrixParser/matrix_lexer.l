/*Copyright 2020 Mateus de Oliveira Oliveira, Farhad Vadiee and CONTRIBUTORS.*/
%option noyywrap
%option prefix="matrix_"
%{
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
    #include <stdlib.h>
    using namespace std::complex_literals;
    using namespace boost::numeric::ublas;
    #include "matrix_parser.hpp"
    #define yylval matrix_lval

    extern int yyparse(int &matdim, int &l, int &s,int &c, vector<int> &Indices, vector<matrix<std::complex<double>>> &instructions);

%}

%option yylineno
DIGIT [0-9]
%%
Matrix\n                                 yylval.string = strdup(yytext);  return MATRIX_WORD;
INDICES\n                                yylval.string = strdup(yytext);  return MATRIX_INDICES_WORD;
PARAMETERS\n                             yylval.string = strdup(yytext);  return MATRIX_PARAMETERS_WORD;
[\+\-\.0-9]+[a-zA-Z]*[\-\+0-9]*          yylval.number= std::stold(yytext); return MATRIX_DOUBLE;
","                                      yylval.string = ",";             return MATRIX_COMMA;
"("                                      yylval.string = "(";             return MATRIX_LEFT_PARENTHESIS;
")"                                      yylval.string = ")";             return MATRIX_RIGHT_PARENTHESIS;
\n                                       yylval.string= strdup(yytext);   return MATRIX_NEWLINE;
[ \t]+                                  ;
%%

