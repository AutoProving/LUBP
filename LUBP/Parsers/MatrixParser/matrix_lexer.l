/**************************************************************************
LUBP: Learning Unitary Branching Programs

Copyright 2021 Mateus de Oliveira Oliveira and Farhad Vadiee.

Copyright 2020 Mateus de Oliveira Oliveira and Fidel Ernesto Diaz Andino

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

