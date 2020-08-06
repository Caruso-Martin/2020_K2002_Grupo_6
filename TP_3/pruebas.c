#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Listado {
    int numero;
    char* cadena;
    struct Listado* siguiente;
} *palabraReservada = NULL;

void pushCadena(struct Listado** cabeza, char* nuevaCadena, int longitudCadena) { 
    char * cadenaIngreso = calloc(longitudCadena, sizeof(char));    
    strncpy(cadenaIngreso, nuevaCadena, longitudCadena);
    
    /* 1. allocate node */
    struct Listado* nuevoNodo = (struct Listado*) malloc(sizeof(struct Listado)); 
    
    /* 2. put in the string  */
    nuevoNodo -> cadena = strdup(cadenaIngreso); 

    nuevoNodo -> numero = 0; 
    
    /* 3. Make next of new node as head */
    nuevoNodo -> siguiente = (*cabeza); 
    
    /* 4. move the head to point to the new node */
    (*cabeza) = nuevoNodo; 
} 
int repeticion(struct Listado** cabeza, char * cadIngreso){
    struct Listado * temp = (struct Listado *)malloc(sizeof(struct Listado));
    temp = (*cabeza);
    while(temp != NULL){
        if(!strcmp (temp -> cadena, cadIngreso)){
            return temp -> numero++;
        } else {
            temp = temp -> siguiente;         
        }
    }
    return 0;
}
void pushListaSinRepetir(struct Listado** cabeza, char* nuevaCadena, int longitudCadena){
    char * cadenaIngreso = calloc(longitudCadena, sizeof(char));    
    strncpy(cadenaIngreso, nuevaCadena, longitudCadena);
    
    struct Listado* nuevoNodo = (struct Listado*) malloc(sizeof(struct Listado)); 

    int seRepite = repeticion(cabeza, cadenaIngreso);

    if(!seRepite){
        nuevoNodo -> cadena = strdup(cadenaIngreso); 
        nuevoNodo -> numero = 1;
        nuevoNodo -> siguiente = (*cabeza); 
        (*cabeza) = nuevoNodo; 
    } else {
        nuevoNodo -> numero = seRepite;
    }
} 

void pushCadenaSinRepetirF(struct Listado **lista, char* nuevaCadena, int cardinalidad){
    char * cadenaIngreso;
    memset(cadenaIngreso, '\0', sizeof(nuevaCadena));
    strncpy(cadenaIngreso, nuevaCadena, cardinalidad);
    
    for (    ; *lista; lista = &(*lista)->siguiente) {
        if((*lista)->cadena == strdup(cadenaIngreso)){
            (*lista)->numero++;
            return;
        }
   }
   *lista = malloc(sizeof **lista);
   (*lista)->cadena = strdup(cadenaIngreso);
   (*lista)->numero = 1;
   (*lista)->siguiente = NULL;
   
}

void mostrarLista_OrdenLista(struct Listado* lista, char * tipoLexama, char* tipoValor) 
{ 
  while (lista != NULL) 
  { 
    printf("%s: %s - %s: %d\n", tipoLexama, lista -> cadena, tipoValor, lista -> numero);
    lista = lista->siguiente; 
  } 
} 

void mostrarLista_OrdenAparicion(struct Listado* lista, char * tipoLexama, char* tipoValor) {
    if (lista == NULL)
        return;
    
    mostrarLista_OrdenAparicion(lista -> siguiente, tipoLexama, tipoValor);
    printf("%s: %8s - %s: %d\n", tipoLexama, lista -> cadena, tipoValor, lista -> numero);
}

void swap(struct Listado *a, struct Listado *b) 
{ 
    int temp = a->numero; 
    char * tempc = strdup(a->cadena);

    a->numero = b->numero; 
    a->cadena = strdup(b->cadena);

    b->numero = temp; 
    b->cadena = strdup(tempc);
} 

void bubbleSort(struct Listado *start) 
{ 
    int swapped, i; 
    struct Listado *ptr1; 
    struct Listado *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->siguiente != lptr) 
        { 
            if (strcmp (ptr1->cadena, ptr1->siguiente->cadena) < 0) 
            {  
                swap(ptr1, ptr1->siguiente); 
                swapped = 1; 
            } 
            ptr1 = ptr1->siguiente; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  


int main(){

    pushListaSinRepetir(&palabraReservada, "z", 1);
    pushListaSinRepetir(&palabraReservada, "a", 1);
    pushListaSinRepetir(&palabraReservada, "b", 1);
    pushListaSinRepetir(&palabraReservada, "f", 1);
    pushListaSinRepetir(&palabraReservada, "c", 1);

    pushListaSinRepetir(&palabraReservada, "a", 1);
    pushListaSinRepetir(&palabraReservada, "b", 1);
    pushListaSinRepetir(&palabraReservada, "f", 1);
    pushListaSinRepetir(&palabraReservada, "c", 1);

    
    pushListaSinRepetir(&palabraReservada, "a", 1);
    pushListaSinRepetir(&palabraReservada, "f", 1);
    pushListaSinRepetir(&palabraReservada, "c", 1);

    pushListaSinRepetir(&palabraReservada, "f", 1);
    pushListaSinRepetir(&palabraReservada, "c", 1);

    pushListaSinRepetir(&palabraReservada, "c", 1);
    
    
    bubbleSort(palabraReservada);

    mostrarLista_OrdenAparicion(palabraReservada, "Palabra", "Numero");
}