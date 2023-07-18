%{
    int countn=0;
    int countOfFormatSpecifiers(const char *str){
        int count = 0;
        const char *tmp = str;
        while(tmp = strstr(tmp, "%"))
        {
            count++;
            tmp++;
        }
        return count;
    }
    int countOfPrintfArguments(const char *str){
        int count = 0;
        const char *tmp = str;
        tmp = strstr(tmp, "\"");
        tmp++;
        tmp = strstr(tmp, "\"");
        tmp++;    
        while(tmp = strstr(tmp, ","))
        {
            count++;
            tmp++;
        }
        return count;
    }
%}


alpha [a-zA-Z]
digit [0-9]
unary "++"|"--"
printf "printf"

%%

{printf}\(["].*["]\)\;      {  
                                printf("%d\t%s\t%s\n",countn,yytext,"PRINTF"); 
                            }
{printf}\(["].*["](,{alpha}({alpha}|{digit})*)*\)\;      {  
                                printf("%d\t%s\t%s\n",countn,yytext,"PRINTF"); 
                                int formatSpecifierCount=countOfFormatSpecifiers(yytext);
                                int argumentCount=countOfPrintfArguments(yytext);
                                if(formatSpecifierCount!=argumentCount){
                                    printf("Error: Number of format specifiers and arguments do not match\n");
                                }
                            }
"scanf"                     {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"SCANF"); 
                            }
"int"                       {
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"INT"); 
                            }
"float"                     {
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"FLOAT"); 
                            }
"char"                      {
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"CHAR"); 
                            }
"void"                      {
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"VOID"); 
                            }
"switch"                    {
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"SWITCH"); 
                            }
"case"                      {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"CASE"); 
                            }
"default"                   {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"DEFAULT"); 
                            }
"main"                      {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"MAIN"); 
                            }
"return"                    {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"RETURN"); 
                            }
"for"	                    {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"FOR"); 
                            }
"while"                     {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"WHILE"); 
                            }
"if"	                    {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"IF"); 
                            }
"else"	                    {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"ELSE"); 
                            }
"true"                      {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"TRUE"); 
                            }
"false"                     {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"FALSE"); 
                            }
"break"                     {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"BREAK"); 
                            }
"continue"                  {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"CONTINUE"); 
                            }
{digit}+                {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"INTEGER"); 
                            }
{digit}+\.{digit}{1,6}  {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"FLOAT"); 
                            } 
[?\-0-9][0-9]*?.[0-9]+E[?\-0-9][0-9]* {
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"EXPONENT");
                                        }
{alpha}({alpha}|{digit})*   {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"IDENTIFIER"); 
                            }
"["                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"LSQBRACKET"); 
                            }
"]"                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"RSQBRACKET");
                            }
"{"                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"LBRACE"); 
                            }
"}"                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"RBRACE"); 
                            }
"("                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"LPAREN"); 
                            }
")"                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"RPAREN"); 
                            }
";"                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"SEMICOLON"); 
                            }
","                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"COMMA"); 
                            }
":"                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"COLON"); 
                            }
"!"                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"NOT"); 
                            }
"%"                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"MOD"); 
                            }
"="                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"ASSIGN"); 
                            }
"<="                        {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"LE"); 
                            }
">="                        {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"GE"); 
                            }
"=="                        {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"EQ"); 
                            }
"!="                        {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"NE"); 
                            }
">"	                        {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"GT"); 
                            }
"<"	                        {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"LT"); 
                            }
"&&"	                    {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"AND"); 
                            }
"||"	                    {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"OR");}
"+"                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"PLUS");}
"-"                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"MINUS"); 
                            }
"/"                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"DIV"); 
                            }
"*"                         {  
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"MUL"); 
                            }
\/\/.*                      { 
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"SINGLELINECOMMENT");
                            }
\/\*(.*\n)*.*\*\/           { 
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"MULTILINECOMMENT");
                            }
[\n]                        { 
                                printf("%d\t\t%s\t\t%s\n",countn,"\\n","NEWLINE");    
                                countn++;
                            }
[ \t]*                      { 
                                printf("%d\t\t%s\t\t%s\n",countn,"\\t","WHITESPACE"); 
                            }
.	                        { 
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"INVALID"); 
                            }
["].*["]                    { 
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"STRING"); 
                            }
['].[']                     { 
                                printf("%d\t\t%s\t\t%s\n",countn,yytext,"CHAR"); 
                            }                   

%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    printf("\nLINE NUMBER        LEXEME        TOKEN TYPE    \n");
    printf("-------------------------------------------------\n");
    yylex();
    return 0;
}
