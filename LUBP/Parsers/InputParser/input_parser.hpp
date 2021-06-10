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

#ifndef YY_INPUT_INPUT_PARSER_HPP_INCLUDED
# define YY_INPUT_INPUT_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef INPUT_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define INPUT_DEBUG 1
#  else
#   define INPUT_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define INPUT_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined INPUT_DEBUG */
#if INPUT_DEBUG
extern int input_debug;
#endif
/* "%code requires" blocks.  */
#line 5 "input_parser.y"

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

#line 73 "input_parser.hpp"

/* Token type.  */
#ifndef INPUT_TOKENTYPE
# define INPUT_TOKENTYPE
  enum input_tokentype
  {
    INPUT_INT = 258,
    INPUT_NEWLINE = 259,
    INPUT_DASH = 260
  };
#endif

/* Value type.  */
#if ! defined INPUT_STYPE && ! defined INPUT_STYPE_IS_DECLARED
union INPUT_STYPE
{
#line 45 "input_parser.y"

     int number;
     char* string;
     vector<int>* vec;

#line 96 "input_parser.hpp"

};
typedef union INPUT_STYPE INPUT_STYPE;
# define INPUT_STYPE_IS_TRIVIAL 1
# define INPUT_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined INPUT_LTYPE && ! defined INPUT_LTYPE_IS_DECLARED
typedef struct INPUT_LTYPE INPUT_LTYPE;
struct INPUT_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define INPUT_LTYPE_IS_DECLARED 1
# define INPUT_LTYPE_IS_TRIVIAL 1
#endif


extern INPUT_STYPE input_lval;
extern INPUT_LTYPE input_lloc;
int input_parse (int &l, int &s, int &c, vector<matrix<int>> &M);

#endif /* !YY_INPUT_INPUT_PARSER_HPP_INCLUDED  */
