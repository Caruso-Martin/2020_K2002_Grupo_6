#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define longitudMaxInt 6 // El mayor int es +32,767
#define cantPalabras 13

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
int automataEnteros(char[]);

void archivoSalida(struct tablaDeSalida *);


void main(){
	FILE * archivoDeEntrada = fopen("valoresDePrueba.txt", "r");					
 
	llenarRegistro(archivoDeEntrada, registroDeSalida);

	for (int i = 0; i < cantPalabras; i++){
		registroDeSalida[i].estado = automataEnteros(registroDeSalida[i].valor);
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
			registroDeSalida[j].valor[k] = '\0';// Borra la coma
			j++;// Nueva palabra
			k=-1;// Resetea la columna de llenado del array valor
		}  
	}
	// Testing de funcionamiento correcto de la funcion
	// Devuelve palabra 
	//printf("%s\n",registroDeSalida[12].valor);
	// Devuelve caracter de palabra      
	//printf("%c\n",registroDeSalida[12].valor[3]); 

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
// 0: No reconocido, 1: Octal, 2: Decimal, 3: Hexadecimal
int automataEnteros(char palabra[]){
	int f = 0, c = 0, l = 0;
	int matrizTTransicion[7][6] = { 
		{2, 1, 1, 6, 6, 6},// Trifurcacion: oct/hex, dec y n/r
		{1, 1, 1, 6, 6, 6},// Verificacion decimal 
		{5, 5, 6, 3, 6, 6},// Trifurcacion: oct, hex y n/r
		{4, 4, 4, 6, 4, 4},// Verificacion hexadecimal (primer caracter obligatorio)
		{4, 4, 4, 6, 4, 4},// Verificacion hexadecimal
		{5, 5, 6, 6, 6, 6},// Verificacion octal
		{6, 6, 6, 6, 6, 6} // ***Duda: ¿es realmente necesaria esta fila?
	};	

}
void archivoSalida(struct tablaDeSalida * registroDeEstados){
	FILE * archivoDeSalida = fopen("estadosDeEnteros.txt", "w");					
	int i = 0;
	char srtEstado [14];
	
	fprintf(archivoDeSalida, "|  Valor  | Tipo de entero |\n| ------- | -------------- |\n");

	for (int i = 0; i < cantPalabras; i++){
		switch (registroDeEstados[i].estado){
			case 1:
				strcpy(srtEstado, "Octal");
				fprintf(archivoDeSalida, "| %7s | %14s |\n", registroDeEstados[i].valor, srtEstado);	
				break;
			case 2:
				strcpy(srtEstado, "Decimal");
				fprintf(archivoDeSalida, "| %7s | %14s |\n", registroDeEstados[i].valor, srtEstado);	
				break;
			case 3:
				strcpy(srtEstado, "Hexadecimal");
				fprintf(archivoDeSalida, "| %7s | %14s |\n", registroDeEstados[i].valor, srtEstado);	
				break;

			default:
				strcpy(srtEstado, "No reconocido");
				fprintf(archivoDeSalida, "| %7s | %14s | \n", registroDeEstados[i].valor, srtEstado);	
				break;
		}
	}
}