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
%option case-insensitive

name	[A-Za-z][A-Za-z0-9_]*
left	[(][/]
right 	[/][)]
integer [1-9][0-9]*|0
zto9 [0-9]
oto9 [1-9]

%%


(?i:allocatable)|(?i:allocate)|(?i:assign)|(?i:associate)|(?i:asynchronous)|(?i:backspace)|(?i:bind)|(?i:call)|(?i:case)|(?i:class)|(?i:close)|(?i:common)|(?i:contains)|(?i:continue)|(?i:cycle)|(?i:codimension)|(?i:contiguous)|(?i:critical)|(?i:data)|(?i:deallocate)|(?i:deferred)|(?i:dimension)|(?i:do)|(?i:else)|(?i:elsewhere)|(?i:end)|(?i:endfile)|(?i:endif)|(?i:entry)|(?i:equivalence)|(?i:exit)|(?i:external)|(?i:enum)|(?i:enumerator)|(?i:extends)|(?i:forall)|(?i:final)|(?i:flush)|(?i:format)|(?i:function)|(?i:goto)|(?i:generic)|(?i:import)|(?i:if)|(?i:implicit)|(?i:inquire)|(?i:intrinsic)|(?i:include)|(?i:interface)|(?i:intent)|(?i:lock)|(?i:module)|(?i:nopass)|(?i:namelist)|(?i:nullify)|(?i:open)|(?i:only)|(?i:operator)|(?i:optional)|(?i:parameter)|(?i:pause)|(?i:print)|(?i:program)|(?i:pointer)|(?i:private)|(?i:pass)|(?i:protected)|(?i:procedure)|(?i:public)|(?i:read)|(?i:return)|(?i:recursive)|(?i:result)|(?i:rewind)|(?i:rewrite)|(?i:save)|(?i:stop)|(?i:subroutine)|(?i:select)|(?i:sequence)|(?i:submodule)|(?i:target)|(?i:then)|(?i:use)|(?i:value)|(?i:unlock)|(?i:volatile)|(?i:while)|(?i:write) {  
	
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

!.*\n     /* Ignoring comments */

\"([^'"\\]|\\.)*\" {  /* Handling double-quoted strings */
    if(flag==0){
        if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="CHAR_LITERAL";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="CHAR_LITERAL";
    	}
    	else{
    		mp[yytext].first++;
    	}
    }
}

"\""{name}|{name}"\""|"\""{name}"'"|"\""{name}"'"{name}"\"" {
    flag=1;
    fprintf(stderr, "Error: Illegal string '%s' at line %d.\n", yytext, yylineno);
}

".true."|".false."    {
	if(flag==0){
		int tempkey=1;
			
		if(mp.begin()==mp.end()) {mp[yytext].first=tempkey; mp[yytext].second="LOGICAL_LITERAL";}
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
		         mp[yytext].second="LOGICAL_LITERAL";
		      }				
		}
	}
}

"_"{name} {
    flag=1;
    fprintf(stderr, "Error: Illegal name '%s' at line %d.\n", yytext, yylineno);
}

[ \t\n\r\f]+   /* Ignoring white spaces */

\[|\]|\(|\)|{left}|{right}       { /*Handling delimiters*/
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

[+-]?"0."{zto9}+|[+-]?{oto9}{zto9}*"."{zto9}+|[+-]?"0."{zto9}*"E"[+-]?{zto9}+|[+-]?"0."{zto9}*"D"[+-]?{zto9}+|[+-]?{oto9}{zto9}*"E"[+-]?{zto9}+|[+-]?{oto9}{zto9}*"D"[+-]?{zto9}+|[+-]?"0E"[+-]?{zto9}+|"0D"[+-]?{zto9}+|[+-]?{oto9}{zto9}*"."{zto9}*"E"[+-]?{zto9}+|[+-]?{oto9}{zto9}*"."{zto9}*"D"[+-]?{zto9}+|[+-]?"."{zto9}+|[+-]?"."{zto9}+"E"[+-]?{zto9}+|[+-]?"."{zto9}+"D"[+-]?{zto9}+ {
    if(flag==0){
    if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="REAL_LITERAL";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="REAL_LITERAL";
    	}
    	else{
    		mp[yytext].first++;
    	}
    }
}

[-]?{oto9}{zto9}*|0     {  
    if(flag==0){
    if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="INT_LITERAL";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="INT_LITERAL";
    	}
    	else{
    		mp[yytext].first++;
    	}
    }
}

[0][0-9]+|0x[0][0-9]+|[1-9][0-9]*[.][0-9][0-9][0-9][0-9][0-9][0-9][0-9]+	{
	//flag=1;
	fprintf(stderr, "Error: Invalid number at line %d.\n", yylineno);
        //exit(EXIT_FAILURE);
}
0x[1-9A-Fa-f][0-9A-Fa-f]*|0x0 {  /* Handling hexadecimal literals */
    if(flag==0){
    if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="INT_LITERAL";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="INT_LITERAL";
    	}
    	else{
    		mp[yytext].first++;
    	}
    }
}

".eq."|".ne."|".lt."|".le."|".gt."|".ge."|".not."|".and."|".or."|".eqv."|".neqv."	{
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

\+|\-|\*|"//"|\%|\^|"**"|\*|"/="|\/|"=="|\=|"<="|"<<"|\<|">="|">>"|"&&"|"||"|\&|\> {  /* Handling other operators */
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

{name} {  /* Handling names */
    if(flag==0){
		int tempkey=1;
			
		if(mp.begin()==mp.end()) {mp[yytext].first=tempkey; mp[yytext].second="NAME";}
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
		         mp[yytext].second="NAME";
		      }				
		}
	}
}

\{|\}|\,|\:|\;|\!|\^|\~|\`|\?|\||\$|\#|\@|\\|\'|\.  { /* Handling special characters */
    if(flag==0){
    if(mp.begin()==mp.end()) {mp[yytext].first=1; mp[yytext].second="SPECIAL_CHAR";}
    	else if(mp.find(yytext)==mp.end()){
    		mp[yytext].first=1;
    		mp[yytext].second="SPECIAL_CHAR";
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

