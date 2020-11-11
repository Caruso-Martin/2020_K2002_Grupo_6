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
    int tipoDeclaracion;    // 0 = Variable | 1 = Funcion 
    struct parametro* tiposParametros;    
    struct SYM_TBL* siguiente;
} * tablaSimbolos = NULL, * dobleDeclaracion = NULL;

// PROTOTIPO
void pushParametro(struct parametro**, char*);
void pushSimbolo(struct SYM_TBL**, char*, int);
void pushSimboloSinRepetir(struct SYM_TBL**, char*, int);

void mostrarParametros(struct parametro*);
void mostrarSimbolos(struct SYM_TBL*);

int cantidadParametros(struct parametro**);
int repeticion(struct SYM_TBL**, char*);


// PUSH
void pushParametro(struct parametro** cabeza, char* nuevoTipoParametro) { 
    struct parametro* nuevoNodo = (struct parametro*) malloc(sizeof(struct parametro)); 

    nuevoNodo->tipoParametro = calloc(strlen(nuevoTipoParametro) + 1, sizeof(char)); 
    
    strncpy(nuevoNodo->tipoParametro, nuevoTipoParametro, strlen(nuevoTipoParametro) + 1); 

    nuevoNodo->siguiente = (*cabeza); 
    (*cabeza) = nuevoNodo; 
}  
void pushSimbolo(struct SYM_TBL** cabeza, char* nuevaCadena, int nuevoTipo) { 
    struct SYM_TBL* nuevoNodo = (struct SYM_TBL*) malloc(sizeof(struct SYM_TBL)); 

    nuevoNodo->identificador = calloc(strlen(nuevaCadena) + 1, sizeof(char)); 
    
    strncpy(nuevoNodo->identificador, nuevaCadena, strlen(nuevaCadena) + 1); 
    nuevoNodo->tipoDeclaracion = nuevoTipo; 
    nuevoNodo->tiposParametros = NULL;

    nuevoNodo->siguiente = (*cabeza); 
    (*cabeza) = nuevoNodo; 
}  

/*void pushSimboloSinRepetir(struct SYM_TBL** cabeza, char* nuevaCadena, int nuevoTipo) { 
    if(repeticion(cabeza, nuevaCadena)){
        pushSimbolo(&tablaSimbolos, nuevaCadena, nuevoTipo);
    } else {
        pushSimbolo(&dobleDeclaracion, nuevaCadena, nuevoTipo);
    }
}*/  

// MOSTRAR LISTAS
void mostrarParametros(struct parametro* lista){
    if (lista == NULL)
        return;
    
    mostrarParametros(lista->siguiente);

    printf("\nTipo de parametro:%20s", lista->tipoParametro);
}
void mostrarSimbolos(struct SYM_TBL* lista){
    if (lista == NULL)
        return;
    
    mostrarSimbolos(lista->siguiente);  

    switch (lista->tipoDeclaracion) {
        case 0:
            printf("\n\nIdentificador....:%20s (Variable)", lista->identificador);
            break;
    
        case 1:
            printf("\n\nIdentificador....:%20s  (Funcion)", lista->identificador);
            mostrarParametros(lista->tiposParametros);
            break;
    }
}

// VALIDACIONES SEMANTICAS
int cantidadParametros(struct parametro** parametros) {
    int cantidad = 0;

    struct parametro* temporal = (*parametros);

    while (temporal != NULL) {
        cantidad++;
        temporal = temporal->siguiente;
    }

    return cantidad;
}
int repeticion(struct SYM_TBL** cabeza, char* cadenaIngreso) {
    struct SYM_TBL * temporal = (struct SYM_TBL*) malloc(sizeof(struct SYM_TBL));
    
    temporal = (*cabeza);
    
    while(temporal != NULL){
        if(!strcmp(temporal->identificador, cadenaIngreso)){
            return 0;
        } else {
            temporal = temporal->siguiente;         
        }
    }

    return 1;
}

int main() {
    pushSimbolo(&tablaSimbolos, "funcion_1", 1);
    pushParametro(&(tablaSimbolos->tiposParametros), "int"   );
    pushParametro(&(tablaSimbolos->tiposParametros), "double");
    pushParametro(&(tablaSimbolos->tiposParametros), "char"  );

    pushSimbolo(&tablaSimbolos, "variable_1", 0);

    pushSimbolo(&tablaSimbolos, "funcion_2", 1);
    pushParametro(&(tablaSimbolos->tiposParametros), "double");
    pushParametro(&(tablaSimbolos->tiposParametros), "char"  );

    /*pushSimbolo(&tablaSimbolos, "funcion_1", 1);
    pushParametro(&(tablaSimbolos->tiposParametros), "int"   );*/

    pushSimbolo(&tablaSimbolos, "variable_2", 0);

    printf("\n/* ********** Tabla de simbolos ********** */");
    mostrarSimbolos(tablaSimbolos);

    /*printf("\nDoble declaracion\n");
    mostrarSimbolos(dobleDeclaracion);*/

}