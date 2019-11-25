%{
#include<stdio.h>
#include"y.tab.h"
extern char name[21];
extern int Line;
%}

D [0-9] 
L [a-zA-Z]
A [a-zA-Z_0-9]
P {D}+\.{D}+
%%
"include" {return INCLUDE;}
"define" {return DEFINE;}
"int" {return INT;}
"char" {return CHAR;}
"float" {return FLOAT;}
"void" {return VOID;}
"for" {return FOR;}
"if"  {return IF;}
"while" {return WHILE;}
"do" {return DO;}
"return" {return RETURN;}
"auto" 	{return AUTO;}
"break"	{return(BREAK); }
"case"	{return(CASE); }
"const"	 {return(CONST); }
"continue" {return(CONTINUE); }
"default" {return(DEFAULT);}
"double" {return(DOUBLE); }
"else"	{ return(ELSE); }
"enum"	 { return(ENUM); }
"extern" { return(EXTERN); }
"goto"	{ return(GOTO); }
"long"	 { return(LONG); }
"register" { return(REGISTER); }
"short"	 { return(SHORT); }
"signed" { return(SIGNED); }
"static" { return(STATIC); }
"struct" { return STRUCT; }
"switch" { return SWITCH; }
"typedef" { return TYPEDEF; }
"union"	 { return UNION; }
"unsigned" { return UNSIGNED; }
"volatile" { return VOLATILE;}
L?\"(\\.|[^\\"])*\" {return LITERAL;}
"->" {return POINTER;}
"&&" {return AND;}
"||" {return OR;}
"==" {return EQUAL;}
"sizeof" {return SIZE;}
"!=" {return DIFF;}
"<=" {return RREL;}
">=" {return LREL;}
"+=" {return ADDE;}
"-=" {return SUBE;}
"/=" {return DIVE;}
"*=" {return MULE;}
"%=" {return QUEE;}
">>=" {return RIGHTE;}
"<<=" {return LEFTE;}
"^=" {return XORE; }
"|=" {return ORE;}
"&=" {return ANDE;}
"<<" {return LSHF;}
">>" {return RSHF;}
{D}+ |
 {P}+   {return NUMBER;}
0(X|x)({D}+|{P}+)  {return NUMBER;}  
"++" {return PP;}
"--" {return MM;}
[;,\[\]&{}=*()\-\\#^!><|/~%~+.:?] {return yytext[0];}
{L}{A}* { strcpy(name,yytext);  return IDENTIFIER;}
[\t\v\f] {}
\n 	{Line++;}
.	{}
%%

int yywrap(){
	return 1;
}

