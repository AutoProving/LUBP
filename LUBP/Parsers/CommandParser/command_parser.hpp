/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_COMMAND_COMMAND_PARSER_HPP_INCLUDED
# define YY_COMMAND_COMMAND_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef COMMAND_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define COMMAND_DEBUG 1
#  else
#   define COMMAND_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define COMMAND_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined COMMAND_DEBUG */
#if COMMAND_DEBUG
extern int command_debug;
#endif
/* "%code requires" blocks.  */
#line 5 "command_parser.y"

    // include required headers
    #include <iostream>
    #include <string.h>


#line 63 "command_parser.hpp"

/* Token type.  */
#ifndef COMMAND_TOKENTYPE
# define COMMAND_TOKENTYPE
  enum command_tokentype
  {
    command_string = 258,
    command_int = 259,
    command_double = 260,
    command_ubp_word = 261,
    command_mode_word = 262,
    command_data_word = 263,
    command_d_word = 264,
    command_w_word = 265,
    command_t_word = 266,
    command_ma_word = 267,
    command_mi_word = 268,
    command_mti_word = 269,
    command_help = 270,
    command_learn_word = 271,
    command_evaluate_word = 272
  };
#endif

/* Value type.  */
#if ! defined COMMAND_STYPE && ! defined COMMAND_STYPE_IS_DECLARED
union COMMAND_STYPE
{
#line 26 "command_parser.y"

     int number;
     double doublenum;
     char* string;


#line 99 "command_parser.hpp"

};
typedef union COMMAND_STYPE COMMAND_STYPE;
# define COMMAND_STYPE_IS_TRIVIAL 1
# define COMMAND_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined COMMAND_LTYPE && ! defined COMMAND_LTYPE_IS_DECLARED
typedef struct COMMAND_LTYPE COMMAND_LTYPE;
struct COMMAND_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define COMMAND_LTYPE_IS_DECLARED 1
# define COMMAND_LTYPE_IS_TRIVIAL 1
#endif


extern COMMAND_STYPE command_lval;
extern COMMAND_LTYPE command_lloc;
int command_parse (int &mode, std::string &inputFileName, int &d, int &windowSize, int &killingtime, double &minaccuracy, int &maxiter, int &maxtotaliterations, std::string &ubpFile, std::string help);

#endif /* !YY_COMMAND_COMMAND_PARSER_HPP_INCLUDED  */
