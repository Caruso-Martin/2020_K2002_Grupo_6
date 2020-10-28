%{
    #include "integrador.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
%}

ESPACIO_VACIO (" "|"\t")

LETRA [a-zA-Z]
DIGITO_DECIMAL [0-9]
DIGITO_DECIMAL_SIN_CERO [1-9]
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 

SUFIJO_LONG (l|L)
SUFIJO_ENTERO ({SUFIJO_LONG}|u|U)

SUFIJO_REAL ({SUFIJO_LONG}|f|F)
CONSTANTE_FRACCION (({DIGITO_DECIMAL}*)?"."{DIGITO_DECIMAL}*|{DIGITO_DECIMAL}*)
PARTE_EXPONENTE (e|E)("+"|"-")?{DIGITO_DECIMAL}*

SECUENCIA_ESCAPE_SIMPLE (a|b|f|n|r|t|v|\'|\"|\?|\\)

OPERADOR_ASIGNACION (\=|\*\=|\/\=|\%\=|\+\=|\-\=|\<\<\=|\>\>\=|\&\=|\^\=|\|\=)      
OPERADOR_O_LOGICO (\|\|)         
OPERADOR_Y_LOGICO (\&\&)       
OPERADOR_O_BINARIO (\|)       
OPERADOR_XOR_BINARIO (\^)    
OPERADOR_Y_BINARIO (\&)    
OPERADOR_IGUALDAD (\=\=|\!\=)         
OPERADOR_RELACIONAL (\>|\<|\>\=|\<\=)       
OPERADOR_CORRIMIENTO (\>\>|\<\<)     
OPERADOR_ADITIVO (\+|\-)         
OPERADOR_MULTIPLICATIVO (\*|\/|\%)  
OPERADOR_INCREMENTO \+\+|\-\-      
OPERADOR_UNARIO (\&|\*|\+|\-|\~|\!)           
OPERADOR_SIZEOF "sizeof"         
OPERADOR_PUNTERO_A_MIEMBRO (\-\>|\.)
OPERADOR_ELIPSIS (\.\.\.)

TIPO_DE_DATO ("void"|"char"|"short"|"int"|"long"|"float"|"double"|"signed"|"unsigned")
ESPECIFICADOR_CLASE_ALMACENAMIENTO ("typedef"|"static"|"auto"|"register"|"extern")
CALIFICADOR_TIPO ("const"|"volatile")                 
STRUCT_O_UNION ("struct"|"union")                  
ENUM ("enum")
IF ("if") 
ELSE ("else")
SWITCH ("switch")
WHILE ("while")
DO ("do")
FOR ("for")
CASE ("case")
DEFAULT ("default")
CONTINUE ("continue")
BREAK ("break")
RETURN ("return")
GOTO ("goto")                              
IDENTIFICADOR [a-zA-Z_][a-zA-Z0-9_]*    

CONSTANTE_CADENA \"(([^\"]|\\\")*[^\\])?\"          
CONSTANTE_DECIMAL {DIGITO_DECIMAL_SIN_CERO}{DIGITO_DECIMAL}*{SUFIJO_ENTERO}?         
CONSTANTE_OCTAL 0{DIGITO_OCTAL}*{SUFIJO_ENTERO}?           
CONSTANTE_HEXADECIMAL 0[xX]{DIGITO_HEXADECIMAL}+{SUFIJO_ENTERO}?    
CONSTANTE_REAL ({CONSTANTE_FRACCION}{PARTE_EXPONENTE}?{SUFIJO_REAL}?|{CONSTANTE_FRACCION}{PARTE_EXPONENTE}{SUFIJO_REAL}?)           
CONSTANTE_CARACTER \'([^\\\']|\\{SECUENCIA_ESCAPE_SIMPLE}|\\{DIGITO_OCTAL}{1,3}|\\x{DIGITO_HEXADECIMAL}{1,2})\'        

CARACTERES_DE_PUNTUACION (\(|\)|\[|\]|\,|\?|\:|\;|\{|\}|\=|\*)

%%
"\n" {return '\n';}
" "|"\t"                         {;};

{OPERADOR_ASIGNACION}                   { return OPERADOR_ASIGNACION; };

{OPERADOR_O_LOGICO}                     { return OPERADOR_O_LOGICO;             };
{OPERADOR_Y_LOGICO}                     { return OPERADOR_Y_LOGICO;             };
{OPERADOR_O_BINARIO}                    { return OPERADOR_O_BINARIO;            };
{OPERADOR_XOR_BINARIO}                  { return OPERADOR_XOR_BINARIO;          };
{OPERADOR_Y_BINARIO}                    { return OPERADOR_Y_BINARIO;            };

{OPERADOR_IGUALDAD}                     { return OPERADOR_IGUALDAD;             };
{OPERADOR_RELACIONAL}                   { return OPERADOR_RELACIONAL;           };
{OPERADOR_CORRIMIENTO}                  { return OPERADOR_CORRIMIENTO;          };
{OPERADOR_ADITIVO}                      { return OPERADOR_ADITIVO;              };
{OPERADOR_MULTIPLICATIVO}               { return OPERADOR_MULTIPLICATIVO;       };
{OPERADOR_INCREMENTO}                   { return OPERADOR_INCREMENTO;           };
{OPERADOR_UNARIO}                       { return OPERADOR_UNARIO;               };

{OPERADOR_SIZEOF}                       { return OPERADOR_SIZEOF;               };
{OPERADOR_PUNTERO_A_MIEMBRO}            { return OPERADOR_PUNTERO_A_MIEMBRO;    };
{OPERADOR_ELIPSIS}                      { return OPERADOR_ELIPSIS;              };


{TIPO_DE_DATO}                          { strcpy(yylval.cadena, yytext);            return TIPO_DE_DATO;                        };
{ESPECIFICADOR_CLASE_ALMACENAMIENTO}    { strcpy(yylval.cadena, yytext);            return ESPECIFICADOR_CLASE_ALMACENAMIENTO;  };
{CALIFICADOR_TIPO}                      { strcpy(yylval.cadena, yytext);            return CALIFICADOR_TIPO;                    };
{STRUCT_O_UNION}                        { strcpy(yylval.cadena, yytext);            return STRUCT_O_UNION;                      };                
{ENUM}                                  { strcpy(yylval.cadena, yytext);            return ENUM;                                };
{IF}                                    { strcpy(yylval.cadena, yytext);            return IF;                                  };
{ELSE}                                  { strcpy(yylval.cadena, yytext);            return ELSE;                                }; 
{SWITCH}                                { strcpy(yylval.cadena, yytext);            return SWITCH;                              };
{WHILE}                                 { strcpy(yylval.cadena, yytext);            return WHILE;                               };
{DO}                                    { strcpy(yylval.cadena, yytext);            return DO;                                  };
{FOR}                                   { strcpy(yylval.cadena, yytext);            return FOR;                                 };
{CASE}                                  { strcpy(yylval.cadena, yytext);            return CASE;                                };
{DEFAULT}                               { strcpy(yylval.cadena, yytext);            return DEFAULT;                             };
{CONTINUE}                              { strcpy(yylval.cadena, yytext);            return CONTINUE;                            };
{BREAK}                                 { strcpy(yylval.cadena, yytext);            return BREAK;                               };
{RETURN}                                { strcpy(yylval.cadena, yytext);            return RETURN;                              };
{GOTO}                                  { strcpy(yylval.cadena, yytext);            return GOTO;                                };
{IDENTIFICADOR}                         { strcpy(yylval.cadena, yytext);            return IDENTIFICADOR;                       };

{CONSTANTE_CADENA}                      { strcpy(yylval.cadena, yytext);            return CONSTANTE_CADENA;        };
{CONSTANTE_DECIMAL}                     { yylval.entero = atoi(yytext);             return CONSTANTE_DECIMAL;       };
{CONSTANTE_OCTAL}                       { yylval.entero = atoi(yytext);             return CONSTANTE_OCTAL;         };
{CONSTANTE_HEXADECIMAL}                 { yylval.entero = atoi(yytext);             return CONSTANTE_HEXADECIMAL;   };
{CONSTANTE_REAL}                        { yylval.real = strtol(yytext, NULL, 0);    return CONSTANTE_REAL;          };
{CONSTANTE_CARACTER}                    { yylval.entero = yytext[1];                return CONSTANTE_CARACTER;      };

{CARACTERES_DE_PUNTUACION}              { return yytext[0]; };

.                                       {printf("\nNo reconocido: %c", yytext[0]);}
%%