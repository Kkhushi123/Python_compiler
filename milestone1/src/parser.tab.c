/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include <string.h>
    //#include <cstring>
    //#include <bits/stdc++.h>
    //#include <fstream>
    #include "parser.tab.h"
    #include "lex.yy.c"
    
    //using namespace std;
    void yyerror(const char * s);
    int yylex();
    extern int yylineno;
    extern FILE* yyin;
    #define YYERROR_VERBOSE 1
    //int nodes = 0;
    //map<int, string> node_names;
    //vector<pair<int,string>> parents, child;
    //string s;


#line 94 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NEWLINE = 3,                    /* NEWLINE  */
  YYSYMBOL_DEF = 4,                        /* DEF  */
  YYSYMBOL_ARROW = 5,                      /* ARROW  */
  YYSYMBOL_COLON = 6,                      /* COLON  */
  YYSYMBOL_LEFTPARANTHESIS = 7,            /* LEFTPARANTHESIS  */
  YYSYMBOL_RIGHTPARANTHESIS = 8,           /* RIGHTPARANTHESIS  */
  YYSYMBOL_ASSIGNMENTOP = 9,               /* ASSIGNMENTOP  */
  YYSYMBOL_COMMA = 10,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 11,                 /* SEMICOLON  */
  YYSYMBOL_PLUSEQUAL = 12,                 /* PLUSEQUAL  */
  YYSYMBOL_MINUSEQUAL = 13,                /* MINUSEQUAL  */
  YYSYMBOL_MULEQUAL = 14,                  /* MULEQUAL  */
  YYSYMBOL_FLOATDIVEQUAL = 15,             /* FLOATDIVEQUAL  */
  YYSYMBOL_ANDEQUAL = 16,                  /* ANDEQUAL  */
  YYSYMBOL_OREQUAL = 17,                   /* OREQUAL  */
  YYSYMBOL_XOREQUAL = 18,                  /* XOREQUAL  */
  YYSYMBOL_MODEQUAL = 19,                  /* MODEQUAL  */
  YYSYMBOL_LSHIFTEQUAL = 20,               /* LSHIFTEQUAL  */
  YYSYMBOL_RSHIFTEQUAL = 21,               /* RSHIFTEQUAL  */
  YYSYMBOL_POWEQUAL = 22,                  /* POWEQUAL  */
  YYSYMBOL_FLOORDIVEQUAL = 23,             /* FLOORDIVEQUAL  */
  YYSYMBOL_PASS = 24,                      /* PASS  */
  YYSYMBOL_BREAK = 25,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 26,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 27,                    /* RETURN  */
  YYSYMBOL_RAISE = 28,                     /* RAISE  */
  YYSYMBOL_GLOBAL = 29,                    /* GLOBAL  */
  YYSYMBOL_NONLOCAL = 30,                  /* NONLOCAL  */
  YYSYMBOL_ASSERT = 31,                    /* ASSERT  */
  YYSYMBOL_FROM = 32,                      /* FROM  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_ELIF = 34,                      /* ELIF  */
  YYSYMBOL_ELSE = 35,                      /* ELSE  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_FOR = 37,                       /* FOR  */
  YYSYMBOL_IN = 38,                        /* IN  */
  YYSYMBOL_LOGICOR = 39,                   /* LOGICOR  */
  YYSYMBOL_LOGICAND = 40,                  /* LOGICAND  */
  YYSYMBOL_LOGICNOT = 41,                  /* LOGICNOT  */
  YYSYMBOL_LESSTHAN = 42,                  /* LESSTHAN  */
  YYSYMBOL_GREATERTHAN = 43,               /* GREATERTHAN  */
  YYSYMBOL_ISEQUAL = 44,                   /* ISEQUAL  */
  YYSYMBOL_LESSTHANEQUALTO = 45,           /* LESSTHANEQUALTO  */
  YYSYMBOL_GREATERTHANEQUALTO = 46,        /* GREATERTHANEQUALTO  */
  YYSYMBOL_LESSGREAT = 47,                 /* LESSGREAT  */
  YYSYMBOL_NOTEQUAL = 48,                  /* NOTEQUAL  */
  YYSYMBOL_NOTIN = 49,                     /* NOTIN  */
  YYSYMBOL_IS = 50,                        /* IS  */
  YYSYMBOL_ISNOT = 51,                     /* ISNOT  */
  YYSYMBOL_ONESTAR = 52,                   /* ONESTAR  */
  YYSYMBOL_TWOSTAR = 53,                   /* TWOSTAR  */
  YYSYMBOL_BITWISEOR = 54,                 /* BITWISEOR  */
  YYSYMBOL_BITWISEAND = 55,                /* BITWISEAND  */
  YYSYMBOL_BITWISENOT = 56,                /* BITWISENOT  */
  YYSYMBOL_BITWISEXOR = 57,                /* BITWISEXOR  */
  YYSYMBOL_LSHIFT = 58,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 59,                    /* RSHIFT  */
  YYSYMBOL_ADD = 60,                       /* ADD  */
  YYSYMBOL_SUBTRACT = 61,                  /* SUBTRACT  */
  YYSYMBOL_DIVIDE = 62,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 63,                    /* MODULO  */
  YYSYMBOL_FLOORDIV = 64,                  /* FLOORDIV  */
  YYSYMBOL_LSQUAREBRACKET = 65,            /* LSQUAREBRACKET  */
  YYSYMBOL_RSQUAREBRACKET = 66,            /* RSQUAREBRACKET  */
  YYSYMBOL_LCURLYBRACE = 67,               /* LCURLYBRACE  */
  YYSYMBOL_RCURLYBRACE = 68,               /* RCURLYBRACE  */
  YYSYMBOL_NONE = 69,                      /* NONE  */
  YYSYMBOL_TRUE = 70,                      /* TRUE  */
  YYSYMBOL_FALSE = 71,                     /* FALSE  */
  YYSYMBOL_DOT = 72,                       /* DOT  */
  YYSYMBOL_CLASS = 73,                     /* CLASS  */
  YYSYMBOL_NAME = 74,                      /* NAME  */
  YYSYMBOL_NUMBER = 75,                    /* NUMBER  */
  YYSYMBOL_STRING = 76,                    /* STRING  */
  YYSYMBOL_INDENT = 77,                    /* INDENT  */
  YYSYMBOL_DEDENT = 78,                    /* DEDENT  */
  YYSYMBOL_ENDMARKER = 79,                 /* ENDMARKER  */
  YYSYMBOL_YYACCEPT = 80,                  /* $accept  */
  YYSYMBOL_start = 81,                     /* start  */
  YYSYMBOL_single_input = 82,              /* single_input  */
  YYSYMBOL_file_input = 83,                /* file_input  */
  YYSYMBOL_newlinestmt = 84,               /* newlinestmt  */
  YYSYMBOL_eval_input = 85,                /* eval_input  */
  YYSYMBOL_newstar = 86,                   /* newstar  */
  YYSYMBOL_funcdef = 87,                   /* funcdef  */
  YYSYMBOL_88_1 = 88,                      /* $@1  */
  YYSYMBOL_89_2 = 89,                      /* $@2  */
  YYSYMBOL_90_3 = 90,                      /* $@3  */
  YYSYMBOL_91_4 = 91,                      /* $@4  */
  YYSYMBOL_arrowtest = 92,                 /* arrowtest  */
  YYSYMBOL_parameters = 93,                /* parameters  */
  YYSYMBOL_typedright = 94,                /* typedright  */
  YYSYMBOL_typedargslist = 95,             /* typedargslist  */
  YYSYMBOL_commoptep = 96,                 /* commoptep  */
  YYSYMBOL_commepcomma = 97,               /* commepcomma  */
  YYSYMBOL_optional_commtfp_or_twotfp = 98, /* optional_commtfp_or_twotfp  */
  YYSYMBOL_oneoptcomm = 99,                /* oneoptcomm  */
  YYSYMBOL_commtfp_or_twotfp = 100,        /* commtfp_or_twotfp  */
  YYSYMBOL_commtfpdefeqtest = 101,         /* commtfpdefeqtest  */
  YYSYMBOL_tfoptcomm = 102,                /* tfoptcomm  */
  YYSYMBOL_commtwotfpcomma = 103,          /* commtwotfpcomma  */
  YYSYMBOL_twotfpdefcomma = 104,           /* twotfpdefcomma  */
  YYSYMBOL_optionaltfpdef = 105,           /* optionaltfpdef  */
  YYSYMBOL_tfpdef = 106,                   /* tfpdef  */
  YYSYMBOL_optionaleqtest = 107,           /* optionaleqtest  */
  YYSYMBOL_colontest = 108,                /* colontest  */
  YYSYMBOL_stmt = 109,                     /* stmt  */
  YYSYMBOL_simple_stmt = 110,              /* simple_stmt  */
  YYSYMBOL_colsmall_stmt = 111,            /* colsmall_stmt  */
  YYSYMBOL_small_stmt = 112,               /* small_stmt  */
  YYSYMBOL_expr_stmt = 113,                /* expr_stmt  */
  YYSYMBOL_anaugassigneqtest = 114,        /* anaugassigneqtest  */
  YYSYMBOL_equalteststarexp = 115,         /* equalteststarexp  */
  YYSYMBOL_annassign = 116,                /* annassign  */
  YYSYMBOL_assignoptest = 117,             /* assignoptest  */
  YYSYMBOL_testlist_star_expr = 118,       /* testlist_star_expr  */
  YYSYMBOL_comm_teststar = 119,            /* comm_teststar  */
  YYSYMBOL_teststar = 120,                 /* teststar  */
  YYSYMBOL_augassign = 121,                /* augassign  */
  YYSYMBOL_pass_stmt = 122,                /* pass_stmt  */
  YYSYMBOL_flow_stmt = 123,                /* flow_stmt  */
  YYSYMBOL_break_stmt = 124,               /* break_stmt  */
  YYSYMBOL_continue_stmt = 125,            /* continue_stmt  */
  YYSYMBOL_return_stmt = 126,              /* return_stmt  */
  YYSYMBOL_raise_stmt = 127,               /* raise_stmt  */
  YYSYMBOL_fromtest = 128,                 /* fromtest  */
  YYSYMBOL_testfromtest = 129,             /* testfromtest  */
  YYSYMBOL_global_stmt = 130,              /* global_stmt  */
  YYSYMBOL_nonlocal_stmt = 131,            /* nonlocal_stmt  */
  YYSYMBOL_assert_stmt = 132,              /* assert_stmt  */
  YYSYMBOL_compound_stmt = 133,            /* compound_stmt  */
  YYSYMBOL_if_stmt = 134,                  /* if_stmt  */
  YYSYMBOL_eliftestsuite = 135,            /* eliftestsuite  */
  YYSYMBOL_while_stmt = 136,               /* while_stmt  */
  YYSYMBOL_for_stmt = 137,                 /* for_stmt  */
  YYSYMBOL_138_5 = 138,                    /* $@5  */
  YYSYMBOL_suite = 139,                    /* suite  */
  YYSYMBOL_140_6 = 140,                    /* $@6  */
  YYSYMBOL_oneormore_stmt = 141,           /* oneormore_stmt  */
  YYSYMBOL_test = 142,                     /* test  */
  YYSYMBOL_if_orelsetest = 143,            /* if_orelsetest  */
  YYSYMBOL_test_nocond = 144,              /* test_nocond  */
  YYSYMBOL_or_test = 145,                  /* or_test  */
  YYSYMBOL_orandtest = 146,                /* orandtest  */
  YYSYMBOL_and_test = 147,                 /* and_test  */
  YYSYMBOL_andnottest = 148,               /* andnottest  */
  YYSYMBOL_not_test = 149,                 /* not_test  */
  YYSYMBOL_comparison = 150,               /* comparison  */
  YYSYMBOL_compexpr = 151,                 /* compexpr  */
  YYSYMBOL_comp_op = 152,                  /* comp_op  */
  YYSYMBOL_star_expr = 153,                /* star_expr  */
  YYSYMBOL_expr = 154,                     /* expr  */
  YYSYMBOL_bitxorexpr = 155,               /* bitxorexpr  */
  YYSYMBOL_xor_expr = 156,                 /* xor_expr  */
  YYSYMBOL_bitandexpr = 157,               /* bitandexpr  */
  YYSYMBOL_and_expr = 158,                 /* and_expr  */
  YYSYMBOL_bitshiftexpr = 159,             /* bitshiftexpr  */
  YYSYMBOL_shift_expr = 160,               /* shift_expr  */
  YYSYMBOL_lrarithexpr = 161,              /* lrarithexpr  */
  YYSYMBOL_lrshift = 162,                  /* lrshift  */
  YYSYMBOL_arith_expr = 163,               /* arith_expr  */
  YYSYMBOL_addsub_term = 164,              /* addsub_term  */
  YYSYMBOL_addsub = 165,                   /* addsub  */
  YYSYMBOL_term = 166,                     /* term  */
  YYSYMBOL_primopfactor = 167,             /* primopfactor  */
  YYSYMBOL_primopr = 168,                  /* primopr  */
  YYSYMBOL_factor = 169,                   /* factor  */
  YYSYMBOL_unaryop = 170,                  /* unaryop  */
  YYSYMBOL_power = 171,                    /* power  */
  YYSYMBOL_twostarfac = 172,               /* twostarfac  */
  YYSYMBOL_atom_expr = 173,                /* atom_expr  */
  YYSYMBOL_zeromoretrail = 174,            /* zeromoretrail  */
  YYSYMBOL_atom = 175,                     /* atom  */
  YYSYMBOL_onemorestring = 176,            /* onemorestring  */
  YYSYMBOL_testlist_comp = 177,            /* testlist_comp  */
  YYSYMBOL_trailer = 178,                  /* trailer  */
  YYSYMBOL_subscriptlist = 179,            /* subscriptlist  */
  YYSYMBOL_commsubscript = 180,            /* commsubscript  */
  YYSYMBOL_subscript = 181,                /* subscript  */
  YYSYMBOL_sliceop = 182,                  /* sliceop  */
  YYSYMBOL_exprlist = 183,                 /* exprlist  */
  YYSYMBOL_exprorstar_expr = 184,          /* exprorstar_expr  */
  YYSYMBOL_commexprorstar = 185,           /* commexprorstar  */
  YYSYMBOL_testlist = 186,                 /* testlist  */
  YYSYMBOL_zeromorecommtest = 187,         /* zeromorecommtest  */
  YYSYMBOL_dictorsetmaker = 188,           /* dictorsetmaker  */
  YYSYMBOL_comp_comtest = 189,             /* comp_comtest  */
  YYSYMBOL_commtestcoltwostar = 190,       /* commtestcoltwostar  */
  YYSYMBOL_testcolonortwostar = 191,       /* testcolonortwostar  */
  YYSYMBOL_comteststar = 192,              /* comteststar  */
  YYSYMBOL_testorstar = 193,               /* testorstar  */
  YYSYMBOL_classdef = 194,                 /* classdef  */
  YYSYMBOL_optionalleftargright = 195,     /* optionalleftargright  */
  YYSYMBOL_leftopargright = 196,           /* leftopargright  */
  YYSYMBOL_arglist = 197,                  /* arglist  */
  YYSYMBOL_commarg = 198,                  /* commarg  */
  YYSYMBOL_argument = 199,                 /* argument  */
  YYSYMBOL_comp_for = 200,                 /* comp_for  */
  YYSYMBOL_comp_if = 201,                  /* comp_if  */
  YYSYMBOL_optionalcolon = 202,            /* optionalcolon  */
  YYSYMBOL_optionalcomma = 203,            /* optionalcomma  */
  YYSYMBOL_optionaltestlist = 204,         /* optionaltestlist  */
  YYSYMBOL_commaname = 205,                /* commaname  */
  YYSYMBOL_commatest = 206,                /* commatest  */
  YYSYMBOL_elsesuite = 207,                /* elsesuite  */
  YYSYMBOL_optionaltest_comp = 208,        /* optionaltest_comp  */
  YYSYMBOL_optionaldictor_maker = 209,     /* optionaldictor_maker  */
  YYSYMBOL_optionaltest = 210,             /* optionaltest  */
  YYSYMBOL_optionalsliceop = 211,          /* optionalsliceop  */
  YYSYMBOL_optionalarglist = 212           /* optionalarglist  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  110
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   698

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  133
/* YYNRULES -- Number of rules.  */
#define YYNRULES  266
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  396

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   334


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   115,   115,   116,   117,   120,   121,   122,   126,   130,
     131,   132,   136,   140,   141,   146,   146,   146,   146,   146,
     149,   150,   154,   157,   158,   161,   162,   163,   167,   168,
     172,   173,   174,   178,   179,   182,   186,   187,   191,   192,
     195,   199,   200,   204,   205,   209,   210,   214,   218,   219,
     223,   224,   228,   229,   233,   237,   238,   242,   243,   244,
     245,   246,   247,   253,   256,   257,   258,   262,   263,   267,
     271,   272,   276,   280,   281,   285,   286,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   305,
     309,   310,   311,   312,   316,   320,   324,   328,   331,   332,
     336,   337,   341,   345,   348,   352,   353,   354,   355,   356,
     359,   363,   364,   368,   372,   372,   376,   377,   377,   381,
     382,   386,   390,   391,   395,   399,   403,   404,   408,   412,
     413,   416,   417,   420,   424,   425,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   444,   448,   452,
     453,   457,   461,   462,   466,   470,   471,   474,   478,   479,
     483,   484,   488,   492,   493,   497,   498,   502,   506,   507,
     511,   512,   513,   514,   518,   519,   522,   523,   524,   528,
     532,   533,   537,   541,   542,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   558,   559,   563,   567,   568,   569,
     573,   577,   578,   582,   583,   587,   591,   595,   596,   600,
     601,   605,   609,   610,   614,   615,   616,   620,   621,   625,
     626,   630,   631,   635,   636,   640,   641,   645,   649,   650,
     654,   658,   662,   663,   667,   668,   669,   670,   671,   675,
     676,   677,   681,   682,   683,   693,   694,   698,   699,   703,
     704,   708,   709,   713,   714,   718,   719,   723,   724,   728,
     729,   733,   734,   738,   739,   743,   744
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NEWLINE", "DEF",
  "ARROW", "COLON", "LEFTPARANTHESIS", "RIGHTPARANTHESIS", "ASSIGNMENTOP",
  "COMMA", "SEMICOLON", "PLUSEQUAL", "MINUSEQUAL", "MULEQUAL",
  "FLOATDIVEQUAL", "ANDEQUAL", "OREQUAL", "XOREQUAL", "MODEQUAL",
  "LSHIFTEQUAL", "RSHIFTEQUAL", "POWEQUAL", "FLOORDIVEQUAL", "PASS",
  "BREAK", "CONTINUE", "RETURN", "RAISE", "GLOBAL", "NONLOCAL", "ASSERT",
  "FROM", "IF", "ELIF", "ELSE", "WHILE", "FOR", "IN", "LOGICOR",
  "LOGICAND", "LOGICNOT", "LESSTHAN", "GREATERTHAN", "ISEQUAL",
  "LESSTHANEQUALTO", "GREATERTHANEQUALTO", "LESSGREAT", "NOTEQUAL",
  "NOTIN", "IS", "ISNOT", "ONESTAR", "TWOSTAR", "BITWISEOR", "BITWISEAND",
  "BITWISENOT", "BITWISEXOR", "LSHIFT", "RSHIFT", "ADD", "SUBTRACT",
  "DIVIDE", "MODULO", "FLOORDIV", "LSQUAREBRACKET", "RSQUAREBRACKET",
  "LCURLYBRACE", "RCURLYBRACE", "NONE", "TRUE", "FALSE", "DOT", "CLASS",
  "NAME", "NUMBER", "STRING", "INDENT", "DEDENT", "ENDMARKER", "$accept",
  "start", "single_input", "file_input", "newlinestmt", "eval_input",
  "newstar", "funcdef", "$@1", "$@2", "$@3", "$@4", "arrowtest",
  "parameters", "typedright", "typedargslist", "commoptep", "commepcomma",
  "optional_commtfp_or_twotfp", "oneoptcomm", "commtfp_or_twotfp",
  "commtfpdefeqtest", "tfoptcomm", "commtwotfpcomma", "twotfpdefcomma",
  "optionaltfpdef", "tfpdef", "optionaleqtest", "colontest", "stmt",
  "simple_stmt", "colsmall_stmt", "small_stmt", "expr_stmt",
  "anaugassigneqtest", "equalteststarexp", "annassign", "assignoptest",
  "testlist_star_expr", "comm_teststar", "teststar", "augassign",
  "pass_stmt", "flow_stmt", "break_stmt", "continue_stmt", "return_stmt",
  "raise_stmt", "fromtest", "testfromtest", "global_stmt", "nonlocal_stmt",
  "assert_stmt", "compound_stmt", "if_stmt", "eliftestsuite", "while_stmt",
  "for_stmt", "$@5", "suite", "$@6", "oneormore_stmt", "test",
  "if_orelsetest", "test_nocond", "or_test", "orandtest", "and_test",
  "andnottest", "not_test", "comparison", "compexpr", "comp_op",
  "star_expr", "expr", "bitxorexpr", "xor_expr", "bitandexpr", "and_expr",
  "bitshiftexpr", "shift_expr", "lrarithexpr", "lrshift", "arith_expr",
  "addsub_term", "addsub", "term", "primopfactor", "primopr", "factor",
  "unaryop", "power", "twostarfac", "atom_expr", "zeromoretrail", "atom",
  "onemorestring", "testlist_comp", "trailer", "subscriptlist",
  "commsubscript", "subscript", "sliceop", "exprlist", "exprorstar_expr",
  "commexprorstar", "testlist", "zeromorecommtest", "dictorsetmaker",
  "comp_comtest", "commtestcoltwostar", "testcolonortwostar",
  "comteststar", "testorstar", "classdef", "optionalleftargright",
  "leftopargright", "arglist", "commarg", "argument", "comp_for",
  "comp_if", "optionalcolon", "optionalcomma", "optionaltestlist",
  "commaname", "commatest", "elsesuite", "optionaltest_comp",
  "optionaldictor_maker", "optionaltest", "optionalsliceop",
  "optionalarglist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-292)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-262)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     358,   299,   -39,    79,  -292,  -292,  -292,   565,   565,   -30,
     -26,   565,   565,   565,   590,   565,   337,  -292,  -292,  -292,
      79,   493,  -292,  -292,  -292,   -24,  -292,  -292,   -22,    55,
    -292,  -292,   -19,  -292,  -292,   413,    65,    68,  -292,   661,
      66,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
      74,  -292,  -292,  -292,     9,    46,    43,    51,  -292,  -292,
     647,    39,    38,    44,   -16,   -14,   -11,   337,  -292,    47,
      24,  -292,    94,  -292,   413,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,    26,    93,    95,  -292,  -292,  -292,    76,
     100,   100,    95,   108,   113,  -292,  -292,  -292,   111,  -292,
    -292,    56,   337,   117,  -292,  -292,    27,    57,   121,  -292,
    -292,  -292,  -292,   201,   118,   565,    79,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,   565,    79,   120,  -292,   565,   120,    95,   565,
    -292,   565,  -292,   565,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,   337,   337,  -292,
     337,  -292,   337,  -292,  -292,  -292,  -292,   337,  -292,  -292,
    -292,   337,  -292,  -292,  -292,  -292,  -292,   337,  -292,   337,
    -292,   518,   565,    59,  -292,    24,  -292,    94,    62,   127,
      79,   590,  -292,   120,  -292,  -292,   565,  -292,    69,  -292,
    -292,  -292,    42,    42,   104,   590,   120,  -292,  -292,   565,
     543,   120,  -292,  -292,   139,  -292,    68,  -292,   144,   142,
     143,  -292,    66,  -292,  -292,  -292,  -292,  -292,   122,    43,
      51,   647,    39,    38,    44,   -16,   -14,   -11,  -292,   565,
     565,    19,  -292,   146,   150,   154,    97,   151,   158,  -292,
    -292,  -292,  -292,    32,  -292,   155,   129,  -292,  -292,   100,
      91,  -292,   135,   138,   565,   111,  -292,  -292,   117,   160,
    -292,    42,  -292,  -292,   565,  -292,  -292,  -292,   565,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
     565,  -292,   518,   120,  -292,  -292,   565,   120,   565,  -292,
     101,   101,   168,  -292,   170,   166,   169,   171,   178,  -292,
     565,  -292,   468,   565,   138,   180,  -292,   181,  -292,  -292,
    -292,  -292,  -292,  -292,   146,  -292,   151,  -292,  -292,   182,
     174,  -292,   120,   565,  -292,  -292,   136,  -292,  -292,     6,
    -292,   565,   174,   565,  -292,     1,   468,  -292,   185,  -292,
      42,    42,  -292,  -292,   565,  -292,  -292,   101,  -292,  -292,
    -292,   101,  -292,  -292,   184,  -292,  -292,  -292,  -292,  -292,
     186,   565,  -292,  -292,  -292,   126,    42,  -292,   138,  -292,
    -292,   120,   136,  -292,  -292,     1,  -292,  -292,   135,  -292,
    -292,    42,  -292,  -292,  -292,  -292
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      11,     5,     0,   258,    89,    94,    95,   250,   101,     0,
       0,     0,     0,     0,     0,     0,     0,   178,   176,   177,
     258,   260,   191,   192,   193,     0,   188,   189,   195,     0,
       2,     3,     0,     4,   108,    11,    52,    56,    57,    68,
      74,    58,    59,    90,    91,    92,    93,    60,    61,    62,
      53,   105,   106,   107,    75,   123,   127,   130,   132,    76,
     135,   150,   153,   156,   159,   164,   169,     0,   175,   181,
     184,   190,    14,   109,    11,     9,    52,    53,    75,    15,
     225,   226,   257,   224,     0,   213,   249,    96,    97,    99,
     252,   252,   254,     0,     0,   208,   207,   114,   210,   131,
     147,     0,     0,   225,   216,   259,   220,     0,   229,   194,
       1,     8,    10,     0,   246,     0,     0,    77,    78,    79,
      80,    82,    83,    84,    81,    85,    86,    87,    88,    63,
      66,    64,     0,     0,   248,     7,     0,   248,   213,     0,
     121,     0,   125,     0,   128,   143,   136,   137,   138,   140,
     139,   141,   142,   144,   145,   146,   133,     0,     0,   148,
       0,   151,     0,   154,   160,   161,   157,     0,   165,   166,
     162,     0,   170,   171,   172,   173,   167,     0,   174,     0,
     179,   266,   262,     0,   182,   184,   197,    14,     0,     0,
       0,     0,   196,   248,   217,   185,     0,   100,     0,   102,
     103,   104,     0,     0,     0,     0,   248,   186,   222,     0,
       0,   248,   214,   187,     0,   228,    56,   245,     0,    71,
      68,    65,    74,   247,    72,   253,   211,   212,     0,   127,
     130,   135,   150,   153,   156,   159,   164,   169,   180,     0,
       0,   234,   265,   233,     0,   203,     0,   202,     0,   199,
     183,    13,    12,     0,    16,   224,     0,   218,    98,   252,
       0,   116,   112,   256,     0,   210,   206,   221,     0,   220,
     215,     0,    55,    54,     0,    69,    67,    73,     0,   126,
     129,   134,   149,   152,   155,   158,   163,   168,   238,   237,
       0,   235,     0,   248,   230,   198,   262,   248,   262,    24,
      46,     0,    51,    22,     0,    32,    29,    49,    21,   223,
       0,   251,     0,     0,   256,     0,   113,     0,   209,   219,
     227,    70,   122,   236,   233,   231,   202,   200,   261,   264,
      39,    45,   248,     0,    47,    23,    31,    26,    30,    34,
      25,     0,    39,     0,    17,   241,   120,   117,     0,   110,
       0,     0,   232,   201,   262,   263,   204,     0,    35,    27,
      50,     0,    41,    28,    42,    33,    37,    48,    40,    20,
       0,     0,   239,   240,   119,     0,     0,   255,   256,   205,
      38,   248,    44,    36,    18,   244,   124,   118,   112,   115,
      43,     0,   242,   243,   111,    19
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -292,  -292,  -292,  -292,    22,  -292,     8,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -141,
    -292,  -143,  -157,  -159,  -133,  -292,  -271,  -292,  -292,  -285,
       4,    -3,    98,  -292,  -292,    -4,  -292,  -292,    99,    -8,
      85,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,   219,  -292,  -168,  -292,  -292,  -292,  -179,
    -292,  -124,     0,  -292,  -292,  -125,     5,    80,    -7,    -5,
    -292,     7,  -292,    12,     2,     3,    75,    -9,    77,    10,
      81,    13,  -292,    78,    11,  -292,    83,    -1,  -292,   -50,
    -292,  -292,  -292,  -292,    64,  -292,   223,   231,  -292,  -292,
     -71,   -40,  -292,    72,    54,    14,    -6,   131,  -292,  -292,
      -2,    50,    18,    90,  -292,  -292,   157,  -292,   -42,    15,
    -104,  -102,  -292,  -131,  -292,   -82,   192,  -291,   265,  -292,
    -273,  -292,  -292
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    29,    30,    31,    75,    33,   188,    34,   189,   308,
     370,   391,   344,   254,   303,   304,   340,   337,   363,   305,
     365,   358,   306,   338,   362,   330,   307,   342,   334,    35,
     261,   114,    37,    38,   129,   130,   131,   275,    39,   134,
      40,   132,    41,    42,    43,    44,    45,    46,   197,    88,
      47,    48,    49,    77,    51,   314,    52,    53,   204,   262,
     375,   347,    78,   140,   385,    55,   142,    56,   144,    57,
      58,   156,   157,    59,    60,   159,    61,   161,    62,   163,
      63,   166,   167,    64,   170,   171,    65,   176,   177,    66,
      67,    68,   180,    69,   184,    70,    71,    82,   185,   246,
     297,   247,   355,    97,    98,   206,    72,   137,   105,   192,
     211,   106,   193,    83,    73,   214,   186,   242,   293,   243,
     194,   373,   218,   224,    87,   199,   138,   316,    84,   107,
     248,   356,   244
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    86,   212,    80,    36,    76,   226,    85,    89,   200,
      99,    92,    93,    94,   228,    81,    96,   178,   100,   136,
      80,   103,    32,   349,   263,   329,    95,   346,   290,   331,
     332,   181,    81,    81,   371,    79,   190,   210,   191,    76,
     299,   172,   164,   165,    90,   260,   168,   169,    91,     3,
     108,   173,   174,   175,    28,   110,   191,   112,   300,   361,
     111,   346,   257,   191,   191,    -6,     4,     5,     6,     7,
       8,     9,    10,    11,   113,   266,   133,   135,    76,   139,
     270,   379,   141,    15,   300,   301,     3,   389,  -213,   182,
     381,   143,   320,   158,    16,   160,   183,   187,    17,   162,
     179,   195,    18,    19,   208,   136,   302,    20,   196,    21,
     198,    22,    23,    24,   202,   219,    26,    27,    28,   203,
      15,   205,   207,   209,   217,   213,   221,   237,   181,   238,
     223,    16,    85,   249,   253,    17,   225,   291,   230,    18,
      19,   252,   264,   259,    20,   271,    21,   273,    22,    23,
      24,   274,   116,    26,    27,    28,   292,   278,   294,   231,
    -261,   296,   325,   295,   298,   190,   327,   310,   312,   313,
     210,   377,   378,   315,   333,   302,   336,   311,   335,   339,
     341,   241,   245,   343,   357,   345,   350,   351,   354,   361,
      80,   376,   384,    96,   382,   251,   258,   388,   364,   368,
     380,   359,    81,    95,   387,   383,   366,    96,     3,   267,
     268,   216,   395,   272,   277,   220,   276,    95,   222,    50,
     394,   229,   374,   280,   283,     4,     5,     6,     7,     8,
       9,    10,    11,   232,   279,   282,   287,   233,   281,   288,
     289,   372,    15,   234,   284,   235,   386,   286,   285,   250,
     390,   109,   104,    16,   236,   353,   326,    17,   317,   265,
     269,    18,    19,   256,    85,   215,    20,   319,    21,   227,
      22,    23,    24,   309,   321,    26,    27,    28,   322,   318,
     255,   392,   352,   393,   201,   101,     0,     0,     0,     0,
     323,     0,   241,     0,     0,     0,   245,     0,   328,     0,
       0,     0,    74,     2,     0,     0,     3,   324,     0,     0,
       0,     0,     0,   348,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,   360,     0,    13,    14,     0,     0,     0,
      15,   367,     0,   369,     3,     0,     0,     0,     0,     0,
      76,    16,     0,     0,   328,    17,     0,     0,     0,    18,
      19,     1,     2,     0,    20,     3,    21,     0,    22,    23,
      24,     0,    25,    26,    27,    28,     0,     0,   -11,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
       0,    12,     0,    17,    13,    14,     0,    18,    19,    15,
       0,     0,    20,     0,    21,     0,    22,    23,    24,     0,
      16,    26,    27,    28,    17,     0,    74,     2,    18,    19,
       3,     0,     0,    20,     0,    21,     0,    22,    23,    24,
       0,    25,    26,    27,    28,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,     0,    12,     0,     0,    13,
      14,     0,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,    17,
       0,     0,     2,    18,    19,     3,     0,     0,    20,     0,
      21,     0,    22,    23,    24,     0,    25,    26,    27,    28,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
       3,    12,     0,     0,    13,    14,     0,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,     0,    17,     3,     0,     0,    18,    19,
       0,     0,     0,    20,    15,    21,     0,    22,    23,    24,
       0,    25,    26,    27,    28,    16,   102,     0,     0,    17,
       3,     0,     0,    18,    19,     0,     0,     0,    20,    15,
      21,     0,    22,    23,    24,     0,     0,    26,    27,    28,
     239,   240,     3,     0,    17,     0,     0,     0,    18,    19,
       0,     0,     0,    20,    15,    21,     0,    22,    23,    24,
       0,     0,    26,    27,    28,     0,   102,     3,     0,    17,
       0,     0,     0,    18,    19,     0,    15,     0,    20,     0,
      21,     0,    22,    23,    24,     0,     0,    26,    27,    28,
       0,    17,     0,     0,     0,    18,    19,     0,     0,     0,
      20,     0,    21,     0,    22,    23,    24,     0,     0,    26,
      27,    28,    16,     0,     0,     0,    17,     0,     0,     0,
      18,    19,     0,     0,     0,    20,     0,    21,     0,    22,
      23,    24,     0,     0,    26,    27,    28,   115,     0,     0,
     116,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   145,     0,     0,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155
};

static const yytype_int16 yycheck[] =
{
       0,     7,   106,     3,     0,     1,   137,     7,     8,    91,
      15,    11,    12,    13,   139,     3,    14,    67,    16,    10,
      20,    21,     0,   314,   203,   298,    14,   312,     9,   300,
     301,     7,    20,    21,    33,    74,    10,    10,    37,    35,
       8,    52,    58,    59,    74,     3,    60,    61,    74,     7,
      74,    62,    63,    64,    76,     0,    37,    35,    52,    53,
      79,   346,   193,    37,    37,     0,    24,    25,    26,    27,
      28,    29,    30,    31,     6,   206,    10,     3,    74,    33,
     211,   354,    39,    41,    52,    53,     7,   378,    79,    65,
     361,    40,   271,    54,    52,    57,    72,     3,    56,    55,
      53,     8,    60,    61,   102,    10,    74,    65,    32,    67,
      10,    69,    70,    71,     6,   115,    74,    75,    76,     6,
      41,    10,    66,     6,     6,    68,   132,   177,     7,   179,
      10,    52,   132,    74,     7,    56,   136,   241,   143,    60,
      61,    79,    38,    74,    65,     6,    67,     3,    69,    70,
      71,     9,     9,    74,    75,    76,    10,    35,     8,   157,
       6,    10,   293,    66,     6,    10,   297,    38,    77,    34,
      10,   350,   351,    35,     6,    74,    10,   259,     8,    10,
       9,   181,   182,     5,    10,   310,     6,     6,     6,    53,
     190,     6,     6,   191,    10,   187,   196,   376,   339,   342,
     357,   332,   190,   191,    78,   364,   339,   205,     7,   209,
     210,   113,   391,   216,   222,   116,   220,   205,   133,     0,
     388,   141,   346,   230,   233,    24,    25,    26,    27,    28,
      29,    30,    31,   158,   229,   232,   237,   160,   231,   239,
     240,   345,    41,   162,   234,   167,   371,   236,   235,   185,
     381,    28,    21,    52,   171,   326,   296,    56,   264,   205,
     210,    60,    61,   191,   264,   108,    65,   269,    67,   138,
      69,    70,    71,   255,   274,    74,    75,    76,   278,   265,
     190,   385,   324,   385,    92,    20,    -1,    -1,    -1,    -1,
     290,    -1,   292,    -1,    -1,    -1,   296,    -1,   298,    -1,
      -1,    -1,     3,     4,    -1,    -1,     7,   292,    -1,    -1,
      -1,    -1,    -1,   313,    -1,    -1,   312,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,   333,    -1,    36,    37,    -1,    -1,    -1,
      41,   341,    -1,   343,     7,    -1,    -1,    -1,    -1,    -1,
     346,    52,    -1,    -1,   354,    56,    -1,    -1,    -1,    60,
      61,     3,     4,    -1,    65,     7,    67,    -1,    69,    70,
      71,    -1,    73,    74,    75,    76,    -1,    -1,    79,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    33,    -1,    56,    36,    37,    -1,    60,    61,    41,
      -1,    -1,    65,    -1,    67,    -1,    69,    70,    71,    -1,
      52,    74,    75,    76,    56,    -1,     3,     4,    60,    61,
       7,    -1,    -1,    65,    -1,    67,    -1,    69,    70,    71,
      -1,    73,    74,    75,    76,    -1,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    -1,    -1,    36,
      37,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    56,
      -1,    -1,     4,    60,    61,     7,    -1,    -1,    65,    -1,
      67,    -1,    69,    70,    71,    -1,    73,    74,    75,    76,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
       7,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    56,     7,    -1,    -1,    60,    61,
      -1,    -1,    -1,    65,    41,    67,    -1,    69,    70,    71,
      -1,    73,    74,    75,    76,    52,    53,    -1,    -1,    56,
       7,    -1,    -1,    60,    61,    -1,    -1,    -1,    65,    41,
      67,    -1,    69,    70,    71,    -1,    -1,    74,    75,    76,
      52,    53,     7,    -1,    56,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    65,    41,    67,    -1,    69,    70,    71,
      -1,    -1,    74,    75,    76,    -1,    53,     7,    -1,    56,
      -1,    -1,    -1,    60,    61,    -1,    41,    -1,    65,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    74,    75,    76,
      -1,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      65,    -1,    67,    -1,    69,    70,    71,    -1,    -1,    74,
      75,    76,    52,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    65,    -1,    67,    -1,    69,
      70,    71,    -1,    -1,    74,    75,    76,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    38,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     7,    24,    25,    26,    27,    28,    29,
      30,    31,    33,    36,    37,    41,    52,    56,    60,    61,
      65,    67,    69,    70,    71,    73,    74,    75,    76,    81,
      82,    83,    84,    85,    87,   109,   110,   112,   113,   118,
     120,   122,   123,   124,   125,   126,   127,   130,   131,   132,
     133,   134,   136,   137,   142,   145,   147,   149,   150,   153,
     154,   156,   158,   160,   163,   166,   169,   170,   171,   173,
     175,   176,   186,   194,     3,    84,   110,   133,   142,    74,
     142,   153,   177,   193,   208,   142,   186,   204,   129,   142,
      74,    74,   142,   142,   142,   153,   154,   183,   184,   149,
     154,   208,    53,   142,   177,   188,   191,   209,    74,   176,
       0,    79,    84,     6,   111,     6,     9,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   114,
     115,   116,   121,    10,   119,     3,    10,   187,   206,    33,
     143,    39,   146,    40,   148,    38,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,   151,   152,    54,   155,
      57,   157,    55,   159,    58,    59,   161,   162,    60,    61,
     164,   165,    52,    62,    63,    64,   167,   168,   169,    53,
     172,     7,    65,    72,   174,   178,   196,     3,    86,    88,
      10,    37,   189,   192,   200,     8,    32,   128,    10,   205,
     205,   206,     6,     6,   138,    10,   185,    66,   154,     6,
      10,   190,   200,    68,   195,   196,   112,     6,   202,   142,
     118,   186,   120,    10,   203,   142,   203,   187,   145,   147,
     149,   154,   156,   158,   160,   163,   166,   169,   169,    52,
      53,   142,   197,   199,   212,   142,   179,   181,   210,    74,
     174,    86,    79,     7,    93,   193,   183,   203,   142,    74,
       3,   110,   139,   139,    38,   184,   203,   142,   142,   191,
     203,     6,   111,     3,     9,   117,   115,   119,    35,   146,
     148,   151,   155,   157,   159,   161,   164,   167,   142,   142,
       9,   200,    10,   198,     8,    66,    10,   180,     6,     8,
      52,    53,    74,    94,    95,    99,   102,   106,    89,   192,
      38,   205,    77,    34,   135,    35,   207,   186,   185,   190,
     139,   142,   142,   142,   199,   203,   181,   203,   142,   210,
     105,   106,   106,     6,   108,     8,    10,    97,   103,    10,
      96,     9,   107,     5,    92,   145,   109,   141,   142,   207,
       6,     6,   198,   180,     6,   182,   211,    10,   101,   203,
     142,    53,   104,    98,    99,   100,   104,   142,   101,   142,
      90,    33,   200,   201,   141,   140,     6,   139,   139,   210,
     102,   106,    10,   103,     6,   144,   145,    78,   139,   207,
     203,    91,   200,   201,   135,   139
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    81,    81,    81,    82,    82,    82,    83,    84,
      84,    84,    85,    86,    86,    88,    89,    90,    91,    87,
      92,    92,    93,    94,    94,    95,    95,    95,    96,    96,
      97,    97,    97,    98,    98,    99,   100,   100,   101,   101,
     102,   103,   103,   104,   104,   105,   105,   106,   107,   107,
     108,   108,   109,   109,   110,   111,   111,   112,   112,   112,
     112,   112,   112,   113,   114,   114,   114,   115,   115,   116,
     117,   117,   118,   119,   119,   120,   120,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   122,
     123,   123,   123,   123,   124,   125,   126,   127,   128,   128,
     129,   129,   130,   131,   132,   133,   133,   133,   133,   133,
     134,   135,   135,   136,   138,   137,   139,   140,   139,   141,
     141,   142,   143,   143,   144,   145,   146,   146,   147,   148,
     148,   149,   149,   150,   151,   151,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   153,   154,   155,
     155,   156,   157,   157,   158,   159,   159,   160,   161,   161,
     162,   162,   163,   164,   164,   165,   165,   166,   167,   167,
     168,   168,   168,   168,   169,   169,   170,   170,   170,   171,
     172,   172,   173,   174,   174,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   176,   176,   177,   178,   178,   178,
     179,   180,   180,   181,   181,   182,   183,   184,   184,   185,
     185,   186,   187,   187,   188,   188,   188,   189,   189,   190,
     190,   191,   191,   192,   192,   193,   193,   194,   195,   195,
     196,   197,   198,   198,   199,   199,   199,   199,   199,   200,
     200,   200,   201,   201,   201,   202,   202,   203,   203,   204,
     204,   205,   205,   206,   206,   207,   207,   208,   208,   209,
     209,   210,   210,   211,   211,   212,   212
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     0,     3,     2,     0,     0,     0,     0,     0,    10,
       2,     0,     2,     2,     1,     2,     2,     3,     2,     0,
       1,     1,     0,     1,     0,     3,     2,     1,     2,     0,
       3,     2,     0,     3,     0,     1,     0,     2,     2,     0,
       2,     0,     1,     1,     4,     3,     0,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     3,     0,     3,
       2,     0,     3,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     0,
       2,     0,     3,     3,     3,     1,     1,     1,     1,     1,
       6,     5,     0,     5,     0,     8,     1,     0,     5,     2,
       1,     2,     4,     0,     1,     2,     3,     0,     2,     3,
       0,     2,     1,     2,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       0,     2,     3,     0,     2,     3,     0,     2,     3,     0,
       1,     1,     2,     3,     0,     1,     1,     2,     3,     0,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     2,
       2,     0,     2,     2,     0,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     3,     2,
       3,     3,     0,     1,     4,     2,     3,     1,     1,     3,
       0,     3,     2,     0,     2,     3,     1,     1,     2,     3,
       0,     3,     2,     3,     0,     1,     1,     5,     1,     0,
       3,     3,     3,     0,     1,     2,     3,     2,     2,     5,
       5,     4,     3,     3,     2,     1,     0,     1,     0,     1,
       0,     3,     0,     2,     0,     3,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* start: single_input  */
#line 115 "parser.y"
                    {printf("single_input\n");}
#line 1687 "parser.tab.c"
    break;

  case 3: /* start: file_input  */
#line 116 "parser.y"
            {printf("file_input\n");}
#line 1693 "parser.tab.c"
    break;

  case 4: /* start: eval_input  */
#line 117 "parser.y"
            {printf("eval_input\n");}
#line 1699 "parser.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 146 "parser.y"
         {printf("func1_input\n");}
#line 1705 "parser.tab.c"
    break;

  case 16: /* $@2: %empty  */
#line 146 "parser.y"
                                               {printf("param_input\n");}
#line 1711 "parser.tab.c"
    break;

  case 17: /* $@3: %empty  */
#line 146 "parser.y"
                                                                                    {printf("arrow_input\n");}
#line 1717 "parser.tab.c"
    break;

  case 18: /* $@4: %empty  */
#line 146 "parser.y"
                                                                                                                     {printf("colon_input\n");}
#line 1723 "parser.tab.c"
    break;

  case 19: /* funcdef: DEF NAME $@1 parameters $@2 arrowtest $@3 COLON $@4 suite  */
#line 146 "parser.y"
                                                                                                                                                       {printf("func_input\n");}
#line 1729 "parser.tab.c"
    break;

  case 114: /* $@5: %empty  */
#line 372 "parser.y"
             {printf("for1_input\n");}
#line 1735 "parser.tab.c"
    break;

  case 115: /* for_stmt: FOR exprlist $@5 IN testlist COLON suite elsesuite  */
#line 372 "parser.y"
                                                                        {printf("for_input\n");}
#line 1741 "parser.tab.c"
    break;

  case 116: /* suite: simple_stmt  */
#line 376 "parser.y"
             {printf("suite_input\n");}
#line 1747 "parser.tab.c"
    break;

  case 117: /* $@6: %empty  */
#line 377 "parser.y"
                                {printf("suite2_input\n");}
#line 1753 "parser.tab.c"
    break;

  case 118: /* suite: NEWLINE INDENT oneormore_stmt $@6 DEDENT  */
#line 377 "parser.y"
                                                                  {printf("suite1_input\n");}
#line 1759 "parser.tab.c"
    break;

  case 199: /* trailer: DOT NAME  */
#line 569 "parser.y"
           {printf("dot\n");}
#line 1765 "parser.tab.c"
    break;


#line 1769 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 750 "parser.y"


int main(int argc, char *argv[])
{
FILE *fp;
    char* filename = argv[1];
   // printf("Enter the filename: \n");
    //scanf("%s",filename);
    fp = fopen(filename,"r");
    yyin = fp;

  yyparse();

  return 0;
}

void yyerror(const char * s)
{
	printf("Error in line %d: %s, %s\n",yylineno,s,yytext);

  exit(0);
}
