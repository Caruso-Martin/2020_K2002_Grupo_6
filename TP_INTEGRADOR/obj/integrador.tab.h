
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
     IDENTIFICADOR = 258,
     OPERADOR_ASIGNACION = 259,
     OPERADOR_O_LOGICO = 260,
     OPERADOR_Y_LOGICO = 261,
     OPERADOR_O_INCLUSIVO = 262,
     OPERADOR_O_EXCLUSIVO = 263,
     OPERADOR_IGUALDAD = 264,
     OPERADOR_RELACIONAL = 265,
     OPERADOR_CORRIMIENTO = 266,
     OPERADOR_MULTIPLICATIVO = 267,
     OPERADOR_INCREMENTO = 268,
     OPERADOR_SIZEOF = 269,
     OPERADOR_SELECCION_MIEMBRO = 270,
     CONSTANTE_CADENA = 271,
     CONSTANTE_DECIMAL = 272,
     CONSTANTE_OCTAL = 273,
     CONSTANTE_HEXADECIMAL = 274,
     CONSTANTE_REAL = 275,
     CONSTANTE_CARACTER = 276,
     TIPO_DATO = 277,
     IF = 278,
     ELSE = 279,
     SWITCH = 280,
     WHILE = 281,
     DO = 282,
     FOR = 283,
     CASE = 284,
     DEFAULT = 285,
     CONTINUE = 286,
     BREAK = 287,
     RETURN = 288,
     GOTO = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 17 "../src/integrador.y"

    char cadena[100];
    int entero;
    float real;



/* Line 1676 of yacc.c  */
#line 94 "integrador.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


