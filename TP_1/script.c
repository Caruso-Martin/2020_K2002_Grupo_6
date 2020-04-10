#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define longitudMaxInt 6 //El mayor int es +32,767
#define cantPalabras 13

struct tablaDeSalida{ 
	int estado; 
	char valor[longitudMaxInt];

} registroDeSalida[cantPalabras];

void llenarRegistro(FILE *, struct tablaDeSalida *); 
int automataEstado(char[]);
void archivoSalida(struct tablaDeSalida *);

void main(){
	FILE * archivoDeEntrada = fopen("valoresDePrueba.txt", "r");					
 
	llenarRegistro(archivoDeEntrada, registroDeSalida);
	/*for (int i = 0; i < cantPalabras; i++){
		registroDeSalida[i].estado = automataEstado(registroDeSalida[i].valor);
	}*/
	//archivoSalida(registroDeSalida);
		
}
void llenarRegistro(FILE * archivoEntrada, struct tablaDeSalida * registroDeSalida){
	int j = 0, k = -1;
	fseek(archivoEntrada, 0, SEEK_END);							
    int longitudArchivo = ftell(archivoEntrada);						
	fseek(archivoEntrada, 0, SEEK_SET);

	for(int i = 0; i < longitudArchivo; i++){
		k++;
		fscanf(archivoEntrada, "%c", &registroDeSalida[j].valor[k]);

		if(registroDeSalida[j].valor[k] == ','){
			registroDeSalida[j].valor[k] = '\0'; //Borra la coma
			j++; //Nueva palabra
			k=-1; //Resetea la columna de llenado del array valor
		}  
	}
	printf("%s\n",registroDeSalida[12].valor);
	printf("%c\n",registroDeSalida[12].valor[3]);

	fclose(archivoEntrada);
} 
//int automataEstado(struct tablaDeSalida *){} //Se le pasa una fila y devuelve un estado
//void archivoSalida(struct tablaDeSalida *){}