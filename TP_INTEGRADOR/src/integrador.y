%{
    // Librerias
    // #include <.h>
    
    #include <ctype.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    // Funciones obligatorias
    int yylex();
    int yywrap() { return(1); }
    void yyerror(char*);
    

    FILE * yyin;

    int numeroLinea = 0;
%}

%union {
    char cadena[100];
    int entero;
    float real;
}


// %token tipoUnion LEXEMA 
%token <cadena> OPERADOR_ASIGNACION         //= *= /= %= += -= >= <= &= ^= |=
%token <cadena> OPERADOR_O_LOGICO           // ||
%token <cadena> OPERADOR_Y_LOGICO           // &&
%token <cadena> OPERADOR_O_BINARIO          // |
%token <cadena> OPERADOR_XOR_BINARIO        // ^
%token <cadena> OPERADOR_Y_BINARIO          // &
%token <cadena> OPERADOR_IGUALDAD           // == !=
%token <cadena> OPERADOR_RELACIONAL         // > <  >= <=
%token <cadena> OPERADOR_CORRIMIENTO        // >> << 
%token <cadena> OPERADOR_ADITIVO            // + - 
%token <cadena> OPERADOR_MULTIPLICATIVO     // * / % 
%token <cadena> OPERADOR_INCREMENTO         // ++ --
%token <cadena> OPERADOR_UNARIO             // & * + - ~ !
%token <cadena> OPERADOR_SIZEOF             // sizeof
%token <cadena> OPERADOR_PUNTERO_A_MIEMBRO  // -> .
%token <cadena> OPERADOR_ELIPSIS            // ...

%token <cadena> IDENTIFICADOR               // Cualquier IDENTIFICADOR
%token <cadena> TIPO_DE_DATO                // void char short int long float double signed unsigned

%token <entero> CONSTANTE_CADENA            // Cualquier cadena entre ""                   
%token <entero> CONSTANTE_DECIMAL                                  
%token <entero> CONSTANTE_OCTAL                                  
%token <entero> CONSTANTE_HEXADECIMAL                         
%token <real>   CONSTANTE_REAL                                         
%token <entero> CONSTANTE_CARACTER


%token <cadena> ESPECIFICADOR_CLASE_ALMACENAMIENTO  // typedef static auto register extern
%token <cadena> CALIFICADOR_TIPO                    // const volatile
%token <cadena> STRUCT_O_UNION                      
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

// %type tipoUnion 


// %asocitividad 'operador' 


%% /* REGLAS Y ACCIONES */

entrada:  /**/
    | entrada linea
;

linea: '\n'
    | declaracion '\n'     { numeroLinea++; }
    | sentencia '\n'        { numeroLinea++; }
    | error '\n'            { printf("\nError sintactico - Numero de linea %i", numeroLinea); numeroLinea++; yyerror;}     
;

/************** Expresiones **************/

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
    | expresionOInclusivo OPERADOR_O_BINARIO expresionOExcluyente
;

expresionOExcluyente: expresionY
    | expresionOExcluyente OPERADOR_XOR_BINARIO expresionY
;

expresionY: expresionIgualdad 
    | expresionY OPERADOR_Y_BINARIO expresionIgualdad
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
    | expresionSufijo '[' expresion ']' 
    | expresionSufijo '(' listaArgumentos ')'  
    | expresionSufijo OPERADOR_PUNTERO_A_MIEMBRO IDENTIFICADOR
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
;

constante: CONSTANTE_DECIMAL             
    | CONSTANTE_OCTAL               
    | CONSTANTE_HEXADECIMAL       
    | CONSTANTE_REAL                 
    | CONSTANTE_CARACTER  
;

/************** Declaraciones **************/

declaracion: especificadoresDeclaracion listaDeclaradores
    | especificadoresDeclaracion 
;

especificadoresDeclaracion: ESPECIFICADOR_CLASE_ALMACENAMIENTO especificadoresDeclaracion 
    | ESPECIFICADOR_CLASE_ALMACENAMIENTO
    | especificadorTipo especificadoresDeclaracion
    | especificadorTipo  { printf("\nSe declara la variable"); }
    | CALIFICADOR_TIPO especificadoresDeclaracion
    | CALIFICADOR_TIPO 
;

listaDeclaradores: declarador 
    | listaDeclaradores ',' declarador
;    

declarador: decla 
    | decla '=' inicializador { printf("\nSe inicializa la variable"); }
;

inicializador: expresionAsignacion 
    | '{' listaInicializadores '}' 
    | '{' listaInicializadores ',' '}'
;

listaInicializadores: inicializador 
    | listaInicializadores ',' inicializador
;

especificadorTipo: TIPO_DE_DATO 
    | especificadorStructOUnion
    | especificadorEnum
    | nombreTypedef
;

nombreTypedef: IDENTIFICADOR
;

especificadorStructOUnion: STRUCT_O_UNION IDENTIFICADOR '{' listaDeclaracionesStruct '}' 
    | '{' listaDeclaracionesStruct '}'
    | STRUCT_O_UNION IDENTIFICADOR
;

listaDeclaracionesStruct: declaracionStruct
    | listaDeclaracionesStruct declaracionStruct
;

declaracionStruct: listaCalificadores declaradoresStruct ';'
;

listaCalificadores: especificadorTipo listaCalificadores 
    | especificadorTipo
    | CALIFICADOR_TIPO listaCalificadores
    | CALIFICADOR_TIPO 
;

declaradoresStruct: declaStruct
    | declaradoresStruct ',' declaStruct
;

declaStruct: decla 
    | decla ':' expresionConstante
    | ':' expresionConstante
;

decla: puntero declaradorDirecto
    | declaradorDirecto
;

puntero: '*' listaCalificadoresTipos 
    | '*' 
    | '*' listaCalificadoresTipos puntero
    | '*' puntero
;

listaCalificadoresTipos: CALIFICADOR_TIPO 
    | listaCalificadoresTipos CALIFICADOR_TIPO
;

declaradorDirecto: IDENTIFICADOR 
    | '(' decla ')' 
    | declaradorDirecto '[' expresionConstante ']' 
    | declaradorDirecto '[' ']' 
    | declaradorDirecto '(' listaTiposParametros ')' 
    | declaradorDirecto '(' ')'  
;

listaTiposParametros: listaParametros 
    | listaParametros ',' OPERADOR_ELIPSIS
;

listaParametros: declaracionParametro 
    | listaParametros ',' declaracionParametro
;

declaracionParametro: especificadoresDeclaracion decla 
    | especificadoresDeclaracion declaradorAbstracto 
    | especificadoresDeclaracion  
;

especificadorEnum: ENUM IDENTIFICADOR '{' listaEnumeradores '}' 
    | ENUM '{' listaEnumeradores '}'
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

nombreTipo: listaCalificadores declaradorAbstracto
    | listaCalificadores 
;

declaradorAbstracto: puntero 
    | puntero declaradorAbstractoDirecto
    | declaradorAbstractoDirecto
;

declaradorAbstractoDirecto: '(' declaradorAbstracto ')' 
    | declaradorAbstractoDirecto '[' expresionConstante ']'     { printf("\nSe declara el arreglo"); }
    | declaradorAbstractoDirecto '[' ']'                        { printf("\nSe declara el arreglo vacio"); }
    | '[' expresionConstante ']' 
    | '[' ']' 
    | declaradorAbstractoDirecto '(' listaTiposParametros ')'   { printf("\nSe declara la funcion"); }
    | declaradorAbstractoDirecto '(' ')'                        { printf("\nSe declara la funcion sin parametros"); }
    | '(' listaTiposParametros ')'
    | '(' ')'
;

/************** Sentencias **************/

sentencia: sentenciaExpresion
    | sentenciaCompuesta 
    | sentenciaSeleccion 
    | sentenciaIteracion 
    | sentenciaEtiquetada 
    | sentenciaSalto
;

sentenciaExpresion:  ';'   { printf("\nSentencia vacia");       }
    | expresion ';'        { printf("\nSentencia expresion");   }    
;

sentenciaCompuesta: '{' listaDeclaraciones listaSentencias '}'  { printf("\nSentencia compuesta");          }  
    | '{' listaDeclaraciones '}'                                { printf("\nSentencia compuesta");          } 
    | '{' listaSentencias '}'                                   { printf("\nSentencia compuesta");          } 
    | '{' '}'                                                   { printf("\nSentencia compuesta (vacia)");  } 
;

listaDeclaraciones: declaracion
    | listaDeclaraciones declaracion
;

listaSentencias: sentencia 
    | listaSentencias sentencia
;

sentenciaSeleccion: IF '(' expresion ')' sentencia      { printf("\nSentencia de seleccion (IF)");      }
    | IF '(' expresion ')'  sentencia ELSE sentencia    { printf("\nSentencia de seleccion (IF-ELSE)"); }
    | SWITCH '(' expresion ')'  sentencia               { printf("\nSentencia de seleccion (SWITCH)");  }
; 
 
sentenciaIteracion: WHILE '(' expresion ')'  sentencia                                  { printf("\nSentencia de iteracion (WHILE)");    }
    | DO sentencia WHILE '(' expresion ')' ';'                                          { printf("\nSentencia de iteracion (DO WHILE)"); }    
    | FOR '(' posibleExpresion ';' posibleExpresion ';' posibleExpresion ')' sentencia  { printf("\nSentencia de iteracion (FOR)");      }
;

posibleExpresion: /**/
    | expresion
;

sentenciaEtiquetada: CASE expresionConstante ':' sentencia  { printf("\nSentencia etiquetada (CASE)");      } 
    | DEFAULT ':' sentencia                                 { printf("\nSentencia etiquetada (DEFAULT)");   } 
    | IDENTIFICADOR ':' sentencia                           { printf("\nSentencia etiquetada ()");          } 
;

sentenciaSalto: CONTINUE ';'    { printf("\nSentencia de salto (CONTINUE)");        } 
    | BREAK ';'                 { printf("\nSentencia de salto (BREAK)");           }
    | RETURN expresion ';'      { printf("\nSentencia de salto (RETURN)");          }
    | RETURN ';'                { printf("\nSentencia de salto (RETURN VACIO)");    }  
    | GOTO IDENTIFICADOR ';'    { printf("\nSentencia de salto (GOTO)");            }
;

%%


// Funcion de error 
void yyerror(char * mensaje) {  
  printf ("Error: %s\n", mensaje);
}

int main() {
    yyin = fopen("test.c", "r");
    yyparse();
}