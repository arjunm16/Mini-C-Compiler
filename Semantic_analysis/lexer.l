%{
    #include "y.tab.h"
    int countn=0;
    extern YYSTYPE yylval;
%}
%option yylineno

alpha [a-zA-Z]
digit [0-9]
unary "++"|"--"

%%

"printf"                    { strcpy(yylval.nd_obj.name,(yytext)); return PRINTF; }
"scanf"                     { strcpy(yylval.nd_obj.name,(yytext)); return SCANF; }
"int"                       { strcpy(yylval.nd_obj.name,(yytext)); return INT; }
"float"                     { strcpy(yylval.nd_obj.name,(yytext)); return FLOAT; }
"char"                      { strcpy(yylval.nd_obj.name,(yytext)); return CHAR; }
"void"                      { strcpy(yylval.nd_obj.name,(yytext)); return VOID; }
"switch"                      { strcpy(yylval.nd_obj.name,(yytext)); return SWITCH; }
"case"                    { strcpy(yylval.nd_obj.name,(yytext)); return CASE; } 
"default"                      { strcpy(yylval.nd_obj.name,(yytext)); return DEFAULT; }
"main"                    { strcpy(yylval.nd_obj.name,(yytext)); return MAIN; }
"return"                    { strcpy(yylval.nd_obj.name,(yytext)); return RETURN; }
"for"	                    { strcpy(yylval.nd_obj.name,(yytext)); return FOR; }
"while"                     { strcpy(yylval.nd_obj.name,(yytext)); return WHILE; }
"if"	                    { strcpy(yylval.nd_obj.name,(yytext)); return IF; }
"else"	                    { strcpy(yylval.nd_obj.name,(yytext)); return ELSE; }
"true"                      { strcpy(yylval.nd_obj.name,(yytext)); return TRUE; }
"false"                     { strcpy(yylval.nd_obj.name,(yytext)); return FALSE; }
"break"                    { strcpy(yylval.nd_obj.name,(yytext)); return BREAK; }
"continue"                    { strcpy(yylval.nd_obj.name,(yytext)); return CONTINUE; }
{digit}+                { strcpy(yylval.nd_obj.name,(yytext)); return NUMBER; }
{digit}+\.{digit}{1,6}  { strcpy(yylval.nd_obj.name,(yytext)); return FLOAT_NUM; }
[?\-0-9][0-9]*?.[0-9]+E[?\-0-9][0-9]* { strcpy(yylval.nd_obj.name,(yytext)); return EXPONENT; }
{alpha}({alpha}|{digit})*   { strcpy(yylval.nd_obj2.name,(yytext)); return ID; }
"["                        { strcpy(yylval.nd_obj.name,(yytext)); return LSQBRACKET; }
"]"                        { strcpy(yylval.nd_obj.name,(yytext)); return RSQBRACKET; }
"{"                         { strcpy(yylval.nd_obj.name,(yytext)); return LBRACE; }
"}"                         { strcpy(yylval.nd_obj.name,(yytext)); return RBRACE; }
"("                         { strcpy(yylval.nd_obj.name,(yytext)); return LPAREN; }
")"                         { strcpy(yylval.nd_obj.name,(yytext)); return RPAREN; }
";"                         { strcpy(yylval.nd_obj.name,(yytext)); return SEMICOLON; }
","                         { strcpy(yylval.nd_obj.name,(yytext)); return COMMA; }
":"                         { strcpy(yylval.nd_obj.name,(yytext)); return COLON; }
"!"                         { strcpy(yylval.nd_obj.name,(yytext)); return NOT; }
"%"                         { strcpy(yylval.nd_obj.name,(yytext)); return MOD; }
"="                         { strcpy(yylval.nd_obj.name,(yytext)); return ASSIGNMENT; }
"<="                        { strcpy(yylval.nd_obj.name,(yytext)); return LE; }
">="                        { strcpy(yylval.nd_obj.name,(yytext)); return GE; }
"=="                        { strcpy(yylval.nd_obj.name,(yytext)); return EQ; }
"!="                        { strcpy(yylval.nd_obj.name,(yytext)); return NE; }
">"	                        { strcpy(yylval.nd_obj.name,(yytext)); return GT; }
"<"	                        { strcpy(yylval.nd_obj.name,(yytext)); return LT; }
"&&"	                    { strcpy(yylval.nd_obj.name,(yytext)); return AND; }
"||"	                    { strcpy(yylval.nd_obj.name,(yytext)); return OR; }
"+"                         { strcpy(yylval.nd_obj.name,(yytext)); return ADD; }
"-"                         { strcpy(yylval.nd_obj.name,(yytext)); return SUB; }
"/"                         { strcpy(yylval.nd_obj.name,(yytext)); return DIV; }
"*"                         { strcpy(yylval.nd_obj.name,(yytext)); return MUL; }
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        { countn++; }
.	                        { return *yytext; }
["][^"]*["]                    { strcpy(yylval.nd_obj.name,(yytext)); return STR; }
['].[']                     { strcpy(yylval.nd_obj.name,(yytext)); return CHARACTER; }

%%

int yywrap() {
    return 1;
}