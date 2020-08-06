#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cadenaHola  "Hola"
#define numeroCinco 5 

struct estructura {
    char* cadena;
    int numero;
} lista;

int constantes();
char* literalesCadena();
void palabrasReservadas();
void operadoresYPuntuacion();

int main (){

    return 0;
}

int constantes(){

    //Octales
    int octal_cero      = 0;
    int octal_bueno     = 01234567;
    //int octal_malo    = 078;
    //int octal_malo_2  = 019; 

    //Decimales
    int decimal_bueno   = 123456789;
    int decimal_bueno_2 = 89u;
    int decimal_bueno_3 = -123;
    //int decimal_malo  = 123e;

    //Hexadecimal
    int hexa_bueno      = 0x123456789ABCDEF;
    int hexa_bueno_2    = 0xabcdef;
    //int hexa_malo     = 0x123w456789gABCF;

    //Reales
    float real_bueno_1  = 8.12;
    float real_bueno_2  = 000.333; 
    float real_bueno_3  = +1111.809;
    float real_bueno_4  = -3200; 
    float real_bueno_5  = .56;
    float real_bueno_6  = -77e-3;
    float real_bueno_7  = +1111e+2;
    float real_bueno_8  = 2000E+2;
    float real_bueno_9  = 3040e2;
    float real_bueno_10 = -50.50e-4;
    float real_bueno_11 = 400.e-3;
    float real_bueno_12 = +65.65E+2;
    float real_bueno_13 = .7e2;
    float real_bueno_14 = 0.004E+3;
    float real_bueno_15 = 4.;
    float real_bueno_16 = .4e1;
    float real_bueno_17 = +400.00e-2;
    float real_bueno_18 = 4000E-3;

    //float real_malo_1   = -200; 
    //float real_malo_2   = -20,0;
    //float real_malo_3   = --111-; 
    //float real_malo_4   = -111..; 
    //float real_malo_5   = -111.11.;
    //float real_malo_6   = +22e; 
    //float real_malo_7   = +22ee6; 
    //float real_malo_8   = +22e 6; 
    //float real_malo_9   = 38E-2.2; 

    //Caracter
    char caracter_bueno_1  = '\'';
    char caracter_bueno_2  = '\"';
    char caracter_bueno_3  = '\?';
    char caracter_bueno_4  = '\\';
    char caracter_bueno_5  = '\a';
    char caracter_bueno_6  = '\b';
    char caracter_bueno_7  = '\f';
    char caracter_bueno_8  = '\n';
    char caracter_bueno_9  = '\r';
    char caracter_bueno_10 = '\t';
    char caracter_bueno_11 = '\v';
    char caracter_bueno_12 = '\07';
    char caracter_bueno_13 = '\023';
    char caracter_bueno_14 = '\x1';
    char caracter_bueno_15 = '\xA';

    //char caracter_malo_1   = '\m';
    //char caracter_malo_2   = '\$';
    //char caracter_malo_3   = '\08';
    //char caracter_malo_4   = '\xfg';
     
    return octal_cero;
}

char* literalesCadena(){

}

/*
void palabrasReservadas(){
    autobreak
    case
    char
    const
    continue
    default
    do
    double
    else
    enum
    extern
    float
    for
    goto
    if
    int
    long
    register
    return
    short
    signed
    sizeof
    static
    struct
    typedef
    union
    unsigned
    void
    volatile 

    while
}
*/

void operadoresYPuntuacion(){
    
}