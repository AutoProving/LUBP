//Copyright 2020 Mateus de Oliveira Oliveira, Farhad Vadiee and CONTRIBUTORS.
%defines
%define api.prefix {command_}

%code requires {
    // include required headers
    #include <iostream>
    #include <string.h>

}
%{
    // include required headers

    #include <iostream>
    #include <string.h>

    // this function will be generated
    // using flex
    extern int yylex();
    extern int command_lineno;

    extern void yyerror(int &mode, std::string &inputFileName, int &d, int &windowSize, int &killingtime, double &minaccuracy, int &maxiter, int &maxtotaliterations
    , std::string &ubpFile, std::string help,char const* msg);
%}
%locations
%union{
     int number;
     double doublenum;
     char* string;

}

// define parameters which are passed
%parse-param {int &mode}
%parse-param {std::string &inputFileName}
%parse-param {int &d}
%parse-param {int &windowSize}
%parse-param {int &killingtime}
%parse-param {double &minaccuracy}
%parse-param {int &maxiter}
%parse-param {int &maxtotaliterations}
%parse-param {std::string &ubpFile}
%parse-param {std::string help}


%token  command_string command_int command_double command_ubp_word command_mode_word command_data_word  command_d_word command_w_word
command_t_word command_ma_word command_mi_word command_mti_word  command_help  command_learn_word command_evaluate_word
%type<number> command_int
%type<string> command_string  command_mode_word command_data_word   command_d_word command_w_word command_learn_word
                                              command_t_word command_ma_word command_mi_word command_mti_word command_ubp_word command_help command_evaluate_word
%type<doublenum> command_double


%start command_start

%%
command_start : command_mode1 command_data command_d command_w command_t command_ma command_mi command_mti command_ubp
	      | command_mode2 command_data command_ubp
	      | command_help {std::cout<<help; exit(20);}
	      ;
command_mode1 : command_mode_word command_learn_word{mode=1;}
command_mode2 : command_mode_word command_evaluate_word{mode =2 ;}
	     ;
command_data : command_data_word command_string {inputFileName = $2; }

command_d  : command_d_word command_double {d=$2;}
	   ;
command_w  : command_w_word command_double {windowSize = $2;}
	   ;
command_t  : command_t_word command_double {killingtime = $2;}
	   ;
command_ma : command_ma_word command_double {minaccuracy = $2;}
	   ;
command_mi : command_mi_word command_double {maxiter = $2;}
	   ;
command_mti : command_mti_word command_double {maxtotaliterations = $2;}
	    ;
command_ubp : command_ubp_word command_string {ubpFile = $2;}
	    | %empty { }
%%

void yyerror(int &mode, std::string &inputFileName, int &d, int &windowSize, int &killingtime, double &minaccuracy, int &maxiter, int &maxtotaliterations
                 , std::string &ubpFile, std::string help, char const* msg){
  std::cout<<"For help run with -help"<<std::endl;
  //std::cout<<"Syntax Error: " << msg <<" " <<command_lineno << std::endl;
  // error printing  disabled, it is handeled in main.cpp
}

