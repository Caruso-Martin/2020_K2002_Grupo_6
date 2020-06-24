#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://stackoverflow.com/questions/13241875/c-linked-list-push-function-just-checking-if-this-is-correct

struct listado{
    char* cadena;
    int numero;
    struct listado* siguiente;
} identificadores;
/*
identificadores: Identificador, Cantidad de apariciones 
literalesCadena: Cadena, Longitud cadena
palabrasReservadas: Palabra reservada, Orden
constOctales: Numero, Conversion
constDecimales: Numero, Numero
constHexadecimales: Numero, Conversion
constReales: Numero, Numero (convertir a mantisa y parte entera en output)
operadorYPuntuacion = Simbolo, Cantidad de apariciones
comentarios: Cadena, 0 = simple 1 = multiple 
*/

void ordenamientoAlfabetico();

int conversorADecimal(int); 
int sumatoria(int[]);
int parteEntera(float);
float mantisa(float);

void push(struct listado**, char*); 


void main(){
    printf("Conversion: %i\n", conversorADecimal(010));

    printf("Parte entera: %i\n", parteEntera(35.99));
     
    printf("Mantisa: %f\n", mantisa(35.9));

    /*
    int l[] = {1, 2, 3, 4, 5, 6, 1};
    printf("Sumatoria: %i", sumatoria(l));
    */

    struct listado* cabeza = NULL; 
    
    char a[5]; 
    itoa(5, a, 10);

    push(&cabeza, a);
    printf("Valor lista: %s \n", cabeza -> cadena);

    //ordenamientoAlfabetico();
}

//NUMEROS
int conversorADecimal(int numOriginal){
    char string[50];
    itoa(numOriginal, string, 10);
    return atoi(string);
}

int sumatoria(int listaNum[]){  
    int sum = 0, longLista = sizeof(listaNum) / sizeof(int);
    printf("Longitud array: %i \n", longLista);
    for (int i = 0; i < longLista; i++){
        sum += listaNum[i];
    }
    return sum;
}

int parteEntera(float numOriginal){
    return (int) numOriginal;
}

float mantisa(float numOriginal){
    int pEntera = (int) numOriginal;
    return numOriginal - pEntera;
}

//LISTADO

void push(struct listado** lista, char* info){ 
    /* 1. allocate node */
    struct listado* nodo = (struct listado*) malloc(sizeof(struct listado)); 
   
    /* 2. put in the data  */
    //nodo -> numero  = info; 
    strcpy(nodo -> cadena, info);

    /* 3. Make next of new node as head */
    nodo -> siguiente = (*lista); 
   
    /* 4. move the head to point to the new node */
    (*lista) = nodo; 
} 

void mostarLista(struct listado *lista) 
{ 
  while (lista != NULL) 
  { 
     printf(" %d ", lista -> numero); 
     lista = lista -> siguiente; 
  } 
} 