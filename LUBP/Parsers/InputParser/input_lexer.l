/*Copyright 2020 Mateus de Oliveira Oliveira, Farhad Vadiee and CONTRIBUTORS.*/
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

