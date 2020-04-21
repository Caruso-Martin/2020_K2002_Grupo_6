/*TP AFD - GRUPO 6 - Integrantes: Caruso Martín, Kuljich Pedro, Lee Alex, Oreste Cristian, Riquelme Blaffet Pablo*/
/* Recomendaciones:
-	SIEMPRE ESCRIBIR LAS PALABRAS A EVALUAR SEGUIDAS DE UNA COMA
-	NO USAR ESPACIOS  
-	Usar 13 palabras de prueba como maximo, a partir del 14 no se leera / modificar cantPalabras si quiere mas palabras 		
-	Usar palabras de 12 caracteres como maximo, a partir del 13 no se leera / modificar longitudMaxInt si quiere mas palabras   
- 	En caso de modificar longitudMaxInt, sepa que no se mostraran mas de 12 caracteres
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cantPalabras 13		
#define longitudMaxInt 12	

struct tablaDeSalida{ 
	int estado; 
	char valor[longitudMaxInt];

} registroDeSalida[cantPalabras];

void llenarRegistro(FILE *, struct tablaDeSalida *); 

int esCero(char);
int estaEntreUnoSiete(char);
int esOchoNueve(char);
int esX(char);
int estaEntreAyF(char);

int automataFinitoDeterministico(char[]);
int obtenerValor(char);

void archivoSalida(struct tablaDeSalida *);

void main(){
	FILE * archivoDeEntrada = fopen("valoresDePrueba.txt", "r");					
 
	llenarRegistro(archivoDeEntrada, registroDeSalida);
	
	for (int i = 0; i< cantPalabras; i++){
		registroDeSalida[i].estado = automataFinitoDeterministico(registroDeSalida[i].valor);
	}

	archivoSalida(registroDeSalida);	
}
// Pasado un archivo y un arreglo de estructura, rellena el arreglo dentro del un arreglo de estructura
void llenarRegistro(FILE * archivoEntrada, struct tablaDeSalida * registroDeSalida){
	int j = 0, k = -1;
	fseek(archivoEntrada, 0, SEEK_END);							
    int longitudArchivo = ftell(archivoEntrada);						
	fseek(archivoEntrada, 0, SEEK_SET);

	for(int i = 0; i < longitudArchivo; i++){
		k++;
		fscanf(archivoEntrada, "%c", &registroDeSalida[j].valor[k]);

		if(registroDeSalida[j].valor[k] == ','){
			registroDeSalida[j].valor[k] = '\0';	// Borra la coma
			j++;									// Nueva palabra
			k=-1;									// Resetea la columna de llenado del array valor
		}  
	}

	fclose(archivoEntrada);
} 
int esCero(char caracter){
	return caracter == '0';
}
int estaEntreUnoSiete(char caracter){
	return caracter >= '1' && caracter <= '7';
}
int esOchoNueve(char caracter){
	return caracter == '8' || caracter == '9';
}
int esX(char caracter){
	return caracter == 'x' || caracter == 'X';
}
int estaEntreAyF(char caracter){
	return (caracter >= 'a' && caracter <= 'f') || (caracter >= 'A' && caracter <= 'F');
}
// Lee los valores del vector palabra[] y determina usando tablaDeTransicion[] si realiza acciones validas
// Si es una palabra reconocida devolvera, 3:Hexadecimal, 4:Octal, 5:Decimal. Cualquier otro valor es no reconocida
int automataFinitoDeterministico(char palabra[]){
	//Los 0 se usan para representar la accion nula en el automata
	int tablaDeTransicion[6][6] = {
		{1, 5, 5, 0, 0, 0},	// Trifurcacion: oct/hex, dec y n/r
		{4, 4, 0, 2, 0, 0},	// Trifurcacion: oct, hex y n/r
		{3, 3, 3, 0, 3, 0},	// Verificacion hexadecimal (primer caracter obligatorio)
		{3, 3, 3, 0, 3, 0},	// Verificacion hexadecimal 
		{4, 4, 0, 0, 0, 0},	// Verificacion octal 
		{5, 5, 5, 0, 0, 0}	// Verificacion decimal
	}; 
	int i = 0, fila = 0, columna;

	while(palabra[i]!='\0'){
		columna = obtenerValor(palabra[i]);
		fila = tablaDeTransicion[fila][columna];
		
		if(fila == 0)		// Si el valor de columna es 0 entonces se entiende que es una accion no valida 
			return fila;	// y devuelve ese valor
		i++;
	}
	return fila;
}
// Lee un caracter del vector palabra[] y devuelve el valor numerico de a que fila pertenece 
int obtenerValor(char x){
	if(esCero(x))
		return 0;
	if(estaEntreUnoSiete(x))
		return 1;
	if(esOchoNueve(x))
		return 2;
	if(esX(x))
		return 3;
	if(estaEntreAyF(x))
		return 4;
	return 5; 				// No reconocido
}
void archivoSalida(struct tablaDeSalida * registroDeEstados){
	FILE * archivoDeSalida = fopen("estadosDeEnteros.txt", "w");					
	int i = 0;
	char srtEstado [14];
	
	fprintf(archivoDeSalida, "|     Valor     | Tipo de entero |\n| ------------- | -------------- |\n");

	for (int i = 0; i < cantPalabras; i++){
		switch (registroDeEstados[i].estado){
			case 4:
				strcpy(srtEstado, "Octal");
				fprintf(archivoDeSalida, "| %13s | %14s |\n", registroDeEstados[i].valor, srtEstado);	
				break;
			case 5:
				strcpy(srtEstado, "Decimal");
				fprintf(archivoDeSalida, "| %13s | %14s |\n", registroDeEstados[i].valor, srtEstado);	
				break;
			case 3:
				strcpy(srtEstado, "Hexadecimal");
				fprintf(archivoDeSalida, "| %13s | %14s |\n", registroDeEstados[i].valor, srtEstado);	
				break;

			default:
				strcpy(srtEstado, "No reconocido");
				fprintf(archivoDeSalida, "| %13s | %14s | \n", registroDeEstados[i].valor, srtEstado);	
				break;
		}
	}
}