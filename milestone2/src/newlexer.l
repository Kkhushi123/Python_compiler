%{

    #include<bits/stdc++.h>

    #include<stdio.h>

    #include<stdlib.h>

    #include"string.h"

    #include "newparser.tab.h"

    using namespace std;
    //extern long long int line_number;

    int line=1;

    int len=0;

    int whitesp=0;

    

   // Stack for indentation levels

int indentation_stack[1000]; 

int stack_top = 0; 

int flag=0;



// Function to push indentation level onto the stack

void push_indentation(int level) {

    indentation_stack[stack_top++] = level;

}



// Function to pop indentation level from the stack

int pop_indentation() {

    if (stack_top > 0) {

        return indentation_stack[--stack_top];

    }

    return 0;

}



// Function to get the top indentation level from the stack

int top_indentation() {

    if (stack_top > 0) {

        return indentation_stack[stack_top - 1];

    }

    return 0;

}



%}



%option yylineno

%option noyywrap

%option case-insensitive

WHITESPACE [ \t]

%s endfile



%%

	// Push initial zero onto stack

	{
	if(!flag) {push_indentation(0); flag=1;}

	
	int current_indentation = len ; 

    int previous_indentation = top_indentation();

 	if(whitesp==1){

 	    whitesp=0; 

    //printf("Current %d Previous %d\n",current_indentation,previous_indentation);

    // Check for odd number of spaces

    if (len % 2 != 0) {

        printf("Error: in indentation\n");

        exit(EXIT_FAILURE);

    }

    //printf("Current %d Previous %d\n",current_indentation,previous_indentation);

    if (current_indentation > previous_indentation) {

         //printf("Indent\n");

        push_indentation(current_indentation);

        return INDENT;

    }}

     

    if (current_indentation < previous_indentation) {

     	int present=0;

    	for(int i=0;i<stack_top;i++){

    		if(current_indentation==indentation_stack[i]) {present=1;break;}

    	}

    	

    	//if curent indentation is not found on stack, then there is an error

        if(!present) {printf("Error: in indentation\n");

        exit(EXIT_FAILURE);}

             int a=0;

        while (current_indentation < top_indentation()) {

            //printf("DEDENT\n");

            pop_indentation();

            a=1;

            return DEDENT;

        }

        

    }

 	

	whitesp=0;

    

  	}



[\n]+({WHITESPACE}*)  {

	

	int i=0;

	while(yytext[i]=='\n')

	i++;

	len= yyleng-i;

	if(len>0) whitesp=1;

	//printf("whiltesp %d %d\n",whitesp,len);

	return NEWLINE;

}





[#](.)*\n {}  

\"\"\"(\\.|[^"\\])*\"\"\"  {}  

\'\'\'(\\.|[^"\\])*\'\'\'  {} 

True {   
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return TRUE;

}

False {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return FALSE;

}



None {  strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';  return NONE;}

pass { strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';   return PASS;}

continue {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0'; return CONTINUE;}

for {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0'; return FOR;}

if {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0'; return IF;}

elif {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0'; return ELIF;}

else {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';  return ELSE;}

break {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';   return BREAK;}

return {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0'; return RETURN;}

class { strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0'; return CLASS;}

while {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';  return WHILE;}

in { strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';   return IN;}

is { strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';   return IS;}

and { strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';  return LOGICAND;}

def {  strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';  return DEF;}

not {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0'; return LOGICNOT;}

or { strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0'; return LOGICOR;}

raise {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';  return RAISE;}

global {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';  return GLOBAL;}

assert {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';  return ASSERT;}

nonlocal {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';  return NONLOCAL;}

from {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';  return FROM;}

"is not" {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';return ISNOT;}

"not in"   {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';return NOTIN;}

[a-zA-Z_]([a-zA-Z0-9_])* {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0'; // Ensure null termination
    return NAME;

}

[0-9]*\.?[0-9]+ {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return NUMBER;

}

(0x|0X)[0-9a-fA-F]*\.?[0-9a-fA-F]+ {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return NUMBER;

}

0[0-7]*\.?[0-7]+([eE][-+]?[0-7]+)? {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
            return NUMBER;}



[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?(f?|F?|d?|D?) {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return NUMBER;

}

(0x|0X)[0-9a-fA-F]*\.?[0-9a-fA-F]+([eE|pP][-+]?[0-9a-fA-F]+)?(f?|F?|d?|D?) {

   strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return NUMBER;

}

(0b|0B)[0-1]*\.?[0-1]+([eE][-+]?[0-1]+)? {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return NUMBER;

}

"+" {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return ADD;

}

"-" {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return SUBTRACT;

}

"*" {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return ONESTAR;

}

"/" {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return DIVIDE;

}



"//" {

   strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return FLOORDIV;

}



"%" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return MODULO;

}



"**" {

    
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return TWOSTAR;

}

"<>" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return LESSGREAT;

}



"=" {

    
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return ASSIGNMENTOP;

}

"+=" {

    
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return PLUSEQUAL;

}

"-=" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return MINUSEQUAL;

}

"*=" {

   strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return  MULEQUAL;

}

"/=" {

   strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return FLOATDIVEQUAL;

}

"//=" {

   
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return FLOORDIVEQUAL;

}

"%=" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return MODEQUAL;

}

"**=" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return POWEQUAL;

}

"&=" {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    

    return ANDEQUAL;

}

"|=" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return OREQUAL;

}

"^=" {

   
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return XOREQUAL;

}



"<<=" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return LSHIFTEQUAL;

}

">>=" {

   strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return RSHIFTEQUAL;

}

">" {

strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return GREATERTHAN;

    }

"<" {

strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return LESSTHAN;

}

"==" {

strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return ISEQUAL;

}

">=" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return GREATERTHANEQUALTO;

}

"<=" {

strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return LESSTHANEQUALTO;

}

"!=" {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return NOTEQUAL;

}

"&" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return BITWISEAND;

}

"|" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return BITWISEOR;

}

"^" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return BITWISEXOR;

}

"~" {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return BITWISENOT;

}



"<<" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return LSHIFT;

}

">>" { 
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return RSHIFT;

}



":" {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

    return COLON;

}

"->" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return ARROW;

}



"[" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return LSQUAREBRACKET;

}

"]" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return RSQUAREBRACKET;

}

"(" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return LEFTPARANTHESIS;

}

")" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
    return RIGHTPARANTHESIS;

}

"." {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
        return DOT;

}

"," {strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0'; return COMMA; }



"{" {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
        return  LCURLYBRACE;

}


"}" {
strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';

        return RCURLYBRACE;

}



";" {

    strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
        return SEMICOLON;

}

\"(\\.|[^"\\])*\" {

   strncpy(yylval.str, yytext, sizeof(yylval.str) - 1);
    yylval.str[sizeof(yylval.str) - 1] = '\0';
            return STRING;

}

<INITIAL><<EOF>>   {BEGIN(endfile);	


    	return ENDMARKER;

    	//yyterminate();

}

[ \t\f\n]+ {}


%%







