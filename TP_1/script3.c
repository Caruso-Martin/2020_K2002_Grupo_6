#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100

int tellIntType(char [LENGTH/10][LENGTH/10], int);		//Pasamos matriz y palabra a leer
void readAndProcessFile(FILE *, char [LENGTH/10][LENGTH/10]);


void main(){
    FILE *file = fopen("testingValues.txt", "r");		//Abre el archivo
	char numMatrix[LENGTH/10][LENGTH/10] = {{""}};

	readAndProcessFile(file, numMatrix[LENGTH/10][LENGTH/10]);
	//createOutPutFile();

	return ;
}
void readAndProcessFile(FILE *file, char numMatrix [LENGTH/10][LENGTH/10]){
	char numArray[LENGTH] = "";
	int col = -1, row = 0, colArr;									

	fseek(file, 0, SEEK_END);							//Ubica el puntero al final del archivo 
    int fileSize = ftell(file);							//Guarda la cantidad de caracteres
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
int tellIntType(char numMatrix[LENGTH/10][LENGTH/10], int p){
	int i = 0;

char a = '7';
	if(numMatrix[p][0] == '0'){
		if(numMatrix[p][1] == 'x' || numMatrix[p][1] == 'X'){
			i=2;
			while(numMatrix[p][i] != '\0'){
				if(!((numMatrix[p][i] >= 48 && numMatrix[p][i] <= 57)  || //Entre 0 y 9
				   (numMatrix[p][i] >= 97 && numMatrix[p][i] <= 102)   || //Entre a y f
			 	   (numMatrix[p][i] >= 65 && numMatrix[p][i] <= 70))){	  //Entre A y F
					return 3;
				}
				i++;
			}
		
		} else {
			i = 1;
			while(numMatrix[p][i] != '\0'){
				if(!((numMatrix[p][i] >= 48 && numMatrix[p][i] <= 55))){	//Entre 0 y 7
					return 1;
				}
				i++;
			}
		}
			
	} else {
		while(numMatrix[p][i] != '\0'){
			if(!((numMatrix[p][i] >= 48 && numMatrix[p][i] <= 57))){	//Entre 0 y 9
				return 2;
			}
			i++;
		}
	}
	return 0;
}

