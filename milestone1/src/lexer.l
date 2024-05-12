%{
    //#include<bits/stdc++.h>
    #include<stdio.h>
    #include<stdlib.h>
    #include"string.h"
    #include "parser.tab.h"
    
    //using namespace std;
	
    //extern long long int line_number;
    int line=1;
    int len=0;
    int whitesp=0;
    
    
   // Stack for indentation levels
int indentation_stack[100]; 
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
%s end

%%
	
	// Push initial zero onto stack
	{
	
	if(!flag) {push_indentation(0); flag=1;}
	
	int current_indentation = len ; 
    int previous_indentation = top_indentation();
 	if(whitesp==1){
 	    whitesp=0; 
    printf("Current %d Previous %d\n",current_indentation,previous_indentation);
    // Check for odd number of spaces
    if (len % 2 != 0) {
        printf("Error: in indentation\n");
        exit(EXIT_FAILURE);
    }
    //printf("Current %d Previous %d\n",current_indentation,previous_indentation);
    if (current_indentation > previous_indentation) {
         printf("Indent\n");
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
            printf("DEDENT\n");
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
	printf("whiltesp %d %d\n",whitesp,len);
	return NEWLINE;
}


[#](.)*\n {}  
\"\"\"(\\.|[^"\\])*\"\"\"  {}  
\'\'\'(\\.|[^"\\])*\'\'\'  {} 
True {   
    return TRUE;
}
False {
    return FALSE;
}

None {    return NONE;}
pass {    return PASS;}
continue { return CONTINUE;}
for { return FOR;}
if { return IF;}
elif { return ELIF;}
else {  return ELSE;}
break {   return BREAK;}
return { return RETURN;}
class {  return CLASS;}
while {  return WHILE;}
in {    return IN;}
is {    return IS;}
and {   return LOGICAND;}
def {    return DEF;}
not { return LOGICNOT;}
or {  return LOGICOR;}
raise {  return RAISE;}
global {  return GLOBAL;}
assert {  return ASSERT;}
nonlocal {  return NONLOCAL;}
from {  return FROM;}
"is not" {return ISNOT;}
"not in"   {return NOTIN;}
[a-zA-Z_]([a-zA-Z0-9_])* {
    return NAME;
}
[0-9]*\.?[0-9]+ {
    return NUMBER;
}
(0x|0X)[0-9a-fA-F]*\.?[0-9a-fA-F]+ {
    return NUMBER;
}
0[0-7]*\.?[0-7]+([eE][-+]?[0-7]+)? {
            return NUMBER;}

[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?(f?|F?|d?|D?) {
   
    return NUMBER;
}
(0x|0X)[0-9a-fA-F]*\.?[0-9a-fA-F]+([eE|pP][-+]?[0-9a-fA-F]+)?(f?|F?|d?|D?) {
   
    return NUMBER;
}
(0b|0B)[0-1]*\.?[0-1]+([eE][-+]?[0-1]+)? {
    return NUMBER;
}
"'"+(.)+"'" {
    return STRING;
}

"+" {
    return ADD;
}
"-" {
    return SUBTRACT;
}
"*" {
    return ONESTAR;
}
"/" {
    return DIVIDE;
}

"//" {
   
    return FLOORDIV;
}

"%" {
    
    return MODULO;
}

"**" {
    
    return TWOSTAR;
}
"<>" {
    
    return LESSGREAT;
}

"=" {
    
    return ASSIGNMENTOP;
}
"+=" {
    
    return PLUSEQUAL;
}
"-=" {
    
    return MINUSEQUAL;
}
"*=" {
   
    return  MULEQUAL;
}
"/=" {
   
    return FLOATDIVEQUAL;
}
"//=" {
   
    return FLOORDIVEQUAL;
}
"%=" {
    
    return MODEQUAL;
}
"**=" {
    
    return POWEQUAL;
}
"&=" {
    
    return ANDEQUAL;
}
"|=" {
    
    return OREQUAL;
}
"^=" {
   
    return XOREQUAL;
}

"<<=" {
    
    return LSHIFTEQUAL;
}
">>=" {
   
    return RSHIFTEQUAL;
}



">" {
   
    return GREATERTHAN;
    }
"<" {
    
    return LESSTHAN;
}
"==" {
    
    return ISEQUAL;
}
">=" {
    
    return GREATERTHANEQUALTO;
}
"<=" {
    
    return LESSTHANEQUALTO;
}
"!=" {
   
    return NOTEQUAL;
}



"&" {
    
    return BITWISEAND;
}
"|" {
    
    return BITWISEOR;
}
"^" {
    
    return BITWISEXOR;
}
"~" {
   
    return BITWISENOT;
}

"<<" {
    
    return LSHIFT;
}
">>" {
   
    return RSHIFT;
}

":" {
    
    return COLON;
}
"->" {
    
    return ARROW;
}

"[" {
    
    return LSQUAREBRACKET;
}
"]" {
    
    return RSQUAREBRACKET;
}
"(" {
    
    return LEFTPARANTHESIS;
}
")" {
    
    return RIGHTPARANTHESIS;
}


"." {
    
        return DOT;
}

"," { return COMMA; }

"{" {
    
        return  LCURLYBRACE;
}

"}" {
    
        return RCURLYBRACE;
}

";" {
    
        return SEMICOLON;
}

\"(\\.|[^"\\])*\" {
   
   
            return STRING;
}


<INITIAL><<EOF>>   {BEGIN(end);	
 printf("END\n");
    	return ENDMARKER;
    	//yyterminate();
}

[ \t\f\n]+ {}

%%

//int yywrap() {return 1;}


