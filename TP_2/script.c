/*TP AFP - GRUPO 6 - Integrantes: Caruso Martín, Kuljich Pedro, Lee Alex, Oreste Cristian, Riquelme Blaffet Pablo*/
/* Recomendaciones:
-	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define textoEnBlanco   "\033[0m"
#define textoEnRojo     "\033[31m" 
#define largoExpresion  100

struct estadoTabla {
    int estadoSiguiente; 
    char cadenaPush[3];
};

void procesarCadena(char[]);
void push();
void pop();
int automataFinitoPila(char[]);
void ubicacionError(char[], int); 

void main(){
    char expresion[largoExpresion] = "";
    int i = 0;
    while (expresion[0] != ';'){ // ';' es un valor sentinela
        procesarCadena(expresion);

        int esSintacticamenteCorrecta = automataFinitoPila(expresion);

        if(!esSintacticamenteCorrecta){
            printf("La expresion ingresada NO es sintacticamente correcta\n");
            //ubicacionError(expresion, esSintacticamenteCorrecta); //TENER CUIDADO
        } else {
            printf("La expresion ingresada es sintacticamente correcta\n");
        }
    }
    printf("Salio del while");

}
void procesarCadena(char expresion[]){ 
    char texto[largoExpresion];
    int i = 0, j = 0;

    printf("Ingreso expresion: ");
    gets(texto);

    while (texto[j] != '\0'){
        if (texto[j] != ' ') {
          expresion[i] = texto[j];
           i++;
        }
        j++;
    }

    expresion[i] = '\0';
 
    printf("Expresion sin espacios: %s\n", expresion);
}
void push(){
    // Relacionado con (
    // En tabla son las posiciones [0][3] para primer (; [2][3] para segundo o superior

}
void pop(){
    // Relacionado con )
    // En tabla son las posiciones [3][4] para primer ); [4][4] para segundo o superior

}
int automataFinitoPila(char expresion[]){ //Devuelve la posicion del primer error encontrado; si no hay, devuelve 0
    int estadoActual = 0, columnaCaracter = 0; 
    struct estadoTabla tablaDeMovimiento[6][5][1] = {
        {{-1},  { 1},   {-1},  { 2},   {-1}},
        {{ 1},  { 1},   { 0},  {-1},   {-1}},
        {{-1},  { 3},   {-1},  { 2},   {-1}},
        {{ 4},  { 4},   { 3},  {-1},   { 5}},
        {{-1},  {-1},   { 3},  {-1},   { 5}},
        {{-1},  {-1},   { 0},  {-1},   {-1}} 
    }; //DE QUE TIPO ES LA TABLA


}
void ubicacionError(char expresion[], int posicionError){
    int i = 0;
    printf("El error se encontro en la posicion %d - ", posicionError);
    while(expresion[i] != '\0'){
        if(i != posicionError){
            printf("%c" , expresion[i]);
        } else {
            printf(textoEnRojo "%c" textoEnBlanco, expresion[i]);
        }
        i++;
    }
    printf("\n");
    //Uso de color: https://stackoverflow.com/questions/1961209/making-some-text-in-printf-appear-in-green-and-red
}