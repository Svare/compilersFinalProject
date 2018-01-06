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

/*Con esto evito el warning: implicit declaration of function ‘yylex’ [-Wimplicit-function-declaration]
       yychar = yylex ();
                ^         */
	extern int yylex (void);

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//^^^^^ TABLA DE SIMBOLOS ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

	typedef struct {
		char *lexema;
		int tipo;
		char *tipoVar;
		int dir;
	}symbolTable;
	
	// Capacidad para 50 tablas de simbolos todas de hasta 1000 elementos
	
	symbolTable ST[50][1000];
	
	// Para indexar esta tabla de simbolos
	
	int posST = 0; // Me dice en que tabla estoy
	int symNum[50] = {0}; // En que simbolo estoy dada una tabla (symNum[posST])
	
	// FUNCIONES
	
	void printSymbolTable(symbolTable ST[][1000],int posST,int symNum[]);
	void insertIntoST(int posST,int *symNum,char *lexeme,int type,char *varType,int dir,symbolTable ST[][1000]);
	
	int posSTT[5];         /*BORRAR*/
	symbolTable GST[10];   /*BORRAR*/
	
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//^^^^^ TABLA DE TIPOS ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

	typedef struct {
		char *tipo;
		int tipoBase;
		int dim;
	}typeTable;
	
	// Capacidad para 50 tablas de tipos todas de hasta 1000 elementos
	
	typeTable TT[50][1000];
	
	// Para indexar esta tabla de tipos
	
	int posTT = 0; // Me dice en que tabla estoy
	int typNum[50]; // Me dice en que tipo estoy dada una tabla (typNum[posTT])
	
	////// FUNCIONES //////
	
	void initTypeTable(typeTable TT[][1000],int typNum[]);
	void insertIntoTT(int posTT,int *typNum,char *type,int baseType,int dim);
	void printTypeTable(typeTable TT[][1000],int posTT,int typNum[]);
	
	// Regresa la dimension de un tipo dada su coordenada posTT & typNum de la Tabla de Tipos
	
	int getDimWithTypNumPosTT(int typNum,int posTT,typeTable TT[][1000]);
	int getTypeWithTypeStr(char *typeStr,int posTT,typeTable TT[][1000]);
	
/*BORRAR*/
	typeTable GTT[1000]; // Tabla de tipos global hasta 1,000 elementos
	
	int posTTT; // Control de las posiciones de la tabla de tipos
/*BORRAR*/

	

////// TABLA DE SIMBOLOS EMBRIÓN //////

	typedef struct{
		char *lexema;
		int tipo;
	}embryoST;

	embryoST EST[100];

	int posEST = 0;

	void insertIntoEmbryoSymbolTable(int *posEST,char *lexema,int type,embryoST EST[]);
	void printEmbryoSymbolTable(embryoST EST[],int posEST);

////// TABLA DE TIPOS EMBRIÓN //////
	
	typedef struct{
		int typNum;
		int tipoBase;
		int dim;
	}embryoTT;

	embryoTT ETT[100];

	int posETT = 0;

	void inserIntoEmbryoTypeTable(int *posETT,int *typNum,int baseType,int dim,embryoTT ETT[]);
	void printEmbryoTypeTable(embryoTT ETT[],int posETT);
	
	 
////// VARIABLES GLOBALES USADAS EN LAS ACCIONES SEMÁNTICAS DE LA PARTE DE REGLAS DE TRADUCCIÓN //////
	 
	int tempNum = 0; // Contador de temporales
	int etiNum = 0; // Contador de etiquetas	
	
	/* Se usa con la funcion synthesizeCode aqui guardamos todos los apuntadores de
	   las cadenas que queremos unir y luego pasamos este arreglo como el primer
	   parametro a la funcion, el segundo parametro es el numero de cadenas que 
	   ingresamos a este arreglo */
	
	char *codeSnippets[50];
	
////// FUNCIONES USADAS EN LAS ACCIONES SEMÁNTICAS DE LA PARTE DE REGLAS DE TRADUCCIÓN //////

	////// TABLAL DE TIPOS //////
	
	
	
	
	////// //////
	
	void yyerror(char *s);
	
	char* synthesizeCode(char* codeSnippets[],int codeSnippetsNum);
	
	char* labelSwitch();
	char* newLabel(int *etiNum);
	char* changeLabel(char *code,char *oldLabel,char *newLabel);
	
	bool isInt(int tipo);
	bool isFloat(int tipo);
	bool isDouble(int tipo);
	
	int getPos(char* tipo,typeTable GTT[],int posTTT);
	int getDimWithposTTT(int posTTT,typeTable GTT[]);
	
	////// FUNCIONES PARA EL NO TERMINAL S //////
	
	char* switchCode(char* etiquetas[],int numCasos[],char* temp,int indice);
	
	// FUNCIONES PARA EL NO TERMINAL E //
	
	bool isNumero(int eType);
	int maxType(int e1Type,int e2Type);
	int getDim(char* tipo,typeTable GTT[],int posTTT);
	bool isEmptyStr(char* s);
	char* changeStr(char* numStr,int originType);
	
	char* newTempNumero(int* tempNum,
					int posST,
					int posTT,
					int *symNum,
					symbolTable ST[][1000],
					typeTable TT[][1000],
					int eType);
					
	char* newTempCaracter(int* tempNum,
						int posST,
						int posTT,
						int *symNum,
						symbolTable ST[][1000],
						typeTable TT[][1000]);
	
	char* newTempCadena(int* tempNum,
					int posST,
					int posTT,
					int *symNum,
					int *typNum,
					symbolTable ST[][1000],
					typeTable TT[][1000],
					char* cadenaLexema);
					
	int mergeRetType(int type1, int type2);
	
	////// NO TERMIANAL G //////
	
	struct params* initParam(int type,bool isArray);
	void insertParam(struct params* initial,int type,bool isArray);
	
	/* Estructura utilizada para almacenar los tipos de los argumetos y si estos
	   son arrays o no */
	   
	// Los no terminales A y G tienen un apuntador a una de estas estructuras
		
	struct params{
		struct params *next;
		int tipo;
		bool isArray;
	};
	
/////////////////////////////////////
////// TABLA DE FUNCIONES ///////////
/////////////////////////////////////
	
	typedef struct{
		char* lexema;
		int tipoRet;
		int numParams;
		struct params *parametros;
		int posTablas;
	}functionTable;
	
	int posFT;
	functionTable FT[50];
	
	void insertIntoFT(int *posFT,
						char *lexeme,
						int retType,
						int paramsNum,
						struct params *x,
						functionTable FT[],
						int posTS);
						
	bool mainExist(int posFT, functionTable FT[]);
	
	void printFunctionTable(functionTable FT[],int posFT){
		int i;
		printf("\npos\tlexema\ttipoRet\tnumParams\tparams\t   numTablas\n\n");
		for(i=0;i<posFT;i++){
			printf("%d\t%s\t%d\t%d\t\t%p\t%d\n",
					i,
					FT[i].lexema,
					FT[i].tipoRet,
					FT[i].numParams,
					FT[i].parametros,
					FT[i].posTablas);
		}
		printf("\n");
	}
		

#line 305 "y.tab.c" /* yacc.c:339  */

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
#line 240 "yacc.y" /* yacc.c:355  */


	struct {
		int ival; // Valor INT
		float fval; // Valor FLOAT
		double dval; // Valor DOUBLE
		int tipo; // 1:INT 2:FLOAT 3:DOUBLE
	}numero;
	
	struct {
		char *codigo;
		int tipo;
	}P;
	
	struct {
		int tipo;
		int tablaNum;
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
		char *codigo;
	}F;

	struct {
		int numParams;
		struct params *parametros;
	}A;
	
	struct {
		int numParams;
		struct params *parametros;
	}G;
	
	struct {
		int numIndices;
	}I;
	
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
		int tipoRet;
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

#line 541 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 558 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

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
       0,   408,   408,   423,   429,   491,   496,   499,   502,   505,
     508,   511,   515,   526,   538,   559,   566,   576,   580,   584,
     589,   612,   629,   632,   636,   647,   666,   678,   701,   713,
     718,   722,   752,   755,   764,   794,   801,   815,   822,   861,
     900,   939,   978,  1017,  1029,  1051,  1068,  1081,  1092,  1097,
    1102,  1123,  1133,  1144,  1147,  1150,  1153,  1156,  1159
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
  "IGUAL", "OR", "AND", "NOT", "$accept", "initial", "p", "d", "t", "l",
  "c", "f", "a", "g", "i", "s", "j", "k", "e", "b", "r", YY_NULLPTR
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

#define YYPACT_NINF -47

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-47)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     121,   -47,   -47,   -47,   -47,   -47,   -47,    16,   -47,    -8,
      13,   -47,   121,   -47,     1,     0,    30,    38,   -47,    36,
       9,    21,     1,   121,     1,   -47,    49,    14,    35,   -47,
      29,    43,   121,    45,   -47,   121,    72,    29,    69,    29,
     -47,   -47,   -47,   -47,    42,    68,    69,    74,   102,    94,
     110,   103,    69,    76,    80,   -47,    -2,    -2,   129,    69,
     103,   -47,   -47,     8,   117,    -8,   103,   103,   103,   103,
     103,   103,   -47,   -47,    -2,    -2,    54,   -38,    27,   105,
     115,    85,   -47,   -47,   -47,    98,   101,   101,   108,   108,
     -47,    61,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   103,
      69,    -2,    -2,   103,    -2,    -2,   122,   -47,    98,   -47,
     100,   -47,    98,    63,     3,   130,   120,    69,   150,   132,
     -47,   113,   123,   124,   131,    69,    69,    69,   -47,   -47,
     130,   -47,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     7,     9,     8,    10,     6,    11,     0,     2,    17,
       0,     1,     0,     3,    15,     4,     0,     0,    13,     0,
       0,     0,    15,    19,    15,    12,     0,     0,    18,    14,
      23,     0,     0,     0,    21,     5,     0,    23,     0,    23,
      22,    44,    43,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,    29,    32,     0,     0,    17,     0,     0,     0,     0,
       0,     0,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    30,    16,    28,    38,    39,    40,    41,
      42,     0,    48,    53,    54,    55,    56,    57,    58,     0,
       0,     0,     0,     0,     0,     0,     0,    49,    50,    24,
      46,    47,    25,     0,     0,    35,     0,     0,     0,    37,
      26,     0,     0,     0,     0,     0,     0,     0,    31,    27,
      35,    36,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,   -47,   125,    11,   -47,   -17,    93,   -47,   -47,
     -29,   -46,    31,   -47,   -42,   -37,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    15,    18,    13,    27,    28,
      34,    53,   119,   124,    54,    77,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,    41,    42,    43,   100,    25,    64,    29,    40,    63,
      55,   101,   102,    80,    76,    76,    11,    12,    81,    14,
      78,    72,    73,    16,    85,    86,    87,    88,    89,    90,
      17,    19,    76,    76,    26,   117,    20,    91,    92,    74,
      82,    21,    22,    36,    67,    68,    69,    70,    71,    75,
      23,    24,   101,   102,   109,    30,    31,   108,    33,    76,
      76,   112,    76,    76,   110,   111,    32,   113,   114,   103,
      35,   121,    41,    42,    43,    37,   101,   102,    39,   129,
     130,   131,    44,    56,    45,    46,    47,    48,    49,    50,
      67,    68,    69,    70,    71,    51,    52,    93,    94,    95,
      96,    97,    98,   107,    65,   116,    41,    42,    43,    57,
     101,   102,   101,   102,    66,    59,    67,    68,    69,    70,
      71,    67,    68,    69,    70,    71,    61,   106,     1,     2,
       3,     4,     5,     6,    67,    68,    69,    70,    71,    69,
      70,    71,    62,    60,    79,    83,   104,   105,    71,   115,
     102,   118,   120,   122,   123,   125,   126,   127,    84,   128,
      38,   132
};

static const yytype_uint8 yycheck[] =
{
      46,     3,     4,     5,    42,    22,    52,    24,    37,    51,
      39,    49,    50,    59,    56,    57,     0,    25,    60,     6,
      57,    23,    24,    12,    66,    67,    68,    69,    70,    71,
      29,    31,    74,    75,    23,    32,     6,    74,    75,    41,
      32,     3,     6,    32,    36,    37,    38,    39,    40,    51,
      41,    30,    49,    50,   100,     6,    42,    99,    29,   101,
     102,   103,   104,   105,   101,   102,    31,   104,   105,    42,
      27,   117,     3,     4,     5,    30,    49,    50,     6,   125,
     126,   127,    13,    41,    15,    16,    17,    18,    19,    20,
      36,    37,    38,    39,    40,    26,    27,    43,    44,    45,
      46,    47,    48,    42,    28,    42,     3,     4,     5,    41,
      49,    50,    49,    50,    34,    41,    36,    37,    38,    39,
      40,    36,    37,    38,    39,    40,    32,    42,     7,     8,
       9,    10,    11,    12,    36,    37,    38,    39,    40,    38,
      39,    40,    32,    41,    15,    28,    41,    32,    40,    27,
      50,    21,    32,     3,    22,    42,    33,    33,    65,    28,
      35,   130
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    11,    12,    53,    54,    55,
      56,     0,    25,    59,     6,    57,    56,    29,    58,    31,
       6,     3,     6,    41,    30,    58,    56,    60,    61,    58,
       6,    42,    31,    29,    62,    27,    56,    30,    55,     6,
      62,     3,     4,     5,    13,    15,    16,    17,    18,    19,
      20,    26,    27,    63,    66,    62,    41,    41,    63,    41,
      41,    32,    32,    66,    63,    28,    34,    36,    37,    38,
      39,    40,    23,    24,    41,    51,    66,    67,    67,    15,
      63,    66,    32,    28,    59,    66,    66,    66,    66,    66,
      66,    67,    67,    43,    44,    45,    46,    47,    48,    68,
      42,    49,    50,    42,    41,    32,    42,    42,    66,    63,
      67,    67,    66,    67,    67,    27,    42,    32,    21,    64,
      32,    63,     3,    22,    65,    42,    33,    33,    28,    63,
      63,    63,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    68,    68,    68,    68,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     4,     2,     4,     0,    11,     0,     1,     0,
       5,     3,     3,     0,     5,     5,     7,     9,     3,     2,
       3,     8,     2,     3,     5,     0,     3,     0,     3,     3,
       3,     3,     3,     1,     1,     1,     3,     3,     2,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 408 "yacc.y" /* yacc.c:1646  */
    {
			if(mainExist(posFT,FT)){ // Validando que la funcion main haya sido declarada
				if(strcmp(FT[0].lexema,"main") != 0){ // Validando que main haya sido la ultima funcion en ser declarada
					yyerror("semantic error:: [LA FUNCION MAIN TIENE QUE SER LA ULTIMA EN SER DECLARADA]");
				} else {
					printf("CODIGO\n\n%s",(yyvsp[0].P).codigo);
					printFunctionTable(FT,posFT);
					printTypeTable(TT,posTT,typNum);
					printSymbolTable(ST,posST,symNum);
				}
			} else {
				yyerror("semantic error:: [LA FUNCION MAIN NO HA SIDO DECLARADA]");
			}			
		}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 423 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.P).codigo = (yyvsp[0].F).codigo;
		(yyval.P).tipo = (yyvsp[-1].D).tipo;
	}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 429 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.D).tipo = (yyvsp[-1].T).tipo;
		(yyval.D).tablaNum = posTT; // Se pasa para saber que tabla de simbolos/tipos corresponde con que funcion
		
		if((yyvsp[-1].T).tipo == 0){
			yyerror("semantic error:: [LAS VARIABLES NO PUEDEN SER DE TIPO VOID]");
		
		} else {
			int i;
		
			// Vaciado de Tabla de Tipos Embrion a la Tabla de Tipos que Corresponda
	
		
			for(i=0;i<(yyvsp[0].L).elementosETT;i++){
				TT[posTT][ETT[i].typNum].tipo = "array";
				if(ETT[i].tipoBase == -1){
					TT[posTT][ETT[i].typNum].tipoBase = (yyvsp[-1].T).tipo;
				} else {
					TT[posTT][ETT[i].typNum].tipoBase = ETT[i].tipoBase;
				}
				TT[posTT][ETT[i].typNum].dim = ETT[i].dim * getDimWithTypNumPosTT((yyvsp[-1].T).tipo,posTT,TT);
			}
		
		
			// Vaciado de Tabla de Simbolos Embrion a la Tabla de Simbolos que Corresponda
		
			for(i=0;i<(yyvsp[0].L).elementosEST;i++){
				ST[posST][symNum[posST]].lexema = EST[i].lexema;
				if(EST[i].tipo == -1){
					ST[posST][symNum[posST]].tipo = (yyvsp[-1].T).tipo;
				} else {
					ST[posST][symNum[posST]].tipo = EST[i].tipo;
				}
				ST[posST][symNum[posST]].tipoVar = "var";
			
				if(symNum[posST] > 0){ // Si ya hay algun elemento en la tabla
					if(ST[posST][symNum[posST]-1].dir == -1){ // Si el ultimo elemento agregado es un parametro
						ST[posST][symNum[posST]].dir = 0;
					} else {
						ST[posST][symNum[posST]].dir = ST[posST][symNum[posST]-1].dir + getDimWithTypNumPosTT(ST[posST][symNum[posST]-1].tipo,posTT,TT);
					}
				} else {
					ST[posST][symNum[posST]].dir = 0;
				}
			
				/* Cada que insertamos un elemento en la tabla incrementamos esta variable para que
				   symNum[posST] siempre almacene la direccion de la tabla de simbolos en donde podemos 
				   almacenar un elemeto directamente */
				   
				symNum[posST] = symNum[posST] + 1; 
			}
		
			posTT++; // Apuntamos a nueva tabla de tipos
			posST++; // Apuntamos a nueva tabla de simbolos
		
			/* Reseteamos las tablas de simbolos embrion y de tipos embiron para que
			   puedan ser utilizadas despues sin mayor problema por otras funciones */
		
			posEST = 0; 
			posETT = 0;
		}
	}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 491 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.D).tipo = -1;
		(yyval.D).tablaNum = -1;
	}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 496 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.T).tipo = getTypeWithTypeStr((yyvsp[0].cadena),posTT,TT); // Busca el tipo en la tabla de tipos dada una cadena ej: "int"
	}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 499 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.T).tipo = getTypeWithTypeStr((yyvsp[0].cadena),posTT,TT);
	}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 502 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.T).tipo = getTypeWithTypeStr((yyvsp[0].cadena),posTT,TT);;
	}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 505 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.T).tipo = getTypeWithTypeStr((yyvsp[0].cadena),posTT,TT);
	}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 508 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.T).tipo = getTypeWithTypeStr((yyvsp[0].cadena),posTT,TT);
	}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 511 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.T).tipo = getTypeWithTypeStr((yyvsp[0].cadena),posTT,TT);
	}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 515 "yacc.y" /* yacc.c:1646  */
    {
		if(!(yyvsp[0].C).isArray){// si no es un arreglo
			insertIntoEmbryoSymbolTable(&posEST,(yyvsp[-1].cadena),-1,EST);
			(yyval.L).elementosEST = (yyvsp[-3].L).elementosEST + 1;
			(yyval.L).elementosETT = (yyvsp[-3].L).elementosETT + (yyvsp[0].C).elementosETT;
		} else { // si es un arreglo
			insertIntoEmbryoSymbolTable(&posEST,(yyvsp[-1].cadena),(yyvsp[0].C).tipoBase,EST);
			(yyval.L).elementosEST = (yyvsp[-3].L).elementosEST + 1;
			(yyval.L).elementosETT = (yyvsp[-3].L).elementosETT + (yyvsp[0].C).elementosETT;
		}
	}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 526 "yacc.y" /* yacc.c:1646  */
    {
		if(!(yyvsp[0].C).isArray){// si no es un arreglo
			insertIntoEmbryoSymbolTable(&posEST,(yyvsp[-1].cadena),-1,EST);
			(yyval.L).elementosEST = 1;
			(yyval.L).elementosETT = 0;
		} else { // si es un arreglo
			insertIntoEmbryoSymbolTable(&posEST,(yyvsp[-1].cadena),(yyvsp[0].C).tipoBase,EST);
			(yyval.L).elementosEST = 1;
			(yyval.L).elementosETT = (yyvsp[0].C).elementosETT;
		}
	}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 538 "yacc.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].numero).tipo == 1){// si NUMERO es un entero
			(yyval.C).isArray = 1; // igual a true
			if((yyvsp[0].C).isUltimo){ // si es último
				(yyval.C).isUltimo = 0; // igual a false
				inserIntoEmbryoTypeTable(&posETT,&typNum[posTT],-1,(yyvsp[-2].numero).ival,ETT);
				(yyval.C).dim = (yyvsp[-2].numero).ival;
				(yyval.C).tipoBase = typNum[posTT] - 1;
				(yyval.C).elementosETT = 1;
			} else { // si no es último
				(yyval.C).isUltimo = 0; // igual a false
				inserIntoEmbryoTypeTable(&posETT,&typNum[posTT],(yyvsp[0].C).tipoBase,(yyvsp[0].C).dim*(yyvsp[-2].numero).ival,ETT);
				(yyval.C).tipoBase = (yyvsp[0].C).tipoBase + 1;
				(yyval.C).dim = (yyvsp[0].C).dim*(yyvsp[-2].numero).ival;
				(yyval.C).elementosETT = (yyvsp[0].C).elementosETT + 1;
			}
		} else {
			yyerror("semantic error::\nLos indices de los arreglos deben ser numeros enteros");
			exit(1);
		}
	}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 559 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.C).isArray = 0; // igual a false
		(yyval.C).isUltimo = 1; // igual a true
		(yyval.C).tipoBase = 0; // No se usa solo se inicializa
		(yyval.C).dim = 0; // No se usa solo se inicializa
	}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 566 "yacc.y" /* yacc.c:1646  */
    {
		insertIntoFT(&posFT,(yyvsp[-8].cadena),(yyvsp[-9].T).tipo,(yyvsp[-6].A).numParams,(yyvsp[-6].A).parametros,FT,(yyvsp[-3].D).tablaNum);
		
		codeSnippets[0] = (yyvsp[-8].cadena);
		codeSnippets[1] = ":\n";
		codeSnippets[2] = (yyvsp[-2].S).codigo;
		codeSnippets[3] = (yyvsp[0].F).codigo;
		
		(yyval.F).codigo = synthesizeCode(codeSnippets,4);
	}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 576 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.F).codigo = "";
	}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 580 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.A).numParams = (yyvsp[0].G).numParams;
		(yyval.A).parametros = (yyvsp[0].G).parametros;	
	}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 584 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.A).numParams = 0;
		(yyval.A).parametros = NULL;
	}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 589 "yacc.y" /* yacc.c:1646  */
    {

		/* Se considera que todos los parametros tienen direccion -1 por que por ser
		   parametros ya fueron declarados en algun otro lado y esa es su verdadera
		   direccion*/
		   
		if ((yyvsp[-2].T).tipo == 0){// Validando que los parametros no sean tipo void
			yyerror("semantic error:: [LOS PARAMETROS NO PUEDEN SER DE TIPO VOID]");
		} else {
			if((yyvsp[0].I).numIndices == 0){
				insertIntoST(posST,&symNum[posST],(yyvsp[-1].cadena),(yyvsp[-2].T).tipo,"param",-1,ST);
				(yyval.G).numParams = (yyvsp[-4].G).numParams + 1;
				(yyval.G).parametros = (yyvsp[-4].G).parametros;
				insertParam((yyval.G).parametros,(yyvsp[-2].T).tipo,false);
			} else {// Si los parametros no son tipo void
				insertIntoTT(posTT,&typNum[posST],"array",(yyvsp[-2].T).tipo,(yyvsp[0].I).numIndices);
				insertIntoST(posST,&symNum[posST],(yyvsp[-1].cadena),typNum[posST]-1,"param",-1,ST);
				(yyval.G).numParams = (yyvsp[-4].G).numParams + 1;
				(yyval.G).parametros = (yyvsp[-4].G).parametros;
				insertParam((yyval.G).parametros,(yyvsp[-2].T).tipo,true);
			}
		}
	}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 612 "yacc.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].T).tipo == 0){// Validando que los parametros no sean tipo void
			yyerror("semantic error:: [LOS PARAMETROS NO PUEDEN SER DE TIPO VOID]");
		} else {
			if((yyvsp[0].I).numIndices == 0){
				insertIntoST(posST,&symNum[posST],(yyvsp[-1].cadena),(yyvsp[-2].T).tipo,"param",-1,ST);
				(yyval.G).numParams = 1;
				(yyval.G).parametros = initParam((yyvsp[-2].T).tipo,false);
			} else {// Si los parametros no son tipo void
				insertIntoTT(posTT,&typNum[posST],"array",(yyvsp[-2].T).tipo,(yyvsp[0].I).numIndices);
				insertIntoST(posST,&symNum[posST],(yyvsp[-1].cadena),typNum[posST]-1,"param",-1,ST);
				(yyval.G).numParams = 1;
				(yyval.G).parametros = initParam((yyvsp[-2].T).tipo,true);
			}
		}
	}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 629 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.I).numIndices = (yyvsp[0].I).numIndices + 1;
	}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 632 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.I).numIndices = 0;
	}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 636 "yacc.y" /* yacc.c:1646  */
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
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 647 "yacc.y" /* yacc.c:1646  */
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
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 666 "yacc.y" /* yacc.c:1646  */
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
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 678 "yacc.y" /* yacc.c:1646  */
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
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 701 "yacc.y" /* yacc.c:1646  */
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
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 713 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.S).next = newLabel(&etiNum);
		(yyval.S).codigo = "AGUIMAWE\n";
		(yyval.S).tipoRet = 11;
	}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 718 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.S).next = (yyvsp[-1].S).next;
		(yyval.S).codigo = (yyvsp[-1].S).codigo;
	}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 722 "yacc.y" /* yacc.c:1646  */
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
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 752 "yacc.y" /* yacc.c:1646  */
    { // S -> break;
		(yyval.S).codigo = "";
	}
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 755 "yacc.y" /* yacc.c:1646  */
    {
		codeSnippets[0] = (yyvsp[-1].E).codigo;
		codeSnippets[1] = "PARAM ";
		codeSnippets[2] = (yyvsp[-1].E).temp;
		codeSnippets[3] = "\nCALL print,1\n";
		
		(yyval.S).codigo = synthesizeCode(codeSnippets,4);
	}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 764 "yacc.y" /* yacc.c:1646  */
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
			yyerror("semantic error: [LOS NUMEROS DE LOS CASOS DEBEN SER ENTEROS]");
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
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 794 "yacc.y" /* yacc.c:1646  */
    {
		// J -> ε
		(yyval.J).next = newLabel(&etiNum);
		(yyval.J).indice = -1; // Para que el indice en la produccion anterior se inicie en 0
		(yyval.J).codigo = ""; // El codigo debe ser cadena vacia para que no marque error "Violacion de Segmento"
	}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 801 "yacc.y" /* yacc.c:1646  */
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
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 815 "yacc.y" /* yacc.c:1646  */
    {
		// K -> ε
		(yyval.K).next = newLabel(&etiNum);
		(yyval.K).etiqueta = newLabel(&etiNum);
		(yyval.K).codigo = "";
	}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 822 "yacc.y" /* yacc.c:1646  */
    {
			if(isNumero((yyvsp[-2].E).tipo) && isNumero((yyvsp[0].E).tipo)){
				(yyval.E).tipo = maxType((yyvsp[-2].E).tipo,(yyvsp[0].E).tipo);
				
				(yyval.E).temp = newTempNumero(&tempNum,
										posST-1,
										posTT-1,
										&symNum[posST-1],
										ST,
										TT,
										(yyval.E).tipo);
			
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
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 861 "yacc.y" /* yacc.c:1646  */
    {
		if(isNumero((yyvsp[-2].E).tipo) && isNumero((yyvsp[0].E).tipo)){
				(yyval.E).tipo = maxType((yyvsp[-2].E).tipo,(yyvsp[0].E).tipo);
				
				(yyval.E).temp = newTempNumero(&tempNum,
										posST-1,
										posTT-1,
										&symNum[posST-1],
										ST,
										TT,
										(yyval.E).tipo);
			
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
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 900 "yacc.y" /* yacc.c:1646  */
    {
		if(isNumero((yyvsp[-2].E).tipo) && isNumero((yyvsp[0].E).tipo)){
				(yyval.E).tipo = maxType((yyvsp[-2].E).tipo,(yyvsp[0].E).tipo);
				
				(yyval.E).temp = newTempNumero(&tempNum,
										posST-1,
										posTT-1,
										&symNum[posST-1],
										ST,
										TT,
										(yyval.E).tipo);
			
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
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 939 "yacc.y" /* yacc.c:1646  */
    {
		if(isNumero((yyvsp[-2].E).tipo) && isNumero((yyvsp[0].E).tipo)){
				(yyval.E).tipo = maxType((yyvsp[-2].E).tipo,(yyvsp[0].E).tipo);
				
				(yyval.E).temp = newTempNumero(&tempNum,
										posST-1,
										posTT-1,
										&symNum[posST-1],
										ST,
										TT,
										(yyval.E).tipo);
			
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
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 978 "yacc.y" /* yacc.c:1646  */
    {
		if(isNumero((yyvsp[-2].E).tipo) && isNumero((yyvsp[0].E).tipo)){
				(yyval.E).tipo = maxType((yyvsp[-2].E).tipo,(yyvsp[0].E).tipo);
				
				(yyval.E).temp = newTempNumero(&tempNum,
										posST-1,
										posTT-1,
										&symNum[posST-1],
										ST,
										TT,
										(yyval.E).tipo);
			
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
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1017 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.E).tipo = 4;
		(yyval.E).temp = newTempCadena(&tempNum,
								posST-1,
								posTT-1,
								&symNum[posST-1],
								&typNum[posTT-1],
								ST,
								TT,
								(yyvsp[0].cadena));
		(yyval.E).codigo = (yyvsp[0].cadena);
	}
#line 2538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1029 "yacc.y" /* yacc.c:1646  */
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
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1051 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.E).tipo = 4;
		
		(yyval.E).temp = newTempCaracter(&tempNum,
									posST-1,
									posTT-1,
									&symNum[posST-1],
									ST,
									TT);
						
		char buffer[1] = {0},*s;
		sprintf(buffer,"%c",(yyvsp[0].caracter));
		s = (char*) malloc(sizeof(char)*(strlen(buffer) + 1));
		strcpy(s,buffer);
		(yyval.E).codigo = s;
	}
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1068 "yacc.y" /* yacc.c:1646  */
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
#line 2604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1081 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.B).trueLabel = (yyvsp[0].B).trueLabel;
		(yyval.B).falseLabel = newLabel(&etiNum);
		
		codeSnippets[0] = changeLabel((yyvsp[-2].B).codigo,(yyvsp[-2].B).falseLabel,(yyval.B).falseLabel);
		codeSnippets[1] = (yyvsp[-2].B).trueLabel;
		codeSnippets[2] = ":\n";
		codeSnippets[3] = changeLabel((yyvsp[0].B).codigo,(yyvsp[0].B).falseLabel,(yyval.B).falseLabel);
		
		(yyval.B).codigo = synthesizeCode(codeSnippets,4);		
	}
#line 2620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1092 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.B).trueLabel = (yyvsp[0].B).falseLabel;
		(yyval.B).falseLabel = (yyvsp[0].B).trueLabel;
		(yyval.B).codigo = (yyvsp[0].B).codigo;
	}
#line 2630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1097 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.B).trueLabel = (yyvsp[-1].B).trueLabel;
		(yyval.B).falseLabel = (yyvsp[-1].B).falseLabel;
		(yyval.B).codigo = (yyvsp[-1].B).codigo;
	}
#line 2640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1102 "yacc.y" /* yacc.c:1646  */
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
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1123 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.B).trueLabel = newLabel(&etiNum);
		(yyval.B).falseLabel = newLabel(&etiNum);
		
		codeSnippets[0] = "GOTO ";
		codeSnippets[1] = (yyval.B).trueLabel;
		codeSnippets[2] = "\n";
		
		(yyval.B).codigo = synthesizeCode(codeSnippets,3);
	}
#line 2681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1133 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.B).trueLabel = newLabel(&etiNum);
		(yyval.B).falseLabel = newLabel(&etiNum);
		
		codeSnippets[0] = "GOTO ";
		codeSnippets[1] = (yyval.B).falseLabel;
		codeSnippets[2] = "\n";
		
		(yyval.B).codigo = synthesizeCode(codeSnippets,3);
	}
#line 2696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1144 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.R).codigo = "<";
	}
#line 2704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1147 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.R).codigo = ">";
	}
#line 2712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1150 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.R).codigo = "<=";
	}
#line 2720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1153 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.R).codigo = ">=";
	}
#line 2728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1156 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.R).codigo = "!=";
	}
#line 2736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1159 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.R).codigo = "==";
	}
#line 2744 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2748 "y.tab.c" /* yacc.c:1646  */
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
#line 1163 "yacc.y" /* yacc.c:1906  */



extern FILE *yyin;
extern int yylineno;

///////////////////////////////////////////////////////////
//////////////////// MAIN /////////////////////////////////
///////////////////////////////////////////////////////////

int main(int argc,char **argv){
	if(argc > 1){
		yyin = fopen(argv[1],"r");	
	}
////// INICIALIZACIONES //////
	posSTT[0] = 0;
	initTypeTable(TT,typNum);
	
	yyparse();
	return 0;
}

//////////////////////////////////////////////////////////
//// MIS FUNCIONES ///////////////////////////////////////
//////////////////////////////////////////////////////////

////// MANEJO DE ERRORES /////////////////////////////////

	void yyerror(char *s){
		printf("%s ::line:%d\n",s,yylineno-2);
		exit(0);
	}

//*********************************************************
//*****	 TABLA DE FUNCIONES *******************************
//*********************************************************

void insertIntoFT(int *posFT,char *lexeme,int retType,int paramsNum,struct params *x,functionTable FT[], int posTS){
		FT[*posFT].lexema = lexeme;
		FT[*posFT].tipoRet = retType;
		FT[*posFT].numParams = paramsNum;
		FT[*posFT].parametros = x;
		FT[*posFT].posTablas = posTS;
		
		*posFT = *posFT + 1;
}

bool mainExist(int posFT, functionTable FT[]){
	int i;
	for(i=0;i<posFT;i++){
		if(strcmp(FT[i].lexema,"main") == 0)
			return true;
	}
	return false;
}
	
//*********************************************************
//*****	 TABLA DE SIMBOLOS ********************************
//*********************************************************

void insertIntoST(int posST,int *symNum,char *lexeme,int type,char *varType,int dir,symbolTable ST[][1000]){
	ST[posST][*symNum].lexema = lexeme;
	ST[posST][*symNum].tipo = type;
	ST[posST][*symNum].tipoVar = varType;
	ST[posST][*symNum].dir = dir;
	
	*symNum = *symNum + 1;
}

void printSymbolTable(symbolTable ST[][1000],int posST,int symNum[]){
	int i,j;
	for(i=0;i<posST;i++){
		printf("*************** Tabla de Simbolos #%d ***************\n\n",i);
		printf("lexema\ttipo\ttipoVar\tdir\n\n");
		for(j=0;j<symNum[i];j++){
			printf("%s\t%d\t%s\t%d\n",
				ST[i][j].lexema,
				ST[i][j].tipo,
				ST[i][j].tipoVar,
				ST[i][j].dir);
		}
		printf("\n");
	}
}

//*********************************************************
//*****	 TABLA DE TIPOS ***********************************
//*********************************************************

void insertIntoTT(int posTT,int *typNum,char *type,int baseType,int dim){
	TT[posTT][*typNum].tipo = type;
	TT[posTT][*typNum].tipoBase = baseType;
	TT[posTT][*typNum].dim = dim;
	
	*typNum = *typNum + 1;
}


void initTypeTable(typeTable TT[][1000],int typNum[]){
	int i;
	for(i=0;i<50;i++){

	// void
		TT[i][0].tipo = "void";
		TT[i][0].tipoBase = -1;
		TT[i][0].dim = -1;
	
	// int

		TT[i][1].tipo = "int";
		TT[i][1].tipoBase = -1;
		TT[i][1].dim = 4;
	
	// float

		TT[i][2].tipo = "float";
		TT[i][2].tipoBase = -1;
		TT[i][2].dim = 8;
	
	// double

		TT[i][3].tipo = "double";
		TT[i][3].tipoBase = -1;
		TT[i][3].dim = 8;

	// char

		TT[i][4].tipo = "char";
		TT[i][4].tipoBase = -1;
		TT[i][4].dim = 1;
	
		typNum[i] = 5;
	}	
}

void printTypeTable(typeTable TT[][1000],int posTT,int typNum[]){
	int i,j;
	for(i=0;i<posTT;i++){
		printf("***************** Tabla de Tipos #%d ***************\n",i);
		printf("\npos\ttipo\ttipoBase\tdim\n\n");
		for(j=0;j<typNum[i];j++){
			printf("%d\t%s\t%d\t\t%d\n",
				j,
				TT[i][j].tipo,
				TT[i][j].tipoBase,
				TT[i][j].dim);
		}
		printf("\n");
	}
}

/* Retorna la posicion de la tabla de tipos en donde la cadena que se pasa como argumento
   y la cadena tipo de la tabla de tipos coinciden (la posicion en la tabla de tipos hace
   alucion a el tipo de la variable en si. por ejemplo la posicion 1 es el tipo int si en 
   la tabla de simbolos alguna variable tiene en su campo tipo 1 significa que es de tipo
   int y ya con ese valor se puede obtener informacion en la tabla de tipos posicion 1) */

int getPos(char* tipo,typeTable GTT[],int posTTT){
	int i;
	for(i=0;i<posTTT;i++){
		if(strcmp(tipo,GTT[i].tipo) == 0)
			return i;
	}
	return -1;
}

/* Retorna un entero que representa la posicion en la tabla de tipos en donde esta contenida
   la informacion respecto a un cierto tipo de datos. Este entero se obtiene comparando la
   cadena que se recibe de parametro (*typeStr) con las cadenas (*tipo) de la tabla de tipos
   para una tabla de simbolos dada (posTT), cuando estas cadenas coinciden se regresa el valor
   del segundo subindice de la tabla de tipos que representa el tipo correspondiente */

int getTypeWithTypeStr(char *typeStr,int posTT,typeTable TT[][1000]){
	int i;
	for(i=0;i<typNum[posTT];i++){
		if(strcmp(typeStr,TT[posTT][i].tipo) == 0){
			return i;
		}
	}
	return -1;
}


int getDimWithposTTT(int posTTT,typeTable GTT[]){
	return GTT[posTTT].dim;
}

int getDimWithTypNumPosTT(int typNum,int posTT,typeTable TT[][1000]){
	return TT[posTT][typNum].dim;
}

////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////// FUNCIONES VARIAS////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

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

int mergeRetType(int type1, int type2){
	if(type1 == type2) {
		return type1;
	}else if(type1 == -1 || type2 == -1){
		if(type1 == -1)
			return type2;
		else
			return type1;
	}		
	yyerror("Conflicto en los tipos de retorno");
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ FUNCIONES PARA EL NO TERMINAL E ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


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

int getDim(char* tipo,typeTable GTT[],int posTTT){
	int i;
	for(i=0;i<posTTT;i++){
		if(strcmp(tipo,GTT[i].tipo) == 0)
			return GTT[i].dim;
	}
	return -1;
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

char* newTempNumero(int* tempNum,
					int posST,
					int posTT,
					int *symNum,
					symbolTable ST[][1000],
					typeTable TT[][1000],
					int eType){
	int i = 0;
	char buffer[30];
	char *s;
	
	for(i=0;i<30;i++) { buffer[i] = 0; } // Limpiamos el buffer
	
	sprintf(buffer,"t%d",*tempNum);
	s = (char*) malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(s,buffer);
		
	ST[posST][*symNum].lexema = s;
	ST[posST][*symNum].tipo = eType;
	ST[posST][*symNum].tipoVar = "temp";
		
	if(*symNum > 0)
		ST[posST][*symNum].dir = ST[posST][*symNum-1].dir + getDimWithTypNumPosTT(ST[posST][*symNum-1].tipo,posTT,TT);
	else
		ST[posST][*symNum].dir = 0;		
	
	
	*symNum = *symNum + 1;
	*tempNum = *tempNum + 1;
	
	return s;
}

char* newTempCaracter(int* tempNum,
						int posST,
						int posTT,
						int *symNum,
						symbolTable ST[][1000],
						typeTable TT[][1000]){
	int i = 0;
	char buffer[30];
	char *s;
	
	for(i=0;i<30;i++) { buffer[i] = 0; } // Limpiamos el buffer
	
	sprintf(buffer,"t%d",*tempNum);
	s = (char*) malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(s,buffer);
	
	ST[posST][*symNum].lexema = s;
	ST[posST][*symNum].tipo = 4;
	ST[posST][*symNum].tipoVar = "cstChar";
	
	if(*symNum > 0)
		ST[posST][*symNum].dir = ST[posST][*symNum-1].dir + getDimWithTypNumPosTT(ST[posST][*symNum-1].tipo,posTT,TT);
	else
		ST[posST][*symNum].dir = 0;
		
	*symNum = *symNum + 1;
	*tempNum = *tempNum + 1;
	
	return s;
}

/* Coloca en la tabla de tipos la informacion sobre la cadena (tipo "array",tipoBase "4",dim strlen(cadenaLexema))
   una vez hecho eso coloca en la tabla de simbolos global una nueva temporal ocupando el espacio de la longitud
   de la cadena y coloca como tipo el que se definio anteriormente en la tabla de tipos, finalmente regresa un
   apuntador a cadena que apunta a la nueva etiqueta que se acaba de definir */

char* newTempCadena(int* tempNum,
					int posST,
					int posTT,
					int *symNum,
					int *typNum,
					symbolTable ST[][1000],
					typeTable TT[][1000],
					char* cadenaLexema){
	int i = 0;
	char buffer[30];
	char *s;
	
	for(i=0;i<30;i++) { buffer[i] = 0; } // Limpiamos el buffer
	
	// Tabla de Tipos
	
	TT[posTT][*typNum].tipo = "array";
	TT[posTT][*typNum].tipoBase = 4;
	TT[posTT][*typNum].dim = (int) strlen(cadenaLexema);
	
	// Tabla de Simbolos
	
	sprintf(buffer,"t%d",*tempNum);
	s = (char*) malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(s,buffer);
	
	ST[posST][*symNum].lexema = s;
	ST[posST][*symNum].tipo = *typNum;
	ST[posST][*symNum].tipoVar = "cstStr";
	
	if(*symNum > 0)
		ST[posST][*symNum].dir = ST[posST][*symNum-1].dir + getDimWithTypNumPosTT(*typNum-1,posTT,TT);
	else
		ST[posST][*symNum].dir = 0;
	
	// Preparo variables de posicion de las tablas y contador de temporales para su nuevo uso
	
	*symNum = *symNum + 1;
	*typNum = *typNum + 1;
	*tempNum = *tempNum + 1;
	
	return s;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ FUNCIONES PARA EL NO TERMINAL G ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct params* initParam(int type,bool isArray){
	struct params *initial;
	
	initial = (struct params*) malloc(sizeof(struct params));
	
	initial->next = NULL;
	initial->tipo = type;
	initial->isArray = isArray;
	
	return initial;
}

void insertParam(struct params* initial,int type,bool isArray){
	struct params *aux,*new;
	
	aux = initial;
	
	while(aux->next != NULL){
		aux = aux->next;
	}
	
	new = (struct params*) malloc(sizeof(struct params));
	
	aux->next = new;
	
	new->next = NULL;
	new->tipo = type;
	new->isArray = isArray;
}

////// FUNCIONES PARA LA TABLA DE SIMBOLOS EMBRIÓN //////


/* Esta funcion recibe como parametros todos los elementos que tiene un miembro del tipo embryoST
   lo que va a hacer es una insertar esos elementos en la posicion que corresponda de la tabla
   EST[] */

void insertIntoEmbryoSymbolTable(int *posEST,char *lexema,int type,embryoST EST[]){
	EST[*posEST].lexema = lexema;
	EST[*posEST].tipo = type;
	
	*posEST = *posEST + 1;
}

void printEmbryoSymbolTable(embryoST EST[],int posEST){
	int i;
	printf("\nposEST\tlexema\ttipo\n\n");
	for(i=0;i<posEST;i++){
		printf("%d\t%s\t%d\n",i,EST[i].lexema,EST[i].tipo);
	}
	printf("\n");
}

////// FUNCIONES PARA LA TABLA DE TIPOS EMBRIÓN //////

void inserIntoEmbryoTypeTable(int *posETT,int *typNum,int baseType,int dim,embryoTT ETT[]){
	ETT[*posETT].typNum = *typNum;
	ETT[*posETT].tipoBase = baseType;
	ETT[*posETT].dim = dim;
	
	*posETT = *posETT + 1;
	*typNum = *typNum + 1;
}

void printEmbryoTypeTable(embryoTT ETT[],int posETT){
	int i;
	printf("\nposETT\ttypNum\ttipoBase\tdim\n\n");
	for(i=0;i<posETT;i++){
		printf("%d\t%d\t%d\t\t%d\n",i,ETT[i].typNum,ETT[i].tipoBase,ETT[i].dim);
	}
}




