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
%option prefix="input_"
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
    using namespace std::complex_literals;
    using namespace boost::numeric::ublas;
    #include "input_parser.hpp"
    #define yylval input_lval

    extern int yyparse(int &l, int &s, int &c, vector<matrix<int>> &M);

%}

%option yylineno

%%

[0-9]+                      yylval.number= atoi(yytext);   return INPUT_INT;
\-                          yylval.string = "-";           return INPUT_DASH;
\n                          yylval.string= strdup(yytext); return INPUT_NEWLINE;

[ \t]+                      ;
%%

