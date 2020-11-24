%{
    #include <ctype.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "validaciones_semanticas.c"

    int yylex();
    int yywrap(){ return(1); }
    void yyerror (char const *s) {}

    FILE* yyin;

    extern int yylineno;

    char* tipoAuxiliar  = "";
    char* tipoAuxiliar1 = "";
    char* tipoAuxiliar2 = "";
    char* identificadorAuxiliar = ""; 
    int validacionBinaria = 0;

%}

%union {
    char* cadena;
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
%token <cadena> OPERADOR_MULTIPLICATIVO             // * 
%token <cadena> OPERADOR_INCREMENTO                 // ++ --
%token <cadena> OPERADOR_SIZEOF                     // sizeof

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
%type <cadena> expresionSufijo

%type <cadena> declaracionVariable
%type <cadena> declarador
%type <cadena> decla
%type <cadena> puntero
%type <cadena> declaradorDirecto
%type <cadena> expresionPrimaria

%type <cadena> constante

%%
input: /* */
    | input line
    ;

line: declaracion '\n'            
    | sentencia '\n'        
    | error '\n'    { printf("\n***Error sintactico - Linea %i: %s***", yylineno, $<cadena>1); }
    | error ';'     { printf("\n***Error sintactico - Linea %i: %s***", yylineno, $<cadena>1); }  
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
    | expresionAditiva '+' expresionMultiplicativa  { numeroLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0; }
    | expresionAditiva '-' expresionMultiplicativa  { numeroLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0; }
    ;

expresionMultiplicativa: expresionConversion 
    | expresionMultiplicativa '*' expresionConversion                       { numeroLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0; }
    | expresionMultiplicativa OPERADOR_MULTIPLICATIVO expresionConversion   { numeroLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0; }
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
    | expresionSufijo '(' listaArgumentos_ ')' { numeroLinea = yylineno; pushSimbolo(&tablaAuxiliar, $<cadena>1, "-", 1);  tablaAuxiliar->tiposParametros = tablaParametros; validacionInvocacion(tablaAuxiliar);  tablaParametros = NULL; tablaAuxiliar = NULL; }
    | expresionSufijo OPERADOR_INCREMENTO                       
    ;

listaArgumentos: expresionAsignacion            { pushParametro(&tablaParametros, $<cadena>1); } 
    | listaArgumentos ',' expresionAsignacion   { pushParametro(&tablaParametros, $<cadena>3); } 
    ;

expresionPrimaria: IDENTIFICADOR    { tablaAuxiliar = obtenerIdentificador($<cadena>1); if(tablaAuxiliar != NULL) (validacionBinaria == 0) ? (tipoAuxiliar1 = tablaAuxiliar->tipo) : (tipoAuxiliar2 = tablaAuxiliar->tipo) ; validacionBinaria = 1; }  
    | constante                     
    | CONSTANTE_CADENA              { (validacionBinaria == 0) ? (tipoAuxiliar1 = "char*") : (tipoAuxiliar2 = "char*"); validacionBinaria = 1; }
    | '(' expresion ')'
    ;

expresionConstante: expresionCondicional
    ; 

constante: CONSTANTE_DECIMAL   { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; }      
    | CONSTANTE_OCTAL          { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; }
    | CONSTANTE_HEXADECIMAL    { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; }
    | CONSTANTE_REAL           { (validacionBinaria == 0) ? (tipoAuxiliar1 = "float") : (tipoAuxiliar2 = "float"); validacionBinaria = 1; }  
    | CONSTANTE_CARACTER       { (validacionBinaria == 0) ? (tipoAuxiliar1 = "char" ) : (tipoAuxiliar2 = "char" ); validacionBinaria = 1; }
    ;
 

/* **************************************** DECLARACIONES **************************************** */
declaracion: declaracionVariable
    |   declaracionFuncion
    ;

/** Variables **/

declaracionVariable: TIPO_DATO  declarador  ';' { tipoAuxiliar = strdup($<cadena>1); tipoAuxiliar = agregadorDeclaradores(tipoAuxiliar); pushSimboloSinRepetir(identificadorAuxiliar, tipoAuxiliar, 0);} 
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

/** Funciones **/

declaracionFuncion: TIPO_DATO  IDENTIFICADOR '(' listaParametros_ ')' ';'   { pushSimboloSinRepetir($<cadena>2, $<cadena>1, 1);  pushParametros($<cadena>2); }
    | TIPO_DATO IDENTIFICADOR '(' listaParametros_ ')' sentenciaCompuesta   { pushSimboloSinRepetir($<cadena>2, $<cadena>1, 1);  pushParametros($<cadena>2); }
    ;

listaParametros: parametro         
    | listaParametros ',' parametro 
    ;

parametro: TIPO_DATO decla { tipoAuxiliar = strdup($<cadena>1); tipoAuxiliar = agregadorDeclaradores(tipoAuxiliar); pushParametro(&tablaParametros, tipoAuxiliar); } 
    ;

/** Extras **/

decla: /* */
    | declaradorDirecto
    | puntero declaradorDirecto
    ;

puntero: '*'      { contador.punteros++; }  
    | '*' puntero { contador.punteros++; }
    ;

declaradorDirecto: IDENTIFICADOR                        { identificadorAuxiliar = strdup($<cadena>1); }
    | declaradorDirecto '[' expresionConstante_ ']'     { contador.dimensiones++; }
    ;

/* **************************************** SENTENCIAS **************************************** */ 
sentencia: sentenciaExpresion
    | sentenciaCompuesta 
    | sentenciaSeleccion 
    | sentenciaIteracion 
    | sentenciaSalto   
    | sentenciaEtiquetada     
    ;

sentenciaExpresion: expresion_s ';'
    ;

expresion_s: /* */  { printf("\nLinea %i - SENTENCIA - EXPRESION:  VACIA", yylineno);   }
    | expresion     /*{ printf("\nLinea %i - SENTENCIA - EXPRESION", yylineno);   }*/   
    ;

sentenciaCompuesta: '{' listaDeclaraciones_ listaSentencias_ '}'    { printf("\nLinea %i - SENTENCIA - EXPRESION:  COMPUESTA", yylineno);   }
    ;

listaDeclaraciones: declaracion 
    | listaDeclaraciones declaracion
    ;

listaSentencias: sentencia 
    | listaSentencias sentencia
    ;

sentenciaSeleccion: IF '(' expresion ')' sentencia  { printf("\nLinea %i - SENTENCIA - SELECCION:  IF     ", yylineno);    }    
    | IF '(' expresion ')' sentencia ELSE sentencia { printf("\nLinea %i - SENTENCIA - SELECCION:  IF/ELSE", yylineno);    } 
    | SWITCH '(' expresion ')' sentencia            { printf("\nLinea %i - SENTENCIA - SELECCION:  SWITCH ", yylineno);    }
    ;

sentenciaEtiquetada: CASE expresionConstante ':' sentencia 
    | DEFAULT ':' sentencia 
    | IDENTIFICADOR ':' sentencia /*Las sentencias case y default se utilizan solo dentro de una sentencia switch.*/
    ;

sentenciaIteracion: WHILE '(' expresion ')' sentencia               { printf("\nLinea %i - SENTENCIA - ITERACION:  WHILE   ", yylineno);   } 
    | DO sentencia WHILE '(' expresion ')' ';'                      { printf("\nLinea %i - SENTENCIA - ITERACION:  DO/WHILE", yylineno);   } 
    | FOR '(' expresion_';' expresion_ ';' expresion_ ')' sentencia { printf("\nLinea %i - SENTENCIA - ITERACION:  FOR     ", yylineno);   }
    ;

sentenciaSalto: CONTINUE ';'    { printf("\nLinea %i - SENTENCIA - SALTO:  CONTINUE", yylineno);   }
    | BREAK ';'                 { printf("\nLinea %i - SENTENCIA - SALTO:  BREAK   ", yylineno);   } 
    | RETURN expresion_ ';'     { printf("\nLinea %i - SENTENCIA - SALTO:  RETURN  ", yylineno);   } 
    | GOTO IDENTIFICADOR ';'    { printf("\nLinea %i - SENTENCIA - SALTO:  GOTO    ", yylineno);   }
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
expresion_: /* */    
    | expresion       
    ;

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
    
    yyin = fopen("./test.c", "r");
    printf("\n/* **********...Errores y advertencias....********* */");

    yyparse();

    printf("\n\n/* **********....Doble declaracion.....********** */");
    mostrarSimbolos(tablaDobleDeclaracion);

    printf("\n\n/* **********.....Tabla de simbolos......********** */");
    mostrarSimbolos(tablaSimbolos);

}