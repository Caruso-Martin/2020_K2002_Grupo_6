/*TP AFP - GRUPO 6 - Integrantes: Caruso Martín, Kuljich Pedro, Lee Alex, Oreste Cristian, Riquelme Blaffet Pablo*/
/* Recomendaciones:
-	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define textoEnBlanco       "\033[0m"
#define textoEnRojo         "\033[31m" 
#define largoExpresion      100
#define tamanioCadenaPush   6

struct tabla {
    int estado; 
    char cadenaPush[tamanioCadenaPush];
};

void procesarCadena(char[]);

int esCero(char);
int estaEntreUnoNueve(char);
int esOperador(char);
int esPartentesisApertura(char);
int esPartentesisCierre(char);
int obtenerValor(char);

int cantLetras(char[]);
void pop (char[]);
void push (char[], char[]);
int automataFinitoPila(char[]);

void ubicacionError(char[], int); 

void main(){
    char expresion[largoExpresion] = "";
    int i = 0;
    while (expresion[0] != ';'){ // ';' es un valor sentinela
        procesarCadena(expresion);

        int esSintacticamenteCorrecta = automataFinitoPila(expresion);

        if(esSintacticamenteCorrecta == -1){ //CREO QUE ES AL REVES LOS PRINTF
            printf("La expresion ingresada es sintacticamente correcta\n");
        } else {
            printf("La expresion ingresada NO es sintacticamente correcta\n");
            ubicacionError(expresion, esSintacticamenteCorrecta); //TENER CUIDADO
        }
    }
    printf("Salio del while");

}
void procesarCadena(char expresion[]){ 
    char texto[largoExpresion];
    int i = 0, j = 0;

    printf("Ingrese expresion: ");
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
	return caracter == '(';
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
int cantLetras(char palabra[]){
    int cantidadLetras = 0;  
        
    for(int i = 0; i < strlen(palabra); i++) {  
        if(palabra[i] != ' ')  
            cantidadLetras++;  
    }  

    return cantidadLetras;
}
void pop (char cadena[]){
    for(int i = 1; i <= cantLetras(cadena); i++){
        cadena[i-1] = cadena[i];
    }
}
void push (char cadenaModificada[], char cadenaModificadora[]){        
    for (int j = 0; j < cantLetras(cadenaModificadora); j++){
        for(int i = cantLetras(cadenaModificada); 0 <= i; i--){
            cadenaModificada[i+1] = cadenaModificada[i];
            cadenaModificada[i] = ' ';
        }
    }    
    for (int i = 0; i < cantLetras(cadenaModificadora); i++)
        cadenaModificada[i] = cadenaModificadora[i];

}
int automataFinitoPila(char expresion[]){ //Devuelve la posicion del primer error encontrado; si no hay, devuelve 0
    struct tabla tablaDeMovimiento[6][5] = {
        {{-1, "-"}, { 1, "$"}, {-1, "-"}, { 2, "R$"}, {-1, "-" }},
        {{ 1, "$"}, { 1, "$"}, { 0, "$"}, {-1,  "-"}, {-1, "-" }},
        {{-1, "-"}, { 3, "R"}, {-1, "-"}, { 2, "RR"}, {-1, "-" }},
        {{ 3, "R"}, { 3, "R"}, { 2, "R"}, {-1,  "-"}, { 4, '\0'}},
        {{-1, "-"}, {-1, "-"}, { 2, "R"}, {-1,  "-"}, { 5, '\0'}},
        {{-1, "-"}, {-1, "-"}, { 0, "$"}, {-1,  "-"}, {-1, "-" }} 
    }; //DE QUE TIPO ES LA TABLA
	
    struct tabla estadoSiguiente = {0, "$"};

    int i = 0, columna = 0;

    while(expresion[i]!='\0'){
		columna = obtenerValor(expresion[i]); 

        pop(estadoSiguiente.cadenaPush);
               
        if (columna != 4 || estadoSiguiente.cadenaPush[0] == '-')
            push(estadoSiguiente.cadenaPush, tablaDeMovimiento[estadoSiguiente.estado][columna].cadenaPush);

        printf("%2d. Caracter: %c | Posicion tabla - Fila: %2d Columna: %2d | Cadena push: %5s|\n", i, expresion[i], estadoSiguiente.estado, columna, estadoSiguiente.cadenaPush);
        
        estadoSiguiente.estado = tablaDeMovimiento[estadoSiguiente.estado][columna].estado;

        if(estadoSiguiente.cadenaPush[0] == '$' && estadoSiguiente.estado == 4)
            estadoSiguiente.estado = 5;

		if(estadoSiguiente.estado == -1)		// Si el valor de columna es 0 entonces se entiende que es una accion no valida 
			return i;	    // y devuelve ese valor
		i++;
	}

    return -1; 
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