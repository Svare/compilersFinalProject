%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	#include "y.tab.h"

	char getCharacter(char *yytext);
	char* getString(char *yytext);
%}

%option yylineno
%option noyywrap

%s COMM
%s COMMII

letra [a-zA-Z]
digito [0-9]
escapes [\n\t\b\r\a\\]
carEsp [!#$%&()*+,-./:;<=>?@[\]^_{}|~]
caracter \'({carEsp}|{letra}|{digito})\'
cadena \"({carEsp}|{letra}|{digito}|{escapes}|" ")*\"

id ({letra}|"_")({letra}|{digito}|"_")*

entero {digito}+
flotante {digito}+"."{digito}+

%%

<INITIAL>{

	"/*" {
		// printf("INICIO COMENTARIO");
		BEGIN COMM;
	}
	
	"*/" {
		printf("\nerrorLexico::linea:%d -> %s [NO SE INDICA EL INICIO DEL COMENTARIO]\n\n",yylineno,yytext);
	}

	"//" {
		BEGIN COMMII;
	}

	{caracter} {
		yylval.caracter = getCharacter(yytext);
	//	printf("Caracter.caracter: %c\n",yylval.caracter);
		return CARACTER;
	}
	
	{cadena} {
		yylval.cadena = getString(yytext);
	//	printf("Cadena.cadena: %s\n",yylval.cadena);
		return CADENA;
	}
	
	"{" { return LLLVE; }
	
	"}" { return RLLVE; }
	
	"[" { return LCHT; }
	
	"]" { return RCHT; }
	
	"(" { return LPAR; }
	
	")" { return RPAR; }
	
	"," { return COMA; }
	
	";" { return PCMA; }
	
	":" { return PNTS; }
	
	"=" { return ASIG; }
	
	"." { return PUNTO; }
	
	"+" { return SUM; }
	
	"-" { return RES; }
	
	"*" { return MUL; }
	
	"/" { return DIV; }
	
	"%" { return MOD; }
	
	"<" { return MNRQ; }
	
	">" { return MYRQ; }
	
	"<=" { return MNROIQ; }
	
	">=" { return MYROIQ; }
	
	"!=" { return DIFRNT; }
	
	"==" { return IGUAL; }
	
	"||" { return OR; }
	
	"&&" { return AND; }
	
	"!" { return NOT; }
	
	int {
		yylval.cadena = "int";
		return INT;
	}
	
	float {
		yylval.cadena = "float";
		return FLOAT;
	}
	
	double {
		yylval.cadena = "double";
		return DOUBLE;		
	}
	
	char {
		yylval.cadena = "char";
		return CHAR;
	}
	
	void {
		yylval.cadena = "void";
		return VOID;
	}
	
	struct {
		yylval.cadena = "struct";
		return STRUCT;
	}
	
	func { return FUNC; }
	
	if { return IF; }
	
	else { return ELSE; }
	
	while { return WHILE; }
	
	do { return DO; }
	
	for { return FOR; }
	
	return { return RETURN; }
	
	switch { return SWITCH; }
		
	break { return BREAK; }
	
	print { return PRINT; }
	
	case { return CASE; }
	
	default { return DEFAULT; }
	
	true { return TRUE; }
	
	false { return FALSE; }
	
	{id} {
		char *id;
		id = (char*) malloc(sizeof(char)*yyleng);
		strcpy(id,yytext);
		yylval.cadena = id;
		return ID;
	}

	{entero} {
		yylval.numero.ival = atoi(yytext);
		yylval.numero.tipo = 1;
		return NUMERO;
	}
	
	{flotante} {
		yylval.numero.fval = atof(yytext);
		yylval.numero.tipo = 2;
		return NUMERO;
	}
	
	[ \n\t] {}
	
	. {
		printf("errorLexico::linea:%d -> %s [NO SE RECONOCE LA EXPRESION]\n\n",yylineno,yytext);
	}
}

<COMM>{

	"*/" {
		// printf("FIN COMENTARIO");
		BEGIN INITIAL;
	}

	[^"*""/"] {
		// Cualquier cosa que no sea * ó /
		// ejemplo: hola como estas 341241 11 1
	}

	"*" {}

	"/" {}
}

<COMMII>{
	[^\n] {}
	
	"\n" {
		BEGIN INITIAL;
	}
}

%%

char getCharacter(char *yytext){
	return yytext[1];
}

char* getString(char *yytext) {
	int i; // Contador para el for
	char *s; // Apuntador a cadena que vamos a regresar
	
	/* Reservamos espacio en memoria para almacenar los caracteres de la cadena que vamos a regresar,
	   su tamaño va a ser el de la cadena que esta recibiendo a la entrada -2 por que lo que pretende
	   esta funcion es eliminar las " " que tiene la cadena de entrada */
	   
	s = (char*) malloc(sizeof(char)*((int) strlen(yytext) - 2));
	
	/* Variable de apoyo, ahí vamos a ir almacenando la nueva cadena, tiene el tamaño de la cadena del
	   parametro -1 ya que al quitar las dos " seria menos dos pero necesitamos uno extra para el caracter
	   de fin de cadena '\0' */	
	
	char buffer[(int) strlen(yytext)-1];
	
	// El for se encarga de copiar lo que queremos de la cadena del parametro a nuestro buffer
	
	for (i=0;i<(int)strlen(yytext)-2;i++){
		buffer[i] = yytext[i+1];	
	}
	
	buffer[i] = '\0'; // Anexamos al buffer el caracter de fin de cadena

	strcpy(s,buffer); // Copio el contenido del buffer al apuntador que voy a retornar

	return s;
}


