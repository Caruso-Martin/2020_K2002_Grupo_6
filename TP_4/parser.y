%{

%}

%% /* REGLAS Y ACCIONES */

/* Expresiones */

expresion:  
    expresionDeAsignacion { ;}
    | expresion ',' expresionDeAsignacion { ;}
;

expresionDeAsignacion: 
    expresionCondicional { ;}
    | expresionUnaria operadorAsignacion expresionDeAsignacion { ;}
;

expresionCondcional:
    expresionOLogico { ;} 
    | expresionOLogico '?' expresion ':' expresionCondcional { ;}
;

operadorAsignacion: 
    '='
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

expresionOLogico:
    expresionYLogico { ;} 
    | expresionOLogico '||' expresionYLogico { ;} 
;

expresionYLogico: 
    expresionOInclusivo { ;} 
    | expresionYLogico '&&' expresionOInclusivo { ;} 
;

expresionOInclusivo:
    expresionOExcluyente { ;} 
    | expresionOInclusivo '|' expresionOExcluyente { ;} 
;

expresionOExcluyente:
    expresionYLogico { ;} 
    | expresionOExcluyente '^' expresionY { ;} 
;

expresionY:
    expresionDeIgualdad { ;} 
    | expresionY '&' expresionDeIgualdad { ;} 
;

expresionDeIgualdad:
    expresionRelacional { ;} 
    | expresionDeIgualdad '==' expresionRelacional { ;} 
    | expresionDeIgualdad '!=' expresionRelacional { ;} 
;

expresionRelacional:
    expresionDeCorrimiento
    | expresionRelacional '<' expresionDeCorrimiento { ;} 
    | expresionRelacional '>' expresionDeCorrimiento { ;} 
    | expresionRelacional '<=' expresionDeCorrimiento { ;} 
    | expresionRelacional '>=' expresionDeCorrimiento { ;} 
;

expresionDeCorrimiento: 
    expresionAditiva 
    | expresionDeCorrimiento '<<' expresionAditiva { ;} 
    | expresionDeCorrimiento '>>' expresionAditiva { ;} 
;

expresionAditiva:
    expresionMultiplicativa
    | expresionAditiva '+' expresionMultiplicativa { ;} 
    | expresionAditiva '-' expresionMultiplicativa
;

expresionMultiplicativa:
    expresionDeConversion
    | expresionMultiplicativa '*' expresionDeConversion { ;} 
    | expresionMultiplicativa '/' expresionDeConversion { ;} 
    | expresionMultiplicativa '%' expresionDeConversion { ;} 
;

expresionDeConversion:
    expresionUnaria { ;} 
    | '(' nombreDeTipo ')' expresionDeConversion { ;} 
;

expresionUnaria:
    expresionSufijo { ;} 
    | '++' expresionUnaria { ;} 
    | '--' expresionUnaria { ;} 
    | operadorUnario expresionDeConversion { ;} 
    | 'sizeof' expresionUnaria { ;} 
    | 'sizeof' '(' nombreDeTipo ')' { ;} 
;

nombreDeTipo:
;

operadorUnario:
    '&'
    | '*'
    | '+'
    | '-'
    | '~'
    | '!'
;

expresionSufijo:
    expresionPrimaria '[' expresion ']' { ;} 
    | expresionSufijo '(' listaDeArgumentos ')' { ;} 
    | expresionSufijo '.' identificador { ;} 
    | expresionSufijo '->' identificador { ;} 
    | expresionSufijo '++' { ;} 
    | expresionSufijo '--' { ;} 
;

listaDeArgumentos:
    expresionDeAsignacion { ;} 
    | listaDeArgumentos ',' expresionDeAsignacion { ;} 
;

expresionPrimaria:
    identificador
    | constante
    | constanteCadena
    | '(' expresion ')' 
;

/* Declaraciones */

declaracion:
    | especificadoresDeDeclaracion
    especificadoresDeDeclaracion listaDeDeclaradores
;

especificadoresDeDeclaracion:
    especificadorDeClaseDeAlmacenamiento especificadoresDeDeclaracion
    | especificadorDeClaseDeAlmacenamiento
    | especificadorDeTipo especificadoresDeDeclaracion
    | especificadorDeTipo 
    | calificadorDeTipo especificadoresDeDeclaracion
    | calificadorDeTipo 
;

listaDeDeclaradores:
    declarador
    | listaDeDeclaradores ',' declarador
;

declarador:
    decla
    | decla '=' inicializador
;

inicializador:
    expresionDeAsignacion
    | '{' listaDeInicializadores '}'
    |  '{' listaDeInicializadores ',' '}'
;

listaDeInicializadores:
    inicializador
    | listaDeInicializadores ',' inicializador
;

especificadorDeClaseDeAlmacenamiento:
    'typedef'
    | 'static'
    | 'auto'
    | 'register'
    | 'extern'
;

especificadorDeTipo:
    'void'
    | 'char'
    | 'short'
    | 'int'
    | 'long'
    | 'float'
    | 'double'
    | 'signed'
    | 'unsigned'
    | especificadorDeStructOUnion
    | especificadorDeEnum
    | nombreDeTypedef
;

calificadorDeTipo:
    'const'
    | 'volatile'
;

especificadorDeStructOUnion:
    structOUnion identificador '{' listaDeDeclaracionesStruct '}'
    | structOUnion '{' listaDeDeclaracionesStruct '}'
    | structOUnion identificador
;

structOUnion:
    | 'struct'
    | 'union'
;

listaDeDeclaracionesStruct:
    declaracionStruct
    | listaDeDeclaracionesStruct declaracionStruct
;

declaracionStruct:
    listaDeCalificadores declaradoresStruct
;

listaDeCalificadores:
    especificadorDeTipo listaDeCalificadores
    | especificadorDeTipo
    | calificadorDeTipo listaDeCalificadores
    | calificadorDeTipo
;

declaradoresStruct:
    declaStruct
    | declaradoresStruct ',' declaStruct
;

declaStruct:
    decla
    | decla ':' expresionConstante
    | ':' expresionConstante
;

decla:
    puntero declaradorDirecto
    | declaradorDirecto
;

puntero:
    '*' listaCalificadoresTipos
    | '*'
    | '*' listaCalificadoresTipos puntero
    | '*' puntero
;

listaCalificadoresTipos:
    calificadorDeTipo
    | listaCalificadoresTipos calificadorDeTipo
;

declaradorDirecto:
    identificadores
    | '(' decla ')'
    | declaradorDirecto '[' expresionConstante ']'
    | declaradorDirecto '(' listaTiposParametros ')'
    | declaradorDirecto '(' listaDeIdentificadores ')'
;

listaTiposParametros:
    listaDeParametros
    | listaDeParametros ',' '...'
;

listaDeParametros:
    declaracionDeParametro
    | listaDeParametros ',' declaracionDeParametro 
;

declaracionDeParametro:
    especificadoresDeDeclaracion decla
    | especificadoresDeDeclaracion declaradorAbstracto
    | especificadoresDeDeclaracion 
;

listaDeIdentificadores:
    identificador
    | listaDeIdentificadores ',' identificador
;

especificadorDeEnum:
    enum identificador '{' listaDeEnumeradores '}'
    | enum '{' listaDeEnumeradores '}'
    | enum identificador
;

listaDeEnumeradores:
    enumerador
    | listaDeEnumeradores ',' enumerador
;

enumerador:
    constanteDeEnumeracion
    | constanteDeEnumeracion '=' expresionConstante
;

constanteDeEnumeracion:
    identificador
;

nombreDeTypedef:
    identificador
;

nombreDeTipo:
    listaDeCalificadores declaradorAbstracto
    | listaDeCalificadores 
;

declaradorAbstracto:
    puntero
    | puntero declaradorAbstractoDirecto
    | declaradorAbstractoDirecto
;

declaradorAbstractoDirecto:
    '(' declaradorAbstracto ')'
    | declaradorAbstractoDirecto '[' expresionConstante ']'
    | declaradorAbstractoDirecto '[' ']'
    | '[' expresionConstante ']'
    | '[' ']'   
    | declaradorAbstractoDirecto '(' listaTiposParametros ')'
    | declaradorAbstractoDirecto '(' ')'
    | '(' listaTiposParametros ')'
    | '(' ')'
;

/* Sentencias */

sentencia:
    sentenciaExpresion
    | sentenciaCompuesta
    | sentenciaDeSeleccion
    | sentenciaDeIteracion
    | sentenciaEtiquetada
    | sentenciaDeSalto
;

sentenciaExpresion:
    expresion ';'
    | ';'
;

sentenciaCompuesta:
    '{' listaDeDeclaraciones listaDeSentencias '}'
    | '{' listaDeDeclaraciones '}'
    | '{' listaDeSentencias '}'
    | '{' '}'
;

listaDeDeclaraciones:
    declaracion
    | listaDeDeclaraciones declaracion
;

listaDeSentencias:
    sentencia
    | listaDeSentencias sentencia 
;

sentenciaDeSeleccion:
    if '(' expresion ')' sentencia
    | if '(' expresion ')' sentencia else sentencia
    | switch '(' expresion ')' sentencia
;

sentenciaDeIteracion:
    while '(' expresion ')' sentencia
    | do sentencia while '(' expresion ')' sentencia
    | for '(' expresion ';' expresion ';' expresion ')' sentencia
    | for '(' expresion ';' expresion ';'  ')' sentencia
    | for '(' expresion ';'  ';' expresion ')' sentencia
    | for '(' expresion ';'  ';'  ')' sentencia
    | for '('  ';' expresion ';' expresion ')' sentencia
    | for '('  ';' expresion ';'  ')' sentencia
    | for '('  ';'  ';' expresion ')' sentencia
    | for '(' ';'  ';' ')' sentencia
;

sentenciaEtiquetada:
    case expresionConstante ':' sentencia
    | default ':' sentencia
    | identificador ':' sentencia
;

sentenciaDeSalto:
    continue ';'
    | break ';'
    | return expresion ';'
    | return ';'
    | goto identificador ';'
;

/*Definiciones Externas*/

unidadDeTraduccion:
    declaracionExterna
    | unidadDeTraduccion declaracionExterna
;

declaracionExterna:
    definicionDeFuncion
    | declaracion
;

definicionExterna:
    especificadoresDeDeclaracion decla listaDeDeclaraciones sentenciaCompuesta
    | especificadoresDeDeclaracion decla sentenciaCompuesta
    | decla listaDeDeclaraciones sentenciaCompuesta
    | decla sentenciaCompuesta

;

/*Preprocesador*/

archivoDePreprocesamiento:
    /* vacio */
    | grupo
;

grupo:
    parteDeGrupo
    | grupo parteDeGrupo
;

parteDeGrupo:
    seccionIF
    | lineaDeControl
    | lineaDeTexto
    | '#' noDirectiva
;

seccionIF:
    grupoIF gruposElif grupoElse lineaEndif
    | grupoIF gruposElif lineaEndif
    | grupoIF grupoElse lineaEndif
    | grupoIF lineaEndif
;

grupoIF:
    '#' if expresionConstante nuevaLinea grupo
    | '#' if expresionConstante nuevaLinea 
    | '#' ifdef identificador nuevaLinea grupo
    | '#' ifdef identificador nuevaLinea 
    | '#' ifndef idetinficador nuevaLinea grupo 
    | '#' ifndef idetinficador nuevaLinea 
;

gruposElif:
    grupoElif
    | gruposElif grupoElif
;

grupoElif:
    '#' elif expresionConstante nuevaLinea grupo
    | '#' elif expresionConstante nuevaLinea 
;

grupoElse:
    '#' else nuevaLinea grupo
    | '#' else nuevaLinea 
;

lineaEndif:
    '#' endif nuevaLinea
;

lineaDeControl:
    '#' include tokensPP nuevaLinea
    | '#' define identificador listaDeReemplazos nuevaLinea
    | '#' define identificador parizq listaDeIdentificadores listaDeReemplazos nuevaLinea
    | '#' define identificador parizq listaDeReemplazos nuevaLinea
    | '#' define identificador parizq listaDeReemplazos nuevaLinea
    | '#' define identificador parizq listaDeIdentificadores ',' listaDeReemplazos nuevaLinea
    | '#' undef identificador nuevaLinea
    | '#' line tokensPP nuevaLinea
    | '#' error tokensPP nuevaLinea
    | '#' error nuevaLinea
    | '#' pragma tokensPP nuevaLinea
    | '#' nuevaLinea
;

lineaDeTexto:
    tokensPP nuevaLinea
    | nuevaLinea
;

noDirectiva:
    tokensPP nuevaLinea
;

parizq:
    (NO SE QUE ES ESO)
;

listaDeReemplazos:
    /* vacio */
    | tokensPP
;

tokensPP:
    tokenDePreprocesamiento
    | tokensPP tokenDePreprocesamiento
;

nuevaLinea:
    '\n'
;

defined(NO SE COMO SE HACE)

%%

void main(){
    yyparse();
}