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
int automataFinitoDeterministico(char[]);
int obtenerValor(char);
void archivoSalida2(struct tablaDeSalida *);

int tablaDeTransicion[6][6] = 	{{1,5,5,0,0,0},
								 {4,4,0,2,0,0},
								 {3,3,3,0,3,0},
								 {3,3,3,0,3,0},
								 {4,4,0,0,0,0},
								 {5,5,5,0,0,0}};
	//Los 0 se usan para representar la accion nula en el automata

void main(){
	
	FILE * archivoDeEntrada = fopen("valoresDePrueba.txt", "r");					
 
	llenarRegistro(archivoDeEntrada, registroDeSalida);
	
	/*for (int i = 0; i < cantPalabras; i++){
		registroDeSalida[i].estado = automataImprovisado(registroDeSalida[i].valor);
	}*/
	for (int i = 0; i< cantPalabras; i++){
		registroDeSalida[i].estado = automataFinitoDeterministico(registroDeSalida[i].valor);
	}
	//archivoSalida(registroDeSalida);
	archivoSalida2(registroDeSalida);	
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
// Lee los valores del vector palabra[] y determina usando tablaDeTransicion[] si realiza acciones validas
// Si es una palabra reconocida devolvera, 3:Hexadecimal, 4:Octal, 5:Decimal. Cualquier otro valor es no reconocida
int automataFinitoDeterministico(char palabra[]){
	int i=0;
	int fila=0;
	int columna;
	while(palabra[i]!='\0'){
		columna = obtenerValor(palabra[i]);
		fila = tablaDeTransicion[fila][columna];
		if(fila == 0){ /*Si el valor de columna es 0 entonces se entiende que es una accion no valida y devuelve ese valor*/
			return fila;
			}
		i++;
	}
	return fila;
}
//Lee un caracter del vector palabra[] y devuelve el valor numerico de a que fila pertenece, 
// 0: 0, 1:[1-7], 2:[8-9], 3:[xX], 4:[a-f][A-F], 5:No reconocido
int obtenerValor(char x){
	if(x > '0' && x < '8'){
		return 1;
		}
	if(x > '7' && x <= '9'){
		return 2;
		}
	if(x == 'x' || x == 'X'){
		return 3;
		}
	if((x >= 'A' && x <= 'F') || (x >= 'a' && x <= 'f')){
		return 4;
		}
	if(x == '0'){
		return 0;
		}
	return 5;
}
//Modificacion a archivoSalida para que use los estados devueltos por automataFinitoDeterministico
void archivoSalida2(struct tablaDeSalida * registroDeEstados){
	FILE * archivoDeSalida = fopen("estadosDeEnteros.txt", "w");					
	int i = 0;
	char srtEstado [14];
	
	fprintf(archivoDeSalida, "|  Valor  | Tipo de entero |\n| ------- | -------------- |\n");

	for (int i = 0; i < cantPalabras; i++){
		switch (registroDeEstados[i].estado){
			case 4:
				strcpy(srtEstado, "Octal");
				fprintf(archivoDeSalida, "| %7s | %14s |\n", registroDeEstados[i].valor, srtEstado);	
				break;
			case 5:
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