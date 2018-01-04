/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>

/*Con esto evito el warning:implicit declaration of function ‘yylex’ [-Wimplicit-function-declaration]
       yychar = yylex ();
                ^         */

	extern int yylex (void);

////// TABLA DE SIMBOLOS //////

	struct symbolTable{
		char *lexema;
		int tipo;
		char *tipoVar;
		int dir;
	};
	
	typedef struct symbolTable symbolTable;
	
	symbolTable GST[10000]; // Tabla de Simbolos Global hasta 10,000 elementos
	
	/*Cada entero controla la posicion de una tabla de simbolos, posST[0] controla
	  la posicion de la tabla de simbolos global */
	  
	int posST[30]; // Control de las posiciones de 30 tablas de simbolos
	
	
////// TABLA DE TIPOS //////

	struct typeTable{
		char *tipo;
		int tipoBase;
		int dim;
	};
	
	typedef struct typeTable typeTable;
	
	typeTable GTT[1000]; // Tabla de tipos global hasta 1,000 elementos
	
	int posTT; // Control de las posiciones de la tabla de tipos

////// TABLA DE SIMBOLOS EMBRIÓN //////

	typedef struct{
		int posST;
		char *lexema;
		int tipo;
	}embryoST;

	embryoST EST[100];

	int posEST = 0;

	
	void insertIntoEmbryoSymbolTable(int *posEST,int *posTS,char *lexema,int type,embryoST EST[]);
	void printEmbryoSymbolTable(embryoST EST[],int posEST);

////// TABLA DE TIPOS EMBRIÓN //////
	
	typedef struct{
		int posTT;
		int tipoBase;
		int dim;
	}embryoTT;

	embryoTT ETT[100];

	int posETT = 0;

	void inserIntoEmbryoTypeTable(int *posETT,int *posTT,int baseType,int dim,embryoTT ETT[]);
	void printEmbryoTypeTable(embryoTT ETT[],int posETT);
	
	 
////// VARIABLES GLOBALES USADAS EN LAS ACCIONES SEMÁNTICAS DE LA PARTE DE REGLAS DE TRADUCCIÓN //////
	 
	int tempNum = 0; // Contador de temporales
	int etiNum = 0; // Contador de etiquetas
	
	int posSTAux; // para que insertIntoEmbryoST sea responsable con posST[0] la engañamos con posSTAux
	
	
	/* Se usa con la funcion synthesizeCode aqui guardamos todos los apuntadores de
	   las cadenas que queremos unir y luego pasamos este arreglo como el primer
	   parametro a la funcion, el segundo parametro es el numero de cadenas que 
	   ingresamos a este arreglo */
	
	char *codeSnippets[50];
	
////// FUNCIONES USADAS EN LAS ACCIONES SEMÁNTICAS DE LA PARTE DE REGLAS DE TRADUCCIÓN //////
	
	////// TABLA DE SIMBOLOS //////

	void printSymbolTable(symbolTable ST[],int posST);
	
	////// TABLAL DE TIPOS //////
	
	void initGlobalTypeTable(typeTable GTT[],int* posTT);
	void printTypeTable(typeTable TT[],int posTT);
	
	////// //////
	
	void yyerror(char *s);
	
	char* synthesizeCode(char* codeSnippets[],int codeSnippetsNum);
	
	char* labelSwitch();
	char* newLabel(int *etiNum);
	char* changeLabel(char *code,char *oldLabel,char *newLabel);
	
	bool isInt(int tipo);
	bool isFloat(int tipo);
	bool isDouble(int tipo);
	
	int getPos(char* tipo,typeTable GTT[],int posTT);
	int getDimWithPosTT(int posTT,typeTable GTT[]);
	
	////// FUNCIONES PARA EL NO TERMINAL S //////
	
	char* switchCode(char* etiquetas[],int numCasos[],char* temp,int indice);
	
	// FUNCIONES PARA EL NO TERMINAL E //
	
	bool isNumero(int eType);
	int maxType(int e1Type,int e2Type);
	int getDim(char* tipo,typeTable GTT[],int posTT);
	bool isEmptyStr(char* s);
	char* changeStr(char* numStr,int originType);
	char* newTempNumero(int* tempNum,int* posST,symbolTable GST[],int eType);
	char* newTempCaracter(int* tempNum,int* posST,symbolTable GST[],int eType);
	char* newTempCadena(int* temp,int* posST,int* posTT,symbolTable GST[],typeTable GTT[],char* cadenaLexema);
		

#line 203 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 138 "yacc.y" /* yacc.c:355  */


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
	

#line 415 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 432 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   268,   268,   271,   274,   277,   282,   328,   331,   334,
     337,   340,   343,   347,   358,   371,   392,   399,   410,   429,
     441,   466,   478,   482,   512,   515,   523,   553,   560,   574,
     581,   613,   645,   677,   709,   741,   746,   769,   782,   793,
     798,   803,   824,   834,   845,   848,   851,   854,   857,   860
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMERO", "CADENA", "CARACTER", "ID",
  "INT", "DOUBLE", "FLOAT", "CHAR", "VOID", "STRUCT", "IF", "ELSE",
  "WHILE", "DO", "FOR", "SWITCH", "RETURN", "BREAK", "CASE", "DEFAULT",
  "TRUE", "FALSE", "FUNC", "PRINT", "LLLVE", "RLLVE", "LCHT", "RCHT",
  "COMA", "PCMA", "PNTS", "ASIG", "PUNTO", "SUM", "RES", "MUL", "DIV",
  "MOD", "LPAR", "RPAR", "MNRQ", "MYRQ", "MNROIQ", "MYROIQ", "DIFRNT",
  "IGUAL", "OR", "AND", "NOT", "$accept", "inicio", "d", "t", "l", "c",
  "s", "j", "k", "e", "b", "r", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF -45

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-45)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      90,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -38,
     -22,    52,   -19,     1,    -2,   -45,   -45,    14,    52,     2,
       2,    44,   -45,    46,   -45,    89,    36,     2,     2,    39,
      37,    52,    14,   -45,   -24,    29,   106,   -15,   -45,   -45,
      34,    33,    14,    14,    14,    14,    14,    14,   -45,   -45,
     -45,   -45,   -45,   -45,    14,     2,     2,    -9,    38,    48,
      63,    82,   -45,   -45,   -45,    93,   -45,   103,   119,   100,
     100,    75,    75,   -45,   119,    80,   -45,    52,    14,     2,
       2,   120,   118,    34,   -45,   119,    62,   -21,   139,    34,
     -45,   129,    52,   159,   141,   -45,   -45,   122,   132,   133,
     140,    52,    52,    52,   -45,   -45,   139,   -45,   -45
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    36,    35,     8,    10,     9,    11,     7,    12,     0,
       0,     0,     0,     0,     0,    42,    43,     0,     0,     0,
       0,     0,     4,     3,     2,     0,     5,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     0,    39,     1,
      16,     6,     0,     0,     0,     0,     0,     0,    44,    45,
      46,    47,    48,    49,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    22,    40,     0,    14,     0,    21,    30,
      31,    32,    33,    34,    41,    37,    38,     0,     0,     0,
       0,     0,     0,    16,    17,    18,     0,     0,    27,    16,
      13,     0,     0,     0,    29,    15,    19,     0,     0,     0,
       0,     0,     0,     0,    23,    20,    27,    28,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -45,   -45,   -45,   -44,   -11,    61,   -45,     4,
     -18,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    21,    22,    23,    41,    66,    24,    94,   100,    30,
      26,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      29,    37,    38,    27,    25,     1,     2,    35,    62,    57,
      58,    92,    43,    44,    45,    46,    47,     1,     2,    28,
      60,    34,    31,    36,    36,    15,    16,    64,    55,    56,
      33,    36,    36,    77,    55,    56,    61,    75,    76,    90,
      55,    56,    32,    19,    39,    95,    68,    69,    70,    71,
      72,    73,    40,    20,    59,     1,     2,    63,    74,    36,
      36,    86,    87,    65,    67,     9,    84,    10,    11,    12,
      13,    42,    14,    43,    44,    45,    46,    47,    17,    18,
      78,    97,    85,    36,    36,    55,    56,    55,    56,    79,
     105,   106,   107,     1,     2,    80,    82,     3,     4,     5,
       6,     7,     8,     9,    91,    10,    11,    12,    13,    83,
      14,    55,    56,    15,    16,    47,    17,    18,    43,    44,
      45,    46,    47,    42,    81,    43,    44,    45,    46,    47,
      56,    19,    48,    49,    50,    51,    52,    53,    45,    46,
      47,    20,    43,    44,    45,    46,    47,    88,    89,    48,
      49,    50,    51,    52,    53,    43,    44,    45,    46,    47,
      93,    96,    98,    99,   101,   102,   103,   108,   104
};

static const yytype_uint8 yycheck[] =
{
      11,    19,    20,    41,     0,     3,     4,    18,    32,    27,
      28,    32,    36,    37,    38,    39,    40,     3,     4,    41,
      31,    17,    41,    19,    20,    23,    24,    42,    49,    50,
      32,    27,    28,    42,    49,    50,    32,    55,    56,    83,
      49,    50,    41,    41,     0,    89,    42,    43,    44,    45,
      46,    47,     6,    51,    15,     3,     4,    28,    54,    55,
      56,    79,    80,    29,    31,    13,    77,    15,    16,    17,
      18,    34,    20,    36,    37,    38,    39,    40,    26,    27,
      42,    92,    78,    79,    80,    49,    50,    49,    50,    41,
     101,   102,   103,     3,     4,    32,     3,     7,     8,     9,
      10,    11,    12,    13,    42,    15,    16,    17,    18,     6,
      20,    49,    50,    23,    24,    40,    26,    27,    36,    37,
      38,    39,    40,    34,    42,    36,    37,    38,    39,    40,
      50,    41,    43,    44,    45,    46,    47,    48,    38,    39,
      40,    51,    36,    37,    38,    39,    40,    27,    30,    43,
      44,    45,    46,    47,    48,    36,    37,    38,    39,    40,
      21,    32,     3,    22,    42,    33,    33,   106,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     7,     8,     9,    10,    11,    12,    13,
      15,    16,    17,    18,    20,    23,    24,    26,    27,    41,
      51,    53,    54,    55,    58,    61,    62,    41,    41,    58,
      61,    41,    41,    32,    61,    58,    61,    62,    62,     0,
       6,    56,    34,    36,    37,    38,    39,    40,    43,    44,
      45,    46,    47,    48,    63,    49,    50,    62,    62,    15,
      58,    61,    32,    28,    42,    29,    57,    31,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    42,    42,    41,
      32,    42,     3,     6,    58,    61,    62,    62,    27,    30,
      57,    42,    32,    21,    59,    57,    32,    58,     3,    22,
      60,    42,    33,    33,    28,    58,    58,    58,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    54,    55,    55,    55,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     4,     2,     4,     0,     5,     5,     7,
       9,     3,     3,     8,     2,     3,     5,     0,     3,     0,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     2,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 268 "yacc.y" /* yacc.c:1646  */
    {
			printf(">>>\n\n%s\n",(yyvsp[0].S).codigo);
		}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 271 "yacc.y" /* yacc.c:1646  */
    {
			printf("El tipo es: %d\n",(yyvsp[0].T).tipo);
		}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 274 "yacc.y" /* yacc.c:1646  */
    {
			
		}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 277 "yacc.y" /* yacc.c:1646  */
    {
			printf("b.trueLabel: %s\nb.falseLabel: %s\n\n",(yyvsp[0].B).trueLabel,(yyvsp[0].B).falseLabel);
			printf(">>>\n\n%s",(yyvsp[0].B).codigo);
		}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 282 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.D).tipo = (yyvsp[-1].T).tipo;
		
		int i;
		
		// Vaciado de informacion de la tabla de tipos embrión a la tabla de tipos global
		
		for(i=0;i<(yyvsp[0].L).elementosETT;i++){
			GTT[ETT[i].posTT].tipo = "array";
			if(ETT[i].tipoBase == -1){
				GTT[ETT[i].posTT].tipoBase = (yyvsp[-1].T).tipo;
			} else {
				GTT[ETT[i].posTT].tipoBase = ETT[i].tipoBase;
			}
			GTT[ETT[i].posTT].dim = ETT[i].dim * getDimWithPosTT((yyvsp[-1].T).tipo,GTT);
		}
		
		// Vaciado de la informacion de la tabla de simbolos embrion a la tabla de simbolos global
		
		for(i=0;i<(yyvsp[0].L).elementosEST;i++){
			GST[EST[i].posST].lexema = EST[i].lexema;
			if(EST[i].tipo == -1){
				GST[EST[i].posST].tipo = (yyvsp[-1].T).tipo;
			} else {
				GST[EST[i].posST].tipo = EST[i].tipo;
			}
			GST[EST[i].posST].tipoVar = "var";
			if(posST[0] > 0){
				GST[EST[i].posST].dir = GST[EST[i].posST-1].dir + getDimWithPosTT(GST[EST[i].posST-1].tipo,GTT);			
			} else {
				GST[EST[i].posST].dir = 0;
			}
			/* Cada que insertamos un elemento en la tabla incrementamos esta variable para que
			   posST siempre almacene la direccion de la tabla de simbolos en donde podemos almacenar
			   un elemeto directamente */
			posST[0] = posST[0] + 1; 
		}
		
		printf("El valor de posST[0]: %d\n",posST[0]);
		printSymbolTable(GST,posST[0]);
		printTypeTable(GTT,posTT);
		printEmbryoSymbolTable(EST,posEST);
		printEmbryoTypeTable(ETT,posETT);
		printf("\n\nelementosEST: %d\nelementosETT : %d\n",(yyvsp[0].L).elementosEST,(yyvsp[0].L).elementosETT);
	}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 328 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.T).tipo = getPos((yyvsp[0].cadena),GTT,posTT); // Busca el tipo en la tabla de tipos dada una cadena ej: "int"
	}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 331 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.T).tipo = getPos((yyvsp[0].cadena),GTT,posTT);
	}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 334 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.T).tipo = getPos((yyvsp[0].cadena),GTT,posTT);
	}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 337 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.T).tipo = getPos((yyvsp[0].cadena),GTT,posTT);
	}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 340 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.T).tipo = getPos((yyvsp[0].cadena),GTT,posTT);
	}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 343 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.T).tipo = getPos((yyvsp[0].cadena),GTT,posTT);
	}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 347 "yacc.y" /* yacc.c:1646  */
    {
		if(!(yyvsp[0].C).isArray){// si no es un arreglo
			insertIntoEmbryoSymbolTable(&posEST,&posSTAux,(yyvsp[-1].cadena),-1,EST);
			(yyval.L).elementosEST = (yyvsp[-3].L).elementosEST + 1;
			(yyval.L).elementosETT = (yyvsp[-3].L).elementosETT + (yyvsp[0].C).elementosETT;
		} else { // si es un arreglo
			insertIntoEmbryoSymbolTable(&posEST,&posSTAux,(yyvsp[-1].cadena),(yyvsp[0].C).tipoBase,EST);
			(yyval.L).elementosEST = (yyvsp[-3].L).elementosEST + 1;
			(yyval.L).elementosETT = (yyvsp[-3].L).elementosETT + (yyvsp[0].C).elementosETT;
		}
	}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 358 "yacc.y" /* yacc.c:1646  */
    {
		posSTAux = posST[0];
		if(!(yyvsp[0].C).isArray){// si no es un arreglo
			insertIntoEmbryoSymbolTable(&posEST,&posSTAux,(yyvsp[-1].cadena),-1,EST);
			(yyval.L).elementosEST = 1;
			(yyval.L).elementosETT = 0;
		} else { // si es un arreglo
			insertIntoEmbryoSymbolTable(&posEST,&posSTAux,(yyvsp[-1].cadena),(yyvsp[0].C).tipoBase,EST);
			(yyval.L).elementosEST = 1;
			(yyval.L).elementosETT = (yyvsp[0].C).elementosETT;
		}
	}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 371 "yacc.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].numero).tipo == 1){// si NUMERO es un entero
			(yyval.C).isArray = 1; // igual a true
			if((yyvsp[0].C).isUltimo){ // si es último
				(yyval.C).isUltimo = 0; // igual a false
				inserIntoEmbryoTypeTable(&posETT,&posTT,-1,(yyvsp[-2].numero).ival,ETT);
				(yyval.C).dim = (yyvsp[-2].numero).ival;
				(yyval.C).tipoBase = posTT - 1;
				(yyval.C).elementosETT = 1;
			} else { // si no es último
				(yyval.C).isUltimo = 0; // igual a false
				inserIntoEmbryoTypeTable(&posETT,&posTT,(yyvsp[0].C).tipoBase,(yyvsp[0].C).dim*(yyvsp[-2].numero).ival,ETT);
				(yyval.C).tipoBase = (yyvsp[0].C).tipoBase + 1;
				(yyval.C).dim = (yyvsp[0].C).dim*(yyvsp[-2].numero).ival;
				(yyval.C).elementosETT = (yyvsp[0].C).elementosETT + 1;
			}
		} else {
			yyerror("semantic error::\nLos indices de los arreglos deben ser numeros enteros");
			exit(1);
		}
	}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 392 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.C).isArray = 0; // igual a false
		(yyval.C).isUltimo = 1; // igual a true
		(yyval.C).tipoBase = 0; // No se usa solo se inicializa
		(yyval.C).dim = 0; // No se usa solo se inicializa
	}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 399 "yacc.y" /* yacc.c:1646  */
    {
		codeSnippets[0] = (yyvsp[-2].B).codigo;
		codeSnippets[1] = (yyvsp[-2].B).trueLabel;
		codeSnippets[2] = ":\n"; 
		codeSnippets[3] = (yyvsp[0].S).codigo;
		codeSnippets[4] = (yyvsp[-2].B).falseLabel;
		codeSnippets[5] = ":\n"; 
		
		(yyval.S).codigo = synthesizeCode(codeSnippets,6);
		(yyval.S).next = (yyvsp[-2].B).falseLabel;
	}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 410 "yacc.y" /* yacc.c:1646  */
    {
		char *w;
		w = newLabel(&etiNum);
		
		codeSnippets[0] = w;
		codeSnippets[1] = ":\n";
		codeSnippets[2] = (yyvsp[-2].B).codigo;
		codeSnippets[3] = (yyvsp[-2].B).trueLabel;
		codeSnippets[4] = ":\n";
		codeSnippets[5] = (yyvsp[0].E).codigo;
		codeSnippets[6] = "GOTO ";
		codeSnippets[7] = w;
		codeSnippets[8] = "\n";
		codeSnippets[9] = (yyvsp[-2].B).falseLabel;
		codeSnippets[10] = ":\n";
		
		(yyval.S).codigo = synthesizeCode(codeSnippets,11);
		(yyval.S).next = (yyvsp[-2].B).falseLabel;
	}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 429 "yacc.y" /* yacc.c:1646  */
    {
		
		codeSnippets[0] = (yyvsp[-2].B).trueLabel;
		codeSnippets[1] = ":\n";
		codeSnippets[2] = (yyvsp[-5].S).codigo;
		codeSnippets[3] = (yyvsp[-2].B).codigo;
		codeSnippets[4] = (yyvsp[-2].B).falseLabel;
		codeSnippets[5] = ":\n";
		
		(yyval.S).codigo = synthesizeCode(codeSnippets,6);
		(yyval.S).next = (yyvsp[-2].B).falseLabel;
	}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 441 "yacc.y" /* yacc.c:1646  */
    {
		
		char *w;
		
		w = newLabel(&etiNum);
		
		codeSnippets[0] = (yyvsp[-6].S).codigo;
		codeSnippets[1] = w;
		codeSnippets[2] = ":\n";
		codeSnippets[3] = (yyvsp[-4].B).codigo;
		codeSnippets[4] = (yyvsp[-4].B).trueLabel;
		codeSnippets[5] = ":\n";
		codeSnippets[6] = (yyvsp[0].S).codigo;
		codeSnippets[7] = (yyvsp[-2].S).codigo;
		codeSnippets[8] = "GOTO ";
		codeSnippets[9] = w;
		codeSnippets[10] = "\n";
		codeSnippets[11] = (yyvsp[-4].B).falseLabel;
		codeSnippets[12] = ":\n";
		
		(yyval.S).next = (yyvsp[-4].B).falseLabel;
		(yyval.S).codigo = synthesizeCode(codeSnippets,13);
		
	
	}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 466 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.S).next = newLabel(&etiNum);
		
		codeSnippets[0] = (yyvsp[-2].E).codigo;
		codeSnippets[1] = (yyvsp[0].E).codigo;
		codeSnippets[2] = (yyvsp[-2].E).temp;
		codeSnippets[3] = " = ";
		codeSnippets[4] = (yyvsp[0].E).temp;
		codeSnippets[5] = "\n";
		
		(yyval.S).codigo = synthesizeCode(codeSnippets,6);
	}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 478 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.S).next = (yyvsp[-1].S).next;
		(yyval.S).codigo = (yyvsp[-1].S).codigo;
	}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 482 "yacc.y" /* yacc.c:1646  */
    {
		
		(yyval.S).next = newLabel(&etiNum);
		
		if((yyvsp[-2].J).indice == -1 && strcmp((yyvsp[-1].K).codigo,"") == 0){
			(yyval.S).codigo = "";
		} else {
			codeSnippets[0] = (yyvsp[-5].E).codigo;
			codeSnippets[1] = switchCode((yyvsp[-2].J).etiquetas,(yyvsp[-2].J).numCasos,(yyvsp[-5].E).temp,(yyvsp[-2].J).indice);
			if(strcmp((yyvsp[-1].K).codigo,"") == 0){
				codeSnippets[2] = "";
				codeSnippets[3] = "";
				codeSnippets[4] = "";
			} else {
			
				codeSnippets[2] = "GOTO ";
				codeSnippets[3] = (yyvsp[-1].K).etiqueta;
				codeSnippets[4] = "\n";
			}
			codeSnippets[5] = "GOTO ";
			codeSnippets[6] = (yyval.S).next;
			codeSnippets[7] = "\n";
			codeSnippets[8] = changeLabel((yyvsp[-2].J).codigo,(yyvsp[-2].J).next,(yyval.S).next);
			codeSnippets[9] = changeLabel((yyvsp[-1].K).codigo,(yyvsp[-1].K).next,(yyval.S).next);
			codeSnippets[10] = (yyval.S).next;
			codeSnippets[11] = ":\n";
		
			(yyval.S).codigo = synthesizeCode(codeSnippets,12);
		}
	}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 512 "yacc.y" /* yacc.c:1646  */
    { // S -> break;
		(yyval.S).codigo = "";
	}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 515 "yacc.y" /* yacc.c:1646  */
    {
		codeSnippets[0] = "PARAM ";
		codeSnippets[1] = (yyvsp[-1].E).temp;
		codeSnippets[2] = "\nCALL print,1\n";
		
		(yyval.S).codigo = synthesizeCode(codeSnippets,3);
	}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 523 "yacc.y" /* yacc.c:1646  */
    {
		int i;
		(yyval.J).next = (yyvsp[0].J).next;
		(yyval.J).indice = (yyvsp[0].J).indice + 1;
		
		for(i=0;i<(yyval.J).indice;i++){
			(yyval.J).etiquetas[i] = (yyvsp[0].J).etiquetas[i];
			(yyval.J).numCasos[i] = (yyvsp[0].J).numCasos[i];
		}
		
		(yyval.J).etiquetas[(yyval.J).indice] = newLabel(&etiNum);
		
		if (isInt((yyvsp[-3].numero).tipo)) {
			(yyval.J).numCasos[(yyval.J).indice] = (yyvsp[-3].numero).ival;
		} else {
			yyerror("Los numeros en los case deben ser enteros");
			exit(1);
		}
		
		codeSnippets[0] = (yyval.J).etiquetas[(yyval.J).indice];
		codeSnippets[1] = ":\n";
		codeSnippets[2] = (yyvsp[-1].S).codigo;
		codeSnippets[3] = "GOTO ";
		codeSnippets[4] = (yyval.J).next;
		codeSnippets[5] = "\n";
		codeSnippets[6] = (yyvsp[0].J).codigo;
		
		(yyval.J).codigo = synthesizeCode(codeSnippets,7);
		
	}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 553 "yacc.y" /* yacc.c:1646  */
    {
		// J -> ε
		(yyval.J).next = newLabel(&etiNum);
		(yyval.J).indice = -1; // Para que el indice en la produccion anterior se inicie en 0
		(yyval.J).codigo = ""; // El codigo debe ser cadena vacia para que no marque error "Violacion de Segmento"
	}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 560 "yacc.y" /* yacc.c:1646  */
    {
		// K -> default: S
		(yyval.K).next = newLabel(&etiNum);
		(yyval.K).etiqueta = newLabel(&etiNum);
		
		codeSnippets[0] = (yyval.K).etiqueta;
		codeSnippets[1] = ":\n";
		codeSnippets[2] = (yyvsp[0].S).codigo; // S.codigo
		codeSnippets[3] = "GOTO ";
		codeSnippets[4] = (yyval.K).next;
		codeSnippets[5] = "\n";
		
		(yyval.K).codigo = synthesizeCode(codeSnippets,6);
	}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 574 "yacc.y" /* yacc.c:1646  */
    {
		// K -> ε
		(yyval.K).next = newLabel(&etiNum);
		(yyval.K).etiqueta = newLabel(&etiNum);
		(yyval.K).codigo = "";
	}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 581 "yacc.y" /* yacc.c:1646  */
    {
			if(isNumero((yyvsp[-2].E).tipo) && isNumero((yyvsp[0].E).tipo)){
				(yyval.E).tipo = maxType((yyvsp[-2].E).tipo,(yyvsp[0].E).tipo);
				(yyval.E).temp = newTempNumero(&tempNum,&posST[0],GST,(yyval.E).tipo);
			
				codeSnippets[0] = (yyvsp[-2].E).codigo;
				codeSnippets[1] = (yyvsp[0].E).codigo;
				codeSnippets[2] = (yyval.E).temp;
				codeSnippets[3] = " = ";
			
				if(isEmptyStr((yyvsp[-2].E).codigo) && ((yyvsp[-2].E).tipo != (yyval.E).tipo)){
					codeSnippets[4] = changeStr((yyvsp[-2].E).temp,(yyvsp[-2].E).tipo);
				} else {
					codeSnippets[4] = (yyvsp[-2].E).temp;
				}
	
				codeSnippets[5] = " + ";
	
				if(isEmptyStr((yyvsp[0].E).codigo) && ((yyvsp[0].E).tipo != (yyval.E).tipo)){
					codeSnippets[6] = changeStr((yyvsp[0].E).temp,(yyvsp[0].E).tipo);
				} else {
					codeSnippets[6] = (yyvsp[0].E).temp;
				}
			
				codeSnippets[7] = "\n";
				
				(yyval.E).codigo = synthesizeCode(codeSnippets,8);
			} else {
				yyerror("Alguno de los operandos no es un número");
				exit(1);
			}
	}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 613 "yacc.y" /* yacc.c:1646  */
    {
		if(isNumero((yyvsp[-2].E).tipo) && isNumero((yyvsp[0].E).tipo)){
				(yyval.E).tipo = maxType((yyvsp[-2].E).tipo,(yyvsp[0].E).tipo);
				(yyval.E).temp = newTempNumero(&tempNum,&posST[0],GST,(yyval.E).tipo);
			
				codeSnippets[0] = (yyvsp[-2].E).codigo;
				codeSnippets[1] = (yyvsp[0].E).codigo;
				codeSnippets[2] = (yyval.E).temp;
				codeSnippets[3] = " = ";
			
				if(isEmptyStr((yyvsp[-2].E).codigo) && ((yyvsp[-2].E).tipo != (yyval.E).tipo)){
					codeSnippets[4] = changeStr((yyvsp[-2].E).temp,(yyvsp[-2].E).tipo);
				} else {
					codeSnippets[4] = (yyvsp[-2].E).temp;
				}
	
				codeSnippets[5] = " - ";
	
				if(isEmptyStr((yyvsp[0].E).codigo) && ((yyvsp[0].E).tipo != (yyval.E).tipo)){
					codeSnippets[6] = changeStr((yyvsp[0].E).temp,(yyvsp[0].E).tipo);
				} else {
					codeSnippets[6] = (yyvsp[0].E).temp;
				}
			
				codeSnippets[7] = "\n";
				
				(yyval.E).codigo = synthesizeCode(codeSnippets,8);
			} else {
				yyerror("Alguno de los operandos no es un número");
				exit(1);
			}
	}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 645 "yacc.y" /* yacc.c:1646  */
    {
		if(isNumero((yyvsp[-2].E).tipo) && isNumero((yyvsp[0].E).tipo)){
				(yyval.E).tipo = maxType((yyvsp[-2].E).tipo,(yyvsp[0].E).tipo);
				(yyval.E).temp = newTempNumero(&tempNum,&posST[0],GST,(yyval.E).tipo);
			
				codeSnippets[0] = (yyvsp[-2].E).codigo;
				codeSnippets[1] = (yyvsp[0].E).codigo;
				codeSnippets[2] = (yyval.E).temp;
				codeSnippets[3] = " = ";
			
				if(isEmptyStr((yyvsp[-2].E).codigo) && ((yyvsp[-2].E).tipo != (yyval.E).tipo)){
					codeSnippets[4] = changeStr((yyvsp[-2].E).temp,(yyvsp[-2].E).tipo);
				} else {
					codeSnippets[4] = (yyvsp[-2].E).temp;
				}
	
				codeSnippets[5] = " * ";
	
				if(isEmptyStr((yyvsp[0].E).codigo) && ((yyvsp[0].E).tipo != (yyval.E).tipo)){
					codeSnippets[6] = changeStr((yyvsp[0].E).temp,(yyvsp[0].E).tipo);
				} else {
					codeSnippets[6] = (yyvsp[0].E).temp;
				}
			
				codeSnippets[7] = "\n";
				
				(yyval.E).codigo = synthesizeCode(codeSnippets,8);
			} else {
				yyerror("Alguno de los operandos no es un número");
				exit(1);
			}
	}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 677 "yacc.y" /* yacc.c:1646  */
    {
		if(isNumero((yyvsp[-2].E).tipo) && isNumero((yyvsp[0].E).tipo)){
				(yyval.E).tipo = maxType((yyvsp[-2].E).tipo,(yyvsp[0].E).tipo);
				(yyval.E).temp = newTempNumero(&tempNum,&posST[0],GST,(yyval.E).tipo);
			
				codeSnippets[0] = (yyvsp[-2].E).codigo;
				codeSnippets[1] = (yyvsp[0].E).codigo;
				codeSnippets[2] = (yyval.E).temp;
				codeSnippets[3] = " = ";
			
				if(isEmptyStr((yyvsp[-2].E).codigo) && ((yyvsp[-2].E).tipo != (yyval.E).tipo)){
					codeSnippets[4] = changeStr((yyvsp[-2].E).temp,(yyvsp[-2].E).tipo);
				} else {
					codeSnippets[4] = (yyvsp[-2].E).temp;
				}
	
				codeSnippets[5] = " / ";
	
				if(isEmptyStr((yyvsp[0].E).codigo) && ((yyvsp[0].E).tipo != (yyval.E).tipo)){
					codeSnippets[6] = changeStr((yyvsp[0].E).temp,(yyvsp[0].E).tipo);
				} else {
					codeSnippets[6] = (yyvsp[0].E).temp;
				}
			
				codeSnippets[7] = "\n";
				
				(yyval.E).codigo = synthesizeCode(codeSnippets,8);
			} else {
				yyerror("Alguno de los operandos no es un número");
				exit(1);
			}
	}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 709 "yacc.y" /* yacc.c:1646  */
    {
		if(isNumero((yyvsp[-2].E).tipo) && isNumero((yyvsp[0].E).tipo)){
				(yyval.E).tipo = maxType((yyvsp[-2].E).tipo,(yyvsp[0].E).tipo);
				(yyval.E).temp = newTempNumero(&tempNum,&posST[0],GST,(yyval.E).tipo);
			
				codeSnippets[0] = (yyvsp[-2].E).codigo;
				codeSnippets[1] = (yyvsp[0].E).codigo;
				codeSnippets[2] = (yyval.E).temp;
				codeSnippets[3] = " = ";
			
				if(isEmptyStr((yyvsp[-2].E).codigo) && ((yyvsp[-2].E).tipo != (yyval.E).tipo)){
					codeSnippets[4] = changeStr((yyvsp[-2].E).temp,(yyvsp[-2].E).tipo);
				} else {
					codeSnippets[4] = (yyvsp[-2].E).temp;
				}
	
				codeSnippets[5] = " % ";
	
				if(isEmptyStr((yyvsp[0].E).codigo) && ((yyvsp[0].E).tipo != (yyval.E).tipo)){
					codeSnippets[6] = changeStr((yyvsp[0].E).temp,(yyvsp[0].E).tipo);
				} else {
					codeSnippets[6] = (yyvsp[0].E).temp;
				}
			
				codeSnippets[7] = "\n";
				
				(yyval.E).codigo = synthesizeCode(codeSnippets,8);
			} else {
				yyerror("Alguno de los operandos no es un número");
				exit(1);
			}
	}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 741 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.E).tipo = 4;
		(yyval.E).temp = newTempCadena(&tempNum,&posST[0],&posTT,GST,GTT,(yyvsp[0].cadena));
		(yyval.E).codigo = (yyvsp[0].cadena);
	}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 746 "yacc.y" /* yacc.c:1646  */
    {
		int i;
		char *s,buffer[30];
		for(i=0;i<30;i++) { buffer[i] = 0; }
		
		(yyval.E).tipo = (yyvsp[0].numero).tipo;
		
		if( isInt((yyvsp[0].numero).tipo) ){
			sprintf(buffer,"%d",(yyvsp[0].numero).ival);
		} else if( isFloat((yyvsp[0].numero).tipo) ){
			sprintf(buffer,"%.2f",(yyvsp[0].numero).fval);
		} else if( isDouble((yyvsp[0].numero).tipo) ) {
			sprintf(buffer,"%.2f",(yyvsp[0].numero).dval);
		}
		
		s = (char*) malloc(sizeof(char)*(strlen(buffer)+1));
		strcpy(s,buffer);
		
		(yyval.E).temp = s;
		(yyval.E).codigo = "";
	
	}
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 769 "yacc.y" /* yacc.c:1646  */
    {
		char *s,*w;
	
		(yyval.B).trueLabel = newLabel(&etiNum);
		(yyval.B).falseLabel = (yyvsp[0].B).falseLabel;
		
		codeSnippets[0] = changeLabel((yyvsp[-2].B).codigo,(yyvsp[-2].B).trueLabel,(yyval.B).trueLabel);
		codeSnippets[1] = (yyvsp[-2].B).falseLabel;
		codeSnippets[2] = ":\n";
		codeSnippets[3] = changeLabel((yyvsp[0].B).codigo,(yyvsp[0].B).trueLabel,(yyval.B).trueLabel);

		(yyval.B).codigo = synthesizeCode(codeSnippets,4);
	}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 782 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.B).trueLabel = (yyvsp[0].B).trueLabel;
		(yyval.B).falseLabel = newLabel(&etiNum);
		
		codeSnippets[0] = changeLabel((yyvsp[-2].B).codigo,(yyvsp[-2].B).falseLabel,(yyval.B).falseLabel);
		codeSnippets[1] = (yyvsp[-2].B).trueLabel;
		codeSnippets[2] = ":\n";
		codeSnippets[3] = changeLabel((yyvsp[0].B).codigo,(yyvsp[0].B).falseLabel,(yyval.B).falseLabel);
		
		(yyval.B).codigo = synthesizeCode(codeSnippets,4);		
	}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 793 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.B).trueLabel = (yyvsp[0].B).falseLabel;
		(yyval.B).falseLabel = (yyvsp[0].B).trueLabel;
		(yyval.B).codigo = (yyvsp[0].B).codigo;
	}
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 798 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.B).trueLabel = (yyvsp[-1].B).trueLabel;
		(yyval.B).falseLabel = (yyvsp[-1].B).falseLabel;
		(yyval.B).codigo = (yyvsp[-1].B).codigo;
	}
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 803 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.B).trueLabel = newLabel(&etiNum);
		(yyval.B).falseLabel = newLabel(&etiNum);
		
		codeSnippets[0] = (yyvsp[-2].E).codigo;
		codeSnippets[1] = (yyvsp[0].E).codigo;
		codeSnippets[2] = "IF ";
		codeSnippets[3] = (yyvsp[-2].E).temp;
		codeSnippets[4] = " ";
		codeSnippets[5] = (yyvsp[-1].R).codigo;
		codeSnippets[6] = " ";
		codeSnippets[7] = (yyvsp[0].E).temp;
		codeSnippets[8] = " GOTO ";
		codeSnippets[9] = (yyval.B).trueLabel;
		codeSnippets[10] = "\n";
		codeSnippets[11] = "GOTO ";
		codeSnippets[12] = (yyval.B).falseLabel;
		codeSnippets[13] = "\n";
		
		(yyval.B).codigo = synthesizeCode(codeSnippets,14);
	}
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 824 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.B).trueLabel = newLabel(&etiNum);
		(yyval.B).falseLabel = newLabel(&etiNum);
		
		codeSnippets[0] = "GOTO ";
		codeSnippets[1] = (yyval.B).trueLabel;
		codeSnippets[2] = "\n";
		
		(yyval.B).codigo = synthesizeCode(codeSnippets,3);
	}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 834 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.B).trueLabel = newLabel(&etiNum);
		(yyval.B).falseLabel = newLabel(&etiNum);
		
		codeSnippets[0] = "GOTO ";
		codeSnippets[1] = (yyval.B).falseLabel;
		codeSnippets[2] = "\n";
		
		(yyval.B).codigo = synthesizeCode(codeSnippets,3);
	}
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 845 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.R).codigo = "<";
	}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 848 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.R).codigo = ">";
	}
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 851 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.R).codigo = "<=";
	}
#line 2384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 854 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.R).codigo = ">=";
	}
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 857 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.R).codigo = "!=";
	}
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 860 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.R).codigo = "==";
	}
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2412 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  return yyresult;
}
#line 864 "yacc.y" /* yacc.c:1906  */



extern FILE *yyin;
extern int yylineno;

int main(int argc,char **argv){
	if(argc > 1){
		yyin = fopen(argv[1],"r");	
	}
////// INICIALIZACIONES //////
	posST[0] = 0;
	initGlobalTypeTable(GTT,&posTT);
	
	yyparse();
	return 0;
}

// MIS FUNCIONES

void yyerror(char *s){
	printf("%s::line:%d\n",s,yylineno-1);
}

////// TABLA DE SIMBOLOS //////

void printSymbolTable(symbolTable ST[],int posST){
	int i;
	printf("\npos\tlexema\ttipo\ttipoVar\tdir\n\n");
	for(i=0;i<posST;i++){
		printf("%d\t%s\t%d\t%s\t%d\n",i,ST[i].lexema,ST[i].tipo,ST[i].tipoVar,ST[i].dir);	
	}		
}

////// TABLA DE TIPOS //////


void initGlobalTypeTable(typeTable GTT[],int* posTT){
//void
	GTT[0].tipo = "void";
	GTT[0].tipoBase = -1;
	GTT[0].dim = -1;
// int
	GTT[1].tipo = "int";
	GTT[1].tipoBase = -1;
	GTT[1].dim = 4;
// float
	GTT[2].tipo = "float";
	GTT[2].tipoBase = -1;
	GTT[2].dim = 8;
// double
	GTT[3].tipo = "double";
	GTT[3].tipoBase = -1;
	GTT[3].dim = 8;
// char
	GTT[4].tipo = "char";
	GTT[4].tipoBase = -1;
	GTT[4].dim = 1;
	
	*posTT = 5;
}

void printTypeTable(typeTable TT[],int posTT){
	int i;
	printf("\npos\ttipo\ttipoBase\tdim\n\n");
	for(i=0;i<posTT;i++){
		printf("%d\t%s\t  %d\t\t%d\n",i,TT[i].tipo,TT[i].tipoBase,TT[i].dim);	
	}		
}

////// //////

char* synthesizeCode(char* codeSnippets[],int codeSnippetsNum){
	int length = 0,i;
	char *s, buffer[100000];
	
	for(i=0;i<100000;i++) {
		buffer[i] = '\0';
	}
	
	for(i=0;i<codeSnippetsNum;i++){
		length = length + strlen(codeSnippets[i]);
		strcat(buffer,codeSnippets[i]);
	}
	
	s = (char*) malloc(sizeof(char)*(length +1));
	
	strcpy(s,buffer);
	
	return s;
}

char* labelSwitch(){
	char *s,*b;
	b = "GOTO siguente";
	s = (char*) malloc(sizeof(char)*10);
	strcpy(s,b);
	return s;	
}

char* newLabel(int *etiNum){
	char buffer[50];
	sprintf(buffer,"ETI%d",*etiNum);
	char* label;
	label = (char*) malloc(sizeof(char)*(strlen(buffer)+1));
	strcpy(label,buffer);
	*etiNum = *etiNum + 1;
	return label;
}

char* changeLabel(char *code,char *oldLabel,char *newLabel){
	char buffer[1000] = {0},*s,*sentinel,*x;
	int snippet;
	
	s = code;
	
	sentinel = strstr(s,oldLabel);
	
	if(sentinel == NULL){
		x = (char*) malloc(sizeof(char)*(strlen(s) + 1));
		strcpy(x,s);
		return x;
	} else {
		do{
			snippet = sentinel - s;
	
			strncat(buffer,s,snippet);
			strcat(buffer,newLabel);
			
			s = s + snippet + strlen(oldLabel);
			
			sentinel = strstr(s,oldLabel);
	
		}while(sentinel);
		
		strcat(buffer,s);
		
		x  = (char*) malloc(sizeof(char)*(strlen(buffer) + 1));
		strcpy(x,buffer);
		return x;	
	}
}


bool isInt(int tipo) {
	if(tipo == 1)
		return true;
	else
		return false;
}

bool isFloat(int tipo) {
	if(tipo == 2)
		return true;
	else
		return false;
}

bool isDouble(int tipo) {
	if(tipo == 3)
		return true;
	else
		return false;
}

////// FUNCIONES PARA EL NO TERMINAL S //////

char* switchCode(char* etiquetas[],int numCasos[],char* temp,int indice){
	char *s,*x,buffer[10000] = {0},num[100] = {0};
	int i;
	for(i=0;i<=indice;i++){
		sprintf(num,"%d ",numCasos[i]);
		x = (char*) malloc(sizeof(char)*(strlen(num) +1));
		strcpy(x,num);
		strcat(buffer,"IF ");
		strcat(buffer,temp);
		strcat(buffer," == ");
		strcat(buffer,x);
		strcat(buffer,"GOTO ");
		strcat(buffer,etiquetas[i]);
		strcat(buffer,"\n");
	}
	
	s = (char*) malloc(sizeof(char)*(strlen(buffer) + 1));
	
	strcpy(s,buffer);
	
	return s;
}

////// FUNCIONES PARA EL NO TERMINAL E //////


bool isNumero(int eType){
	if(eType == 1 || eType == 2 || eType == 3)
		return true;
	else
		return false;
}

int maxType(int e1Type,int e2Type){
	if(e1Type >= e2Type)
		return e1Type;
	else
		return e2Type;
}

int getDim(char* tipo,typeTable GTT[],int posTT){
	int i;
	for(i=0;i<posTT;i++){
		if(strcmp(tipo,GTT[i].tipo) == 0)
			return GTT[i].dim;
	}
	return -1;
}

/* Retorna la posicion de la tabla de tipos en donde la cadena que se pasa como argumento
   y la cadena tipo de la tabla de tipos coinciden (la posicion en la tabla de tipos hace
   alucion a el tipo de la variable en si. por ejemplo la posicion 1 es el tipo int si en 
   la tabla de simbolos alguna variable tiene en su campo tipo 1 significa que es de tipo
   int y ya con ese valor se puede obtener informacion en la tabla de tipos posicion 1) */

int getPos(char* tipo,typeTable GTT[],int posTT){
	int i;
	for(i=0;i<posTT;i++){
		if(strcmp(tipo,GTT[i].tipo) == 0)
			return i;
	}
	return -1;
}

int getDimWithPosTT(int posTT,typeTable GTT[]){
	return GTT[posTT].dim;
}

bool isEmptyStr(char* s){
	int n;
	n = strcmp(s,"");
	if (n == 0)
		return true;
	else
		return false;
}

char* changeStr(char* numStr,int originType){
	int i;
	char *s,buffer[30];	
	
	for(i=0;i<30;i++) { buffer[i] = 0; }
	
	if(originType == 1){
		sprintf(buffer,"%s.0",numStr);
		s = (char*) malloc(sizeof(char)*(strlen(buffer)+1));
		strcpy(s,buffer);
		return s;
	} else {
		return numStr;
	}
	
	return s;
}

char* newTempNumero(int* tempNum,int* posST,symbolTable GST[],int eType){
	int i = 0;
	char buffer[30];
	char *s;
	
	for(i=0;i<30;i++) { buffer[i] = 0; } // Limpiamos el buffer
	
	if(eType == 1){
		sprintf(buffer,"t%d",*tempNum);
		s = (char*) malloc(sizeof(char)*(strlen(buffer) + 1));
		strcpy(s,buffer);
		GST[*posST].lexema = s;
		GST[*posST].tipo = 1;
		GST[*posST].tipoVar = "temp";
		if(*posST > 0)
			GST[*posST].dir = GST[*posST-1].dir + 4;
		else
			GST[*posST].dir = 0;			
	} else if(eType == 2){
		sprintf(buffer,"t%d",*tempNum);
		s = (char*) malloc(sizeof(char)*(strlen(buffer) + 1));
		strcpy(s,buffer);
		GST[*posST].lexema = s;
		GST[*posST].tipo = 2;
		GST[*posST].tipoVar = "temp";
		if(*posST > 0)
			GST[*posST].dir = GST[*posST-1].dir + 8;
		else
			GST[*posST].dir = 0;	
	} else if(eType == 3){
		sprintf(buffer,"t%d",*tempNum);
		s = (char*) malloc(sizeof(char)*(strlen(buffer) + 1));
		strcpy(s,buffer);
		GST[*posST].lexema = s;
		GST[*posST].tipo = 3;
		GST[*posST].tipoVar = "temp";
		if(*posST > 0)
			GST[*posST].dir = GST[*posST-1].dir + 8;
		else
			GST[*posST].dir = 0;	
	}
	
	*posST = *posST + 1;
	*tempNum = *tempNum + 1;
	
	return s;
}

char* newTempCaracter(int* tempNum,int* posST,symbolTable GST[],int eType){
	int i = 0;
	char buffer[30];
	char *s;
	
	for(i=0;i<30;i++) { buffer[i] = 0; } // Limpiamos el buffer
	
	sprintf(buffer,"t%d",*tempNum);
	s = (char*) malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(s,buffer);
	GST[*posST].lexema = s;
	GST[*posST].tipo = 4;
	GST[*posST].tipoVar = "temp";
	if(*posST > 0)
		GST[*posST].dir = GST[*posST-1].dir + 1;
	else
		GST[*posST].dir = 0;
		
	*posST = *posST + 1;
	*tempNum = *tempNum + 1;
	
	return s;
}

/* Coloca en la tabla de tipos la informacion sobre la cadena (tipo "array",tipoBase "4",dim strlen(cadenaLexema))
   una vez hecho eso coloca en la tabla de simbolos global una nueva temporal ocupando el espacio de la longitud
   de la cadena y coloca como tipo el que se definio anteriormente en la tabla de tipos, finalmente regresa un
   apuntador a cadena que apunta a la nueva etiquera que se acaba de definir */

char* newTempCadena(int* tempNum,int* posST,int* posTT,symbolTable GST[],typeTable GTT[],char* cadenaLexema){
	int i = 0;
	char buffer[30];
	char *s;
	
	for(i=0;i<30;i++) { buffer[i] = 0; } // Limpiamos el buffer
	
	// Tabla de Tipos
	
	GTT[*posTT].tipo = "array";
	GTT[*posTT].tipoBase = 4;
	GTT[*posTT].dim = (int) strlen(cadenaLexema);
	
	// Tabla de Simbolos
	
	sprintf(buffer,"t%d",*tempNum);
	s = (char*) malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(s,buffer);
	GST[*posST].lexema = s;
	GST[*posST].tipo = *posTT;
	GST[*posST].tipoVar = "tempStr";
	if(*posST > 0)
		GST[*posST].dir = GST[*posST-1].dir + GTT[*posTT].dim;
	else
		GST[*posST].dir = 0;
	
	// Preparo variables de posicion de las tablas y contador de temporales para su nuevo uso
	
	*posST = *posST + 1;
	*posTT = *posTT + 1;
	*tempNum = *tempNum + 1;
	
	return s;
}

////// FUNCIONES PARA LA TABLA DE SIMBOLOS EMBRIÓN //////


/* Esta funcion recibe como parametros todos los elementos que tiene un miembro del tipo embryoST
   lo que va a hacer es una insertar esos elementos en la posicion que corresponda de la tabla
   EST[] */

void insertIntoEmbryoSymbolTable(int *posEST,int *posST,char *lexema,int type,embryoST EST[]){
	EST[*posEST].posST = *posST;
	EST[*posEST].lexema = lexema;
	EST[*posEST].tipo = type;
	
	*posEST = *posEST + 1;
	*posST = *posST + 1; 
}

void printEmbryoSymbolTable(embryoST EST[],int posEST){
	int i;
	printf("\nposEST\tposTS\tlexema\ttipo\n\n");
	for(i=0;i<posEST;i++){
		printf("%d\t%d\t%s\t%d\n",i,EST[i].posST,EST[i].lexema,EST[i].tipo);
	}
	printf("\n");
}

////// FUNCIONES PARA LA TABLA DE TIPOS EMBRIÓN //////

void inserIntoEmbryoTypeTable(int *posETT,int *posTT,int baseType,int dim,embryoTT ETT[]){
	ETT[*posETT].posTT = *posTT;
	ETT[*posETT].tipoBase = baseType;
	ETT[*posETT].dim = dim;
	
	*posETT = *posETT + 1;
	*posTT = *posTT + 1;
}

void printEmbryoTypeTable(embryoTT ETT[],int posETT){
	int i;
	printf("\nposETT\tposTT\ttipoBase\tdim\n\n");
	for(i=0;i<posETT;i++){
		printf("%d\t%d\t%d\t\t%d\n",i,ETT[i].posTT,ETT[i].tipoBase,ETT[i].dim);
	}
}




