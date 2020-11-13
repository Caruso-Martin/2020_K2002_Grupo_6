#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// STRUCT
struct parametro {
    char* tipoParametro;
    struct parametro* siguiente;
};

struct SYM_TBL {
    char* identificador;
    char* tipo;
    int tipoDeclaracion;    // 0 = Variable | 1 = Funcion 
    struct parametro* tiposParametros;    
    struct SYM_TBL* siguiente;
} * tablaSimbolos = NULL, * dobleDeclaracion = NULL;

// PROTOTIPO
void pushParametro(struct parametro**, char*);
void pushSimbolo(struct SYM_TBL**, char*, char*, int);
//void pushSimboloSinRepetir(struct SYM_TBL**, char*, int);

void mostrarParametros(struct parametro*);
void mostrarSimbolos(struct SYM_TBL*);

int cantidadParametros(struct parametro**);
int estaDeclarado(struct SYM_TBL**, char*);


// PUSH
void pushParametro(struct parametro** cabeza, char* nuevoTipoParametro) { 
    struct parametro* nuevoNodo = (struct parametro*) malloc(sizeof(struct parametro)); 

    nuevoNodo->tipoParametro = calloc(strlen(nuevoTipoParametro) + 1, sizeof(char)); 
    
    strncpy(nuevoNodo->tipoParametro, nuevoTipoParametro, strlen(nuevoTipoParametro) + 1); 

    nuevoNodo->siguiente = (*cabeza); 
    (*cabeza) = nuevoNodo; 
}  
void pushSimbolo(struct SYM_TBL** cabeza, char* nuevoIdentificador, char* nuevoTipo, int nuevaTipoDeclaracion) { 
    struct SYM_TBL* nuevoNodo = (struct SYM_TBL*) malloc(sizeof(struct SYM_TBL)); 

    nuevoNodo->identificador = calloc(strlen(nuevoIdentificador) + 1, sizeof(char));
    nuevoNodo->tipo = calloc(strlen(nuevoTipo) + 1, sizeof(char));  
    
    strncpy(nuevoNodo->identificador, nuevoIdentificador, strlen(nuevoIdentificador) + 1); 
    strncpy(nuevoNodo->tipo, nuevoTipo, strlen(nuevoTipo) + 1); 

    nuevoNodo->tipoDeclaracion = nuevaTipoDeclaracion; 
    nuevoNodo->tiposParametros = NULL;

    nuevoNodo->siguiente = (*cabeza); 
    (*cabeza) = nuevoNodo; 
}  
void pushSimboloSinRepetir(struct SYM_TBL** cabeza, char* nuevaCadena, char* nuevoTipo, int nuevaTipoDeclaracion) { 
    if(estaDeclarado(cabeza, nuevaCadena)){
        pushSimbolo(&tablaSimbolos, nuevaCadena, nuevoTipo, nuevaTipoDeclaracion);
    } else {
        pushSimbolo(&dobleDeclaracion, nuevaCadena, nuevoTipo, nuevaTipoDeclaracion);
    }
}

// MOSTRAR LISTAS
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

// UTILES PARA VALIDACIONES SEMANTICAS
int estaDeclarado(struct SYM_TBL** cabeza, char* identificadorIngreso) {
    struct SYM_TBL * temporal = (struct SYM_TBL*) malloc(sizeof(struct SYM_TBL));
    
    temporal = (*cabeza);
    
    while(temporal != NULL){
        if(!strcmp(temporal->identificador, identificadorIngreso)){
            return 0;
        } else {
            temporal = temporal->siguiente;         
        }
    }

    return 1;
}
int cantidadParametros(struct parametro** parametros) {
    int cantidad = 0;

    struct parametro* temporal = (*parametros);

    while (temporal != NULL) {
        cantidad++;
        temporal = temporal->siguiente;
    }

    return cantidad;
}

struct SYM_TBL* buscarIdentificadorEnTabla(struct SYM_TBL* tabla, char* identificador) {
    struct SYM_TBL* temporal = tabla;

    while (temporal != NULL && strcmp(identificador, temporal->identificador) != 0) {
        temporal = temporal->siguiente;
    }
    
    return temporal;
}

/*int cantidadParametrosCorrecta(struct parametros** tabla, char* identificadorIngreso) {
    int cantidad = 0;

    struct parametros* temporal = (*tabla);

    while (temporal != NULL) {
        cantidad++;
        temporal = (*temporal)->siguiente;
    }

    return cantidad;
}*/



// VALIDACIONES SEMANTICAS

/*int validacionInvocacion(struct SYM_TBL** tabla, char* identificadorIngreso){
    if(!estaDeclarado(tabla, identificadorIngreso)){
        printf("\nAtencion: Invocacion sin declaracion previa\n");
        return 0;
    }

    if(!cantidadParametrosCorrecta(tabla, identificadorIngreso)){
        printf("\nAtencion: Invocacion con cantidad incorrecta de parametros\n");
        return 0;
    }

    if(!tipoParametros()){
        printf("\nAtencion: Invocacion con tipo/s incorrectos de variable\n");
        return 0;
    }

    return 1;
}*/

int validacionTipos(char* identificadorA, char* identificadorB) {
    struct SYM_TBL* idA = buscarIdentificadorEnTabla(tablaSimbolos, identificadorA);
    struct SYM_TBL* idB = buscarIdentificadorEnTabla(tablaSimbolos, identificadorB);

    if(strcmp(idA->tipo, idB->tipo) && strcmp(idA->tipo,"void") && strcmp(idB->tipo, "void")) { // Tipos distintos, no void
        printf("Nota: Conversion implicita de %s a %s\n", idB->tipo, idA->tipo);
        printf("I: %s T:%s - I: %s T: %s\n", idA->identificador, idA->tipo, idB->identificador, idB->tipo);
        return 0;
    } else if(!strcmp(idA->tipo, "void") || !strcmp(idB->tipo, "void")) { // Algun void
        printf("Error: no se puede declarar una variable de tipo void\n", idA->tipo, idB->tipo);
        printf("I: %s T:%s - I: %s T: %s\n", idA->identificador, idA->tipo, idB->identificador, idB->tipo);
        return 0;
    }

    return 1;
}

/*void tipoParametros() {
    struct SYM_TBL* invocacion = NULL;

    pushSimbolo()

}*/

int main() {
    printf("\n/* ********** Advertencias y errores ********** */\n");
    pushSimboloSinRepetir(&tablaSimbolos, "funcion_1", "int", 1);
    pushParametro(&(tablaSimbolos->tiposParametros), "int"   );
    pushParametro(&(tablaSimbolos->tiposParametros), "double");
    pushParametro(&(tablaSimbolos->tiposParametros), "char"  );

    pushSimbolo(&tablaSimbolos, "variable_1", "int", 0);

    pushSimboloSinRepetir(&tablaSimbolos, "funcion_2", "void", 1);
    pushParametro(&(tablaSimbolos->tiposParametros), "double");
    pushParametro(&(tablaSimbolos->tiposParametros), "char"  );

    pushSimboloSinRepetir(&tablaSimbolos, "funcion_1", "void", 1);
    pushParametro(&(dobleDeclaracion->tiposParametros), "int"   ); // Modificar

    pushSimboloSinRepetir(&tablaSimbolos, "variable_2", "short", 0);

    if(validacionTipos("variable_1", "variable_2")){
        printf("Son del mismo tipo\n");
    }

    printf("\n/* ********** Tabla de simbolos ********** */");
    mostrarSimbolos(tablaSimbolos);

    printf("\n\n/* ********** Doble declaracion ********** */");
    mostrarSimbolos(dobleDeclaracion);

}