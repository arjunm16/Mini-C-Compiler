%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
void yyerror(const char *s);
    int yylex();
    int yywrap();
%}
 
%union { struct var_name { 
            char name[100]; 
            struct node* nd;
        } nd_obj;
 
        struct var_name2 { 
            char name[100]; 
            struct node* nd;
            char type[5];
        } nd_obj2; 
 
        struct var_name3 {
            char name[100];
            struct node* nd;
            char if_body[5];
            char else_body[5];
        } nd_obj3;

        struct var_name4 { 
            char name[100]; 
            struct node* nd;
            int sz;
        } nd_obj_arr;   //change
 
        struct var_name5 { 
            char name[100]; 
            struct node* nd;
            int sz;
            int each_list_sz;
        } nd_obj_arr2;   //change
    } 
 
%token <nd_obj> VOID 
%token <nd_obj> INT FLOAT CHAR
%token <nd_obj> IF ELSE FOR WHILE SWITCH CASE DEFAULT PRINTF SCANF RETURN TRUE FALSE INCLUDE STR STRCONST FLOAT_NUM EXPONENT
%token <nd_obj> MAIN
%token <nd_obj> ID
%token <nd_obj> BREAK CONTINUE
%token <nd_obj> NUMBER
%token <nd_obj> CHARACTER
%token <nd_obj> ASSIGNMENT
%token <nd_obj> NOT AND OR
%token <nd_obj> EQ NE LT LE GT GE
%token <nd_obj> ADD SUB MUL DIV MOD
%token <nd_obj> LSQBRACKET RSQBRACKET LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA COLON
 
%start program
%type<nd_obj> program datatype functions function loop_stat_list calling_list program_body main arglist plist args statement_list statement arr_dec declaration_statement type_specifier var_list assignment_statement assignment_statement_2 print if_statement for_statement while_statement switch_statement switch_case_list switch_case return_statement compound_statement for_initializer for_condition for_update
%type<nd_obj> logical_o_exp logical_a_exp relational_exp additive_exp multiplicative_exp negation_exp access_call_exp primary_exp constant  expression_statement
%type<nd_obj> number_list character_list float_num_list stringconst //change
%type<nd_obj> stringconst_list multiple_num_list multiple_character_list multiple_float_num_list braced_num_list braced_character_list braced_float_num_list
%%
program:
        program_body    
    
datatype:
        INT     
        | FLOAT 
        | CHAR  
        | VOID  
;
 
program_body:
        functions   
    
functions:
        function    
        | main      
    
function: 
        datatype ID  LPAREN arglist RPAREN LBRACE statement_list  RBRACE functions
                                                            
    
arglist:
        type_specifier ID       
        |  type_specifier ID args                   
        |                       
        ;
 
args:
        COMMA type_specifier ID  args   
        |   COMMA type_specifier ID 
        ;
 
main:
        datatype MAIN LPAREN RPAREN compound_statement  
        ;
 
statement_list:
        statement                       
        |   statement statement_list    
        |                               
        ;
 
statement:
    declaration_statement                         
        |   assignment_statement_2 SEMICOLON    
        |   expression_statement SEMICOLON      
        |   if_statement                        
        |   for_statement                       
        |   while_statement                     
        |   switch_statement                    
        |   return_statement                    
        |   compound_statement                  
        |   print                               
        |   SEMICOLON                          
        ;


calling_list:
        ID  
        |   ID COMMA calling_list 
        |  constant COMMA calling_list
        |  constant 
        ;

declaration_statement:
        type_specifier var_list SEMICOLON   
 
type_specifier:
        INT         
        |   FLOAT   
        |   CHAR    
        ;
 
var_list: 
        ID                                      
        |   ID COMMA var_list    
        |   assignment_statement                
        |   assignment_statement COMMA var_list 
        |   arr_dec                             
        |   arr_dec COMMA var_list              
        ;
 
arr_dec:
        ID LSQBRACKET NUMBER RSQBRACKET         
        |   ID LSQBRACKET RSQBRACKET ASSIGNMENT LBRACE number_list RBRACE  
        |   ID LSQBRACKET RSQBRACKET ASSIGNMENT LBRACE character_list RBRACE    
        |   ID LSQBRACKET RSQBRACKET ASSIGNMENT stringconst 
        |   ID LSQBRACKET RSQBRACKET ASSIGNMENT LBRACE float_num_list RBRACE   
        |   ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE number_list RBRACE    
        |   ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE character_list RBRACE 
        |   ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT stringconst  
        |   ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE float_num_list RBRACE 
        |   ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET 
        |   ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_num_list                                                        
        |   ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_character_list
        |   ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE stringconst_list RBRACE                                                               
        |   ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_float_num_list                                                               
        |   ID LSQBRACKET RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_num_list                                                             
        |   ID LSQBRACKET RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_character_list                                                            
        |   ID LSQBRACKET RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE stringconst_list RBRACE                                                              
        |   ID LSQBRACKET RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_float_num_list                                                                
        ;
    
multiple_num_list:
        LBRACE number_list RBRACE   
        |   LBRACE braced_num_list RBRACE   
        ;
    
multiple_character_list:
        LBRACE character_list RBRACE   
        |   LBRACE braced_character_list RBRACE 
        ;
    
multiple_float_num_list:
        LBRACE float_num_list RBRACE    
        |   LBRACE braced_float_num_list RBRACE 
        ;
    
braced_num_list:
        LBRACE number_list RBRACE   
        |   LBRACE number_list RBRACE COMMA braced_num_list
        ;
    
braced_character_list:
        LBRACE character_list RBRACE    
        |   LBRACE character_list RBRACE COMMA braced_character_list  
        ;
    
braced_float_num_list:
        LBRACE float_num_list RBRACE 
        |   LBRACE float_num_list RBRACE COMMA braced_float_num_list  
        ;
 
number_list:
        NUMBER                         
        |   NUMBER COMMA number_list    
        ;
    
character_list:
        CHARACTER                           
        |   CHARACTER COMMA character_list 
        ;
stringconst_list:
        stringconst COMMA stringconst_list  
        | stringconst     
        ;

float_num_list:
        FLOAT_NUM                          
        |   FLOAT_NUM COMMA float_num_list  
        ;
    

assignment_statement:
        ID  ASSIGNMENT expression_statement   
        ;
 
expression_statement:
        expression_statement OR logical_o_exp   
        |   logical_o_exp                       
        ;
 
logical_o_exp:
        logical_o_exp AND logical_a_exp 
        |   logical_a_exp               
        ;
 
logical_a_exp:
        logical_a_exp EQ relational_exp     
        |   logical_a_exp NE relational_exp 
        |   relational_exp                  
        ;
 
relational_exp:
        relational_exp GT additive_exp      
        |   relational_exp GE additive_exp  
        |   relational_exp LT additive_exp  
        |   relational_exp LE additive_exp  
        |   additive_exp                    
        ;
 
additive_exp:
        additive_exp ADD multiplicative_exp     
        |   additive_exp SUB multiplicative_exp
        |   multiplicative_exp                  
        ;
 
multiplicative_exp:
        multiplicative_exp MUL negation_exp     
        |   multiplicative_exp DIV negation_exp
        |   multiplicative_exp MOD negation_exp 
        |   negation_exp                       
        ;
 
negation_exp:
        NOT access_call_exp 
        |   access_call_exp 
        ;
    
access_call_exp:
        access_call_exp LSQBRACKET NUMBER RSQBRACKET   
        |  access_call_exp LSQBRACKET ID RSQBRACKET
        |   primary_exp 
        |   access_call_exp LPAREN RPAREN  
        |   access_call_exp  LPAREN calling_list RPAREN  
        ;
 
primary_exp:
        LPAREN expression_statement RPAREN  
        |   ID                              
        |   constant                        
        ;
 
constant:
        NUMBER          
        | CHARACTER   
        | FLOAT_NUM    
        | EXPONENT       
        ;
 
if_statement:
        IF LPAREN expression_statement RPAREN compound_statement   
        |   IF LPAREN expression_statement RPAREN compound_statement ELSE compound_statement                                                                          
        ;
 
for_statement:
        FOR LPAREN for_initializer for_condition for_update RPAREN  LBRACE loop_stat_list RBRACE                                                                   
        ;
 
assignment_statement_2: ID ASSIGNMENT expression_statement  
        |  access_call_exp LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT expression_statement
        | access_call_exp LSQBRACKET ID RSQBRACKET ASSIGNMENT expression_statement
        ;
 
for_initializer:
        type_specifier ID  ASSIGNMENT expression_statement SEMICOLON   
        |   assignment_statement_2 SEMICOLON    
        |   SEMICOLON   
        ;
 
for_condition:
        expression_statement SEMICOLON 
        |   SEMICOLON   
        ;
 
for_update:
        assignment_statement_2 
        |
        ;
 
while_statement:
        WHILE LPAREN expression_statement RPAREN LBRACE loop_stat_list RBRACE    
        ;

loop_stat_list:
        statement   
        |   statement loop_stat_list    
        |   BREAK SEMICOLON 
        |   BREAK SEMICOLON loop_stat_list 
        |   CONTINUE SEMICOLON  
        |   CONTINUE SEMICOLON loop_stat_list  
        | 
        ;
 

switch_statement:
        SWITCH LPAREN expression_statement RPAREN LBRACE switch_case_list RBRACE 
        ;
 
switch_case_list:
        switch_case 
        |  switch_case switch_case_list   
        ;
 
switch_case:
        CASE constant COLON loop_stat_list  
        |   DEFAULT COLON loop_stat_list   
        ;
 
print: PRINTF LPAREN stringconst plist  RPAREN SEMICOLON    
        ;
 
stringconst: STR 
;
 
plist: COMMA ID 
    | COMMA ID plist 
    | ID LSQBRACKET NUMBER RSQBRACKET
    | ID LSQBRACKET NUMBER RSQBRACKET plist
    | constant
    | constant plist
    | 
    ;
 
return_statement:
        RETURN expression_statement SEMICOLON   
        |  RETURN SEMICOLON    
        ;
 
compound_statement:
        LBRACE statement_list RBRACE    
        ;
%%
 
int main() {
    yyparse();
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
    printf("Completed Lexical Analysis and Found No Errors \n\n");    
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
    printf("Completed Syntax Analysis and Found No Errors \n\n");
    printf("\n\n");
}
 
void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}