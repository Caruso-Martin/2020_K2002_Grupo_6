#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ************* COLORES PARA ERRORES ************* */

#define C_RED     "\x1b[31m"
#define C_GREEN   "\x1b[32m"
#define C_YELLOW  "\x1b[33m"
#define C_BLUE    "\x1b[34m"
#define C_MAGENTA "\x1b[35m"
#define C_CYAN    "\x1b[36m"
#define C_RESET   "\x1b[0m"

/* *************..ESTRUCTURA DE TABLA DE SIMBOLOS..************* */
struct parametro {
    char* tipoParametro;
    struct parametro* siguiente;
} * tablaParametros = NULL;

struct SYM_TBL {
    char* identificador;
    char* tipo;
    int tipoDeclaracion;    // 0 = Variable | 1 = Funcion 
    struct parametro* tiposParametros;    
    struct SYM_TBL* siguiente;
} * tablaSimbolos = NULL, * tablaDobleDeclaracion = NULL, * tablaAuxiliar = NULL;

/* *************.............PROTOTIPOS............************* */
// INGRESAR
void pushParametro(struct parametro**, char*);
void pushSimbolo(struct SYM_TBL**, char*, char*, int);

char* agregadorDeclarador(char * tipoDato, char * declarador, int cantidad);
void eliminarDeclarador(char * tipoDato, char declarador);

// IMPRIMIR
void mostrarParametros(struct parametro*);
void mostrarSimbolos(struct SYM_TBL*);

// BUSCAR
int estaDeclarado(char*);
int estaDoblementeDeclarado(char*);

// OBTENER
struct SYM_TBL* obtenerIdentificador(char* identificador);
struct parametro* obtenerParametros(char* identificador);

// CONTROL - DOBLE DE DECLARACION
void pushParametroSinRepetir(char*, char*);
void pushSimboloSinRepetir(char*, char*, int);

// CONTROL - OPERACION BINARIA
int validacionTipos(char* identificadorA, char* identificadorB);

// CONTROL - INVOCACION DE FUNCION
int cantidadParametros(struct parametro**);
int cantidadParametrosCorrecta(struct SYM_TBL*);
int tipoParametrosCorrecto(struct SYM_TBL*);
int validacionInvocacion(struct SYM_TBL*);


/* *************..MANEJO DE TABLA DE SIMBOLOS......************* */
// INGRESAR
void pushParametro(struct parametro** cabeza, char* nuevoTipoParametro) { 
    struct parametro* nuevoNodo = (struct parametro*) malloc(sizeof(struct parametro)); 

    nuevoNodo->tipoParametro = calloc(strlen(nuevoTipoParametro) + 1, sizeof(char)); 
    
    strncpy(nuevoNodo->tipoParametro, nuevoTipoParametro, strlen(nuevoTipoParametro) + 1); 

    nuevoNodo->siguiente = (*cabeza); 
    (*cabeza) = nuevoNodo; 
}  
void pushSimbolo(struct SYM_TBL** tabla, char* nuevoIdentificador, char* nuevoTipo, int nuevoTipoDeclaracion) { 
    struct SYM_TBL* nuevoNodo = (struct SYM_TBL*) malloc(sizeof(struct SYM_TBL)); 

    nuevoNodo->identificador = calloc(strlen(nuevoIdentificador) + 1, sizeof(char));
    nuevoNodo->tipo = calloc(strlen(nuevoTipo) + 1, sizeof(char));  
    
    strncpy(nuevoNodo->identificador, nuevoIdentificador, strlen(nuevoIdentificador) + 1); 
    strncpy(nuevoNodo->tipo, nuevoTipo, strlen(nuevoTipo) + 1); 

    nuevoNodo->tipoDeclaracion = nuevoTipoDeclaracion; 
    nuevoNodo->tiposParametros = NULL;

    nuevoNodo->siguiente = (*tabla); 
    (*tabla) = nuevoNodo; 
}  

char* agregadorDeclarador(char * tipoDato, char * declarador, int cantidad) {
    char * temporal = (char *) malloc(1 + strlen(tipoDato)+ strlen(declarador) * cantidad);
    
    strcpy(temporal, tipoDato);

    for(int i = 0; i < cantidad; i++){
        strcat(temporal, declarador);
    }
    
    return temporal;
}
void eliminarDeclarador(char * tipoDato, char declarador){ 
  
    int j, n = strlen(tipoDato); 
    for (int i = j = 0; i < n; i++) 
       if (tipoDato[i] != declarador) 
          tipoDato[j++] = tipoDato[i]; 
      
    tipoDato[j] = '\0'; 
} 

// IMPRIMIR
void mostrarParametros(struct parametro* lista){
    if (lista == NULL)
        return;
    
    mostrarParametros(lista->siguiente);

    printf("\nTipo de parametro.....:%15s", lista->tipoParametro);
}
void mostrarSimbolos(struct SYM_TBL* lista){
    if (lista == NULL)
        return;
    
    mostrarSimbolos(lista->siguiente);  

    switch (lista->tipoDeclaracion) {
        case 0:
            printf("\n\nIdentificador.........:%15s | Variable...Tipo: %s", lista->identificador, lista->tipo);
            break;
    
        case 1:
            printf("\n\nIdentificador.........:%15s | Funcion....Tipo: %s", lista->identificador, lista->tipo);
            printf("\nCantidad de parametros: %14i", cantidadParametros(&lista->tiposParametros));
            mostrarParametros(lista->tiposParametros);
            break;
    }
}

// BUSCAR
int estaDeclarado(char* identificadorIngreso) {
    struct SYM_TBL * temporal = (struct SYM_TBL*) malloc(sizeof(struct SYM_TBL));

    temporal = tablaSimbolos;
    
    while(temporal != NULL){
        if(!strcmp(temporal->identificador, identificadorIngreso)){
            return 1;
        } else {
            temporal = temporal->siguiente;         
        }
    }

    return 0;
}
int estaDoblementeDeclarado(char* identificadorIngreso) {
    struct SYM_TBL * temporal = (struct SYM_TBL*) malloc(sizeof(struct SYM_TBL));

    temporal = tablaDobleDeclaracion;
    
    while(temporal != NULL){
        if(!strcmp(temporal->identificador, identificadorIngreso)){
            return 1;
        } else {
            temporal = temporal->siguiente;         
        }
    }

    return 0;
}

// OBTENER
struct SYM_TBL* obtenerIdentificador(char* identificador) {
    struct SYM_TBL* temporal = tablaSimbolos;

    while (temporal != NULL && strcmp(identificador, temporal->identificador) != 0) {
        temporal = temporal->siguiente;
    }
    return temporal;
}
struct parametro* obtenerParametros(char* identificador) {
    struct SYM_TBL* temporal = tablaSimbolos;

    while (temporal != NULL && strcmp(identificador, temporal->identificador) != 0) {
        temporal = temporal->siguiente;
    }

    return temporal->tiposParametros;
}

/* *************..CONTROL - DOBLE DE DECLARACION...************* */
void pushParametroSinRepetir(char* nuevaCadena, char* nuevoTipoParametro) { 
    if(!estaDoblementeDeclarado(nuevaCadena)) {
        pushParametro(&(tablaSimbolos->tiposParametros), nuevoTipoParametro);
    } else {
         pushParametro(&(tablaDobleDeclaracion->tiposParametros), nuevoTipoParametro);   
    }
}
void pushSimboloSinRepetir(char* nuevaCadena, char* nuevoTipo, int nuevaTipoDeclaracion) { 
    if(!estaDeclarado(nuevaCadena)){
        pushSimbolo(&tablaSimbolos, nuevaCadena, nuevoTipo, nuevaTipoDeclaracion);
    } else {
        pushSimbolo(&tablaDobleDeclaracion, nuevaCadena, nuevoTipo, nuevaTipoDeclaracion);
    }
}

/* *************..CONTROL - OPERACION BINARIA......************* */
int validacionTipos(char* identificadorA, char* identificadorB) {
    if(!estaDeclarado(identificadorA)){
        printf("\nNo se ha declarado la variable: %s", identificadorA);
        return 0;
    }

    if(!estaDeclarado(identificadorB)){
        printf("\nNo se ha declarado la variable: %s", identificadorB);
        return 0;
    }

    struct SYM_TBL* idA = obtenerIdentificador(identificadorA);
    struct SYM_TBL* idB = obtenerIdentificador(identificadorB);

    if(strcmp(idA->tipo, idB->tipo) && strstr(idA->tipo,"void") == NULL && strstr(idB->tipo, "void") == NULL) { // Tipos distintos, no void
        printf("Nota: Conversion implicita de %s a %s\n", idB->tipo, idA->tipo);
        printf("I: %s T:%s - I: %s T: %s\n", idA->identificador, idA->tipo, idB->identificador, idB->tipo);
        
        return 0;
    } else if(strstr(idA->tipo, "void") != NULL || strstr(idB->tipo, "void") != NULL) { // Algun void
        printf("Error: no se puede declarar una variable de tipo void\n", idA->tipo, idB->tipo);
        printf("I: %s T:%s - I: %s T: %s\n", idA->identificador, idA->tipo, idB->identificador, idB->tipo);
        
        return 1;
    }
    
    printf("I: %s T:%s - I: %s T: %s\n", idA->identificador, idA->tipo, idB->identificador, idB->tipo);
    printf("Son del mismo tipo\n");
    
    return 0;
}

/* *************..CONTROL - INVOCACION DE FUNCION..************* */
int cantidadParametros(struct parametro** parametros) {
    int cantidad = 0;

    struct parametro* temporal = (*parametros);

    while (temporal != NULL) {
        cantidad++;
        temporal = temporal->siguiente;
    }

    return cantidad;
}
int cantidadParametrosCorrecta(struct SYM_TBL* invocacion){
    struct SYM_TBL* temporal = invocacion;
    struct SYM_TBL* comparacion = obtenerIdentificador(temporal->identificador);

    return cantidadParametros(&temporal->tiposParametros) == cantidadParametros(&comparacion->tiposParametros);
}
int tipoParametrosCorrecto(struct SYM_TBL* invocacion){
    struct parametro* temporal = invocacion->tiposParametros;
    struct parametro* comparacion = obtenerParametros(invocacion->identificador);

    while (temporal != NULL && comparacion != NULL) {
        if(strcmp(temporal->tipoParametro, comparacion->tipoParametro)) 
            return 0;
        
        comparacion = comparacion->siguiente;
        temporal = temporal->siguiente;
    }

    return 1;
}
int validacionInvocacion(struct SYM_TBL* invocacion){
    struct SYM_TBL* temporal = invocacion;

    if(!estaDeclarado(temporal->identificador)){
        printf(C_MAGENTA "\nAtencion: Invocacion sin declaracion previa\n" C_RESET);
        return 0;
    }

    if(!cantidadParametrosCorrecta(temporal)){
        printf("\nAtencion: Invocacion con cantidad incorrecta de parametros\n");
        return 0;
    }

    if(!tipoParametrosCorrecto(temporal)){
        printf("\nAtencion: Invocacion con tipo/s incorrectos\n");
        return 0;
    }

    return 1;
}

int main() {
    char* tipoAuxiliar = "int"; //Para declaraciones "listaDeclaradores ',' declarador"
    int contadorPunteros = 5;
    int contadorArreglos = 2;
    int contadorReferencia = 1;

    /*// Casos de Uso - Declaracion - Variable
    pushSimbolo(&tablaSimbolos, "variable_1", tipoAuxiliar, 0);    // Declaracion de variable
    pushSimbolo(&tablaSimbolos, "variable_2", tipoAuxiliar, 0);    // Declaracion sucesiva
    tipoAuxiliar = "char";                                         // Ejemplo de cambio de tipo de dato
    pushSimbolo(&tablaSimbolos, "variable_3", tipoAuxiliar, 0);
    */
    /*// Casos de Uso - Declaracion - Variable 2
    pushSimbolo(&tablaSimbolos, "variable_1", tipoAuxiliar, 0);    // Declaracion de variable
    
    tipoAuxiliar = agregadorDeclarador(tipoAuxiliar, "*", contadorPunteros);
    pushSimbolo(&tablaSimbolos, "variable_2", tipoAuxiliar, 0);    // Declaracion sucesiva
    
    eliminarDeclarador(tipoAuxiliar, '*');
    
    tipoAuxiliar = agregadorDeclarador(tipoAuxiliar, "[]", contadorArreglos);
    pushSimbolo(&tablaSimbolos, "variable_3", tipoAuxiliar, 0);    // Declaracion sucesiva
    
    eliminarDeclarador(tipoAuxiliar, '[');
    eliminarDeclarador(tipoAuxiliar, ']');
    
    tipoAuxiliar = agregadorDeclarador(tipoAuxiliar, "&", contadorReferencia);
    pushSimbolo(&tablaSimbolos, "variable_3", tipoAuxiliar, 0); // Declaracion sucesiva
    */
    /*// Casos de Uso - Declaracion - Funcion
    pushSimbolo(&tablaSimbolos, "funcion_1", "int", 1);     // Declaracion de funcion
    pushParametro(&(tablaSimbolos->tiposParametros), "double");
    pushParametro(&(tablaSimbolos->tiposParametros), "char"  );

    pushSimbolo(&tablaSimbolos, "funcion_2", "char", 1);
    pushParametro(&(tablaSimbolos->tiposParametros), "double");
    */

    /*// Casos de Uso - Validacion Semantica - Control binario
    pushSimbolo(&tablaSimbolos, "variable_1", tipoAuxiliar, 0);    
    pushSimbolo(&tablaSimbolos, "variable_2", tipoAuxiliar, 0);    
    tipoAuxiliar = "int**********";                                         
    pushSimbolo(&tablaSimbolos, "variable_3", tipoAuxiliar, 0);

    if(validacionTipos("variable_1", "variable_3")) 
        printf("\nError de tipos");
    */
    /*// Casos de Uso - Validacion Semantica - Invocacion de funcion
    pushSimbolo(&tablaSimbolos, "funcion_1", "int", 1);     // Declaracion de funcion
    pushParametro(&(tablaSimbolos->tiposParametros), "double");
    pushParametro(&(tablaSimbolos->tiposParametros), "char"  );

    pushSimbolo(&tablaAuxiliar, "funcion_1", "-", 1);     // Invocacion de funcion
    pushParametro(&(tablaAuxiliar->tiposParametros), "double");
    pushParametro(&(tablaAuxiliar->tiposParametros), "char"  );

    if(validacionInvocacion(tablaAuxiliar))
        printf("Fue invocada");
    */
    /*// Casos de Uso - Validacion Semantica - Doble declaracion
    pushSimboloSinRepetir("variable_1", tipoAuxiliar, 0);    // Declaracion de variable
    tipoAuxiliar = "char"; 
    pushSimboloSinRepetir("variable_1", tipoAuxiliar, 0);    // Doble declaracion

    pushSimboloSinRepetir("funcion_1", "int", 1);     // Declaracion de funcion
    pushParametroSinRepetir("funcion_1", "double");
    pushParametroSinRepetir("funcion_1", "char"  );

    pushSimboloSinRepetir("funcion_1", "int", 1);     // Doble declaracion
    pushParametroSinRepetir("funcion_1", "int");
    pushParametroSinRepetir("funcion_1", "char"  );
    */
   
    printf("\n/* ********** Tabla de simbolos ********** */");
    mostrarSimbolos(tablaSimbolos);
    
    printf("\n\n/* ********** Doble declaracion ********** */");
    mostrarSimbolos(tablaDobleDeclaracion);
}