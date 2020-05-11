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

struct tabla {
    int estado; 
    char cadenaPush[3];
};

void procesarCadena(char[]);
void push(struct tabla, char[]);
void pop(struct tabla, char[]);
int automataFinitoPila(char[]);
void ubicacionError(char[], int); 

void main(){
    char expresion[largoExpresion] = "";
    int i = 0;
    while (expresion[0] != ';'){ // ';' es un valor sentinela
        procesarCadena(expresion);

        int esSintacticamenteCorrecta = automataFinitoPila(expresion);

        if(esSintacticamenteCorrecta){ //CREO QUE ES AL REVES LOS PRINTF
            printf("La expresion ingresada NO es sintacticamente correcta\n");
            ubicacionError(expresion, esSintacticamenteCorrecta); //TENER CUIDADO
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
void push(struct tabla estadoSiguiente, char cadenaEnTabla[]){
    // Relacionado con (
    // En tabla son las posiciones [0][3] para primer (; [2][3] para segundo o superior

    if(cadenaEnTabla == "-"){
        estadoSiguiente.cadenaPush[0] == '\0';
    } else if (cadenaEnTabla[0] != '\0' && cadenaEnTabla != "RR" && cadenaEnTabla != "R$"){
        for (int i = 0; i < sizeof(estadoSiguiente.cadenaPush); i++){
            if(estadoSiguiente.cadenaPush[i] == '\0')
                estadoSiguiente.cadenaPush[i - 1] = cadenaEnTabla[0];
        } 
    } else {
        for (int i = 0; i < sizeof(estadoSiguiente.cadenaPush); i++){
            if(estadoSiguiente.cadenaPush[i] == '\0'){
                estadoSiguiente.cadenaPush[i - 1] = cadenaEnTabla[0];
                estadoSiguiente.cadenaPush[i] = cadenaEnTabla[1];
                estadoSiguiente.cadenaPush[i+1] = '\0';
            }
        } 
    }
}
void pop(struct tabla estadoSiguiente, char cadenaEnTabla[]){
    // Relacionado con )
    // En tabla son las posiciones [3][4] para primer ); [4][4] para segundo o superior

    if(cadenaEnTabla[0] == '-'){
        estadoSiguiente.cadenaPush[0] == '\0';
    } else {
        for (int i = 0; i < sizeof(estadoSiguiente.cadenaPush); i++){
            if(estadoSiguiente.cadenaPush[i] == '\0')
                estadoSiguiente.cadenaPush[i - 1] == '\0';
        } 
    }
}
int esCero(char caracter){
	return caracter == '0';
}
int estaEntreUnoNueve(char caracter){
	return caracter >= '1' && caracter <= '9';
}
int esOperador(char caracter){
	return caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/';
}
int esPartentesisApertura(char caracter){
	return caracter >= '(';
}
int esPartentesisCierre(char caracter){
	return caracter == ')';
}
int obtenerValor(char caracter){
	if(esCero(caracter))
		return 0;
	if(estaEntreUnoNueve(caracter))
		return 1;
	if(esOperador(caracter))
		return 2;
	if(esPartentesisApertura(caracter))
		return 3;
	if(esPartentesisCierre(caracter))
		return 4;
	return 5; 				// No reconocido
}
int automataFinitoPila(char expresion[]){ //Devuelve la posicion del primer error encontrado; si no hay, devuelve 0
    struct tabla tablaDeMovimiento[6][5] = {
        {{-1, "-"}, { 1, "$"}, {-1, "-"}, { 2, "R$"}, {-1, "-" }},
        {{ 1, "$"}, { 1, "$"}, { 0, "$"}, {-1,  "-"}, {-1, "-" }},
        {{-1, "-"}, { 3, "R"}, {-1, "-"}, { 2, "RR"}, {-1, "-" }},
        {{ 4, "R"}, { 4, "R"}, { 3, "R"}, {-1,  "-"}, { 5, '\0'}},
        {{-1, "-"}, {-1, "-"}, { 3, "R"}, {-1,  "-"}, { 5, '\0'}},
        {{-1, "-"}, {-1, "-"}, { 0, "$"}, {-1,  "-"}, {-1, "-" }} 
    }; //DE QUE TIPO ES LA TABLA
	
    struct tabla estadoSiguiente = {0, "$"};

    int i = 0, fila = 0, columna = 0;

    while(expresion[i]!='\0'){
		columna = obtenerValor(expresion[i]); 

        pop(estadoSiguiente, tablaDeMovimiento[fila][columna].cadenaPush);
        push(estadoSiguiente, tablaDeMovimiento[fila][columna].cadenaPush);
        
        fila = estadoSiguiente.estado;

		if(estadoSiguiente.cadenaPush[0] == '\0')		// Si el valor de columna es 0 entonces se entiende que es una accion no valida 
			return i;	    // y devuelve ese valor
		i++;
	}

    return 0; 
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