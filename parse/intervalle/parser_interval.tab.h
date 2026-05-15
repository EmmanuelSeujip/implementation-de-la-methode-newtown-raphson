/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_INTERVAL_PARSE_INTERVALLE_PARSER_INTERVAL_TAB_H_INCLUDED
# define YY_INTERVAL_PARSE_INTERVALLE_PARSER_INTERVAL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef INTERVAL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define INTERVAL_DEBUG 1
#  else
#   define INTERVAL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define INTERVAL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined INTERVAL_DEBUG */
#if INTERVAL_DEBUG
extern int interval_debug;
#endif

/* Token kinds.  */
#ifndef INTERVAL_TOKENTYPE
# define INTERVAL_TOKENTYPE
  enum interval_tokentype
  {
    INTERVAL_EMPTY = -2,
    INTERVAL_EOF = 0,              /* "end of file"  */
    INTERVAL_error = 256,          /* error  */
    INTERVAL_UNDEF = 257,          /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    OPEN = 259,                    /* OPEN  */
    CLOSE = 260,                   /* CLOSE  */
    COMA = 261,                    /* COMA  */
    MINUS = 262                    /* MINUS  */
  };
  typedef enum interval_tokentype interval_token_kind_t;
#endif

/* Value type.  */
#if ! defined INTERVAL_STYPE && ! defined INTERVAL_STYPE_IS_DECLARED
union INTERVAL_STYPE
{
#line 22 "parse/intervalle/parser_interval.y"

    double doubleval;

#line 83 "parse/intervalle/parser_interval.tab.h"

};
typedef union INTERVAL_STYPE INTERVAL_STYPE;
# define INTERVAL_STYPE_IS_TRIVIAL 1
# define INTERVAL_STYPE_IS_DECLARED 1
#endif


extern INTERVAL_STYPE interval_lval;


int interval_parse (void);


#endif /* !YY_INTERVAL_PARSE_INTERVALLE_PARSER_INTERVAL_TAB_H_INCLUDED  */
