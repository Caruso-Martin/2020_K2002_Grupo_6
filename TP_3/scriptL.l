%option noyywrap

%{
#include <stdio.h>
%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 


CONSTANTE_FRACCION (({DIGITO_DECIMAL}*)?"."{DIGITO_DECIMAL}*|{DIGITO_DECIMAL}*)
PARTE_EXPONENTE (e|E)("+"|"-")?{DIGITO_DECIMAL}*
SUFIJO_REAL (f|F|l|L)

SECUENCIA_ESCAPE_SIMPLE (a|b|f|n|r|t|v|\'|\"|\?|\\)


CARACTERES_PUNTUACION (\[|\]|\(|\)|\{|\}|\,|\;|\:|\...|\*|\=|\#)


LETRA [a-zA-Z] 
PALABRAS_RESERVADAS (autobreak|case|const|continue|default|do|else|enum|extern|for|goto|if|register|return|sizeof|static|struct|typedef|union|volatile|while)
TIPOS_DE_DATOS (char|double|float|int|long|short|signed|unsigned|void)

%%

0{DIGITO_OCTAL}* {printf("Constante entera - Octal: %s \n", yytext);}
[1-9]{DIGITO_DECIMAL}* {printf("Constante entera - Decimal: %s \n", yytext);}
0[xX]{DIGITO_HEXADECIMAL}+ {printf("Constante entera - Hexadecimal: %s\n", yytext);}

({CONSTANTE_FRACCION}{PARTE_EXPONENTE}?{SUFIJO_REAL}?|{CONSTANTE_FRACCION}{PARTE_EXPONENTE}{SUFIJO_REAL}?) {printf("Constante real: %s\n", yytext);}

\'([^\\\']|\\{SECUENCIA_ESCAPE_SIMPLE}|\\{DIGITO_OCTAL}{1,3}|\\x{DIGITO_HEXADECIMAL}{1,2})\' {printf("Constante caracter: %s\n", yytext);}

\".*\" {printf("Literal cadena: %s ; Longitud = %i \n", yytext, yyleng - 2);}
{PALABRAS_RESERVADAS} {printf("Palabra reservada: %s \n", yytext);}
({LETRA}|"_")({LETRA}|{DIGITO_DECIMAL}|"_")* {printf("Identificador: %s \n", yytext);}

"//".* {printf("Comentario simple: %s \n", yytext);}
"/*".*"*/" {printf("Comentario multiple: %s \n", yytext);}

%%
