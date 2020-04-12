#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define longitudMaxInt 6 // El mayor int es +32,767
#define cantPalabras 13

#define inicio 0
#define q1 1
#define q2 2
#define q3 3
#define q4 4
#define q5 5
#define error 6

struct tablaDeSalida{ 
	int estado; 
	char valor[longitudMaxInt];

} registroDeSalida[cantPalabras];

void llenarRegistro(FILE *, struct tablaDeSalida *); 
void trifurcacionDeEstados(char [], char, char, char, int, int, int, int);
int automataEstado(char[]);
void archivoSalida(struct tablaDeSalida *);

void main(){
	FILE * archivoDeEntrada = fopen("valoresDePrueba.txt", "r");					
 
	llenarRegistro(archivoDeEntrada, registroDeSalida);
	registroDeSalida[0].estado = 3;
	registroDeSalida[1].estado = 2;
	registroDeSalida[2].estado = 1;
	for (int i = 3; i < cantPalabras; i++){
		registroDeSalida[i].estado = 0; /*automataEstado(registroDeSalida[i].valor);
		printf("El valor: %s es %c adios\n", registroDeSalida[i].valor, registroDeSalida[i].estado);*/
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
// Pasada una palabra, devuelve un estado
// 0: No reconocido, 1: Octal, 2: Decimal, 3: Hexadecimal
/*int automataEstado(char palabra[]){
	int estado;
	int matrizTTransicion[7][6] = { 
		{2, 1, 1, 6, 6, 6},// Trifurcacion: oct/hex, dec y n/r
		{1, 1, 1, 6, 6, 6},// Verificacion decimal 
		{5, 5, 6, 3, 6, 6},// Trifurcacion: oct, hex y n/r
		{4, 4, 4, 6, 4, 4},// Verificacion hexadecimal (primer caracter obligatorio)
		{4, 4, 4, 6, 4, 4},// Verificacion hexadecimal
		{5, 5, 6, 6, 6, 6},// Verificacion octal
		{6, 6, 6, 6, 6, 6} // ***Duda: ¿es realmente necesaria esta fila?
	};
	// Testing de funcionamiento correcto de la entrada del valor
	// Devuelve palabra 
	//printf("%s\n", palabra);
	// Devuelve caracter de palabra      
	//printf("%c\n", palabra[3]); 
	 
	//void esValido(i);
	//void esValidoHex(); //usar for() en q4 //Se podria repetir esValido 3 veces adentro de la funcion como un reemplazo de los limitesSuperiores e inferiores

	int i = 1;
	switch(estado){
		case inicio:
				trifurcacionDeEstados(palabra, '1', '9', '0', 0, estado, q1, q2);
			break;
		case q1:
			while(palabra[i] >= '1' && palabra[i] <= '9'){
				if(palabra[i] >= '1' && palabra[i] <= '9'){
					i++;
					if(palabra[i] == '\0')
						return 2;// Es decimal
				} else {
					estado = error;// Es no reconocido
				}
			}
			break;
		case q2:
			trifurcacionDeEstados(palabra, '0', '7', 'X', 1, estado, q5, q3);
			break;
		case q3:
			i++;
			if((palabra[i] >= '0' && palabra[i] <= '9') || (palabra[i] >= 'a' && palabra[i] <= 'f') || (palabra[i] >= 'A' && palabra[i] <= 'F')){
				i++;
				if(palabra[i] == '\0')
					return 2;// Es hexadecimal
				estado = q4;// Es hexadecimal o no reconocido
			} else {
				estado = error;// Es no reconocido
			}
			break;
		case q4:
			while((palabra[i] >= '0' && palabra[i] <= '9') || (palabra[i] >= 'a' && palabra[i] <= 'f') || (palabra[i] >= 'A' && palabra[i] <= 'F')){
				if((palabra[i] >= '0' && palabra[i] <= '9') || (palabra[i] >= 'a' && palabra[i] <= 'f') || (palabra[i] >= 'A' && palabra[i] <= 'F')){
					i++;
					if(palabra[i] == '\0')
						return 2;// Es hexadecimal
				} else {
					estado = error;// Es no reconocido
				}
			}
			break;
		case q5:
			i++;
			while(palabra[i] >= '0' && palabra[i] <= '7'){
				if(palabra[i] >= '0' && palabra[i] <= '7'){
					i++;
					if(palabra[i] == '\0')
						return 1;// Es octal
				} else {
					estado = error;// Es no reconocido
				}
			};
		case error:
			return 0;//Es no reconocido
			break;
	}

} */
/*void trifurcacionDeEstados(char palabra[], char limiteInf, char limiteSup, char delimitadorSegundoEstado, int posicion, int estado, int primerEstado, int segundoEstado){
	if(palabra[posicion] >= limiteInf && palabra[posicion] <= limiteSup){
			estado = primerEstado;

	} else {
		if(palabra[posicion] == delimitadorSegundoEstado || palabra[posicion] == tolower(delimitadorSegundoEstado)){
			estado = segundoEstado; 
		} else {
			estado = error;// Es no reconocido 
		}
	}
}*/
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
				fprintf(archivoDeSalida, "| %7s | %14s |\n", registroDeEstados[i].valor, srtEstado);	
				break;
		}
	}
}