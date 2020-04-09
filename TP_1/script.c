#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Longitud 100

struct tablaDeSalida{ //Tabla para procesamiento de los estados junto a su estado
	char valor[10];
	int estado; //0: No recocido 1: Octal 2: Decimal 3: Hexadecimal
} registroDeSalida;

void procesarArchivo(FILE *, char[Longitud/10][Longitud/10]); //Funcion lee el archivo y lo guarda en una matriz
//int detectarTipoEntero(); //Detecta el tipo de entero y devuelve un estado
//void procesarTipoEntero(); //Procesa la matriz en un struct para el archivo de salida
//void archivoDeSalida(); //Arma el archivo de salida con los valores y sus respectivos estados

void main(){
    FILE *archivo = fopen("valoresDePrueba.txt", "r");					
	char matrizNum[Longitud/10][Longitud/10] = {{""}};

	procesarArchivo(archivo, matrizNum[Longitud/10][Longitud/10]);

	return ;
}
void procesarArchivo(FILE *archivo, char matrizNum [Longitud/10][Longitud/10]){ //Procesa el archivo en una matriz 
	char arrNumArchivo[Longitud] = "";											//de [cantidad de palabras][10 caracteres de longitud]
	int col = -1, fila = 0, colArr;											

	fseek(archivo, 0, SEEK_END);							
    int longArchivo = ftell(archivo);						
	fseek(archivo, 0, SEEK_SET);							

	for(int i = 0; i < longArchivo; i++){ //Guarda todo el archivo en un arreglo
   		fscanf(archivo, "%c", &arrNumArchivo[i]);				
		printf("%c", arrNumArchivo[i]);
	}

	for (colArr = 0; colArr < Longitud; colArr++){ //Pasa el arreglo a una matriz (mas facil para comparar)
		col++;
		if(arrNumArchivo[colArr] != ','){ //Usa la coma para determinar una nueva fila
			matrizNum[fila][col] = arrNumArchivo[colArr];
			printf("%c", matrizNum[fila][col]);
		} else {
			col = -1;
			fila++;
			printf("\n");
		}	
	}

    fclose(archivo);										
}    

