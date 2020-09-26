%option noyywrap

%{
    #include <stdio.h>
    #include "funcionesUtiles.h"
%}

PALABRAS_RESERVADAS (break|continue|default|enum|goto|return|sizeof|typedef|union)
ESPECIFICADOR_DE_CLASE_DE_ALMACENAMIENTO (typedef|static|auto|register|extern)
ESPECIFICADOR_DE_TIPO (void|char|short|int|long|float|double|signed|unsigned)
CALIFICADOR_DE_TIPO (const|volatile)
STRUCT_O_UNION (struct|union)

LETRA [a-zA-Z]
DIGITO_DECIMAL [0-9]
DIGITO_DECIMAL_SIN_CERO [1-9]
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 

SUFIJO_LONG (l|L)
SUFIJO_ENTERO ({SUFIJO_LONG}|u|U)

SUFIJO_REAL ({SUFIJO_LONG}|f|F)
CONSTANTE_FRACCION (({DIGITO_DECIMAL}*)?"."{DIGITO_DECIMAL}*|{DIGITO_DECIMAL}*)
PARTE_EXPONENTE (e|E)("+"|"-")?{DIGITO_DECIMAL}*

SECUENCIA_ESCAPE_SIMPLE (a|b|f|n|r|t|v|\'|\"|\?|\\)

CARACTER_DE_PUNTUACION (\[|\]|\(|\)|\{|\}|\.|\-\>|\+\+|\-\-|\&|\*|\+|\-|\˜|\!|\/|\%|\<\<|\>\>|\<|\>|\<\=|\>\=|\=\=|\!\=|\ˆ|\||\&\&|\|\||\=|\*\=|\/\=|\%\=|\+\=|\-\=|\<\<\=|\>\>\=|\&\=|\ˆ\=|\|\=|\?|\:|\;|\.\.\.|\,|\#|\#\#)

%%
\n contadorDeLinea++;
{PALABRA_RESERVADA} {strcpy(yylval.cadena, yytext); return PALABRA_RESERVADA;}
{ESPECIFICADOR_DE_CLASE_DE_ALMACENAMIENTO} {strcpy(yylval.cadena, yytext); return ESPECIFICADOR_DE_CLASE_DE_ALMACENAMIENTO}
{ESPECIFICADOR_DE_TIPO} {strcpy(yylval.cadena, yytext); return ESPECIFICADOR_DE_TIPO;}
{CALIFICADOR_DE_TIPO}  {strcpy(yylval.cadena, yytext); return CALIFICADOR_DE_TIPO}
{STRUCT_O_UNION} {strcpy(yylval.cadena, yytext); return STRUCT_O_UNION;}


\#(include|define) {pushListaSinRepetir(&directivas, yytext, yyleng);}


({LETRA}|"_")({LETRA}|"_"|{DIGITO_DECIMAL})* {strcpy(yylval.cadena, yytext); return IDENTIFICADOR;}

{CARACTER_DE_PUNTUACION}  {return CARACTER_DE_PUNTUACION;}

{DIGITO_DECIMAL_SIN_CERO}{DIGITO_DECIMAL}*{SUFIJO_ENTERO}? {yylval.entero = strtol(yytext, NULL, 0); return ENTERO;}
0{DIGITO_OCTAL}*{SUFIJO_ENTERO}? {yylval.entero = strtol(yytext, NULL, 0); return ENTERO;}
0[xX]{DIGITO_HEXADECIMAL}+{SUFIJO_ENTERO}? {yylval.entero = strtol(yytext, NULL, 0); return ENTERO;}
({CONSTANTE_FRACCION}{PARTE_EXPONENTE}?{SUFIJO_REAL}?|{CONSTANTE_FRACCION}{PARTE_EXPONENTE}{SUFIJO_REAL}?) {yylval.doble = atof(yytext); return REAL;}
\'([^\\\']|\\{SECUENCIA_ESCAPE_SIMPLE}|\\{DIGITO_OCTAL}{1,3}|\\x{DIGITO_HEXADECIMAL}{1,2})\' {strcpy(yylval.cadena, yytext); return CONSTANTE_CARACTER}


\"(([^\"]|\\\")*[^\\])?\" {strcpy(yylval.cadena, yytext); return LITERAL_CADENA;}

\/\/.*  {strcpy(yylval.cadena, yytext); return COMENTARIO;}
\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/  {strcpy(yylval.cadena, yytext); return COMENTARIO;}

([ ])+ {}
. {pushLista(&noReconocidos, yytext, contadorDeLinea, yyleng);}
%%

int main() {
    // Acciones previas a la invocación den analizador léxico 

    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");	

    // Invocación del analizador léxico 

    yylex();
	

    
    return 0;
}