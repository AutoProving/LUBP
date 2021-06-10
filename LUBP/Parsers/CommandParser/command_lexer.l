/*Copyright 2020 Mateus de Oliveira Oliveira, Farhad Vadiee and CONTRIBUTORS.*/
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
