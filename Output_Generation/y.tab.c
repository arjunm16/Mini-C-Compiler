/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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
    void getOutput();
    char *get_type(char *);
    int isArray(char *);
    void addArgument(char *,char *);
    void propogateValue(struct node * head);
    void check_Argument(char *);
    void clearFormatSpecifierList();
    void checkFinalArguments(char *);
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
        int to_print;
    };
 

#line 290 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VOID = 258,                    /* VOID  */
    INT = 259,                     /* INT  */
    FLOAT = 260,                   /* FLOAT  */
    CHAR = 261,                    /* CHAR  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    FOR = 264,                     /* FOR  */
    WHILE = 265,                   /* WHILE  */
    SWITCH = 266,                  /* SWITCH  */
    CASE = 267,                    /* CASE  */
    DEFAULT = 268,                 /* DEFAULT  */
    PRINTF = 269,                  /* PRINTF  */
    SCANF = 270,                   /* SCANF  */
    RETURN = 271,                  /* RETURN  */
    TRUE = 272,                    /* TRUE  */
    FALSE = 273,                   /* FALSE  */
    INCLUDE = 274,                 /* INCLUDE  */
    STR = 275,                     /* STR  */
    STRCONST = 276,                /* STRCONST  */
    FLOAT_NUM = 277,               /* FLOAT_NUM  */
    EXPONENT = 278,                /* EXPONENT  */
    MAIN = 279,                    /* MAIN  */
    ID = 280,                      /* ID  */
    BREAK = 281,                   /* BREAK  */
    CONTINUE = 282,                /* CONTINUE  */
    NUMBER = 283,                  /* NUMBER  */
    CHARACTER = 284,               /* CHARACTER  */
    ASSIGNMENT = 285,              /* ASSIGNMENT  */
    NOT = 286,                     /* NOT  */
    AND = 287,                     /* AND  */
    OR = 288,                      /* OR  */
    EQ = 289,                      /* EQ  */
    NE = 290,                      /* NE  */
    LT = 291,                      /* LT  */
    LE = 292,                      /* LE  */
    GT = 293,                      /* GT  */
    GE = 294,                      /* GE  */
    ADD = 295,                     /* ADD  */
    SUB = 296,                     /* SUB  */
    MUL = 297,                     /* MUL  */
    DIV = 298,                     /* DIV  */
    MOD = 299,                     /* MOD  */
    LSQBRACKET = 300,              /* LSQBRACKET  */
    RSQBRACKET = 301,              /* RSQBRACKET  */
    LPAREN = 302,                  /* LPAREN  */
    RPAREN = 303,                  /* RPAREN  */
    LBRACE = 304,                  /* LBRACE  */
    RBRACE = 305,                  /* RBRACE  */
    SEMICOLON = 306,               /* SEMICOLON  */
    COMMA = 307,                   /* COMMA  */
    COLON = 308                    /* COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define VOID 258
#define INT 259
#define FLOAT 260
#define CHAR 261
#define IF 262
#define ELSE 263
#define FOR 264
#define WHILE 265
#define SWITCH 266
#define CASE 267
#define DEFAULT 268
#define PRINTF 269
#define SCANF 270
#define RETURN 271
#define TRUE 272
#define FALSE 273
#define INCLUDE 274
#define STR 275
#define STRCONST 276
#define FLOAT_NUM 277
#define EXPONENT 278
#define MAIN 279
#define ID 280
#define BREAK 281
#define CONTINUE 282
#define NUMBER 283
#define CHARACTER 284
#define ASSIGNMENT 285
#define NOT 286
#define AND 287
#define OR 288
#define EQ 289
#define NE 290
#define LT 291
#define LE 292
#define GT 293
#define GE 294
#define ADD 295
#define SUB 296
#define MUL 297
#define DIV 298
#define MOD 299
#define LSQBRACKET 300
#define RSQBRACKET 301
#define LPAREN 302
#define RPAREN 303
#define LBRACE 304
#define RBRACE 305
#define SEMICOLON 306
#define COMMA 307
#define COLON 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 220 "parser.y"
 struct var_name { 
            char name[100]; 
            struct node* nd;
            int t;
            int to_print;
            int value;
        } nd_obj;
 
        struct var_name2 { 
            char name[100]; 
            struct node* nd;
            char type[5];
            int t;
            int to_print;
            int value;
        } nd_obj2; 
 
        struct var_name3 {
            char name[100];
            struct node* nd;
            int t;
            char type[5];
            char if_body[5];
            char else_body[5];
            int to_print;
            int value;
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
    

#line 492 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_SWITCH = 11,                    /* SWITCH  */
  YYSYMBOL_CASE = 12,                      /* CASE  */
  YYSYMBOL_DEFAULT = 13,                   /* DEFAULT  */
  YYSYMBOL_PRINTF = 14,                    /* PRINTF  */
  YYSYMBOL_SCANF = 15,                     /* SCANF  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_TRUE = 17,                      /* TRUE  */
  YYSYMBOL_FALSE = 18,                     /* FALSE  */
  YYSYMBOL_INCLUDE = 19,                   /* INCLUDE  */
  YYSYMBOL_STR = 20,                       /* STR  */
  YYSYMBOL_STRCONST = 21,                  /* STRCONST  */
  YYSYMBOL_FLOAT_NUM = 22,                 /* FLOAT_NUM  */
  YYSYMBOL_EXPONENT = 23,                  /* EXPONENT  */
  YYSYMBOL_MAIN = 24,                      /* MAIN  */
  YYSYMBOL_ID = 25,                        /* ID  */
  YYSYMBOL_BREAK = 26,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 27,                  /* CONTINUE  */
  YYSYMBOL_NUMBER = 28,                    /* NUMBER  */
  YYSYMBOL_CHARACTER = 29,                 /* CHARACTER  */
  YYSYMBOL_ASSIGNMENT = 30,                /* ASSIGNMENT  */
  YYSYMBOL_NOT = 31,                       /* NOT  */
  YYSYMBOL_AND = 32,                       /* AND  */
  YYSYMBOL_OR = 33,                        /* OR  */
  YYSYMBOL_EQ = 34,                        /* EQ  */
  YYSYMBOL_NE = 35,                        /* NE  */
  YYSYMBOL_LT = 36,                        /* LT  */
  YYSYMBOL_LE = 37,                        /* LE  */
  YYSYMBOL_GT = 38,                        /* GT  */
  YYSYMBOL_GE = 39,                        /* GE  */
  YYSYMBOL_ADD = 40,                       /* ADD  */
  YYSYMBOL_SUB = 41,                       /* SUB  */
  YYSYMBOL_MUL = 42,                       /* MUL  */
  YYSYMBOL_DIV = 43,                       /* DIV  */
  YYSYMBOL_MOD = 44,                       /* MOD  */
  YYSYMBOL_LSQBRACKET = 45,                /* LSQBRACKET  */
  YYSYMBOL_RSQBRACKET = 46,                /* RSQBRACKET  */
  YYSYMBOL_LPAREN = 47,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 48,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 49,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 50,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 51,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 52,                     /* COMMA  */
  YYSYMBOL_COLON = 53,                     /* COLON  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_datatype = 56,                  /* datatype  */
  YYSYMBOL_program_body = 57,              /* program_body  */
  YYSYMBOL_functions = 58,                 /* functions  */
  YYSYMBOL_function = 59,                  /* function  */
  YYSYMBOL_60_1 = 60,                      /* $@1  */
  YYSYMBOL_61_2 = 61,                      /* $@2  */
  YYSYMBOL_62_3 = 62,                      /* $@3  */
  YYSYMBOL_arglist = 63,                   /* arglist  */
  YYSYMBOL_64_4 = 64,                      /* $@4  */
  YYSYMBOL_args = 65,                      /* args  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_main = 67,                      /* main  */
  YYSYMBOL_68_6 = 68,                      /* $@6  */
  YYSYMBOL_statement_list = 69,            /* statement_list  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_calling_list = 71,              /* calling_list  */
  YYSYMBOL_72_7 = 72,                      /* $@7  */
  YYSYMBOL_73_8 = 73,                      /* $@8  */
  YYSYMBOL_declaration_statement = 74,     /* declaration_statement  */
  YYSYMBOL_type_specifier = 75,            /* type_specifier  */
  YYSYMBOL_var_list = 76,                  /* var_list  */
  YYSYMBOL_77_9 = 77,                      /* $@9  */
  YYSYMBOL_arr_dec = 78,                   /* arr_dec  */
  YYSYMBOL_multiple_num_list = 79,         /* multiple_num_list  */
  YYSYMBOL_multiple_character_list = 80,   /* multiple_character_list  */
  YYSYMBOL_multiple_float_num_list = 81,   /* multiple_float_num_list  */
  YYSYMBOL_braced_num_list = 82,           /* braced_num_list  */
  YYSYMBOL_braced_character_list = 83,     /* braced_character_list  */
  YYSYMBOL_braced_float_num_list = 84,     /* braced_float_num_list  */
  YYSYMBOL_number_list = 85,               /* number_list  */
  YYSYMBOL_character_list = 86,            /* character_list  */
  YYSYMBOL_stringconst_list = 87,          /* stringconst_list  */
  YYSYMBOL_float_num_list = 88,            /* float_num_list  */
  YYSYMBOL_assignment_statement = 89,      /* assignment_statement  */
  YYSYMBOL_90_10 = 90,                     /* $@10  */
  YYSYMBOL_expression_statement = 91,      /* expression_statement  */
  YYSYMBOL_logical_o_exp = 92,             /* logical_o_exp  */
  YYSYMBOL_logical_a_exp = 93,             /* logical_a_exp  */
  YYSYMBOL_relational_exp = 94,            /* relational_exp  */
  YYSYMBOL_additive_exp = 95,              /* additive_exp  */
  YYSYMBOL_multiplicative_exp = 96,        /* multiplicative_exp  */
  YYSYMBOL_negation_exp = 97,              /* negation_exp  */
  YYSYMBOL_access_call_exp = 98,           /* access_call_exp  */
  YYSYMBOL_99_11 = 99,                     /* $@11  */
  YYSYMBOL_primary_exp = 100,              /* primary_exp  */
  YYSYMBOL_constant = 101,                 /* constant  */
  YYSYMBOL_if_statement = 102,             /* if_statement  */
  YYSYMBOL_103_12 = 103,                   /* $@12  */
  YYSYMBOL_104_13 = 104,                   /* $@13  */
  YYSYMBOL_105_14 = 105,                   /* $@14  */
  YYSYMBOL_EL_statement = 106,             /* EL_statement  */
  YYSYMBOL_for_statement = 107,            /* for_statement  */
  YYSYMBOL_108_15 = 108,                   /* $@15  */
  YYSYMBOL_assignment_statement_2 = 109,   /* assignment_statement_2  */
  YYSYMBOL_for_initializer = 110,          /* for_initializer  */
  YYSYMBOL_111_16 = 111,                   /* $@16  */
  YYSYMBOL_for_condition = 112,            /* for_condition  */
  YYSYMBOL_for_update = 113,               /* for_update  */
  YYSYMBOL_while_statement = 114,          /* while_statement  */
  YYSYMBOL_115_17 = 115,                   /* $@17  */
  YYSYMBOL_loop_stat_list = 116,           /* loop_stat_list  */
  YYSYMBOL_switch_statement = 117,         /* switch_statement  */
  YYSYMBOL_118_18 = 118,                   /* $@18  */
  YYSYMBOL_switch_case_list = 119,         /* switch_case_list  */
  YYSYMBOL_switch_case = 120,              /* switch_case  */
  YYSYMBOL_print = 121,                    /* print  */
  YYSYMBOL_stringconst = 122,              /* stringconst  */
  YYSYMBOL_plist = 123,                    /* plist  */
  YYSYMBOL_return_statement = 124,         /* return_statement  */
  YYSYMBOL_compound_statement = 125,       /* compound_statement  */
  YYSYMBOL_126_19 = 126                    /* $@19  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   390

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  334

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   283,   283,   289,   290,   291,   292,   296,   299,   300,
     303,   306,   309,   303,   320,   329,   329,   338,   342,   342,
     352,   363,   363,   373,   374,   375,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   390,   398,   410,   410,
     418,   425,   425,   431,   438,   439,   440,   444,   453,   453,
     466,   467,   472,   473,   480,   490,   497,   504,   512,   519,
     537,   555,   570,   588,   598,   622,   646,   670,   694,   713,
     732,   751,   773,   779,   788,   794,   803,   809,   818,   824,
     833,   839,   848,   854,   863,   868,   876,   881,   888,   895,
     905,   910,   919,   919,   940,   962,   972,   994,  1004,  1026,
    1048,  1058,  1084,  1110,  1136,  1162,  1172,  1191,  1210,  1219,
    1237,  1258,  1276,  1285,  1309,  1318,  1348,  1354,  1369,  1369,
    1385,  1392,  1405,  1416,  1424,  1432,  1440,  1451,  1451,  1451,
    1451,  1460,  1464,  1469,  1469,  1487,  1524,  1561,  1580,  1604,
    1623,  1650,  1650,  1670,  1674,  1681,  1689,  1696,  1697,  1701,
    1701,  1709,  1710,  1711,  1716,  1722,  1727,  1733,  1738,  1738,
    1747,  1748,  1752,  1757,  1764,  1775,  1784,  1818,  1846,  1872,
    1898,  1920,  1946,  1952,  1964,  1977,  1977
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "INT", "FLOAT",
  "CHAR", "IF", "ELSE", "FOR", "WHILE", "SWITCH", "CASE", "DEFAULT",
  "PRINTF", "SCANF", "RETURN", "TRUE", "FALSE", "INCLUDE", "STR",
  "STRCONST", "FLOAT_NUM", "EXPONENT", "MAIN", "ID", "BREAK", "CONTINUE",
  "NUMBER", "CHARACTER", "ASSIGNMENT", "NOT", "AND", "OR", "EQ", "NE",
  "LT", "LE", "GT", "GE", "ADD", "SUB", "MUL", "DIV", "MOD", "LSQBRACKET",
  "RSQBRACKET", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON",
  "COMMA", "COLON", "$accept", "program", "datatype", "program_body",
  "functions", "function", "$@1", "$@2", "$@3", "arglist", "$@4", "args",
  "$@5", "main", "$@6", "statement_list", "statement", "calling_list",
  "$@7", "$@8", "declaration_statement", "type_specifier", "var_list",
  "$@9", "arr_dec", "multiple_num_list", "multiple_character_list",
  "multiple_float_num_list", "braced_num_list", "braced_character_list",
  "braced_float_num_list", "number_list", "character_list",
  "stringconst_list", "float_num_list", "assignment_statement", "$@10",
  "expression_statement", "logical_o_exp", "logical_a_exp",
  "relational_exp", "additive_exp", "multiplicative_exp", "negation_exp",
  "access_call_exp", "$@11", "primary_exp", "constant", "if_statement",
  "$@12", "$@13", "$@14", "EL_statement", "for_statement", "$@15",
  "assignment_statement_2", "for_initializer", "$@16", "for_condition",
  "for_update", "while_statement", "$@17", "loop_stat_list",
  "switch_statement", "$@18", "switch_case_list", "switch_case", "print",
  "stringconst", "plist", "return_statement", "compound_statement", "$@19", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
#endif

#define YYPACT_NINF (-273)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-176)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     212,  -273,  -273,  -273,  -273,    59,   221,  -273,  -273,  -273,
    -273,  -273,  -273,  -273,     7,    16,    17,  -273,  -273,   223,
    -273,    24,  -273,  -273,  -273,    57,    82,   183,    33,    61,
     108,   112,   129,   134,   136,    52,  -273,  -273,    26,  -273,
    -273,   109,    86,  -273,   120,   183,  -273,   160,    -6,   159,
     113,   187,   207,   197,  -273,   -13,  -273,  -273,  -273,  -273,
     156,  -273,  -273,  -273,  -273,  -273,   183,   148,  -273,  -273,
      86,    86,   193,  -273,  -273,    25,    86,    18,   -13,    54,
    -273,  -273,     3,   180,   208,   209,    86,  -273,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
     205,   201,  -273,   213,   223,  -273,    86,    10,    71,    73,
    -273,   210,  -273,   226,   218,   219,  -273,    38,   214,   237,
    -273,   160,   160,   159,   113,   187,   187,   207,   207,   207,
     207,   197,   197,  -273,  -273,  -273,   222,  -273,   150,  -273,
     244,   117,    26,  -273,   245,   220,    69,  -273,  -273,   173,
     224,   228,   122,   229,   123,   160,    86,  -273,  -273,  -273,
     225,   230,   227,   212,   232,  -273,  -273,  -273,  -273,    34,
     249,   233,   234,    84,   210,   235,    98,    86,   149,   124,
       1,   248,  -273,   226,   236,  -273,   238,  -273,   148,  -273,
     251,  -273,  -273,   241,   135,   239,   256,  -273,  -273,  -273,
     246,   247,   226,   250,   252,     4,   257,    96,  -273,   253,
     150,   150,  -273,  -273,    86,   242,   243,   254,   135,   258,
     181,   259,   260,   239,   255,   265,   267,   270,   272,    96,
    -273,   261,   262,   263,   264,   268,   269,   271,   273,  -273,
    -273,   279,    35,   135,   135,   135,  -273,  -273,   274,   135,
    -273,  -273,   210,    86,    86,    86,    86,   275,   276,   278,
     281,   282,   285,   277,  -273,  -273,  -273,   280,  -273,  -273,
    -273,   283,  -273,  -273,   135,  -273,  -273,   226,   226,   226,
     226,  -273,  -273,  -273,   286,  -273,  -273,  -273,     0,  -273,
    -273,  -273,  -273,  -273,  -273,     0,  -273,  -273,  -273,    96,
     284,   287,   288,   289,   290,   291,   292,   293,   294,   296,
     297,   298,  -273,  -273,  -273,  -273,  -273,  -273,  -273,   193,
    -273,   299,   300,   301,  -273,   305,   306,   307,   285,  -273,
     277,  -273,   282,  -273
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     3,     4,     5,     0,     0,     2,     7,     8,
       9,     1,    21,    10,     0,     0,     0,    11,   175,    17,
      22,     0,    44,    45,    46,     0,     0,    25,     0,    14,
       0,     0,     0,     0,     0,     0,   125,   126,   121,   123,
     124,     0,     0,    36,     0,    23,    26,     0,     0,    95,
      97,   100,   105,   108,   112,   114,   116,   122,    29,    30,
       0,    31,    32,    35,    33,    34,    25,     0,   127,   133,
       0,     0,     0,   121,   174,     0,     0,     0,   113,     0,
     176,    24,    47,     0,    52,    50,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,    27,     0,     0,    16,     0,     0,     0,     0,
     165,   172,   173,   135,     0,     0,   120,     0,     0,     0,
      43,     0,     0,    94,    96,    98,    99,   103,   104,   101,
     102,   106,   107,   109,   110,   111,     0,   117,     0,    12,
       0,     0,     0,   144,     0,     0,     0,   149,   158,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    51,   115,
      37,     0,    40,     0,    18,   128,   141,   143,   146,     0,
     148,     0,     0,   166,   170,     0,     0,     0,     0,    54,
       0,     0,    49,    93,     0,   119,     0,    13,     0,   175,
       0,   145,   147,     0,   157,     0,     0,   167,   171,   164,
       0,     0,   136,     0,     0,     0,     0,     0,    57,     0,
       0,     0,    19,   129,     0,     0,     0,     0,   151,     0,
       0,     0,     0,   160,     0,     0,     0,     0,     0,     0,
      61,     0,    90,    84,    86,     0,     0,     0,     0,    39,
      42,   132,     0,   157,   153,   155,   152,   150,     0,   157,
     159,   161,   168,     0,     0,     0,     0,     0,     0,     0,
      63,     0,     0,     0,    55,    56,    58,     0,   175,   130,
     142,     0,   154,   156,   157,   163,   169,   138,   137,   140,
     139,    59,    60,    62,     0,    91,    85,    87,     0,    68,
      69,    71,   131,   134,   162,     0,    64,    65,    67,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,    73,    75,    77,    72,    74,    70,    76,     0,
      66,    78,    80,    82,    88,     0,     0,     0,     0,    79,
       0,    81,     0,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -273,  -273,  -273,  -273,   146,  -273,  -273,  -273,  -273,  -273,
    -273,   132,  -273,  -273,  -273,    -4,   -15,    43,  -273,  -273,
    -273,   -14,  -103,  -273,  -273,    39,    40,    46,    -8,     5,
      -5,  -198,  -203,  -272,  -204,  -273,  -273,   -34,   295,   302,
     166,   144,   162,   145,   308,  -273,  -273,  -132,  -273,  -273,
    -273,  -273,  -273,  -273,  -273,  -100,  -273,  -273,  -273,  -273,
    -273,  -273,  -205,  -273,  -273,   127,  -273,  -273,   -70,  -163,
    -273,   -18,  -273
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    15,    19,   163,    25,
      67,   105,   188,    10,    14,    44,   218,   161,   184,   186,
      46,    47,    83,   118,    84,   289,   290,   291,   300,   301,
     302,   303,   304,   305,   306,    85,   119,    48,    49,    50,
      51,    52,    53,    54,    55,   138,    56,    57,    58,   106,
     189,   241,   269,    59,   107,    60,   146,   190,   170,   193,
      61,   171,   219,    62,   172,   222,   223,    63,   307,   150,
      64,    65,    21
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    75,   111,   237,   236,    26,   162,   145,    79,   235,
     197,   198,    45,   246,    22,    23,    24,   174,   157,   158,
     110,   110,   232,   308,   110,   259,   258,    86,   233,   234,
      45,   257,   100,   -92,   101,   142,   108,   109,   271,   272,
     273,    81,   113,   114,   275,    87,   115,   324,   117,   299,
     207,    45,   182,   229,    16,   -48,    76,   285,    86,    11,
     287,   143,   103,    17,   286,    18,   153,    86,    86,   294,
     192,    77,   141,    27,    36,    37,   112,    73,   162,   162,
      39,    40,    66,    41,   154,   191,   270,    86,   248,   276,
     140,    36,    37,   144,    73,   311,   310,    39,    40,    42,
      41,   309,   116,    74,    86,    28,    86,    29,    36,    37,
     208,    73,   169,   -15,    39,    40,    42,    41,   232,   147,
     168,   148,   183,   200,   233,   234,   201,   310,   311,   196,
     309,    36,    37,    42,    73,   230,   149,    39,    40,    22,
      23,    24,    30,   202,    31,    32,    33,    89,    90,    34,
      86,    35,   177,   180,   205,    68,    42,    36,    37,    69,
      38,   216,   217,    39,    40,   165,    41,   178,   181,   206,
      80,   213,    36,    37,   203,   160,    70,   204,    39,    40,
     242,    71,    42,    72,  -175,    82,    43,    22,    23,    24,
      30,    88,    31,    32,    33,    36,    37,    34,   173,    35,
     104,    39,    40,    36,    37,    36,    37,   102,    38,    39,
      40,    39,    40,   110,    41,     1,     2,     3,     4,   277,
     278,   279,   280,    91,    92,    93,    94,    22,    23,    24,
      42,   120,  -175,   136,    43,   127,   128,   129,   130,    97,
      98,    99,   133,   134,   135,    12,    13,    95,    96,   137,
     292,   220,   221,   239,   240,   125,   126,   131,   132,    86,
     121,   122,   149,   139,   151,   152,   155,   156,   159,   164,
     166,   167,   175,   176,   142,   179,   209,   -38,   185,   -41,
     -20,   214,   194,   195,   224,   231,   199,   268,   210,   215,
     211,   243,   225,   226,   244,   253,   227,   254,   228,   238,
     255,   252,   256,   267,   232,   245,   234,   260,   247,   187,
     250,   284,   249,   233,   261,   262,   263,   329,   264,   265,
     212,   266,   333,   296,   297,   281,   282,   274,   283,   288,
     298,   331,     0,   293,   312,   295,     0,   313,   314,   315,
     316,   317,   318,     0,   320,   319,   321,   322,   323,    78,
     251,   325,   326,   327,   328,   330,   332,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
     124
};

static const yytype_int16 yycheck[] =
{
      18,    35,    72,   207,   207,    19,   138,   107,    42,   207,
     173,   174,    27,   218,     4,     5,     6,   149,   121,   122,
      20,    20,    22,   295,    20,   229,   229,    33,    28,    29,
      45,   229,    45,    30,    47,    25,    70,    71,   243,   244,
     245,    45,    76,    25,   249,    51,    28,   319,    45,    49,
      49,    66,   155,    49,    47,    52,    30,   261,    33,     0,
     263,    51,    66,    47,   262,    48,    28,    33,    33,   274,
     170,    45,   106,    49,    22,    23,    51,    25,   210,   211,
      28,    29,    49,    31,    46,    51,    51,    33,   220,   252,
     104,    22,    23,   107,    25,   299,   299,    28,    29,    47,
      31,   299,    48,    51,    33,    48,    33,    25,    22,    23,
     180,    25,   146,    52,    28,    29,    47,    31,    22,    48,
      51,    48,   156,    25,    28,    29,    28,   330,   332,    45,
     328,    22,    23,    47,    25,   205,    52,    28,    29,     4,
       5,     6,     7,   177,     9,    10,    11,    34,    35,    14,
      33,    16,    30,    30,    30,    47,    47,    22,    23,    47,
      25,    26,    27,    28,    29,    48,    31,    45,    45,    45,
      50,   189,    22,    23,    25,    25,    47,    28,    28,    29,
     214,    47,    47,    47,    49,    25,    51,     4,     5,     6,
       7,    32,     9,    10,    11,    22,    23,    14,    25,    16,
      52,    28,    29,    22,    23,    22,    23,    51,    25,    28,
      29,    28,    29,    20,    31,     3,     4,     5,     6,   253,
     254,   255,   256,    36,    37,    38,    39,     4,     5,     6,
      47,    51,    49,    28,    51,    91,    92,    93,    94,    42,
      43,    44,    97,    98,    99,    24,    25,    40,    41,    48,
     268,    12,    13,   210,   211,    89,    90,    95,    96,    33,
      52,    52,    52,    50,    46,    46,    52,    30,    46,    25,
      25,    51,    48,    45,    25,    46,    28,    52,    48,    52,
      48,    30,    49,    49,    28,    28,    51,     8,    52,    48,
      52,    49,    46,    46,    51,    30,    46,    30,    46,    46,
      30,    46,    30,    30,    22,    51,    29,    46,    50,   163,
      50,    30,    53,    28,    52,    52,    52,   325,    50,    50,
     188,    50,   327,   284,   284,    50,    50,    53,    50,    49,
     284,   326,    -1,    50,    50,    49,    -1,    50,    50,    50,
      50,    50,    50,    -1,    50,    52,    50,    50,    50,    41,
     223,    52,    52,    52,    49,    49,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    55,    56,    57,    58,    59,
      67,     0,    24,    25,    68,    60,    47,    47,    48,    61,
     125,   126,     4,     5,     6,    63,    75,    49,    48,    25,
       7,     9,    10,    11,    14,    16,    22,    23,    25,    28,
      29,    31,    47,    51,    69,    70,    74,    75,    91,    92,
      93,    94,    95,    96,    97,    98,   100,   101,   102,   107,
     109,   114,   117,   121,   124,   125,    49,    64,    47,    47,
      47,    47,    47,    25,    51,    91,    30,    45,    98,    91,
      50,    69,    25,    76,    78,    89,    33,    51,    32,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    47,    51,    69,    52,    65,   103,   108,    91,    91,
      20,   122,    51,    91,    25,    28,    48,    45,    77,    90,
      51,    52,    52,    92,    93,    94,    94,    95,    95,    95,
      95,    96,    96,    97,    97,    97,    28,    48,    99,    50,
      75,    91,    25,    51,    75,   109,   110,    48,    48,    52,
     123,    46,    46,    28,    46,    52,    30,    76,    76,    46,
      25,    71,   101,    62,    25,    48,    25,    51,    51,    91,
     112,   115,   118,    25,   101,    48,    45,    30,    45,    46,
      30,    45,    76,    91,    72,    48,    73,    58,    66,   104,
     111,    51,   109,   113,    49,    49,    45,   123,   123,    51,
      25,    28,    91,    25,    28,    30,    45,    49,   122,    28,
      52,    52,    65,   125,    30,    48,    26,    27,    70,   116,
      12,    13,   119,   120,    28,    46,    46,    46,    46,    49,
     122,    28,    22,    28,    29,    85,    86,    88,    46,    71,
      71,   105,    91,    49,    51,    51,   116,    50,   101,    53,
      50,   119,    46,    30,    30,    30,    30,    85,    86,    88,
      46,    52,    52,    52,    50,    50,    50,    30,     8,   106,
      51,   116,   116,   116,    53,   116,   123,    91,    91,    91,
      91,    50,    50,    50,    30,    88,    85,    86,    49,    79,
      80,    81,   125,    50,   116,    49,    79,    80,    81,    49,
      82,    83,    84,    85,    86,    87,    88,   122,    87,    85,
      86,    88,    50,    50,    50,    50,    50,    50,    50,    52,
      50,    50,    50,    50,    87,    52,    52,    52,    49,    82,
      49,    83,    49,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    56,    57,    58,    58,
      60,    61,    62,    59,    63,    64,    63,    63,    66,    65,
      65,    68,    67,    69,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    72,    71,
      71,    73,    71,    74,    75,    75,    75,    76,    77,    76,
      76,    76,    76,    76,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    90,    89,    91,    91,    92,    92,    93,    93,
      93,    94,    94,    94,    94,    94,    95,    95,    95,    96,
      96,    96,    96,    97,    97,    98,    98,    98,    99,    98,
     100,   100,   100,   101,   101,   101,   101,   103,   104,   105,
     102,   106,   106,   108,   107,   109,   109,   109,   109,   109,
     109,   111,   110,   110,   110,   112,   112,   113,   113,   115,
     114,   116,   116,   116,   116,   116,   116,   116,   118,   117,
     119,   119,   120,   120,   121,   122,   123,   123,   123,   123,
     123,   123,   123,   124,   124,   126,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     0,    12,     2,     0,     4,     0,     0,     5,
       3,     0,     6,     1,     2,     0,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     0,     4,     3,     1,     1,     1,     1,     0,     4,
       1,     3,     1,     3,     4,     7,     7,     5,     7,     8,
       8,     6,     8,     7,     9,     9,    11,     9,     8,     8,
      10,     8,     3,     3,     3,     3,     3,     3,     3,     5,
       3,     5,     3,     5,     1,     3,     1,     3,     3,     1,
       1,     3,     0,     4,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     1,     4,     1,     3,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     0,     0,     0,
       9,     2,     0,     0,    10,     3,     6,     9,     9,     9,
       9,     0,     6,     2,     1,     2,     1,     1,     0,     0,
       8,     1,     2,     2,     3,     2,     3,     0,     0,     8,
       1,     2,     4,     3,     6,     1,     2,     3,     5,     6,
       2,     3,     0,     3,     2,     0,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: program_body  */
#line 283 "parser.y"
                        { 
                            (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "program"); 
                            head = (yyval.nd_obj).nd;
                        }
#line 1852 "y.tab.c"
    break;

  case 3: /* datatype: INT  */
#line 289 "parser.y"
                {   insert_type();  }
#line 1858 "y.tab.c"
    break;

  case 4: /* datatype: FLOAT  */
#line 290 "parser.y"
                {   insert_type();  }
#line 1864 "y.tab.c"
    break;

  case 5: /* datatype: CHAR  */
#line 291 "parser.y"
                {   insert_type();  }
#line 1870 "y.tab.c"
    break;

  case 6: /* datatype: VOID  */
#line 292 "parser.y"
                {   insert_type();  }
#line 1876 "y.tab.c"
    break;

  case 7: /* program_body: functions  */
#line 296 "parser.y"
                    {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "program_body"); }
#line 1882 "y.tab.c"
    break;

  case 8: /* functions: function  */
#line 299 "parser.y"
                    {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "function");    }
#line 1888 "y.tab.c"
    break;

  case 9: /* functions: main  */
#line 300 "parser.y"
                    {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "function");    }
#line 1894 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 303 "parser.y"
                    {   strcpy(yytext, (yyvsp[0].nd_obj2).name); 
                        add('F'); 
                        strcpy(currentFunction, (yyvsp[0].nd_obj2).name);
         }
#line 1903 "y.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 306 "parser.y"
                  { 
            nextTable();
        }
#line 1911 "y.tab.c"
    break;

  case 12: /* $@3: %empty  */
#line 309 "parser.y"
        {
            prevTable();
        }
#line 1919 "y.tab.c"
    break;

  case 13: /* function: datatype ID $@1 LPAREN $@2 arglist RPAREN LBRACE statement_list RBRACE $@3 functions  */
#line 312 "parser.y"
                                                            { 
                                                                (yyvsp[-11].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-11].nd_obj).name);
                                                                (yyvsp[-10].nd_obj2).nd = mknode((yyvsp[-6].nd_obj).nd, (yyvsp[-3].nd_obj).nd, (yyvsp[-10].nd_obj2).name);
                                                                struct node *temp = mknode((yyvsp[-11].nd_obj).nd, (yyvsp[-10].nd_obj2).nd, "function_body");
                                                                (yyval.nd_obj).nd = mknode(temp, (yyvsp[0].nd_obj).nd, "function");
                                                            }
#line 1930 "y.tab.c"
    break;

  case 14: /* arglist: type_specifier ID  */
#line 320 "parser.y"
                                {
                                    (yyvsp[0].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj2).name);
                                    yytext = malloc(sizeof(char) * strlen((yyvsp[0].nd_obj2).name));
                                    strcpy(yytext, (yyvsp[0].nd_obj2).name);
                                    add('V');
                                    printf("Adding argument %s to function %s of type %s\n", (yyvsp[0].nd_obj2).name,currentFunction,type);
                                    addArgument((yyvsp[0].nd_obj2).name,type); 
                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd,(yyvsp[0].nd_obj2).nd, "Argument");
                                }
#line 1944 "y.tab.c"
    break;

  case 15: /* $@4: %empty  */
#line 329 "parser.y"
                                {   (yyvsp[0].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj2).name);
                                    yytext = malloc(sizeof(char) * strlen((yyvsp[0].nd_obj2).name));
                                    strcpy(yytext, (yyvsp[0].nd_obj2).name);
                                    add('V');
                                    addArgument((yyvsp[0].nd_obj2).name,type);
                                }
#line 1955 "y.tab.c"
    break;

  case 16: /* arglist: type_specifier ID $@4 args  */
#line 334 "parser.y"
                                            {
                                                struct node *temp = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-2].nd_obj2).nd, "Argument");
                                                (yyval.nd_obj).nd = mknode(temp, (yyvsp[0].nd_obj).nd, "arglist");
                                            }
#line 1964 "y.tab.c"
    break;

  case 17: /* arglist: %empty  */
#line 338 "parser.y"
                                {   (yyval.nd_obj).nd = mknode(NULL, NULL, "arglist");  }
#line 1970 "y.tab.c"
    break;

  case 18: /* $@5: %empty  */
#line 342 "parser.y"
                                    {
                                        (yyvsp[0].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj2).name);
                                        yytext = malloc(sizeof(char) * strlen((yyvsp[0].nd_obj2).name));
                                        strcpy(yytext, (yyvsp[0].nd_obj2).name);
                                        add('V');
                                        addArgument((yyvsp[0].nd_obj2).name,type);
                                    }
#line 1982 "y.tab.c"
    break;

  case 19: /* args: COMMA type_specifier ID $@5 args  */
#line 348 "parser.y"
                                                {
                                                    struct node *temp = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-2].nd_obj2).nd, "Argument");
                                                    (yyval.nd_obj).nd = mknode(temp, (yyvsp[0].nd_obj).nd, "args");
                                                }
#line 1991 "y.tab.c"
    break;

  case 20: /* args: COMMA type_specifier ID  */
#line 352 "parser.y"
                                    {
                                        (yyvsp[0].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj2).name);
                                        yytext = malloc(sizeof(char) * strlen((yyvsp[0].nd_obj2).name));
                                        strcpy(yytext, (yyvsp[0].nd_obj2).name);
                                        add('V');
                                        addArgument((yyvsp[0].nd_obj2).name,type);
                                        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "Argument");
                                    }
#line 2004 "y.tab.c"
    break;

  case 21: /* $@6: %empty  */
#line 363 "parser.y"
                      {   add('F');  
                          strcpy(currentFunction, "main");
         }
#line 2012 "y.tab.c"
    break;

  case 22: /* main: datatype MAIN $@6 LPAREN RPAREN compound_statement  */
#line 365 "parser.y"
                                             {
                                                                                        (yyvsp[-5].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-5].nd_obj).name);
                                                                                        struct node *temp = mknode((yyvsp[0].nd_obj).nd, NULL, (yyvsp[-4].nd_obj).name);
                                                                                        (yyval.nd_obj).nd = mknode((yyvsp[-5].nd_obj).nd, temp, "Main_Structure");
                                                                                    }
#line 2022 "y.tab.c"
    break;

  case 23: /* statement_list: statement  */
#line 373 "parser.y"
                                        {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement_list");}
#line 2028 "y.tab.c"
    break;

  case 24: /* statement_list: statement statement_list  */
#line 374 "parser.y"
                                        {   (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "statement_list");}
#line 2034 "y.tab.c"
    break;

  case 25: /* statement_list: %empty  */
#line 375 "parser.y"
                                        {   (yyval.nd_obj).nd = mknode(NULL, NULL, "statement_list");}
#line 2040 "y.tab.c"
    break;

  case 26: /* statement: declaration_statement  */
#line 379 "parser.y"
                                                {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");   }
#line 2046 "y.tab.c"
    break;

  case 27: /* statement: assignment_statement_2 SEMICOLON  */
#line 380 "parser.y"
                                                {   (yyvsp[0].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ; (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "statement");  }
#line 2052 "y.tab.c"
    break;

  case 28: /* statement: expression_statement SEMICOLON  */
#line 381 "parser.y"
                                                {   (yyvsp[0].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ; (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj3).nd, (yyvsp[0].nd_obj).nd, "statement");  }
#line 2058 "y.tab.c"
    break;

  case 29: /* statement: if_statement  */
#line 382 "parser.y"
                                                {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 2064 "y.tab.c"
    break;

  case 30: /* statement: for_statement  */
#line 383 "parser.y"
                                                {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 2070 "y.tab.c"
    break;

  case 31: /* statement: while_statement  */
#line 384 "parser.y"
                                                {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 2076 "y.tab.c"
    break;

  case 32: /* statement: switch_statement  */
#line 385 "parser.y"
                                                {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 2082 "y.tab.c"
    break;

  case 33: /* statement: return_statement  */
#line 386 "parser.y"
                                                {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 2088 "y.tab.c"
    break;

  case 34: /* statement: compound_statement  */
#line 387 "parser.y"
                                                {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 2094 "y.tab.c"
    break;

  case 35: /* statement: print  */
#line 388 "parser.y"
                                                {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");}
#line 2100 "y.tab.c"
    break;

  case 36: /* statement: SEMICOLON  */
#line 390 "parser.y"
                                                {   
                                                    (yyvsp[0].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ;
                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");
                                                }
#line 2109 "y.tab.c"
    break;

  case 37: /* calling_list: ID  */
#line 398 "parser.y"
            {   
                if(check_declaration((yyvsp[0].nd_obj2).name) == 0)
                {
                    printf("Error: Argument %s not declared at line %d\n", (yyvsp[0].nd_obj2).name, yylineno);
                    exit(1);
                }
                check_Argument((yyvsp[0].nd_obj2).name);
                printf("Name is %s\n", (yyvsp[0].nd_obj2).name);
                checkFinalArguments(currentFunction);
                (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "calling_list"); 
                currentArgumentIndex=0;
            }
#line 2126 "y.tab.c"
    break;

  case 38: /* $@7: %empty  */
#line 410 "parser.y"
               {
                if(check_declaration((yyvsp[0].nd_obj2).name) == 0)
                {
                    printf("Error: Argument %s not declared at line %d\n", (yyvsp[0].nd_obj2).name, yylineno);
                    exit(1);
                }
                check_Argument((yyvsp[0].nd_obj2).name);
        }
#line 2139 "y.tab.c"
    break;

  case 39: /* calling_list: ID $@7 COMMA calling_list  */
#line 417 "parser.y"
                              {   (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj2).nd, (yyvsp[0].nd_obj).nd, "calling_list"); }
#line 2145 "y.tab.c"
    break;

  case 40: /* calling_list: constant  */
#line 418 "parser.y"
                   {
                printf("Checking this\n");
                check_Argument((yyvsp[0].nd_obj3).type);
                checkFinalArguments(currentFunction);
                (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "calling_list"); 
                currentArgumentIndex=0;
        }
#line 2157 "y.tab.c"
    break;

  case 41: /* $@8: %empty  */
#line 425 "parser.y"
                    {
                check_Argument((yyvsp[0].nd_obj3).type);
        }
#line 2165 "y.tab.c"
    break;

  case 42: /* calling_list: constant $@8 COMMA calling_list  */
#line 427 "parser.y"
                             {   (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj3).nd, (yyvsp[0].nd_obj).nd, "calling_list"); }
#line 2171 "y.tab.c"
    break;

  case 43: /* declaration_statement: type_specifier var_list SEMICOLON  */
#line 431 "parser.y"
                                            {
                                                (yyvsp[0].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ; 
                                                struct node *temp = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "declaration_statement");
                                                (yyval.nd_obj).nd = mknode(temp, (yyvsp[0].nd_obj).nd, "declaration_statement_structure");
                                            }
#line 2181 "y.tab.c"
    break;

  case 44: /* type_specifier: INT  */
#line 438 "parser.y"
                    {   insert_type(); (yyval.nd_obj).nd = mknode(NULL, NULL, "int");   }
#line 2187 "y.tab.c"
    break;

  case 45: /* type_specifier: FLOAT  */
#line 439 "parser.y"
                    {   insert_type(); (yyval.nd_obj).nd = mknode(NULL, NULL, "float"); }
#line 2193 "y.tab.c"
    break;

  case 46: /* type_specifier: CHAR  */
#line 440 "parser.y"
                    {   insert_type(); (yyval.nd_obj).nd = mknode(NULL, NULL, "char");  }
#line 2199 "y.tab.c"
    break;

  case 47: /* var_list: ID  */
#line 444 "parser.y"
                                                { 
                                                    yytext = malloc(sizeof(char)*strlen((yyvsp[0].nd_obj2).name));
                                                    strcpy(yytext, (yyvsp[0].nd_obj2).name);
                                                    add('V');
                                                    (yyvsp[0].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj2).name);
                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "var_list1");

                                                    sprintf(icg[ic_idx++], "%s = NULL\n", (yyvsp[0].nd_obj2).name);
                                                }
#line 2213 "y.tab.c"
    break;

  case 48: /* $@9: %empty  */
#line 453 "parser.y"
                                                {
                                                    yytext = malloc(sizeof(char)*strlen((yyvsp[0].nd_obj2).name));
                                                    strcpy(yytext, (yyvsp[0].nd_obj2).name);
                                                    add('V');
                                                    sprintf((yyvsp[0].nd_obj2).type,type);

                                                    sprintf(icg[ic_idx++], "%s = NULL\n", (yyvsp[0].nd_obj2).name);
                                                }
#line 2226 "y.tab.c"
    break;

  case 49: /* var_list: ID $@9 COMMA var_list  */
#line 460 "parser.y"
                                                                    { 
                                                                        (yyvsp[-3].nd_obj2).nd = mknode(NULL,NULL,(yyvsp[-3].nd_obj2).name) ;
                                                                        (yyvsp[-1].nd_obj).nd = mknode(NULL,NULL,"Comma") ; 
                                                                        struct node *temp = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "var_list");
                                                                        (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj2).nd, temp, "var_list_structure"); 
                                                                    }
#line 2237 "y.tab.c"
    break;

  case 50: /* var_list: assignment_statement  */
#line 466 "parser.y"
                                                {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "var_list");    }
#line 2243 "y.tab.c"
    break;

  case 51: /* var_list: assignment_statement COMMA var_list  */
#line 467 "parser.y"
                                                {
                                                    (yyvsp[-1].nd_obj).nd = mknode(NULL,NULL,"Comma") ; 
                                                    struct node *temp = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "var_list");
                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "var_list_structure");
                                                }
#line 2253 "y.tab.c"
    break;

  case 52: /* var_list: arr_dec  */
#line 472 "parser.y"
                                                {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "var_list");    }
#line 2259 "y.tab.c"
    break;

  case 53: /* var_list: arr_dec COMMA var_list  */
#line 473 "parser.y"
                                                {   (yyvsp[-1].nd_obj).nd = mknode(NULL,NULL,"Comma") ;
                                                    struct node *temp = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "var_list");
                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "var_list_structure");
                                                }
#line 2268 "y.tab.c"
    break;

  case 54: /* arr_dec: ID LSQBRACKET NUMBER RSQBRACKET  */
#line 480 "parser.y"
                                            {
                                                yytext = malloc(sizeof(char)*strlen((yyvsp[-3].nd_obj2).name));
                                                strcpy(yytext, (yyvsp[-3].nd_obj2).name);
                                                add('A'); 
                                                (yyvsp[-3].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj2).name);
                                                (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name);
                                                struct node *temp = mknode((yyvsp[-1].nd_obj).nd, NULL, "size");
                                                (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj2).nd, temp, "arr_dec");
                                            }
#line 2282 "y.tab.c"
    break;

  case 55: /* arr_dec: ID LSQBRACKET RSQBRACKET ASSIGNMENT LBRACE number_list RBRACE  */
#line 490 "parser.y"
                                                                            {   
                                                                                yytext = malloc(sizeof(char)*strlen((yyvsp[-6].nd_obj2).name));
                                                                                add('A');
                                                                                (yyvsp[-6].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-6].nd_obj2).name);
                                                                                struct node *temp = mknode((yyvsp[-1].nd_obj_arr).nd, NULL, "init_list");
                                                                                (yyval.nd_obj).nd = mknode((yyvsp[-6].nd_obj2).nd, temp, "arr_dec");
                                                                            }
#line 2294 "y.tab.c"
    break;

  case 56: /* arr_dec: ID LSQBRACKET RSQBRACKET ASSIGNMENT LBRACE character_list RBRACE  */
#line 497 "parser.y"
                                                                                {   
                                                                                    yytext = malloc(sizeof(char)*strlen((yyvsp[-6].nd_obj2).name));
                                                                                    add('A'); 
                                                                                    (yyvsp[-6].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-6].nd_obj2).name);
                                                                                    struct node *temp = mknode((yyvsp[-1].nd_obj_arr).nd, NULL, "init_list");
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-6].nd_obj2).nd, temp, "arr_dec");
                                                                                }
#line 2306 "y.tab.c"
    break;

  case 57: /* arr_dec: ID LSQBRACKET RSQBRACKET ASSIGNMENT stringconst  */
#line 504 "parser.y"
                                                            {   //change
                                                                yytext = malloc(sizeof(char) * strlen((yyvsp[-4].nd_obj2).name));
                                                                add('A');
                                                                (yyvsp[-4].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-4].nd_obj2).name);
                                                                struct node *temp = mknode((yyvsp[0].nd_obj_arr).nd, NULL, "string_init");
                                                                (yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj2).nd, temp, "arr_dec");
                                                            }
#line 2318 "y.tab.c"
    break;

  case 58: /* arr_dec: ID LSQBRACKET RSQBRACKET ASSIGNMENT LBRACE float_num_list RBRACE  */
#line 512 "parser.y"
                                                                                {   
                                                                                    yytext = malloc(sizeof(char)*strlen((yyvsp[-6].nd_obj2).name));
                                                                                    add('A'); 
                                                                                    (yyvsp[-6].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-6].nd_obj2).name);
                                                                                    struct node *temp = mknode((yyvsp[-1].nd_obj_arr).nd, NULL, "init_list");
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-6].nd_obj2).nd, temp, "arr_dec");
                                                                                }
#line 2330 "y.tab.c"
    break;

  case 59: /* arr_dec: ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE number_list RBRACE  */
#line 519 "parser.y"
                                                                                    {   
                                                                                        //change
                                                                                        printf("%d\n", (yyvsp[-1].nd_obj_arr).sz);
                                                                                        if(atoi((yyvsp[-5].nd_obj).name) < (yyvsp[-1].nd_obj_arr).sz) {
                                                                                            printf("Error: Array size is less than the number of elements in the initialization list\n");
                                                                                            exit(1);
                                                                                        }
                                                                                        else{
                                                                                            yytext = malloc(sizeof(char)*strlen((yyvsp[-7].nd_obj2).name));
                                                                                            strcpy(yytext, (yyvsp[-7].nd_obj2).name);
                                                                                            add('A');
                                                                                            (yyvsp[-7].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-7].nd_obj2).name);
                                                                                            (yyvsp[-5].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-5].nd_obj).name);
                                                                                            struct node *temp2 = mknode((yyvsp[-5].nd_obj).nd, NULL, "size");
                                                                                            struct node *temp = mknode((yyvsp[-7].nd_obj2).nd, temp2, "ID_size");
                                                                                            (yyval.nd_obj).nd = mknode(temp, (yyvsp[-1].nd_obj_arr).nd, "arr_dec");
                                                                                        }
                                                                                    }
#line 2353 "y.tab.c"
    break;

  case 60: /* arr_dec: ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE character_list RBRACE  */
#line 537 "parser.y"
                                                                                    {   
                                                                                        //change
                                                                                        printf("%d\n", (yyvsp[-1].nd_obj_arr).sz);
                                                                                        if(atoi((yyvsp[-5].nd_obj).name) < (yyvsp[-1].nd_obj_arr).sz) {
                                                                                            printf("Error: Array size is less than the number of elements in the initialization list\n");
                                                                                            exit(1);
                                                                                        }
                                                                                        else {
                                                                                            yytext = malloc(sizeof(char)*strlen((yyvsp[-7].nd_obj2).name));
                                                                                            strcpy(yytext, (yyvsp[-7].nd_obj2).name);
                                                                                            add('A');
                                                                                            (yyvsp[-7].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-7].nd_obj2).name);
                                                                                            (yyvsp[-5].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-5].nd_obj).name);
                                                                                            struct node *temp2 = mknode((yyvsp[-5].nd_obj).nd, NULL, "size");
                                                                                            struct node *temp = mknode((yyvsp[-7].nd_obj2).nd, temp2, "ID_size");
                                                                                            (yyval.nd_obj).nd = mknode(temp, (yyvsp[-1].nd_obj_arr).nd, "arr_dec");
                                                                                        }
                                                                                    }
#line 2376 "y.tab.c"
    break;

  case 61: /* arr_dec: ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT stringconst  */
#line 555 "parser.y"
                                                                    {   //change
                                                                        if(atoi((yyvsp[-3].nd_obj).name) < (yyvsp[0].nd_obj_arr).sz) {
                                                                            printf("Error: Array size is less than the number of elements in the initialization list\n");
                                                                            exit(1);
                                                                        }
                                                                        else {
                                                                            yytext = malloc(sizeof(char) * strlen((yyvsp[-5].nd_obj2).name));
                                                                            strcpy(yytext, (yyvsp[-5].nd_obj2).name);
                                                                            add('A');
                                                                            (yyvsp[-5].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-5].nd_obj2).name);
                                                                            (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name);
                                                                            struct node *temp = mknode((yyvsp[-5].nd_obj2).nd, (yyvsp[-3].nd_obj).nd, "ID_size");
                                                                            (yyval.nd_obj).nd = mknode(temp, (yyvsp[0].nd_obj_arr).nd, "arr_dec");
                                                                        }
                                                                    }
#line 2396 "y.tab.c"
    break;

  case 62: /* arr_dec: ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE float_num_list RBRACE  */
#line 570 "parser.y"
                                                                                    {
                                                                                        //change
                                                                                        printf("%d\n", (yyvsp[-1].nd_obj_arr).sz);
                                                                                        if(atoi((yyvsp[-5].nd_obj).name) < (yyvsp[-1].nd_obj_arr).sz) {
                                                                                            printf("Error: Array size is less than the number of elements in the initialization list\n");
                                                                                            exit(1);
                                                                                        }
                                                                                        else {
                                                                                            yytext = malloc(sizeof(char)*strlen((yyvsp[-7].nd_obj2).name));
                                                                                            strcpy(yytext, (yyvsp[-7].nd_obj2).name);
                                                                                            add('A');
                                                                                            (yyvsp[-7].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-7].nd_obj2).name);
                                                                                            (yyvsp[-5].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-5].nd_obj).name);
                                                                                            struct node *temp2 = mknode((yyvsp[-5].nd_obj).nd, NULL, "size");
                                                                                            struct node *temp = mknode((yyvsp[-7].nd_obj2).nd, temp2, "ID_size");
                                                                                            (yyval.nd_obj).nd = mknode(temp, (yyvsp[-1].nd_obj_arr).nd, "arr_dec");
                                                                                        }
                                                                                    }
#line 2419 "y.tab.c"
    break;

  case 63: /* arr_dec: ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET  */
#line 588 "parser.y"
                                                                            {
                                                                                yytext = malloc(sizeof(char) * strlen((yyvsp[-6].nd_obj2).name));
                                                                                strcpy(yytext, (yyvsp[-6].nd_obj2).name);
                                                                                add('A');
                                                                                (yyvsp[-6].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-6].nd_obj2).name);
                                                                                (yyvsp[-4].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-4].nd_obj).name);
                                                                                (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name);
                                                                                struct node *temp = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "size");
                                                                                (yyval.nd_obj).nd = mknode((yyvsp[-6].nd_obj2).nd, temp, "arr_dec");
                                                                            }
#line 2434 "y.tab.c"
    break;

  case 64: /* arr_dec: ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_num_list  */
#line 599 "parser.y"
                                                                {
                                                                    //change
                                                                    if(atoi((yyvsp[-3].nd_obj).name) < (yyvsp[0].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else if(atoi((yyvsp[-6].nd_obj).name) < (yyvsp[0].nd_obj_arr2).sz){
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more number of {} in init list than specified by 1st dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        // printf("sz = %d, each_sz = %d, mul = %d \n", $9.sz, $9.each_list_sz, $9.sz * $9.each_list_sz);
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[-8].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[-8].nd_obj2).name);
                                                                        add('A');
                                                                        (yyvsp[-8].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-8].nd_obj2).name);
                                                                        (yyvsp[-6].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-6].nd_obj).name);
                                                                        (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name);
                                                                        struct node *temp = mknode((yyvsp[-6].nd_obj).nd, (yyvsp[-3].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[-8].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[0].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
#line 2462 "y.tab.c"
    break;

  case 65: /* arr_dec: ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_character_list  */
#line 623 "parser.y"
                                                                {
                                                                    //change
                                                                    if(atoi((yyvsp[-3].nd_obj).name) < (yyvsp[0].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else if(atoi((yyvsp[-6].nd_obj).name) < (yyvsp[0].nd_obj_arr2).sz){
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more number of {} in init list than specified by 1st dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        // printf("sz = %d, each_sz = %d, mul = %d \n", $9.sz, $9.each_list_sz, $9.sz * $9.each_list_sz);
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[-8].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[-8].nd_obj2).name);
                                                                        add('A');
                                                                        (yyvsp[-8].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-8].nd_obj2).name);
                                                                        (yyvsp[-6].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-6].nd_obj).name);
                                                                        (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name);
                                                                        struct node *temp = mknode((yyvsp[-6].nd_obj).nd, (yyvsp[-3].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[-8].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[0].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
#line 2490 "y.tab.c"
    break;

  case 66: /* arr_dec: ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE stringconst_list RBRACE  */
#line 647 "parser.y"
                                                                {
                                                                    //change2
                                                                    if(atoi((yyvsp[-5].nd_obj).name) < (yyvsp[-1].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more chars in one or more strings in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else if(atoi((yyvsp[-8].nd_obj).name) < (yyvsp[-1].nd_obj_arr2).sz){
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more number of strings in init list than specified by 1st dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        // printf("sz = %d, each_sz = %d, mul = %d \n", $9.sz, $9.each_list_sz, $9.sz * $9.each_list_sz);
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[-10].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[-10].nd_obj2).name);
                                                                        add('V');
                                                                        (yyvsp[-10].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-10].nd_obj2).name);
                                                                        (yyvsp[-8].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-8].nd_obj).name);
                                                                        (yyvsp[-5].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-5].nd_obj).name);
                                                                        struct node *temp = mknode((yyvsp[-8].nd_obj).nd, (yyvsp[-5].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[-10].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[-1].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
#line 2518 "y.tab.c"
    break;

  case 67: /* arr_dec: ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_float_num_list  */
#line 671 "parser.y"
                                                                {
                                                                    //change
                                                                    if(atoi((yyvsp[-3].nd_obj).name) < (yyvsp[0].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else if(atoi((yyvsp[-6].nd_obj).name) < (yyvsp[0].nd_obj_arr2).sz){
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more number of {} in init list than specified by 1st dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        // printf("sz = %d, each_sz = %d, mul = %d \n", $9.sz, $9.each_list_sz, $9.sz * $9.each_list_sz);
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[-8].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[-8].nd_obj2).name);
                                                                        add('A');
                                                                        (yyvsp[-8].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-8].nd_obj2).name);
                                                                        (yyvsp[-6].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-6].nd_obj).name);
                                                                        (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name);
                                                                        struct node *temp = mknode((yyvsp[-6].nd_obj).nd, (yyvsp[-3].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[-8].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[0].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
#line 2546 "y.tab.c"
    break;

  case 68: /* arr_dec: ID LSQBRACKET RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_num_list  */
#line 695 "parser.y"
                                                                {
                                                                    //change
                                                                    if(atoi((yyvsp[-3].nd_obj).name) < (yyvsp[0].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[-7].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[-7].nd_obj2).name);
                                                                        add('A');
                                                                        (yyvsp[-7].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-7].nd_obj2).name);
                                                                        struct node *firstsize = mknode(NULL, NULL, " ");
                                                                        (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name);
                                                                        struct node *temp = mknode(firstsize, (yyvsp[-3].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[-7].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[0].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
#line 2569 "y.tab.c"
    break;

  case 69: /* arr_dec: ID LSQBRACKET RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_character_list  */
#line 714 "parser.y"
                                                                {
                                                                    //change
                                                                    if(atoi((yyvsp[-3].nd_obj).name) < (yyvsp[0].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[-7].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[-7].nd_obj2).name);
                                                                        add('A');
                                                                        (yyvsp[-7].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-7].nd_obj2).name);
                                                                        struct node *firstsize = mknode(NULL, NULL, " ");
                                                                        (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name);
                                                                        struct node *temp = mknode(firstsize, (yyvsp[-3].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[-7].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[0].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
#line 2592 "y.tab.c"
    break;

  case 70: /* arr_dec: ID LSQBRACKET RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT LBRACE stringconst_list RBRACE  */
#line 733 "parser.y"
                                                                {
                                                                    //change2
                                                                    if(atoi((yyvsp[-5].nd_obj).name) < (yyvsp[-1].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more chars in one or more strings in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[-9].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[-9].nd_obj2).name);
                                                                        add('V');
                                                                        (yyvsp[-9].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-9].nd_obj2).name);
                                                                        struct node *firstsize = mknode(NULL, NULL, " ");
                                                                        (yyvsp[-5].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-5].nd_obj).name);
                                                                        struct node *temp = mknode(firstsize, (yyvsp[-5].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[-9].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[-1].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
#line 2615 "y.tab.c"
    break;

  case 71: /* arr_dec: ID LSQBRACKET RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT multiple_float_num_list  */
#line 752 "parser.y"
                                                                {
                                                                    //change
                                                                    if(atoi((yyvsp[-3].nd_obj).name) < (yyvsp[0].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[-7].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[-7].nd_obj2).name);
                                                                        add('A');
                                                                        (yyvsp[-7].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-7].nd_obj2).name);
                                                                        struct node *firstsize = mknode(NULL, NULL, " ");
                                                                        (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name);
                                                                        struct node *temp = mknode(firstsize, (yyvsp[-3].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[-7].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[0].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
#line 2638 "y.tab.c"
    break;

  case 72: /* multiple_num_list: LBRACE number_list RBRACE  */
#line 773 "parser.y"
                                    {
                                        //change
                                        (yyval.nd_obj_arr2).sz = 1;
                                        (yyval.nd_obj_arr2).each_list_sz = (yyvsp[-1].nd_obj_arr).sz;
                                        (yyval.nd_obj_arr2).nd = mknode((yyvsp[-1].nd_obj_arr).nd, NULL, "multiple_num_list");
                                    }
#line 2649 "y.tab.c"
    break;

  case 73: /* multiple_num_list: LBRACE braced_num_list RBRACE  */
#line 779 "parser.y"
                                            {
                                                //change
                                                (yyval.nd_obj_arr2).sz = (yyvsp[-1].nd_obj_arr2).sz;
                                                (yyval.nd_obj_arr2).each_list_sz = (yyvsp[-1].nd_obj_arr2).each_list_sz;
                                                (yyval.nd_obj_arr2).nd = mknode((yyvsp[-1].nd_obj_arr2).nd, NULL, "multiple_num_list");
                                            }
#line 2660 "y.tab.c"
    break;

  case 74: /* multiple_character_list: LBRACE character_list RBRACE  */
#line 788 "parser.y"
                                        {
                                            //change
                                            (yyval.nd_obj_arr2).sz = 1;
                                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[-1].nd_obj_arr).sz;
                                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[-1].nd_obj_arr).nd, NULL, "multiple_character_list");
                                        }
#line 2671 "y.tab.c"
    break;

  case 75: /* multiple_character_list: LBRACE braced_character_list RBRACE  */
#line 794 "parser.y"
                                                {
                                                    //change
                                                    (yyval.nd_obj_arr2).sz = (yyvsp[-1].nd_obj_arr2).sz;
                                                    (yyval.nd_obj_arr2).each_list_sz = (yyvsp[-1].nd_obj_arr2).each_list_sz;
                                                    (yyval.nd_obj_arr2).nd = mknode((yyvsp[-1].nd_obj_arr2).nd, NULL, "multiple_character_list");
                                                }
#line 2682 "y.tab.c"
    break;

  case 76: /* multiple_float_num_list: LBRACE float_num_list RBRACE  */
#line 803 "parser.y"
                                        {
                                            //change
                                            (yyval.nd_obj_arr2).sz = 1;
                                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[-1].nd_obj_arr).sz;
                                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[-1].nd_obj_arr).nd, NULL, "multiple_float_num_list");
                                        }
#line 2693 "y.tab.c"
    break;

  case 77: /* multiple_float_num_list: LBRACE braced_float_num_list RBRACE  */
#line 809 "parser.y"
                                                {
                                                    //change
                                                    (yyval.nd_obj_arr2).sz = (yyvsp[-1].nd_obj_arr2).sz;
                                                    (yyval.nd_obj_arr2).each_list_sz = (yyvsp[-1].nd_obj_arr2).each_list_sz;
                                                    (yyval.nd_obj_arr2).nd = mknode((yyvsp[-1].nd_obj_arr2).nd, NULL, "multiple_float_num_list");
                                                }
#line 2704 "y.tab.c"
    break;

  case 78: /* braced_num_list: LBRACE number_list RBRACE  */
#line 818 "parser.y"
                                    {
                                        //change
                                        (yyval.nd_obj_arr2).sz = 1;
                                        (yyval.nd_obj_arr2).each_list_sz = (yyvsp[-1].nd_obj_arr).sz;
                                        (yyval.nd_obj_arr2).nd = mknode((yyvsp[-1].nd_obj_arr).nd, NULL, "braced_num_list");
                                    }
#line 2715 "y.tab.c"
    break;

  case 79: /* braced_num_list: LBRACE number_list RBRACE COMMA braced_num_list  */
#line 824 "parser.y"
                                                            {
                                                                //change
                                                                (yyval.nd_obj_arr2).sz = (yyvsp[0].nd_obj_arr2).sz + 1;
                                                                (yyval.nd_obj_arr2).each_list_sz = (yyvsp[-3].nd_obj_arr).sz > (yyvsp[0].nd_obj_arr2).each_list_sz ? (yyvsp[-3].nd_obj_arr).sz : (yyvsp[0].nd_obj_arr2).each_list_sz;
                                                                (yyval.nd_obj_arr2).nd = mknode((yyvsp[-3].nd_obj_arr).nd, (yyvsp[0].nd_obj_arr2).nd, "braced_num_list");
                                                            }
#line 2726 "y.tab.c"
    break;

  case 80: /* braced_character_list: LBRACE character_list RBRACE  */
#line 833 "parser.y"
                                        {
                                            //change
                                            (yyval.nd_obj_arr2).sz = 1;
                                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[-1].nd_obj_arr).sz;
                                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[-1].nd_obj_arr).nd, NULL, "braced_character_list");
                                        }
#line 2737 "y.tab.c"
    break;

  case 81: /* braced_character_list: LBRACE character_list RBRACE COMMA braced_character_list  */
#line 839 "parser.y"
                                                                        {
                                                                            //change
                                                                            (yyval.nd_obj_arr2).sz = (yyvsp[0].nd_obj_arr2).sz + 1;
                                                                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[-3].nd_obj_arr).sz > (yyvsp[0].nd_obj_arr2).each_list_sz ? (yyvsp[-3].nd_obj_arr).sz : (yyvsp[0].nd_obj_arr2).each_list_sz;
                                                                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[-3].nd_obj_arr).nd, (yyvsp[0].nd_obj_arr2).nd, "braced_character_list");
                                                                        }
#line 2748 "y.tab.c"
    break;

  case 82: /* braced_float_num_list: LBRACE float_num_list RBRACE  */
#line 848 "parser.y"
                                        {
                                            //change
                                            (yyval.nd_obj_arr2).sz = 1;
                                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[-1].nd_obj_arr).sz;
                                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[-1].nd_obj_arr).nd, NULL, "braced_float_num_list");
                                        }
#line 2759 "y.tab.c"
    break;

  case 83: /* braced_float_num_list: LBRACE float_num_list RBRACE COMMA braced_float_num_list  */
#line 854 "parser.y"
                                                                        {
                                                                            //change
                                                                            (yyval.nd_obj_arr2).sz = (yyvsp[0].nd_obj_arr2).sz + 1;
                                                                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[-3].nd_obj_arr).sz > (yyvsp[0].nd_obj_arr2).each_list_sz ? (yyvsp[-3].nd_obj_arr).sz : (yyvsp[0].nd_obj_arr2).each_list_sz;
                                                                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[-3].nd_obj_arr).nd, (yyvsp[0].nd_obj_arr2).nd, "braced_float_num_list");
                                                                        }
#line 2770 "y.tab.c"
    break;

  case 84: /* number_list: NUMBER  */
#line 863 "parser.y"
                                        {
                                            (yyval.nd_obj_arr).sz = 1;      //change
                                            (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
                                            (yyval.nd_obj_arr).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "number_list");
                                        }
#line 2780 "y.tab.c"
    break;

  case 85: /* number_list: NUMBER COMMA number_list  */
#line 868 "parser.y"
                                        {
                                            (yyval.nd_obj_arr).sz = (yyvsp[0].nd_obj_arr).sz + 1;  //change
                                            (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name);
                                            (yyval.nd_obj_arr).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj_arr).nd, "number_list");
                                        }
#line 2790 "y.tab.c"
    break;

  case 86: /* character_list: CHARACTER  */
#line 876 "parser.y"
                                            {
                                                (yyval.nd_obj_arr).sz = 1;      //change
                                                (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
                                                (yyval.nd_obj_arr).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "character_list");
                                            }
#line 2800 "y.tab.c"
    break;

  case 87: /* character_list: CHARACTER COMMA character_list  */
#line 881 "parser.y"
                                            {
                                                (yyval.nd_obj_arr).sz = (yyvsp[0].nd_obj_arr).sz + 1;  //change
                                                (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name);
                                                (yyval.nd_obj_arr).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj_arr).nd, "character_list");
                                            }
#line 2810 "y.tab.c"
    break;

  case 88: /* stringconst_list: stringconst COMMA stringconst_list  */
#line 888 "parser.y"
                                            {
                                                    //change2
                                                    (yyval.nd_obj_arr2).sz = (yyvsp[0].nd_obj_arr2).sz + 1;
                                                    (yyval.nd_obj_arr2).each_list_sz = (yyvsp[-2].nd_obj_arr).sz > (yyvsp[0].nd_obj_arr2).each_list_sz ? (yyvsp[-2].nd_obj_arr).sz : (yyvsp[0].nd_obj_arr2).each_list_sz;
                                                    (yyvsp[-2].nd_obj_arr).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj_arr).name);
                                                    (yyval.nd_obj_arr2).nd = mknode((yyvsp[-2].nd_obj_arr).nd, (yyvsp[0].nd_obj_arr2).nd, "stringconst_list");
                                                }
#line 2822 "y.tab.c"
    break;

  case 89: /* stringconst_list: stringconst  */
#line 895 "parser.y"
                          {
                            //change2
                            (yyval.nd_obj_arr2).sz = 1;
                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[0].nd_obj_arr).sz;
                            (yyvsp[0].nd_obj_arr).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj_arr).name);
                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[0].nd_obj_arr).nd, NULL, "stringconst_list");
                        }
#line 2834 "y.tab.c"
    break;

  case 90: /* float_num_list: FLOAT_NUM  */
#line 905 "parser.y"
                                            {
                                                (yyval.nd_obj_arr).sz = 1;      //change
                                                (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
                                                (yyval.nd_obj_arr).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "float_num_list");
                                            }
#line 2844 "y.tab.c"
    break;

  case 91: /* float_num_list: FLOAT_NUM COMMA float_num_list  */
#line 910 "parser.y"
                                            {
                                                (yyval.nd_obj_arr).sz = (yyvsp[0].nd_obj_arr).sz + 1;  //change
                                                (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name);
                                                (yyval.nd_obj_arr).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj_arr).nd, "float_num_list");
                                            }
#line 2854 "y.tab.c"
    break;

  case 92: /* $@10: %empty  */
#line 919 "parser.y"
            {
                yytext = malloc(sizeof(char)*strlen((yyvsp[0].nd_obj2).name));
                strcpy(yytext, (yyvsp[0].nd_obj2).name);
                add('V');
            }
#line 2864 "y.tab.c"
    break;

  case 93: /* assignment_statement: ID $@10 ASSIGNMENT expression_statement  */
#line 923 "parser.y"
                                                {
                                                    printf("Types: 1 %s 2 %s\n", get_type((yyvsp[-3].nd_obj2).name), (yyvsp[0].nd_obj3).type);
                                                    if(strcmp(get_type((yyvsp[-3].nd_obj2).name), (yyvsp[0].nd_obj3).type) != 0)
                                                    {
                                                        printf("Error: Type mismatch in assignment statement %d\n",yylineno);
                                                        exit(1);
                                                    }
                                                    (yyvsp[-3].nd_obj2).value=(yyvsp[0].nd_obj3).value;
                                                    (yyvsp[-3].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj2).name);
                                                    (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-3].nd_obj2).nd, (yyvsp[0].nd_obj3).nd, "ASSIGNMENT");
                                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "assignment_statement");

                                                    sprintf(icg[ic_idx++], "%s = t%d\n", (yyvsp[-3].nd_obj2).name, (yyvsp[0].nd_obj3).t);
                                                }
#line 2883 "y.tab.c"
    break;

  case 94: /* expression_statement: expression_statement OR logical_o_exp  */
#line 940 "parser.y"
                                                {   
                                                    sprintf((yyval.nd_obj3).type, "int");
                                                    (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "OR");
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "expression_statement");
                                                    (yyval.nd_obj3).value = (yyvsp[-2].nd_obj3).value || (yyvsp[0].nd_obj3).value;

                                                    if(is_if == 1) {
                                                        sprintf(icg[ic_idx++], "\nIF t%d OR t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label, label + 1);
                                                        sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                        sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                    } 
                                                    else if(is_for == 1) {
                                                        sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                        sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                        sprintf(icg[ic_idx++], "if NOT (t%d OR t%d) GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label);
                                                        sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                    }
                                                    else {
                                                        (yyval.nd_obj3).t = temp_var++;
                                                        sprintf(icg[ic_idx++], "t%d = %d OR t%d\n", (yyval.nd_obj3).t, (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t);
                                                    }
                                                }
#line 2910 "y.tab.c"
    break;

  case 95: /* expression_statement: logical_o_exp  */
#line 962 "parser.y"
                                                {
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "expression_statement");   
                                                    sprintf((yyval.nd_obj3).type, (yyvsp[0].nd_obj3).type);
                                                    (yyval.nd_obj3).value = (yyvsp[0].nd_obj3).value;

                                                    (yyval.nd_obj3).t = (yyvsp[0].nd_obj3).t;
                                                }
#line 2922 "y.tab.c"
    break;

  case 96: /* logical_o_exp: logical_o_exp AND logical_a_exp  */
#line 972 "parser.y"
                                        {   
                                            sprintf((yyval.nd_obj3).type, "int");
                                            (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "AND");
                                            (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "logical_or_expression");
                                            (yyval.nd_obj3).value = (yyvsp[-2].nd_obj3).value && (yyvsp[0].nd_obj3).value;

                                            if(is_if == 1) {
                                                sprintf(icg[ic_idx++], "\nIF t%d AND t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label, label + 1);
                                                sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                            }
                                            else if(is_for == 1) {
                                                sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                sprintf(icg[ic_idx++], "if NOT (t%d AND t%d) GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label);
                                                sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                            }
                                            else {
                                                (yyval.nd_obj3).t = temp_var++;
                                                sprintf(icg[ic_idx++], "t%d = t%d AND t%d\n", (yyval.nd_obj3).t, (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t);
                                            }
                                        }
#line 2949 "y.tab.c"
    break;

  case 97: /* logical_o_exp: logical_a_exp  */
#line 994 "parser.y"
                                        {   
                                            (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "logical_or_expression");   
                                            sprintf((yyval.nd_obj3).type, (yyvsp[0].nd_obj3).type);
                                            (yyval.nd_obj3).value = (yyvsp[0].nd_obj3).value;

                                            (yyval.nd_obj3).t = (yyvsp[0].nd_obj3).t;
                                        }
#line 2961 "y.tab.c"
    break;

  case 98: /* logical_a_exp: logical_a_exp EQ relational_exp  */
#line 1004 "parser.y"
                                            {
                                                sprintf((yyval.nd_obj3).type, "int");
                                                (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "EQ");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "logical_a_exp");
                                                (yyval.nd_obj3).value = (yyvsp[-2].nd_obj3).value==(yyvsp[0].nd_obj3).value;

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d == t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label, label + 1);
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d == t%d) GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else {
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d == t%d\n", (yyval.nd_obj3).t, (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t);
                                                }
                                            }
#line 2988 "y.tab.c"
    break;

  case 99: /* logical_a_exp: logical_a_exp NE relational_exp  */
#line 1026 "parser.y"
                                            {
                                                sprintf((yyval.nd_obj3).type, "int");
                                                (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "NE");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "logical_a_exp");
                                                (yyval.nd_obj3).value = (yyvsp[-2].nd_obj3).value!=(yyvsp[0].nd_obj3).value;

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d != t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label, label + 1);
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d != t%d) GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else {
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d != t%d\n", (yyval.nd_obj3).t, (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t);
                                                }
                                            }
#line 3015 "y.tab.c"
    break;

  case 100: /* logical_a_exp: relational_exp  */
#line 1048 "parser.y"
                                            {   
                                                (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "logical_a_exp");   
                                                sprintf((yyval.nd_obj3).type, (yyvsp[0].nd_obj3).type);
                                                (yyval.nd_obj3).value = (yyvsp[0].nd_obj3).value;

                                                (yyval.nd_obj3).t = (yyvsp[0].nd_obj3).t;
                                            }
#line 3027 "y.tab.c"
    break;

  case 101: /* relational_exp: relational_exp GT additive_exp  */
#line 1058 "parser.y"
                                            {
                                                if(strcmp((yyvsp[-2].nd_obj3).type, "char") == 0 || strcmp((yyvsp[0].nd_obj3).type, "char") == 0){
                                                    printf("Can't compare character in line %d\n", yylineno);
                                                    exit(1);
                                                }
                                                sprintf((yyval.nd_obj3).type, "int");
                                                (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "GT");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "relational_exp");
                                                (yyval.nd_obj3).value = (yyvsp[-2].nd_obj3).value>(yyvsp[0].nd_obj3).value;

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d > t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label, label + 1);
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d > t%d) GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else {
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d > t%d\n", (yyval.nd_obj3).t, (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t);
                                                }
                                            }
#line 3058 "y.tab.c"
    break;

  case 102: /* relational_exp: relational_exp GE additive_exp  */
#line 1084 "parser.y"
                                            {
                                                if(strcmp((yyvsp[-2].nd_obj3).type, "char") == 0 || strcmp((yyvsp[0].nd_obj3).type, "char") == 0){
                                                    printf("Can't compare character in line %d\n", yylineno);
                                                    exit(1);
                                                }
                                                sprintf((yyval.nd_obj3).type, "int");
                                                (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "GE");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "relational_exp");
                                                (yyval.nd_obj3).value = (yyvsp[-2].nd_obj3).value>=(yyvsp[0].nd_obj3).value;

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d >= t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label, label + 1);
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d >= t%d) GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else {
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d >= t%d\n", (yyval.nd_obj3).t, (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t);
                                                }
                                            }
#line 3089 "y.tab.c"
    break;

  case 103: /* relational_exp: relational_exp LT additive_exp  */
#line 1110 "parser.y"
                                            {
                                                if(strcmp((yyvsp[-2].nd_obj3).type, "char") == 0 || strcmp((yyvsp[0].nd_obj3).type, "char") == 0){
                                                    printf("Can't compare character in line %d\n", yylineno);
                                                    exit(1);
                                                }
                                                sprintf((yyval.nd_obj3).type, "int");
                                                (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "LT");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "relational_exp");
                                                (yyval.nd_obj3).value = (yyvsp[-2].nd_obj3).value<(yyvsp[0].nd_obj3).value;

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d < t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label, label + 1);
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d < t%d) GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else {
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d < t%d\n", (yyval.nd_obj3).t, (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t);
                                                }
                                            }
#line 3120 "y.tab.c"
    break;

  case 104: /* relational_exp: relational_exp LE additive_exp  */
#line 1136 "parser.y"
                                            {
                                                if(strcmp((yyvsp[-2].nd_obj3).type, "char") == 0 || strcmp((yyvsp[0].nd_obj3).type, "char") == 0){
                                                    printf("Can't compare character in line %d\n", yylineno);
                                                    exit(1);
                                                }
                                                sprintf((yyval.nd_obj3).type, "int");
                                                (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "LE");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "relational_exp");
                                                (yyval.nd_obj3).value = (yyvsp[-2].nd_obj3).value<(yyvsp[0].nd_obj3).value;

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d <= t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label, label + 1);
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d <= t%d) GOTO L%d\n", (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t, label);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else {
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d <= t%d\n", (yyval.nd_obj3).t, (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t);
                                                }
                                            }
#line 3151 "y.tab.c"
    break;

  case 105: /* relational_exp: additive_exp  */
#line 1162 "parser.y"
                                            {   
                                                (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "relational_exp");  
                                                sprintf((yyval.nd_obj3).type, (yyvsp[0].nd_obj3).type);
                                                (yyval.nd_obj3).value = (yyvsp[0].nd_obj3).value;

                                                (yyval.nd_obj3).t = (yyvsp[0].nd_obj3).t;
                                            }
#line 3163 "y.tab.c"
    break;

  case 106: /* additive_exp: additive_exp ADD multiplicative_exp  */
#line 1172 "parser.y"
                                                {
                                                    if(strcmp((yyvsp[-2].nd_obj3).type, "char") == 0 || strcmp((yyvsp[0].nd_obj3).type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp((yyvsp[-2].nd_obj3).type, (yyvsp[0].nd_obj3).type)) {
		                                                sprintf((yyval.nd_obj3).type, (yyvsp[-2].nd_obj3).type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line  %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "ADD");
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "additive_exp");
                                                    (yyval.nd_obj3).value = (yyvsp[-2].nd_obj3).value+(yyvsp[0].nd_obj3).value;

                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d + t%d\n", (yyval.nd_obj3).t, (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t);
                                                }
#line 3187 "y.tab.c"
    break;

  case 107: /* additive_exp: additive_exp SUB multiplicative_exp  */
#line 1191 "parser.y"
                                                {
                                                    if(strcmp((yyvsp[-2].nd_obj3).type, "char") == 0 || strcmp((yyvsp[0].nd_obj3).type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp((yyvsp[-2].nd_obj3).type, (yyvsp[0].nd_obj3).type)) {
		                                                sprintf((yyval.nd_obj3).type, (yyvsp[-2].nd_obj3).type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    (yyval.nd_obj3).value = (yyvsp[-2].nd_obj3).value-(yyvsp[0].nd_obj3).value;
                                                    (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "SUB");
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "additive_exp");

                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d - t%d\n", (yyval.nd_obj3).t, (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t);
                                                }
#line 3211 "y.tab.c"
    break;

  case 108: /* additive_exp: multiplicative_exp  */
#line 1210 "parser.y"
                                                {   
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "additive_exp");    
                                                    sprintf((yyval.nd_obj3).type, (yyvsp[0].nd_obj3).type);
                                                    (yyval.nd_obj3).value = (yyvsp[0].nd_obj3).value;
                                                    (yyval.nd_obj3).t = (yyvsp[0].nd_obj3).t;
                                                }
#line 3222 "y.tab.c"
    break;

  case 109: /* multiplicative_exp: multiplicative_exp MUL negation_exp  */
#line 1219 "parser.y"
                                                {   
                                                    if(strcmp((yyvsp[-2].nd_obj3).type, "char") == 0 || strcmp((yyvsp[0].nd_obj3).type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp((yyvsp[-2].nd_obj3).type, (yyvsp[0].nd_obj3).type)) {
		                                                sprintf((yyval.nd_obj3).type, (yyvsp[-2].nd_obj3).type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "MUL");
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "multiplicative_exp");
                                                    (yyval.nd_obj3).value = (yyvsp[-2].nd_obj3).value/(yyvsp[0].nd_obj3).value;
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d * t%d\n", (yyval.nd_obj3).t, (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t);
                                                }
#line 3245 "y.tab.c"
    break;

  case 110: /* multiplicative_exp: multiplicative_exp DIV negation_exp  */
#line 1237 "parser.y"
                                                {
                                                    if(strcmp((yyvsp[-2].nd_obj3).type, "char") == 0 || strcmp((yyvsp[0].nd_obj3).type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp((yyvsp[-2].nd_obj3).type, (yyvsp[0].nd_obj3).type)) {
		                                                sprintf((yyval.nd_obj3).type, (yyvsp[-2].nd_obj3).type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    if(strcmp((yyvsp[-2].nd_obj3).name,"0")==0){
                                                        printf("Divide by zero error in line %d\n", yylineno);
                                                    }
                                                    (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "DIV");
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "multiplicative_exp");
                                                    (yyval.nd_obj3).value = (yyvsp[-2].nd_obj3).value/(yyvsp[0].nd_obj3).value;
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d / t%d\n", (yyval.nd_obj3).t, (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t);
                                                }
#line 3271 "y.tab.c"
    break;

  case 111: /* multiplicative_exp: multiplicative_exp MOD negation_exp  */
#line 1258 "parser.y"
                                                {
                                                    if(strcmp((yyvsp[-2].nd_obj3).type, "char") == 0 || strcmp((yyvsp[0].nd_obj3).type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp((yyvsp[-2].nd_obj3).type, (yyvsp[0].nd_obj3).type)) {
		                                                sprintf((yyval.nd_obj3).type, (yyvsp[-2].nd_obj3).type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "MOD");
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "multiplicative_exp");
                                                    (yyval.nd_obj3).value = (yyvsp[-2].nd_obj3).value%(yyvsp[0].nd_obj3).value;                                                
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d %% t%d\n", (yyval.nd_obj3).t, (yyvsp[-2].nd_obj3).t, (yyvsp[0].nd_obj3).t);
                                                }
#line 3294 "y.tab.c"
    break;

  case 112: /* multiplicative_exp: negation_exp  */
#line 1276 "parser.y"
                                                {   
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "multiplicative_exp");  
                                                    sprintf((yyval.nd_obj3).type, (yyvsp[0].nd_obj3).type);
                                                    (yyval.nd_obj3).value = (yyvsp[0].nd_obj3).value;
                                                    (yyval.nd_obj3).t = (yyvsp[0].nd_obj3).t;
                                                }
#line 3305 "y.tab.c"
    break;

  case 113: /* negation_exp: NOT access_call_exp  */
#line 1285 "parser.y"
                            {
                            if(strcmp((yyvsp[0].nd_obj3).type, "int") != 0){
                                printf("Type mismatch in line %d\n", yylineno);
                                exit(1);
                            }
                            (yyval.nd_obj3).value= !((yyvsp[0].nd_obj3).value);
                            sprintf((yyval.nd_obj3).type, (yyvsp[0].nd_obj3).type);
                            (yyvsp[-1].nd_obj).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "NOT");
                            (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "negation_exp");

                            if(is_if == 1) {
                                sprintf(icg[ic_idx++], "\nIF !t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[0].nd_obj3).t, label, label + 1);
                                sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                            }
                            else if(is_for == 1) {
                                sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                sprintf(icg[ic_idx++], "if NOT (!t%d) GOTO L%d\n", (yyvsp[0].nd_obj3).t, label);
                                sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                            }
                            (yyval.nd_obj3).t = temp_var++;
                            sprintf(icg[ic_idx++], "t%d = !t%d\n", (yyval.nd_obj3).t, (yyvsp[0].nd_obj3).t);
                        }
#line 3334 "y.tab.c"
    break;

  case 114: /* negation_exp: access_call_exp  */
#line 1309 "parser.y"
                            {   
                                sprintf((yyval.nd_obj3).type, (yyvsp[0].nd_obj3).type);
                                (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "negation_exp");
                                (yyval.nd_obj3).value = (yyvsp[0].nd_obj3).value;
                                (yyval.nd_obj3).t = (yyvsp[0].nd_obj3).t;  
                            }
#line 3345 "y.tab.c"
    break;

  case 115: /* access_call_exp: access_call_exp LSQBRACKET NUMBER RSQBRACKET  */
#line 1318 "parser.y"
                                                       {
                                                        if(check_declaration((yyvsp[-3].nd_obj3).name)==0){
                                                            printf("Variable %s not declared in line %d\n", (yyvsp[-3].nd_obj3).name, yylineno);
                                                            exit(1);
                                                        }
                                                        sprintf((yyval.nd_obj3).type, (yyvsp[-3].nd_obj3).type);
                                                        (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name);
                                                        (yyval.nd_obj3).nd = mknode((yyvsp[-3].nd_obj3).nd, (yyvsp[-1].nd_obj).nd, "access_call_exp");
                                                        if(strcmp((yyvsp[-3].nd_obj3).type, "int") == 0)
                                                            (yyval.nd_obj3).value = (yyvsp[-3].nd_obj3).value + 4*atoi((yyvsp[-1].nd_obj).name);
                                                        else if(strcmp((yyvsp[-3].nd_obj3).type, "char") == 0)
                                                            (yyval.nd_obj3).value = (yyvsp[-3].nd_obj3).value + 1*atoi((yyvsp[-1].nd_obj).name);
                                                        else if(strcmp((yyvsp[-3].nd_obj3).type, "float") == 0)
                                                            (yyval.nd_obj3).value = (yyvsp[-3].nd_obj3).value + 8*atoi((yyvsp[-1].nd_obj).name);
                                                        (yyval.nd_obj3).t = temp_var++;
                                                        if(strcmp((yyvsp[-3].nd_obj3).type, "int") == 0)
                                                            sprintf(icg[ic_idx++], "t%d = 4 * %d\n", (yyval.nd_obj3).t, atoi((yyvsp[-1].nd_obj).name));
                                                        else if(strcmp((yyvsp[-3].nd_obj3).type, "char") == 0)
                                                            sprintf(icg[ic_idx++], "t%d = 1 * %d\n", (yyval.nd_obj3).t, atoi((yyvsp[-1].nd_obj).name));
                                                        else if(strcmp((yyvsp[-3].nd_obj3).type, "float") == 0)
                                                            sprintf(icg[ic_idx++], "t%d = 8 * %d\n", (yyval.nd_obj3).t, atoi((yyvsp[-1].nd_obj).name));
                                                        
                                                        (yyval.nd_obj3).t = temp_var++;
                                                        sprintf(icg[ic_idx++], "t%d = &%s\n", (yyval.nd_obj3).t, (yyvsp[-3].nd_obj3).name);

                                                        (yyval.nd_obj3).t = temp_var++;
                                                        sprintf(icg[ic_idx++], "t%d = t%d + t%d\n", (yyval.nd_obj3).t, (yyval.nd_obj3).t - 1, (yyval.nd_obj3).t - 2);
                                                        arr_en = 1;
                                                        // sprintf(icg[ic_idx++], "%s = *t%d\n", "HAHA", $$.t);
                                                    }
#line 3380 "y.tab.c"
    break;

  case 116: /* access_call_exp: primary_exp  */
#line 1348 "parser.y"
                        {   
                            sprintf((yyval.nd_obj3).type, (yyvsp[0].nd_obj3).type);
                            (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "access_call_exp");
                            (yyval.nd_obj3).value = (yyvsp[0].nd_obj3).value;
                            (yyval.nd_obj3).t = (yyvsp[0].nd_obj3).t;  
                        }
#line 3391 "y.tab.c"
    break;

  case 117: /* access_call_exp: access_call_exp LPAREN RPAREN  */
#line 1354 "parser.y"
                                            {
                                                printf("Checking for function name %s\n", (yyvsp[-2].nd_obj3).name);
                                                if(check_declaration((yyvsp[-2].nd_obj3).name)==0){
                                                    printf("BACK TO access_call_exp\n");
                                                    printf("Variable %s not declared in line %d\n", (yyvsp[-2].nd_obj3).name, yylineno);
                                                    exit(1);
                                                }
                                                printf("BACK TO access_call_exp\n");
                                                checkFinalArguments((yyvsp[-2].nd_obj3).name);
                                                (yyval.nd_obj3).value=(yyvsp[-2].nd_obj3).value;
                                                (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, "LPAREN");
                                                (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, "RPAREN");
                                                struct node *temp = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "PARENTHESES");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[-2].nd_obj3).nd, temp, "access_call_exp");
                                            }
#line 3411 "y.tab.c"
    break;

  case 118: /* $@11: %empty  */
#line 1369 "parser.y"
                                    {
            stringTemp=strdup(currentFunction);
            strcpy(currentFunction, (yyvsp[-1].nd_obj3).name);
            }
#line 3420 "y.tab.c"
    break;

  case 119: /* access_call_exp: access_call_exp LPAREN $@11 calling_list RPAREN  */
#line 1372 "parser.y"
                                   { 
                                        strcpy(currentFunction, stringTemp);  
                                        printf("Accessing Function %s\n", (yyvsp[-4].nd_obj3).name);
                                        if(check_declaration((yyvsp[-4].nd_obj3).name)==0){
                                            printf("Variable %s not declared in line %d\n", (yyvsp[-4].nd_obj3).name, yylineno);
                                            exit(1);
                                        }
                                        (yyval.nd_obj3).value=(yyvsp[-4].nd_obj3).value;
                                        (yyval.nd_obj3).nd = mknode((yyvsp[-4].nd_obj3).nd, (yyvsp[-1].nd_obj).nd, "access_call_exp");    
                                    }
#line 3435 "y.tab.c"
    break;

  case 120: /* primary_exp: LPAREN expression_statement RPAREN  */
#line 1385 "parser.y"
                                            {   
                                                (yyval.nd_obj3).value=(yyvsp[-1].nd_obj3).value;
                                                (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj3).nd, NULL, "primary_exp"); 
                                                sprintf((yyval.nd_obj3).type, (yyvsp[-1].nd_obj3).type);

                                                (yyval.nd_obj3).t = (yyvsp[-1].nd_obj3).t;
                                            }
#line 3447 "y.tab.c"
    break;

  case 121: /* primary_exp: ID  */
#line 1392 "parser.y"
                                            {  
                                                printf("Checking for variable name %s\n", (yyvsp[0].nd_obj2).name);
                                                if(check_declaration((yyvsp[0].nd_obj2).name)==0){
                                                    printf("Variable %s not declared in line %d\n", (yyvsp[0].nd_obj2).name, yylineno);
                                                    exit(1);
                                                }
                                                sprintf((yyval.nd_obj3).type, get_type((yyvsp[0].nd_obj2).name));
                                                (yyvsp[0].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj2).name);
                                                (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj2).nd, NULL, "primary_exp");

                                                (yyval.nd_obj3).t = temp_var++;
                                                sprintf(icg[ic_idx++], "t%d = %s\n", (yyval.nd_obj3).t, (yyvsp[0].nd_obj2).name);
                                            }
#line 3465 "y.tab.c"
    break;

  case 122: /* primary_exp: constant  */
#line 1405 "parser.y"
                                            {   
                                                (yyval.nd_obj3).value=(yyvsp[0].nd_obj3).value;
                                                sprintf((yyval.nd_obj3).type, (yyvsp[0].nd_obj3).type);
                                                (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "primary_exp");

                                                (yyval.nd_obj3).t = temp_var++;
                                                sprintf(icg[ic_idx++], "t%d = %s\n", (yyval.nd_obj3).t, (yyvsp[0].nd_obj3).name);
                                            }
#line 3478 "y.tab.c"
    break;

  case 123: /* constant: NUMBER  */
#line 1416 "parser.y"
                        {
                            (yyval.nd_obj3).value = atoi((yyvsp[0].nd_obj).name);
                            sprintf((yyval.nd_obj3).type, "int");
                            (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
                            (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "constant");

                            // strcpy($$.name, $1.name);
                        }
#line 3491 "y.tab.c"
    break;

  case 124: /* constant: CHARACTER  */
#line 1424 "parser.y"
                        {
                            (yyval.nd_obj3).value = (yyvsp[0].nd_obj).name;
                            sprintf((yyval.nd_obj3).type, "char");
                            (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
                            (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "constant");

                            // strcpy($$.name, $1.name);
                        }
#line 3504 "y.tab.c"
    break;

  case 125: /* constant: FLOAT_NUM  */
#line 1432 "parser.y"
                        {
                            (yyval.nd_obj3).value = atof((yyvsp[0].nd_obj).name);
                            sprintf((yyval.nd_obj3).type, "float");
                            (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
                            (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "constant");

                            // strcpy($$.name, $1.name);
                        }
#line 3517 "y.tab.c"
    break;

  case 126: /* constant: EXPONENT  */
#line 1440 "parser.y"
                            {
                            (yyval.nd_obj3).value = atof((yyvsp[0].nd_obj).name);
                            sprintf((yyval.nd_obj3).type, "exp");
                            (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
                            (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "constant");

                            // strcpy($$.name, $1.name);
                        }
#line 3530 "y.tab.c"
    break;

  case 127: /* $@12: %empty  */
#line 1451 "parser.y"
                  {is_if = 1;}
#line 3536 "y.tab.c"
    break;

  case 128: /* $@13: %empty  */
#line 1451 "parser.y"
                                                           {sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[-1].nd_obj3).if_body);}
#line 3542 "y.tab.c"
    break;

  case 129: /* $@14: %empty  */
#line 1451 "parser.y"
                                                                                                                                     {sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[-3].nd_obj3).else_body);}
#line 3548 "y.tab.c"
    break;

  case 130: /* if_statement: IF LPAREN $@12 expression_statement RPAREN $@13 compound_statement $@14 EL_statement  */
#line 1452 "parser.y"
                                                                        {
                                                                            (yyvsp[-8].nd_obj).nd = mknode((yyvsp[-5].nd_obj3).nd,(yyvsp[-2].nd_obj).nd,"IF");
                                                                            // $9.nd = mknode($10.nd,NULL,"ELSE");
                                                                            (yyval.nd_obj).nd = mknode((yyvsp[-8].nd_obj).nd,(yyvsp[0].nd_obj).nd,"IF_statement");
                                                                            is_if = 0;
                                                                        }
#line 3559 "y.tab.c"
    break;

  case 131: /* EL_statement: ELSE compound_statement  */
#line 1460 "parser.y"
                                {
                                    (yyvsp[-1].nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "ELSE");
                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "EL_statement");    
                                }
#line 3568 "y.tab.c"
    break;

  case 132: /* EL_statement: %empty  */
#line 1464 "parser.y"
            {   (yyval.nd_obj).nd = NULL; }
#line 3574 "y.tab.c"
    break;

  case 133: /* $@15: %empty  */
#line 1469 "parser.y"
                   {
            nextTable();
            is_for = 1;
        }
#line 3583 "y.tab.c"
    break;

  case 134: /* for_statement: FOR LPAREN $@15 for_initializer for_condition for_update RPAREN LBRACE loop_stat_list RBRACE  */
#line 1474 "parser.y"
                                                                    {
                                                                        prevTable();
                                                                        struct node *temp1 = mknode((yyvsp[-6].nd_obj).nd, (yyvsp[-5].nd_obj3).nd, "For_Parameters_1");
                                                                        struct node *temp2 = mknode(temp1, (yyvsp[-4].nd_obj).nd, "For_Parameters_2");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[-1].nd_obj).nd, "For_Statement");

                                                                        sprintf(icg[ic_idx++], buff);
                                                                        sprintf(icg[ic_idx++], "JUMP TO %s\n", (yyvsp[-5].nd_obj3).if_body);
                                                                        sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[-5].nd_obj3).else_body);
                                                                        is_for = 0;
                                                                    }
#line 3599 "y.tab.c"
    break;

  case 135: /* assignment_statement_2: ID ASSIGNMENT expression_statement  */
#line 1487 "parser.y"
                                                            {   
                                                                if(check_declaration((yyvsp[-2].nd_obj2).name) == 0 || isArray((yyvsp[-2].nd_obj2).name) == 1)
                                                                {
                                                                    printf("Error: Variable %s not declared at line %d\n", (yyvsp[-2].nd_obj2).name, yylineno);
                                                                    exit(1);
                                                                }
                                                                printf("Types of %s is %s\n", get_type((yyvsp[-2].nd_obj2).name), (yyvsp[0].nd_obj3).type);
                                                                if(strcmp(get_type((yyvsp[-2].nd_obj2).name), (yyvsp[0].nd_obj3).type) != 0)
                                                                {
                                                                    printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                    exit(1);
                                                                }
                                                                (yyvsp[-2].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj2).name);
                                                                (yyvsp[-1].nd_obj).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj3).nd, "ASSIGNMENT");
                                                                (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "assignment_statement");

                                                                // if(is_for == 1) {
                                                                //     // if(for_up == 1)
                                                                //     //     sprintf(buff, "t%d = %s\n", $3.t, $1.name);
                                                                //     // else
                                                                //     // sprintf(buff, "t%d = %s\n", $3.t, $1.name);
                                                                //         sprintf(buff, "%s = t%d\n", $1.name, $3.t);//correct
                                                                //     // sprintf(buff, "%s = t%d\n", $1.name, temp_var);
                                                                // }
                                                                // else {
                                                                (yyvsp[-2].nd_obj2).value=(yyvsp[0].nd_obj3).value;
                                                                    if(arr_en == 1) {
                                                                        sprintf(icg[ic_idx++], "%s = *t%d\n", (yyvsp[-2].nd_obj2).name, (yyvsp[0].nd_obj3).t);
                                                                        arr_en = 0;
                                                                    }
                                                                    else {
                                                                        sprintf(icg[ic_idx++], "%s = t%d\n", (yyvsp[-2].nd_obj2).name, (yyvsp[0].nd_obj3).t);
                                                                    }
                                                                // }
                                                                //need to put a = *T3 here after array
                                                                    
                                                            }
#line 3641 "y.tab.c"
    break;

  case 136: /* assignment_statement_2: ID LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT expression_statement  */
#line 1524 "parser.y"
                                                                            {
                                                                                if(check_declaration((yyvsp[-5].nd_obj2).name) == 0 || isArray((yyvsp[-5].nd_obj2).name) == 0)
                                                                                {
                                                                                    printf("Error: Variable %s is not an array at line %d\n", (yyvsp[-5].nd_obj2).name, yylineno);
                                                                                    exit(1);
                                                                                }
                                                                                printf("Types of %s is %s\n", get_type((yyvsp[-5].nd_obj2).name), (yyvsp[0].nd_obj3).type);
                                                                                if(strcmp(get_type((yyvsp[-5].nd_obj2).name), (yyvsp[0].nd_obj3).type) != 0)
                                                                                {
                                                                                    printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                    exit(1);
                                                                                }
                                                                                (yyvsp[-5].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-5].nd_obj2).name);
                                                                                (yyvsp[-4].nd_obj).nd = mknode((yyvsp[-5].nd_obj2).nd, (yyvsp[-3].nd_obj).nd, "LSQBRACKET");
                                                                                (yyvsp[-2].nd_obj).nd = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "RSQBRACKET");
                                                                                (yyvsp[0].nd_obj3).nd = mknode((yyvsp[-2].nd_obj).nd, NULL, "ASSIGNMENT");
                                                                                (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "assignment_statement");

                                                                                // $$.t = temp_var++;
                                                                                (yyvsp[-5].nd_obj2).value=(yyvsp[0].nd_obj3).value;
                                                                                if(strcmp(get_type((yyvsp[-5].nd_obj2).name), "int") == 0)
                                                                                    sprintf(icg[ic_idx++], "t%d = 4 * %d\n", temp_var++, atoi((yyvsp[-3].nd_obj).name));
                                                                                else if(strcmp(get_type((yyvsp[-5].nd_obj2).name), "char") == 0)
                                                                                    sprintf(icg[ic_idx++], "t%d = 1 * %d\n", temp_var++, atoi((yyvsp[-3].nd_obj).name));
                                                                                else if(strcmp(get_type((yyvsp[-5].nd_obj2).name), "float") == 0)
                                                                                    sprintf(icg[ic_idx++], "t%d = 8 * %d\n", temp_var++, atoi((yyvsp[-3].nd_obj).name));
                                                                                

                                                                                // $$.t = temp_var++;
                                                                                sprintf(icg[ic_idx++], "t%d = &%s\n", temp_var++, (yyvsp[-5].nd_obj2).name);

                                                                                // $$.t = temp_var++;
                                                                                sprintf(icg[ic_idx++], "t%d = t%d + t%d\n", temp_var, temp_var - 2, temp_var - 1);

                                                                                sprintf(icg[ic_idx++], "*t%d = t%d", temp_var, (yyvsp[0].nd_obj3).t);
                                                                                // arr_en = 1;
                                                                            }
#line 3683 "y.tab.c"
    break;

  case 137: /* assignment_statement_2: ID LSQBRACKET ID RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT expression_statement  */
#line 1561 "parser.y"
                                                                                                                         {
                                                                                                                    printf("Testing Here 4\n");
                                                                                                                    if(check_declaration((yyvsp[-8].nd_obj2).name) == 0 || isArray((yyvsp[-8].nd_obj2).name) == 0)
                                                                                                                    {
                                                                                                                        printf("Error: Variable %s is not an array at line %d\n", (yyvsp[-8].nd_obj2).name, yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    printf("Types of %s is %s\n", get_type((yyvsp[-8].nd_obj2).name), (yyvsp[0].nd_obj3).type);
                                                                                                                    if(strcmp(get_type((yyvsp[-8].nd_obj2).name), (yyvsp[0].nd_obj3).type) != 0)
                                                                                                                    {
                                                                                                                        printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    (yyvsp[-8].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-8].nd_obj2).name);
                                                                                                                    (yyvsp[-7].nd_obj).nd = mknode((yyvsp[-8].nd_obj2).nd, (yyvsp[-6].nd_obj2).nd, "LSQBRACKET");
                                                                                                                    (yyvsp[-5].nd_obj).nd = mknode((yyvsp[-7].nd_obj).nd, (yyvsp[-4].nd_obj).nd, "RSQBRACKET");
                                                                                                                    (yyvsp[0].nd_obj3).nd = mknode((yyvsp[-5].nd_obj).nd, NULL, "ASSIGNMENT");
                                                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "assignment_statement");
                                                                                                                }
#line 3707 "y.tab.c"
    break;

  case 138: /* assignment_statement_2: ID LSQBRACKET ID RSQBRACKET LSQBRACKET ID RSQBRACKET ASSIGNMENT expression_statement  */
#line 1580 "parser.y"
                                                                                               {
                                                                                        printf("Testing Here 5\n");
                                                                                        if(check_declaration((yyvsp[-8].nd_obj2).name) == 0 || isArray((yyvsp[-8].nd_obj2).name) == 0)
                                                                                        {
                                                                                            printf("Error: Variable %s is not an array at line %d\n", (yyvsp[-8].nd_obj2).name, yylineno);
                                                                                            exit(1);
                                                                                        }
                                                                                        if(check_declaration((yyvsp[-6].nd_obj2).name) == 0 || isArray((yyvsp[-6].nd_obj2).name) == 1)
                                                                                        {
                                                                                            printf("Error: Variable %s not declared at line %d\n", (yyvsp[-6].nd_obj2).name, yylineno);
                                                                                            exit(1);
                                                                                        }
                                                                                        printf("Types of %s is %s\n", get_type((yyvsp[-8].nd_obj2).name), (yyvsp[0].nd_obj3).type);
                                                                                        if(strcmp(get_type((yyvsp[-8].nd_obj2).name), (yyvsp[0].nd_obj3).type) != 0)
                                                                                        {
                                                                                            printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                            exit(1);
                                                                                        }
                                                                                        (yyvsp[-8].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-8].nd_obj2).name);
                                                                                        (yyvsp[-7].nd_obj).nd = mknode((yyvsp[-8].nd_obj2).nd, (yyvsp[-6].nd_obj2).nd, "LSQBRACKET");
                                                                                        (yyvsp[-5].nd_obj).nd = mknode((yyvsp[-7].nd_obj).nd, (yyvsp[-4].nd_obj).nd, "RSQBRACKET");
                                                                                        (yyvsp[0].nd_obj3).nd = mknode((yyvsp[-5].nd_obj).nd, NULL, "ASSIGNMENT");
                                                                                        (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "assignment_statement");
                                                                                    }
#line 3736 "y.tab.c"
    break;

  case 139: /* assignment_statement_2: ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET NUMBER RSQBRACKET ASSIGNMENT expression_statement  */
#line 1604 "parser.y"
                                                                                                               {
                                                                                                                    printf("Testing Here 6\n");
                                                                                                                    if(check_declaration((yyvsp[-8].nd_obj2).name) == 0 || isArray((yyvsp[-8].nd_obj2).name) == 0)
                                                                                                                    {
                                                                                                                        printf("Error: Variable %s is not an array at line %d\n", (yyvsp[-8].nd_obj2).name, yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    printf("Types of %s is %s\n", get_type((yyvsp[-8].nd_obj2).name), (yyvsp[0].nd_obj3).type);
                                                                                                                    if(strcmp(get_type((yyvsp[-8].nd_obj2).name), (yyvsp[0].nd_obj3).type) != 0)
                                                                                                                    {
                                                                                                                        printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    (yyvsp[-8].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-8].nd_obj2).name);
                                                                                                                    (yyvsp[-7].nd_obj).nd = mknode((yyvsp[-8].nd_obj2).nd, (yyvsp[-6].nd_obj).nd, "LSQBRACKET");
                                                                                                                    (yyvsp[-5].nd_obj).nd = mknode((yyvsp[-7].nd_obj).nd, (yyvsp[-4].nd_obj).nd, "RSQBRACKET");
                                                                                                                    (yyvsp[0].nd_obj3).nd = mknode((yyvsp[-5].nd_obj).nd, NULL, "ASSIGNMENT");
                                                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "assignment_statement");
                                                                                                                }
#line 3760 "y.tab.c"
    break;

  case 140: /* assignment_statement_2: ID LSQBRACKET NUMBER RSQBRACKET LSQBRACKET ID RSQBRACKET ASSIGNMENT expression_statement  */
#line 1623 "parser.y"
                                                                                                           {
                                                                                                                    printf("Testing Here 7\n");
                                                                                                                    if(check_declaration((yyvsp[-8].nd_obj2).name) == 0 || isArray((yyvsp[-8].nd_obj2).name) == 0)
                                                                                                                    {
                                                                                                                        printf("Error: Variable %s is not an array at line %d\n", (yyvsp[-8].nd_obj2).name, yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    if(check_declaration((yyvsp[-6].nd_obj).name) == 0 || isArray((yyvsp[-6].nd_obj).name) == 1)
                                                                                                                    {
                                                                                                                        printf("Error: Variable %s not declared at line %d\n", (yyvsp[-6].nd_obj).name, yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    printf("Types of %s is %s\n", get_type((yyvsp[-8].nd_obj2).name), (yyvsp[0].nd_obj3).type);
                                                                                                                    if(strcmp(get_type((yyvsp[-8].nd_obj2).name), (yyvsp[0].nd_obj3).type) != 0)
                                                                                                                    {
                                                                                                                        printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    (yyvsp[-8].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-8].nd_obj2).name);
                                                                                                                    (yyvsp[-7].nd_obj).nd = mknode((yyvsp[-8].nd_obj2).nd, (yyvsp[-6].nd_obj).nd, "LSQBRACKET");
                                                                                                                    (yyvsp[-5].nd_obj).nd = mknode((yyvsp[-7].nd_obj).nd, (yyvsp[-4].nd_obj).nd, "RSQBRACKET");
                                                                                                                    (yyvsp[0].nd_obj3).nd = mknode((yyvsp[-5].nd_obj).nd, NULL, "ASSIGNMENT");
                                                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "assignment_statement");
                                                                                                                }
#line 3789 "y.tab.c"
    break;

  case 141: /* $@16: %empty  */
#line 1650 "parser.y"
                            {   
                                printf("Variable %s declared at line %d\n", (yyvsp[0].nd_obj2).name, yylineno);
                                if(check_declaration((yyvsp[0].nd_obj2).name) == 1)
                                {
                                    printf("Error: Variable %s not declared at line %d\n", (yyvsp[0].nd_obj2).name, yylineno);
                                    exit(1);
                                }
                                yytext = malloc(sizeof(char)*strlen((yyvsp[0].nd_obj2).name));
                                strcpy(yytext,(yyvsp[0].nd_obj2).name);
                                add('V');
                                printf("Added\n");
                            }
#line 3806 "y.tab.c"
    break;

  case 142: /* for_initializer: type_specifier ID $@16 ASSIGNMENT expression_statement SEMICOLON  */
#line 1662 "parser.y"
                                                                        {
                                                                            (yyvsp[-5].nd_obj).value=(yyvsp[-1].nd_obj3).value;
                                                                            (yyvsp[-2].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ; 
                                                                            struct node *temp = mknode((yyvsp[-5].nd_obj).nd, (yyvsp[-4].nd_obj2).nd, "for_initializer");
                                                                            (yyval.nd_obj).nd = mknode(temp, (yyvsp[-2].nd_obj).nd, "for_initializer_structure");

                                                                            sprintf(icg[ic_idx++], "%s = t%d\n", (yyvsp[-4].nd_obj2).name, (yyvsp[-1].nd_obj3).t);
                                                                        }
#line 3819 "y.tab.c"
    break;

  case 143: /* for_initializer: assignment_statement_2 SEMICOLON  */
#line 1670 "parser.y"
                                                {
                                                    (yyvsp[0].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ;
                                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "for_initializer");
                                                }
#line 3828 "y.tab.c"
    break;

  case 144: /* for_initializer: SEMICOLON  */
#line 1674 "parser.y"
                        {
                            (yyvsp[0].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ;
                            (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "for_initializer");
                        }
#line 3837 "y.tab.c"
    break;

  case 145: /* for_condition: expression_statement SEMICOLON  */
#line 1681 "parser.y"
                                        {
                                            (yyvsp[0].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ;
                                            (yyval.nd_obj3).nd = mknode((yyvsp[-1].nd_obj3).nd, (yyvsp[0].nd_obj).nd, "for_condition");

                                            //here checker
                                            // $$.if_body = $1.if_body;
                                            // $$.else_body = $1.else_body;
                                        }
#line 3850 "y.tab.c"
    break;

  case 146: /* for_condition: SEMICOLON  */
#line 1689 "parser.y"
                        {
                            (yyvsp[0].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ;
                            (yyval.nd_obj3).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "for_condition");
                        }
#line 3859 "y.tab.c"
    break;

  case 147: /* for_update: assignment_statement_2  */
#line 1696 "parser.y"
                                {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "for_update"); /*for_up = 1;*/ }
#line 3865 "y.tab.c"
    break;

  case 148: /* for_update: %empty  */
#line 1697 "parser.y"
          { (yyval.nd_obj).nd = mknode(NULL, NULL, "for_update"); }
#line 3871 "y.tab.c"
    break;

  case 149: /* $@17: %empty  */
#line 1701 "parser.y"
                                                 {
            nextTable();
        }
#line 3879 "y.tab.c"
    break;

  case 150: /* while_statement: WHILE LPAREN expression_statement RPAREN $@17 LBRACE loop_stat_list RBRACE  */
#line 1703 "parser.y"
                                          {     prevTable();
                                                (yyval.nd_obj).nd = mknode((yyvsp[-5].nd_obj3).nd, (yyvsp[-1].nd_obj).nd, "while_statement");    
                                        }
#line 3887 "y.tab.c"
    break;

  case 151: /* loop_stat_list: statement  */
#line 1709 "parser.y"
                    {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "loop_stat_list");  }
#line 3893 "y.tab.c"
    break;

  case 152: /* loop_stat_list: statement loop_stat_list  */
#line 1710 "parser.y"
                                        {  printf("222\n"); (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "loop_stat_list");   }
#line 3899 "y.tab.c"
    break;

  case 153: /* loop_stat_list: BREAK SEMICOLON  */
#line 1711 "parser.y"
                            {   
                                (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, "BREAK");
                                (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, "SEMICOLON");
                                (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "loop_stat_list");
                            }
#line 3909 "y.tab.c"
    break;

  case 154: /* loop_stat_list: BREAK SEMICOLON loop_stat_list  */
#line 1716 "parser.y"
                                            {   
                                                (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, "BREAK");
                                                (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, "SEMICOLON");
                                                struct node* temp = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "break_stat");
                                                (yyval.nd_obj).nd = mknode(temp, (yyvsp[0].nd_obj).nd, "loop_stat_list");
                                            }
#line 3920 "y.tab.c"
    break;

  case 155: /* loop_stat_list: CONTINUE SEMICOLON  */
#line 1722 "parser.y"
                                {   
                                    (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, "CONTINUE");
                                    (yyvsp[0].nd_obj).nd = mknode(NULL, NULL, "SEMICOLON");
                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "loop_stat_list");
                                }
#line 3930 "y.tab.c"
    break;

  case 156: /* loop_stat_list: CONTINUE SEMICOLON loop_stat_list  */
#line 1727 "parser.y"
                                                {   
                                                    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, "CONTINUE");
                                                    (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, "SEMICOLON");
                                                    struct node* temp = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "continue_stat");
                                                    (yyval.nd_obj).nd = mknode(temp, (yyvsp[0].nd_obj).nd, "loop_stat_list");
                                                }
#line 3941 "y.tab.c"
    break;

  case 157: /* loop_stat_list: %empty  */
#line 1733 "parser.y"
          {(yyval.nd_obj).nd = mknode(NULL, NULL, "loop_stat_list");}
#line 3947 "y.tab.c"
    break;

  case 158: /* $@18: %empty  */
#line 1738 "parser.y"
                                                  {
            nextTable();
        }
#line 3955 "y.tab.c"
    break;

  case 159: /* switch_statement: SWITCH LPAREN expression_statement RPAREN $@18 LBRACE switch_case_list RBRACE  */
#line 1740 "parser.y"
                                         {   
            (yyval.nd_obj).nd = mknode((yyvsp[-5].nd_obj3).nd, (yyvsp[-2].nd_obj).nd, "switch_statement");   
            prevTable();
        }
#line 3964 "y.tab.c"
    break;

  case 160: /* switch_case_list: switch_case  */
#line 1747 "parser.y"
                    {   (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "switch_case_list");    }
#line 3970 "y.tab.c"
    break;

  case 161: /* switch_case_list: switch_case switch_case_list  */
#line 1748 "parser.y"
                                            {   (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "switch_case_list");   }
#line 3976 "y.tab.c"
    break;

  case 162: /* switch_case: CASE constant COLON loop_stat_list  */
#line 1752 "parser.y"
                                            {
                                                struct node* temp1 = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-2].nd_obj3).nd, "Case");
                                                struct node* temp2 = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "Statement_List");
                                                (yyval.nd_obj).nd = mknode(temp1, temp2, "switch_case");
                                            }
#line 3986 "y.tab.c"
    break;

  case 163: /* switch_case: DEFAULT COLON loop_stat_list  */
#line 1757 "parser.y"
                                            {
                                                struct node* temp1 = mknode((yyvsp[-2].nd_obj).nd, NULL, "Default");
                                                struct node* temp2 = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "Statement_List");
                                                (yyval.nd_obj).nd = mknode(temp1, temp2, "switch_case");
                                            }
#line 3996 "y.tab.c"
    break;

  case 164: /* print: PRINTF LPAREN stringconst plist RPAREN SEMICOLON  */
#line 1764 "parser.y"
                                                            { 
            if(currentPrintfArgumentIndex<FormatSpecifierListIndex){
                printf("Error: Too few arguments for printf\n");
                exit(1);
            } 
            currentPrintfArgumentIndex=0;
            clearFormatSpecifierList();
            (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj_arr).nd, NULL, "print");    
        }
#line 4010 "y.tab.c"
    break;

  case 165: /* stringconst: STR  */
#line 1775 "parser.y"
                 {
    countOfFormatSpecifiers((yyvsp[0].nd_obj).name);
    (yyval.nd_obj_arr).nd = mknode(NULL, NULL, "STR");
    printf("\nString is 1 %s\n", (yyvsp[0].nd_obj).name);
    (yyval.nd_obj_arr).sz = strlen((yyvsp[0].nd_obj).name)-2;
    printf("$$ size is %d\n", (yyval.nd_obj_arr).sz);
}
#line 4022 "y.tab.c"
    break;

  case 166: /* plist: COMMA ID  */
#line 1784 "parser.y"
                {   

                    printf("Type of constant is %s\n", (yyvsp[0].nd_obj2).type);
                    if(check_declaration((yyvsp[0].nd_obj2).name)==0 && isArray((yyvsp[-1].nd_obj).name)==0){
                        printf("Error: Undeclared variable %s\n", (yyvsp[0].nd_obj2).name);
                        exit(1);
                    }
                    if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                        printf("Error: Too many arguments for printf\n");
                        exit(1);
                    }
                    if(strcmp(get_type((yyvsp[0].nd_obj2).name),"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                        exit(1);
                    }
                    else if(strcmp(get_type((yyvsp[0].nd_obj2).name),"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                        exit(1);
                    }
                    else if(strcmp(get_type((yyvsp[0].nd_obj2).name),"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                        exit(1);
                    }
                    (yyvsp[0].nd_obj2).to_print = 1;
                    currentPrintfArgumentIndex++;
                    printf("currentPrintfArgumentIndex is %d\n", currentPrintfArgumentIndex);
                    printf("FormatSpecifierListIndex is %d\n", FormatSpecifierListIndex);
                    // if(currentPrintfArgumentIndex<FormatSpecifierListIndex){
                    //     printf("Error: Too few arguments for printf\n");
                    //     exit(1);
                    // }
                    (yyvsp[0].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj2).name);
                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj2).nd, (yyval.nd_obj).nd, "plist");
}
#line 4061 "y.tab.c"
    break;

  case 167: /* plist: COMMA ID plist  */
#line 1818 "parser.y"
                     {

                        if(check_declaration((yyvsp[-1].nd_obj2).name)==0 && isArray((yyvsp[-2].nd_obj).name)==0){
                            printf("Error: Undeclared variable %s\n", (yyvsp[-1].nd_obj2).name);
                            exit(1);
                        }
                        if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                            printf("Error: Too many arguments for printf\n");
                            exit(1);
                        }
                        if(strcmp(get_type((yyvsp[-1].nd_obj2).name),"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        else if(strcmp(get_type((yyvsp[-1].nd_obj2).name),"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        else if(strcmp(get_type((yyvsp[-1].nd_obj2).name),"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        (yyvsp[-1].nd_obj2).to_print = 1;
                        currentPrintfArgumentIndex++;
                        (yyvsp[-1].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj2).name);
                        struct node* temp = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj2).nd, "ID");
                        (yyval.nd_obj).nd = mknode(temp, (yyvsp[0].nd_obj).nd, "plist");
    }
#line 4094 "y.tab.c"
    break;

  case 168: /* plist: COMMA ID LSQBRACKET NUMBER RSQBRACKET  */
#line 1846 "parser.y"
                                           {
                                        if(check_declaration((yyvsp[-3].nd_obj2).name)==0 && isArray((yyvsp[-3].nd_obj2).name)==1){
                                            printf("Error: Undeclared variable %s\n", (yyvsp[-4].nd_obj).name);
                                            exit(1);
                                        }
                                        if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                                            printf("Error: Too many arguments for printf\n");
                                            exit(1);
                                        }
                                        if(strcmp(get_type((yyvsp[-3].nd_obj2).name),"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                                            printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                            exit(1);
                                        }
                                        else if(strcmp(get_type((yyvsp[-3].nd_obj2).name),"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                                            printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                            exit(1);
                                        }
                                        else if(strcmp(get_type((yyvsp[-3].nd_obj2).name),"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                                            printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                            exit(1);
                                        }
                                        (yyvsp[-3].nd_obj2).to_print = 1;
                                        currentPrintfArgumentIndex++;
                                        (yyvsp[-3].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj2).name);
                                        (yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj).nd, NULL, "plist");
                                    }
#line 4125 "y.tab.c"
    break;

  case 169: /* plist: COMMA ID LSQBRACKET NUMBER RSQBRACKET plist  */
#line 1872 "parser.y"
                                                  {
                                                if(check_declaration((yyvsp[-4].nd_obj2).name)==0 && isArray((yyvsp[-4].nd_obj2).name)==1){
                                                    printf("Error: Undeclared variable %s\n", (yyvsp[-4].nd_obj2).name);
                                                    exit(1);
                                                }
                                                if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                                                    printf("Error: Too many arguments for printf\n");
                                                    exit(1);
                                                }
                                                if(strcmp(get_type((yyvsp[-4].nd_obj2).name),"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                                                    printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                                    exit(1);
                                                }
                                                else if(strcmp(get_type((yyvsp[-4].nd_obj2).name),"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                                                    printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                                    exit(1);
                                                }
                                                else if(strcmp(get_type((yyvsp[-5].nd_obj).name),"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                                                    printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                                    exit(1);
                                                }
                                                (yyvsp[-4].nd_obj2).to_print = 1;
                                                currentPrintfArgumentIndex++;
                                                (yyvsp[-4].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[-4].nd_obj2).name);
                                                (yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj2).nd, (yyvsp[0].nd_obj).nd, "plist");
                                            }
#line 4156 "y.tab.c"
    break;

  case 170: /* plist: COMMA constant  */
#line 1898 "parser.y"
                     {
                    printf("Type of constant is %s\n", (yyvsp[0].nd_obj3).type);
                    if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                        printf("Error: Too many arguments for printf\n");
                        exit(1);
                    }
                    if(strcmp((yyvsp[0].nd_obj3).type,"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                        printf("Error: Format specifier mismatch for argument %d\n",currentPrintfArgumentIndex+1);
                        exit(1);
                    }
                    else if(strcmp((yyvsp[0].nd_obj3).type,"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                        printf("Error: Format specifier mismatch for argument %d\n",currentPrintfArgumentIndex+1);
                        exit(1);
                    }
                    else if(strcmp((yyvsp[0].nd_obj3).type,"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                        printf("Error: Format specifier mismatch for argument %d\n",currentPrintfArgumentIndex+1);
                        exit(1);
                    }
                    (yyvsp[0].nd_obj3).to_print = 1;
                    currentPrintfArgumentIndex++;
                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj3).nd, NULL, "plist");
                }
#line 4183 "y.tab.c"
    break;

  case 171: /* plist: COMMA constant plist  */
#line 1920 "parser.y"
                          {
                        printf("Type of constant is %s\n", (yyvsp[-1].nd_obj3).type);
                        printf("currentPrintfArgumentIndex is %d\n", currentPrintfArgumentIndex);
                        printf("FormatSpecifierListIndex is %d\n", FormatSpecifierListIndex);
                        if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                            printf("Error: Too many arguments for printf\n");
                            exit(1);
                        }
                        if(strcmp((yyvsp[-1].nd_obj3).type,"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        else if(strcmp((yyvsp[-1].nd_obj3).type,"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        else if(strcmp((yyvsp[-1].nd_obj3).type,"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        (yyvsp[-1].nd_obj3).to_print = 1;
                        currentPrintfArgumentIndex++;
                        printf("currentPrintfArgumentIndex is %d\n", currentPrintfArgumentIndex);
                        printf("FormatSpecifierListIndex is %d\n", FormatSpecifierListIndex);
                        (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj3).nd, (yyvsp[0].nd_obj).nd, "plist");
                    }
#line 4214 "y.tab.c"
    break;

  case 172: /* plist: %empty  */
#line 1946 "parser.y"
     {
        (yyval.nd_obj).nd = mknode(NULL, NULL, "plist");
    }
#line 4222 "y.tab.c"
    break;

  case 173: /* return_statement: RETURN expression_statement SEMICOLON  */
#line 1952 "parser.y"
                                                {
                                                    check_declaration(currentFunction);
                                                    // printf("Current function is %s\n",currentFunction);
                                                    if(strcmp(get_type(currentFunction),(yyvsp[-1].nd_obj3).type)!=0){
                                                        printf("Error: Return type mismatch for function %s\n",currentFunction);
                                                        exit(1);
                                                    }
                                                    (yyvsp[0].nd_obj).nd = mknode(NULL,NULL,"SEMICOLON");
                                                    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, "RETURN");
                                                    struct node *temp = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj3).nd, "return_statement");
                                                    (yyval.nd_obj).nd = mknode(temp, (yyvsp[0].nd_obj).nd, "return_statement_structure");
                                                }
#line 4239 "y.tab.c"
    break;

  case 174: /* return_statement: RETURN SEMICOLON  */
#line 1964 "parser.y"
                               {
                                    check_declaration(currentFunction);
                                    if(strcmp(get_type(currentFunction),"void")!=0){
                                        printf("Error: Return type mismatch for function %s\n",currentFunction);
                                        exit(1);
                                    }
                                    (yyvsp[0].nd_obj).nd = mknode(NULL,NULL,"SEMICOLON");
                                    (yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, "RETURN");
                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "return_statement_structure");
                                }
#line 4254 "y.tab.c"
    break;

  case 175: /* $@19: %empty  */
#line 1977 "parser.y"
        {                                            
            nextTable();
        }
#line 4262 "y.tab.c"
    break;

  case 176: /* compound_statement: $@19 LBRACE statement_list RBRACE  */
#line 1979 "parser.y"
                                          {   
                                            (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "compound_statement");
                                            prevTable();
                                        }
#line 4271 "y.tab.c"
    break;


#line 4275 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1984 "parser.y"

 
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
    printf("\t\t\t\t\t\t\t   PHASE 5: OUTPUT GENERATION \n\n");
    propogateValue(head);
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

void propogateValue(struct node * head){
    if(head==NULL){
        return;
    }
    if(head->to_print==1){
        if(head->left!=NULL && head->left->to_print==1){
            propogateValue(head->left);
        }
        if(head->right!=NULL && head->right->to_print==1){
            propogateValue(head->right);
        }
        if(head->left!=NULL && head->left->to_print==0){
            propogateValue(head->left);
        }
        if(head->right!=NULL && head->right->to_print==0){
            if(head->right->token==NULL){
                head->right->token=malloc(sizeof(char)*100);
            }
            strcpy(head->right->token,head->token);
            head->right->to_print=1;
            propogateValue(head->right);
        }
    }
    else{
        if(head->left!=NULL && head->left->to_print==1){
            propogateValue(head->left);
        }
        if(head->right!=NULL && head->right->to_print==1){
            propogateValue(head->right);
        }
    }
    if(head->left!=NULL && head->left->to_print==1){
        propogateValue(head->left);
    }
    if(head->right!=NULL && head->right->to_print==1){
        propogateValue(head->right);
    }
    getOutput();
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

void getOutput(){
    system("mkdir .folder");
    system("gcc -o .folder/a.out input.c &> .folder/temp.txt");
    system(".folder/a.out");
    system("rm -rf .folder");
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
