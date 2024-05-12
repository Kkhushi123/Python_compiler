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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NEWLINE = 258,                 /* NEWLINE  */
    DEF = 259,                     /* DEF  */
    ARROW = 260,                   /* ARROW  */
    COLON = 261,                   /* COLON  */
    LEFTPARANTHESIS = 262,         /* LEFTPARANTHESIS  */
    RIGHTPARANTHESIS = 263,        /* RIGHTPARANTHESIS  */
    ASSIGNMENTOP = 264,            /* ASSIGNMENTOP  */
    COMMA = 265,                   /* COMMA  */
    SEMICOLON = 266,               /* SEMICOLON  */
    PLUSEQUAL = 267,               /* PLUSEQUAL  */
    MINUSEQUAL = 268,              /* MINUSEQUAL  */
    MULEQUAL = 269,                /* MULEQUAL  */
    FLOATDIVEQUAL = 270,           /* FLOATDIVEQUAL  */
    ANDEQUAL = 271,                /* ANDEQUAL  */
    OREQUAL = 272,                 /* OREQUAL  */
    XOREQUAL = 273,                /* XOREQUAL  */
    MODEQUAL = 274,                /* MODEQUAL  */
    LSHIFTEQUAL = 275,             /* LSHIFTEQUAL  */
    RSHIFTEQUAL = 276,             /* RSHIFTEQUAL  */
    POWEQUAL = 277,                /* POWEQUAL  */
    FLOORDIVEQUAL = 278,           /* FLOORDIVEQUAL  */
    PASS = 279,                    /* PASS  */
    BREAK = 280,                   /* BREAK  */
    CONTINUE = 281,                /* CONTINUE  */
    RETURN = 282,                  /* RETURN  */
    RAISE = 283,                   /* RAISE  */
    GLOBAL = 284,                  /* GLOBAL  */
    NONLOCAL = 285,                /* NONLOCAL  */
    ASSERT = 286,                  /* ASSERT  */
    FROM = 287,                    /* FROM  */
    IF = 288,                      /* IF  */
    ELIF = 289,                    /* ELIF  */
    ELSE = 290,                    /* ELSE  */
    WHILE = 291,                   /* WHILE  */
    FOR = 292,                     /* FOR  */
    IN = 293,                      /* IN  */
    LOGICOR = 294,                 /* LOGICOR  */
    LOGICAND = 295,                /* LOGICAND  */
    LOGICNOT = 296,                /* LOGICNOT  */
    LESSTHAN = 297,                /* LESSTHAN  */
    GREATERTHAN = 298,             /* GREATERTHAN  */
    ISEQUAL = 299,                 /* ISEQUAL  */
    LESSTHANEQUALTO = 300,         /* LESSTHANEQUALTO  */
    GREATERTHANEQUALTO = 301,      /* GREATERTHANEQUALTO  */
    LESSGREAT = 302,               /* LESSGREAT  */
    NOTEQUAL = 303,                /* NOTEQUAL  */
    NOTIN = 304,                   /* NOTIN  */
    IS = 305,                      /* IS  */
    ISNOT = 306,                   /* ISNOT  */
    ONESTAR = 307,                 /* ONESTAR  */
    TWOSTAR = 308,                 /* TWOSTAR  */
    BITWISEOR = 309,               /* BITWISEOR  */
    BITWISEAND = 310,              /* BITWISEAND  */
    BITWISENOT = 311,              /* BITWISENOT  */
    BITWISEXOR = 312,              /* BITWISEXOR  */
    LSHIFT = 313,                  /* LSHIFT  */
    RSHIFT = 314,                  /* RSHIFT  */
    ADD = 315,                     /* ADD  */
    SUBTRACT = 316,                /* SUBTRACT  */
    DIVIDE = 317,                  /* DIVIDE  */
    MODULO = 318,                  /* MODULO  */
    FLOORDIV = 319,                /* FLOORDIV  */
    LSQUAREBRACKET = 320,          /* LSQUAREBRACKET  */
    RSQUAREBRACKET = 321,          /* RSQUAREBRACKET  */
    LCURLYBRACE = 322,             /* LCURLYBRACE  */
    RCURLYBRACE = 323,             /* RCURLYBRACE  */
    NONE = 324,                    /* NONE  */
    TRUE = 325,                    /* TRUE  */
    FALSE = 326,                   /* FALSE  */
    DOT = 327,                     /* DOT  */
    CLASS = 328,                   /* CLASS  */
    NAME = 329,                    /* NAME  */
    NUMBER = 330,                  /* NUMBER  */
    STRING = 331,                  /* STRING  */
    INDENT = 332,                  /* INDENT  */
    DEDENT = 333,                  /* DEDENT  */
    ENDMARKER = 334                /* ENDMARKER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "parser.y"

  struct {
    int n;
    char str[1000];
  } lab;


#line 151 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
