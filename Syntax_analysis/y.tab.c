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

#line 83 "y.tab.c"

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
#line 13 "parser.y"
 struct var_name { 
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
    

#line 275 "y.tab.c"

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
  YYSYMBOL_arglist = 60,                   /* arglist  */
  YYSYMBOL_args = 61,                      /* args  */
  YYSYMBOL_main = 62,                      /* main  */
  YYSYMBOL_statement_list = 63,            /* statement_list  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_calling_list = 65,              /* calling_list  */
  YYSYMBOL_declaration_statement = 66,     /* declaration_statement  */
  YYSYMBOL_type_specifier = 67,            /* type_specifier  */
  YYSYMBOL_var_list = 68,                  /* var_list  */
  YYSYMBOL_arr_dec = 69,                   /* arr_dec  */
  YYSYMBOL_multiple_num_list = 70,         /* multiple_num_list  */
  YYSYMBOL_multiple_character_list = 71,   /* multiple_character_list  */
  YYSYMBOL_multiple_float_num_list = 72,   /* multiple_float_num_list  */
  YYSYMBOL_braced_num_list = 73,           /* braced_num_list  */
  YYSYMBOL_braced_character_list = 74,     /* braced_character_list  */
  YYSYMBOL_braced_float_num_list = 75,     /* braced_float_num_list  */
  YYSYMBOL_number_list = 76,               /* number_list  */
  YYSYMBOL_character_list = 77,            /* character_list  */
  YYSYMBOL_stringconst_list = 78,          /* stringconst_list  */
  YYSYMBOL_float_num_list = 79,            /* float_num_list  */
  YYSYMBOL_assignment_statement = 80,      /* assignment_statement  */
  YYSYMBOL_expression_statement = 81,      /* expression_statement  */
  YYSYMBOL_logical_o_exp = 82,             /* logical_o_exp  */
  YYSYMBOL_logical_a_exp = 83,             /* logical_a_exp  */
  YYSYMBOL_relational_exp = 84,            /* relational_exp  */
  YYSYMBOL_additive_exp = 85,              /* additive_exp  */
  YYSYMBOL_multiplicative_exp = 86,        /* multiplicative_exp  */
  YYSYMBOL_negation_exp = 87,              /* negation_exp  */
  YYSYMBOL_access_call_exp = 88,           /* access_call_exp  */
  YYSYMBOL_primary_exp = 89,               /* primary_exp  */
  YYSYMBOL_constant = 90,                  /* constant  */
  YYSYMBOL_if_statement = 91,              /* if_statement  */
  YYSYMBOL_for_statement = 92,             /* for_statement  */
  YYSYMBOL_assignment_statement_2 = 93,    /* assignment_statement_2  */
  YYSYMBOL_for_initializer = 94,           /* for_initializer  */
  YYSYMBOL_for_condition = 95,             /* for_condition  */
  YYSYMBOL_for_update = 96,                /* for_update  */
  YYSYMBOL_while_statement = 97,           /* while_statement  */
  YYSYMBOL_loop_stat_list = 98,            /* loop_stat_list  */
  YYSYMBOL_switch_statement = 99,          /* switch_statement  */
  YYSYMBOL_switch_case_list = 100,         /* switch_case_list  */
  YYSYMBOL_switch_case = 101,              /* switch_case  */
  YYSYMBOL_print = 102,                    /* print  */
  YYSYMBOL_stringconst = 103,              /* stringconst  */
  YYSYMBOL_plist = 104,                    /* plist  */
  YYSYMBOL_return_statement = 105,         /* return_statement  */
  YYSYMBOL_compound_statement = 106        /* compound_statement  */
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
#define YYLAST   391

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  302

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
       0,    66,    66,    69,    70,    71,    72,    76,    79,    80,
      83,    87,    88,    89,    93,    94,    98,   102,   103,   104,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   123,   124,   125,   126,   130,   133,   134,   135,   139,
     140,   141,   142,   143,   144,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   169,   170,   174,   175,   179,   180,   184,
     185,   189,   190,   194,   195,   199,   200,   204,   205,   208,
     209,   213,   214,   219,   223,   224,   228,   229,   233,   234,
     235,   239,   240,   241,   242,   243,   247,   248,   249,   253,
     254,   255,   256,   260,   261,   265,   266,   267,   268,   269,
     273,   274,   275,   279,   280,   281,   282,   286,   287,   291,
     294,   295,   296,   300,   301,   302,   306,   307,   311,   312,
     316,   320,   321,   322,   323,   324,   325,   326,   331,   335,
     336,   340,   341,   344,   347,   350,   351,   352,   353,   354,
     355,   356,   360,   361,   365
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
  "functions", "function", "arglist", "args", "main", "statement_list",
  "statement", "calling_list", "declaration_statement", "type_specifier",
  "var_list", "arr_dec", "multiple_num_list", "multiple_character_list",
  "multiple_float_num_list", "braced_num_list", "braced_character_list",
  "braced_float_num_list", "number_list", "character_list",
  "stringconst_list", "float_num_list", "assignment_statement",
  "expression_statement", "logical_o_exp", "logical_a_exp",
  "relational_exp", "additive_exp", "multiplicative_exp", "negation_exp",
  "access_call_exp", "primary_exp", "constant", "if_statement",
  "for_statement", "assignment_statement_2", "for_initializer",
  "for_condition", "for_update", "while_statement", "loop_stat_list",
  "switch_statement", "switch_case_list", "switch_case", "print",
  "stringconst", "plist", "return_statement", "compound_statement", YY_NULLPTR
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

#define YYPACT_NINF (-251)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     195,  -251,  -251,  -251,  -251,    26,    -8,  -251,  -251,  -251,
    -251,  -251,    10,    45,    49,   150,    32,  -251,  -251,  -251,
      67,   106,   206,  -251,    98,    99,   116,   120,   123,   132,
     143,    94,  -251,  -251,   193,  -251,  -251,   237,   217,  -251,
     180,   206,  -251,   171,   -21,   204,    68,   213,   186,   165,
    -251,   129,  -251,  -251,  -251,  -251,   187,  -251,  -251,  -251,
    -251,  -251,   206,   150,  -251,   217,    85,   217,   217,   221,
    -251,  -251,    33,   140,   217,   140,    22,  -251,  -251,    34,
     192,   202,   209,   217,  -251,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,    -3,   196,  -251,
     208,   222,    72,  -251,   231,   129,   212,   121,    73,    76,
    -251,     6,  -251,   102,   236,  -251,   217,    55,   171,  -251,
     171,   171,   204,    68,   213,   213,   186,   186,   186,   186,
     165,   165,  -251,  -251,  -251,   233,   234,   225,  -251,   235,
     238,   195,    99,    32,   259,  -251,  -251,    60,   245,   242,
     247,   252,   273,     6,   251,   254,   255,   236,   256,    50,
    -251,  -251,  -251,   274,   275,   253,  -251,   253,  -251,  -251,
     295,   217,  -251,  -251,   258,   155,   122,   279,     6,  -251,
     257,  -251,  -251,   103,    -6,   281,   217,   217,  -251,  -251,
      32,    61,   261,   260,   262,   155,   264,   166,   263,   265,
     122,   266,  -251,  -251,     0,   289,    25,  -251,   272,   236,
     236,  -251,  -251,   155,   155,   155,  -251,  -251,   267,   155,
    -251,  -251,     6,    25,  -251,   276,   269,   271,   277,   278,
     280,   282,   294,   283,  -251,  -251,   155,  -251,  -251,   284,
     285,   286,   296,   297,   299,   302,  -251,  -251,  -251,   288,
    -251,  -251,  -251,  -251,  -251,   290,  -251,  -251,  -251,    47,
    -251,  -251,  -251,    47,  -251,  -251,  -251,    25,   291,   292,
     293,   298,   300,   301,   303,   304,   305,   307,   308,   309,
    -251,  -251,  -251,  -251,  -251,  -251,  -251,   221,  -251,   310,
     311,   312,  -251,   316,   317,   318,   299,  -251,   302,  -251,
     297,  -251
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     3,     4,     5,     0,     0,     2,     7,     8,
       9,     1,     0,     0,     0,    13,     0,    36,    37,    38,
       0,     0,    19,    16,     0,    11,     0,     0,     0,     0,
       0,     0,   115,   116,   111,   113,   114,     0,     0,    30,
       0,    17,    20,     0,     0,    85,    87,    90,    95,    98,
     102,   104,   107,   112,    23,    24,     0,    25,    26,    29,
      27,    28,    19,     0,    12,     0,     0,     0,     0,     0,
     111,   153,     0,   104,     0,   103,     0,   154,    18,    39,
       0,    43,    41,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
     144,   151,   152,     0,   120,   110,     0,     0,     0,    35,
       0,     0,    84,    86,    88,    89,    93,    94,    91,    92,
      96,    97,    99,   100,   101,     0,     0,    31,   108,     0,
      34,     0,    15,     0,     0,   124,   127,     0,   129,     0,
       0,     0,     0,   149,     0,     0,     0,    83,     0,     0,
      40,    44,    42,   106,   105,     0,   109,     0,    10,    14,
     117,     0,   126,   128,     0,   137,     0,     0,   145,   150,
       0,   106,   105,    45,     0,     0,     0,     0,    32,    33,
       0,     0,     0,     0,     0,   131,     0,     0,     0,     0,
     139,     0,   146,   143,     0,     0,     0,    48,     0,   122,
     121,   118,   123,   137,   133,   135,   132,   130,     0,   137,
     138,   140,   147,     0,    52,     0,    81,    75,    77,     0,
       0,     0,     0,     0,   134,   136,   137,   142,   148,     0,
       0,     0,    54,     0,     0,     0,    46,    47,    49,     0,
     119,   141,    50,    51,    53,     0,    82,    76,    78,     0,
      59,    60,    62,     0,    55,    56,    58,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
      64,    66,    68,    63,    65,    61,    67,     0,    57,    69,
      71,    73,    79,     0,     0,     0,     0,    70,     0,    72,
       0,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -251,  -251,  -251,  -251,   184,  -251,  -251,   198,  -251,    20,
       1,    38,  -251,    -4,    19,  -251,    83,    89,    90,    53,
      58,    52,  -196,  -199,  -250,  -202,  -251,   -29,   287,   306,
     146,   197,   179,   199,   -22,  -251,   -93,  -251,  -251,   -60,
    -251,  -251,  -251,  -251,  -163,  -251,   149,  -251,  -251,   -66,
    -145,  -251,   -15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    20,    64,    10,    40,
     195,   139,    42,    43,    80,    81,   260,   261,   262,   268,
     269,   270,   271,   272,   273,   274,    82,    44,    45,    46,
      47,    48,    49,    50,    73,    52,    53,    54,    55,    56,
     107,   148,   174,    57,   196,    58,   199,   200,    59,   275,
     154,    60,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    23,    72,   111,   231,   140,   106,   230,   179,    76,
     229,    21,    83,   276,   110,    75,    12,    13,   153,    51,
     110,   241,   135,    41,   240,   136,    11,   239,    32,    33,
      84,   151,   216,   202,    35,    36,   102,   292,   108,   109,
      51,   256,    41,   206,   105,   114,   258,   226,   257,   223,
     233,   234,   235,   227,   228,    83,   237,    14,   152,   101,
     153,    78,   104,    41,   116,   279,    83,   110,   278,   226,
     115,   277,   140,   251,   140,   227,   228,   238,   147,   117,
     184,    22,   100,   158,   112,   153,   118,   157,   173,    17,
      18,    19,    15,    83,    83,   185,   267,    16,   279,   278,
     277,   159,    86,    87,   218,    83,    83,    32,    33,    83,
      34,   172,   212,    35,    36,    24,    32,    33,   207,    70,
     143,   149,    35,    36,   150,    37,   105,   155,   170,   153,
     156,    25,    38,   204,   197,   198,   103,   160,   224,   161,
     162,    38,   191,    32,    33,    71,    70,    62,   205,    35,
      36,    63,    37,    51,    17,    18,    19,   209,   210,    17,
      18,    19,    26,    65,    27,    28,    29,    66,    38,    30,
      67,    31,   146,    51,    97,   211,    98,    32,    33,    68,
      34,   193,   194,    35,    36,   113,    37,    98,    32,    33,
      69,    51,    51,    51,    35,    36,    79,    51,     1,     2,
       3,     4,    38,   188,    22,   189,    39,    94,    95,    96,
      17,    18,    19,    26,    51,    27,    28,    29,    32,    33,
      30,   137,    31,    74,    35,    36,    92,    93,    32,    33,
      77,    34,   124,   125,    35,    36,    85,    37,    99,    32,
      33,   110,    70,   119,   138,    35,    36,   142,    37,    88,
      89,    90,    91,    38,   120,    22,   144,    39,   141,    32,
      33,   121,    70,   145,    38,    35,    36,    32,    33,    83,
      34,   130,   131,    35,    36,    32,    33,   165,   137,   163,
     164,    35,    36,   166,    38,   126,   127,   128,   129,   171,
     167,   175,    38,   132,   133,   134,   176,   177,   178,   180,
     181,   182,   183,   190,   186,   187,   192,   201,   203,   208,
     213,   214,   222,   215,   217,   220,   219,   225,   232,   226,
     236,   243,   242,   244,   249,   168,   255,   227,   246,   245,
     247,   228,   248,   250,   252,   253,   254,   259,   264,   263,
     169,   280,   281,   282,   265,   266,   297,   301,   283,   221,
     284,   285,   299,   286,     0,   288,   287,   289,   290,   291,
       0,     0,   293,   294,   295,   296,   298,   300,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123
};

static const yytype_int16 yycheck[] =
{
      22,    16,    31,    69,   206,    98,    66,   206,   153,    38,
     206,    15,    33,   263,    20,    37,    24,    25,   111,    41,
      20,   223,    25,    22,   223,    28,     0,   223,    22,    23,
      51,    25,   195,   178,    28,    29,    65,   287,    67,    68,
      62,   243,    41,    49,    66,    74,   245,    22,   244,    49,
     213,   214,   215,    28,    29,    33,   219,    47,    52,    63,
     153,    41,    66,    62,    30,   267,    33,    20,   267,    22,
      48,   267,   165,   236,   167,    28,    29,   222,   107,    45,
      30,    49,    62,    28,    51,   178,    52,   116,   148,     4,
       5,     6,    47,    33,    33,    45,    49,    48,   300,   298,
     296,    46,    34,    35,   197,    33,    33,    22,    23,    33,
      25,    51,    51,    28,    29,    48,    22,    23,   184,    25,
      48,    48,    28,    29,    48,    31,   148,    25,   143,   222,
      28,    25,    47,    30,    12,    13,    51,   118,   204,   120,
     121,    47,   171,    22,    23,    51,    25,    49,    45,    28,
      29,    52,    31,   175,     4,     5,     6,   186,   187,     4,
       5,     6,     7,    47,     9,    10,    11,    47,    47,    14,
      47,    16,    51,   195,    45,   190,    47,    22,    23,    47,
      25,    26,    27,    28,    29,    45,    31,    47,    22,    23,
      47,   213,   214,   215,    28,    29,    25,   219,     3,     4,
       5,     6,    47,   165,    49,   167,    51,    42,    43,    44,
       4,     5,     6,     7,   236,     9,    10,    11,    22,    23,
      14,    25,    16,    30,    28,    29,    40,    41,    22,    23,
      50,    25,    86,    87,    28,    29,    32,    31,    51,    22,
      23,    20,    25,    51,    48,    28,    29,    25,    31,    36,
      37,    38,    39,    47,    52,    49,    25,    51,    50,    22,
      23,    52,    25,    51,    47,    28,    29,    22,    23,    33,
      25,    92,    93,    28,    29,    22,    23,    52,    25,    46,
      46,    28,    29,    48,    47,    88,    89,    90,    91,    30,
      52,    49,    47,    94,    95,    96,    49,    45,    25,    48,
      46,    46,    46,     8,    30,    30,    48,    28,    51,    28,
      49,    51,    46,    51,    50,    50,    53,    28,    46,    22,
      53,    52,    46,    52,    30,   141,    30,    28,    50,    52,
      50,    29,    50,    50,    50,    50,    50,    49,   255,    49,
     142,    50,    50,    50,   255,   255,   293,   295,    50,   200,
      50,    50,   294,    50,    -1,    50,    52,    50,    50,    50,
      -1,    -1,    52,    52,    52,    49,    49,    49,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    55,    56,    57,    58,    59,
      62,     0,    24,    25,    47,    47,    48,     4,     5,     6,
      60,    67,    49,   106,    48,    25,     7,     9,    10,    11,
      14,    16,    22,    23,    25,    28,    29,    31,    47,    51,
      63,    64,    66,    67,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    97,    99,   102,
     105,   106,    49,    52,    61,    47,    47,    47,    47,    47,
      25,    51,    81,    88,    30,    88,    81,    50,    63,    25,
      68,    69,    80,    33,    51,    32,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    47,    51,
      63,    67,    81,    51,    67,    88,    93,    94,    81,    81,
      20,   103,    51,    45,    81,    48,    30,    45,    52,    51,
      52,    52,    82,    83,    84,    84,    85,    85,    85,    85,
      86,    86,    87,    87,    87,    25,    28,    25,    48,    65,
      90,    50,    25,    48,    25,    51,    51,    81,    95,    48,
      48,    25,    52,    90,   104,    25,    28,    81,    28,    46,
      68,    68,    68,    46,    46,    52,    48,    52,    58,    61,
     106,    30,    51,    93,    96,    49,    49,    45,    25,   104,
      48,    46,    46,    46,    30,    45,    30,    30,    65,    65,
       8,    81,    48,    26,    27,    64,    98,    12,    13,   100,
     101,    28,   104,    51,    30,    45,    49,   103,    28,    81,
      81,   106,    51,    49,    51,    51,    98,    50,    90,    53,
      50,   100,    46,    49,   103,    28,    22,    28,    29,    76,
      77,    79,    46,    98,    98,    98,    53,    98,   104,    76,
      77,    79,    46,    52,    52,    52,    50,    50,    50,    30,
      50,    98,    50,    50,    50,    30,    79,    76,    77,    49,
      70,    71,    72,    49,    70,    71,    72,    49,    73,    74,
      75,    76,    77,    78,    79,   103,    78,    76,    77,    79,
      50,    50,    50,    50,    50,    50,    50,    52,    50,    50,
      50,    50,    78,    52,    52,    52,    49,    73,    49,    74,
      49,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    56,    57,    58,    58,
      59,    60,    60,    60,    61,    61,    62,    63,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    65,    65,    66,    67,    67,    67,    68,
      68,    68,    68,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    81,    81,    82,    82,    83,    83,
      83,    84,    84,    84,    84,    84,    85,    85,    85,    86,
      86,    86,    86,    87,    87,    88,    88,    88,    88,    88,
      89,    89,    89,    90,    90,    90,    90,    91,    91,    92,
      93,    93,    93,    94,    94,    94,    95,    95,    96,    96,
      97,    98,    98,    98,    98,    98,    98,    98,    99,   100,
     100,   101,   101,   102,   103,   104,   104,   104,   104,   104,
     104,   104,   105,   105,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       9,     2,     3,     0,     4,     3,     5,     1,     2,     0,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     4,     7,     7,     5,     7,
       8,     8,     6,     8,     7,     9,     9,    11,     9,     8,
       8,    10,     8,     3,     3,     3,     3,     3,     3,     3,
       5,     3,     5,     3,     5,     1,     3,     1,     3,     3,
       1,     1,     3,     3,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     1,     4,     4,     1,     3,     4,
       3,     1,     1,     1,     1,     1,     1,     5,     7,     9,
       3,     6,     6,     5,     2,     1,     2,     1,     1,     0,
       7,     1,     2,     2,     3,     2,     3,     0,     7,     1,
       2,     4,     3,     6,     1,     2,     3,     4,     5,     1,
       2,     0,     3,     2,     3
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

#line 1589 "y.tab.c"

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

#line 367 "parser.y"

 
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
