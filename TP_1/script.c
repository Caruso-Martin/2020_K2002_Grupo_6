#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100

void readAndProcessFile(FILE *, char [LENGTH/10][LENGTH/10]); 				//Funcion lee el archivo y lo guarda en una matriz


void main(){
    FILE *file = fopen("testingValues.txt", "r");					//Abre el archivo
	char numMatrix[LENGTH/10][LENGTH/10] = {{""}};

	readAndProcessFile(file, numMatrix[LENGTH/10][LENGTH/10]);

	return ;
}
void readAndProcessFile(FILE *file, char numMatrix [LENGTH/10][LENGTH/10]){
	char numArray[LENGTH] = "";
	int col = -1, row = 0, colArr;									

	fseek(file, 0, SEEK_END);							//Ubica el puntero al final del archivo 
    int fileSize = ftell(file);								//Guarda la cantidad de caracteres
	fseek(file, 0, SEEK_SET);							//Devuelve el puntero al principio del archivos

	for(int i = 0; i < fileSize; i++){
   		fscanf(file, "%c", &numArray[i]);				
		printf("%c", numArray[i]);
	}

	for (colArr = 0; colArr < LENGTH; colArr++){
		col++;
		if(numArray[colArr] != ','){
			numMatrix[row][col] = numArray[colArr];
			printf("%c", numMatrix[row][col]);
		} else {
			col = -1;
			row++;
			printf("\n");
		}	
	}

    fclose(file);										//Cerra el archivo
}    

