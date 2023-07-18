%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
void yyerror(const char *s);
    int yylex();
    int yywrap();
    void add(char);
    int search(char *);
    int searchLocal(char *);
    void insert_type();
    void print_tree(struct node*);
    void print_inorder(struct node *);
    int check_declaration(char *);
    void check_return_type(char *);
    int check_types(char *, char *);
    char *get_type(char *);
    int isArray(char *);
    void addArgument(char *,char *);
    void check_Argument(char *);
    void checkFinalArguments(char *);
    void clearFormatSpecifierList();
    struct node* mknode(struct node *left, struct node *right, char *token);
    
    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
        int rows;
        int columns;
        int functionCallArguments[10];
        int arg_count;
    } symbol_table[40];
 
    struct dataType symbol_table_global[50][40];
    int currentScope_global=0;
    int countStorage[50]={0};
    int countStorageIndex=0;

    int count=0;

    void clearGlobalTable(struct dataType symbol_table_global[50][40],int currentScope_global){
        int i=0;
        for(i=0;i<40;i++){
            symbol_table_global[currentScope_global][i].id_name=NULL;
            symbol_table_global[currentScope_global][i].data_type=NULL;
            symbol_table_global[currentScope_global][i].type=NULL;
            symbol_table_global[currentScope_global][i].line_no = 0;
            symbol_table_global[currentScope_global][i].rows = 0;
            symbol_table_global[currentScope_global][i].columns = 0;
            for(int j=0;j<10;j++){
                symbol_table_global[currentScope_global][i].functionCallArguments[j]=0;
            }
            symbol_table_global[currentScope_global][i].arg_count=0;
        }
        count=0;
    }

    void printGlobalSymbolTable(struct dataType symbol_table_global[50][40],int currentScope_global){
        printf("Printing Global Symbol Table\n");
        int i=0;
        for(i=0;i<40;i++){
            if(symbol_table_global[currentScope_global][i].id_name!=NULL){
                printf("id_name is %s\n",symbol_table_global[currentScope_global][i].id_name);
                printf("data_type is %s\n",symbol_table_global[currentScope_global][i].data_type);
                printf("type is %s\n",symbol_table_global[currentScope_global][i].type);
                printf("line_no is %d\n",symbol_table_global[currentScope_global][i].line_no);
                printf("rows is %d\n",symbol_table_global[currentScope_global][i].rows);
                printf("columns is %d\n",symbol_table_global[currentScope_global][i].columns);
                printf("arg_count is %d\n",symbol_table_global[currentScope_global][i].arg_count);
                printf("functionCallArguments are ");
                for(int j=0;j<10;j++){
                    printf("%d ",symbol_table_global[currentScope_global][i].functionCallArguments[j]);
                }
                printf("\n");
            }
        }
    }

    void clearLocalTable(){
        int i=0;
        for(i=0;i<40;i++){
            symbol_table[i].id_name=NULL;
            symbol_table[i].data_type=NULL;
            symbol_table[i].type=NULL;
            symbol_table[i].line_no = 0;
            symbol_table[i].rows = 0;
            symbol_table[i].columns = 0;
            for(int j=0;j<10;j++){
                symbol_table[i].functionCallArguments[j]=0;
            }
            symbol_table[i].arg_count=0;
        }
        count=0;
    }

    void nextTable(){
        int i=0;
        printf("Inside nextTable\n");
        for(i=0;i<count;i++){
            symbol_table_global[currentScope_global][i].id_name=(char *)malloc(sizeof(char)*strlen(symbol_table[i].id_name));
            symbol_table_global[currentScope_global][i].data_type=(char *)malloc(sizeof(char)*strlen(symbol_table[i].data_type));
            symbol_table_global[currentScope_global][i].type=(char *)malloc(sizeof(char)*strlen(symbol_table[i].type));
            strcpy(symbol_table_global[currentScope_global][i].id_name, symbol_table[i].id_name);
            strcpy(symbol_table_global[currentScope_global][i].data_type, symbol_table[i].data_type);
            strcpy(symbol_table_global[currentScope_global][i].type, symbol_table[i].type);
            symbol_table_global[currentScope_global][i].line_no = symbol_table[i].line_no;
            symbol_table_global[currentScope_global][i].rows = symbol_table[i].rows;
            symbol_table_global[currentScope_global][i].columns = symbol_table[i].columns;
            // printf("%s\n",symbol_table_global[currentScope_global][i].id_name);
            for(int j=0;j<10;j++){
                symbol_table_global[currentScope_global][i].functionCallArguments[j]=symbol_table[i].functionCallArguments[j];
                // printf("%d ",symbol_table_global[currentScope_global][i].functionCallArguments[j]);
            }
            // printf("\n");
            symbol_table_global[currentScope_global][i].arg_count=symbol_table[i].arg_count;
            // printf("%d\n",symbol_table_global[currentScope_global][i].arg_count);
        }
        printGlobalSymbolTable(symbol_table_global,currentScope_global);
        currentScope_global++;
        countStorage[countStorageIndex++]=count;
        clearLocalTable();
        // clearGlobalTable(symbol_table_global,currentScope_global);
    }

    void prevTable(){
        printf("In prevTable\n");
        clearGlobalTable(symbol_table_global,currentScope_global);
        currentScope_global--;
        countStorageIndex--;
        count=countStorage[countStorageIndex];
        int i=0;
        for(i=0;i<count;i++){
            symbol_table[i].id_name=(char *)malloc(sizeof(char)*strlen(symbol_table_global[currentScope_global][i].id_name));
            symbol_table[i].data_type=(char *)malloc(sizeof(char)*strlen(symbol_table_global[currentScope_global][i].data_type));
            symbol_table[i].type=(char *)malloc(sizeof(char)*strlen(symbol_table_global[currentScope_global][i].type));
            strcpy(symbol_table[i].id_name, symbol_table_global[currentScope_global][i].id_name);
            strcpy(symbol_table[i].data_type, symbol_table_global[currentScope_global][i].data_type);
            strcpy(symbol_table[i].type, symbol_table_global[currentScope_global][i].type);
            symbol_table[i].line_no = symbol_table_global[currentScope_global][i].line_no;
            symbol_table[i].rows = symbol_table_global[currentScope_global][i].rows;
            symbol_table[i].columns = symbol_table_global[currentScope_global][i].columns;
            // printf("%s\n",symbol_table[i].id_name);
            for(int j=0;j<10;j++){
                symbol_table[i].functionCallArguments[j]=symbol_table_global[currentScope_global][i].functionCallArguments[j];
            }
            symbol_table[i].arg_count=symbol_table_global[currentScope_global][i].arg_count;
            // printf("%d\n",symbol_table[i].arg_count);
        }     
        printGlobalSymbolTable(symbol_table_global,currentScope_global);
              
    }

    int FormatSpecifierList[50]={-1};
    int FormatSpecifierListIndex=0;
    int currentPrintfArgumentIndex=0;

    void clearFormatSpecifierList(){
        for(int i=0;i<50;i++){
            FormatSpecifierList[i]=-1;
        }
        FormatSpecifierListIndex=0;
    }

    int countOfFormatSpecifiers(const char *str){
        const char *tmp = str;
        while(tmp = strstr(tmp, "%"))
        {
            if(tmp[1]=='c'){
                FormatSpecifierList[FormatSpecifierListIndex++]=1;
            }
            else if(tmp[1]=='d'){
                FormatSpecifierList[FormatSpecifierListIndex++]=2;
            }
            else if(tmp[1]=='f'){
                FormatSpecifierList[FormatSpecifierListIndex++]=3;
            }
            tmp++;
        }
        printf("FormatSpecifierList is : ");
        for(int i=0;i<FormatSpecifierListIndex;i++){
            printf("%d ",FormatSpecifierList[i]);
        }
    }

    int q;
    char type[10];
    extern int countn;
    struct node *head;
    int sem_errors=0;
    int ic_idx=0;
    int temp_var=0;
    int label=0;
    int is_if = 0;
    int is_for = 0;
    // int for_up = 0;
    int arr_en = 0;
    char buff[100];
    char errors[10][100];
    char reserved[10][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "include"};
    char icg[50][100];
    char currentFunction[100];    
    int currentArgumentIndex=0;
    char *stringTemp;
    struct node { 
        struct node *left; 
        struct node *right; 
        char *token; 
    };
 
%}
 
%union { struct var_name { 
            char name[100]; 
            struct node* nd;
            int t;
        } nd_obj;
 
        struct var_name2 { 
            char name[100]; 
            struct node* nd;
            char type[5];
            int t;
        } nd_obj2; 
 
        struct var_name3 {
            char name[100];
            struct node* nd;
            int t;
            char type[5];
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
%token <nd_obj2> ID
%token <nd_obj> BREAK CONTINUE
%token <nd_obj> NUMBER
%token <nd_obj> CHARACTER
%token <nd_obj> ASSIGNMENT
%token <nd_obj> NOT AND OR
%token <nd_obj> EQ NE LT LE GT GE
%token <nd_obj> ADD SUB MUL DIV MOD
%token <nd_obj> LSQBRACKET RSQBRACKET LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA COLON
 
%start program
%type<nd_obj> EL_statement program datatype functions function loop_stat_list calling_list program_body main arglist plist args statement_list statement arr_dec declaration_statement type_specifier var_list assignment_statement assignment_statement_2 print if_statement for_statement while_statement switch_statement switch_case_list switch_case return_statement compound_statement for_initializer for_update
%type<nd_obj3> for_condition logical_o_exp logical_a_exp relational_exp additive_exp multiplicative_exp negation_exp access_call_exp primary_exp constant expression_statement
%type<nd_obj_arr> number_list character_list float_num_list stringconst //change
%type<nd_obj_arr2> stringconst_list multiple_num_list multiple_character_list multiple_float_num_list braced_num_list braced_character_list braced_float_num_list
%%
program:
        program_body    { 
                            $$.nd = mknode($1.nd, NULL, "program"); 
                            head = $$.nd;
                        }
    
datatype:
        INT     {   insert_type();  }
        | FLOAT {   insert_type();  }
        | CHAR  {   insert_type();  }
        | VOID  {   insert_type();  }
;
 
program_body:
        functions   {   $$.nd = mknode($1.nd, NULL, "program_body"); }
    
functions:
        function    {   $$.nd = mknode($1.nd, NULL, "function");    }
        | main      {   $$.nd = mknode($1.nd, NULL, "function");    }
    
function: 
        datatype ID {   strcpy(yytext, $2.name); 
                        add('F'); 
                        strcpy(currentFunction, $2.name);
         } LPAREN { 
            nextTable();
        } arglist RPAREN LBRACE statement_list  RBRACE
        {
            prevTable();
        } functions
                                                            { 
                                                                $1.nd = mknode(NULL, NULL, $1.name);
                                                                $2.nd = mknode($6.nd, $9.nd, $2.name);
                                                                struct node *temp = mknode($1.nd, $2.nd, "function_body");
                                                                $$.nd = mknode(temp, $12.nd, "function");
                                                            }
    
arglist:
        type_specifier ID       {
                                    $2.nd = mknode(NULL, NULL, $2.name);
                                    yytext = malloc(sizeof(char) * strlen($2.name));
                                    strcpy(yytext, $2.name);
                                    add('V');
                                    printf("Adding argument %s to function %s of type %s\n", $2.name,currentFunction,type);
                                    addArgument($2.name,type); 
                                    $$.nd = mknode($1.nd,$2.nd, "Argument");
                                }
        |   type_specifier ID   {   $2.nd = mknode(NULL, NULL, $2.name);
                                    yytext = malloc(sizeof(char) * strlen($2.name));
                                    strcpy(yytext, $2.name);
                                    add('V');
                                    addArgument($2.name,type);
                                }   args    {
                                                struct node *temp = mknode($1.nd, $2.nd, "Argument");
                                                $$.nd = mknode(temp, $4.nd, "arglist");
                                            }                 
        |                       {   $$.nd = mknode(NULL, NULL, "arglist");  }
        ;
 
args:
        COMMA type_specifier ID     {
                                        $3.nd = mknode(NULL, NULL, $3.name);
                                        yytext = malloc(sizeof(char) * strlen($3.name));
                                        strcpy(yytext, $3.name);
                                        add('V');
                                        addArgument($3.name,type);
                                    }   args    {
                                                    struct node *temp = mknode($2.nd, $3.nd, "Argument");
                                                    $$.nd = mknode(temp, $5.nd, "args");
                                                }
        |   COMMA type_specifier ID {
                                        $3.nd = mknode(NULL, NULL, $3.name);
                                        yytext = malloc(sizeof(char) * strlen($3.name));
                                        strcpy(yytext, $3.name);
                                        add('V');
                                        addArgument($3.name,type);
                                        $$.nd = mknode($2.nd, $3.nd, "Argument");
                                    }
        ;
 
main:
        datatype MAIN {   add('F');  
                          strcpy(currentFunction, "main");
         } LPAREN RPAREN compound_statement  {
                                                                                        $1.nd = mknode(NULL, NULL, $1.name);
                                                                                        struct node *temp = mknode($6.nd, NULL, $2.name);
                                                                                        $$.nd = mknode($1.nd, temp, "Main_Structure");
                                                                                    }
        ;
 
statement_list:
        statement                       {   $$.nd = mknode($1.nd, NULL, "statement_list");}
        |   statement statement_list    {   $$.nd = mknode($1.nd, $2.nd, "statement_list");}
        |                               {   $$.nd = mknode(NULL, NULL, "statement_list");}
        ;
 
statement:
    declaration_statement                       {   $$.nd = mknode($1.nd, NULL, "statement");   }
        |   assignment_statement_2 SEMICOLON    {   $2.nd = mknode(NULL,NULL,"Semicolon") ; $$.nd = mknode($1.nd, $2.nd, "statement");  }
        |   expression_statement SEMICOLON      {   $2.nd = mknode(NULL,NULL,"Semicolon") ; $$.nd = mknode($1.nd, $2.nd, "statement");  }
        |   if_statement                        {   $$.nd = mknode($1.nd, NULL, "statement");}
        |   for_statement                       {   $$.nd = mknode($1.nd, NULL, "statement");}
        |   while_statement                     {   $$.nd = mknode($1.nd, NULL, "statement");}
        |   switch_statement                    {   $$.nd = mknode($1.nd, NULL, "statement");}
        |   return_statement                    {   $$.nd = mknode($1.nd, NULL, "statement");}
        |   compound_statement                  {   $$.nd = mknode($1.nd, NULL, "statement");}
        |   print                               {   $$.nd = mknode($1.nd, NULL, "statement");}
        
        |   SEMICOLON                           {   
                                                    $1.nd = mknode(NULL,NULL,"Semicolon") ;
                                                    $$.nd = mknode($1.nd, NULL, "statement");
                                                }
        ;


calling_list:
        ID  {   
                if(check_declaration($1.name) == 0)
                {
                    printf("Error: Argument %s not declared at line %d\n", $1.name, yylineno);
                    exit(1);
                }
                check_Argument($1.name);
                printf("Name is %s\n", $1.name);
                checkFinalArguments(currentFunction);
                $$.nd = mknode($1.nd, NULL, "calling_list"); 
                currentArgumentIndex=0;
            }
        |   ID {
                if(check_declaration($1.name) == 0)
                {
                    printf("Error: Argument %s not declared at line %d\n", $1.name, yylineno);
                    exit(1);
                }
                check_Argument($1.name);
        } COMMA calling_list  {   $$.nd = mknode($1.nd, $4.nd, "calling_list"); }
        |  constant{
                printf("Checking this\n");
                check_Argument($1.type);
                checkFinalArguments(currentFunction);
                $$.nd = mknode($1.nd, NULL, "calling_list"); 
                currentArgumentIndex=0;
        } 
        |  constant {
                check_Argument($1.type);
        }COMMA calling_list  {   $$.nd = mknode($1.nd, $4.nd, "calling_list"); }
        ;

declaration_statement:
        type_specifier var_list SEMICOLON   {
                                                $3.nd = mknode(NULL,NULL,"Semicolon") ; 
                                                struct node *temp = mknode($1.nd, $2.nd, "declaration_statement");
                                                $$.nd = mknode(temp, $3.nd, "declaration_statement_structure");
                                            }
 
type_specifier:
        INT         {   insert_type(); $$.nd = mknode(NULL, NULL, "int");   }
        |   FLOAT   {   insert_type(); $$.nd = mknode(NULL, NULL, "float"); }
        |   CHAR    {   insert_type(); $$.nd = mknode(NULL, NULL, "char");  }
        ;
 
var_list: 
        ID                                      { 
                                                    yytext = malloc(sizeof(char)*strlen($1.name));
                                                    strcpy(yytext, $1.name);
                                                    add('V');
                                                    $1.nd = mknode(NULL, NULL, $1.name);
                                                    $$.nd = mknode($1.nd, NULL, "var_list1");

                                                    sprintf(icg[ic_idx++], "%s = NULL\n", $1.name);
                                                }
        |   ID                                  {
                                                    yytext = malloc(sizeof(char)*strlen($1.name));
                                                    strcpy(yytext, $1.name);
                                                    add('V');
                                                    sprintf($1.type,type);

                                                    sprintf(icg[ic_idx++], "%s = NULL\n", $1.name);
                                                } COMMA var_list    { 
                                                                        $1.nd = mknode(NULL,NULL,$1.name) ;
                                                                        $3.nd = mknode(NULL,NULL,"Comma") ; 
                                                                        struct node *temp = mknode($3.nd, $4.nd, "var_list");
                                                                        $$.nd = mknode($1.nd, temp, "var_list_structure"); 
                                                                    }
        |   assignment_statement                {   $$.nd = mknode($1.nd, NULL, "var_list");    }
        |   assignment_statement COMMA var_list {
                                                    $2.nd = mknode(NULL,NULL,"Comma") ; 
                                                    struct node *temp = mknode($2.nd, $3.nd, "var_list");
                                                    $$.nd = mknode($1.nd, temp, "var_list_structure");
                                                }
        |   arr_dec                             {   $$.nd = mknode($1.nd, NULL, "var_list");    }
        |   arr_dec COMMA var_list              {   $2.nd = mknode(NULL,NULL,"Comma") ;
                                                    struct node *temp = mknode($2.nd, $3.nd, "var_list");
                                                    $$.nd = mknode($1.nd, temp, "var_list_structure");
                                                }
        ;
 
arr_dec:
        ID LSQBRACKET NUMBER RSQBRACKET     {
                                                yytext = malloc(sizeof(char)*strlen($1.name));
                                                strcpy(yytext, $1.name);
                                                add('A'); 
                                                $1.nd = mknode(NULL, NULL, $1.name);
                                                $3.nd = mknode(NULL, NULL, $3.name);
                                                struct node *temp = mknode($3.nd, NULL, "size");
                                                $$.nd = mknode($1.nd, temp, "arr_dec");
                                            }
        
        |   ID LSQBRACKET RSQBRACKET ASSIGNMENT LBRACE number_list RBRACE   {   
                                                                                yytext = malloc(sizeof(char)*strlen($1.name));
                                                                                add('A');
                                                                                $1.nd = mknode(NULL, NULL, $1.name);
                                                                                struct node *temp = mknode($6.nd, NULL, "init_list");
                                                                                $$.nd = mknode($1.nd, temp, "arr_dec");
                                                                            }
        |   ID LSQBRACKET RSQBRACKET ASSIGNMENT LBRACE character_list RBRACE    {   
                                                                                    yytext = malloc(sizeof(char)*strlen($1.name));
                                                                                    add('A'); 
                                                                                    $1.nd = mknode(NULL, NULL, $1.name);
                                                                                    struct node *temp = mknode($6.nd, NULL, "init_list");
                                                                                    $$.nd = mknode($1.nd, temp, "arr_dec");
                                                                                }
        |   ID LSQBRACKET RSQBRACKET ASSIGNMENT stringconst {   //change
                                                                yytext = malloc(sizeof(char) * strlen($1.name));
                                                                add('A');
                                                                $1.nd = mknode(NULL, NULL, $1.name);
                                                                struct node *temp = mknode($5.nd, NULL, "string_init");
                                                                $$.nd = mknode($1.nd, temp, "arr_dec");
                                                            }
 
        |   ID LSQBRACKET RSQBRACKET ASSIGNMENT LBRACE float_num_list RBRACE    {   
                                                                                    yytext = malloc(sizeof(char)*strlen($1.name));
                                                                                    add('A'); 
                                                                                    $1.nd = mknode(NULL, NULL, $1.name);
                                                                                    struct node *temp = mknode($6.nd, NULL, "init_list");
                                                                                    $$.nd = mknode($1.nd, temp, "arr_dec");
                                                                                }
        |   ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE number_list RBRACE    {   
                                                                                        //change
                                                                                        printf("%d\n", $7.sz);
                                                                                        if(atoi($3.name) < $7.sz) {
                                                                                            printf("Error: Array size is less than the number of elements in the initialization list\n");
                                                                                            exit(1);
                                                                                        }
                                                                                        else{
                                                                                            yytext = malloc(sizeof(char)*strlen($1.name));
                                                                                            strcpy(yytext, $1.name);
                                                                                            add('A');
                                                                                            $1.nd = mknode(NULL, NULL, $1.name);
                                                                                            $3.nd = mknode(NULL, NULL, $3.name);
                                                                                            struct node *temp2 = mknode($3.nd, NULL, "size");
                                                                                            struct node *temp = mknode($1.nd, temp2, "ID_size");
                                                                                            $$.nd = mknode(temp, $7.nd, "arr_dec");
                                                                                        }
                                                                                    }
        |   ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE character_list RBRACE {   
                                                                                        //change
                                                                                        printf("%d\n", $7.sz);
                                                                                        if(atoi($3.name) < $7.sz) {
                                                                                            printf("Error: Array size is less than the number of elements in the initialization list\n");
                                                                                            exit(1);
                                                                                        }
                                                                                        else {
                                                                                            yytext = malloc(sizeof(char)*strlen($1.name));
                                                                                            strcpy(yytext, $1.name);
                                                                                            add('A');
                                                                                            $1.nd = mknode(NULL, NULL, $1.name);
                                                                                            $3.nd = mknode(NULL, NULL, $3.name);
                                                                                            struct node *temp2 = mknode($3.nd, NULL, "size");
                                                                                            struct node *temp = mknode($1.nd, temp2, "ID_size");
                                                                                            $$.nd = mknode(temp, $7.nd, "arr_dec");
                                                                                        }
                                                                                    }
        |   ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT stringconst  {   //change
                                                                        if(atoi($3.name) < $6.sz) {
                                                                            printf("Error: Array size is less than the number of elements in the initialization list\n");
                                                                            exit(1);
                                                                        }
                                                                        else {
                                                                            yytext = malloc(sizeof(char) * strlen($1.name));
                                                                            strcpy(yytext, $1.name);
                                                                            add('A');
                                                                            $1.nd = mknode(NULL, NULL, $1.name);
                                                                            $3.nd = mknode(NULL, NULL, $3.name);
                                                                            struct node *temp = mknode($1.nd, $3.nd, "ID_size");
                                                                            $$.nd = mknode(temp, $6.nd, "arr_dec");
                                                                        }
                                                                    }
        |   ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE float_num_list RBRACE {
                                                                                        //change
                                                                                        printf("%d\n", $7.sz);
                                                                                        if(atoi($3.name) < $7.sz) {
                                                                                            printf("Error: Array size is less than the number of elements in the initialization list\n");
                                                                                            exit(1);
                                                                                        }
                                                                                        else {
                                                                                            yytext = malloc(sizeof(char)*strlen($1.name));
                                                                                            strcpy(yytext, $1.name);
                                                                                            add('A');
                                                                                            $1.nd = mknode(NULL, NULL, $1.name);
                                                                                            $3.nd = mknode(NULL, NULL, $3.name);
                                                                                            struct node *temp2 = mknode($3.nd, NULL, "size");
                                                                                            struct node *temp = mknode($1.nd, temp2, "ID_size");
                                                                                            $$.nd = mknode(temp, $7.nd, "arr_dec");
                                                                                        }
                                                                                    }
        |   ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET    {
                                                                                yytext = malloc(sizeof(char) * strlen($1.name));
                                                                                strcpy(yytext, $1.name);
                                                                                add('A');
                                                                                $1.nd = mknode(NULL, NULL, $1.name);
                                                                                $3.nd = mknode(NULL, NULL, $3.name);
                                                                                $6.nd = mknode(NULL, NULL, $6.name);
                                                                                struct node *temp = mknode($3.nd, $6.nd, "size");
                                                                                $$.nd = mknode($1.nd, temp, "arr_dec");
                                                                            }
        |   ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_num_list
                                                                {
                                                                    //change
                                                                    if(atoi($6.name) < $9.each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else if(atoi($3.name) < $9.sz){
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more number of {} in init list than specified by 1st dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        // printf("sz = %d, each_sz = %d, mul = %d \n", $9.sz, $9.each_list_sz, $9.sz * $9.each_list_sz);
                                                                        yytext = malloc(sizeof(char) * strlen($1.name));
                                                                        strcpy(yytext, $1.name);
                                                                        add('A');
                                                                        $1.nd = mknode(NULL, NULL, $1.name);
                                                                        $3.nd = mknode(NULL, NULL, $3.name);
                                                                        $6.nd = mknode(NULL, NULL, $6.name);
                                                                        struct node *temp = mknode($3.nd, $6.nd, "size");
                                                                        struct node *temp2 = mknode($1.nd, temp, "ID_size");
                                                                        $$.nd = mknode(temp2, $9.nd, "arr_dec");
                                                                    }
                                                                }
        |   ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_character_list
                                                                {
                                                                    //change
                                                                    if(atoi($6.name) < $9.each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else if(atoi($3.name) < $9.sz){
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more number of {} in init list than specified by 1st dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        // printf("sz = %d, each_sz = %d, mul = %d \n", $9.sz, $9.each_list_sz, $9.sz * $9.each_list_sz);
                                                                        yytext = malloc(sizeof(char) * strlen($1.name));
                                                                        strcpy(yytext, $1.name);
                                                                        add('A');
                                                                        $1.nd = mknode(NULL, NULL, $1.name);
                                                                        $3.nd = mknode(NULL, NULL, $3.name);
                                                                        $6.nd = mknode(NULL, NULL, $6.name);
                                                                        struct node *temp = mknode($3.nd, $6.nd, "size");
                                                                        struct node *temp2 = mknode($1.nd, temp, "ID_size");
                                                                        $$.nd = mknode(temp2, $9.nd, "arr_dec");
                                                                    }
                                                                }
        |   ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE stringconst_list RBRACE
                                                                {
                                                                    //change2
                                                                    if(atoi($6.name) < $10.each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more chars in one or more strings in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else if(atoi($3.name) < $10.sz){
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more number of strings in init list than specified by 1st dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        // printf("sz = %d, each_sz = %d, mul = %d \n", $9.sz, $9.each_list_sz, $9.sz * $9.each_list_sz);
                                                                        yytext = malloc(sizeof(char) * strlen($1.name));
                                                                        strcpy(yytext, $1.name);
                                                                        add('V');
                                                                        $1.nd = mknode(NULL, NULL, $1.name);
                                                                        $3.nd = mknode(NULL, NULL, $3.name);
                                                                        $6.nd = mknode(NULL, NULL, $6.name);
                                                                        struct node *temp = mknode($3.nd, $6.nd, "size");
                                                                        struct node *temp2 = mknode($1.nd, temp, "ID_size");
                                                                        $$.nd = mknode(temp2, $10.nd, "arr_dec");
                                                                    }
                                                                }
        |   ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_float_num_list
                                                                {
                                                                    //change
                                                                    if(atoi($6.name) < $9.each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else if(atoi($3.name) < $9.sz){
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more number of {} in init list than specified by 1st dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        // printf("sz = %d, each_sz = %d, mul = %d \n", $9.sz, $9.each_list_sz, $9.sz * $9.each_list_sz);
                                                                        yytext = malloc(sizeof(char) * strlen($1.name));
                                                                        strcpy(yytext, $1.name);
                                                                        add('A');
                                                                        $1.nd = mknode(NULL, NULL, $1.name);
                                                                        $3.nd = mknode(NULL, NULL, $3.name);
                                                                        $6.nd = mknode(NULL, NULL, $6.name);
                                                                        struct node *temp = mknode($3.nd, $6.nd, "size");
                                                                        struct node *temp2 = mknode($1.nd, temp, "ID_size");
                                                                        $$.nd = mknode(temp2, $9.nd, "arr_dec");
                                                                    }
                                                                }
        |   ID LSQBRACKET RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_num_list
                                                                {
                                                                    //change
                                                                    if(atoi($5.name) < $8.each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        yytext = malloc(sizeof(char) * strlen($1.name));
                                                                        strcpy(yytext, $1.name);
                                                                        add('A');
                                                                        $1.nd = mknode(NULL, NULL, $1.name);
                                                                        struct node *firstsize = mknode(NULL, NULL, " ");
                                                                        $5.nd = mknode(NULL, NULL, $5.name);
                                                                        struct node *temp = mknode(firstsize, $5.nd, "size");
                                                                        struct node *temp2 = mknode($1.nd, temp, "ID_size");
                                                                        $$.nd = mknode(temp2, $8.nd, "arr_dec");
                                                                    }
                                                                }
        |   ID LSQBRACKET RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_character_list
                                                                {
                                                                    //change
                                                                    if(atoi($5.name) < $8.each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        yytext = malloc(sizeof(char) * strlen($1.name));
                                                                        strcpy(yytext, $1.name);
                                                                        add('A');
                                                                        $1.nd = mknode(NULL, NULL, $1.name);
                                                                        struct node *firstsize = mknode(NULL, NULL, " ");
                                                                        $5.nd = mknode(NULL, NULL, $5.name);
                                                                        struct node *temp = mknode(firstsize, $5.nd, "size");
                                                                        struct node *temp2 = mknode($1.nd, temp, "ID_size");
                                                                        $$.nd = mknode(temp2, $8.nd, "arr_dec");
                                                                    }
                                                                }
        |   ID LSQBRACKET RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE stringconst_list RBRACE
                                                                {
                                                                    //change2
                                                                    if(atoi($5.name) < $9.each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more chars in one or more strings in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        yytext = malloc(sizeof(char) * strlen($1.name));
                                                                        strcpy(yytext, $1.name);
                                                                        add('V');
                                                                        $1.nd = mknode(NULL, NULL, $1.name);
                                                                        struct node *firstsize = mknode(NULL, NULL, " ");
                                                                        $5.nd = mknode(NULL, NULL, $5.name);
                                                                        struct node *temp = mknode(firstsize, $5.nd, "size");
                                                                        struct node *temp2 = mknode($1.nd, temp, "ID_size");
                                                                        $$.nd = mknode(temp2, $9.nd, "arr_dec");
                                                                    }
                                                                }
        |   ID LSQBRACKET RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_float_num_list
                                                                {
                                                                    //change
                                                                    if(atoi($5.name) < $8.each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        yytext = malloc(sizeof(char) * strlen($1.name));
                                                                        strcpy(yytext, $1.name);
                                                                        add('A');
                                                                        $1.nd = mknode(NULL, NULL, $1.name);
                                                                        struct node *firstsize = mknode(NULL, NULL, " ");
                                                                        $5.nd = mknode(NULL, NULL, $5.name);
                                                                        struct node *temp = mknode(firstsize, $5.nd, "size");
                                                                        struct node *temp2 = mknode($1.nd, temp, "ID_size");
                                                                        $$.nd = mknode(temp2, $8.nd, "arr_dec");
                                                                    }
                                                                }
        ;
    
multiple_num_list:
        LBRACE number_list RBRACE   {
                                        //change
                                        $$.sz = 1;
                                        $$.each_list_sz = $2.sz;
                                        $$.nd = mknode($2.nd, NULL, "multiple_num_list");
                                    }
        |   LBRACE braced_num_list RBRACE   {
                                                //change
                                                $$.sz = $2.sz;
                                                $$.each_list_sz = $2.each_list_sz;
                                                $$.nd = mknode($2.nd, NULL, "multiple_num_list");
                                            }
        ;
    
multiple_character_list:
        LBRACE character_list RBRACE    {
                                            //change
                                            $$.sz = 1;
                                            $$.each_list_sz = $2.sz;
                                            $$.nd = mknode($2.nd, NULL, "multiple_character_list");
                                        }
        |   LBRACE braced_character_list RBRACE {
                                                    //change
                                                    $$.sz = $2.sz;
                                                    $$.each_list_sz = $2.each_list_sz;
                                                    $$.nd = mknode($2.nd, NULL, "multiple_character_list");
                                                }
        ;
    
multiple_float_num_list:
        LBRACE float_num_list RBRACE    {
                                            //change
                                            $$.sz = 1;
                                            $$.each_list_sz = $2.sz;
                                            $$.nd = mknode($2.nd, NULL, "multiple_float_num_list");
                                        }
        |   LBRACE braced_float_num_list RBRACE {
                                                    //change
                                                    $$.sz = $2.sz;
                                                    $$.each_list_sz = $2.each_list_sz;
                                                    $$.nd = mknode($2.nd, NULL, "multiple_float_num_list");
                                                }
        ;
    
braced_num_list:
        LBRACE number_list RBRACE   {
                                        //change
                                        $$.sz = 1;
                                        $$.each_list_sz = $2.sz;
                                        $$.nd = mknode($2.nd, NULL, "braced_num_list");
                                    }
        |   LBRACE number_list RBRACE COMMA braced_num_list {
                                                                //change
                                                                $$.sz = $5.sz + 1;
                                                                $$.each_list_sz = $2.sz > $5.each_list_sz ? $2.sz : $5.each_list_sz;
                                                                $$.nd = mknode($2.nd, $5.nd, "braced_num_list");
                                                            }
        ;
    
braced_character_list:
        LBRACE character_list RBRACE    {
                                            //change
                                            $$.sz = 1;
                                            $$.each_list_sz = $2.sz;
                                            $$.nd = mknode($2.nd, NULL, "braced_character_list");
                                        }
        |   LBRACE character_list RBRACE COMMA braced_character_list    {
                                                                            //change
                                                                            $$.sz = $5.sz + 1;
                                                                            $$.each_list_sz = $2.sz > $5.each_list_sz ? $2.sz : $5.each_list_sz;
                                                                            $$.nd = mknode($2.nd, $5.nd, "braced_character_list");
                                                                        }
        ;
    
braced_float_num_list:
        LBRACE float_num_list RBRACE    {
                                            //change
                                            $$.sz = 1;
                                            $$.each_list_sz = $2.sz;
                                            $$.nd = mknode($2.nd, NULL, "braced_float_num_list");
                                        }
        |   LBRACE float_num_list RBRACE COMMA braced_float_num_list    {
                                                                            //change
                                                                            $$.sz = $5.sz + 1;
                                                                            $$.each_list_sz = $2.sz > $5.each_list_sz ? $2.sz : $5.each_list_sz;
                                                                            $$.nd = mknode($2.nd, $5.nd, "braced_float_num_list");
                                                                        }
        ;
 
number_list:
        NUMBER                          {
                                            $$.sz = 1;      //change
                                            $1.nd = mknode(NULL, NULL, $1.name);
                                            $$.nd = mknode($1.nd, NULL, "number_list");
                                        }
        |   NUMBER COMMA number_list    {
                                            $$.sz = $3.sz + 1;  //change
                                            $1.nd = mknode(NULL, NULL, $1.name);
                                            $$.nd = mknode($1.nd, $3.nd, "number_list");
                                        }
        ;
    
character_list:
        CHARACTER                           {
                                                $$.sz = 1;      //change
                                                $1.nd = mknode(NULL, NULL, $1.name);
                                                $$.nd = mknode($1.nd, NULL, "character_list");
                                            }
        |   CHARACTER COMMA character_list  {
                                                $$.sz = $3.sz + 1;  //change
                                                $1.nd = mknode(NULL, NULL, $1.name);
                                                $$.nd = mknode($1.nd, $3.nd, "character_list");
                                            }
        ;
stringconst_list:
        stringconst COMMA stringconst_list  {
                                                    //change2
                                                    $$.sz = $3.sz + 1;
                                                    $$.each_list_sz = $1.sz > $3.each_list_sz ? $1.sz : $3.each_list_sz;
                                                    $1.nd = mknode(NULL, NULL, $1.name);
                                                    $$.nd = mknode($1.nd, $3.nd, "stringconst_list");
                                                }
        | stringconst     {
                            //change2
                            $$.sz = 1;
                            $$.each_list_sz = $1.sz;
                            $1.nd = mknode(NULL, NULL, $1.name);
                            $$.nd = mknode($1.nd, NULL, "stringconst_list");
                        }
        ;

float_num_list:
        FLOAT_NUM                           {
                                                $$.sz = 1;      //change
                                                $1.nd = mknode(NULL, NULL, $1.name);
                                                $$.nd = mknode($1.nd, NULL, "float_num_list");
                                            }
        |   FLOAT_NUM COMMA float_num_list  {
                                                $$.sz = $3.sz + 1;  //change
                                                $1.nd = mknode(NULL, NULL, $1.name);
                                                $$.nd = mknode($1.nd, $3.nd, "float_num_list");
                                            }
        ;
    

assignment_statement:
        ID  {
                yytext = malloc(sizeof(char)*strlen($1.name));
                strcpy(yytext, $1.name);
                add('V');
            } ASSIGNMENT expression_statement   {
                                                    printf("Types: 1 %s 2 %s\n", get_type($1.name), $4.type);
                                                    if(strcmp(get_type($1.name), $4.type) != 0)
                                                    {
                                                        printf("Error: Type mismatch in assignment statement %d\n",yylineno);
                                                        exit(1);
                                                    }
                                                    $1.nd = mknode(NULL, NULL, $1.name);
                                                    $3.nd = mknode($1.nd, $4.nd, "ASSIGNMENT");
                                                    $$.nd = mknode($3.nd, NULL, "assignment_statement");

                                                    sprintf(icg[ic_idx++], "%s = t%d\n", $1.name, $4.t);
                                                }
        ;
 
expression_statement:
        expression_statement OR logical_o_exp   {   
                                                    sprintf($$.type, "int");
                                                    $2.nd = mknode($1.nd, $3.nd, "OR");
                                                    $$.nd = mknode($2.nd, NULL, "expression_statement");

                                                    if(is_if == 1) {
                                                        sprintf(icg[ic_idx++], "\nIF t%d OR t%d GOTO L%d ELSE GOTO L%d\n", $1.t, $3.t, label, label + 1);
                                                        sprintf($$.if_body, "L%d", label++);
                                                        sprintf($$.else_body, "L%d", label++);
                                                    } 
                                                    else if(is_for == 1) {
                                                        sprintf($$.if_body, "L%d", label++);
                                                        sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
                                                        sprintf(icg[ic_idx++], "if NOT (t%d OR t%d) GOTO L%d\n", $1.t, $3.t, label);
                                                        sprintf($$.else_body, "L%d", label++);
                                                    }
                                                    else {
                                                        $$.t = temp_var++;
                                                        sprintf(icg[ic_idx++], "t%d = %d OR t%d\n", $$.t, $1.t, $3.t);
                                                    }
                                                }
        |   logical_o_exp                       {
                                                    $$.nd = mknode($1.nd, NULL, "expression_statement");   
                                                    sprintf($$.type, $1.type);

                                                    $$.t = $1.t;
                                                }
        ;
 
logical_o_exp:
        logical_o_exp AND logical_a_exp {
                                            sprintf($$.type, "int");
                                            $2.nd = mknode($1.nd, $3.nd, "AND");
                                            $$.nd = mknode($2.nd, NULL, "logical_or_expression");

                                            if(is_if == 1) {
                                                sprintf(icg[ic_idx++], "\nIF t%d AND t%d GOTO L%d ELSE GOTO L%d\n", $1.t, $3.t, label, label + 1);
                                                sprintf($$.if_body, "L%d", label++);
                                                sprintf($$.else_body, "L%d", label++);
                                            }
                                            else if(is_for == 1) {
                                                sprintf($$.if_body, "L%d", label++);
                                                sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
                                                sprintf(icg[ic_idx++], "if NOT (t%d AND t%d) GOTO L%d\n", $1.t, $3.t, label);
                                                sprintf($$.else_body, "L%d", label++);
                                            }
                                            else {
                                                $$.t = temp_var++;
                                                sprintf(icg[ic_idx++], "t%d = t%d AND t%d\n", $$.t, $1.t, $3.t);
                                            }
                                        }
        |   logical_a_exp               {   
                                            $$.nd = mknode($1.nd, NULL, "logical_or_expression");   
                                            sprintf($$.type, $1.type);

                                            $$.t = $1.t;
                                        }
        ;
 
logical_a_exp:
        logical_a_exp EQ relational_exp     {
                                                sprintf($$.type, "int");
                                                $2.nd = mknode($1.nd, $3.nd, "EQ");
                                                $$.nd = mknode($2.nd, NULL, "logical_a_exp");

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d == t%d GOTO L%d ELSE GOTO L%d\n", $1.t, $3.t, label, label + 1);
                                                    sprintf($$.if_body, "L%d", label++);
                                                    sprintf($$.else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf($$.if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d == t%d) GOTO L%d\n", $1.t, $3.t, label);
                                                    sprintf($$.else_body, "L%d", label++);
                                                }
                                                else {
                                                    $$.t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d == t%d\n", $$.t, $1.t, $3.t);
                                                }
                                            }
        |   logical_a_exp NE relational_exp {
                                                sprintf($$.type, "int");
                                                $2.nd = mknode($1.nd, $3.nd, "NE");
                                                $$.nd = mknode($2.nd, NULL, "logical_a_exp");

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d != t%d GOTO L%d ELSE GOTO L%d\n", $1.t, $3.t, label, label + 1);
                                                    sprintf($$.if_body, "L%d", label++);
                                                    sprintf($$.else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf($$.if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d != t%d) GOTO L%d\n", $1.t, $3.t, label);
                                                    sprintf($$.else_body, "L%d", label++);
                                                }
                                                else {
                                                    $$.t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d != t%d\n", $$.t, $1.t, $3.t);
                                                }
                                            }
        |   relational_exp                  {   
                                                $$.nd = mknode($1.nd, NULL, "logical_a_exp");   
                                                sprintf($$.type, $1.type);

                                                $$.t = $1.t;
                                            }
        ;
 
relational_exp:
        relational_exp GT additive_exp      {
                                                if(strcmp($1.type, "char") == 0 || strcmp($3.type, "char") == 0){
                                                    printf("Can't compare character in line %d\n", yylineno);
                                                    exit(1);
                                                }
                                                sprintf($$.type, "int");
                                                $2.nd = mknode($1.nd, $3.nd, "GT");
                                                $$.nd = mknode($2.nd, NULL, "relational_exp");

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d > t%d GOTO L%d ELSE GOTO L%d\n", $1.t, $3.t, label, label + 1);
                                                    sprintf($$.if_body, "L%d", label++);
                                                    sprintf($$.else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf($$.if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d > t%d) GOTO L%d\n", $1.t, $3.t, label);
                                                    sprintf($$.else_body, "L%d", label++);
                                                }
                                                else {
                                                    $$.t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d > t%d\n", $$.t, $1.t, $3.t);
                                                }
                                            }
        |   relational_exp GE additive_exp  {
                                                if(strcmp($1.type, "char") == 0 || strcmp($3.type, "char") == 0){
                                                    printf("Can't compare character in line %d\n", yylineno);
                                                    exit(1);
                                                }
                                                sprintf($$.type, "int");
                                                $2.nd = mknode($1.nd, $3.nd, "GE");
                                                $$.nd = mknode($2.nd, NULL, "relational_exp");

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d >= t%d GOTO L%d ELSE GOTO L%d\n", $1.t, $3.t, label, label + 1);
                                                    sprintf($$.if_body, "L%d", label++);
                                                    sprintf($$.else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf($$.if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d >= t%d) GOTO L%d\n", $1.t, $3.t, label);
                                                    sprintf($$.else_body, "L%d", label++);
                                                }
                                                else {
                                                    $$.t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d >= t%d\n", $$.t, $1.t, $3.t);
                                                }
                                            }
        |   relational_exp LT additive_exp  {
                                                if(strcmp($1.type, "char") == 0 || strcmp($3.type, "char") == 0){
                                                    printf("Can't compare character in line %d\n", yylineno);
                                                    exit(1);
                                                }
                                                sprintf($$.type, "int");
                                                $2.nd = mknode($1.nd, $3.nd, "LT");
                                                $$.nd = mknode($2.nd, NULL, "relational_exp");

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d < t%d GOTO L%d ELSE GOTO L%d\n", $1.t, $3.t, label, label + 1);
                                                    sprintf($$.if_body, "L%d", label++);
                                                    sprintf($$.else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf($$.if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d < t%d) GOTO L%d\n", $1.t, $3.t, label);
                                                    sprintf($$.else_body, "L%d", label++);
                                                }
                                                else {
                                                    $$.t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d < t%d\n", $$.t, $1.t, $3.t);
                                                }
                                            }
        |   relational_exp LE additive_exp  {
                                                if(strcmp($1.type, "char") == 0 || strcmp($3.type, "char") == 0){
                                                    printf("Can't compare character in line %d\n", yylineno);
                                                    exit(1);
                                                }
                                                sprintf($$.type, "int");
                                                $2.nd = mknode($1.nd, $3.nd, "LE");
                                                $$.nd = mknode($2.nd, NULL, "relational_exp");

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d <= t%d GOTO L%d ELSE GOTO L%d\n", $1.t, $3.t, label, label + 1);
                                                    sprintf($$.if_body, "L%d", label++);
                                                    sprintf($$.else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf($$.if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d <= t%d) GOTO L%d\n", $1.t, $3.t, label);
                                                    sprintf($$.else_body, "L%d", label++);
                                                }
                                                else {
                                                    $$.t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d <= t%d\n", $$.t, $1.t, $3.t);
                                                }
                                            }
        |   additive_exp                    {   
                                                $$.nd = mknode($1.nd, NULL, "relational_exp");  
                                                sprintf($$.type, $1.type);

                                                $$.t = $1.t;
                                            }
        ;
 
additive_exp:
        additive_exp ADD multiplicative_exp     {
                                                    if(strcmp($1.type, "char") == 0 || strcmp($3.type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp($1.type, $3.type)) {
		                                                sprintf($$.type, $1.type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line  %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    $2.nd = mknode($1.nd, $3.nd, "ADD");
                                                    $$.nd = mknode($2.nd, NULL, "additive_exp");

                                                    $$.t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d + t%d\n", $$.t, $1.t, $3.t);
                                                }
        |   additive_exp SUB multiplicative_exp {
                                                    if(strcmp($1.type, "char") == 0 || strcmp($3.type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp($1.type, $3.type)) {
		                                                sprintf($$.type, $1.type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    $2.nd = mknode($1.nd, $3.nd, "SUB");
                                                    $$.nd = mknode($2.nd, NULL, "additive_exp");

                                                    $$.t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d - t%d\n", $$.t, $1.t, $3.t);
                                                }
        |   multiplicative_exp                  {   
                                                    $$.nd = mknode($1.nd, NULL, "additive_exp");    
                                                    sprintf($$.type, $1.type);

                                                    $$.t = $1.t;
                                                }
        ;
 
multiplicative_exp:
        multiplicative_exp MUL negation_exp     {   
                                                    if(strcmp($1.type, "char") == 0 || strcmp($3.type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp($1.type, $3.type)) {
		                                                sprintf($$.type, $1.type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    $2.nd = mknode($1.nd, $3.nd, "MUL");
                                                    $$.nd = mknode($2.nd, NULL, "multiplicative_exp");

                                                    $$.t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d * t%d\n", $$.t, $1.t, $3.t);
                                                }
        |   multiplicative_exp DIV negation_exp {
                                                    if(strcmp($1.type, "char") == 0 || strcmp($3.type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp($1.type, $3.type)) {
		                                                sprintf($$.type, $1.type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    $2.nd = mknode($1.nd, $3.nd, "DIV");
                                                    $$.nd = mknode($2.nd, NULL, "multiplicative_exp");

                                                    $$.t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d / t%d\n", $$.t, $1.t, $3.t);
                                                }
        |   multiplicative_exp MOD negation_exp {
                                                    if(strcmp($1.type, "char") == 0 || strcmp($3.type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp($1.type, $3.type)) {
		                                                sprintf($$.type, $1.type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    $2.nd = mknode($1.nd, $3.nd, "MOD");
                                                    $$.nd = mknode($2.nd, NULL, "multiplicative_exp");

                                                    $$.t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d %% t%d\n", $$.t, $1.t, $3.t);
                                                }
        |   negation_exp                        {   
                                                    $$.nd = mknode($1.nd, NULL, "multiplicative_exp");  
                                                    sprintf($$.type, $1.type);

                                                    $$.t = $1.t;
                                                }
        ;
 
negation_exp:
        NOT access_call_exp {
                            if(strcmp($2.type, "int") != 0){
                                printf("Type mismatch in line %d\n", yylineno);
                                exit(1);
                            }
                            sprintf($$.type, $2.type);
                            $1.nd = mknode($2.nd, NULL, "NOT");
                            $$.nd = mknode($1.nd, NULL, "negation_exp");

                            if(is_if == 1) {
                                sprintf(icg[ic_idx++], "\nIF !t%d GOTO L%d ELSE GOTO L%d\n", $2.t, label, label + 1);
                                sprintf($$.if_body, "L%d", label++);
                                sprintf($$.else_body, "L%d", label++);
                            }
                            else if(is_for == 1) {
                                sprintf($$.if_body, "L%d", label++);
                                sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
                                sprintf(icg[ic_idx++], "if NOT (!t%d) GOTO L%d\n", $2.t, label);
                                sprintf($$.else_body, "L%d", label++);
                            }
                            $$.t = temp_var++;
                            sprintf(icg[ic_idx++], "t%d = !t%d\n", $$.t, $2.t);
                        }
        |   access_call_exp {   
                                sprintf($$.type, $1.type);
                                $$.nd = mknode($1.nd, NULL, "negation_exp");

                                $$.t = $1.t;  
                            }
        ;
    
access_call_exp:
        access_call_exp LSQBRACKET NUMBER RSQBRACKET   {
                                                        if(check_declaration($1.name)==0){
                                                            printf("Variable %s not declared in line %d\n", $1.name, yylineno);
                                                            exit(1);
                                                        }
                                                        sprintf($$.type, $1.type);
                                                        $3.nd = mknode(NULL, NULL, $3.name);
                                                        $$.nd = mknode($1.nd, $3.nd, "access_call_exp");

                                                        $$.t = temp_var++;
                                                        if(strcmp($1.type, "int") == 0)
                                                            sprintf(icg[ic_idx++], "t%d = 4 * %d\n", $$.t, atoi($3.name));
                                                        else if(strcmp($1.type, "char") == 0)
                                                            sprintf(icg[ic_idx++], "t%d = 1 * %d\n", $$.t, atoi($3.name));
                                                        else if(strcmp($1.type, "float") == 0)
                                                            sprintf(icg[ic_idx++], "t%d = 8 * %d\n", $$.t, atoi($3.name));
                                                        
                                                        $$.t = temp_var++;
                                                        sprintf(icg[ic_idx++], "t%d = &%s\n", $$.t, $1.name);

                                                        $$.t = temp_var++;
                                                        sprintf(icg[ic_idx++], "t%d = t%d + t%d\n", $$.t, $$.t - 1, $$.t - 2);
                                                        arr_en = 1;
                                                        // sprintf(icg[ic_idx++], "%s = *t%d\n", "HAHA", $$.t);
                                                    }
        |   primary_exp {   
                            sprintf($$.type, $1.type);
                            $$.nd = mknode($1.nd, NULL, "access_call_exp");

                            $$.t = $1.t;  
                        }
        |   access_call_exp LPAREN RPAREN   {
                                                printf("Checking for function name %s\n", $1.name);
                                                if(check_declaration($1.name)==0){
                                                    printf("BACK TO access_call_exp\n");
                                                    printf("Variable %s not declared in line %d\n", $1.name, yylineno);
                                                    exit(1);
                                                }
                                                printf("BACK TO access_call_exp\n");
                                                checkFinalArguments($1.name);
                                                $2.nd = mknode(NULL, NULL, "LPAREN");
                                                $3.nd = mknode(NULL, NULL, "RPAREN");
                                                struct node *temp = mknode($2.nd, $3.nd, "PARENTHESES");
                                                $$.nd = mknode($1.nd, temp, "access_call_exp");
                                            }
        |   access_call_exp  LPAREN {
            stringTemp=strdup(currentFunction);
            strcpy(currentFunction, $1.name);
            } calling_list RPAREN  { 
                                        strcpy(currentFunction, stringTemp);  
                                        printf("Accessing Function %s\n", $1.name);
                                        if(check_declaration($1.name)==0){
                                            printf("Variable %s not declared in line %d\n", $1.name, yylineno);
                                            exit(1);
                                        }
                                        
                                        $$.nd = mknode($1.nd, $4.nd, "access_call_exp");    
                                    }
        ;
 
primary_exp:
        LPAREN expression_statement RPAREN  {   
                                                $$.nd = mknode($2.nd, NULL, "primary_exp"); 
                                                sprintf($$.type, $2.type);

                                                $$.t = $2.t;
                                            }
        |   ID                              {  
                                                printf("Checking for variable name %s\n", $1.name);
                                                if(check_declaration($1.name)==0){
                                                    printf("Variable %s not declared in line %d\n", $1.name, yylineno);
                                                    exit(1);
                                                }
                                                sprintf($$.type, get_type($1.name));
                                                $1.nd = mknode(NULL, NULL, $1.name);
                                                $$.nd = mknode($1.nd, NULL, "primary_exp");

                                                $$.t = temp_var++;
                                                sprintf(icg[ic_idx++], "t%d = %s\n", $$.t, $1.name);
                                            }
        |   constant                        {   
                                                sprintf($$.type, $1.type);
                                                $$.nd = mknode($1.nd, NULL, "primary_exp");

                                                $$.t = temp_var++;
                                                sprintf(icg[ic_idx++], "t%d = %s\n", $$.t, $1.name);
                                            }
        ;
 
constant:
        NUMBER          {
                            sprintf($$.type, "int");
                            $1.nd = mknode(NULL, NULL, $1.name);
                            $$.nd = mknode($1.nd, NULL, "constant");

                            // strcpy($$.name, $1.name);
                        }
        |   CHARACTER   {
                            sprintf($$.type, "char");
                            $1.nd = mknode(NULL, NULL, $1.name);
                            $$.nd = mknode($1.nd, NULL, "constant");

                            // strcpy($$.name, $1.name);
                        }
        | FLOAT_NUM     {
                            sprintf($$.type, "float");
                            $1.nd = mknode(NULL, NULL, $1.name);
                            $$.nd = mknode($1.nd, NULL, "constant");

                            // strcpy($$.name, $1.name);
                        }
        | EXPONENT          {
                            sprintf($$.type, "exp");
                            $1.nd = mknode(NULL, NULL, $1.name);
                            $$.nd = mknode($1.nd, NULL, "constant");

                            // strcpy($$.name, $1.name);
                        }
        ;

if_statement:
        IF LPAREN {is_if = 1;} expression_statement RPAREN {sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.if_body);} compound_statement {sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.else_body);} EL_statement
                                                                        {
                                                                            $1.nd = mknode($4.nd,$7.nd,"IF");
                                                                            // $9.nd = mknode($10.nd,NULL,"ELSE");
                                                                            $$.nd = mknode($1.nd,$9.nd,"IF_statement");
                                                                            is_if = 0;
                                                                        }
        ;
EL_statement:
        ELSE compound_statement {
                                    $1.nd = mknode($2.nd, NULL, "ELSE");
                                    $$.nd = mknode($1.nd, NULL, "EL_statement");    
                                }
        |   {   $$.nd = NULL; }
        ;                                               

 
for_statement:
        FOR LPAREN {
            nextTable();
            is_for = 1;
        } 
        for_initializer for_condition for_update RPAREN LBRACE loop_stat_list RBRACE
                                                                    {
                                                                        prevTable();
                                                                        struct node *temp1 = mknode($4.nd, $5.nd, "For_Parameters_1");
                                                                        struct node *temp2 = mknode(temp1, $6.nd, "For_Parameters_2");
                                                                        $$.nd = mknode(temp2, $9.nd, "For_Statement");

                                                                        sprintf(icg[ic_idx++], buff);
                                                                        sprintf(icg[ic_idx++], "JUMP TO %s\n", $5.if_body);
                                                                        sprintf(icg[ic_idx++], "\nLABEL %s:\n", $5.else_body);
                                                                        is_for = 0;
                                                                    }
        ;
 
assignment_statement_2: ID ASSIGNMENT expression_statement  {   
                                                                if(check_declaration($1.name) == 0 || isArray($1.name) == 1)
                                                                {
                                                                    printf("Error: Variable %s not declared at line %d\n", $1.name, yylineno);
                                                                    exit(1);
                                                                }
                                                                printf("Types of %s is %s\n", get_type($1.name), $3.type);
                                                                if(strcmp(get_type($1.name), $3.type) != 0)
                                                                {
                                                                    printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                    exit(1);
                                                                }
                                                                $1.nd = mknode(NULL, NULL, $1.name);
                                                                $2.nd = mknode($1.nd, $3.nd, "ASSIGNMENT");
                                                                $$.nd = mknode($2.nd, NULL, "assignment_statement");

                                                                // if(is_for == 1) {
                                                                //     // if(for_up == 1)
                                                                //     //     sprintf(buff, "t%d = %s\n", $3.t, $1.name);
                                                                //     // else
                                                                //     // sprintf(buff, "t%d = %s\n", $3.t, $1.name);
                                                                //         sprintf(buff, "%s = t%d\n", $1.name, $3.t);//correct
                                                                //     // sprintf(buff, "%s = t%d\n", $1.name, temp_var);
                                                                // }
                                                                // else {
                                                                    if(arr_en == 1) {
                                                                        sprintf(icg[ic_idx++], "%s = *t%d\n", $1.name, $3.t);
                                                                        arr_en = 0;
                                                                    }
                                                                    else {
                                                                        sprintf(icg[ic_idx++], "%s = t%d\n", $1.name, $3.t);
                                                                    }
                                                                // }
                                                                //need to put a = *T3 here after array
                                                                    
                                                            }
        |  ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT expression_statement  {
                                                                                if(check_declaration($1.name) == 0 || isArray($1.name) == 0)
                                                                                {
                                                                                    printf("Error: Variable %s is not an array at line %d\n", $1.name, yylineno);
                                                                                    exit(1);
                                                                                }
                                                                                printf("Types of %s is %s\n", get_type($1.name), $6.type);
                                                                                if(strcmp(get_type($1.name), $6.type) != 0)
                                                                                {
                                                                                    printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                    exit(1);
                                                                                }
                                                                                $1.nd = mknode(NULL, NULL, $1.name);
                                                                                $2.nd = mknode($1.nd, $3.nd, "LSQBRACKET");
                                                                                $4.nd = mknode($2.nd, $5.nd, "RSQBRACKET");
                                                                                $6.nd = mknode($4.nd, NULL, "ASSIGNMENT");
                                                                                $$.nd = mknode($6.nd, NULL, "assignment_statement");

                                                                                // $$.t = temp_var++;
                                                                                
                                                                                if(strcmp(get_type($1.name), "int") == 0)
                                                                                    sprintf(icg[ic_idx++], "t%d = 4 * %d\n", temp_var++, atoi($3.name));
                                                                                else if(strcmp(get_type($1.name), "char") == 0)
                                                                                    sprintf(icg[ic_idx++], "t%d = 1 * %d\n", temp_var++, atoi($3.name));
                                                                                else if(strcmp(get_type($1.name), "float") == 0)
                                                                                    sprintf(icg[ic_idx++], "t%d = 8 * %d\n", temp_var++, atoi($3.name));
                                                                                

                                                                                // $$.t = temp_var++;
                                                                                sprintf(icg[ic_idx++], "t%d = &%s\n", temp_var++, $1.name);

                                                                                // $$.t = temp_var++;
                                                                                sprintf(icg[ic_idx++], "t%d = t%d + t%d\n", temp_var, temp_var - 2, temp_var - 1);

                                                                                sprintf(icg[ic_idx++], "*t%d = t%d", temp_var, $6.t);
                                                                                // arr_en = 1;
                                                                            }
                            |   ID LSQBRACKET ID RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT expression_statement {
                                                                                                                    printf("Testing Here 4\n");
                                                                                                                    if(check_declaration($1.name) == 0 || isArray($1.name) == 0)
                                                                                                                    {
                                                                                                                        printf("Error: Variable %s is not an array at line %d\n", $1.name, yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    printf("Types of %s is %s\n", get_type($1.name), $9.type);
                                                                                                                    if(strcmp(get_type($1.name), $9.type) != 0)
                                                                                                                    {
                                                                                                                        printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    $1.nd = mknode(NULL, NULL, $1.name);
                                                                                                                    $2.nd = mknode($1.nd, $3.nd, "LSQBRACKET");
                                                                                                                    $4.nd = mknode($2.nd, $5.nd, "RSQBRACKET");
                                                                                                                    $9.nd = mknode($4.nd, NULL, "ASSIGNMENT");
                                                                                                                    $$.nd = mknode($9.nd, NULL, "assignment_statement");
                                                                                                                }
        | ID LSQBRACKET ID RSQBRACKET LSQBRACKET ID RSQBRACKET ASSIGNMENT expression_statement {
                                                                                        printf("Testing Here 5\n");
                                                                                        if(check_declaration($1.name) == 0 || isArray($1.name) == 0)
                                                                                        {
                                                                                            printf("Error: Variable %s is not an array at line %d\n", $1.name, yylineno);
                                                                                            exit(1);
                                                                                        }
                                                                                        if(check_declaration($3.name) == 0 || isArray($3.name) == 1)
                                                                                        {
                                                                                            printf("Error: Variable %s not declared at line %d\n", $3.name, yylineno);
                                                                                            exit(1);
                                                                                        }
                                                                                        printf("Types of %s is %s\n", get_type($1.name), $9.type);
                                                                                        if(strcmp(get_type($1.name), $9.type) != 0)
                                                                                        {
                                                                                            printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                            exit(1);
                                                                                        }
                                                                                        $1.nd = mknode(NULL, NULL, $1.name);
                                                                                        $2.nd = mknode($1.nd, $3.nd, "LSQBRACKET");
                                                                                        $4.nd = mknode($2.nd, $5.nd, "RSQBRACKET");
                                                                                        $9.nd = mknode($4.nd, NULL, "ASSIGNMENT");
                                                                                        $$.nd = mknode($9.nd, NULL, "assignment_statement");
                                                                                    }
                | ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT expression_statement {
                                                                                                                    printf("Testing Here 6\n");
                                                                                                                    if(check_declaration($1.name) == 0 || isArray($1.name) == 0)
                                                                                                                    {
                                                                                                                        printf("Error: Variable %s is not an array at line %d\n", $1.name, yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    printf("Types of %s is %s\n", get_type($1.name), $9.type);
                                                                                                                    if(strcmp(get_type($1.name), $9.type) != 0)
                                                                                                                    {
                                                                                                                        printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    $1.nd = mknode(NULL, NULL, $1.name);
                                                                                                                    $2.nd = mknode($1.nd, $3.nd, "LSQBRACKET");
                                                                                                                    $4.nd = mknode($2.nd, $5.nd, "RSQBRACKET");
                                                                                                                    $9.nd = mknode($4.nd, NULL, "ASSIGNMENT");
                                                                                                                    $$.nd = mknode($9.nd, NULL, "assignment_statement");
                                                                                                                }
                | ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET ID RSQBRACKET ASSIGNMENT expression_statement {
                                                                                                                    printf("Testing Here 7\n");
                                                                                                                    if(check_declaration($1.name) == 0 || isArray($1.name) == 0)
                                                                                                                    {
                                                                                                                        printf("Error: Variable %s is not an array at line %d\n", $1.name, yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    if(check_declaration($3.name) == 0 || isArray($3.name) == 1)
                                                                                                                    {
                                                                                                                        printf("Error: Variable %s not declared at line %d\n", $3.name, yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    printf("Types of %s is %s\n", get_type($1.name), $9.type);
                                                                                                                    if(strcmp(get_type($1.name), $9.type) != 0)
                                                                                                                    {
                                                                                                                        printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    $1.nd = mknode(NULL, NULL, $1.name);
                                                                                                                    $2.nd = mknode($1.nd, $3.nd, "LSQBRACKET");
                                                                                                                    $4.nd = mknode($2.nd, $5.nd, "RSQBRACKET");
                                                                                                                    $9.nd = mknode($4.nd, NULL, "ASSIGNMENT");
                                                                                                                    $$.nd = mknode($9.nd, NULL, "assignment_statement");
                                                                                                                }                                                                   
        ;
 
for_initializer:
        type_specifier ID   {   
                                printf("Variable %s declared at line %d\n", $2.name, yylineno);
                                if(check_declaration($2.name) == 1)
                                {
                                    printf("Error: Variable %s not declared at line %d\n", $2.name, yylineno);
                                    exit(1);
                                }
                                yytext = malloc(sizeof(char)*strlen($2.name));
                                strcpy(yytext,$2.name);
                                add('V');
                                printf("Added\n");
                            }
                            ASSIGNMENT expression_statement SEMICOLON   {
                                                                            $4.nd = mknode(NULL,NULL,"Semicolon") ; 
                                                                            struct node *temp = mknode($1.nd, $2.nd, "for_initializer");
                                                                            $$.nd = mknode(temp, $4.nd, "for_initializer_structure");

                                                                            sprintf(icg[ic_idx++], "%s = t%d\n", $2.name, $5.t);
                                                                        }
        |   assignment_statement_2 SEMICOLON    {
                                                    $2.nd = mknode(NULL,NULL,"Semicolon") ;
                                                    $$.nd = mknode($1.nd, $2.nd, "for_initializer");
                                                }
        |   SEMICOLON   {
                            $1.nd = mknode(NULL,NULL,"Semicolon") ;
                            $$.nd = mknode($1.nd, NULL, "for_initializer");
                        }
        ;
 
for_condition:
        expression_statement SEMICOLON  {
                                            $2.nd = mknode(NULL,NULL,"Semicolon") ;
                                            $$.nd = mknode($1.nd, $2.nd, "for_condition");

                                            //here checker
                                            // $$.if_body = $1.if_body;
                                            // $$.else_body = $1.else_body;
                                        }
        |   SEMICOLON   {
                            $1.nd = mknode(NULL,NULL,"Semicolon") ;
                            $$.nd = mknode($1.nd, NULL, "for_condition");
                        }
        ;
 
for_update:
        assignment_statement_2  {   $$.nd = mknode($1.nd, NULL, "for_update"); /*for_up = 1;*/ }
        | { $$.nd = mknode(NULL, NULL, "for_update"); }
        ;
 
while_statement:
        WHILE LPAREN expression_statement RPAREN {
            nextTable();
        } LBRACE loop_stat_list RBRACE    {     prevTable();
                                                $$.nd = mknode($3.nd, $7.nd, "while_statement");    
                                        }
        ;

loop_stat_list:
        statement   {   $$.nd = mknode($1.nd, NULL, "loop_stat_list");  }
        |   statement loop_stat_list    {  printf("222\n"); $$.nd = mknode($1.nd, $2.nd, "loop_stat_list");   }
        |   BREAK SEMICOLON {   
                                $1.nd = mknode(NULL, NULL, "BREAK");
                                $2.nd = mknode(NULL, NULL, "SEMICOLON");
                                $$.nd = mknode($1.nd, $2.nd, "loop_stat_list");
                            }
        |   BREAK SEMICOLON loop_stat_list  {   
                                                $1.nd = mknode(NULL, NULL, "BREAK");
                                                $2.nd = mknode(NULL, NULL, "SEMICOLON");
                                                struct node* temp = mknode($1.nd, $2.nd, "break_stat");
                                                $$.nd = mknode(temp, $3.nd, "loop_stat_list");
                                            }
        |   CONTINUE SEMICOLON  {   
                                    $1.nd = mknode(NULL, NULL, "CONTINUE");
                                    $2.nd = mknode(NULL, NULL, "SEMICOLON");
                                    $$.nd = mknode($1.nd, $2.nd, "loop_stat_list");
                                }
        |   CONTINUE SEMICOLON loop_stat_list   {   
                                                    $1.nd = mknode(NULL, NULL, "CONTINUE");
                                                    $2.nd = mknode(NULL, NULL, "SEMICOLON");
                                                    struct node* temp = mknode($1.nd, $2.nd, "continue_stat");
                                                    $$.nd = mknode(temp, $3.nd, "loop_stat_list");
                                                }
        | {$$.nd = mknode(NULL, NULL, "loop_stat_list");}
        ;
 

switch_statement:
        SWITCH LPAREN expression_statement RPAREN {
            nextTable();
        } LBRACE switch_case_list RBRACE {   
            $$.nd = mknode($3.nd, $6.nd, "switch_statement");   
            prevTable();
        }
        ;
 
switch_case_list:
        switch_case {   $$.nd = mknode($1.nd, NULL, "switch_case_list");    }
        |   switch_case switch_case_list    {   $$.nd = mknode($1.nd, $2.nd, "switch_case_list");   }
        ;
 
switch_case:
        CASE constant COLON loop_stat_list  {
                                                struct node* temp1 = mknode($1.nd, $2.nd, "Case");
                                                struct node* temp2 = mknode($3.nd, $4.nd, "Statement_List");
                                                $$.nd = mknode(temp1, temp2, "switch_case");
                                            }
        |   DEFAULT COLON loop_stat_list    {
                                                struct node* temp1 = mknode($1.nd, NULL, "Default");
                                                struct node* temp2 = mknode($2.nd, $3.nd, "Statement_List");
                                                $$.nd = mknode(temp1, temp2, "switch_case");
                                            }
        ;
 
print: PRINTF LPAREN stringconst plist  RPAREN SEMICOLON    { 
            if(currentPrintfArgumentIndex<FormatSpecifierListIndex){
                printf("Error: Too few arguments for printf\n");
                exit(1);
            } 
            currentPrintfArgumentIndex=0;
            clearFormatSpecifierList();
            $$.nd = mknode($3.nd, NULL, "print");    
        }
        ;
 
stringconst: STR {
    countOfFormatSpecifiers($1.name);
    $$.nd = mknode(NULL, NULL, "STR");
    printf("\nString is 1 %s\n", $1.name);
    $$.sz = strlen($1.name)-2;
    printf("$$ size is %d\n", $$.sz);
}
;
 
plist: COMMA ID {
                    if(check_declaration($2.name)==0 && isArray($1.name)==0){
                        printf("Error: Undeclared variable %s\n", $2.name);
                        exit(1);
                    }
                    if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                        printf("Error: Too many arguments for printf\n");
                        exit(1);
                    }
                    if(strcmp(get_type($2.name),"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                        exit(1);
                    }
                    else if(strcmp(get_type($2.name),"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                        exit(1);
                    }
                    else if(strcmp(get_type($2.name),"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                        exit(1);
                    }
                    currentPrintfArgumentIndex++;
                    printf("currentPrintfArgumentIndex is %d\n", currentPrintfArgumentIndex);
                    printf("FormatSpecifierListIndex is %d\n", FormatSpecifierListIndex);
                    // if(currentPrintfArgumentIndex<FormatSpecifierListIndex){
                    //     printf("Error: Too few arguments for printf\n");
                    //     exit(1);
                    // }
                    $2.nd = mknode(NULL, NULL, $2.name);
                    $$.nd = mknode($2.nd, $$.nd, "plist");
}
    | COMMA ID plist {
                        if(check_declaration($2.name)==0 && isArray($1.name)==0){
                            printf("Error: Undeclared variable %s\n", $2.name);
                            exit(1);
                        }
                        if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                            printf("Error: Too many arguments for printf\n");
                            exit(1);
                        }
                        if(strcmp(get_type($2.name),"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        else if(strcmp(get_type($2.name),"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        else if(strcmp(get_type($2.name),"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        currentPrintfArgumentIndex++;
                        $2.nd = mknode(NULL, NULL, $2.name);
                        struct node* temp = mknode($1.nd, $2.nd, "ID");
                        $$.nd = mknode(temp, $3.nd, "plist");
    }
    | COMMA ID LSQBRACKET NUMBER RSQBRACKET{
                                        if(check_declaration($2.name)==0 && isArray($2.name)==1){
                                            printf("Error: Undeclared variable %s\n", $1.name);
                                            exit(1);
                                        }
                                        if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                                            printf("Error: Too many arguments for printf\n");
                                            exit(1);
                                        }
                                        if(strcmp(get_type($2.name),"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                                            printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                            exit(1);
                                        }
                                        else if(strcmp(get_type($2.name),"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                                            printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                            exit(1);
                                        }
                                        else if(strcmp(get_type($2.name),"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                                            printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                            exit(1);
                                        }
                                        currentPrintfArgumentIndex++;
                                        $2.nd = mknode(NULL, NULL, $2.name);
                                        $$.nd = mknode($1.nd, NULL, "plist");
                                    }
    | COMMA ID LSQBRACKET NUMBER RSQBRACKET plist {
                                                if(check_declaration($2.name)==0 && isArray($2.name)==1){
                                                    printf("Error: Undeclared variable %s\n", $2.name);
                                                    exit(1);
                                                }
                                                if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                                                    printf("Error: Too many arguments for printf\n");
                                                    exit(1);
                                                }
                                                if(strcmp(get_type($2.name),"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                                                    printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                                    exit(1);
                                                }
                                                else if(strcmp(get_type($2.name),"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                                                    printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                                    exit(1);
                                                }
                                                else if(strcmp(get_type($1.name),"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                                                    printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                                    exit(1);
                                                }
                                                currentPrintfArgumentIndex++;
                                                $2.nd = mknode(NULL, NULL, $2.name);
                                                $$.nd = mknode($2.nd, $6.nd, "plist");
                                            }
    | COMMA constant {
                    if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                        printf("Error: Too many arguments for printf\n");
                        exit(1);
                    }
                    if(strcmp($2.type,"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                        printf("Error: Format specifier mismatch for argument %d\n",currentPrintfArgumentIndex+1);
                        exit(1);
                    }
                    else if(strcmp($2.type,"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                        printf("Error: Format specifier mismatch for argument %d\n",currentPrintfArgumentIndex+1);
                        exit(1);
                    }
                    else if(strcmp($2.type,"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                        printf("Error: Format specifier mismatch for argument %d\n",currentPrintfArgumentIndex+1);
                        exit(1);
                    }
                    currentPrintfArgumentIndex++;
                    $$.nd = mknode($2.nd, NULL, "plist");
                }
    | COMMA constant plist{
                        printf("currentPrintfArgumentIndex is %d\n", currentPrintfArgumentIndex);
                        printf("FormatSpecifierListIndex is %d\n", FormatSpecifierListIndex);
                        if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                            printf("Error: Too many arguments for printf\n");
                            exit(1);
                        }
                        if(strcmp($2.type,"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        else if(strcmp($2.type,"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        else if(strcmp($2.type,"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        currentPrintfArgumentIndex++;
                        printf("currentPrintfArgumentIndex is %d\n", currentPrintfArgumentIndex);
                        printf("FormatSpecifierListIndex is %d\n", FormatSpecifierListIndex);
                        $$.nd = mknode($2.nd, $3.nd, "plist");
                    }
    |{
        $$.nd = mknode(NULL, NULL, "plist");
    }
    ;
 
return_statement:
        RETURN expression_statement SEMICOLON   {
                                                    check_declaration(currentFunction);
                                                    // printf("Current function is %s\n",currentFunction);
                                                    if(strcmp(get_type(currentFunction),$2.type)!=0){
                                                        printf("Error: Return type mismatch for function %s\n",currentFunction);
                                                        exit(1);
                                                    }
                                                    $3.nd = mknode(NULL,NULL,"SEMICOLON");
                                                    $1.nd = mknode(NULL, NULL, "RETURN");
                                                    struct node *temp = mknode($1.nd, $2.nd, "return_statement");
                                                    $$.nd = mknode(temp, $3.nd, "return_statement_structure");
                                                }
        |  RETURN SEMICOLON    {
                                    check_declaration(currentFunction);
                                    if(strcmp(get_type(currentFunction),"void")!=0){
                                        printf("Error: Return type mismatch for function %s\n",currentFunction);
                                        exit(1);
                                    }
                                    $2.nd = mknode(NULL,NULL,"SEMICOLON");
                                    $1.nd = mknode(NULL, NULL, "RETURN");
                                    $$.nd = mknode($1.nd, $2.nd, "return_statement_structure");
                                }
        ;
 
compound_statement:
        {                                            
            nextTable();
        } LBRACE statement_list RBRACE    {   
                                            $$.nd = mknode($3.nd, NULL, "compound_statement");
                                            prevTable();
                                        }
        ;
%%
 
int main() {
    yyparse();
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
    printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
    printf("_______________________________________\n\n");
    int i=0; 
    for(i=0; i<count; i++) {
        printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
    }
    for(i=0;i<count;i++) {
        free(symbol_table[i].id_name);
        free(symbol_table[i].type);
    }
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
    printf("\t\t\t\t\t\t\t\t PHASE 3: SEMANTIC ANALYSIS \n\n");
    print_tree(head); 
    printf("\n\n\n\n");
    if(sem_errors>0) {
        printf("Semantic analysis completed with %d errors\n", sem_errors);
        for(int i=0; i<sem_errors; i++){
            printf("\t - %s", errors[i]);
        }
    } else {
        printf("Semantic analysis completed with no errors");
    }
    printf("\n\n");
    printf("\t\t\t\t\t\t\t   PHASE 4: INTERMEDIATE CODE GENERATION \n\n");
    for(int i=0; i<ic_idx; i++){
        printf("%s", icg[i]);
    }
    printf("\n\n");
}
 
int search(char *type) {
    int i;
    printf("Type is %s\n",type);
    for(i=count-1; i>=0; i--) {
        printf("Checking local symbol table %s\n",symbol_table[i].id_name);
        if(strcmp(symbol_table[i].id_name, type)==0) {
            return -1;
            break;
        }
    }
    printf("Checking global scope now\n");
    for(int i=0;i<countStorageIndex;i++){
        printf("Count storage is %d\n",countStorage[i]);
    }
    int j=countStorageIndex-1;
    while(j>=0){
        printf("j is %d\n",j);
        int local_count=countStorage[j];
        printf("Local count is %d\n",local_count);
        for(i=local_count-1;i>=0;i--){
            printf("Checking global symbol table %s\n",symbol_table_global[j][i].id_name);
            if(strcmp(symbol_table_global[j][i].id_name, type)==0) {
                printf("Here\n");
                return -1;
            }
        }
        j--;
    }
    return 0;
}
 
int check_declaration(char *c) {
    q = search(c);
    if(!q) {
        /* sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", countn+1, c);
        sem_errors++; */
        return 0;
    }
    return 1;
}
 
void check_return_type(char *value) {
    char *main_datatype = get_type("main");
    char *return_datatype = get_type(value);
    if((!strcmp(main_datatype, "int") && !strcmp(return_datatype, "CONST")) || !strcmp(main_datatype, return_datatype)){
        return ;
    }
    else {
        sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", countn+1);
        sem_errors++;
    }
}
 
int check_types(char *type1, char *type2){
    // declaration with no init
    if(!strcmp(type2, "null"))
        return -1;
    // both datatypes are same
    if(!strcmp(type1, type2))
        return 0;
    // both datatypes are different
    if(!strcmp(type1, "int") && !strcmp(type2, "float"))
        return 1;
    if(!strcmp(type1, "float") && !strcmp(type2, "int"))
        return 2;
    if(!strcmp(type1, "int") && !strcmp(type2, "char"))
        return 3;
    if(!strcmp(type1, "char") && !strcmp(type2, "int"))
        return 4;
    if(!strcmp(type1, "float") && !strcmp(type2, "char"))
        return 5;
    if(!strcmp(type1, "char") && !strcmp(type2, "float"))
        return 6;
}
 
char *get_type(char *var){
    if(!strcmp(var,"int") || !strcmp(var,"float") || !strcmp(var,"char")){
        return var;
    }
    for(int i=0; i<count; i++) {
        // Handle case of use before declaration
        if(!strcmp(symbol_table[i].id_name, var)) {
            return symbol_table[i].data_type;
        }
    }
    int j=countStorageIndex-1;
    while(j>=0){
        int local_count=countStorage[j];
        for(int i=local_count-1;i>=0;i--){
            if(!strcmp(symbol_table_global[j][i].id_name, var)) {
                return symbol_table_global[j][i].data_type;
            }
        }
        j--;
    }

}

int searchLocal(char *type) {
    int i;
    printf("Type is %s\n",type);
    for(i=count-1; i>=0; i--) {
        printf("Checking local symbol table %s\n",symbol_table[i].id_name);
        if(strcmp(symbol_table[i].id_name, type)==0) {
            return -1;
        }
    }
    return 0;
}

void add(char c) {
    printf("Searching for %s\n", yytext);
    if(c == 'V' || c== 'A'){
        for(int i=0; i<10; i++){
            if(!strcmp(reserved[i], strdup(yytext))){
                sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword!\n", countn+1, yytext);
                sem_errors++;
                return;
            }
        }
    }
    q=searchLocal(yytext);
    printf("q=%d\n", q);
    if(!q) {
        if(c == 'H') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Header");
            count++;
        }
        else if(c == 'K') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup("N/A");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Keyword\t");
            count++;
        }
        else if(c == 'V') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Variable");
            count++;
        }
        else if(c == 'C') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup("CONST");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Constant");
            count++;
        }
        else if(c == 'F') {
            printf("Inserting function\n");
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Function");
            count++;
            printf("Count is %d\n", count);
        }
        else if(c == 'A') {
            symbol_table[count].id_name=strdup(yytext);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Array");
            count++;
        }
    }
    else if((c == 'V' || c == 'A') && q) {
        sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed!\n", countn+1, yytext);
        sem_errors++;
    }
}
 
struct node* mknode(struct node *left, struct node *right, char *token) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    char *newstr = (char *)malloc(strlen(token)+1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return(newnode);
}
 
char* printtreestring(struct node* n, char* str) {
    char* comb = malloc(sizeof(char) * (strlen(str) + 1 + 1));
    strcpy(comb, str);
    strcat(comb, "[");
    str = malloc(sizeof(char) * (strlen(comb) + strlen(n->token) + 1));
    strcpy(str, comb);
    strcat(str, n->token);

    if(n->left != NULL) {
        char* ans = printtreestring(n->left, str);
        str = ans;
        comb = malloc(sizeof(char) * (strlen(str) + 1 ));
        strcpy(comb, str);
        str = comb;
    }
 
    if(n->right != NULL) {
        char* ans = printtreestring(n->right, str);
        str = ans;
        comb = malloc(sizeof(char) * (strlen(str) + 1 ));
        strcpy(comb, str);
        str = comb;
    }
 
    comb = malloc(sizeof(char) * (strlen(str) + 1 + 1));
    strcpy(comb, str);
    strcat(comb, "]");
    str = comb;
}
 
void print_tree(struct node* tree) {
    printf("\n\nInorder traversal of the Parse Tree is: \n\n");
    if(tree==NULL){
        printf("Empty Tree due to syntax error\n");
        return;
    }
    printf("%s\n",printtreestring(tree, ""));
    /* print_inorder(tree); */
}
 
void print_inorder(struct node *tree) {
    int i;
    if (tree->left) {
        print_inorder(tree->left);
    }
    printf("%s, ", tree->token);
    if (tree->right) {
        print_inorder(tree->right);
    }
}

void checkFinalArguments(char *name){
    int i;
    for(i=count-1; i>=0; i--) {
        if(strcmp(symbol_table[i].id_name, name)==0) {
            printf("Found function %s\n", name);
            printf("Number of arguments: %d\n", symbol_table[i].arg_count);
            if(currentArgumentIndex<symbol_table[i].arg_count){
                sprintf(errors[sem_errors], "Line %d: Too few arguments passed to function \"%s\"!\n", countn+1, name);
                sem_errors++;
                return;
            }
            return;
        }
    }

    int j=countStorageIndex-1;
    while(j>=0){
        int local_count=countStorage[j];
        for(int i=local_count-1;i>=0;i--){
            if(strcmp(symbol_table_global[j][i].id_name, name)==0) {
                if(currentArgumentIndex<symbol_table_global[j][i].arg_count){
                    sprintf(errors[sem_errors], "Line %d: Too few arguments passed to function \"%s\"!\n", countn+1, name);
                    sem_errors++;
                    return;
                }
                return;
            }
        }
        j--;
    }
    sprintf(errors[sem_errors], "Line %d: Function \"%s\" not found!\n", countn+1, name);
    sem_errors++;
    return;
}

void check_Argument(char *type){
    int i;
    printf("Type is %s\n", type);
    for(i=count-1; i>=0; i--) {
        if(strcmp(symbol_table[i].id_name, currentFunction)==0) {
            if(currentArgumentIndex>=symbol_table[i].arg_count){
                sprintf(errors[sem_errors], "Line %d: Too many arguments passed to function \"%s\"!\n", countn+1, currentFunction);
                sem_errors++;
                return;
            }
            if(strcmp(type,"char")==0 || strcmp(get_type(type),"char")==0){
                if(symbol_table[i].functionCallArguments[currentArgumentIndex]!=1){
                    printf( "Line %d: Argument type mismatch in function \"%s\"!\n", countn+1, currentFunction);
                    exit(1);
                }
                currentArgumentIndex++;
                return;
            }
            else if(strcmp(type,"int")==0 || strcmp(get_type(type),"int")==0){
                if(symbol_table[i].functionCallArguments[currentArgumentIndex]!=2){
                    printf( "Line %d: Argument type mismatch in function \"%s\"!\n", countn+1, currentFunction);
                    exit(1);
                }
                currentArgumentIndex++;
                return;
            }
            else if(strcmp(type,"float")==0 || strcmp(get_type(type),"float")==0){
                if(symbol_table[i].functionCallArguments[currentArgumentIndex]!=3){
                    printf( "Line %d: Argument type mismatch in function \"%s\"!\n", countn+1, currentFunction);
                    exit(1);
                }
                currentArgumentIndex++;
                return;
            }
        }
    }
    printf("Checking global scope now\n");
    int j=countStorageIndex-1;
    while(j>=0){
        int local_count=countStorage[j];
        for(i=local_count-1;i>=0;i--){
            if(strcmp(symbol_table_global[j][i].id_name, currentFunction)==0) {
                if(currentArgumentIndex>=symbol_table_global[j][i].arg_count){
                    printf( "Line %d: Argument type mismatch in function \"%s\"!\n", countn+1, currentFunction);
                    exit(1);
                }
                printf("Inside global scope\n");
                printf("Type is %s\n", type);
                printf("String compare is %d\n", strcmp(type,"int"));
                if(strcmp(type,"char")==0 || strcmp(get_type(type),"char")==0){
                    if(symbol_table_global[j][i].functionCallArguments[currentArgumentIndex]!=1){
                        printf( "Line %d: Argument type mismatch in function \"%s\"!\n", countn+1, currentFunction);
                        exit(1);
                    }
                    currentArgumentIndex++;
                    return;
                }
                else if(strcmp(type,"int")==0 || strcmp(get_type(type),"int")==0){
                    printf("Inside int\n");
                    if(symbol_table_global[j][i].functionCallArguments[currentArgumentIndex]!=2){
                        printf( "Line %d: Argument type mismatch in function \"%s\"!\n", countn+1, currentFunction);
                        exit(1);
                    }
                    currentArgumentIndex++;
                    return;
                }
                else if(strcmp(type,"float")==0 || strcmp(get_type(type),"float")==0){
                    if(symbol_table_global[j][i].functionCallArguments[currentArgumentIndex]!=3){
                        printf( "Line %d: Argument type mismatch in function \"%s\"!\n", countn+1, currentFunction);
                        exit(1);
                    }
                    currentArgumentIndex++;
                    return;
                }
            }
        }
        j--;
    }
}

void addArgument(char *name,char *type){
    int i;
    for(i=count-1; i>=0; i--) {
        printf("symbol table name is %s\n", symbol_table[i].id_name);
        if(strcmp(symbol_table[i].id_name, currentFunction)==0) {
            if(strcmp(type,"char")==0){
                symbol_table[i].functionCallArguments[symbol_table[i].arg_count]=1;
                symbol_table[i].arg_count++;
                return;
            }
            else if(strcmp(type,"int")==0){
                symbol_table[i].functionCallArguments[symbol_table[i].arg_count]=2;
                symbol_table[i].arg_count++;
                printf("Added argument to function %s\n", currentFunction);
                printf("Argument count is %d\n", symbol_table[i].arg_count);
                printf("global scope is %d\n", currentScope_global);
                return;
            }
            else if(strcmp(type,"float")==0){
                symbol_table[i].functionCallArguments[symbol_table[i].arg_count]=3;
                symbol_table[i].arg_count++;
                return;
            }
            else {
                printf("Invalid Type Specifier in Function Argument\n");
                exit(1);
            }
        }
    }
    printf("Checking global scope now\n");
    int j=currentScope_global-1;
    while(j>=0){
        int local_count=countStorage[countStorageIndex-1];
        for(i=local_count-1;i>=0;i--){
            if(strcmp(symbol_table_global[j][i].id_name, currentFunction)==0) {
                printf("Found function %s\n", currentFunction);
                if(strcmp(type,"char")==0){
                    symbol_table_global[j][i].functionCallArguments[symbol_table_global[j][i].arg_count]=1;
                    symbol_table_global[j][i].arg_count++;
                    return;
                }
                else if(strcmp(type,"int")==0){
                    symbol_table_global[j][i].functionCallArguments[symbol_table_global[j][i].arg_count]=2;
                    symbol_table_global[j][i].arg_count++;
                    return;
                }
                else if(strcmp(type,"float")==0){
                    symbol_table_global[j][i].functionCallArguments[symbol_table_global[j][i].arg_count]=3;
                    symbol_table_global[j][i].arg_count++;
                    return;
                }
                else {
                    printf("Invalid Type Specifier in Function Argument\n");
                    exit(1);
                }
            }
        }
        j--;
    }
    printf("Error in adding argument\n");
    exit(1);
}

int isArray(char *name){
    printf("In isArray\n");
    for(int i=0;i<count;i++){
        printf("symbol table name is %s\n", symbol_table[i].id_name);
        if(!strcmp(symbol_table[i].id_name,name)){
            if(!strcmp(symbol_table[i].type,"Array")){
                printf("Yes, %s is an array\n",name);
                return 1;
            }
        }
    }
    printf("Checking global scope now\n");
    int j=countStorageIndex-1;
    while(j>=0){
        int local_count=countStorage[j];
        for(int i=local_count-1;i>=0;i--){
            if(!strcmp(symbol_table_global[j][i].id_name,name)){
                if(!strcmp(symbol_table_global[j][i].type,"Array")){
                    printf("Yes, %s is an array\n",name);
                    return 1;
                }
            }
        }
        j--;
    }
    printf("No, %s is not an array\n",name);
    return 0;
}
 
void insert_type() {
    strcpy(type, yytext);
}
 
void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}