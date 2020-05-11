#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tabla {
    int estado; 
    char cadenaPush[5];
};

void main(){
    struct tabla tablaDeMovimiento[6][5] = {
        {{-1, "-"}, { 1, "$"}, {-1, "-"}, { 2, "R$"}, {-1, "-" }},
        {{ 1, "$"}, { 1, "$"}, { 0, "$"}, {-1,  "-"}, {-1, "-" }},
        {{-1, "-"}, { 3, "R"}, {-1, "-"}, { 2, "RR"}, {-1, "-" }},
        {{ 4, "R"}, { 4, "R"}, { 3, "R"}, {-1,  "-"}, { 5, '\0'}},
        {{-1, "-"}, {-1, "-"}, { 3, "R"}, {-1,  "-"}, { 5, '\0'}},
        {{-1, "-"}, {-1, "-"}, { 0, "$"}, {-1,  "-"}, {-1, "-" }} 
    };

    struct tabla estadoSiguiente;
    
    estadoSiguiente.cadenaPush[0] = 'a';
    estadoSiguiente.cadenaPush[1] = 'e';
    estadoSiguiente.cadenaPush[2] = 'i';
    printf("\n%d\n", sizeof(estadoSiguiente.cadenaPush));
}