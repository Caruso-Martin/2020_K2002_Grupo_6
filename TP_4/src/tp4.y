%{
    #include <ctype.h>
    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>

    int yylex();
    int yyerror(char*);
%}

%union { /*Para poder manejar varios tipos de datos en el yyval, uno para enteros y otro para punto flotante)*/
    char        caracter;
    char*       cadena; 
    double      doble;  // 1.7E-308 a 1.7E+308
    long int    entero; // -2^(31)  a 2^(31)-1
}

// %token <tipoUnion> LEXEMA 

%token <cadena> IDENTIFICADOR
%token <cadena> CONSTANTE 
%token <cadena> CONSTANTE_CADENA

%token <cadena> ESPECIFICADOR_DE_CLASE_DE_ALMACENAMIENTO
// TYPEDEF STATIC AUTO REGISTER EXTERN
%token <cadena> ESPECIFICADOR_DE_TIPO 
// VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED
%token <cadena> CALIFICADOR_DE_TIPO 
// CONST VOLATILE
%token <cadena> STRUCT_O_UNION 
// STRUCT UNION

%token <cadena> EXPRESION_CONSTANTE 

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
 
%token <cadena> IFDEF
%token <cadena> IFNDEF
%token <cadena> ELIF
%token <cadena> INCLUDE
%token <cadena> DEFINE
%token <cadena> UNDEF
%token <cadena> LINE
%token <cadena> ERROR
%token <cadena> PRAGMA

/* RENOVACIONES TP 4*/

%token <charDe3Caracteres> OPERADOR_ASIGNACION
/*'=' '*=' '/=' '%=' '+=' '-=' '<<=' '>>=' '&=' '^=' '|='*/
%token <caracter> OPERADOR_UNARIO 
/*'&' '*' '+' '-' '~' '!'*/

// %type <tipoUnion> categoriaLexica

%type <cadena> expresion
%type <cadena> expresionDeAsignacion
%type <cadena> expresionCondicional
%type <cadena> operadorAsignacion 
%type <cadena> expresionOLogico
%type <cadena> expresionYLogico
%type <cadena> expresionOInclusivo
%type <cadena> expresionOExcluyente
%type <cadena> expresionY
%type <cadena> expresionDeIgualdad
%type <cadena> expresionRelacional
%type <cadena> expresionDeCorrimiento
%type <cadena> expresionAditiva
%type <cadena> expresionMultiplicativa
%type <cadena> expresionDeConversion
%type <cadena> expresionUnaria
%type <cadena> nombreDeTipo
%type <cadena> operadorUnario
%type <cadena> expresionSufijo
%type <cadena> listaDeArgumentos
%type <cadena> expresionPrimaria

%type <cadena> declaracion 
%type <cadena> especificadoresDeDeclaracion
%type <cadena> listaDeDeclaradores
%type <cadena> declarador
%type <cadena> inicializador
%type <cadena> listaDeInicializadores
%type <cadena> especificadorDeClaseDeAlmacenamiento
%type <cadena> especificadorDeTipo
%type <cadena> calificadorDeTipo
%type <cadena> especificadorDeStructOUnion
%type <cadena> structOUnion 
%type <cadena> listaDeDeclaracionesStruct 
%type <cadena> declaracionStruct
%type <cadena> listaDeCalificadores
%type <cadena> declaradoresStruct
%type <cadena> declaStruct
%type <cadena> decla
%type <cadena> puntero
%type <cadena> listaCalificadoresTipos
%type <cadena> declaradorDirecto
%type <cadena> listaTiposParametros
%type <cadena> listaDeParametros
%type <cadena> declaracionDeParametro
%type <cadena> listaDeIdentificadores
%type <cadena> especificadorDeEnum
%type <cadena> listaDeEnumeradores
%type <cadena> enumerador
%type <cadena> constanteDeEnumeracion 
%type <cadena> nombreDeTypedef
%type <cadena> declaradorAbstracto
%type <cadena> declaradorAbstractoDirecto

%type <cadena> sentencia
%type <cadena> sentenciaExpresion
%type <cadena> sentenciaCompuesta
%type <cadena> listaDeDeclaraciones
%type <cadena> listaDeSentencias
%type <cadena> sentenciaDeSeleccion
%type <cadena> sentenciaDeIteracion
%type <cadena> sentenciaEtiquetada
%type <cadena> sentenciaDeSalto

%type <cadena> unidadDeTraduccion
%type <cadena> declaracionExterna
%type <cadena> definicionExterna

%type <cadena> archivoDePreprocesamiento
%type <cadena> grupo
%type <cadena> parteDeGrupo
%type <cadena> seccionIF
%type <cadena> grupoIF
%type <cadena> gruposElif
%type <cadena> grupoElif
%type <cadena> grupoElse
%type <cadena> lineaEndif
%type <cadena> lineaDeControl
%type <cadena> lineaDeTexto
%type <cadena> noDirectiva 
%type <cadena> parizq
%type <cadena> listaDeReemplazos 
%type <cadena> tokensPP
%type <cadena> nuevaLinea

// %asocitividad 'operador' 

%left '++' '--'        // Post-Incremento
%left '(' ')'           // Llamada a funcion
%left '[' ']'           // Elemento de vector
%left '.'               // Seleccionar elemento por referencia
%left "->"              // Seleccionar elemento con puntero 

%right '++' '--'       // Pre-Incremento
%right '+' '-'          // Suma/Resta unitaria
%right '!' '~'          // NOT logico/binario
%right '(typecast)'     // Conversion de tipo
%right '*'              // Indireccion
%right '&'              // Direccion
%right 'sizeof'         // Tamanio

%left '*' '/' '%'       // Multiplicativos
%left '+' '-'           // Aditivos
%left '>>' '<<'         // Desplazamiento
%left '>' '<' '>=' '<=' // Relacionales
%left '==' '!='         // Igualdad
%left '&' '^' '|'       // AND/XOR/OR binario
%left '&&' '||'         // AND/OR logico

%right '?' ':'          // Ternario
%right '='              // Asignacion
%right '+=' '-='        // Asignacion aditiva
%right '*=' '/=' '%='   // Asignacion multiplicativa
%right '<<=' '>>='      // Asignacion de desplazamiento
%right '&=' '^=' '|='   // Asignacion AND/XOR/OR binaria

%left ','               // Coma

%% /* REGLAS Y ACCIONES */

/* Expresiones */

expresion: expresionDeAsignacion { ;}
    | expresion ',' expresionDeAsignacion { ;}
;

expresionDeAsignacion: expresionCondicional { ;}
    | expresionUnaria operadorAsignacion expresionDeAsignacion { ;}
;

expresionCondicional: expresionOLogico { ;} 
    | expresionOLogico '?' expresion ':' expresionCondicional { ;}
;

operadorAsignacion: OPERADOR_ASIGNACION;

expresionOLogico: expresionYLogico { ;} 
    | expresionOLogico '||' expresionYLogico { ;} 
;

expresionYLogico: expresionOInclusivo { ;} 
    | expresionYLogico '&&' expresionOInclusivo { ;} 
;

expresionOInclusivo: expresionOExcluyente { ;} 
    | expresionOInclusivo '|' expresionOExcluyente { ;} 
;

expresionOExcluyente: expresionYLogico { ;} 
    | expresionOExcluyente '^' expresionY { ;} 
;

expresionY: expresionDeIgualdad { ;} 
    | expresionY '&' expresionDeIgualdad { ;} 
;

expresionDeIgualdad: expresionRelacional { ;} 
    | expresionDeIgualdad '==' expresionRelacional { ;} 
    | expresionDeIgualdad '!=' expresionRelacional { ;} 
;

expresionRelacional: expresionDeCorrimiento
    | expresionRelacional '<' expresionDeCorrimiento { ;} 
    | expresionRelacional '>' expresionDeCorrimiento { ;} 
    | expresionRelacional '<=' expresionDeCorrimiento { ;} 
    | expresionRelacional '>=' expresionDeCorrimiento { ;} 
;

expresionDeCorrimiento: expresionAditiva 
    | expresionDeCorrimiento '<<' expresionAditiva { ;} 
    | expresionDeCorrimiento '>>' expresionAditiva { ;} 
;

expresionAditiva: expresionMultiplicativa
    | expresionAditiva '+' expresionMultiplicativa { ;} 
    | expresionAditiva '-' expresionMultiplicativa
;

expresionMultiplicativa: expresionDeConversion
    | expresionMultiplicativa '*' expresionDeConversion { ;} 
    | expresionMultiplicativa '/' expresionDeConversion { ;} 
    | expresionMultiplicativa '%' expresionDeConversion { ;} 
;

expresionDeConversion: expresionUnaria { ;} 
    | '(' nombreDeTipo ')' expresionDeConversion { ;} 
;

expresionUnaria: expresionSufijo { ;} 
    | '++' expresionUnaria { ;} 
    | '--' expresionUnaria { ;} 
    | operadorUnario expresionDeConversion { ;} 
    | 'sizeof' expresionUnaria { ;} 
    | 'sizeof' '(' nombreDeTipo ')' { ;} 
;

operadorUnario: OPERADOR_UNARIO;

expresionSufijo:  expresionPrimaria '[' expresion ']' { ;} 
    | expresionSufijo '(' listaDeArgumentos ')' { ;} 
    | expresionSufijo '.' IDENTIFICADOR { ;} 
    | expresionSufijo '->' IDENTIFICADOR { ;} 
    | expresionSufijo '++' { ;} 
    | expresionSufijo '--' { ;} 
;

listaDeArgumentos: expresionDeAsignacion { ;} 
    | listaDeArgumentos ',' expresionDeAsignacion { ;} 
;

expresionPrimaria: IDENTIFICADOR { ;} 
    | CONSTANTE { ;} 
    | CONSTANTE_CADENA { ;} 
    | '(' expresion ')' { ;} 
;

/* Declaraciones */

declaracion: especificadoresDeDeclaracion { ;} 
    | especificadoresDeDeclaracion listaDeDeclaradores { ;} 
;

especificadoresDeDeclaracion: especificadorDeClaseDeAlmacenamiento especificadoresDeDeclaracion { ;} 
    | especificadorDeClaseDeAlmacenamiento { ;} 
    | especificadorDeTipo especificadoresDeDeclaracion { ;} 
    | especificadorDeTipo { ;} 
    | calificadorDeTipo especificadoresDeDeclaracion { ;} 
    | calificadorDeTipo { ;} 
;

listaDeDeclaradores: declarador { ;} 
    | listaDeDeclaradores ',' declarador { ;} 
;

declarador: decla { ;} 
    | decla '=' inicializador { ;} 
;

inicializador: expresionDeAsignacion { ;} 
    | '{' listaDeInicializadores '}' { ;} 
    |  '{' listaDeInicializadores ',' '}' { ;} 
;

listaDeInicializadores: inicializador { ;} 
    | listaDeInicializadores ',' inicializador { ;} 
;

especificadorDeClaseDeAlmacenamiento: ESPECIFICADOR_DE_CLASE_DE_ALMACENAMIENTO;

especificadorDeTipo: ESPECIFICADOR_DE_TIPO
    | especificadorDeStructOUnion { ;} 
    | especificadorDeEnum { ;} 
    | nombreDeTypedef { ;} 
;

calificadorDeTipo: CALIFICADOR_DE_TIPO;

especificadorDeStructOUnion: structOUnion IDENTIFICADOR '{' listaDeDeclaracionesStruct '}' { ;} 
    | structOUnion '{' listaDeDeclaracionesStruct '}' { ;} 
    | structOUnion IDENTIFICADOR { ;} 
;

structOUnion: STRUCT_O_UNION;

listaDeDeclaracionesStruct: declaracionStruct { ;} 
    | listaDeDeclaracionesStruct declaracionStruct { ;} 
;

declaracionStruct: listaDeCalificadores declaradoresStruct { ;} ;

listaDeCalificadores: especificadorDeTipo listaDeCalificadores { ;} 
    | especificadorDeTipo { ;} 
    | calificadorDeTipo listaDeCalificadores { ;} 
    | calificadorDeTipo { ;} 
;

declaradoresStruct: declaStruct { ;} 
    | declaradoresStruct ',' declaStruct { ;} 
;

declaStruct: decla { ;} 
    | decla ':' EXPRESION_CONSTANTE { ;} 
    | ':' EXPRESION_CONSTANTE { ;} 
;

decla: puntero declaradorDirecto { ;} 
    | declaradorDirecto { ;} 
;

puntero: '*' listaCalificadoresTipos { ;} 
    | '*' { ;} 
    | '*' listaCalificadoresTipos puntero { ;} 
    | '*' puntero { ;} 
;

listaCalificadoresTipos: calificadorDeTipo { ;} 
    | listaCalificadoresTipos calificadorDeTipo { ;} 
;

declaradorDirecto: IDENTIFICADOR { ;} 
    | '(' decla ')' { ;} 
    | declaradorDirecto '[' EXPRESION_CONSTANTE ']' { ;} 
    | declaradorDirecto '(' listaTiposParametros ')' { ;} 
    | declaradorDirecto '(' listaDeIdentificadores ')' { ;} 
;

listaTiposParametros: listaDeParametros { ;} 
    | listaDeParametros ',' '...' { ;} 
;

listaDeParametros: declaracionDeParametro { ;} 
    | listaDeParametros ',' declaracionDeParametro { ;} 
;

declaracionDeParametro: especificadoresDeDeclaracion decla { ;} 
    | especificadoresDeDeclaracion declaradorAbstracto { ;} 
    | especificadoresDeDeclaracion { ;} 
;

listaDeIdentificadores: IDENTIFICADOR { ;} 
    | listaDeIdentificadores ',' IDENTIFICADOR { ;} 
;

especificadorDeEnum: ENUM IDENTIFICADOR '{' listaDeEnumeradores '}' { ;} 
    | ENUM '{' listaDeEnumeradores '}' { ;} 
    | ENUM IDENTIFICADOR { ;} 
;

listaDeEnumeradores: enumerador { ;} 
    | listaDeEnumeradores ',' enumerador { ;} 
;

enumerador: constanteDeEnumeracion { ;}
    | constanteDeEnumeracion '=' EXPRESION_CONSTANTE { ;} 
;

constanteDeEnumeracion: IDENTIFICADOR { ;} ;

nombreDeTypedef: IDENTIFICADOR { ;} ;

nombreDeTipo: listaDeCalificadores declaradorAbstracto { ;} 
    | listaDeCalificadores { ;} 
; 

declaradorAbstracto: puntero { ;} 
    | puntero declaradorAbstractoDirecto { ;} 
    | declaradorAbstractoDirecto { ;} 
;

declaradorAbstractoDirecto: '(' declaradorAbstracto ')' { ;} 
    | declaradorAbstractoDirecto '[' EXPRESION_CONSTANTE ']' { ;} 
    | declaradorAbstractoDirecto '[' ']' { ;} 
    | '[' EXPRESION_CONSTANTE ']' { ;} 
    | '[' ']' { ;}     
    | declaradorAbstractoDirecto '(' listaTiposParametros ')' { ;} 
    | declaradorAbstractoDirecto '(' ')' { ;} 
    | '(' listaTiposParametros ')' { ;} 
    | '(' ')'
;

/* Sentencias */

sentencia: sentenciaExpresion { ;} 
    | sentenciaCompuesta { ;} 
    | sentenciaDeSeleccion { ;} 
    | sentenciaDeIteracion { ;} 
    | sentenciaEtiquetada { ;} 
    | sentenciaDeSalto { ;} 
;

sentenciaExpresion: expresion ';' { ;} 
    | ';' { ;} 
;

sentenciaCompuesta: '{' listaDeDeclaraciones listaDeSentencias '}' { ;} 
    | '{' listaDeDeclaraciones '}' { ;} 
    | '{' listaDeSentencias '}' { ;} 
    | '{' '}' { ;} 
;

listaDeDeclaraciones: declaracion { ;} 
    | listaDeDeclaraciones declaracion { ;} 
;

listaDeSentencias: sentencia { ;} 
    | listaDeSentencias sentencia { ;} 
;

sentenciaDeSeleccion: IF '(' expresion ')' sentencia { ;} 
    | IF '(' expresion ')' sentencia ELSE sentencia { ;} 
    | SWITCH '(' expresion ')' sentencia { ;} 
;

sentenciaDeIteracion: WHILE '(' expresion ')' sentencia { ;} 
    | DO sentencia WHILE '(' expresion ')' sentencia { ;} 
    | FOR '(' expresion ';' expresion ';' expresion ')' sentencia { ;} 
    | FOR '(' expresion ';' expresion ';'  ')' sentencia { ;} 
    | FOR '(' expresion ';'  ';' expresion ')' sentencia { ;} 
    | FOR '(' expresion ';'  ';'  ')' sentencia { ;} 
    | FOR '('  ';' expresion ';' expresion ')' sentencia { ;} 
    | FOR '('  ';' expresion ';'  ')' sentencia { ;} 
    | FOR '('  ';'  ';' expresion ')' sentencia { ;} 
    | FOR '(' ';'  ';' ')' sentencia { ;} 
;

sentenciaEtiquetada: CASE EXPRESION_CONSTANTE ':' sentencia { ;} 
    | DEFAULT ':' sentencia { ;} 
    | IDENTIFICADOR ':' sentencia { ;} 
;

sentenciaDeSalto: CONTINUE ';' { ;} 
    | BREAK ';' { ;} 
    | RETURN expresion ';' { ;} 
    | RETURN ';' { ;} 
    | GOTO IDENTIFICADOR ';' { ;} 
;

/*Definiciones Externas*/

unidadDeTraduccion: declaracionExterna { ;} 
    | unidadDeTraduccion declaracionExterna { ;} 
;

declaracionExterna: definicionDeFuncion { ;} 
    | declaracion { ;} 
;

definicionDeFuncion: especificadoresDeDeclaracion decla listaDeDeclaraciones sentenciaCompuesta { ;} 
    | especificadoresDeDeclaracion decla sentenciaCompuesta { ;} 
    | decla listaDeDeclaraciones sentenciaCompuesta { ;} 
    | decla sentenciaCompuesta { ;} 

;

/*Preprocesador*/

archivoDePreprocesamiento: /* vacio */ { ;} 
    | grupo { ;} 
;

grupo: parteDeGrupo { ;} 
    | grupo parteDeGrupo { ;} 
;

parteDeGrupo: seccionIF { ;} 
    | lineaDeControl { ;} 
    | lineaDeTexto { ;} 
    | '#' noDirectiva { ;} 
;

seccionIF: grupoIF gruposElif grupoElse lineaEndif { ;} 
    | grupoIF gruposElif lineaEndif { ;} 
    | grupoIF grupoElse lineaEndif { ;} 
    | grupoIF lineaEndif { ;} 
;

grupoIF: '#' IF EXPRESION_CONSTANTE nuevaLinea grupo { ;} 
    | '#' IF EXPRESION_CONSTANTE nuevaLinea { ;} 
    | '#' IFDEF IDENTIFICADOR nuevaLinea grupo { ;} 
    | '#' IFDEF IDENTIFICADOR nuevaLinea { ;} 
    | '#' IFNDEF IDENTIFICADOR nuevaLinea grupo { ;}  
    | '#' IFNDEF IDENTIFICADOR nuevaLinea { ;} 
;

gruposElif: grupoElif { ;} 
    | gruposElif grupoElif { ;} 
;

grupoElif: '#' ELIF EXPRESION_CONSTANTE nuevaLinea grupo { ;} 
    | '#' ELIF EXPRESION_CONSTANTE nuevaLinea { ;} 
;

grupoElse: '#' ELSE nuevaLinea grupo { ;} 
    | '#' ELSE nuevaLinea { ;} 
;

lineaEndif: '#' ENDIF nuevaLinea { ;} ;

lineaDeControl: '#' INCLUDE tokensPP nuevaLinea { ;} 
    | '#' DEFINE IDENTIFICADOR listaDeReemplazos nuevaLinea { ;} 
    | '#' DEFINE IDENTIFICADOR parizq listaDeIdentificadores listaDeReemplazos nuevaLinea { ;} 
    | '#' DEFINE IDENTIFICADOR parizq listaDeReemplazos nuevaLinea { ;} 
    | '#' DEFINE IDENTIFICADOR parizq listaDeReemplazos nuevaLinea { ;} 
    | '#' DEFINE IDENTIFICADOR parizq listaDeIdentificadores ',' listaDeReemplazos nuevaLinea { ;} 
    | '#' UNDEF IDENTIFICADOR nuevaLinea { ;} 
    | '#' LINE tokensPP nuevaLinea { ;} 
    | '#' ERROR tokensPP nuevaLinea { ;} 
    | '#' ERROR nuevaLinea { ;} 
    | '#' PRAGMA tokensPP nuevaLinea { ;} 
    | '#' nuevaLinea { ;} 
;

lineaDeTexto: tokensPP nuevaLinea { ;} 
    | nuevaLinea { ;} 
;

noDirectiva: tokensPP nuevaLinea { ;} ;

parizq:
    CARACTER(NO SEGUIDO DE UN ESPACIO EN BLANCO)
;

listaDeReemplazos: /* vacio */ { ;} 
    | tokensPP { ;} 
;

tokensPP: tokenDePreprocesamiento { ;} 
    | tokensPP tokenDePreprocesamiento { ;} 
;

nuevaLinea: '\n' { ;} ;

defined(NO SE COMO SE HACE)

%%

int yyerror(char *mensaje) {  // Funcion de error 
  printf ("Error: %s\n", mensaje);
}

int main()
{
    #ifdef BISON_DEBUG
        yydebug = 1;
    #endif
        yyparse();
}