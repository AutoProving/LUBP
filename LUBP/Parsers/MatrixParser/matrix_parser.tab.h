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

#ifndef YY_MATRIX_MATRIX_PARSER_TAB_H_INCLUDED
# define YY_MATRIX_MATRIX_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef MATRIX_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define MATRIX_DEBUG 1
#  else
#   define MATRIX_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define MATRIX_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined MATRIX_DEBUG */
#if MATRIX_DEBUG
extern int matrix_debug;
#endif
/* "%code requires" blocks.  */
#line 5 "matrix_parser.y"

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

#line 73 "matrix_parser.tab.h"

/* Token type.  */
#ifndef MATRIX_TOKENTYPE
# define MATRIX_TOKENTYPE
  enum matrix_tokentype
  {
    MATRIX_NEWLINE = 258,
    MATRIX_WORD = 259,
    MATRIX_LEFT_PARENTHESIS = 260,
    MATRIX_DOUBLE = 261,
    MATRIX_COMMA = 262,
    MATRIX_RIGHT_PARENTHESIS = 263
  };
#endif

/* Value type.  */
#if ! defined MATRIX_STYPE && ! defined MATRIX_STYPE_IS_DECLARED
union MATRIX_STYPE
{
#line 45 "matrix_parser.y"

     double number;
     char* string;
     vector<std::complex<double> >* vec;
     matrix<std::complex<double>>* mat;
     std::complex<double>* complexnum;

#line 101 "matrix_parser.tab.h"

};
typedef union MATRIX_STYPE MATRIX_STYPE;
# define MATRIX_STYPE_IS_TRIVIAL 1
# define MATRIX_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined MATRIX_LTYPE && ! defined MATRIX_LTYPE_IS_DECLARED
typedef struct MATRIX_LTYPE MATRIX_LTYPE;
struct MATRIX_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define MATRIX_LTYPE_IS_DECLARED 1
# define MATRIX_LTYPE_IS_TRIVIAL 1
#endif


extern MATRIX_STYPE matrix_lval;
extern MATRIX_LTYPE matrix_lloc;
int matrix_parse (int &matdim, vector<matrix<std::complex<double>>> &instructions);

#endif /* !YY_MATRIX_MATRIX_PARSER_TAB_H_INCLUDED  */
