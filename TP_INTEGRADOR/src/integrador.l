%{
    #include "integrador.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
%}

%option yylineno
%option noyywrap

OPERADOR_ASIGNACION ("*="|"/="|"%="|"+="|"*="|"<<="|">>="|"&="|"^="|"|=") 
OPERADOR_O_LOGICO "||"
OPERADOR_Y_LOGICO "&&"
OPERADOR_O_INCLUSIVO "|"
OPERADOR_O_EXCLUSIVO "^"
OPERADOR_IGUALDAD ("=="|"!=")
OPERADOR_RELACIONAL ("<"|">"|"<="|">=")
OPERADOR_CORRIMIENTO ("<<"|">>") 
OPERADOR_MULTIPLICATIVO ("/"|"%")
OPERADOR_INCREMENTO ("++"|"--")
OPERADOR_SIZEOF "sizeof"
OPERADOR_SELECCION_MIEMBRO ("."|"->")

TIPO_DATO ("void"|"char"|"short"|"int"|"long"|"float"|"double"|"signed"|"unsigned")

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

%%

"\n" { return '\n'; }
" "|"\t"
 
","|"?"|":"|"("|")"|"["|"]"|"="|"{"|"}"|";"|"*"|"&"|"+"|"-"|"~"|"!" { return yytext[0]; }

"if"        { return IF;        }
"else"      { return ELSE;      }
"switch"    { return SWITCH;    }
"while"     { return WHILE;     }
"do"        { return DO;        }
"for"       { return FOR;       }
"case"      { return CASE;      }
"default"   { return DEFAULT;   }
"continue"  { return CONTINUE;  }
"break"     { return BREAK;     }
"return"    { return RETURN;    }
"goto"      { return GOTO;      }

{TIPO_DATO}                     { yylval.cadena = strdup(yytext); return TIPO_DATO; }
                        
{OPERADOR_ASIGNACION}           { return OPERADOR_ASIGNACION;           }       
{OPERADOR_O_LOGICO}             { return OPERADOR_O_LOGICO;             }         
{OPERADOR_Y_LOGICO}             { return OPERADOR_Y_LOGICO;             }         
{OPERADOR_O_INCLUSIVO}          { return OPERADOR_O_INCLUSIVO;          }      
{OPERADOR_O_EXCLUSIVO}          { return OPERADOR_O_EXCLUSIVO;          }                    
{OPERADOR_IGUALDAD}             { return OPERADOR_IGUALDAD;             }         
{OPERADOR_RELACIONAL}           { return OPERADOR_RELACIONAL;           }       
{OPERADOR_CORRIMIENTO}          { return OPERADOR_CORRIMIENTO;          }              
{OPERADOR_MULTIPLICATIVO}       { return OPERADOR_MULTIPLICATIVO;       }   
{OPERADOR_INCREMENTO}           { return OPERADOR_INCREMENTO;           }                  
{OPERADOR_SIZEOF}               { return OPERADOR_SIZEOF;               }           
{OPERADOR_SELECCION_MIEMBRO}    { return OPERADOR_SELECCION_MIEMBRO;    }

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.cadena = strdup(yytext); return IDENTIFICADOR;  }

\"(([^\"]|\\\")*[^\\])?\"                                                                                   { yylval.cadena = strdup(yytext); return CONSTANTE_CADENA;      }
{DIGITO_DECIMAL_SIN_CERO}{DIGITO_DECIMAL}*{SUFIJO_ENTERO}?                                                  { yylval.entero = atoi(yytext); return CONSTANTE_DECIMAL;       }
0{DIGITO_OCTAL}*{SUFIJO_ENTERO}?                                                                            { yylval.entero = atoi(yytext); return CONSTANTE_OCTAL;         }
0[xX]{DIGITO_HEXADECIMAL}+{SUFIJO_ENTERO}?                                                                  { yylval.entero = atoi(yytext); return CONSTANTE_HEXADECIMAL;   }
\'([^\\\']|\\{SECUENCIA_ESCAPE_SIMPLE}|\\{DIGITO_OCTAL}{1,3}|\\x{DIGITO_HEXADECIMAL}{1,2})\'                { yylval.entero = atoi(yytext); return CONSTANTE_CARACTER;      }
({CONSTANTE_FRACCION}{PARTE_EXPONENTE}?{SUFIJO_REAL}?|{CONSTANTE_FRACCION}{PARTE_EXPONENTE}{SUFIJO_REAL}?)  { yylval.real = strtol(yytext, NULL, 0); return CONSTANTE_REAL; }

. {printf("\nEl caracter %c no fue reconocido.", yytext[0]);}

%%