
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OPERADOR_ASIGNACION = 258,
     OPERADOR_O_LOGICO = 259,
     OPERADOR_Y_LOGICO = 260,
     OPERADOR_O_BINARIO = 261,
     OPERADOR_XOR_BINARIO = 262,
     OPERADOR_Y_BINARIO = 263,
     OPERADOR_IGUALDAD = 264,
     OPERADOR_RELACIONAL = 265,
     OPERADOR_CORRIMIENTO = 266,
     OPERADOR_ADITIVO = 267,
     OPERADOR_MULTIPLICATIVO = 268,
     OPERADOR_INCREMENTO = 269,
     OPERADOR_UNARIO = 270,
     OPERADOR_SIZEOF = 271,
     OPERADOR_PUNTERO_A_MIEMBRO = 272,
     OPERADOR_ELIPSIS = 273,
     IDENTIFICADOR = 274,
     TIPO_DE_DATO = 275,
     CONSTANTE_CADENA = 276,
     CONSTANTE_DECIMAL = 277,
     CONSTANTE_OCTAL = 278,
     CONSTANTE_HEXADECIMAL = 279,
     CONSTANTE_REAL = 280,
     CONSTANTE_CARACTER = 281,
     ESPECIFICADOR_CLASE_ALMACENAMIENTO = 282,
     CALIFICADOR_TIPO = 283,
     STRUCT_O_UNION = 284,
     ENUM = 285,
     IF = 286,
     ELSE = 287,
     SWITCH = 288,
     WHILE = 289,
     DO = 290,
     FOR = 291,
     CASE = 292,
     DEFAULT = 293,
     CONTINUE = 294,
     BREAK = 295,
     RETURN = 296,
     GOTO = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 20 "../src/integrador.y"

    char cadena[100];
    int entero;
    float real;



/* Line 1676 of yacc.c  */
#line 102 "integrador.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


