%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include<map>
#include<iostream>
#include <cstring>

using namespace std;

map<string,pair<int,string>> mp;
int flag=0;

%}

%option noyywrap
%option yylineno

identifier  [A-Za-z][A-Za-z0-9]*
%%


(?i:ARRAY)|(?i:BEGIN)|(?i:BOOLEAN)|(?i:COMMENT)|(?i:CONTINUE)|(?i:DO)|(?i:DOUBLE)|(?i:ELSE)|(?i:END)|(?i:FALSE)|(?i:FOR)|(?i:IF)|(?i:INTEGER)|(?i:LABEL)|(?i:LIST)|(?i:LONG)|(?i:OWN)|(?i:PROCEDURE)|(?i:STEP)|(?i:SWITCH)|(?i:THEN)|(?i:TRUE)|(?i:UNTIL)|(?i:VALUE)|(?i:WHILE) {  
	
	if(flag==0){
		int tempkey=1;
			
		if(mp.begin()==mp.end()) {mp[yytext].first=tempkey; mp[yytext].second="KEYWORD";}
		else {
			for(auto& it:mp){
			int l=(it.first).length();
			char* char_array = new char[l+1]; 
			strcpy(char_array, (it.first).c_str()); 
			
			if(strcasecmp(char_array,yytext)==0){
				it.second.first++;
				tempkey=it.second.first;				
				}
				
			delete[] char_array; 
			
		      }
		      		      
		      if(mp.find(yytext)==mp.end()){
		      	 mp[yytext].first=tempkey;
		         mp[yytext].second="KEYWORD";
		      }				
		}
	}	
}

"{"[^}]*"}"   /* Ignoring comments */

\'([^"'\\]|\\.)*\' {  /* Handling single-quoted strings */

    if(flag==0){
    	if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="STRING";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="STRING";
    	}
    	else{
    		mp[yytext].first++;
    	}
    }
}

\"([^'"\\]|\\.)*\" {  /* Handling double-quoted strings */
    if(flag==0){
        if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="STRING";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="STRING";
    	}
    	else{
    		mp[yytext].first++;
    	}
    }
}

\"(([^"']"'")|("'"[^"'])|("'"[^"']"'"))*\"  {
    flag=1;
    fprintf(stderr, "Error: Ill-formed string '%s' at line %d.\n", yytext, yylineno);	
}

"'"{identifier}|{identifier}"'"|"\""{identifier}|{identifier}"\""|"'"{identifier}"\""|"\""{identifier}"'"|"'"{identifier}"\""{identifier}"'"|"\""{identifier}"'"{identifier}"\"" {
    flag=1;
    fprintf(stderr, "Error: Ill-formed string '%s' at line %d.\n", yytext, yylineno);
}

[ \t\n\r\f]+   /* Ignoring white spaces */

\;|\:|\,|\[|\]|\{|\}|\(|\)          { 
    if(flag==0){
        if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="DELIMITER";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="DELIMITER";
    	}
    	else{
    		mp[yytext].first++;
    	}
    }
}


[1-9][0-9]*|0        {  /* Handling integer literals */
    if(flag==0){
    if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="INTEGER";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="INTEGER";
    	}
    	else{
    		mp[yytext].first++;
    	}
    }
}
[0][0-9]+|0x[0][0-9]+|[1-9][0-9]*[.][0-9][0-9][0-9][0-9][0-9][0-9][0-9]+|0[.][0-9][0-9][0-9][0-9][0-9][0-9][0-9]+	{
	//flag=1;
	fprintf(stderr, "Error: Invalid number at line %d.\n", yylineno);
        //exit(EXIT_FAILURE);
}
0x[1-9A-Fa-f][0-9A-Fa-f]*|0x0 {  /* Handling hexadecimal literals */
    if(flag==0){
    if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="HEXADECIMAL";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="HEXADECIMAL";
    	}
    	else{
    		mp[yytext].first++;
    	}
    }
}

[1-9][0-9]*[.][0-9][0-9][0-9][0-9][0-9][0-9]|0[.][0-9][0-9][0-9][0-9][0-9][0-9] {
    if(flag==0){
    if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="FLOATING_POINT";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="FLOATING_POINT";
    	}
    	else{
    		mp[yytext].first++;
    	}
    }
    
}

":="           {  /* Handling assignment operator */
    if(flag==0){
    if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="OPERATOR";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="OPERATOR";
    	}
    	else{
    		mp[yytext].first++;
    	}
    }
}

(?i:and)|(?i:or)|(?i:leq)|(?i:lt)|(?i:geq)|(?i:gt)|(?i:not)|(?i:eql)|(?i:neq) 	{
	if(flag==0){
		int tempkey=1;
			
		if(mp.begin()==mp.end()) {mp[yytext].first=tempkey; mp[yytext].second="OPERATOR";}
		else {
			for(auto& it:mp){
			int l=(it.first).length();
			char* char_array = new char[l+1]; 
			strcpy(char_array, (it.first).c_str()); 
			
			if(strcasecmp(char_array,yytext)==0){
				it.second.first++;
				tempkey=it.second.first;				
				}
				
			delete[] char_array; 
			
		      }
		      		      
		      if(mp.find(yytext)==mp.end()){
		      	 mp[yytext].first=tempkey;
		         mp[yytext].second="OPERATOR";
		      }				
		}
	}
}

\+|\-|\*|\/|\%|\^|\||\&|<=|>=|>>|<< {  /* Handling other operators */
    if(flag==0){
    if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="OPERATOR";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="OPERATOR";
    	}
    	else{
    		mp[yytext].first++;
    	}
    }
}

{identifier} {  /* Handling identifiers */
    if(flag==0){
    if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="IDENTIFIER";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="IDENTIFIER";
    	}
    	else{
    		mp[yytext].first++;
    	}
    }
}

. {
	flag=1;
    fprintf(stderr, "Error: Illegal character '%s' at line %d.\n", yytext, yylineno);
    //exit(EXIT_FAILURE);
}

%%

//int yywrap(){}
int main() {
    FILE *fp;
    char filename[50];
    printf("Enter the filename: \n");
    scanf("%s",filename);
    fp = fopen(filename,"r");
    yyin = fp;
    yylex();
    cout<<"All valid tokens and lexemes before first error are:\n";
    cout<<"TOKEN COUNT\tLEXEME\n";
    
    for(auto it1:mp){
    	cout<<it1.second.second<<" "<<it1.second.first<<"\t"<<it1.first<<endl;
    }
    if(flag==0) cout<<"There is no error\n";
    return 0;
}

