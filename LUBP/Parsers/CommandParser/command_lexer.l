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
%option prefix="command_"
%{
    #include <iostream>

    #include "command_parser.hpp"
    #define yylval command_lval

    extern int yyparse(int &mode, std::string &inputFileName, int &d, int &windowSize, int &killingtime, double &minaccuracy, int &maxiter, int &maxtotaliterations
                           , std::string &ubpFile,std::string help);

%}

%option yylineno
DIGIT [0-9]

%%
-mode\n                       yylval.string = strdup(yytext);  return command_mode_word;
learn\n                       yylval.string = strdup(yytext);  return command_learn_word;
evaluate\n                    yylval.string = strdup(yytext);  return command_evaluate_word;
-data\n                       yylval.string = strdup(yytext);  return command_data_word;
-d\n                          yylval.string = strdup(yytext);  return command_d_word;
-w\n                          yylval.string = strdup(yytext);  return command_w_word;
-t\n                          yylval.string = strdup(yytext);  return command_t_word;
-ma\n                         yylval.string = strdup(yytext);  return command_ma_word;
-mi\n                         yylval.string = strdup(yytext);  return command_mi_word;
-mti\n                        yylval.string = strdup(yytext);  return command_mti_word;
-ubp\n                        yylval.string = strdup(yytext);  return command_ubp_word;
-help\n                          yylval.string = strdup(yytext);  return command_help;
\+?{DIGIT}*\.?{DIGIT}+\n      yylval.doublenum = atof(yytext); return command_double;
[\-\_\"a-zA-Z\.\\\/0-9\(\)]+\n    yylval.string = strdup(yytext);  return command_string;
[ \t]+                      ;
%%
