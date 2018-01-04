/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMERO = 258,
    CADENA = 259,
    CARACTER = 260,
    ID = 261,
    INT = 262,
    DOUBLE = 263,
    FLOAT = 264,
    CHAR = 265,
    VOID = 266,
    STRUCT = 267,
    IF = 268,
    ELSE = 269,
    WHILE = 270,
    DO = 271,
    FOR = 272,
    SWITCH = 273,
    RETURN = 274,
    BREAK = 275,
    CASE = 276,
    DEFAULT = 277,
    TRUE = 278,
    FALSE = 279,
    FUNC = 280,
    PRINT = 281,
    LLLVE = 282,
    RLLVE = 283,
    LCHT = 284,
    RCHT = 285,
    COMA = 286,
    PCMA = 287,
    PNTS = 288,
    ASIG = 289,
    PUNTO = 290,
    SUM = 291,
    RES = 292,
    MUL = 293,
    DIV = 294,
    MOD = 295,
    LPAR = 296,
    RPAR = 297,
    MNRQ = 298,
    MYRQ = 299,
    MNROIQ = 300,
    MYROIQ = 301,
    DIFRNT = 302,
    IGUAL = 303,
    OR = 304,
    AND = 305,
    NOT = 306
  };
#endif
/* Tokens.  */
#define NUMERO 258
#define CADENA 259
#define CARACTER 260
#define ID 261
#define INT 262
#define DOUBLE 263
#define FLOAT 264
#define CHAR 265
#define VOID 266
#define STRUCT 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define DO 271
#define FOR 272
#define SWITCH 273
#define RETURN 274
#define BREAK 275
#define CASE 276
#define DEFAULT 277
#define TRUE 278
#define FALSE 279
#define FUNC 280
#define PRINT 281
#define LLLVE 282
#define RLLVE 283
#define LCHT 284
#define RCHT 285
#define COMA 286
#define PCMA 287
#define PNTS 288
#define ASIG 289
#define PUNTO 290
#define SUM 291
#define RES 292
#define MUL 293
#define DIV 294
#define MOD 295
#define LPAR 296
#define RPAR 297
#define MNRQ 298
#define MYRQ 299
#define MNROIQ 300
#define MYROIQ 301
#define DIFRNT 302
#define IGUAL 303
#define OR 304
#define AND 305
#define NOT 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 134 "yacc.y" /* yacc.c:1909  */


	struct {
		int ival; // Valor INT
		float fval; // Valor FLOAT
		double dval; // Valor DOUBLE
		int tipo; // 1:INT 2:FLOAT 3:DOUBLE
	}numero;
	
	struct {
		int tipo;
	}D;
	
	struct {
		int tipo;
	}T;

	struct {
		int elementosEST;
		int elementosETT;
	}L;
	
	struct {
		int isArray;
		int isUltimo;
		int tipoBase;
		int dim;
		int elementosETT;
	}C;
	
	struct {
		char *next;
		int indice; // entero para manipular los indices de los arreglos
		char *etiquetas[50]; // guarda todas las cadenas de las etiquetas de cada caso
		int numCasos[50]; // guarda el entrero contra el cual debemos comprarar en cada caso
		char *codigo;
	}J;
	
	struct {
		char *next;
		char *etiqueta; // cadena que guarda la etiqueta en donde esta el codigo de default
		char *codigo; // cadena que guarda el codigo
	}K;
	
	struct {
		char *next; // cadena/etiqueta situada en el proximo codigo a ejecutarse
		char *codigo; //cadena que guarda el codigo
	}S;

	struct {
		char *trueLabel;
		char *falseLabel;
		char *codigo;
	}B;
	
	struct {
		int tipo;
		char *temp;
		char *codigo;
	}E;
	
	struct {
		char *codigo;
	}R;
	
	char *cadena;
	char caracter;
	

#line 226 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
