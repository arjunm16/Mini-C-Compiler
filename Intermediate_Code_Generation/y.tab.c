
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
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
 


/* Line 189 of yacc.c  */
#line 290 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VOID = 258,
     INT = 259,
     FLOAT = 260,
     CHAR = 261,
     IF = 262,
     ELSE = 263,
     FOR = 264,
     WHILE = 265,
     SWITCH = 266,
     CASE = 267,
     DEFAULT = 268,
     PRINTF = 269,
     SCANF = 270,
     RETURN = 271,
     TRUE = 272,
     FALSE = 273,
     INCLUDE = 274,
     STR = 275,
     STRCONST = 276,
     FLOAT_NUM = 277,
     EXPONENT = 278,
     MAIN = 279,
     ID = 280,
     BREAK = 281,
     CONTINUE = 282,
     NUMBER = 283,
     CHARACTER = 284,
     ASSIGNMENT = 285,
     NOT = 286,
     AND = 287,
     OR = 288,
     EQ = 289,
     NE = 290,
     LT = 291,
     LE = 292,
     GT = 293,
     GE = 294,
     ADD = 295,
     SUB = 296,
     MUL = 297,
     DIV = 298,
     MOD = 299,
     LSQBRACKET = 300,
     RSQBRACKET = 301,
     LPAREN = 302,
     RPAREN = 303,
     LBRACE = 304,
     RBRACE = 305,
     SEMICOLON = 306,
     COMMA = 307,
     COLON = 308
   };
#endif
/* Tokens.  */
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 217 "parser.y"
 struct var_name { 
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
    


/* Line 214 of yacc.c  */
#line 470 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 482 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

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
/* YYNRULES -- Number of states.  */
#define YYNSTATES  334

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    20,    21,    22,    35,    38,    39,    44,    45,    46,
      52,    56,    57,    64,    66,    69,    70,    72,    75,    78,
      80,    82,    84,    86,    88,    90,    92,    94,    96,    97,
     102,   104,   105,   110,   114,   116,   118,   120,   122,   123,
     128,   130,   134,   136,   140,   145,   153,   161,   167,   175,
     184,   193,   200,   209,   217,   227,   237,   249,   259,   268,
     277,   288,   297,   301,   305,   309,   313,   317,   321,   325,
     331,   335,   341,   345,   351,   353,   357,   359,   363,   367,
     369,   371,   375,   376,   381,   385,   387,   391,   393,   397,
     401,   403,   407,   411,   415,   419,   421,   425,   429,   431,
     435,   439,   443,   445,   448,   450,   455,   457,   461,   462,
     468,   472,   474,   476,   478,   480,   482,   484,   485,   486,
     487,   497,   500,   501,   502,   513,   517,   524,   534,   544,
     554,   564,   565,   572,   575,   577,   580,   582,   584,   585,
     586,   595,   597,   600,   603,   607,   610,   614,   615,   616,
     625,   627,   630,   635,   639,   646,   648,   651,   655,   661,
     668,   671,   675,   676,   680,   683,   684
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    57,    -1,     4,    -1,     5,    -1,     6,
      -1,     3,    -1,    58,    -1,    59,    -1,    67,    -1,    -1,
      -1,    -1,    56,    25,    60,    47,    61,    63,    48,    49,
      69,    50,    62,    58,    -1,    75,    25,    -1,    -1,    75,
      25,    64,    65,    -1,    -1,    -1,    52,    75,    25,    66,
      65,    -1,    52,    75,    25,    -1,    -1,    56,    24,    68,
      47,    48,   125,    -1,    70,    -1,    70,    69,    -1,    -1,
      74,    -1,   109,    51,    -1,    91,    51,    -1,   102,    -1,
     107,    -1,   114,    -1,   117,    -1,   124,    -1,   125,    -1,
     121,    -1,    51,    -1,    25,    -1,    -1,    25,    72,    52,
      71,    -1,   101,    -1,    -1,   101,    73,    52,    71,    -1,
      75,    76,    51,    -1,     4,    -1,     5,    -1,     6,    -1,
      25,    -1,    -1,    25,    77,    52,    76,    -1,    89,    -1,
      89,    52,    76,    -1,    78,    -1,    78,    52,    76,    -1,
      25,    45,    28,    46,    -1,    25,    45,    46,    30,    49,
      85,    50,    -1,    25,    45,    46,    30,    49,    86,    50,
      -1,    25,    45,    46,    30,   122,    -1,    25,    45,    46,
      30,    49,    88,    50,    -1,    25,    45,    28,    46,    30,
      49,    85,    50,    -1,    25,    45,    28,    46,    30,    49,
      86,    50,    -1,    25,    45,    28,    46,    30,   122,    -1,
      25,    45,    28,    46,    30,    49,    88,    50,    -1,    25,
      45,    28,    46,    45,    28,    46,    -1,    25,    45,    28,
      46,    45,    28,    46,    30,    79,    -1,    25,    45,    28,
      46,    45,    28,    46,    30,    80,    -1,    25,    45,    28,
      46,    45,    28,    46,    30,    49,    87,    50,    -1,    25,
      45,    28,    46,    45,    28,    46,    30,    81,    -1,    25,
      45,    46,    45,    28,    46,    30,    79,    -1,    25,    45,
      46,    45,    28,    46,    30,    80,    -1,    25,    45,    46,
      45,    28,    46,    30,    49,    87,    50,    -1,    25,    45,
      46,    45,    28,    46,    30,    81,    -1,    49,    85,    50,
      -1,    49,    82,    50,    -1,    49,    86,    50,    -1,    49,
      83,    50,    -1,    49,    88,    50,    -1,    49,    84,    50,
      -1,    49,    85,    50,    -1,    49,    85,    50,    52,    82,
      -1,    49,    86,    50,    -1,    49,    86,    50,    52,    83,
      -1,    49,    88,    50,    -1,    49,    88,    50,    52,    84,
      -1,    28,    -1,    28,    52,    85,    -1,    29,    -1,    29,
      52,    86,    -1,   122,    52,    87,    -1,   122,    -1,    22,
      -1,    22,    52,    88,    -1,    -1,    25,    90,    30,    91,
      -1,    91,    33,    92,    -1,    92,    -1,    92,    32,    93,
      -1,    93,    -1,    93,    34,    94,    -1,    93,    35,    94,
      -1,    94,    -1,    94,    38,    95,    -1,    94,    39,    95,
      -1,    94,    36,    95,    -1,    94,    37,    95,    -1,    95,
      -1,    95,    40,    96,    -1,    95,    41,    96,    -1,    96,
      -1,    96,    42,    97,    -1,    96,    43,    97,    -1,    96,
      44,    97,    -1,    97,    -1,    31,    98,    -1,    98,    -1,
      98,    45,    28,    46,    -1,   100,    -1,    98,    47,    48,
      -1,    -1,    98,    47,    99,    71,    48,    -1,    47,    91,
      48,    -1,    25,    -1,   101,    -1,    28,    -1,    29,    -1,
      22,    -1,    23,    -1,    -1,    -1,    -1,     7,    47,   103,
      91,    48,   104,   125,   105,   106,    -1,     8,   125,    -1,
      -1,    -1,     9,    47,   108,   110,   112,   113,    48,    49,
     116,    50,    -1,    25,    30,    91,    -1,    25,    45,    28,
      46,    30,    91,    -1,    25,    45,    25,    46,    45,    28,
      46,    30,    91,    -1,    25,    45,    25,    46,    45,    25,
      46,    30,    91,    -1,    25,    45,    28,    46,    45,    28,
      46,    30,    91,    -1,    25,    45,    28,    46,    45,    25,
      46,    30,    91,    -1,    -1,    75,    25,   111,    30,    91,
      51,    -1,   109,    51,    -1,    51,    -1,    91,    51,    -1,
      51,    -1,   109,    -1,    -1,    -1,    10,    47,    91,    48,
     115,    49,   116,    50,    -1,    70,    -1,    70,   116,    -1,
      26,    51,    -1,    26,    51,   116,    -1,    27,    51,    -1,
      27,    51,   116,    -1,    -1,    -1,    11,    47,    91,    48,
     118,    49,   119,    50,    -1,   120,    -1,   120,   119,    -1,
      12,   101,    53,   116,    -1,    13,    53,   116,    -1,    14,
      47,   122,   123,    48,    51,    -1,    20,    -1,    52,    25,
      -1,    52,    25,   123,    -1,    52,    25,    45,    28,    46,
      -1,    52,    25,    45,    28,    46,   123,    -1,    52,   101,
      -1,    52,   101,   123,    -1,    -1,    16,    91,    51,    -1,
      16,    51,    -1,    -1,   126,    49,    69,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   274,   274,   280,   281,   282,   283,   287,   290,   291,
     294,   297,   300,   294,   311,   320,   320,   329,   333,   333,
     343,   354,   354,   364,   365,   366,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   381,   389,   401,   401,
     409,   416,   416,   422,   429,   430,   431,   435,   444,   444,
     457,   458,   463,   464,   471,   481,   488,   495,   503,   510,
     528,   546,   561,   579,   589,   613,   637,   661,   685,   704,
     723,   742,   764,   770,   779,   785,   794,   800,   809,   815,
     824,   830,   839,   845,   854,   859,   867,   872,   879,   886,
     896,   901,   910,   910,   930,   951,   960,   981,   990,  1011,
    1032,  1041,  1066,  1091,  1116,  1141,  1150,  1168,  1186,  1195,
    1213,  1231,  1249,  1258,  1281,  1290,  1315,  1321,  1335,  1335,
    1351,  1357,  1370,  1380,  1387,  1394,  1401,  1411,  1411,  1411,
    1411,  1420,  1424,  1429,  1429,  1447,  1483,  1520,  1539,  1563,
    1582,  1609,  1609,  1628,  1632,  1639,  1647,  1654,  1655,  1659,
    1659,  1667,  1668,  1669,  1674,  1680,  1685,  1691,  1696,  1696,
    1705,  1706,  1710,  1715,  1722,  1733,  1742,  1773,  1799,  1824,
    1849,  1869,  1893,  1899,  1911,  1924,  1924
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "FLOAT", "CHAR", "IF",
  "ELSE", "FOR", "WHILE", "SWITCH", "CASE", "DEFAULT", "PRINTF", "SCANF",
  "RETURN", "TRUE", "FALSE", "INCLUDE", "STR", "STRCONST", "FLOAT_NUM",
  "EXPONENT", "MAIN", "ID", "BREAK", "CONTINUE", "NUMBER", "CHARACTER",
  "ASSIGNMENT", "NOT", "AND", "OR", "EQ", "NE", "LT", "LE", "GT", "GE",
  "ADD", "SUB", "MUL", "DIV", "MOD", "LSQBRACKET", "RSQBRACKET", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "SEMICOLON", "COMMA", "COLON", "$accept",
  "program", "datatype", "program_body", "functions", "function", "$@1",
  "$@2", "$@3", "arglist", "$@4", "args", "$@5", "main", "$@6",
  "statement_list", "statement", "calling_list", "$@7", "$@8",
  "declaration_statement", "type_specifier", "var_list", "$@9", "arr_dec",
  "multiple_num_list", "multiple_character_list",
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
  "stringconst", "plist", "return_statement", "compound_statement", "$@19", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
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

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -273
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

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -176
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
static const yytype_uint8 yystos[] =
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

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 274 "parser.y"
    { 
                            (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "program"); 
                            head = (yyval.nd_obj).nd;
                        }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    {   insert_type();  }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 281 "parser.y"
    {   insert_type();  }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 282 "parser.y"
    {   insert_type();  }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 283 "parser.y"
    {   insert_type();  }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 287 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "program_body"); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 290 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "function");    }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 291 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "function");    }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 294 "parser.y"
    {   strcpy(yytext, (yyvsp[(2) - (2)].nd_obj2).name); 
                        add('F'); 
                        strcpy(currentFunction, (yyvsp[(2) - (2)].nd_obj2).name);
         }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 297 "parser.y"
    { 
            nextTable();
        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 300 "parser.y"
    {
            prevTable();
        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 303 "parser.y"
    { 
                                                                (yyvsp[(1) - (12)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (12)].nd_obj).name);
                                                                (yyvsp[(2) - (12)].nd_obj2).nd = mknode((yyvsp[(6) - (12)].nd_obj).nd, (yyvsp[(9) - (12)].nd_obj).nd, (yyvsp[(2) - (12)].nd_obj2).name);
                                                                struct node *temp = mknode((yyvsp[(1) - (12)].nd_obj).nd, (yyvsp[(2) - (12)].nd_obj2).nd, "function_body");
                                                                (yyval.nd_obj).nd = mknode(temp, (yyvsp[(12) - (12)].nd_obj).nd, "function");
                                                            }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 311 "parser.y"
    {
                                    (yyvsp[(2) - (2)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(2) - (2)].nd_obj2).name);
                                    yytext = malloc(sizeof(char) * strlen((yyvsp[(2) - (2)].nd_obj2).name));
                                    strcpy(yytext, (yyvsp[(2) - (2)].nd_obj2).name);
                                    add('V');
                                    printf("Adding argument %s to function %s of type %s\n", (yyvsp[(2) - (2)].nd_obj2).name,currentFunction,type);
                                    addArgument((yyvsp[(2) - (2)].nd_obj2).name,type); 
                                    (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd,(yyvsp[(2) - (2)].nd_obj2).nd, "Argument");
                                }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    {   (yyvsp[(2) - (2)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(2) - (2)].nd_obj2).name);
                                    yytext = malloc(sizeof(char) * strlen((yyvsp[(2) - (2)].nd_obj2).name));
                                    strcpy(yytext, (yyvsp[(2) - (2)].nd_obj2).name);
                                    add('V');
                                    addArgument((yyvsp[(2) - (2)].nd_obj2).name,type);
                                }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    {
                                                struct node *temp = mknode((yyvsp[(1) - (4)].nd_obj).nd, (yyvsp[(2) - (4)].nd_obj2).nd, "Argument");
                                                (yyval.nd_obj).nd = mknode(temp, (yyvsp[(4) - (4)].nd_obj).nd, "arglist");
                                            }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    {   (yyval.nd_obj).nd = mknode(NULL, NULL, "arglist");  }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 333 "parser.y"
    {
                                        (yyvsp[(3) - (3)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(3) - (3)].nd_obj2).name);
                                        yytext = malloc(sizeof(char) * strlen((yyvsp[(3) - (3)].nd_obj2).name));
                                        strcpy(yytext, (yyvsp[(3) - (3)].nd_obj2).name);
                                        add('V');
                                        addArgument((yyvsp[(3) - (3)].nd_obj2).name,type);
                                    }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 339 "parser.y"
    {
                                                    struct node *temp = mknode((yyvsp[(2) - (5)].nd_obj).nd, (yyvsp[(3) - (5)].nd_obj2).nd, "Argument");
                                                    (yyval.nd_obj).nd = mknode(temp, (yyvsp[(5) - (5)].nd_obj).nd, "args");
                                                }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 343 "parser.y"
    {
                                        (yyvsp[(3) - (3)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(3) - (3)].nd_obj2).name);
                                        yytext = malloc(sizeof(char) * strlen((yyvsp[(3) - (3)].nd_obj2).name));
                                        strcpy(yytext, (yyvsp[(3) - (3)].nd_obj2).name);
                                        add('V');
                                        addArgument((yyvsp[(3) - (3)].nd_obj2).name,type);
                                        (yyval.nd_obj).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj2).nd, "Argument");
                                    }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 354 "parser.y"
    {   add('F');  
                          strcpy(currentFunction, "main");
         }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 356 "parser.y"
    {
                                                                                        (yyvsp[(1) - (6)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (6)].nd_obj).name);
                                                                                        struct node *temp = mknode((yyvsp[(6) - (6)].nd_obj).nd, NULL, (yyvsp[(2) - (6)].nd_obj).name);
                                                                                        (yyval.nd_obj).nd = mknode((yyvsp[(1) - (6)].nd_obj).nd, temp, "Main_Structure");
                                                                                    }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 364 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "statement_list");}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 365 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "statement_list");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 366 "parser.y"
    {   (yyval.nd_obj).nd = mknode(NULL, NULL, "statement_list");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 370 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "statement");   }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 371 "parser.y"
    {   (yyvsp[(2) - (2)].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ; (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "statement");  }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 372 "parser.y"
    {   (yyvsp[(2) - (2)].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ; (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj3).nd, (yyvsp[(2) - (2)].nd_obj).nd, "statement");  }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 373 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "statement");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 374 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "statement");}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 375 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "statement");}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 376 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "statement");}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 377 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "statement");}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 378 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "statement");}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 379 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "statement");}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 381 "parser.y"
    {   
                                                    (yyvsp[(1) - (1)].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ;
                                                    (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "statement");
                                                }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 389 "parser.y"
    {   
                if(check_declaration((yyvsp[(1) - (1)].nd_obj2).name) == 0)
                {
                    printf("Error: Argument %s not declared at line %d\n", (yyvsp[(1) - (1)].nd_obj2).name, yylineno);
                    exit(1);
                }
                check_Argument((yyvsp[(1) - (1)].nd_obj2).name);
                printf("Name is %s\n", (yyvsp[(1) - (1)].nd_obj2).name);
                checkFinalArguments(currentFunction);
                (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj2).nd, NULL, "calling_list"); 
                currentArgumentIndex=0;
            }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 401 "parser.y"
    {
                if(check_declaration((yyvsp[(1) - (1)].nd_obj2).name) == 0)
                {
                    printf("Error: Argument %s not declared at line %d\n", (yyvsp[(1) - (1)].nd_obj2).name, yylineno);
                    exit(1);
                }
                check_Argument((yyvsp[(1) - (1)].nd_obj2).name);
        }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 408 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj2).nd, (yyvsp[(4) - (4)].nd_obj).nd, "calling_list"); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 409 "parser.y"
    {
                printf("Checking this\n");
                check_Argument((yyvsp[(1) - (1)].nd_obj3).type);
                checkFinalArguments(currentFunction);
                (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj3).nd, NULL, "calling_list"); 
                currentArgumentIndex=0;
        }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 416 "parser.y"
    {
                check_Argument((yyvsp[(1) - (1)].nd_obj3).type);
        }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 418 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj3).nd, (yyvsp[(4) - (4)].nd_obj).nd, "calling_list"); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 422 "parser.y"
    {
                                                (yyvsp[(3) - (3)].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ; 
                                                struct node *temp = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).nd, "declaration_statement");
                                                (yyval.nd_obj).nd = mknode(temp, (yyvsp[(3) - (3)].nd_obj).nd, "declaration_statement_structure");
                                            }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 429 "parser.y"
    {   insert_type(); (yyval.nd_obj).nd = mknode(NULL, NULL, "int");   }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 430 "parser.y"
    {   insert_type(); (yyval.nd_obj).nd = mknode(NULL, NULL, "float"); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 431 "parser.y"
    {   insert_type(); (yyval.nd_obj).nd = mknode(NULL, NULL, "char");  }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 435 "parser.y"
    { 
                                                    yytext = malloc(sizeof(char)*strlen((yyvsp[(1) - (1)].nd_obj2).name));
                                                    strcpy(yytext, (yyvsp[(1) - (1)].nd_obj2).name);
                                                    add('V');
                                                    (yyvsp[(1) - (1)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj2).name);
                                                    (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj2).nd, NULL, "var_list1");

                                                    sprintf(icg[ic_idx++], "%s = NULL\n", (yyvsp[(1) - (1)].nd_obj2).name);
                                                }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 444 "parser.y"
    {
                                                    yytext = malloc(sizeof(char)*strlen((yyvsp[(1) - (1)].nd_obj2).name));
                                                    strcpy(yytext, (yyvsp[(1) - (1)].nd_obj2).name);
                                                    add('V');
                                                    sprintf((yyvsp[(1) - (1)].nd_obj2).type,type);

                                                    sprintf(icg[ic_idx++], "%s = NULL\n", (yyvsp[(1) - (1)].nd_obj2).name);
                                                }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 451 "parser.y"
    { 
                                                                        (yyvsp[(1) - (4)].nd_obj2).nd = mknode(NULL,NULL,(yyvsp[(1) - (4)].nd_obj2).name) ;
                                                                        (yyvsp[(3) - (4)].nd_obj).nd = mknode(NULL,NULL,"Comma") ; 
                                                                        struct node *temp = mknode((yyvsp[(3) - (4)].nd_obj).nd, (yyvsp[(4) - (4)].nd_obj).nd, "var_list");
                                                                        (yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj2).nd, temp, "var_list_structure"); 
                                                                    }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 457 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "var_list");    }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 458 "parser.y"
    {
                                                    (yyvsp[(2) - (3)].nd_obj).nd = mknode(NULL,NULL,"Comma") ; 
                                                    struct node *temp = mknode((yyvsp[(2) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, "var_list");
                                                    (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, temp, "var_list_structure");
                                                }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 463 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "var_list");    }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 464 "parser.y"
    {   (yyvsp[(2) - (3)].nd_obj).nd = mknode(NULL,NULL,"Comma") ;
                                                    struct node *temp = mknode((yyvsp[(2) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, "var_list");
                                                    (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, temp, "var_list_structure");
                                                }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 471 "parser.y"
    {
                                                yytext = malloc(sizeof(char)*strlen((yyvsp[(1) - (4)].nd_obj2).name));
                                                strcpy(yytext, (yyvsp[(1) - (4)].nd_obj2).name);
                                                add('A'); 
                                                (yyvsp[(1) - (4)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (4)].nd_obj2).name);
                                                (yyvsp[(3) - (4)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(3) - (4)].nd_obj).name);
                                                struct node *temp = mknode((yyvsp[(3) - (4)].nd_obj).nd, NULL, "size");
                                                (yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj2).nd, temp, "arr_dec");
                                            }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 481 "parser.y"
    {   
                                                                                yytext = malloc(sizeof(char)*strlen((yyvsp[(1) - (7)].nd_obj2).name));
                                                                                add('A');
                                                                                (yyvsp[(1) - (7)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (7)].nd_obj2).name);
                                                                                struct node *temp = mknode((yyvsp[(6) - (7)].nd_obj_arr).nd, NULL, "init_list");
                                                                                (yyval.nd_obj).nd = mknode((yyvsp[(1) - (7)].nd_obj2).nd, temp, "arr_dec");
                                                                            }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 488 "parser.y"
    {   
                                                                                    yytext = malloc(sizeof(char)*strlen((yyvsp[(1) - (7)].nd_obj2).name));
                                                                                    add('A'); 
                                                                                    (yyvsp[(1) - (7)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (7)].nd_obj2).name);
                                                                                    struct node *temp = mknode((yyvsp[(6) - (7)].nd_obj_arr).nd, NULL, "init_list");
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[(1) - (7)].nd_obj2).nd, temp, "arr_dec");
                                                                                }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 495 "parser.y"
    {   //change
                                                                yytext = malloc(sizeof(char) * strlen((yyvsp[(1) - (5)].nd_obj2).name));
                                                                add('A');
                                                                (yyvsp[(1) - (5)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (5)].nd_obj2).name);
                                                                struct node *temp = mknode((yyvsp[(5) - (5)].nd_obj_arr).nd, NULL, "string_init");
                                                                (yyval.nd_obj).nd = mknode((yyvsp[(1) - (5)].nd_obj2).nd, temp, "arr_dec");
                                                            }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 503 "parser.y"
    {   
                                                                                    yytext = malloc(sizeof(char)*strlen((yyvsp[(1) - (7)].nd_obj2).name));
                                                                                    add('A'); 
                                                                                    (yyvsp[(1) - (7)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (7)].nd_obj2).name);
                                                                                    struct node *temp = mknode((yyvsp[(6) - (7)].nd_obj_arr).nd, NULL, "init_list");
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[(1) - (7)].nd_obj2).nd, temp, "arr_dec");
                                                                                }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 510 "parser.y"
    {   
                                                                                        //change
                                                                                        printf("%d\n", (yyvsp[(7) - (8)].nd_obj_arr).sz);
                                                                                        if(atoi((yyvsp[(3) - (8)].nd_obj).name) < (yyvsp[(7) - (8)].nd_obj_arr).sz) {
                                                                                            printf("Error: Array size is less than the number of elements in the initialization list\n");
                                                                                            exit(1);
                                                                                        }
                                                                                        else{
                                                                                            yytext = malloc(sizeof(char)*strlen((yyvsp[(1) - (8)].nd_obj2).name));
                                                                                            strcpy(yytext, (yyvsp[(1) - (8)].nd_obj2).name);
                                                                                            add('A');
                                                                                            (yyvsp[(1) - (8)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (8)].nd_obj2).name);
                                                                                            (yyvsp[(3) - (8)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(3) - (8)].nd_obj).name);
                                                                                            struct node *temp2 = mknode((yyvsp[(3) - (8)].nd_obj).nd, NULL, "size");
                                                                                            struct node *temp = mknode((yyvsp[(1) - (8)].nd_obj2).nd, temp2, "ID_size");
                                                                                            (yyval.nd_obj).nd = mknode(temp, (yyvsp[(7) - (8)].nd_obj_arr).nd, "arr_dec");
                                                                                        }
                                                                                    }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 528 "parser.y"
    {   
                                                                                        //change
                                                                                        printf("%d\n", (yyvsp[(7) - (8)].nd_obj_arr).sz);
                                                                                        if(atoi((yyvsp[(3) - (8)].nd_obj).name) < (yyvsp[(7) - (8)].nd_obj_arr).sz) {
                                                                                            printf("Error: Array size is less than the number of elements in the initialization list\n");
                                                                                            exit(1);
                                                                                        }
                                                                                        else {
                                                                                            yytext = malloc(sizeof(char)*strlen((yyvsp[(1) - (8)].nd_obj2).name));
                                                                                            strcpy(yytext, (yyvsp[(1) - (8)].nd_obj2).name);
                                                                                            add('A');
                                                                                            (yyvsp[(1) - (8)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (8)].nd_obj2).name);
                                                                                            (yyvsp[(3) - (8)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(3) - (8)].nd_obj).name);
                                                                                            struct node *temp2 = mknode((yyvsp[(3) - (8)].nd_obj).nd, NULL, "size");
                                                                                            struct node *temp = mknode((yyvsp[(1) - (8)].nd_obj2).nd, temp2, "ID_size");
                                                                                            (yyval.nd_obj).nd = mknode(temp, (yyvsp[(7) - (8)].nd_obj_arr).nd, "arr_dec");
                                                                                        }
                                                                                    }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 546 "parser.y"
    {   //change
                                                                        if(atoi((yyvsp[(3) - (6)].nd_obj).name) < (yyvsp[(6) - (6)].nd_obj_arr).sz) {
                                                                            printf("Error: Array size is less than the number of elements in the initialization list\n");
                                                                            exit(1);
                                                                        }
                                                                        else {
                                                                            yytext = malloc(sizeof(char) * strlen((yyvsp[(1) - (6)].nd_obj2).name));
                                                                            strcpy(yytext, (yyvsp[(1) - (6)].nd_obj2).name);
                                                                            add('A');
                                                                            (yyvsp[(1) - (6)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (6)].nd_obj2).name);
                                                                            (yyvsp[(3) - (6)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(3) - (6)].nd_obj).name);
                                                                            struct node *temp = mknode((yyvsp[(1) - (6)].nd_obj2).nd, (yyvsp[(3) - (6)].nd_obj).nd, "ID_size");
                                                                            (yyval.nd_obj).nd = mknode(temp, (yyvsp[(6) - (6)].nd_obj_arr).nd, "arr_dec");
                                                                        }
                                                                    }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 561 "parser.y"
    {
                                                                                        //change
                                                                                        printf("%d\n", (yyvsp[(7) - (8)].nd_obj_arr).sz);
                                                                                        if(atoi((yyvsp[(3) - (8)].nd_obj).name) < (yyvsp[(7) - (8)].nd_obj_arr).sz) {
                                                                                            printf("Error: Array size is less than the number of elements in the initialization list\n");
                                                                                            exit(1);
                                                                                        }
                                                                                        else {
                                                                                            yytext = malloc(sizeof(char)*strlen((yyvsp[(1) - (8)].nd_obj2).name));
                                                                                            strcpy(yytext, (yyvsp[(1) - (8)].nd_obj2).name);
                                                                                            add('A');
                                                                                            (yyvsp[(1) - (8)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (8)].nd_obj2).name);
                                                                                            (yyvsp[(3) - (8)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(3) - (8)].nd_obj).name);
                                                                                            struct node *temp2 = mknode((yyvsp[(3) - (8)].nd_obj).nd, NULL, "size");
                                                                                            struct node *temp = mknode((yyvsp[(1) - (8)].nd_obj2).nd, temp2, "ID_size");
                                                                                            (yyval.nd_obj).nd = mknode(temp, (yyvsp[(7) - (8)].nd_obj_arr).nd, "arr_dec");
                                                                                        }
                                                                                    }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 579 "parser.y"
    {
                                                                                yytext = malloc(sizeof(char) * strlen((yyvsp[(1) - (7)].nd_obj2).name));
                                                                                strcpy(yytext, (yyvsp[(1) - (7)].nd_obj2).name);
                                                                                add('A');
                                                                                (yyvsp[(1) - (7)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (7)].nd_obj2).name);
                                                                                (yyvsp[(3) - (7)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(3) - (7)].nd_obj).name);
                                                                                (yyvsp[(6) - (7)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(6) - (7)].nd_obj).name);
                                                                                struct node *temp = mknode((yyvsp[(3) - (7)].nd_obj).nd, (yyvsp[(6) - (7)].nd_obj).nd, "size");
                                                                                (yyval.nd_obj).nd = mknode((yyvsp[(1) - (7)].nd_obj2).nd, temp, "arr_dec");
                                                                            }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 590 "parser.y"
    {
                                                                    //change
                                                                    if(atoi((yyvsp[(6) - (9)].nd_obj).name) < (yyvsp[(9) - (9)].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else if(atoi((yyvsp[(3) - (9)].nd_obj).name) < (yyvsp[(9) - (9)].nd_obj_arr2).sz){
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more number of {} in init list than specified by 1st dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        // printf("sz = %d, each_sz = %d, mul = %d \n", $9.sz, $9.each_list_sz, $9.sz * $9.each_list_sz);
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[(1) - (9)].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[(1) - (9)].nd_obj2).name);
                                                                        add('A');
                                                                        (yyvsp[(1) - (9)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (9)].nd_obj2).name);
                                                                        (yyvsp[(3) - (9)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(3) - (9)].nd_obj).name);
                                                                        (yyvsp[(6) - (9)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(6) - (9)].nd_obj).name);
                                                                        struct node *temp = mknode((yyvsp[(3) - (9)].nd_obj).nd, (yyvsp[(6) - (9)].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[(1) - (9)].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[(9) - (9)].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 614 "parser.y"
    {
                                                                    //change
                                                                    if(atoi((yyvsp[(6) - (9)].nd_obj).name) < (yyvsp[(9) - (9)].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else if(atoi((yyvsp[(3) - (9)].nd_obj).name) < (yyvsp[(9) - (9)].nd_obj_arr2).sz){
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more number of {} in init list than specified by 1st dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        // printf("sz = %d, each_sz = %d, mul = %d \n", $9.sz, $9.each_list_sz, $9.sz * $9.each_list_sz);
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[(1) - (9)].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[(1) - (9)].nd_obj2).name);
                                                                        add('A');
                                                                        (yyvsp[(1) - (9)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (9)].nd_obj2).name);
                                                                        (yyvsp[(3) - (9)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(3) - (9)].nd_obj).name);
                                                                        (yyvsp[(6) - (9)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(6) - (9)].nd_obj).name);
                                                                        struct node *temp = mknode((yyvsp[(3) - (9)].nd_obj).nd, (yyvsp[(6) - (9)].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[(1) - (9)].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[(9) - (9)].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 638 "parser.y"
    {
                                                                    //change2
                                                                    if(atoi((yyvsp[(6) - (11)].nd_obj).name) < (yyvsp[(10) - (11)].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more chars in one or more strings in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else if(atoi((yyvsp[(3) - (11)].nd_obj).name) < (yyvsp[(10) - (11)].nd_obj_arr2).sz){
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more number of strings in init list than specified by 1st dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        // printf("sz = %d, each_sz = %d, mul = %d \n", $9.sz, $9.each_list_sz, $9.sz * $9.each_list_sz);
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[(1) - (11)].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[(1) - (11)].nd_obj2).name);
                                                                        add('V');
                                                                        (yyvsp[(1) - (11)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (11)].nd_obj2).name);
                                                                        (yyvsp[(3) - (11)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(3) - (11)].nd_obj).name);
                                                                        (yyvsp[(6) - (11)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(6) - (11)].nd_obj).name);
                                                                        struct node *temp = mknode((yyvsp[(3) - (11)].nd_obj).nd, (yyvsp[(6) - (11)].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[(1) - (11)].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[(10) - (11)].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 662 "parser.y"
    {
                                                                    //change
                                                                    if(atoi((yyvsp[(6) - (9)].nd_obj).name) < (yyvsp[(9) - (9)].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else if(atoi((yyvsp[(3) - (9)].nd_obj).name) < (yyvsp[(9) - (9)].nd_obj_arr2).sz){
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more number of {} in init list than specified by 1st dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        // printf("sz = %d, each_sz = %d, mul = %d \n", $9.sz, $9.each_list_sz, $9.sz * $9.each_list_sz);
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[(1) - (9)].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[(1) - (9)].nd_obj2).name);
                                                                        add('A');
                                                                        (yyvsp[(1) - (9)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (9)].nd_obj2).name);
                                                                        (yyvsp[(3) - (9)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(3) - (9)].nd_obj).name);
                                                                        (yyvsp[(6) - (9)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(6) - (9)].nd_obj).name);
                                                                        struct node *temp = mknode((yyvsp[(3) - (9)].nd_obj).nd, (yyvsp[(6) - (9)].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[(1) - (9)].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[(9) - (9)].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 686 "parser.y"
    {
                                                                    //change
                                                                    if(atoi((yyvsp[(5) - (8)].nd_obj).name) < (yyvsp[(8) - (8)].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[(1) - (8)].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[(1) - (8)].nd_obj2).name);
                                                                        add('A');
                                                                        (yyvsp[(1) - (8)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (8)].nd_obj2).name);
                                                                        struct node *firstsize = mknode(NULL, NULL, " ");
                                                                        (yyvsp[(5) - (8)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(5) - (8)].nd_obj).name);
                                                                        struct node *temp = mknode(firstsize, (yyvsp[(5) - (8)].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[(1) - (8)].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[(8) - (8)].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 705 "parser.y"
    {
                                                                    //change
                                                                    if(atoi((yyvsp[(5) - (8)].nd_obj).name) < (yyvsp[(8) - (8)].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[(1) - (8)].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[(1) - (8)].nd_obj2).name);
                                                                        add('A');
                                                                        (yyvsp[(1) - (8)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (8)].nd_obj2).name);
                                                                        struct node *firstsize = mknode(NULL, NULL, " ");
                                                                        (yyvsp[(5) - (8)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(5) - (8)].nd_obj).name);
                                                                        struct node *temp = mknode(firstsize, (yyvsp[(5) - (8)].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[(1) - (8)].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[(8) - (8)].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 724 "parser.y"
    {
                                                                    //change2
                                                                    if(atoi((yyvsp[(5) - (10)].nd_obj).name) < (yyvsp[(9) - (10)].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more chars in one or more strings in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[(1) - (10)].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[(1) - (10)].nd_obj2).name);
                                                                        add('V');
                                                                        (yyvsp[(1) - (10)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (10)].nd_obj2).name);
                                                                        struct node *firstsize = mknode(NULL, NULL, " ");
                                                                        (yyvsp[(5) - (10)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(5) - (10)].nd_obj).name);
                                                                        struct node *temp = mknode(firstsize, (yyvsp[(5) - (10)].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[(1) - (10)].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[(9) - (10)].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 743 "parser.y"
    {
                                                                    //change
                                                                    if(atoi((yyvsp[(5) - (8)].nd_obj).name) < (yyvsp[(8) - (8)].nd_obj_arr2).each_list_sz) {
                                                                        printf("Error: Array size is less than the number of elements in the initialization list(more elts in one or more {} in init list than specified by 2nd dim)\n");
                                                                        exit(1);
                                                                    }
                                                                    else {
                                                                        yytext = malloc(sizeof(char) * strlen((yyvsp[(1) - (8)].nd_obj2).name));
                                                                        strcpy(yytext, (yyvsp[(1) - (8)].nd_obj2).name);
                                                                        add('A');
                                                                        (yyvsp[(1) - (8)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (8)].nd_obj2).name);
                                                                        struct node *firstsize = mknode(NULL, NULL, " ");
                                                                        (yyvsp[(5) - (8)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(5) - (8)].nd_obj).name);
                                                                        struct node *temp = mknode(firstsize, (yyvsp[(5) - (8)].nd_obj).nd, "size");
                                                                        struct node *temp2 = mknode((yyvsp[(1) - (8)].nd_obj2).nd, temp, "ID_size");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[(8) - (8)].nd_obj_arr2).nd, "arr_dec");
                                                                    }
                                                                }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 764 "parser.y"
    {
                                        //change
                                        (yyval.nd_obj_arr2).sz = 1;
                                        (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(2) - (3)].nd_obj_arr).sz;
                                        (yyval.nd_obj_arr2).nd = mknode((yyvsp[(2) - (3)].nd_obj_arr).nd, NULL, "multiple_num_list");
                                    }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 770 "parser.y"
    {
                                                //change
                                                (yyval.nd_obj_arr2).sz = (yyvsp[(2) - (3)].nd_obj_arr2).sz;
                                                (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(2) - (3)].nd_obj_arr2).each_list_sz;
                                                (yyval.nd_obj_arr2).nd = mknode((yyvsp[(2) - (3)].nd_obj_arr2).nd, NULL, "multiple_num_list");
                                            }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 779 "parser.y"
    {
                                            //change
                                            (yyval.nd_obj_arr2).sz = 1;
                                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(2) - (3)].nd_obj_arr).sz;
                                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[(2) - (3)].nd_obj_arr).nd, NULL, "multiple_character_list");
                                        }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 785 "parser.y"
    {
                                                    //change
                                                    (yyval.nd_obj_arr2).sz = (yyvsp[(2) - (3)].nd_obj_arr2).sz;
                                                    (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(2) - (3)].nd_obj_arr2).each_list_sz;
                                                    (yyval.nd_obj_arr2).nd = mknode((yyvsp[(2) - (3)].nd_obj_arr2).nd, NULL, "multiple_character_list");
                                                }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 794 "parser.y"
    {
                                            //change
                                            (yyval.nd_obj_arr2).sz = 1;
                                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(2) - (3)].nd_obj_arr).sz;
                                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[(2) - (3)].nd_obj_arr).nd, NULL, "multiple_float_num_list");
                                        }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 800 "parser.y"
    {
                                                    //change
                                                    (yyval.nd_obj_arr2).sz = (yyvsp[(2) - (3)].nd_obj_arr2).sz;
                                                    (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(2) - (3)].nd_obj_arr2).each_list_sz;
                                                    (yyval.nd_obj_arr2).nd = mknode((yyvsp[(2) - (3)].nd_obj_arr2).nd, NULL, "multiple_float_num_list");
                                                }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 809 "parser.y"
    {
                                        //change
                                        (yyval.nd_obj_arr2).sz = 1;
                                        (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(2) - (3)].nd_obj_arr).sz;
                                        (yyval.nd_obj_arr2).nd = mknode((yyvsp[(2) - (3)].nd_obj_arr).nd, NULL, "braced_num_list");
                                    }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 815 "parser.y"
    {
                                                                //change
                                                                (yyval.nd_obj_arr2).sz = (yyvsp[(5) - (5)].nd_obj_arr2).sz + 1;
                                                                (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(2) - (5)].nd_obj_arr).sz > (yyvsp[(5) - (5)].nd_obj_arr2).each_list_sz ? (yyvsp[(2) - (5)].nd_obj_arr).sz : (yyvsp[(5) - (5)].nd_obj_arr2).each_list_sz;
                                                                (yyval.nd_obj_arr2).nd = mknode((yyvsp[(2) - (5)].nd_obj_arr).nd, (yyvsp[(5) - (5)].nd_obj_arr2).nd, "braced_num_list");
                                                            }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 824 "parser.y"
    {
                                            //change
                                            (yyval.nd_obj_arr2).sz = 1;
                                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(2) - (3)].nd_obj_arr).sz;
                                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[(2) - (3)].nd_obj_arr).nd, NULL, "braced_character_list");
                                        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 830 "parser.y"
    {
                                                                            //change
                                                                            (yyval.nd_obj_arr2).sz = (yyvsp[(5) - (5)].nd_obj_arr2).sz + 1;
                                                                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(2) - (5)].nd_obj_arr).sz > (yyvsp[(5) - (5)].nd_obj_arr2).each_list_sz ? (yyvsp[(2) - (5)].nd_obj_arr).sz : (yyvsp[(5) - (5)].nd_obj_arr2).each_list_sz;
                                                                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[(2) - (5)].nd_obj_arr).nd, (yyvsp[(5) - (5)].nd_obj_arr2).nd, "braced_character_list");
                                                                        }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 839 "parser.y"
    {
                                            //change
                                            (yyval.nd_obj_arr2).sz = 1;
                                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(2) - (3)].nd_obj_arr).sz;
                                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[(2) - (3)].nd_obj_arr).nd, NULL, "braced_float_num_list");
                                        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 845 "parser.y"
    {
                                                                            //change
                                                                            (yyval.nd_obj_arr2).sz = (yyvsp[(5) - (5)].nd_obj_arr2).sz + 1;
                                                                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(2) - (5)].nd_obj_arr).sz > (yyvsp[(5) - (5)].nd_obj_arr2).each_list_sz ? (yyvsp[(2) - (5)].nd_obj_arr).sz : (yyvsp[(5) - (5)].nd_obj_arr2).each_list_sz;
                                                                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[(2) - (5)].nd_obj_arr).nd, (yyvsp[(5) - (5)].nd_obj_arr2).nd, "braced_float_num_list");
                                                                        }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 854 "parser.y"
    {
                                            (yyval.nd_obj_arr).sz = 1;      //change
                                            (yyvsp[(1) - (1)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);
                                            (yyval.nd_obj_arr).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "number_list");
                                        }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 859 "parser.y"
    {
                                            (yyval.nd_obj_arr).sz = (yyvsp[(3) - (3)].nd_obj_arr).sz + 1;  //change
                                            (yyvsp[(1) - (3)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (3)].nd_obj).name);
                                            (yyval.nd_obj_arr).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj_arr).nd, "number_list");
                                        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 867 "parser.y"
    {
                                                (yyval.nd_obj_arr).sz = 1;      //change
                                                (yyvsp[(1) - (1)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);
                                                (yyval.nd_obj_arr).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "character_list");
                                            }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 872 "parser.y"
    {
                                                (yyval.nd_obj_arr).sz = (yyvsp[(3) - (3)].nd_obj_arr).sz + 1;  //change
                                                (yyvsp[(1) - (3)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (3)].nd_obj).name);
                                                (yyval.nd_obj_arr).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj_arr).nd, "character_list");
                                            }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 879 "parser.y"
    {
                                                    //change2
                                                    (yyval.nd_obj_arr2).sz = (yyvsp[(3) - (3)].nd_obj_arr2).sz + 1;
                                                    (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(1) - (3)].nd_obj_arr).sz > (yyvsp[(3) - (3)].nd_obj_arr2).each_list_sz ? (yyvsp[(1) - (3)].nd_obj_arr).sz : (yyvsp[(3) - (3)].nd_obj_arr2).each_list_sz;
                                                    (yyvsp[(1) - (3)].nd_obj_arr).nd = mknode(NULL, NULL, (yyvsp[(1) - (3)].nd_obj_arr).name);
                                                    (yyval.nd_obj_arr2).nd = mknode((yyvsp[(1) - (3)].nd_obj_arr).nd, (yyvsp[(3) - (3)].nd_obj_arr2).nd, "stringconst_list");
                                                }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 886 "parser.y"
    {
                            //change2
                            (yyval.nd_obj_arr2).sz = 1;
                            (yyval.nd_obj_arr2).each_list_sz = (yyvsp[(1) - (1)].nd_obj_arr).sz;
                            (yyvsp[(1) - (1)].nd_obj_arr).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj_arr).name);
                            (yyval.nd_obj_arr2).nd = mknode((yyvsp[(1) - (1)].nd_obj_arr).nd, NULL, "stringconst_list");
                        }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 896 "parser.y"
    {
                                                (yyval.nd_obj_arr).sz = 1;      //change
                                                (yyvsp[(1) - (1)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);
                                                (yyval.nd_obj_arr).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "float_num_list");
                                            }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 901 "parser.y"
    {
                                                (yyval.nd_obj_arr).sz = (yyvsp[(3) - (3)].nd_obj_arr).sz + 1;  //change
                                                (yyvsp[(1) - (3)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (3)].nd_obj).name);
                                                (yyval.nd_obj_arr).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj_arr).nd, "float_num_list");
                                            }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 910 "parser.y"
    {
                yytext = malloc(sizeof(char)*strlen((yyvsp[(1) - (1)].nd_obj2).name));
                strcpy(yytext, (yyvsp[(1) - (1)].nd_obj2).name);
                add('V');
            }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 914 "parser.y"
    {
                                                    printf("Types: 1 %s 2 %s\n", get_type((yyvsp[(1) - (4)].nd_obj2).name), (yyvsp[(4) - (4)].nd_obj3).type);
                                                    if(strcmp(get_type((yyvsp[(1) - (4)].nd_obj2).name), (yyvsp[(4) - (4)].nd_obj3).type) != 0)
                                                    {
                                                        printf("Error: Type mismatch in assignment statement %d\n",yylineno);
                                                        exit(1);
                                                    }
                                                    (yyvsp[(1) - (4)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (4)].nd_obj2).name);
                                                    (yyvsp[(3) - (4)].nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj2).nd, (yyvsp[(4) - (4)].nd_obj3).nd, "ASSIGNMENT");
                                                    (yyval.nd_obj).nd = mknode((yyvsp[(3) - (4)].nd_obj).nd, NULL, "assignment_statement");

                                                    sprintf(icg[ic_idx++], "%s = t%d\n", (yyvsp[(1) - (4)].nd_obj2).name, (yyvsp[(4) - (4)].nd_obj3).t);
                                                }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 930 "parser.y"
    {   
                                                    sprintf((yyval.nd_obj3).type, "int");
                                                    (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "OR");
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "expression_statement");

                                                    if(is_if == 1) {
                                                        sprintf(icg[ic_idx++], "\nIF t%d OR t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label, label + 1);
                                                        sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                        sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                    } 
                                                    else if(is_for == 1) {
                                                        sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                        sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                        sprintf(icg[ic_idx++], "if NOT (t%d OR t%d) GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label);
                                                        sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                    }
                                                    else {
                                                        (yyval.nd_obj3).t = temp_var++;
                                                        sprintf(icg[ic_idx++], "t%d = %d OR t%d\n", (yyval.nd_obj3).t, (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t);
                                                    }
                                                }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 951 "parser.y"
    {
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj3).nd, NULL, "expression_statement");   
                                                    sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (1)].nd_obj3).type);

                                                    (yyval.nd_obj3).t = (yyvsp[(1) - (1)].nd_obj3).t;
                                                }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 960 "parser.y"
    {
                                            sprintf((yyval.nd_obj3).type, "int");
                                            (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "AND");
                                            (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "logical_or_expression");

                                            if(is_if == 1) {
                                                sprintf(icg[ic_idx++], "\nIF t%d AND t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label, label + 1);
                                                sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                            }
                                            else if(is_for == 1) {
                                                sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                sprintf(icg[ic_idx++], "if NOT (t%d AND t%d) GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label);
                                                sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                            }
                                            else {
                                                (yyval.nd_obj3).t = temp_var++;
                                                sprintf(icg[ic_idx++], "t%d = t%d AND t%d\n", (yyval.nd_obj3).t, (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t);
                                            }
                                        }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 981 "parser.y"
    {   
                                            (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj3).nd, NULL, "logical_or_expression");   
                                            sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (1)].nd_obj3).type);

                                            (yyval.nd_obj3).t = (yyvsp[(1) - (1)].nd_obj3).t;
                                        }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 990 "parser.y"
    {
                                                sprintf((yyval.nd_obj3).type, "int");
                                                (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "EQ");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "logical_a_exp");

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d == t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label, label + 1);
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d == t%d) GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else {
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d == t%d\n", (yyval.nd_obj3).t, (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t);
                                                }
                                            }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1011 "parser.y"
    {
                                                sprintf((yyval.nd_obj3).type, "int");
                                                (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "NE");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "logical_a_exp");

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d != t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label, label + 1);
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d != t%d) GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else {
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d != t%d\n", (yyval.nd_obj3).t, (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t);
                                                }
                                            }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1032 "parser.y"
    {   
                                                (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj3).nd, NULL, "logical_a_exp");   
                                                sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (1)].nd_obj3).type);

                                                (yyval.nd_obj3).t = (yyvsp[(1) - (1)].nd_obj3).t;
                                            }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1041 "parser.y"
    {
                                                if(strcmp((yyvsp[(1) - (3)].nd_obj3).type, "char") == 0 || strcmp((yyvsp[(3) - (3)].nd_obj3).type, "char") == 0){
                                                    printf("Can't compare character in line %d\n", yylineno);
                                                    exit(1);
                                                }
                                                sprintf((yyval.nd_obj3).type, "int");
                                                (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "GT");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "relational_exp");

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d > t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label, label + 1);
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d > t%d) GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else {
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d > t%d\n", (yyval.nd_obj3).t, (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t);
                                                }
                                            }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1066 "parser.y"
    {
                                                if(strcmp((yyvsp[(1) - (3)].nd_obj3).type, "char") == 0 || strcmp((yyvsp[(3) - (3)].nd_obj3).type, "char") == 0){
                                                    printf("Can't compare character in line %d\n", yylineno);
                                                    exit(1);
                                                }
                                                sprintf((yyval.nd_obj3).type, "int");
                                                (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "GE");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "relational_exp");

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d >= t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label, label + 1);
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d >= t%d) GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else {
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d >= t%d\n", (yyval.nd_obj3).t, (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t);
                                                }
                                            }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1091 "parser.y"
    {
                                                if(strcmp((yyvsp[(1) - (3)].nd_obj3).type, "char") == 0 || strcmp((yyvsp[(3) - (3)].nd_obj3).type, "char") == 0){
                                                    printf("Can't compare character in line %d\n", yylineno);
                                                    exit(1);
                                                }
                                                sprintf((yyval.nd_obj3).type, "int");
                                                (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "LT");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "relational_exp");

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d < t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label, label + 1);
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d < t%d) GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else {
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d < t%d\n", (yyval.nd_obj3).t, (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t);
                                                }
                                            }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1116 "parser.y"
    {
                                                if(strcmp((yyvsp[(1) - (3)].nd_obj3).type, "char") == 0 || strcmp((yyvsp[(3) - (3)].nd_obj3).type, "char") == 0){
                                                    printf("Can't compare character in line %d\n", yylineno);
                                                    exit(1);
                                                }
                                                sprintf((yyval.nd_obj3).type, "int");
                                                (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "LE");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "relational_exp");

                                                if(is_if == 1) {
                                                    sprintf(icg[ic_idx++], "\nIF t%d <= t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label, label + 1);
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else if(is_for == 1) {
                                                    sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                                    sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                                    sprintf(icg[ic_idx++], "if NOT (t%d <= t%d) GOTO L%d\n", (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t, label);
                                                    sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                                                }
                                                else {
                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d <= t%d\n", (yyval.nd_obj3).t, (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t);
                                                }
                                            }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1141 "parser.y"
    {   
                                                (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj3).nd, NULL, "relational_exp");  
                                                sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (1)].nd_obj3).type);

                                                (yyval.nd_obj3).t = (yyvsp[(1) - (1)].nd_obj3).t;
                                            }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1150 "parser.y"
    {
                                                    if(strcmp((yyvsp[(1) - (3)].nd_obj3).type, "char") == 0 || strcmp((yyvsp[(3) - (3)].nd_obj3).type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp((yyvsp[(1) - (3)].nd_obj3).type, (yyvsp[(3) - (3)].nd_obj3).type)) {
		                                                sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (3)].nd_obj3).type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line  %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "ADD");
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "additive_exp");

                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d + t%d\n", (yyval.nd_obj3).t, (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t);
                                                }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1168 "parser.y"
    {
                                                    if(strcmp((yyvsp[(1) - (3)].nd_obj3).type, "char") == 0 || strcmp((yyvsp[(3) - (3)].nd_obj3).type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp((yyvsp[(1) - (3)].nd_obj3).type, (yyvsp[(3) - (3)].nd_obj3).type)) {
		                                                sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (3)].nd_obj3).type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "SUB");
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "additive_exp");

                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d - t%d\n", (yyval.nd_obj3).t, (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t);
                                                }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1186 "parser.y"
    {   
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj3).nd, NULL, "additive_exp");    
                                                    sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (1)].nd_obj3).type);

                                                    (yyval.nd_obj3).t = (yyvsp[(1) - (1)].nd_obj3).t;
                                                }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1195 "parser.y"
    {   
                                                    if(strcmp((yyvsp[(1) - (3)].nd_obj3).type, "char") == 0 || strcmp((yyvsp[(3) - (3)].nd_obj3).type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp((yyvsp[(1) - (3)].nd_obj3).type, (yyvsp[(3) - (3)].nd_obj3).type)) {
		                                                sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (3)].nd_obj3).type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "MUL");
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "multiplicative_exp");

                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d * t%d\n", (yyval.nd_obj3).t, (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t);
                                                }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1213 "parser.y"
    {
                                                    if(strcmp((yyvsp[(1) - (3)].nd_obj3).type, "char") == 0 || strcmp((yyvsp[(3) - (3)].nd_obj3).type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp((yyvsp[(1) - (3)].nd_obj3).type, (yyvsp[(3) - (3)].nd_obj3).type)) {
		                                                sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (3)].nd_obj3).type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "DIV");
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "multiplicative_exp");

                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d / t%d\n", (yyval.nd_obj3).t, (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t);
                                                }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1231 "parser.y"
    {
                                                    if(strcmp((yyvsp[(1) - (3)].nd_obj3).type, "char") == 0 || strcmp((yyvsp[(3) - (3)].nd_obj3).type, "char") == 0){
                                                        printf("Can't compare character in line %d\n", yylineno);
                                                        exit(1);
                                                    }
                                                    if(!strcmp((yyvsp[(1) - (3)].nd_obj3).type, (yyvsp[(3) - (3)].nd_obj3).type)) {
		                                                sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (3)].nd_obj3).type);
                                                    }
                                                    else{
                                                        printf("Type mismatch in line %d\n", yylineno);
                                                        exit(1);    
                                                    }
                                                    (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "MOD");
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "multiplicative_exp");

                                                    (yyval.nd_obj3).t = temp_var++;
                                                    sprintf(icg[ic_idx++], "t%d = t%d %% t%d\n", (yyval.nd_obj3).t, (yyvsp[(1) - (3)].nd_obj3).t, (yyvsp[(3) - (3)].nd_obj3).t);
                                                }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1249 "parser.y"
    {   
                                                    (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj3).nd, NULL, "multiplicative_exp");  
                                                    sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (1)].nd_obj3).type);

                                                    (yyval.nd_obj3).t = (yyvsp[(1) - (1)].nd_obj3).t;
                                                }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1258 "parser.y"
    {
                            if(strcmp((yyvsp[(2) - (2)].nd_obj3).type, "int") != 0){
                                printf("Type mismatch in line %d\n", yylineno);
                                exit(1);
                            }
                            sprintf((yyval.nd_obj3).type, (yyvsp[(2) - (2)].nd_obj3).type);
                            (yyvsp[(1) - (2)].nd_obj).nd = mknode((yyvsp[(2) - (2)].nd_obj3).nd, NULL, "NOT");
                            (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, "negation_exp");

                            if(is_if == 1) {
                                sprintf(icg[ic_idx++], "\nIF !t%d GOTO L%d ELSE GOTO L%d\n", (yyvsp[(2) - (2)].nd_obj3).t, label, label + 1);
                                sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                            }
                            else if(is_for == 1) {
                                sprintf((yyval.nd_obj3).if_body, "L%d", label++);
                                sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
                                sprintf(icg[ic_idx++], "if NOT (!t%d) GOTO L%d\n", (yyvsp[(2) - (2)].nd_obj3).t, label);
                                sprintf((yyval.nd_obj3).else_body, "L%d", label++);
                            }
                            (yyval.nd_obj3).t = temp_var++;
                            sprintf(icg[ic_idx++], "t%d = !t%d\n", (yyval.nd_obj3).t, (yyvsp[(2) - (2)].nd_obj3).t);
                        }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1281 "parser.y"
    {   
                                sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (1)].nd_obj3).type);
                                (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj3).nd, NULL, "negation_exp");

                                (yyval.nd_obj3).t = (yyvsp[(1) - (1)].nd_obj3).t;  
                            }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1290 "parser.y"
    {
                                                        if(check_declaration((yyvsp[(1) - (4)].nd_obj3).name)==0){
                                                            printf("Variable %s not declared in line %d\n", (yyvsp[(1) - (4)].nd_obj3).name, yylineno);
                                                            exit(1);
                                                        }
                                                        sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (4)].nd_obj3).type);
                                                        (yyvsp[(3) - (4)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(3) - (4)].nd_obj).name);
                                                        (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (4)].nd_obj3).nd, (yyvsp[(3) - (4)].nd_obj).nd, "access_call_exp");

                                                        (yyval.nd_obj3).t = temp_var++;
                                                        if(strcmp((yyvsp[(1) - (4)].nd_obj3).type, "int") == 0)
                                                            sprintf(icg[ic_idx++], "t%d = 4 * %d\n", (yyval.nd_obj3).t, atoi((yyvsp[(3) - (4)].nd_obj).name));
                                                        else if(strcmp((yyvsp[(1) - (4)].nd_obj3).type, "char") == 0)
                                                            sprintf(icg[ic_idx++], "t%d = 1 * %d\n", (yyval.nd_obj3).t, atoi((yyvsp[(3) - (4)].nd_obj).name));
                                                        else if(strcmp((yyvsp[(1) - (4)].nd_obj3).type, "float") == 0)
                                                            sprintf(icg[ic_idx++], "t%d = 8 * %d\n", (yyval.nd_obj3).t, atoi((yyvsp[(3) - (4)].nd_obj).name));
                                                        
                                                        (yyval.nd_obj3).t = temp_var++;
                                                        sprintf(icg[ic_idx++], "t%d = &%s\n", (yyval.nd_obj3).t, (yyvsp[(1) - (4)].nd_obj3).name);

                                                        (yyval.nd_obj3).t = temp_var++;
                                                        sprintf(icg[ic_idx++], "t%d = t%d + t%d\n", (yyval.nd_obj3).t, (yyval.nd_obj3).t - 1, (yyval.nd_obj3).t - 2);
                                                        arr_en = 1;
                                                        // sprintf(icg[ic_idx++], "%s = *t%d\n", "HAHA", $$.t);
                                                    }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1315 "parser.y"
    {   
                            sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (1)].nd_obj3).type);
                            (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj3).nd, NULL, "access_call_exp");

                            (yyval.nd_obj3).t = (yyvsp[(1) - (1)].nd_obj3).t;  
                        }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1321 "parser.y"
    {
                                                printf("Checking for function name %s\n", (yyvsp[(1) - (3)].nd_obj3).name);
                                                if(check_declaration((yyvsp[(1) - (3)].nd_obj3).name)==0){
                                                    printf("BACK TO access_call_exp\n");
                                                    printf("Variable %s not declared in line %d\n", (yyvsp[(1) - (3)].nd_obj3).name, yylineno);
                                                    exit(1);
                                                }
                                                printf("BACK TO access_call_exp\n");
                                                checkFinalArguments((yyvsp[(1) - (3)].nd_obj3).name);
                                                (yyvsp[(2) - (3)].nd_obj).nd = mknode(NULL, NULL, "LPAREN");
                                                (yyvsp[(3) - (3)].nd_obj).nd = mknode(NULL, NULL, "RPAREN");
                                                struct node *temp = mknode((yyvsp[(2) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, "PARENTHESES");
                                                (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (3)].nd_obj3).nd, temp, "access_call_exp");
                                            }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1335 "parser.y"
    {
            stringTemp=strdup(currentFunction);
            strcpy(currentFunction, (yyvsp[(1) - (2)].nd_obj3).name);
            }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1338 "parser.y"
    { 
                                        strcpy(currentFunction, stringTemp);  
                                        printf("Accessing Function %s\n", (yyvsp[(1) - (5)].nd_obj3).name);
                                        if(check_declaration((yyvsp[(1) - (5)].nd_obj3).name)==0){
                                            printf("Variable %s not declared in line %d\n", (yyvsp[(1) - (5)].nd_obj3).name, yylineno);
                                            exit(1);
                                        }
                                        
                                        (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (5)].nd_obj3).nd, (yyvsp[(4) - (5)].nd_obj).nd, "access_call_exp");    
                                    }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1351 "parser.y"
    {   
                                                (yyval.nd_obj3).nd = mknode((yyvsp[(2) - (3)].nd_obj3).nd, NULL, "primary_exp"); 
                                                sprintf((yyval.nd_obj3).type, (yyvsp[(2) - (3)].nd_obj3).type);

                                                (yyval.nd_obj3).t = (yyvsp[(2) - (3)].nd_obj3).t;
                                            }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1357 "parser.y"
    {  
                                                printf("Checking for variable name %s\n", (yyvsp[(1) - (1)].nd_obj2).name);
                                                if(check_declaration((yyvsp[(1) - (1)].nd_obj2).name)==0){
                                                    printf("Variable %s not declared in line %d\n", (yyvsp[(1) - (1)].nd_obj2).name, yylineno);
                                                    exit(1);
                                                }
                                                sprintf((yyval.nd_obj3).type, get_type((yyvsp[(1) - (1)].nd_obj2).name));
                                                (yyvsp[(1) - (1)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj2).name);
                                                (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj2).nd, NULL, "primary_exp");

                                                (yyval.nd_obj3).t = temp_var++;
                                                sprintf(icg[ic_idx++], "t%d = %s\n", (yyval.nd_obj3).t, (yyvsp[(1) - (1)].nd_obj2).name);
                                            }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1370 "parser.y"
    {   
                                                sprintf((yyval.nd_obj3).type, (yyvsp[(1) - (1)].nd_obj3).type);
                                                (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj3).nd, NULL, "primary_exp");

                                                (yyval.nd_obj3).t = temp_var++;
                                                sprintf(icg[ic_idx++], "t%d = %s\n", (yyval.nd_obj3).t, (yyvsp[(1) - (1)].nd_obj3).name);
                                            }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1380 "parser.y"
    {
                            sprintf((yyval.nd_obj3).type, "int");
                            (yyvsp[(1) - (1)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);
                            (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "constant");

                            // strcpy($$.name, $1.name);
                        }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1387 "parser.y"
    {
                            sprintf((yyval.nd_obj3).type, "char");
                            (yyvsp[(1) - (1)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);
                            (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "constant");

                            // strcpy($$.name, $1.name);
                        }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1394 "parser.y"
    {
                            sprintf((yyval.nd_obj3).type, "float");
                            (yyvsp[(1) - (1)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);
                            (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "constant");

                            // strcpy($$.name, $1.name);
                        }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1401 "parser.y"
    {
                            sprintf((yyval.nd_obj3).type, "exp");
                            (yyvsp[(1) - (1)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);
                            (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "constant");

                            // strcpy($$.name, $1.name);
                        }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1411 "parser.y"
    {is_if = 1;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1411 "parser.y"
    {sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[(4) - (5)].nd_obj3).if_body);}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1411 "parser.y"
    {sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[(4) - (7)].nd_obj3).else_body);}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1412 "parser.y"
    {
                                                                            (yyvsp[(1) - (9)].nd_obj).nd = mknode((yyvsp[(4) - (9)].nd_obj3).nd,(yyvsp[(7) - (9)].nd_obj).nd,"IF");
                                                                            // $9.nd = mknode($10.nd,NULL,"ELSE");
                                                                            (yyval.nd_obj).nd = mknode((yyvsp[(1) - (9)].nd_obj).nd,(yyvsp[(9) - (9)].nd_obj).nd,"IF_statement");
                                                                            is_if = 0;
                                                                        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1420 "parser.y"
    {
                                    (yyvsp[(1) - (2)].nd_obj).nd = mknode((yyvsp[(2) - (2)].nd_obj).nd, NULL, "ELSE");
                                    (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, NULL, "EL_statement");    
                                }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1424 "parser.y"
    {   (yyval.nd_obj).nd = NULL; }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1429 "parser.y"
    {
            nextTable();
            is_for = 1;
        }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1434 "parser.y"
    {
                                                                        prevTable();
                                                                        struct node *temp1 = mknode((yyvsp[(4) - (10)].nd_obj).nd, (yyvsp[(5) - (10)].nd_obj3).nd, "For_Parameters_1");
                                                                        struct node *temp2 = mknode(temp1, (yyvsp[(6) - (10)].nd_obj).nd, "For_Parameters_2");
                                                                        (yyval.nd_obj).nd = mknode(temp2, (yyvsp[(9) - (10)].nd_obj).nd, "For_Statement");

                                                                        sprintf(icg[ic_idx++], buff);
                                                                        sprintf(icg[ic_idx++], "JUMP TO %s\n", (yyvsp[(5) - (10)].nd_obj3).if_body);
                                                                        sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[(5) - (10)].nd_obj3).else_body);
                                                                        is_for = 0;
                                                                    }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1447 "parser.y"
    {   
                                                                if(check_declaration((yyvsp[(1) - (3)].nd_obj2).name) == 0 || isArray((yyvsp[(1) - (3)].nd_obj2).name) == 1)
                                                                {
                                                                    printf("Error: Variable %s not declared at line %d\n", (yyvsp[(1) - (3)].nd_obj2).name, yylineno);
                                                                    exit(1);
                                                                }
                                                                printf("Types of %s is %s\n", get_type((yyvsp[(1) - (3)].nd_obj2).name), (yyvsp[(3) - (3)].nd_obj3).type);
                                                                if(strcmp(get_type((yyvsp[(1) - (3)].nd_obj2).name), (yyvsp[(3) - (3)].nd_obj3).type) != 0)
                                                                {
                                                                    printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                    exit(1);
                                                                }
                                                                (yyvsp[(1) - (3)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (3)].nd_obj2).name);
                                                                (yyvsp[(2) - (3)].nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj2).nd, (yyvsp[(3) - (3)].nd_obj3).nd, "ASSIGNMENT");
                                                                (yyval.nd_obj).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, NULL, "assignment_statement");

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
                                                                        sprintf(icg[ic_idx++], "%s = *t%d\n", (yyvsp[(1) - (3)].nd_obj2).name, (yyvsp[(3) - (3)].nd_obj3).t);
                                                                        arr_en = 0;
                                                                    }
                                                                    else {
                                                                        sprintf(icg[ic_idx++], "%s = t%d\n", (yyvsp[(1) - (3)].nd_obj2).name, (yyvsp[(3) - (3)].nd_obj3).t);
                                                                    }
                                                                // }
                                                                //need to put a = *T3 here after array
                                                                    
                                                            }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1483 "parser.y"
    {
                                                                                if(check_declaration((yyvsp[(1) - (6)].nd_obj2).name) == 0 || isArray((yyvsp[(1) - (6)].nd_obj2).name) == 0)
                                                                                {
                                                                                    printf("Error: Variable %s is not an array at line %d\n", (yyvsp[(1) - (6)].nd_obj2).name, yylineno);
                                                                                    exit(1);
                                                                                }
                                                                                printf("Types of %s is %s\n", get_type((yyvsp[(1) - (6)].nd_obj2).name), (yyvsp[(6) - (6)].nd_obj3).type);
                                                                                if(strcmp(get_type((yyvsp[(1) - (6)].nd_obj2).name), (yyvsp[(6) - (6)].nd_obj3).type) != 0)
                                                                                {
                                                                                    printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                    exit(1);
                                                                                }
                                                                                (yyvsp[(1) - (6)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (6)].nd_obj2).name);
                                                                                (yyvsp[(2) - (6)].nd_obj).nd = mknode((yyvsp[(1) - (6)].nd_obj2).nd, (yyvsp[(3) - (6)].nd_obj).nd, "LSQBRACKET");
                                                                                (yyvsp[(4) - (6)].nd_obj).nd = mknode((yyvsp[(2) - (6)].nd_obj).nd, (yyvsp[(5) - (6)].nd_obj).nd, "RSQBRACKET");
                                                                                (yyvsp[(6) - (6)].nd_obj3).nd = mknode((yyvsp[(4) - (6)].nd_obj).nd, NULL, "ASSIGNMENT");
                                                                                (yyval.nd_obj).nd = mknode((yyvsp[(6) - (6)].nd_obj3).nd, NULL, "assignment_statement");

                                                                                // $$.t = temp_var++;
                                                                                
                                                                                if(strcmp(get_type((yyvsp[(1) - (6)].nd_obj2).name), "int") == 0)
                                                                                    sprintf(icg[ic_idx++], "t%d = 4 * %d\n", temp_var++, atoi((yyvsp[(3) - (6)].nd_obj).name));
                                                                                else if(strcmp(get_type((yyvsp[(1) - (6)].nd_obj2).name), "char") == 0)
                                                                                    sprintf(icg[ic_idx++], "t%d = 1 * %d\n", temp_var++, atoi((yyvsp[(3) - (6)].nd_obj).name));
                                                                                else if(strcmp(get_type((yyvsp[(1) - (6)].nd_obj2).name), "float") == 0)
                                                                                    sprintf(icg[ic_idx++], "t%d = 8 * %d\n", temp_var++, atoi((yyvsp[(3) - (6)].nd_obj).name));
                                                                                

                                                                                // $$.t = temp_var++;
                                                                                sprintf(icg[ic_idx++], "t%d = &%s\n", temp_var++, (yyvsp[(1) - (6)].nd_obj2).name);

                                                                                // $$.t = temp_var++;
                                                                                sprintf(icg[ic_idx++], "t%d = t%d + t%d\n", temp_var, temp_var - 2, temp_var - 1);

                                                                                sprintf(icg[ic_idx++], "*t%d = t%d", temp_var, (yyvsp[(6) - (6)].nd_obj3).t);
                                                                                // arr_en = 1;
                                                                            }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1520 "parser.y"
    {
                                                                                                                    printf("Testing Here 4\n");
                                                                                                                    if(check_declaration((yyvsp[(1) - (9)].nd_obj2).name) == 0 || isArray((yyvsp[(1) - (9)].nd_obj2).name) == 0)
                                                                                                                    {
                                                                                                                        printf("Error: Variable %s is not an array at line %d\n", (yyvsp[(1) - (9)].nd_obj2).name, yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    printf("Types of %s is %s\n", get_type((yyvsp[(1) - (9)].nd_obj2).name), (yyvsp[(9) - (9)].nd_obj3).type);
                                                                                                                    if(strcmp(get_type((yyvsp[(1) - (9)].nd_obj2).name), (yyvsp[(9) - (9)].nd_obj3).type) != 0)
                                                                                                                    {
                                                                                                                        printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    (yyvsp[(1) - (9)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (9)].nd_obj2).name);
                                                                                                                    (yyvsp[(2) - (9)].nd_obj).nd = mknode((yyvsp[(1) - (9)].nd_obj2).nd, (yyvsp[(3) - (9)].nd_obj2).nd, "LSQBRACKET");
                                                                                                                    (yyvsp[(4) - (9)].nd_obj).nd = mknode((yyvsp[(2) - (9)].nd_obj).nd, (yyvsp[(5) - (9)].nd_obj).nd, "RSQBRACKET");
                                                                                                                    (yyvsp[(9) - (9)].nd_obj3).nd = mknode((yyvsp[(4) - (9)].nd_obj).nd, NULL, "ASSIGNMENT");
                                                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[(9) - (9)].nd_obj3).nd, NULL, "assignment_statement");
                                                                                                                }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1539 "parser.y"
    {
                                                                                        printf("Testing Here 5\n");
                                                                                        if(check_declaration((yyvsp[(1) - (9)].nd_obj2).name) == 0 || isArray((yyvsp[(1) - (9)].nd_obj2).name) == 0)
                                                                                        {
                                                                                            printf("Error: Variable %s is not an array at line %d\n", (yyvsp[(1) - (9)].nd_obj2).name, yylineno);
                                                                                            exit(1);
                                                                                        }
                                                                                        if(check_declaration((yyvsp[(3) - (9)].nd_obj2).name) == 0 || isArray((yyvsp[(3) - (9)].nd_obj2).name) == 1)
                                                                                        {
                                                                                            printf("Error: Variable %s not declared at line %d\n", (yyvsp[(3) - (9)].nd_obj2).name, yylineno);
                                                                                            exit(1);
                                                                                        }
                                                                                        printf("Types of %s is %s\n", get_type((yyvsp[(1) - (9)].nd_obj2).name), (yyvsp[(9) - (9)].nd_obj3).type);
                                                                                        if(strcmp(get_type((yyvsp[(1) - (9)].nd_obj2).name), (yyvsp[(9) - (9)].nd_obj3).type) != 0)
                                                                                        {
                                                                                            printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                            exit(1);
                                                                                        }
                                                                                        (yyvsp[(1) - (9)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (9)].nd_obj2).name);
                                                                                        (yyvsp[(2) - (9)].nd_obj).nd = mknode((yyvsp[(1) - (9)].nd_obj2).nd, (yyvsp[(3) - (9)].nd_obj2).nd, "LSQBRACKET");
                                                                                        (yyvsp[(4) - (9)].nd_obj).nd = mknode((yyvsp[(2) - (9)].nd_obj).nd, (yyvsp[(5) - (9)].nd_obj).nd, "RSQBRACKET");
                                                                                        (yyvsp[(9) - (9)].nd_obj3).nd = mknode((yyvsp[(4) - (9)].nd_obj).nd, NULL, "ASSIGNMENT");
                                                                                        (yyval.nd_obj).nd = mknode((yyvsp[(9) - (9)].nd_obj3).nd, NULL, "assignment_statement");
                                                                                    }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1563 "parser.y"
    {
                                                                                                                    printf("Testing Here 6\n");
                                                                                                                    if(check_declaration((yyvsp[(1) - (9)].nd_obj2).name) == 0 || isArray((yyvsp[(1) - (9)].nd_obj2).name) == 0)
                                                                                                                    {
                                                                                                                        printf("Error: Variable %s is not an array at line %d\n", (yyvsp[(1) - (9)].nd_obj2).name, yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    printf("Types of %s is %s\n", get_type((yyvsp[(1) - (9)].nd_obj2).name), (yyvsp[(9) - (9)].nd_obj3).type);
                                                                                                                    if(strcmp(get_type((yyvsp[(1) - (9)].nd_obj2).name), (yyvsp[(9) - (9)].nd_obj3).type) != 0)
                                                                                                                    {
                                                                                                                        printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    (yyvsp[(1) - (9)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (9)].nd_obj2).name);
                                                                                                                    (yyvsp[(2) - (9)].nd_obj).nd = mknode((yyvsp[(1) - (9)].nd_obj2).nd, (yyvsp[(3) - (9)].nd_obj).nd, "LSQBRACKET");
                                                                                                                    (yyvsp[(4) - (9)].nd_obj).nd = mknode((yyvsp[(2) - (9)].nd_obj).nd, (yyvsp[(5) - (9)].nd_obj).nd, "RSQBRACKET");
                                                                                                                    (yyvsp[(9) - (9)].nd_obj3).nd = mknode((yyvsp[(4) - (9)].nd_obj).nd, NULL, "ASSIGNMENT");
                                                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[(9) - (9)].nd_obj3).nd, NULL, "assignment_statement");
                                                                                                                }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1582 "parser.y"
    {
                                                                                                                    printf("Testing Here 7\n");
                                                                                                                    if(check_declaration((yyvsp[(1) - (9)].nd_obj2).name) == 0 || isArray((yyvsp[(1) - (9)].nd_obj2).name) == 0)
                                                                                                                    {
                                                                                                                        printf("Error: Variable %s is not an array at line %d\n", (yyvsp[(1) - (9)].nd_obj2).name, yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    if(check_declaration((yyvsp[(3) - (9)].nd_obj).name) == 0 || isArray((yyvsp[(3) - (9)].nd_obj).name) == 1)
                                                                                                                    {
                                                                                                                        printf("Error: Variable %s not declared at line %d\n", (yyvsp[(3) - (9)].nd_obj).name, yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    printf("Types of %s is %s\n", get_type((yyvsp[(1) - (9)].nd_obj2).name), (yyvsp[(9) - (9)].nd_obj3).type);
                                                                                                                    if(strcmp(get_type((yyvsp[(1) - (9)].nd_obj2).name), (yyvsp[(9) - (9)].nd_obj3).type) != 0)
                                                                                                                    {
                                                                                                                        printf("Error: Type mismatch in assignment statement at line %d\n", yylineno);
                                                                                                                        exit(1);
                                                                                                                    }
                                                                                                                    (yyvsp[(1) - (9)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(1) - (9)].nd_obj2).name);
                                                                                                                    (yyvsp[(2) - (9)].nd_obj).nd = mknode((yyvsp[(1) - (9)].nd_obj2).nd, (yyvsp[(3) - (9)].nd_obj).nd, "LSQBRACKET");
                                                                                                                    (yyvsp[(4) - (9)].nd_obj).nd = mknode((yyvsp[(2) - (9)].nd_obj).nd, (yyvsp[(5) - (9)].nd_obj).nd, "RSQBRACKET");
                                                                                                                    (yyvsp[(9) - (9)].nd_obj3).nd = mknode((yyvsp[(4) - (9)].nd_obj).nd, NULL, "ASSIGNMENT");
                                                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[(9) - (9)].nd_obj3).nd, NULL, "assignment_statement");
                                                                                                                }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1609 "parser.y"
    {   
                                printf("Variable %s declared at line %d\n", (yyvsp[(2) - (2)].nd_obj2).name, yylineno);
                                if(check_declaration((yyvsp[(2) - (2)].nd_obj2).name) == 1)
                                {
                                    printf("Error: Variable %s not declared at line %d\n", (yyvsp[(2) - (2)].nd_obj2).name, yylineno);
                                    exit(1);
                                }
                                yytext = malloc(sizeof(char)*strlen((yyvsp[(2) - (2)].nd_obj2).name));
                                strcpy(yytext,(yyvsp[(2) - (2)].nd_obj2).name);
                                add('V');
                                printf("Added\n");
                            }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1621 "parser.y"
    {
                                                                            (yyvsp[(4) - (6)].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ; 
                                                                            struct node *temp = mknode((yyvsp[(1) - (6)].nd_obj).nd, (yyvsp[(2) - (6)].nd_obj2).nd, "for_initializer");
                                                                            (yyval.nd_obj).nd = mknode(temp, (yyvsp[(4) - (6)].nd_obj).nd, "for_initializer_structure");

                                                                            sprintf(icg[ic_idx++], "%s = t%d\n", (yyvsp[(2) - (6)].nd_obj2).name, (yyvsp[(5) - (6)].nd_obj3).t);
                                                                        }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1628 "parser.y"
    {
                                                    (yyvsp[(2) - (2)].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ;
                                                    (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "for_initializer");
                                                }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1632 "parser.y"
    {
                            (yyvsp[(1) - (1)].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ;
                            (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "for_initializer");
                        }
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1639 "parser.y"
    {
                                            (yyvsp[(2) - (2)].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ;
                                            (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (2)].nd_obj3).nd, (yyvsp[(2) - (2)].nd_obj).nd, "for_condition");

                                            //here checker
                                            // $$.if_body = $1.if_body;
                                            // $$.else_body = $1.else_body;
                                        }
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1647 "parser.y"
    {
                            (yyvsp[(1) - (1)].nd_obj).nd = mknode(NULL,NULL,"Semicolon") ;
                            (yyval.nd_obj3).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "for_condition");
                        }
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1654 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "for_update"); /*for_up = 1;*/ }
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1655 "parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "for_update"); }
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1659 "parser.y"
    {
            nextTable();
        }
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1661 "parser.y"
    {     prevTable();
                                                (yyval.nd_obj).nd = mknode((yyvsp[(3) - (8)].nd_obj3).nd, (yyvsp[(7) - (8)].nd_obj).nd, "while_statement");    
                                        }
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1667 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "loop_stat_list");  }
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1668 "parser.y"
    {  printf("222\n"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "loop_stat_list");   }
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1669 "parser.y"
    {   
                                (yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, "BREAK");
                                (yyvsp[(2) - (2)].nd_obj).nd = mknode(NULL, NULL, "SEMICOLON");
                                (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "loop_stat_list");
                            }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1674 "parser.y"
    {   
                                                (yyvsp[(1) - (3)].nd_obj).nd = mknode(NULL, NULL, "BREAK");
                                                (yyvsp[(2) - (3)].nd_obj).nd = mknode(NULL, NULL, "SEMICOLON");
                                                struct node* temp = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).nd, "break_stat");
                                                (yyval.nd_obj).nd = mknode(temp, (yyvsp[(3) - (3)].nd_obj).nd, "loop_stat_list");
                                            }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1680 "parser.y"
    {   
                                    (yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, "CONTINUE");
                                    (yyvsp[(2) - (2)].nd_obj).nd = mknode(NULL, NULL, "SEMICOLON");
                                    (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "loop_stat_list");
                                }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1685 "parser.y"
    {   
                                                    (yyvsp[(1) - (3)].nd_obj).nd = mknode(NULL, NULL, "CONTINUE");
                                                    (yyvsp[(2) - (3)].nd_obj).nd = mknode(NULL, NULL, "SEMICOLON");
                                                    struct node* temp = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).nd, "continue_stat");
                                                    (yyval.nd_obj).nd = mknode(temp, (yyvsp[(3) - (3)].nd_obj).nd, "loop_stat_list");
                                                }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1691 "parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, "loop_stat_list");}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1696 "parser.y"
    {
            nextTable();
        }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1698 "parser.y"
    {   
            (yyval.nd_obj).nd = mknode((yyvsp[(3) - (8)].nd_obj3).nd, (yyvsp[(6) - (8)].nd_obj).nd, "switch_statement");   
            prevTable();
        }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1705 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "switch_case_list");    }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1706 "parser.y"
    {   (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "switch_case_list");   }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1710 "parser.y"
    {
                                                struct node* temp1 = mknode((yyvsp[(1) - (4)].nd_obj).nd, (yyvsp[(2) - (4)].nd_obj3).nd, "Case");
                                                struct node* temp2 = mknode((yyvsp[(3) - (4)].nd_obj).nd, (yyvsp[(4) - (4)].nd_obj).nd, "Statement_List");
                                                (yyval.nd_obj).nd = mknode(temp1, temp2, "switch_case");
                                            }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1715 "parser.y"
    {
                                                struct node* temp1 = mknode((yyvsp[(1) - (3)].nd_obj).nd, NULL, "Default");
                                                struct node* temp2 = mknode((yyvsp[(2) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, "Statement_List");
                                                (yyval.nd_obj).nd = mknode(temp1, temp2, "switch_case");
                                            }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1722 "parser.y"
    { 
            if(currentPrintfArgumentIndex<FormatSpecifierListIndex){
                printf("Error: Too few arguments for printf\n");
                exit(1);
            } 
            currentPrintfArgumentIndex=0;
            clearFormatSpecifierList();
            (yyval.nd_obj).nd = mknode((yyvsp[(3) - (6)].nd_obj_arr).nd, NULL, "print");    
        }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1733 "parser.y"
    {
    countOfFormatSpecifiers((yyvsp[(1) - (1)].nd_obj).name);
    (yyval.nd_obj_arr).nd = mknode(NULL, NULL, "STR");
    printf("\nString is 1 %s\n", (yyvsp[(1) - (1)].nd_obj).name);
    (yyval.nd_obj_arr).sz = strlen((yyvsp[(1) - (1)].nd_obj).name)-2;
    printf("$$ size is %d\n", (yyval.nd_obj_arr).sz);
}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1742 "parser.y"
    {
                    if(check_declaration((yyvsp[(2) - (2)].nd_obj2).name)==0 && isArray((yyvsp[(1) - (2)].nd_obj).name)==0){
                        printf("Error: Undeclared variable %s\n", (yyvsp[(2) - (2)].nd_obj2).name);
                        exit(1);
                    }
                    if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                        printf("Error: Too many arguments for printf\n");
                        exit(1);
                    }
                    if(strcmp(get_type((yyvsp[(2) - (2)].nd_obj2).name),"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                        exit(1);
                    }
                    else if(strcmp(get_type((yyvsp[(2) - (2)].nd_obj2).name),"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                        exit(1);
                    }
                    else if(strcmp(get_type((yyvsp[(2) - (2)].nd_obj2).name),"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
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
                    (yyvsp[(2) - (2)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(2) - (2)].nd_obj2).name);
                    (yyval.nd_obj).nd = mknode((yyvsp[(2) - (2)].nd_obj2).nd, (yyval.nd_obj).nd, "plist");
}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1773 "parser.y"
    {
                        if(check_declaration((yyvsp[(2) - (3)].nd_obj2).name)==0 && isArray((yyvsp[(1) - (3)].nd_obj).name)==0){
                            printf("Error: Undeclared variable %s\n", (yyvsp[(2) - (3)].nd_obj2).name);
                            exit(1);
                        }
                        if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                            printf("Error: Too many arguments for printf\n");
                            exit(1);
                        }
                        if(strcmp(get_type((yyvsp[(2) - (3)].nd_obj2).name),"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        else if(strcmp(get_type((yyvsp[(2) - (3)].nd_obj2).name),"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        else if(strcmp(get_type((yyvsp[(2) - (3)].nd_obj2).name),"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        currentPrintfArgumentIndex++;
                        (yyvsp[(2) - (3)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(2) - (3)].nd_obj2).name);
                        struct node* temp = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj2).nd, "ID");
                        (yyval.nd_obj).nd = mknode(temp, (yyvsp[(3) - (3)].nd_obj).nd, "plist");
    }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1799 "parser.y"
    {
                                        if(check_declaration((yyvsp[(2) - (5)].nd_obj2).name)==0 && isArray((yyvsp[(2) - (5)].nd_obj2).name)==1){
                                            printf("Error: Undeclared variable %s\n", (yyvsp[(1) - (5)].nd_obj).name);
                                            exit(1);
                                        }
                                        if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                                            printf("Error: Too many arguments for printf\n");
                                            exit(1);
                                        }
                                        if(strcmp(get_type((yyvsp[(2) - (5)].nd_obj2).name),"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                                            printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                            exit(1);
                                        }
                                        else if(strcmp(get_type((yyvsp[(2) - (5)].nd_obj2).name),"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                                            printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                            exit(1);
                                        }
                                        else if(strcmp(get_type((yyvsp[(2) - (5)].nd_obj2).name),"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                                            printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                            exit(1);
                                        }
                                        currentPrintfArgumentIndex++;
                                        (yyvsp[(2) - (5)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(2) - (5)].nd_obj2).name);
                                        (yyval.nd_obj).nd = mknode((yyvsp[(1) - (5)].nd_obj).nd, NULL, "plist");
                                    }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1824 "parser.y"
    {
                                                if(check_declaration((yyvsp[(2) - (6)].nd_obj2).name)==0 && isArray((yyvsp[(2) - (6)].nd_obj2).name)==1){
                                                    printf("Error: Undeclared variable %s\n", (yyvsp[(2) - (6)].nd_obj2).name);
                                                    exit(1);
                                                }
                                                if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                                                    printf("Error: Too many arguments for printf\n");
                                                    exit(1);
                                                }
                                                if(strcmp(get_type((yyvsp[(2) - (6)].nd_obj2).name),"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                                                    printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                                    exit(1);
                                                }
                                                else if(strcmp(get_type((yyvsp[(2) - (6)].nd_obj2).name),"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                                                    printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                                    exit(1);
                                                }
                                                else if(strcmp(get_type((yyvsp[(1) - (6)].nd_obj).name),"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                                                    printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                                                    exit(1);
                                                }
                                                currentPrintfArgumentIndex++;
                                                (yyvsp[(2) - (6)].nd_obj2).nd = mknode(NULL, NULL, (yyvsp[(2) - (6)].nd_obj2).name);
                                                (yyval.nd_obj).nd = mknode((yyvsp[(2) - (6)].nd_obj2).nd, (yyvsp[(6) - (6)].nd_obj).nd, "plist");
                                            }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1849 "parser.y"
    {
                    if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                        printf("Error: Too many arguments for printf\n");
                        exit(1);
                    }
                    if(strcmp((yyvsp[(2) - (2)].nd_obj3).type,"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                        printf("Error: Format specifier mismatch for argument %d\n",currentPrintfArgumentIndex+1);
                        exit(1);
                    }
                    else if(strcmp((yyvsp[(2) - (2)].nd_obj3).type,"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                        printf("Error: Format specifier mismatch for argument %d\n",currentPrintfArgumentIndex+1);
                        exit(1);
                    }
                    else if(strcmp((yyvsp[(2) - (2)].nd_obj3).type,"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                        printf("Error: Format specifier mismatch for argument %d\n",currentPrintfArgumentIndex+1);
                        exit(1);
                    }
                    currentPrintfArgumentIndex++;
                    (yyval.nd_obj).nd = mknode((yyvsp[(2) - (2)].nd_obj3).nd, NULL, "plist");
                }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1869 "parser.y"
    {
                        printf("currentPrintfArgumentIndex is %d\n", currentPrintfArgumentIndex);
                        printf("FormatSpecifierListIndex is %d\n", FormatSpecifierListIndex);
                        if(currentPrintfArgumentIndex>=FormatSpecifierListIndex){
                            printf("Error: Too many arguments for printf\n");
                            exit(1);
                        }
                        if(strcmp((yyvsp[(2) - (3)].nd_obj3).type,"char")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=1){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        else if(strcmp((yyvsp[(2) - (3)].nd_obj3).type,"int")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=2){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        else if(strcmp((yyvsp[(2) - (3)].nd_obj3).type,"float")==0 && FormatSpecifierList[currentPrintfArgumentIndex]!=3){
                        printf("Error: Format specifier mismatch at line  %d\n",yylineno);
                            exit(1);
                        }
                        currentPrintfArgumentIndex++;
                        printf("currentPrintfArgumentIndex is %d\n", currentPrintfArgumentIndex);
                        printf("FormatSpecifierListIndex is %d\n", FormatSpecifierListIndex);
                        (yyval.nd_obj).nd = mknode((yyvsp[(2) - (3)].nd_obj3).nd, (yyvsp[(3) - (3)].nd_obj).nd, "plist");
                    }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1893 "parser.y"
    {
        (yyval.nd_obj).nd = mknode(NULL, NULL, "plist");
    }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1899 "parser.y"
    {
                                                    check_declaration(currentFunction);
                                                    // printf("Current function is %s\n",currentFunction);
                                                    if(strcmp(get_type(currentFunction),(yyvsp[(2) - (3)].nd_obj3).type)!=0){
                                                        printf("Error: Return type mismatch for function %s\n",currentFunction);
                                                        exit(1);
                                                    }
                                                    (yyvsp[(3) - (3)].nd_obj).nd = mknode(NULL,NULL,"SEMICOLON");
                                                    (yyvsp[(1) - (3)].nd_obj).nd = mknode(NULL, NULL, "RETURN");
                                                    struct node *temp = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj3).nd, "return_statement");
                                                    (yyval.nd_obj).nd = mknode(temp, (yyvsp[(3) - (3)].nd_obj).nd, "return_statement_structure");
                                                }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1911 "parser.y"
    {
                                    check_declaration(currentFunction);
                                    if(strcmp(get_type(currentFunction),"void")!=0){
                                        printf("Error: Return type mismatch for function %s\n",currentFunction);
                                        exit(1);
                                    }
                                    (yyvsp[(2) - (2)].nd_obj).nd = mknode(NULL,NULL,"SEMICOLON");
                                    (yyvsp[(1) - (2)].nd_obj).nd = mknode(NULL, NULL, "RETURN");
                                    (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "return_statement_structure");
                                }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1924 "parser.y"
    {                                            
            nextTable();
        }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1926 "parser.y"
    {   
                                            (yyval.nd_obj).nd = mknode((yyvsp[(3) - (4)].nd_obj).nd, NULL, "compound_statement");
                                            prevTable();
                                        }
    break;



/* Line 1455 of yacc.c  */
#line 4576 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1931 "parser.y"

 
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
