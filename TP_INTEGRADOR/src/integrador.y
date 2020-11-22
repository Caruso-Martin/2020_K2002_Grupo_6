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

    char* tipoAuxiliar = "";
    char* identificadorAuxiliar = ""; 

%}

%union {
    char* cadena;
    int entero;
    float real;
}

//%error-verbose

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
%type <cadena> declaracionVariable
//%type <cadena> listaDeclaradores
%type <cadena> declarador
%type <cadena> decla
%type <cadena> declaradorDirecto

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
    | expresionAditiva '+' expresionMultiplicativa
    | expresionAditiva '-' expresionMultiplicativa 
    ;

expresionMultiplicativa: expresionConversion 
    | expresionMultiplicativa '*' expresionConversion { validacionTipos($<cadena>1, $<cadena>3) }
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
    | expresionSufijo '(' listaArgumentos_ ')' /* invocacion */ {printf("\nIdentificador: %s", $<cadena>1);}
    | expresionSufijo OPERADOR_INCREMENTO                       
    ;

listaArgumentos: expresionAsignacion {printf("\nparametro: %s", $<cadena>1);}
    | listaArgumentos ',' expresionAsignacion {printf("\nparametro\: %s", $<cadena>3); }
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

parametro: TIPO_DATO decla { pushParametro(&tablaParametros, $<cadena>1); } 
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
    printf("\n/* ********** Validaciones de simbolos ********** */");
    yyparse();

    printf("\n/* ********** Tabla de simbolos ********** */");
    mostrarSimbolos(tablaSimbolos);
    
    printf("\n\n/* ********** Doble declaracion ********** */");
    mostrarSimbolos(tablaDobleDeclaracion);

}