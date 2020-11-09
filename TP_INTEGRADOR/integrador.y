%{
    #include <stdio.h>
    #include <ctype.h>
    #include <string.h>
    #include <stdlib.h>

    int yylex();
    int yywrap(){ return(1); }
    void yyerror (char const *s) {}

    FILE* yyin;

%}

%union {
    char cadena[100];
    int entero;
    float real;
}

/* %token <tipo> LEXEMA */
%token <cadena> IDENTIFICADOR

// OPERADORES
%token <cadena> OPERADOR_ASIGNACION                 // = *= /= %= += *= <<= >>= &= ^= |=
%token <cadena> OPERADOR_O_LOGICO                   // ||
%token <cadena> OPERADOR_Y_LOGICO                   // &&
%token <cadena> OPERADOR_O_INCLUSIVO                // |
%token <cadena> OPERADOR_O_EXCLUSIVO                // ^
%token <cadena> OPERADOR_Y                          // &
%token <cadena> OPERADOR_IGUALDAD                   // == !=
%token <cadena> OPERADOR_RELACIONAL                 // < > <= >=
%token <cadena> OPERADOR_CORRIMIENTO                // << >>
%token <cadena> OPERADOR_ADITIVO                    // + - 
%token <cadena> OPERADOR_MULTIPLICATIVO             // * /
%token <cadena> OPERADOR_INCREMENTO                 // ++ --
%token <cadena> OPERADOR_UNARIO                     // & * + - ~ !
%token <cadena> OPERADOR_SIZEOF                     // sizeof
%token <cadena> OPERADOR_SELECCION_MIEMBRO          // . ->

// CONSTANTES
%token <cadena> CONSTANTE_CADENA                    // "*"
%token <entero> CONSTANTE_DECIMAL                   // [1-9][0-9]*
%token <entero> CONSTANTE_OCTAL                     // 0[0-7]*     
%token <entero> CONSTANTE_HEXADECIMAL               // 0[xX][a-fA-F0-9]+
%token <real>   CONSTANTE_REAL                      //  
%token <entero> CONSTANTE_CARACTER                  // 

// TIPOS DE DATO
%token <cadena> TIPO_DATO                           // void char short int long float double signed unsigned
%token <cadena> ESPECIFICADOR_CLASE_ALMACENAMIENTO  // typedef static auto register extern
%token <cadena> CALIFICADOR_TIPO                    // const volatile
%token <cadena> STRUCT_O_UNION                      // struct union
%token <cadena> ELLIPSIS                            // . . .

// PALABRAS RESERVADAS
%token <cadena> ENUM 
%token <cadena> IF
%token <cadena> ELSE
%token <cadena> SWITCH
%token <cadena> WHILE
%token <cadena> DO
%token <cadena> FOR
%token <cadena> CASE
%token <cadena> DEFAULT
%token <cadena> CONTINUE
%token <cadena> BREAK
%token <cadena> RETURN
%token <cadena> GOTO

%%

input: /**/
    | input line
;

line: declaracion '\n'  
    | sentencia '\n'    
    | error '\n'          
;

/* **** Expresiones **** */

expresion: expresionAsignacion 
    | expresion ',' expresionAsignacion
;

expresionAsignacion: expresionCondicional 
    | expresionUnaria OPERADOR_ASIGNACION expresionAsignacion
;

expresionCondicional: expresionOLogico 
    | expresionOLogico '?' expresion ':' expresionCondicional
;

expresionOLogico: expresionYLogico 
    | expresionOLogico OPERADOR_O_LOGICO expresionYLogico
;

expresionYLogico: expresionOInclusivo 
    | expresionYLogico OPERADOR_Y_LOGICO expresionOInclusivo
;

expresionOInclusivo: expresionOExcluyente 
    | expresionOInclusivo OPERADOR_O_INCLUSIVO expresionOExcluyente
;

expresionOExcluyente: expresionY 
    | expresionOExcluyente OPERADOR_O_EXCLUSIVO expresionY
;

expresionY: expresionIgualdad 
    | expresionY OPERADOR_Y expresionIgualdad
;

expresionIgualdad: expresionRelacional 
    | expresionIgualdad OPERADOR_IGUALDAD expresionRelacional 
;

expresionRelacional: expresionCorrimiento 
    | expresionRelacional OPERADOR_RELACIONAL expresionCorrimiento 
;

expresionCorrimiento: expresionAditiva 
    | expresionCorrimiento OPERADOR_CORRIMIENTO expresionAditiva 
;

expresionAditiva: expresionMultiplicativa 
    | expresionAditiva OPERADOR_ADITIVO expresionMultiplicativa 
;

expresionMultiplicativa: expresionConversion 
    | expresionMultiplicativa OPERADOR_MULTIPLICATIVO expresionConversion 
;

expresionConversion: expresionUnaria 
    | '(' nombreTipo ')' expresionConversion
;

expresionUnaria: expresionSufijo 
    | OPERADOR_INCREMENTO expresionUnaria 
    | OPERADOR_UNARIO expresionConversion 
    | OPERADOR_SIZEOF expresionUnaria 
    | OPERADOR_SIZEOF '(' nombreTipo ')'
;

expresionSufijo: expresionPrimaria 
    | expresionSufijo '[' expresion ']' /* arreglo */
    | expresionSufijo '(' listaArgumentos ')' /* invocacion */
    | expresionSufijo OPERADOR_SELECCION_MIEMBRO IDENTIFICADOR 
    | expresionSufijo OPERADOR_INCREMENTO
;

listaArgumentos: /**/
    | expresionAsignacion 
    | listaArgumentos ',' expresionAsignacion
;

expresionPrimaria: IDENTIFICADOR 
    | constante 
    | CONSTANTE_CADENA 
    | '(' expresion ')'
;

expresionConstante: expresionCondicional
; //Las expresiones constantes pueden ser evaluadas durante la traduccion en lugar de durante la ejecucion.

constante: CONSTANTE_DECIMAL             
    | CONSTANTE_OCTAL               
    | CONSTANTE_HEXADECIMAL       
    | CONSTANTE_REAL                 
    | CONSTANTE_CARACTER                         
;


/* **** Declaraciones **** */

declaracion: especificadoresDeclaracion listaDeclaradores_
;

listaDeclaradores_: /**/
    | listaDeclaradores;

especificadoresDeclaracion: ESPECIFICADOR_CLASE_ALMACENAMIENTO especificadoresDeclaracion_
    | especificadorTipo especificadoresDeclaracion_
    | CALIFICADOR_TIPO especificadoresDeclaracion_
;

especificadoresDeclaracion_: /**/
    | especificadoresDeclaracion
;

listaDeclaradores: declarador 
    | listaDeclaradores ',' declarador
;

declarador: decla 
    | decla '=' inicializador
;

inicializador: expresionAsignacion  /* Inicializacion de tipos escalares */
    | '{' listaInicializadores '}'  /* Inicializacion de tipos estructurados */
    | '{' listaInicializadores ',' '}'
;

listaInicializadores: inicializador 
    | listaInicializadores ',' inicializador
;

especificadorTipo: TIPO_DATO
    | especificadorStructOUnion
    | especificadorEnum
    | nombreTypedef
;

especificadorStructOUnion: STRUCT_O_UNION IDENTIFICADOR_ '{' listaDeclaracionesStruct '}' 
    | STRUCT_O_UNION IDENTIFICADOR
;

IDENTIFICADOR_: /**/
    | IDENTIFICADOR
;

listaDeclaracionesStruct: declaracionStruct 
    | listaDeclaracionesStruct declaracionStruct
;

declaracionStruct: listaCalificadores declaradoresStruct ';'
;

listaCalificadores: especificadorTipo listaCalificadores
    | CALIFICADOR_TIPO listaCalificadores
;

listaCalificadores_: /**/
    | listaCalificadores
;

declaradoresStruct: declaStruct 
    | declaradoresStruct ',' declaStruct
;

declaStruct: decla 
    | decla_ ':' expresionConstante
;

decla_: /**/
    | decla
;

decla: puntero_ declaradorDirecto
;

puntero_: /**/
    | puntero
;

puntero: '*' listaCalificadoresTipos_ 
    | '*' listaCalificadoresTipos_ puntero
;

listaCalificadoresTipos_: /**/
    | listaCalificadoresTipos
;
listaCalificadoresTipos: CALIFICADOR_TIPO 
    | listaCalificadoresTipos CALIFICADOR_TIPO
;

declaradorDirecto: IDENTIFICADOR 
    | '(' decla ')' 
    | declaradorDirecto '[' expresionConstante_ ']' 
    | declaradorDirecto '(' listaTiposParametros ')' /* Declarador nuevo estilo */
    | declaradorDirecto '(' listaIdentificadores_ ')' /* Declarador estilo obsoleto */
;

expresionConstante_: /**/
    | expresionConstante
;

listaIdentificadores_: /**/
    | listaIdentificadores
;

listaTiposParametros: listaParametros 
    | listaParametros ',' ELLIPSIS
;

listaParametros: declaracionParametro 
    | listaParametros ',' declaracionParametro
;

declaracionParametro: especificadoresDeclaracion decla  /* Parametros "nombrados" */
    | especificadoresDeclaracion declaradorAbstracto_ /* Parametros "anonimos" */
;

declaradorAbstracto_: /**/
    | declaradorAbstracto
;

listaIdentificadores: IDENTIFICADOR 
    | listaIdentificadores ',' IDENTIFICADOR
;

especificadorEnum: ENUM IDENTIFICADOR_ { listaEnumeradores } 
    | ENUM IDENTIFICADOR
;

listaEnumeradores: enumerador 
    | listaEnumeradores ',' enumerador
;

enumerador: constanteEnumeracion 
    | constanteEnumeracion '=' expresionConstante
;

constanteEnumeracion: IDENTIFICADOR
;

nombreTypedef: IDENTIFICADOR
;

nombreTipo: listaCalificadores declaradorAbstracto_
;

declaradorAbstracto: puntero 
    | puntero_ declaradorAbstractoDirecto
;

declaradorAbstractoDirecto: '(' declaradorAbstracto ')' 
    | declaradorAbstractoDirecto_ '[' expresionConstante_ ']' 
    | declaradorAbstractoDirecto_ '(' listaTiposParametros_ ')'
;

listaTiposParametros_: /**/ 
    | listaTiposParametros
;
declaradorAbstractoDirecto_: /**/
    | declaradorAbstractoDirecto
;

/* **** Sentencias **** */ 
sentencia: sentenciaExpresion
    | sentenciaCompuesta 
    | sentenciaSeleccion 
    | sentenciaIteracion 
    | sentenciaEtiquetada 
    | sentenciaSalto
;

sentenciaExpresion: expresion_ ';'
;

expresion_: /**/ 
    | expresion_
;
sentenciaCompuesta: '{' listaDeclaraciones listaSentencias '}'
;

listaDeclaraciones: /**/
    | declaracion 
    | listaDeclaraciones declaracion
;

listaSentencias: /**/
    | sentencia 
    | listaSentencias sentencia
;

sentenciaSeleccion: IF '(' expresion ')' sentencia 
    | IF '(' expresion ')' sentencia ELSE sentencia 
    | SWITCH '(' expresion ')' sentencia /* La expresion e controla un switch debe ser de tipo entero. */
;

sentenciaIteracion: WHILE '(' expresion ')' sentencia 
    | DO sentencia WHILE '(' expresion ')' ';' 
    | FOR '(' expresion_';' expresion_ ';' expresion_ ')' sentencia
;

sentenciaEtiquetada: CASE expresionConstante ':' sentencia 
    | DEFAULT ':' sentencia 
    | IDENTIFICADOR ':' sentencia /*Las sentencias case y default se utilizan solo dentro de una sentencia switch.*/
;

sentenciaSalto: CONTINUE ';'
    | BREAK ';' 
    | RETURN expresion_ ';' 
    | GOTO IDENTIFICADOR ';'
;

%%

int main() {
    //yyin = fopen("", "r");
    yyparse();
}