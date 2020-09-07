%{
    #include <ctype.h>
    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>

    int yylex ();
    int yyerror (char*);
%}

%union { /*Para poder manejar varios tipos de datos en el yyval, uno para enteros y otro para punto flotante)*/
    char        caracter;
    char*       cadena; 
    double      doble;  // 1.7E-308 a 1.7E+308
    long int    entero; // -2^(31)  a 2^(31)-1
}

// %token <tipoUnion> LEXEMA 


%token <doble> ENTERO
%token <doble> REAL
%token <doble> EXPRESION_CONSTANTE

%token <cadena> CONSTANTE_CARACTER

%token <cadena> LITERAL_CADENA

%token <cadena> PALABRA_RESERVADA
%token <cadena> TIPO_DE_DATO
%token <cadena> ESTRUCTURA_DE_CONTROL
%token <cadena> ESTRUCTURA_DE_ITERACCION

%token <cadena> IDENTIFICADOR
%token <caracter> CARACTER_DE_PUNTUACION

%token <cadena> COMENTARIO

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
%type <cadena> nombreDeTipo
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

%left '++' '--'         // Post-Incremento
%left '(' ')'           // Llamada a funcion
%left '[' ']'           // Elemento de vector
%left '.'               // Seleccionar elemento por referencia
%left '->'              // Seleccionar elemento con puntero 

%right '++' '--'        // Pre-Incremento
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

operadorAsignacion: '='
    | '*='
    | '/='
    | '%='
    | '+='
    | '-='
    | '<<='
    | '>>='
    | '&='
    | '^='
    | '|='
;

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

nombreDeTipo:
;

operadorUnario: '&'
    | '*'
    | '+'
    | '-'
    | '~'
    | '!'
;

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
    | constante { ;} 
    | constanteCadena { ;} 
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

especificadorDeClaseDeAlmacenamiento: 'typedef'
    | 'static'
    | 'auto'
    | 'register'
    | 'extern'
;

especificadorDeTipo: 'void'
    | 'char'
    | 'short'
    | 'int'
    | 'long'
    | 'float'
    | 'double'
    | 'signed'
    | 'unsigned'
    | especificadorDeStructOUnion { ;} 
    | especificadorDeEnum { ;} 
    | nombreDeTypedef { ;} 
;

calificadorDeTipo: 'const'
    | 'volatile'
;

especificadorDeStructOUnion: structOUnion IDENTIFICADOR '{' listaDeDeclaracionesStruct '}' { ;} 
    | structOUnion '{' listaDeDeclaracionesStruct '}' { ;} 
    | structOUnion IDENTIFICADOR { ;} 
;

structOUnion: 'struct'
    | 'union'
;

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

especificadorDeEnum: 'enum' IDENTIFICADOR '{' listaDeEnumeradores '}' { ;} 
    | 'enum' '{' listaDeEnumeradores '}' { ;} 
    | 'enum' IDENTIFICADOR { ;} 
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

sentenciaDeSeleccion: 'if' '(' expresion ')' sentencia { ;} 
    | 'if' '(' expresion ')' sentencia 'else' sentencia { ;} 
    | 'switch' '(' expresion ')' sentencia { ;} 
;

sentenciaDeIteracion: 'while' '(' expresion ')' sentencia { ;} 
    | 'do' sentencia 'while' '(' expresion ')' sentencia { ;} 
    | 'for' '(' expresion ';' expresion ';' expresion ')' sentencia { ;} 
    | 'for' '(' expresion ';' expresion ';'  ')' sentencia { ;} 
    | 'for' '(' expresion ';'  ';' expresion ')' sentencia { ;} 
    | 'for' '(' expresion ';'  ';'  ')' sentencia { ;} 
    | 'for' '('  ';' expresion ';' expresion ')' sentencia { ;} 
    | 'for' '('  ';' expresion ';'  ')' sentencia { ;} 
    | 'for' '('  ';'  ';' expresion ')' sentencia { ;} 
    | 'for' '(' ';'  ';' ')' sentencia { ;} 
;

sentenciaEtiquetada: 'case' EXPRESION_CONSTANTE ':' sentencia { ;} 
    | 'default' ':' sentencia { ;} 
    | IDENTIFICADOR ':' sentencia { ;} 
;

sentenciaDeSalto: 'continue' ';' { ;} 
    | 'break' ';' { ;} 
    | 'return' expresion ';' { ;} 
    | 'return' ';' { ;} 
    | 'goto' IDENTIFICADOR ';' { ;} 
;

/*Definiciones Externas*/

unidadDeTraduccion: declaracionExterna { ;} 
    | unidadDeTraduccion declaracionExterna { ;} 
;

declaracionExterna: definicionDeFuncion { ;} 
    | declaracion { ;} 
;

definicionExterna: especificadoresDeDeclaracion decla listaDeDeclaraciones sentenciaCompuesta { ;} 
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

grupoIF: '#' 'if' EXPRESION_CONSTANTE nuevaLinea grupo { ;} 
    | '#' 'if' EXPRESION_CONSTANTE nuevaLinea { ;} 
    | '#' 'ifdef' IDENTIFICADOR nuevaLinea grupo { ;} 
    | '#' 'ifdef' IDENTIFICADOR nuevaLinea { ;} 
    | '#' 'ifndef' IDENTIFICADOR nuevaLinea grupo { ;}  
    | '#' 'ifndef' IDENTIFICADOR nuevaLinea { ;} 
;

gruposElif: grupoElif { ;} 
    | gruposElif grupoElif { ;} 
;

grupoElif: '#' 'elif' EXPRESION_CONSTANTE nuevaLinea grupo { ;} 
    | '#' 'elif' EXPRESION_CONSTANTE nuevaLinea { ;} 
;

grupoElse: '#' 'else' nuevaLinea grupo { ;} 
    | '#' 'else' nuevaLinea { ;} 
;

lineaEndif: '#' 'endif' nuevaLinea { ;} ;

lineaDeControl: '#' 'include' tokensPP nuevaLinea { ;} 
    | '#' 'define' IDENTIFICADOR listaDeReemplazos nuevaLinea { ;} 
    | '#' 'define' IDENTIFICADOR parizq listaDeIdentificadores listaDeReemplazos nuevaLinea { ;} 
    | '#' 'define' IDENTIFICADOR parizq listaDeReemplazos nuevaLinea { ;} 
    | '#' 'define' IDENTIFICADOR parizq listaDeReemplazos nuevaLinea { ;} 
    | '#' 'define' IDENTIFICADOR parizq listaDeIdentificadores ',' listaDeReemplazos nuevaLinea { ;} 
    | '#' 'undef' IDENTIFICADOR nuevaLinea { ;} 
    | '#' 'line' tokensPP nuevaLinea { ;} 
    | '#' 'error' tokensPP nuevaLinea { ;} 
    | '#' 'error' nuevaLinea { ;} 
    | '#' 'pragma' tokensPP nuevaLinea { ;} 
    | '#' nuevaLinea { ;} 
;

lineaDeTexto: tokensPP nuevaLinea { ;} 
    | nuevaLinea { ;} 
;

noDirectiva: tokensPP nuevaLinea { ;} ;

parizq:
    (NO SE QUE ES ESO)
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

void main() {
    yyparse();
}