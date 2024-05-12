%{

    #include<stdio.h>

    #include<stdlib.h>

    #include <string.h>

    #include <cstring>

    #include <bits/stdc++.h>

    #include <fstream>

    #include "newparser.tab.h"

    #include "lex.yy.c"

    

    using namespace std;



    void yyerror(const char * s);

    int yylex();

    extern int yylineno;

    extern FILE* yyin;

   

    int nformal_params=0;
    int ndim=0;

    extern int yylineno;  

    #define YYERROR_VERBOSE 1


    vector<string> ops = {"+","-","*","/","//","%","**","<>","=","+=","-=","*=","**=","/=","//=","%=","&=","|=","^=","<<=",">>=","<",">","==",">=","<=","!=","&","|","^","~","<<",">>","and","or","not"};

    vector<string> keywords = {"range","True","False","len","None","pass","continue","for","if","elif","else","break","return","class","while","in","is","and","def","not","or","raise","global","assert","nonlocal","from","is not","not in", "__main__","__name__","print", "self", "__init__"};

    vector<string> dtype = {"bool","int","float","str"}; 

//Actually not supporting strings

    int getsize(string s)

    {

      if(s=="bool")

      return 1;

      else if(s=="int")

      return 4;

      else if(s=="float")

      return 8;

      else

      return 0;

    }


//invalid_datatype not invalidoperator

 int invalidoperator(string s,int flag){

      int x=3;

      for(int i=0;i<x;i++){

          if(s==dtype[i])  return 0;

      }

      return 1;

    }

    //returning higher precedence data type

string getorder(string a,string b, int flag)

    {

      int size;
      size=3;
      if(a==b)

      return a;

      else

      {

        int q=3,w=3;

        for(int i=0;i<size;i++)

        {

          if(a==dtype[i])

          q=i;      

        }

        for(int i=0;i<size;i++)

        {

          if(b==dtype[i])

          w=i;      

        }

        if(q>w)

        return dtype[q];

        else

        return dtype[w];

      }



    }


class Sym_Entry {

      public:

        string token;

        string type;

        int offset;

        string scope_name;

        int line;

        int nformal_params;

        int isitfinal;

        Sym_Entry(){ 

        }

        Sym_Entry(string toke, string typ, int offse, string scope_nam, int lin, int argn){

          token = toke;

          type = typ;

          offset = offse;

          scope_name = scope_nam;

          line = lin;
          nformal_params=argn;
        }

        void print_entry(){

          cout << token << " " << type << " " << offset << " " << scope_name << " " << line << " "<<nformal_params<<" "<<endl;

        }

    };





class Sym_Table {

      public:

        map<string, Sym_Entry> table;

        Sym_Table* parent;

        int level_no;
        string table_name;

        void entry(string lexeme, string token, string type, int offset, string scope_name, int line, int argno){

          table[lexeme] = Sym_Entry(token, type, offset, scope_name, line, argno);

        }

        Sym_Table(){}

        Sym_Table(Sym_Table* child){

            if(!child){

              level_no = 0;

              parent = NULL;

            }

            else{

              level_no = child->level_no + 1;

              parent = child;

            }

        }

        Sym_Entry lookup(string lexeme){

          for(auto it=this; it!=NULL; it=it->parent){

            if(it->table.find(lexeme) != it->table.end()){

              return it->table[lexeme];

            }

          }

          return Sym_Entry("null", "null", -1, "null", -1, -2);

        }

        void print_table(){
          //cout<<"print_table called\n";

          if(table.begin()==table.end()) cout<<"empty table\n";
          for(auto it:table){

            cout<<it.first<<": ";

            it.second.print_entry();

          }

        }

    };

    int offset = 0;

    Sym_Table* curr_table = new Sym_Table(NULL);
    // curr_table->table_name = "Global_Table";


    string curr_scope = "Global";

    stack<Sym_Table*> tables;

    stack<int> offsets;

    stack<string> scope_names;

    int size; 

    string type="";

    vector<Sym_Table*> list_of_Symbol_Tables(1, curr_table);

    void print_complete_symTable(){
      for (Sym_Table* sym_tab : list_of_Symbol_Tables) {
        string name="";

        if(sym_tab->parent == NULL) name= "Global Table";
        else name = sym_tab->table_name;

        cout<<endl<<"Level: "<<sym_tab-> level_no<<"  Table Name: "<<name <<endl;
        
        sym_tab->print_table();
        cout << endl;
        
    }

    }
    

//cheching for function name and number of arguments match or not
    Sym_Entry lookup1(string funcname, int argno){

          for(auto it: list_of_Symbol_Tables){

            auto tab = it->table;

            for(auto it1 = tab.begin(); it1 != tab.end(); it1++){

                if(it1->second.scope_name == funcname){

                    if(it1->second.nformal_params == argno){

                        return it1->second;

                    }

                }

                else break;

            }

          }

          return Sym_Entry("null", "null", -1, "null", -1, -2);

    }


stack<string> st;
queue<string> errors;

%}

%define parse.error verbose

%union {

  // struct {
  //   int n;
  //   char str[1000];

  // } str;
  char str[1000];

    struct {

        int size;
        int nformal_params;
        int isnumber;
        int isvar;
        char lexeme[100];

        char type[1000];
        
    } typ;

}


%type<typ> start
%type<typ> file_input
%type<typ> simple_stmt
%type<typ> compound_stmt
%type<typ> newlinestmt
%type<typ> stmt
%type<typ> funcdef
%type<typ> parameters
%type<typ> suite
%type<typ> test
%type<typ> formalarguments
%type<typ> oneargument
%type<typ> small_stmt
%type<typ> expr_stmt
%type<typ> augassign
%type<typ> if_stmt
%type<typ> while_stmt
%type<typ> for_stmt
%type<typ> classdef
%type<typ> eliftestsuite
%type<typ> oneormore_stmt
%type<typ> expr
%type<typ> comp_op
%type<typ> term
%type<typ> factor
%type<typ> power
%type<typ> atom_expr
%type<typ> atom
%type<typ> trailer
%type<typ> comma_test
%type<typ> funcstart
%type<typ> colsmall_stmt
%type<typ> equal_test

%token<str> NEWLINE
%token<str> DEF
%token<str> ARROW
%token<str> COLON
%token<str> LEFTPARANTHESIS
%token<str> RIGHTPARANTHESIS
%token<str> ASSIGNMENTOP
%token<str> COMMA
%token<str> SEMICOLON
%token<str> PLUSEQUAL
%token<str> MINUSEQUAL
%token<str> MULEQUAL
%token<str> FLOATDIVEQUAL
%token<str> ANDEQUAL
%token<str> OREQUAL
%token<str> XOREQUAL
%token<str> MODEQUAL
%token<str> LSHIFTEQUAL
%token<str> RSHIFTEQUAL
%token<str> POWEQUAL
%token<str> FLOORDIVEQUAL
%token<str> PASS
%token<str> BREAK
%token<str> CONTINUE
%token<str> RETURN
%token<str> RAISE
%token<str> GLOBAL
%token<str> NONLOCAL
%token<str> ASSERT
%token<str> FROM
%token<str> IF
%token<str> ELIF
%token<str> ELSE
%token<str> WHILE
%token<str> FOR
%token<str> IN
%token<str> LOGICOR
%token<str> LOGICAND
%token<str> LOGICNOT
%token<str> LESSTHAN
%token<str> GREATERTHAN
%token<str> ISEQUAL
%token<str> LESSTHANEQUALTO
%token<str> GREATERTHANEQUALTO
%token<str> LESSGREAT
%token<str> NOTEQUAL
%token<str> NOTIN
%token<str> IS 
%token<str> ISNOT
%token<str> ONESTAR
%token<str> TWOSTAR
%token<str> BITWISEOR 
%token<str> BITWISEAND 
%token<str> BITWISENOT 
%token<str> BITWISEXOR 
%token<str> LSHIFT
%token<str> RSHIFT
%token<str> ADD 
%token<str> SUBTRACT
%token<str> DIVIDE
%token<str> MODULO
%token<str> FLOORDIV
%token<str> LSQUAREBRACKET
%token<str> RSQUAREBRACKET 
%token<str> LCURLYBRACE
%token<str> RCURLYBRACE
%token<str> NONE
%token<str> TRUE
%token<str> FALSE
%token<str> DOT
%token<str> CLASS
%token<str> NAME
%token<str> NUMBER
%token<str> STRING
%token<str> INDENT
%token<str> DEDENT
%token ENDMARKER

%start start


%%

start: 

file_input 

;


file_input:

newlinestmt ENDMARKER {cout<<"end of file\n";
print_complete_symTable();
}

;


newlinestmt:

NEWLINE newlinestmt

|stmt newlinestmt

|/*epsilon*/

;


funcdef:

funcstart parameters ARROW test COLON suite {

  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();

  curr_table->table[string((char*)($1).lexeme)].nformal_params = ($2).nformal_params;
    if(($4).lexeme != "None") curr_table->table[string((char*)($1).lexeme)].type = ($4).type;
    else curr_table->table[string((char*)($1).lexeme)].type = "None";

}

| funcstart parameters COLON suite {
  int line = yylineno;
  string name = string((char*)($1).lexeme);
  string err_msg = "Return type of function ,"+name+ " is not mentioned at line "+to_string(line)+"\n";
  if(name != "main" && name != "__init__") errors.push(err_msg);
  
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();

  curr_table->table[string((char*)($1).lexeme)].nformal_params = ($2).nformal_params;
    curr_table->table[string((char*)($1).lexeme)].type = "null";

}

;

funcstart:
DEF NAME {
  // cout << string($2) << endl;

  curr_table->entry(string((char*)($2)),"Function", "FF", offset, curr_scope, yylineno, -1);
  //int old_level = curr_table->level_no;
  tables.push(curr_table);
  Sym_Table parent = tables.top();
  curr_table = new Sym_Table(parent);
  curr_table->table_name = "Function"+ string((char*)($2)) ;
  //curr_table->level_no = old_level +1;
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Func:" + string((char*)($2));
  curr_scope = new_scope;
  // curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset; 
  strcpy(($$).lexeme,($2));
}
;

parameters:

LEFTPARANTHESIS RIGHTPARANTHESIS {($$).nformal_params = 0;}

| LEFTPARANTHESIS formalarguments RIGHTPARANTHESIS {
  ($$).nformal_params = ($2).nformal_params;
}
;


formalarguments:

oneargument COMMA formalarguments {
  ($$).nformal_params = ($3).nformal_params + 1;
}

| oneargument {
   ($$).nformal_params = 1;
}

;

oneargument: 

NAME COLON test {

curr_table->entry(string((char*)($1)),"Identifier",string((char*)($3).type), offset, curr_scope, yylineno, -1);

}

| NAME {}

;


stmt:

simple_stmt 

| compound_stmt

;


simple_stmt:

small_stmt colsmall_stmt SEMICOLON NEWLINE {
}

| small_stmt colsmall_stmt NEWLINE {
}

;

colsmall_stmt:

SEMICOLON small_stmt colsmall_stmt {
  }

|/*epsilon*/ {}

;



//not supporting many declarations or assignments in one line

small_stmt: 

expr_stmt  

| PASS 

| BREAK 

| CONTINUE 

| RETURN test 

| RETURN

;

expr_stmt: 

//declaration of a variable, should not be present already(if lookup test->atom is already in the symbol table, throw error of redclaration)
test COLON test ASSIGNMENTOP Declcheck test {
    int line = yylineno-1;
  string name = string((char*)($1).lexeme);
if(name == "null") {

   string err_msg = "Wrong identifier name , "+name+ " at line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);
}

else if(curr_table->lookup(string((char*)($1).lexeme)).offset==-1) {
  if(string((char*)($3).type) == "int" || string((char*)($3).type) == "float" || string((char*)($3).type) == "bool") {

    curr_table->entry(string((char*)($1).lexeme),"Identifier",string((char*)($3).type), offset, curr_scope, yylineno-1, -1);

    offset+=($3).size;

  }

  else {
    string err_msg = "Type of identifier "+name+ " at line " +to_string(line)+" is not supported\n";
     if(!name.empty()) errors.push(err_msg);
  }

}

else{

  string err_msg = "Identifier, "+name+ " is already declared at line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);
} 

// if(($3).type == int )
st.pop();
}

//same
| test COLON test {
    int line = yylineno-1;
  string name = string((char*)($1).lexeme);
if(name == "null") {

   string err_msg = "Wrong identifier name , "+name+ " at line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);
}

else if(curr_table->lookup(string((char*)($1).lexeme)).offset==-1) {
  if(string((char*)($3).type) == "int" || string((char*)($3).type) == "float" || string((char*)($3).type) == "bool") {

    curr_table->entry(string((char*)($1).lexeme),"Identifier",string((char*)($3).type), offset, curr_scope, yylineno-1, -1);

    offset+=($3).size;

  }

  else {
    string err_msg = "Type of identifier "+name+ " at line " +to_string(line)+" is not supported\n";
     if(!name.empty()) errors.push(err_msg);
  }

}

else{

  string err_msg = "Identifier, "+name+ " is already declared at line "+to_string(line)+"\n";
  errors.push(err_msg);
}
}

//test1 should already be present as there is no type mention here
| test augassign Declcheck test {
  if(curr_table->lookup(string((char*)($1).lexeme)).offset==-1) {

  int line = yylineno;
  string name = string((char*)($1).lexeme);
  string err_msg = "Variable ,"+name+ " is not declared at line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);

  }
 st.pop();
}

| test equal_test {

}

;

equal_test:
// test should be present already if it is a name
ASSIGNMENTOP Declcheck test equal_test {st.pop();}

| /*epsilon*/
;

Declcheck:
 {
  st.push("=");
 }
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


compound_stmt:

if_stmt 

| while_stmt 

| for_stmt 

| funcdef 

| classdef 

;

if_stmt: 

IF test COLON suite eliftestsuite ELSE COLON suite {

   if(($2).isvar==1 && curr_table->lookup(string((char*)($2).lexeme)).offset==-1) {
    int line = yylineno;
  string name = string((char*)($2).lexeme);
  string err_msg = "Variable ,"+name+ " is not declared in the if statement around line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);
   }


}

| IF test COLON suite eliftestsuite {
     if(($2).isvar==1 && curr_table->lookup(string((char*)($2).lexeme)).offset==-1) {
    int line = yylineno;
  string name = string((char*)($2).lexeme);
  string err_msg = "Variable ,"+name+ " is not declared in the if statement around line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);
   }
}

;

eliftestsuite:

ELIF test COLON suite eliftestsuite {
     if(($2).isvar==1 && curr_table->lookup(string((char*)($2).lexeme)).offset==-1) {
    int line = yylineno;
  string name = string((char*)($2).lexeme);
  string err_msg = "Variable ,"+name+ " is not declared in the elif statement around line "+to_string(line)+"\n";
  if(!name.empty() ) errors.push(err_msg);
   }
}

|/*epsilon*/

;

while_stmt:

WHILE test COLON suite ELSE COLON suite {
     if(($2).isvar==1 && curr_table->lookup(string((char*)($2).lexeme)).offset==-1) {
    int line = yylineno;
  string name = string((char*)($2).lexeme);
  string err_msg = "Variable ,"+name+ " is not declared in the while loop around line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);
   }
}

| WHILE test COLON suite {
     if(($2).isvar==1 && curr_table->lookup(string((char*)($2).lexeme)).offset==-1) {
    int line = yylineno;
  string name = string((char*)($2).lexeme);
  string err_msg = "Variable ,"+name+ " is not declared in the while loop around line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);
   }
}
;


for_stmt: 

FOR expr IN test COLON suite ELSE COLON suite {
  if(($2).isvar==0){
       
    int line = yylineno;
  string name = string((char*)($2).lexeme);
  string err_msg = "Literal ,"+name+ " cannot be assigned in for loop around line "+to_string(line)+"\n";
  errors.push(err_msg);
   
  }
     if(($2).isvar==1 && curr_table->lookup(string((char*)($2).lexeme)).offset==-1) {
    int line = yylineno;
  string name = string((char*)($2).lexeme);
  string err_msg = "Variable ,"+name+ " is not declared in the for loop around line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);
   }

     if(($4).isnumber==1){
       
    int line = yylineno;
  string name = string((char*)($4).lexeme);
  string err_msg = "Literal ,"+name+ " is not iterable in the for loop around line "+to_string(line)+"\n";
  errors.push(err_msg);
   
  }
     if(($4).isvar==1 && curr_table->lookup(string((char*)($4).lexeme)).offset==-1) {
    int line = yylineno;
  string name = string((char*)($4).lexeme);
  string err_msg = "Variable ,"+name+ " is not declared in the for loop around line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);
   }
}

| FOR expr IN test COLON suite {
  if(($2).isvar==0){
       
    int line = yylineno;
  string name = string((char*)($2).lexeme);
  string err_msg = "Literal ,"+name+ " cannot be assigned in the for loop around line "+to_string(line)+"\n";
  errors.push(err_msg);
   
  }
     if(($2).isvar==1 && curr_table->lookup(string((char*)($2).lexeme)).offset==-1) {
    int line = yylineno;
  string name = string((char*)($2).lexeme);
  string err_msg = "Variable ,"+name+ " is not declared in the for loop around line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);
   }

     if(($4).isnumber==1){
       
    int line = yylineno;
  string name = string((char*)($4).lexeme);
  string err_msg = "Literal ,"+name+ " is not iterable in the for loop around line "+to_string(line)+"\n";
  errors.push(err_msg);
   
  }
     if(($4).isvar==1 && curr_table->lookup(string((char*)($4).lexeme)).offset==-1) {
    int line = yylineno;
  string name = string((char*)($4).lexeme);
  string err_msg = "Variable ,"+name+ " is not declared in the for loop around line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);
   }
}

;

suite: 

simple_stmt 

| NEWLINE INDENT oneormore_stmt DEDENT

;

oneormore_stmt:

stmt oneormore_stmt

|stmt

;



test: 
expr comp_op expr {
  if(($1).isvar==1 && curr_table->lookup(string((char*)($1).lexeme)).offset==-1) {
    int line = yylineno;
  string name = string((char*)($2).lexeme);
  string err_msg = "Variable ,"+name+ " is not declared at line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);
  //cout<<err_msg<<endl;
   }

   if(($3).isvar==1 && curr_table->lookup(string((char*)($3).lexeme)).offset==-1) {
    int line = yylineno;
  string name = string((char*)($2).lexeme);
  string err_msg = "Variable ,"+name+ " is not declared at line "+to_string(line)+"\n";
  if(!name.empty()) errors.push(err_msg);
   }

   ($$).isvar = 0;
    ($$).isnumber = 1;   
    strcpy(($$).type,"int");
    ($$).size = 4;

}
| expr {
    ($$).isvar = ($1).isvar;
    ($$).isnumber = ($1).isnumber;
    strcpy(($$).lexeme,($1).lexeme);
    strcpy(($$).type,($1).type);
    ($$).size = ($1).size;

   }
;


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



//not supporting bitwise or, xor, and, left shift , right shift

expr: 
// do type checking here 
expr ADD term {
 if (($1).type == "int" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "int" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "int") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "int" && ($3).type == "bool") strcpy(($$).type,"int");
else if (($1).type == "float" && ($3).type == "bool") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "bool" && ($3).type == "bool") strcpy(($$).type,"int");
}

| expr SUBTRACT term {
 if (($1).type == "int" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "int" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "int") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "int" && ($3).type == "bool") strcpy(($$).type,"int");
else if (($1).type == "float" && ($3).type == "bool") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "bool" && ($3).type == "bool") strcpy(($$).type,"int");

}

| term 
{
  ($$).isvar = ($1).isvar;
    ($$).isnumber = ($1).isnumber;
    strcpy(($$).lexeme,($1).lexeme);
    strcpy(($$).type,($1).type);
    ($$).size = ($1).size;
}

| LEFTPARANTHESIS expr RIGHTPARANTHESIS {strcpy(($$).type,($2).type);}
;



term: 
//do type checking here
term ONESTAR factor {
 if (($1).type == "int" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "int" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "int") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "int" && ($3).type == "bool") strcpy(($$).type,"int");
else if (($1).type == "float" && ($3).type == "bool") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "bool" && ($3).type == "bool") strcpy(($$).type,"int");
}

| term DIVIDE factor {
 if (($1).type == "int" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "int" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "int") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "int" && ($3).type == "bool") strcpy(($$).type,"int");
else if (($1).type == "float" && ($3).type == "bool") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "bool" && ($3).type == "bool") strcpy(($$).type,"int");
}

| term MODULO factor {
 if (($1).type == "int" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "int" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "int") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "int" && ($3).type == "bool") strcpy(($$).type,"int");
else if (($1).type == "float" && ($3).type == "bool") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "bool" && ($3).type == "bool") strcpy(($$).type,"int");

}

| term FLOORDIV factor {
 if (($1).type == "int" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "int" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "int") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "int" && ($3).type == "bool") strcpy(($$).type,"int");
else if (($1).type == "float" && ($3).type == "bool") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "bool" && ($3).type == "bool") strcpy(($$).type,"int");
}

| factor {
  ($$).isvar = ($1).isvar;
    ($$).isnumber = ($1).isnumber;
    strcpy(($$).lexeme,($1).lexeme);
    strcpy(($$).type,($1).type);
    ($$).size = ($1).size;
}

| LEFTPARANTHESIS expr RIGHTPARANTHESIS {strcpy(($$).type,($2).type);}

;



factor: 

ADD factor {strcpy(($$).type,($2).type);}

| SUBTRACT factor {strcpy(($$).type,($2).type);}

| BITWISENOT factor {
   if (($2).type == "int") strcpy(($$).type,"int");
   //else ERROR;

}

| power {
  ($$).isvar = ($1).isvar;
    ($$).isnumber = ($1).isnumber;
    strcpy(($$).lexeme,($1).lexeme);
    strcpy(($$).type,($1).type);
    ($$).size = ($1).size;
}

| LEFTPARANTHESIS expr RIGHTPARANTHESIS {strcpy(($$).type,($2).type);}

;

//right associative
power: 

atom_expr TWOSTAR power {
 if (($1).type == "int" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "int" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "int") strcpy(($$).type,"float");
else if (($1).type == "float" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "int" && ($3).type == "bool") strcpy(($$).type,"int");
else if (($1).type == "float" && ($3).type == "bool") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "float") strcpy(($$).type,"float");
else if (($1).type == "bool" && ($3).type == "int") strcpy(($$).type,"int");
else if (($1).type == "bool" && ($3).type == "bool") strcpy(($$).type,"int");
}

| atom_expr {
  ($$).isvar = ($1).isvar;
    ($$).isnumber = ($1).isnumber;
    strcpy(($$).lexeme,($1).lexeme);
    strcpy(($$).type,($1).type);
    ($$).size = ($1).size;
}

;



atom_expr: 

atom {
  ($$).isvar = ($1).isvar;
    ($$).isnumber = ($1).isnumber;
    strcpy(($$).lexeme,($1).lexeme);
    strcpy(($$).type,($1).type);
    ($$).size = ($1).size;
}

| atom trailer

;



atom: 

LEFTPARANTHESIS test comma_test RIGHTPARANTHESIS {strcpy(($$).type,"null");}

| LEFTPARANTHESIS RIGHTPARANTHESIS {strcpy(($$).type,"null");}



//---------not supporting lists----------

//| LSQUAREBRACKET optionaltest_comp RSQUAREBRACKET 

//| LCURLYBRACE optionaldictor_maker RCURLYBRACE 

| NAME 

 {
  ($$).isvar=1;
    int var=1;
    int datatype=0;
    int keyword=0;

string temp = string((char*)($1)); 

// cout<< temp<<endl;
    for(int i=0; i<4;i++){

        if(dtype[i]==temp) {
            var=0;
            datatype=1;
            ($$).isvar=0;
        }

    }
        for(auto it: keywords){

        if(it==temp) {
            var=0;
            ($$).isvar=0;
            keyword=1;
        }

    }

    strcpy(($$).lexeme,($1));
    strcpy(($$).type,"null");
    ($$).size = 0;


    if(!st.empty() && st.top()=="=" && var) {
      //variable present in RHS, so should be declared already

      if(curr_table->lookup(temp).offset==-1) {
        string err_msg = "Variable "+temp+ " used but not declared in line "+to_string(yylineno)+ "\n";
        errors.push(err_msg);
      }

    }
    if(st.empty() && (var || keyword)) {strcpy(($$).lexeme,($1));}

    if(datatype) {
      char datype[100];
      if(getsize(temp)==1) {strcpy(($$).type, "bool"); ($$).size=1;}
      if(getsize(temp)==4) {strcpy(($$).type, "int"); ($$).size=4;}
      if(getsize(temp)==8) {strcpy(($$).type, "float"); ($$).size=8;}
      strcpy(($$).lexeme, "null");
    }
    ($$).isnumber=0;
    
    
  //  scope_names.push(curr_scope);

}

| NUMBER

{
    strcpy(($$).lexeme,($1));
    strcpy(($$).type,"null");
    ($$).size = 0;

if (strchr(($1), '.') != NULL) {
            // Contains a decimal point, treating as float
            //printf("Float detected: %f\n", atof($1));

              ($$).size = 8;

              strcpy(($$).type,"float");
        }
        
         else {
            // No decimal point, treating as integer
           // printf("Integer detected: %d\n", atoi($1));
             ($$).size = 4;

            strcpy(($$).type,"int");
        }

        ($$).isvar=0;
        ($$).isnumber=1;

}

| STRING {
      strcpy(($$).lexeme,($1));
    strcpy(($$).type,"string");
    
    string stri= string((char*)($1));
    ($$).size = stri.size();
}

| NONE {
    strcpy(($$).lexeme,($1));
    strcpy(($$).type,"keyword");
    ($$).size = 16;
}

| TRUE {
  ($$).size = 1;
 strcpy(($$).lexeme,($1));
  strcpy(($$).type,"bool");
}

| FALSE {
  ($$).size = 1;
 strcpy(($$).lexeme,($1));
  strcpy(($$).type,"bool");
}

;


comma_test:

COMMA test comma_test

|/*epsilon*/

;


trailer: 

LEFTPARANTHESIS test comma_test RIGHTPARANTHESIS 

| LEFTPARANTHESIS RIGHTPARANTHESIS

| DOT NAME 

| DOT NAME LEFTPARANTHESIS RIGHTPARANTHESIS 

| DOT NAME LEFTPARANTHESIS test comma_test RIGHTPARANTHESIS

;


classdef: 

CLASS NAME COLON suite

| CLASS NAME LEFTPARANTHESIS RIGHTPARANTHESIS COLON suite

| CLASS NAME LEFTPARANTHESIS test comma_test RIGHTPARANTHESIS COLON suite

;



%%



int main(int argc, char *argv[])

{

FILE *fp;

    char* filename = argv[1];

    fp = fopen(filename,"r");

    yyin = fp;



  yyparse();

if(!errors.empty()){
  cout<<"Errors are:\n";
  while(!errors.empty()){
    string errr= errors.front();
    errors.pop();
    cout<< errr<<endl;
  }
}

  return 0;

}



void yyerror(const char * s)

{

	printf("Error in line %d: %s, %s\n",yylineno,s,yytext);



  exit(0);

}


