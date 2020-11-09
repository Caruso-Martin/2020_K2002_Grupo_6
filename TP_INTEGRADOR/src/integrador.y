%{
    #include <stdio.h>
    #include <ctype.h>
    #include <string.h>
    #include <stdlib.h>

    int yylex();
    int yywrap(){ return(1); }
    void yyerror (char const *s) {}

    FILE* yyin;

    int numeroLinea = 1;

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
%token <cadena> OPERADOR_MULTIPLICATIVO             // * / %
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

// DECLARADORES
%token <cadena> TIPO_DATO                           // void char short int long float double signed unsigned
%token <cadena> ESPECIFICADOR_CLASE_ALMACENAMIENTO  // typedef static auto register extern
%token <cadena> CALIFICADOR_TIPO                    // const volatile
%token <cadena> STRUCT_O_UNION                      // struct union
%token <cadena> ELLIPSIS                            // ...

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

/* %type <tipo>  */
%type <cadena> error

%%

input: /* */
    | input line
;

line: declaracion '\n'  { numeroLinea++; }
    | sentencia '\n'    { numeroLinea++; }
    | error '\n'        { printf("\n***Error sintactico - Linea %i***\n", numeroLinea); numeroLinea++; }        
;

/* **************************************** EXPRESIONES **************************************** */
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
    | expresionSufijo '(' listaArgumentos_ ')' /* invocacion */
    | expresionSufijo OPERADOR_SELECCION_MIEMBRO IDENTIFICADOR 
    | expresionSufijo OPERADOR_INCREMENTO
;

listaArgumentos: expresionAsignacion 
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


/* **************************************** DECLARACIONES **************************************** */

declaracion: especificadoresDeclaracion listaDeclaradores_
;

especificadoresDeclaracion: ESPECIFICADOR_CLASE_ALMACENAMIENTO especificadoresDeclaracion_  { printf(" - Clase de almacenamiento : %s", $<cadena>1);    }
    | especificadorTipo especificadoresDeclaracion_                                         { printf(" - Tipo : %s", $<cadena>1);                       }
    | CALIFICADOR_TIPO especificadoresDeclaracion_                                          { printf(" - Calificador : %s", $<cadena>1);                }
;

listaDeclaradores: declarador 
    | listaDeclaradores ',' declarador
;

declarador: decla               { printf("\nSe declaro una variable");    }
    | decla '=' inicializador   { printf("\nSe inicializo una variable"); }
;

inicializador: expresionAsignacion  /* Inicializacion de tipos escalares     */
    | '{' listaInicializadores '}'  /* Inicializacion de tipos estructurados */
    | '{' listaInicializadores ',' '}'
;

listaInicializadores: inicializador 
    | listaInicializadores ',' inicializador
;

especificadorTipo: TIPO_DATO
    /*| especificadorStructOUnion*/
    | especificadorEnum
    | nombreTypedef
;

// STRUCT-UNION 
/*A1
especificadorStructOUnion: STRUCT_O_UNION IDENTIFICADOR_ '{' listaDeclaracionesStruct '}' 
    | STRUCT_O_UNION IDENTIFICADOR
;

listaDeclaracionesStruct: declaracionStruct 
    | listaDeclaracionesStruct declaracionStruct
;

declaracionStruct: listaCalificadores declaradoresStruct ';'
;
A1*/
/*
listaCalificadores: especificadorTipo listaCalificadores
    | CALIFICADOR_TIPO listaCalificadores
;*/
/*B2
declaradoresStruct: declaStruct 
    | declaradoresStruct ',' declaStruct
;

declaStruct: decla 
    | decla_ ':' expresionConstante
;
B2*/
decla: puntero_ declaradorDirecto
;

puntero: '*' /*listaCalificadoresTipos_ */
    | '*' /*listaCalificadoresTipos_*/ puntero
;

/*listaCalificadoresTipos: CALIFICADOR_TIPO 
    | listaCalificadoresTipos CALIFICADOR_TIPO
;*/

declaradorDirecto: IDENTIFICADOR 
    | '(' decla ')' 
    | declaradorDirecto '[' expresionConstante_ ']' 
    | declaradorDirecto '(' listaTiposParametros ')'    { printf("\nSe declaro una funcion"); }
;

/*  declaradorDirecto '(' listaIdentificadores_ ')'  Declarador estilo obsoleto */

listaTiposParametros: listaParametros 
    | listaParametros ',' ELLIPSIS
;

listaParametros: declaracionParametro 
    | listaParametros ',' declaracionParametro
;

declaracionParametro: especificadoresDeclaracion decla  /* Parametros nombrados */
    | especificadoresDeclaracion declaradorAbstracto_   /* Parametros anonimos  */
;

especificadorEnum: ENUM IDENTIFICADOR_ '{' listaEnumeradores '}' 
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

nombreTipo: /*listaCalificadores*/ declaradorAbstracto_
;

declaradorAbstracto: puntero 
    | puntero_ declaradorAbstractoDirecto
;

declaradorAbstractoDirecto: '(' declaradorAbstracto ')' 
    | declaradorAbstractoDirecto_ '[' expresionConstante_ ']' 
    | declaradorAbstractoDirecto_ '(' listaTiposParametros_ ')'
;


/* **************************************** SENTENCIAS **************************************** */ 
sentencia: sentenciaExpresion
    | sentenciaCompuesta 
    | sentenciaSeleccion 
    | sentenciaIteracion 
    | sentenciaSalto        
;

sentenciaExpresion: expresion_ ';'
;

expresion_: /* */    { printf("\nSentencia expresion - VACIA.");   }
    | expresion     
;
sentenciaCompuesta: '{' listaDeclaraciones_ listaSentencias_ '}'    { printf("\nSentencia expresion - COMPUESTA.");   }
;

listaDeclaraciones: declaracion 
    | listaDeclaraciones declaracion
;

listaSentencias: sentencia 
    | listaSentencias sentencia
;

sentenciaSeleccion: IF '(' expresion ')' sentencia  { printf("\nSentencia de SELECCION - IF.");         }    
    | IF '(' expresion ')' sentencia ELSE sentencia { printf("\nSentencia de SELECCION - IF/ELSE.");    } 
    | SWITCH '(' expresion ')' sentencia            { printf("\nSentencia de SELECCION - SWITCH.");     }
    | SWITCH '(' expresion ')' sentenciaEtiquetada  { printf("\nSentencia de SELECCION - SWITCH.");     }
;

sentenciaEtiquetada: CASE expresionConstante ':' sentencia 
    | DEFAULT ':' sentencia 
    | IDENTIFICADOR ':' sentencia /*Las sentencias case y default se utilizan solo dentro de una sentencia switch.*/
;

sentenciaIteracion: WHILE '(' expresion ')' sentencia               { printf("\nSentencia de ITERACION - WHILE.");      } 
    | DO sentencia WHILE '(' expresion ')' ';'                      { printf("\nSentencia de ITERACION - DO/WHILE.");   } 
    | FOR '(' expresion_';' expresion_ ';' expresion_ ')' sentencia { printf("\nSentencia de ITERACION - FOR.");        }
;

sentenciaSalto: CONTINUE ';'    { printf("\nSentencia de SALTO - CONTINUE.");   }
    | BREAK ';'                 { printf("\nSentencia de SALTO - BREAK.");      } 
    | RETURN expresion_ ';'     { printf("\nSentencia de SALTO - RETURN.");     } 
    | GOTO IDENTIFICADOR ';'    { printf("\nSentencia de SALTO - GOTO.");       }
;


/* **************************************** OPCIONALES **************************************** */
// Opcionales en "Expresiones"
listaArgumentos_: /* */
    | listaArgumentos
;

// Opcionales en "Declaraciones"

listaDeclaradores_: /* */
    | listaDeclaradores
;

especificadoresDeclaracion_: /* */
    | especificadoresDeclaracion
;

IDENTIFICADOR_: /* */
    | IDENTIFICADOR
;

//listaCalificadores_: /* */
//    | listaCalificadores
//;

decla_: /* */
    | decla
;

puntero_: /* */
    | puntero
;

//listaCalificadoresTipos_: /* */
//    | listaCalificadoresTipos
//;

expresionConstante_: /* */
    | expresionConstante
;

declaradorAbstracto_: /* */
    | declaradorAbstracto
;

listaTiposParametros_: /* */ 
    | listaTiposParametros
;
declaradorAbstractoDirecto_: /* */
    | declaradorAbstractoDirecto
;

// Opcionales en "Sentencias"
listaDeclaraciones_: /* */
    | listaDeclaraciones 
;

listaSentencias_: /* */ 
    | listaSentencias 
;

%%

int main() {
    yyin = fopen("test.c", "r");
    yyparse();
}