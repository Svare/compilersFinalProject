%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>

/*Con esto evito el warning: implicit declaration of function ‘yylex’ [-Wimplicit-function-declaration]
       yychar = yylex ();
                ^         */
	extern int yylex (void);

////// TABLA DE SIMBOLOS //////

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
	int symNum[50] = {0}; // En que simbolo estoy indexado por posST (symNum[posST])
	
	// FUNCIONES
	
	void printSymbolTable(symbolTable ST[][1000],int posST,int symNum[]);
	
	int posSTT[5];         /*BORRAR*/
	symbolTable GST[10];   /*BORRAR*/
	
////// TABLA DE TIPOS //////

	typedef struct {
		char *tipo;
		int tipoBase;
		int dim;
	}typeTable;
	
/*BORRAR*/
	typeTable GTT[1000]; // Tabla de tipos global hasta 1,000 elementos
	
	int posTT; // Control de las posiciones de la tabla de tipos
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
	
	/* Se usa con la funcion synthesizeCode aqui guardamos todos los apuntadores de
	   las cadenas que queremos unir y luego pasamos este arreglo como el primer
	   parametro a la funcion, el segundo parametro es el numero de cadenas que 
	   ingresamos a este arreglo */
	
	char *codeSnippets[50];
	
////// FUNCIONES USADAS EN LAS ACCIONES SEMÁNTICAS DE LA PARTE DE REGLAS DE TRADUCCIÓN //////

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
		
%}

%union {

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
	
}

%token <numero> NUMERO
%token <cadena> CADENA
%token <caracter> CARACTER
%token <cadena> ID

// Palabras Reservadas

%token <cadena> INT DOUBLE FLOAT CHAR VOID STRUCT 
%token IF ELSE WHILE DO FOR SWITCH RETURN
%token BREAK CASE DEFAULT TRUE FALSE FUNC PRINT

// Signos de Puntuacion

%token LLLVE RLLVE LCHT RCHT COMA PCMA PNTS

// Operadores de Asignación

%right ASIG

// Operador de Seleccion

%right PUNTO

// Operadores Aritméticos

%left SUM RES
%left MUL DIV
%left MOD

%nonassoc LPAR RPAR

// Operadores de Comparacion

%left MNRQ MYRQ MNROIQ MYROIQ DIFRNT IGUAL

// Operadores Lógicos

%left OR
%left AND
%right NOT

// Declaracion de NO TERMINALES

%type<D> d
%type<T> t
%type<L> l
%type<C> c

%type<J> j
%type<K> k
%type<S> s
%type<E> e

%type<B> b
%type<R> r

%start inicio

%%

inicio : s {
			printf(">>>\n\n%s\n",$1.codigo);
		}
		| t {
			printf("El tipo es: %d\n",$1.tipo);
		}
		| d {
			
		}
		| b {
			printf("b.trueLabel: %s\nb.falseLabel: %s\n\n",$1.trueLabel,$1.falseLabel);
			printf(">>>\n\n%s",$1.codigo);
		};

d : t l {
		$$.tipo = $1.tipo;
		
		int i;
		
		// Vaciado de informacion de la tabla de tipos embrión a la tabla de tipos global
		
		for(i=0;i<$2.elementosETT;i++){
			GTT[ETT[i].posTT].tipo = "array";
			if(ETT[i].tipoBase == -1){
				GTT[ETT[i].posTT].tipoBase = $1.tipo;
			} else {
				GTT[ETT[i].posTT].tipoBase = ETT[i].tipoBase;
			}
			GTT[ETT[i].posTT].dim = ETT[i].dim * getDimWithPosTT($1.tipo,GTT);
		}
		
		// Vaciado de datos de la tabla de simbolos embrion a la tabla de simbolos global
		
		for(i=0;i<$2.elementosEST;i++){
			ST[posST][symNum[posST]].lexema = EST[i].lexema;
			if(EST[i].tipo == -1){
				ST[posST][symNum[posST]].tipo = $1.tipo;
			} else {
				ST[posST][symNum[posST]].tipo = EST[i].tipo;
			}
			ST[posST][symNum[posST]].tipoVar = "var";
			if(symNum[posST] > 0){
				ST[posST][symNum[posST]].dir = ST[posST][symNum[posST]-1].dir + getDimWithPosTT(ST[posST][symNum[posST]-1].tipo,GTT);			
			} else {
				ST[posST][symNum[posST]].dir = 0;
			}
			/* Cada que insertamos un elemento en la tabla incrementamos esta variable para que
			   posST siempre almacene la direccion de la tabla de simbolos en donde podemos almacenar
			   un elemeto directamente */
			symNum[posST] = symNum[posST] + 1; 
		}
		
		posST++;
		
//		printSymbolTableII(GST,posSTT[0]);
		printTypeTable(GTT,posTT);
		printEmbryoSymbolTable(EST,posEST);
		printEmbryoTypeTable(ETT,posETT);
		printf("lo nuevo\n");
		printSymbolTable(ST,posST,symNum);
		
	};

t : VOID {
		$$.tipo = getPos($1,GTT,posTT); // Busca el tipo en la tabla de tipos dada una cadena ej: "int"
	}
	| INT {
		$$.tipo = getPos($1,GTT,posTT);
	}
	| FLOAT {
		$$.tipo = getPos($1,GTT,posTT);
	}
	| DOUBLE {
		$$.tipo = getPos($1,GTT,posTT);
	}
	| CHAR {
		$$.tipo = getPos($1,GTT,posTT);
	}
	| STRUCT {
		$$.tipo = getPos($1,GTT,posTT);
	};
	
l : l COMA ID c {
		if(!$4.isArray){// si no es un arreglo
			insertIntoEmbryoSymbolTable(&posEST,$3,-1,EST);
			$$.elementosEST = $1.elementosEST + 1;
			$$.elementosETT = $1.elementosETT + $4.elementosETT;
		} else { // si es un arreglo
			insertIntoEmbryoSymbolTable(&posEST,$3,$4.tipoBase,EST);
			$$.elementosEST = $1.elementosEST + 1;
			$$.elementosETT = $1.elementosETT + $4.elementosETT;
		}
	}
	|ID c {
		if(!$2.isArray){// si no es un arreglo
			insertIntoEmbryoSymbolTable(&posEST,$1,-1,EST);
			$$.elementosEST = 1;
			$$.elementosETT = 0;
		} else { // si es un arreglo
			insertIntoEmbryoSymbolTable(&posEST,$1,$2.tipoBase,EST);
			$$.elementosEST = 1;
			$$.elementosETT = $2.elementosETT;
		}
	};
	
c : LCHT NUMERO RCHT c {
		if($2.tipo == 1){// si NUMERO es un entero
			$$.isArray = 1; // igual a true
			if($4.isUltimo){ // si es último
				$$.isUltimo = 0; // igual a false
				inserIntoEmbryoTypeTable(&posETT,&posTT,-1,$2.ival,ETT);
				$$.dim = $2.ival;
				$$.tipoBase = posTT - 1;
				$$.elementosETT = 1;
			} else { // si no es último
				$$.isUltimo = 0; // igual a false
				inserIntoEmbryoTypeTable(&posETT,&posTT,$4.tipoBase,$4.dim*$2.ival,ETT);
				$$.tipoBase = $4.tipoBase + 1;
				$$.dim = $4.dim*$2.ival;
				$$.elementosETT = $4.elementosETT + 1;
			}
		} else {
			yyerror("semantic error::\nLos indices de los arreglos deben ser numeros enteros");
			exit(1);
		}
	}
	| {
		$$.isArray = 0; // igual a false
		$$.isUltimo = 1; // igual a true
		$$.tipoBase = 0; // No se usa solo se inicializa
		$$.dim = 0; // No se usa solo se inicializa
	};

s : IF LPAR b RPAR s {
		codeSnippets[0] = $3.codigo;
		codeSnippets[1] = $3.trueLabel;
		codeSnippets[2] = ":\n"; 
		codeSnippets[3] = $5.codigo;
		codeSnippets[4] = $3.falseLabel;
		codeSnippets[5] = ":\n"; 
		
		$$.codigo = synthesizeCode(codeSnippets,6);
		$$.next = $3.falseLabel;
	}
	| WHILE LPAR b RPAR e {
		char *w;
		w = newLabel(&etiNum);
		
		codeSnippets[0] = w;
		codeSnippets[1] = ":\n";
		codeSnippets[2] = $3.codigo;
		codeSnippets[3] = $3.trueLabel;
		codeSnippets[4] = ":\n";
		codeSnippets[5] = $5.codigo;
		codeSnippets[6] = "GOTO ";
		codeSnippets[7] = w;
		codeSnippets[8] = "\n";
		codeSnippets[9] = $3.falseLabel;
		codeSnippets[10] = ":\n";
		
		$$.codigo = synthesizeCode(codeSnippets,11);
		$$.next = $3.falseLabel;
	}
	| DO s WHILE LPAR b RPAR PCMA {
		
		codeSnippets[0] = $5.trueLabel;
		codeSnippets[1] = ":\n";
		codeSnippets[2] = $2.codigo;
		codeSnippets[3] = $5.codigo;
		codeSnippets[4] = $5.falseLabel;
		codeSnippets[5] = ":\n";
		
		$$.codigo = synthesizeCode(codeSnippets,6);
		$$.next = $5.falseLabel;
	}
	| FOR LPAR s PCMA b PCMA s RPAR s {
		
		char *w;
		
		w = newLabel(&etiNum);
		
		codeSnippets[0] = $3.codigo;
		codeSnippets[1] = w;
		codeSnippets[2] = ":\n";
		codeSnippets[3] = $5.codigo;
		codeSnippets[4] = $5.trueLabel;
		codeSnippets[5] = ":\n";
		codeSnippets[6] = $9.codigo;
		codeSnippets[7] = $7.codigo;
		codeSnippets[8] = "GOTO ";
		codeSnippets[9] = w;
		codeSnippets[10] = "\n";
		codeSnippets[11] = $5.falseLabel;
		codeSnippets[12] = ":\n";
		
		$$.next = $5.falseLabel;
		$$.codigo = synthesizeCode(codeSnippets,13);
		
	
	}
	| e ASIG e {
		$$.next = newLabel(&etiNum);
		
		codeSnippets[0] = $1.codigo;
		codeSnippets[1] = $3.codigo;
		codeSnippets[2] = $1.temp;
		codeSnippets[3] = " = ";
		codeSnippets[4] = $3.temp;
		codeSnippets[5] = "\n";
		
		$$.codigo = synthesizeCode(codeSnippets,6);
	}
	| LLLVE s RLLVE{
		$$.next = $2.next;
		$$.codigo = $2.codigo;
	}
	| SWITCH LPAR e RPAR LLLVE j k RLLVE {
		
		$$.next = newLabel(&etiNum);
		
		if($6.indice == -1 && strcmp($7.codigo,"") == 0){
			$$.codigo = "";
		} else {
			codeSnippets[0] = $3.codigo;
			codeSnippets[1] = switchCode($6.etiquetas,$6.numCasos,$3.temp,$6.indice);
			if(strcmp($7.codigo,"") == 0){
				codeSnippets[2] = "";
				codeSnippets[3] = "";
				codeSnippets[4] = "";
			} else {
			
				codeSnippets[2] = "GOTO ";
				codeSnippets[3] = $7.etiqueta;
				codeSnippets[4] = "\n";
			}
			codeSnippets[5] = "GOTO ";
			codeSnippets[6] = $$.next;
			codeSnippets[7] = "\n";
			codeSnippets[8] = changeLabel($6.codigo,$6.next,$$.next);
			codeSnippets[9] = changeLabel($7.codigo,$7.next,$$.next);
			codeSnippets[10] = $$.next;
			codeSnippets[11] = ":\n";
		
			$$.codigo = synthesizeCode(codeSnippets,12);
		}
	}
	| BREAK PCMA { // S -> break;
		$$.codigo = "";
	}
	| PRINT e PCMA {
		codeSnippets[0] = "PARAM ";
		codeSnippets[1] = $2.temp;
		codeSnippets[2] = "\nCALL print,1\n";
		
		$$.codigo = synthesizeCode(codeSnippets,3);
	};
	
j : CASE NUMERO PNTS s j {
		int i;
		$$.next = $5.next;
		$$.indice = $5.indice + 1;
		
		for(i=0;i<$$.indice;i++){
			$$.etiquetas[i] = $5.etiquetas[i];
			$$.numCasos[i] = $5.numCasos[i];
		}
		
		$$.etiquetas[$$.indice] = newLabel(&etiNum);
		
		if (isInt($2.tipo)) {
			$$.numCasos[$$.indice] = $2.ival;
		} else {
			yyerror("Los numeros en los case deben ser enteros");
			exit(1);
		}
		
		codeSnippets[0] = $$.etiquetas[$$.indice];
		codeSnippets[1] = ":\n";
		codeSnippets[2] = $4.codigo;
		codeSnippets[3] = "GOTO ";
		codeSnippets[4] = $$.next;
		codeSnippets[5] = "\n";
		codeSnippets[6] = $5.codigo;
		
		$$.codigo = synthesizeCode(codeSnippets,7);
		
	}
	| {
		// J -> ε
		$$.next = newLabel(&etiNum);
		$$.indice = -1; // Para que el indice en la produccion anterior se inicie en 0
		$$.codigo = ""; // El codigo debe ser cadena vacia para que no marque error "Violacion de Segmento"
	};
	
k : DEFAULT PNTS s {
		// K -> default: S
		$$.next = newLabel(&etiNum);
		$$.etiqueta = newLabel(&etiNum);
		
		codeSnippets[0] = $$.etiqueta;
		codeSnippets[1] = ":\n";
		codeSnippets[2] = $3.codigo; // S.codigo
		codeSnippets[3] = "GOTO ";
		codeSnippets[4] = $$.next;
		codeSnippets[5] = "\n";
		
		$$.codigo = synthesizeCode(codeSnippets,6);
	}
	| {
		// K -> ε
		$$.next = newLabel(&etiNum);
		$$.etiqueta = newLabel(&etiNum);
		$$.codigo = "";
	};
	
e : e SUM e {
			if(isNumero($1.tipo) && isNumero($3.tipo)){
				$$.tipo = maxType($1.tipo,$3.tipo);
				$$.temp = newTempNumero(&tempNum,&posSTT[0],GST,$$.tipo);
			
				codeSnippets[0] = $1.codigo;
				codeSnippets[1] = $3.codigo;
				codeSnippets[2] = $$.temp;
				codeSnippets[3] = " = ";
			
				if(isEmptyStr($1.codigo) && ($1.tipo != $$.tipo)){
					codeSnippets[4] = changeStr($1.temp,$1.tipo);
				} else {
					codeSnippets[4] = $1.temp;
				}
	
				codeSnippets[5] = " + ";
	
				if(isEmptyStr($3.codigo) && ($3.tipo != $$.tipo)){
					codeSnippets[6] = changeStr($3.temp,$3.tipo);
				} else {
					codeSnippets[6] = $3.temp;
				}
			
				codeSnippets[7] = "\n";
				
				$$.codigo = synthesizeCode(codeSnippets,8);
			} else {
				yyerror("Alguno de los operandos no es un número");
				exit(1);
			}
	}
	| e RES e {
		if(isNumero($1.tipo) && isNumero($3.tipo)){
				$$.tipo = maxType($1.tipo,$3.tipo);
				$$.temp = newTempNumero(&tempNum,&posSTT[0],GST,$$.tipo);
			
				codeSnippets[0] = $1.codigo;
				codeSnippets[1] = $3.codigo;
				codeSnippets[2] = $$.temp;
				codeSnippets[3] = " = ";
			
				if(isEmptyStr($1.codigo) && ($1.tipo != $$.tipo)){
					codeSnippets[4] = changeStr($1.temp,$1.tipo);
				} else {
					codeSnippets[4] = $1.temp;
				}
	
				codeSnippets[5] = " - ";
	
				if(isEmptyStr($3.codigo) && ($3.tipo != $$.tipo)){
					codeSnippets[6] = changeStr($3.temp,$3.tipo);
				} else {
					codeSnippets[6] = $3.temp;
				}
			
				codeSnippets[7] = "\n";
				
				$$.codigo = synthesizeCode(codeSnippets,8);
			} else {
				yyerror("Alguno de los operandos no es un número");
				exit(1);
			}
	}
	| e MUL e {
		if(isNumero($1.tipo) && isNumero($3.tipo)){
				$$.tipo = maxType($1.tipo,$3.tipo);
				$$.temp = newTempNumero(&tempNum,&posSTT[0],GST,$$.tipo);
			
				codeSnippets[0] = $1.codigo;
				codeSnippets[1] = $3.codigo;
				codeSnippets[2] = $$.temp;
				codeSnippets[3] = " = ";
			
				if(isEmptyStr($1.codigo) && ($1.tipo != $$.tipo)){
					codeSnippets[4] = changeStr($1.temp,$1.tipo);
				} else {
					codeSnippets[4] = $1.temp;
				}
	
				codeSnippets[5] = " * ";
	
				if(isEmptyStr($3.codigo) && ($3.tipo != $$.tipo)){
					codeSnippets[6] = changeStr($3.temp,$3.tipo);
				} else {
					codeSnippets[6] = $3.temp;
				}
			
				codeSnippets[7] = "\n";
				
				$$.codigo = synthesizeCode(codeSnippets,8);
			} else {
				yyerror("Alguno de los operandos no es un número");
				exit(1);
			}
	}
	| e DIV e {
		if(isNumero($1.tipo) && isNumero($3.tipo)){
				$$.tipo = maxType($1.tipo,$3.tipo);
				$$.temp = newTempNumero(&tempNum,&posSTT[0],GST,$$.tipo);
			
				codeSnippets[0] = $1.codigo;
				codeSnippets[1] = $3.codigo;
				codeSnippets[2] = $$.temp;
				codeSnippets[3] = " = ";
			
				if(isEmptyStr($1.codigo) && ($1.tipo != $$.tipo)){
					codeSnippets[4] = changeStr($1.temp,$1.tipo);
				} else {
					codeSnippets[4] = $1.temp;
				}
	
				codeSnippets[5] = " / ";
	
				if(isEmptyStr($3.codigo) && ($3.tipo != $$.tipo)){
					codeSnippets[6] = changeStr($3.temp,$3.tipo);
				} else {
					codeSnippets[6] = $3.temp;
				}
			
				codeSnippets[7] = "\n";
				
				$$.codigo = synthesizeCode(codeSnippets,8);
			} else {
				yyerror("Alguno de los operandos no es un número");
				exit(1);
			}
	}
	| e MOD e {
		if(isNumero($1.tipo) && isNumero($3.tipo)){
				$$.tipo = maxType($1.tipo,$3.tipo);
				$$.temp = newTempNumero(&tempNum,&posSTT[0],GST,$$.tipo);
			
				codeSnippets[0] = $1.codigo;
				codeSnippets[1] = $3.codigo;
				codeSnippets[2] = $$.temp;
				codeSnippets[3] = " = ";
			
				if(isEmptyStr($1.codigo) && ($1.tipo != $$.tipo)){
					codeSnippets[4] = changeStr($1.temp,$1.tipo);
				} else {
					codeSnippets[4] = $1.temp;
				}
	
				codeSnippets[5] = " % ";
	
				if(isEmptyStr($3.codigo) && ($3.tipo != $$.tipo)){
					codeSnippets[6] = changeStr($3.temp,$3.tipo);
				} else {
					codeSnippets[6] = $3.temp;
				}
			
				codeSnippets[7] = "\n";
				
				$$.codigo = synthesizeCode(codeSnippets,8);
			} else {
				yyerror("Alguno de los operandos no es un número");
				exit(1);
			}
	}
	| CADENA {
		$$.tipo = 4;
		$$.temp = newTempCadena(&tempNum,&posSTT[0],&posTT,GST,GTT,$1);
		$$.codigo = $1;
	}
	| NUMERO {
		int i;
		char *s,buffer[30];
		for(i=0;i<30;i++) { buffer[i] = 0; }
		
		$$.tipo = $1.tipo;
		
		if( isInt($1.tipo) ){
			sprintf(buffer,"%d",$1.ival);
		} else if( isFloat($1.tipo) ){
			sprintf(buffer,"%.2f",$1.fval);
		} else if( isDouble($1.tipo) ) {
			sprintf(buffer,"%.2f",$1.dval);
		}
		
		s = (char*) malloc(sizeof(char)*(strlen(buffer)+1));
		strcpy(s,buffer);
		
		$$.temp = s;
		$$.codigo = "";
	
	};
	
b : b OR b {
		char *s,*w;
	
		$$.trueLabel = newLabel(&etiNum);
		$$.falseLabel = $3.falseLabel;
		
		codeSnippets[0] = changeLabel($1.codigo,$1.trueLabel,$$.trueLabel);
		codeSnippets[1] = $1.falseLabel;
		codeSnippets[2] = ":\n";
		codeSnippets[3] = changeLabel($3.codigo,$3.trueLabel,$$.trueLabel);

		$$.codigo = synthesizeCode(codeSnippets,4);
	}
	| b AND b {
		$$.trueLabel = $3.trueLabel;
		$$.falseLabel = newLabel(&etiNum);
		
		codeSnippets[0] = changeLabel($1.codigo,$1.falseLabel,$$.falseLabel);
		codeSnippets[1] = $1.trueLabel;
		codeSnippets[2] = ":\n";
		codeSnippets[3] = changeLabel($3.codigo,$3.falseLabel,$$.falseLabel);
		
		$$.codigo = synthesizeCode(codeSnippets,4);		
	}
	| NOT b {
		$$.trueLabel = $2.falseLabel;
		$$.falseLabel = $2.trueLabel;
		$$.codigo = $2.codigo;
	}
	| LPAR b RPAR {
		$$.trueLabel = $2.trueLabel;
		$$.falseLabel = $2.falseLabel;
		$$.codigo = $2.codigo;
	}
	| e r e {
		$$.trueLabel = newLabel(&etiNum);
		$$.falseLabel = newLabel(&etiNum);
		
		codeSnippets[0] = $1.codigo;
		codeSnippets[1] = $3.codigo;
		codeSnippets[2] = "IF ";
		codeSnippets[3] = $1.temp;
		codeSnippets[4] = " ";
		codeSnippets[5] = $2.codigo;
		codeSnippets[6] = " ";
		codeSnippets[7] = $3.temp;
		codeSnippets[8] = " GOTO ";
		codeSnippets[9] = $$.trueLabel;
		codeSnippets[10] = "\n";
		codeSnippets[11] = "GOTO ";
		codeSnippets[12] = $$.falseLabel;
		codeSnippets[13] = "\n";
		
		$$.codigo = synthesizeCode(codeSnippets,14);
	}
	| TRUE {
		$$.trueLabel = newLabel(&etiNum);
		$$.falseLabel = newLabel(&etiNum);
		
		codeSnippets[0] = "GOTO ";
		codeSnippets[1] = $$.trueLabel;
		codeSnippets[2] = "\n";
		
		$$.codigo = synthesizeCode(codeSnippets,3);
	}
	| FALSE {
		$$.trueLabel = newLabel(&etiNum);
		$$.falseLabel = newLabel(&etiNum);
		
		codeSnippets[0] = "GOTO ";
		codeSnippets[1] = $$.falseLabel;
		codeSnippets[2] = "\n";
		
		$$.codigo = synthesizeCode(codeSnippets,3);
	};
	
r : MNRQ {
		$$.codigo = "<";
	}
	| MYRQ {
		$$.codigo = ">";
	}
	| MNROIQ {
		$$.codigo = "<=";
	}
	| MYROIQ {
		$$.codigo = ">=";
	}
	| DIFRNT {
		$$.codigo = "!=";
	}
	| IGUAL {
		$$.codigo = "==";
	};

%%


extern FILE *yyin;
extern int yylineno;

int main(int argc,char **argv){
	if(argc > 1){
		yyin = fopen(argv[1],"r");	
	}
////// INICIALIZACIONES //////
	posSTT[0] = 0;
	initGlobalTypeTable(GTT,&posTT);
	
	yyparse();
	return 0;
}

// MIS FUNCIONES

void yyerror(char *s){
	printf("%s::line:%d\n",s,yylineno-1);
}

////// TABLA DE SIMBOLOS //////

void printSymbolTableII(symbolTable ST[],int posST){
	int i;
	printf("\npos\tlexema\ttipo\ttipoVar\tdir\n\n");
	for(i=0;i<posST;i++){
		printf("%d\t%s\t%d\t%s\t%d\n",i,ST[i].lexema,ST[i].tipo,ST[i].tipoVar,ST[i].dir);	
	}		
}

void printSymbolTable(symbolTable ST[][1000],int posST,int symNum[]){
	int i,j;
	for(i=0;i<posST;i++){
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




