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
%token <cadena> OPERADOR_IGUALDAD                   // == !=
%token <cadena> OPERADOR_RELACIONAL                 // < > <= >=
%token <cadena> OPERADOR_CORRIMIENTO                // << >>
%token <cadena> OPERADOR_MULTIPLICATIVO             // * / %
%token <cadena> OPERADOR_INCREMENTO                 // ++ --
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


// PALABRAS RESERVADAS
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

/* %type <tipo>   */ 
%type <cadena> error

%%

input: /* */
    | input line
;

line: declaracion '\n'              { numeroLinea++; }
    | sentencia '\n'                { numeroLinea++; }
    | error '\n'                    { strcpy($<cadena>$, $<cadena>1); printf("\n***Error sintactico - Linea %i: %s***\n", numeroLinea, $<cadena>1); numeroLinea++; }
    | error ';'                     { strcpy($<cadena>$, $<cadena>1); printf("\n***Error sintactico - Linea %i: %s***\n", numeroLinea, $<cadena>1); numeroLinea++; }  

;

/* **************************************** EXPRESIONES **************************************** */
expresion: expresionAsignacion 
    | expresion ',' expresionAsignacion
;

expresionAsignacion: expresionCondicional 
    | expresionUnaria '=' expresionAsignacion 
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
    | expresionY '&' expresionIgualdad
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
    | expresionAditiva '+' expresionMultiplicativa 
    | expresionAditiva '-' expresionMultiplicativa 
;

expresionMultiplicativa: expresionConversion 
    | expresionMultiplicativa '*' expresionConversion 
    | expresionMultiplicativa OPERADOR_MULTIPLICATIVO expresionConversion  
;

expresionConversion: expresionUnaria 
    | '(' TIPO_DATO ')' expresionConversion
;

expresionUnaria: expresionSufijo            
    | OPERADOR_INCREMENTO expresionUnaria  
    | operadorUnario expresionConversion   
    | OPERADOR_SIZEOF expresionUnaria       
    | OPERADOR_SIZEOF '(' TIPO_DATO ')'     
;

operadorUnario:'&'
    |'*'
    |'+'
    |'-'
    |'~'
    |'!'
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
declaracion: declaracionVariable
    |   declaracionFuncion
;

/****/

declaracionVariable: TIPO_DATO listaDeclaradores ';' {printf("de tipo %s.", $<cadena>1);} 
;

listaDeclaradores: declarador           { printf("\nSe declaro una variable ");    }
    | listaDeclaradores ',' declarador  { printf("y otra variable ");               }
;

declarador: decla                   
    | decla '=' inicializador
;

inicializador: expresionAsignacion
    | '{' listaInicializadores '}'
    | '{'listaInicializadores ',' listaInicializadores '}'
;

listaInicializadores: inicializador
    | listaInicializadores ',' inicializador  
;

/****/

declaracionFuncion: TIPO_DATO IDENTIFICADOR '(' listaParametros_ ')' ';'     { printf("\nSe declaro una funcion\n"); }
    | TIPO_DATO IDENTIFICADOR '(' listaParametros_ ')' sentenciaCompuesta    { printf("\nSe definio una funcion\n"); }
;

listaParametros: parametro
    | listaParametros ',' parametro 
;

parametro: TIPO_DATO decla
;

/****/

decla: /* */
    | declaradorDirecto
    | puntero declaradorDirecto
    | '&' declaradorDirecto
;

puntero: '*'
    | '*' puntero
;

declaradorDirecto: IDENTIFICADOR 
    | declaradorDirecto '[' expresionConstante_ ']'    { printf("\nSe declaro un arreglo\n");  }
;

/* **************************************** SENTENCIAS **************************************** */ 
sentencia: sentenciaExpresion
    | sentenciaCompuesta 
    | sentenciaSeleccion 
    | sentenciaIteracion 
    | sentenciaSalto   
    | sentenciaEtiquetada     
;

sentenciaExpresion: expresion_ ';'
;

expresion_: /* */    { printf("\nSentencia expresion - VACIA.\n");   }
    | expresion      { printf("\nSentencia expresion\n");   }   
;
sentenciaCompuesta: '{' listaDeclaraciones_ listaSentencias_ '}'    { printf("\nSentencia expresion - COMPUESTA.\n");   }
;

listaDeclaraciones: declaracion 
    | listaDeclaraciones declaracion
;

listaSentencias: sentencia 
    | listaSentencias sentencia
;

sentenciaSeleccion: IF '(' expresion ')' sentencia  { printf("\nSentencia de SELECCION - IF.\n");         }    
    | IF '(' expresion ')' sentencia ELSE sentencia { printf("\nSentencia de SELECCION - IF/ELSE.\n");    } 
    | SWITCH '(' expresion ')' sentencia            { printf("\nSentencia de SELECCION - SWITCH.\n");     };

sentenciaEtiquetada: CASE expresionConstante ':' sentencia 
    | DEFAULT ':' sentencia 
    | IDENTIFICADOR ':' sentencia /*Las sentencias case y default se utilizan solo dentro de una sentencia switch.*/
;

sentenciaIteracion: WHILE '(' expresion ')' sentencia               { printf("\nSentencia de ITERACION - WHILE.\n");      } 
    | DO sentencia WHILE '(' expresion ')' ';'                      { printf("\nSentencia de ITERACION - DO/WHILE.\n");   } 
    | FOR '(' expresion_';' expresion_ ';' expresion_ ')' sentencia { printf("\nSentencia de ITERACION - FOR.\n");        }
;

sentenciaSalto: CONTINUE ';'    { printf("\nSentencia de SALTO - CONTINUE.\n");   }
    | BREAK ';'                 { printf("\nSentencia de SALTO - BREAK.\n");      } 
    | RETURN expresion_ ';'     { printf("\nSentencia de SALTO - RETURN.\n");     } 
    | GOTO IDENTIFICADOR ';'    { printf("\nSentencia de SALTO - GOTO.\n");       }
;


/* **************************************** OPCIONALES **************************************** */
// Opcionales en "Expresiones"
listaArgumentos_: /* */
    | listaArgumentos
;

// Opcionales en "Declaraciones"

expresionConstante_: /* */
    | expresionConstante
;

listaParametros_: /* */ 
    | listaParametros
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

    #ifdef BISON_DEBUG
        yydebug = 1;
    #endif 
    
    yyin = fopen("test.c", "r");
    yyparse();
}