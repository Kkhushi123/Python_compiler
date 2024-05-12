%{
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

%}

 //%define parse.error verbose

%union {
  struct {
    int n;
    char str[1000];
  } lab;

}


%token<lab> NEWLINE
%token<lab> DEF
%token<lab> ARROW
%token<lab> COLON
%token<lab> LEFTPARANTHESIS
%token<lab> RIGHTPARANTHESIS
%token<lab> ASSIGNMENTOP
%token<lab> COMMA
%token<lab> SEMICOLON
%token<lab> PLUSEQUAL
%token<lab> MINUSEQUAL
%token<lab> MULEQUAL
%token<lab> FLOATDIVEQUAL
%token<lab> ANDEQUAL
%token<lab> OREQUAL
%token<lab> XOREQUAL
%token<lab> MODEQUAL
%token<lab> LSHIFTEQUAL
%token<lab> RSHIFTEQUAL
%token<lab> POWEQUAL
%token<lab> FLOORDIVEQUAL
%token<lab> PASS
%token<lab> BREAK
%token<lab> CONTINUE
%token<lab> RETURN
%token<lab> RAISE
%token<lab> GLOBAL
%token<lab> NONLOCAL
%token<lab> ASSERT
%token<lab> FROM
%token<lab> IF
%token<lab> ELIF
%token<lab> ELSE
%token<lab> WHILE
%token<lab> FOR
%token<lab> IN
%token<lab> LOGICOR
%token<lab> LOGICAND
%token<lab> LOGICNOT
%token<lab> LESSTHAN
%token<lab> GREATERTHAN
%token<lab> ISEQUAL
%token<lab> LESSTHANEQUALTO
%token<lab> GREATERTHANEQUALTO
%token<lab> LESSGREAT
%token<lab> NOTEQUAL
%token<lab> NOTIN
%token<lab> IS 
%token<lab> ISNOT
%token<lab> ONESTAR
%token<lab> TWOSTAR
%token<lab> BITWISEOR 
%token<lab> BITWISEAND 
%token<lab> BITWISENOT 
%token<lab> BITWISEXOR 
%token<lab> LSHIFT
%token<lab> RSHIFT
%token<lab> ADD 
%token<lab> SUBTRACT
%token<lab> DIVIDE
%token<lab> MODULO
%token<lab> FLOORDIV
%token<lab> LSQUAREBRACKET
%token<lab> RSQUAREBRACKET 
%token<lab> LCURLYBRACE
%token<lab> RCURLYBRACE
%token<lab> NONE
%token<lab> TRUE
%token<lab> FALSE
%token<lab> DOT
%token<lab> CLASS
%token<lab> NAME
%token<lab> NUMBER
%token<lab> STRING
%token<lab> INDENT
%token<lab> DEDENT
%token ENDMARKER
%start start

%%
start: single_input {printf("single_input\n");}
|file_input {printf("file_input\n");}
|eval_input {printf("eval_input\n");}
;

single_input: NEWLINE 
| simple_stmt 
| compound_stmt NEWLINE
;

file_input:
newlinestmt ENDMARKER
;

newlinestmt:
NEWLINE newlinestmt
|stmt newlinestmt
|/*epsilon*/
;

eval_input:
testlist newstar ENDMARKER
;

newstar:
NEWLINE newstar
| /*epsilon*/
; 


funcdef:
DEF NAME {printf("func1_input\n");} parameters {printf("param_input\n");} arrowtest {printf("arrow_input\n");} COLON {printf("colon_input\n");} suite  {printf("func_input\n");}
;
arrowtest:
ARROW test
|/*epsilon*/
;

parameters:
LEFTPARANTHESIS typedright 
;
typedright:
typedargslist RIGHTPARANTHESIS
| RIGHTPARANTHESIS
;
typedargslist:
 tfoptcomm commoptep
| oneoptcomm commepcomma
| TWOSTAR tfpdef optionalcomma
; 

commoptep:
COMMA optional_commtfp_or_twotfp
| /*epsilon*/
;

commepcomma:
commtwotfpcomma
| COMMA
| /*epsilon*/
;

optional_commtfp_or_twotfp:
commtfp_or_twotfp
|/*epsilon*/
;
oneoptcomm:
ONESTAR optionaltfpdef commtfpdefeqtest
;

commtfp_or_twotfp:
oneoptcomm commtwotfpcomma
| twotfpdefcomma
;

commtfpdefeqtest:
COMMA tfoptcomm
|/*epsilon*/
;
tfoptcomm:
tfpdef optionaleqtest commtfpdefeqtest
;

commtwotfpcomma:
COMMA twotfpdefcomma
|/*epsilon*/
;

twotfpdefcomma:
TWOSTAR tfpdef optionalcomma
|/*epsilon*/
;

optionaltfpdef:
tfpdef
|/*epsilon*/
;

tfpdef: 
NAME colontest
;

optionaleqtest:
ASSIGNMENTOP test
|/*epsilon*/
;

colontest:
COLON test
| /*epsilon*/
;

stmt:
simple_stmt 
| compound_stmt
;

simple_stmt:
small_stmt colsmall_stmt optionalcolon NEWLINE
;

colsmall_stmt:
COLON small_stmt colsmall_stmt
|/*epsilon*/
;

small_stmt: 
expr_stmt  
| pass_stmt 
| flow_stmt 
| global_stmt 
| nonlocal_stmt 
| assert_stmt
 
;

  
expr_stmt: 
testlist_star_expr anaugassigneqtest
;
anaugassigneqtest:
annassign 
| augassign testlist 
| equalteststarexp
;

equalteststarexp:
ASSIGNMENTOP testlist_star_expr equalteststarexp
| /*epsilon*/
;

annassign: 
COLON test assignoptest
;

assignoptest:
ASSIGNMENTOP test
|/*epsilon*/
;

testlist_star_expr:
teststar comm_teststar optionalcomma
;

comm_teststar:
COMMA teststar comm_teststar
|/*epsilon*/
;

teststar:
test
|star_expr
;

augassign: 
PLUSEQUAL 
| MINUSEQUAL 
| MULEQUAL 
| FLOATDIVEQUAL 
| MODEQUAL 
| ANDEQUAL 
| OREQUAL 
| XOREQUAL 
| LSHIFTEQUAL 
| RSHIFTEQUAL 
| POWEQUAL 
| FLOORDIVEQUAL
;

pass_stmt: 
PASS
;

flow_stmt: 
break_stmt 
| continue_stmt 
| return_stmt 
| raise_stmt 
;

break_stmt: 
BREAK
;

continue_stmt: 
CONTINUE
;

return_stmt:
RETURN optionaltestlist
;

raise_stmt:
RAISE testfromtest
;
fromtest:
FROM test
|/*epsilon*/
;

testfromtest:
test fromtest
|/*epsilon*/
;

global_stmt:
GLOBAL NAME commaname
;

nonlocal_stmt:
NONLOCAL NAME commaname
;

assert_stmt: ASSERT test commatest
;

compound_stmt:
if_stmt 
| while_stmt 
| for_stmt 
| funcdef 
| classdef 
;

if_stmt: IF test COLON suite eliftestsuite elsesuite
;

eliftestsuite:
ELIF test COLON suite eliftestsuite
|/*epsilon*/
;

while_stmt:
WHILE test COLON suite elsesuite
;

for_stmt: 
FOR exprlist {printf("for1_input\n");}IN testlist COLON suite elsesuite {printf("for_input\n");}
;

suite: 
simple_stmt  {printf("suite_input\n");}
| NEWLINE INDENT oneormore_stmt {printf("suite2_input\n");}DEDENT {printf("suite1_input\n");}
;

oneormore_stmt:
stmt oneormore_stmt
|stmt
;

test: 
or_test if_orelsetest
;

if_orelsetest:
IF or_test ELSE test
|/*epsilon*/
;

test_nocond:
or_test 
;

or_test: 
and_test orandtest
;

orandtest:
LOGICOR and_test orandtest
| /*epsilon*/
;

and_test: 
not_test andnottest
;

andnottest:
LOGICAND not_test andnottest
|/*epsilon*/
;

not_test: LOGICNOT not_test 
| comparison
;

comparison: expr compexpr
;

compexpr:
comp_op expr compexpr
|/*epsilon*/
;

//remove lambda
comp_op: 
LESSTHAN
|GREATERTHAN
|ISEQUAL
|GREATERTHANEQUALTO
|LESSTHANEQUALTO
|LESSGREAT
|NOTEQUAL
|IN
|NOTIN
|IS
|ISNOT
;

star_expr: 
ONESTAR expr
;

expr: 
xor_expr bitxorexpr
;

bitxorexpr:
BITWISEOR xor_expr bitxorexpr
|/*epsilon*/
;

xor_expr: 
and_expr bitandexpr
;

bitandexpr:
BITWISEXOR and_expr bitandexpr
|/*epsilon*/
;

and_expr: 
shift_expr bitshiftexpr
;

bitshiftexpr:
BITWISEAND shift_expr bitshiftexpr
|/*epsilon*/
;

shift_expr: arith_expr lrarithexpr
;

lrarithexpr:
lrshift arith_expr lrarithexpr
|/*epsilon*/
;

lrshift:
LSHIFT
|RSHIFT
;

arith_expr: 
term addsub_term
;

addsub_term:
addsub term addsub_term
|/*epsilon*/
;

addsub:
ADD
|SUBTRACT
;

term: 
factor primopfactor
;

primopfactor:
primopr factor primopfactor
|/*epsilon*/
;

primopr:
ONESTAR
|DIVIDE
|MODULO
|FLOORDIV
;

factor: 
unaryop factor 
| power
;
unaryop:
ADD
|SUBTRACT
|BITWISENOT
;

power: 
atom_expr twostarfac
;

twostarfac: 
TWOSTAR factor
|/*epsilon*/
;

atom_expr: 
atom zeromoretrail
;

zeromoretrail:
trailer zeromoretrail
|/*epsilon*/
;

atom: 
LEFTPARANTHESIS optionaltest_comp RIGHTPARANTHESIS 
| LSQUAREBRACKET optionaltest_comp RSQUAREBRACKET 
| LCURLYBRACE optionaldictor_maker RCURLYBRACE 
| NAME 
| NUMBER 
| onemorestring
| NONE 
| TRUE 
| FALSE
;

onemorestring:
STRING onemorestring
| STRING
;

testlist_comp: 
testorstar comp_comtest
;

trailer: 
leftopargright 
| LSQUAREBRACKET subscriptlist RSQUAREBRACKET 
| DOT NAME {printf("dot\n");}
;

subscriptlist: 
subscript commsubscript optionalcomma
;

commsubscript:
COMMA subscript commsubscript
|/*epsilon*/
;

subscript: 
test 
| optionaltest COLON optionaltest optionalsliceop
;

sliceop: 
COLON optionaltest
;

exprlist: 
exprorstar_expr commexprorstar optionalcomma
;

exprorstar_expr:
expr
|star_expr
;

commexprorstar:
COMMA exprorstar_expr commexprorstar
|/*epsilon*/
;

testlist: 
test zeromorecommtest optionalcomma
;

zeromorecommtest:
commatest zeromorecommtest
|/*epsilon*/
;

dictorsetmaker: 
testcolonortwostar comp_for
| testcolonortwostar commtestcoltwostar optionalcomma
| testlist_comp
;

comp_comtest:
comp_for
| comteststar optionalcomma
;

commtestcoltwostar:
COMMA testcolonortwostar commtestcoltwostar
|/*epsilon*/
;

testcolonortwostar:
test COLON test
| TWOSTAR expr
;

comteststar:
COMMA testorstar comteststar
|/*epsilon*/
;

testorstar:
test
|star_expr
;

classdef: 
CLASS NAME optionalleftargright COLON suite
;

optionalleftargright:
leftopargright
|/*epsilon*/
;

leftopargright:
LEFTPARANTHESIS optionalarglist RIGHTPARANTHESIS
;

arglist: 
argument commarg  optionalcomma
;

commarg:
COMMA argument commarg
|/*epsilon*/
;

argument:  
test
| test comp_for 
| test ASSIGNMENTOP test 
| TWOSTAR test 
| ONESTAR test
;

comp_for: 
FOR exprlist IN or_test comp_for
| FOR exprlist IN or_test comp_if
| FOR exprlist IN or_test 
;

comp_if: 
IF test_nocond comp_for
| IF test_nocond comp_if
| IF test_nocond 
;

/*encoding_decl: 
NAME
;*/

/******Utilities********/

optionalcolon:
COLON
|/*epsilon*/
;

optionalcomma:
COMMA
|/*epsilon*/
;

optionaltestlist:
testlist
|/*epsilon*/
;

commaname:
COMMA NAME commaname
|/*epsilon*/
;

commatest:
COMMA test
|/*epsilon*/
;

elsesuite:
ELSE COLON suite
|/*epsilon*/
;

optionaltest_comp:
testlist_comp
|/*epsilon*/
;

optionaldictor_maker:
dictorsetmaker
|/*epsilon*/
;

optionaltest:
test
|/*epsilon*/
;

optionalsliceop:
sliceop
|/*epsilon*/
;

optionalarglist:
arglist
|/*epsilon*/
;

/**************/


%%

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
