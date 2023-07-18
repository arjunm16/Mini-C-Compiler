
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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
    


/* Line 1676 of yacc.c  */
#line 196 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


