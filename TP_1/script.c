#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define longitudMaxInt 6 // El mayor int es +32,767
#define cantPalabras 13

#define q0 0
#define q1 1
#define q2 2
#define q3 3
#define q4 4
#define q5 5
#define q6 6

struct tablaDeSalida{ 
	int estado; 
	char valor[longitudMaxInt];

} registroDeSalida[cantPalabras];

void llenarRegistro(FILE *, struct tablaDeSalida *); 
int esOctal(char[]);
int esDecimal(char[]);
int esHexadecimal(char[]);
int automataImprovisado(char[]);
void archivoSalida(struct tablaDeSalida *);

void main(){
	FILE * archivoDeEntrada = fopen("valoresDePrueba.txt", "r");					
 
	llenarRegistro(archivoDeEntrada, registroDeSalida);
	
	/*for (int i = 0; i < cantPalabras; i++){
		registroDeSalida[i].estado = automataImprovisado(registroDeSalida[i].valor);
	}*/

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
int esOctal(char palabra[]){
	int estado = 1, i = 1; 

	if (palabra[0] == '0'){
		while(palabra[i+1] != '\0'){
			if (!(palabra[i] >= '0' && palabra[i] <= '7'))
				return 0;
			i++;
		}
	}
	
	return estado;
}
int esDecimal(char palabra[]){
	int estado = 2, i = 0; 

	if (palabra[0] >= '1' && palabra[0] <= '9'){
		while(palabra[i+1] != '\0'){
			if (!(palabra[i] >= '0' && palabra[i] <= '9'))
				return 0;
			i++;
		}
	}
	
	return estado;
}
int esHexadecimal(char palabra[]){
	int estado = 3, i = 2; 

	if (palabra[0] == '0' && (palabra[1] == 'X' || palabra[1] == 'x')){
		while(palabra[i+1] != '\0'){
			if (!((palabra[i] >= '0' && palabra[i] <= '9') || 
			(palabra[i] >= 'A' && palabra[i] <= 'F') || 
			(palabra[i] >= 'a' && palabra[i] <= 'f')))
				return 0;
			i++;
		}
	}

	return estado;
}
// 0: No reconocido, 1: Octal, 2: Decimal, 3: Hexadecimal
int automataImprovisado(char palabra[]){
	int estado = 0;

	if(palabra[0] == '0'){
		if(palabra[1] == 'x' || palabra[1] == 'X'){
			estado = esHexadecimal(palabra);
		} else {
			estado = esOctal(palabra);
		}
	} else{
		if(palabra[0] >= '1' || palabra[0] <= '9')
			estado = esDecimal(palabra);
	}

	return estado;
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