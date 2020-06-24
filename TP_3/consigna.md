# UTN - FRBA


## Sintaxis y Semántica de los Lenguajes - 2020
### Trabajo Práctico n° 3 - FLEX para reconocimiento de categorías léxicas de C

**Implementar en C** un programa que permita reconocer en un archivo.c de entrada **todas las categorías léxicas de C y comentarios.** El mismo deberá  dar como salida en pantalla un reporte. Para desarrollar dicho programa deberá utilizar LEX/FLEX para la generación del código C que implemente el analizador léxico
 
### Categorías léxicas a reconocer:

- Constantes (Entera decimal, entera octal, entera hexadecimal, real, caracter)
- Literal cadena
- Palabras reservadas (distinguir entre tipo de dato, estructuras de control y otros)
- Identificadores 
- Caracteres de puntuación y operadores de C.

### Comentarios

- Comentarios de una línea
- Comentarios de múltiples líneas

Las directivas de precompilación que comienzan con # no estarán incluídas.


El archivo de reporte deberá contener lo siguiente

### Reporte

1. Listado de identificadores encontrados indicando la cantidad de veces que aparece cada uno de ellos. El listado debe estar ordenado alfabéticamente 

2. Listado de literales cadena encontrados indicando la longitud de los mismos.

3. Listado de palabras reservadas en el orden en el que han aparecido.

4. Listado de constantes indicando según su tipo:

- Para las constantes octales indicar su valor entero decimal.
- Para las constante hexadecimales indicar su valor entero decimal.
- Para las constantes decimales indicar el valor de cada una y el total acumulado de sumar todas ellas.
- Para las constantes reales indicar el valor de su mantisa y parte entera. 

5. Listado de operadores/caracteres de puntuación indicando cantidad de veces que aparecen.

6. Listado de comentarios encontrados distinguiendo si se trata de comentarios de una línea o múltiples líneas..

7. Listado de cadenas y/o caracteres no reconocidos indicando el numero de linea.


La entrega de este trabajo práctico no es obligatoria, su fe**cha límite para consulta, entrega y revisión es el día Domingo 9 de Agosto.** Luego de esa fecha, no se aceptarán más trabajos, y toda consulta referida quedará para la defensa final que será en el mes de noviembre.

**El entorno de programación queda a criterio de cada grupo de trabajo** (Eclipse, Dev, Codeblocks, Visual Studio Code). Se recomienda un IDE que esté integrado con Git para poder realizar el trabajo en equipo de una forma más práctica.

**La entrega será a través del repositorio** de GitHub en la carpeta correspondiente a cada TP generando un issue que notifique para la corrección @santiagoferreiros

**Las consultas** podrán ser respondidas a través de los foros. Es importante que los utilices para compartir sus dudas con el resto de los compañeros

Muchos éxitos =)

`Desafío opcional: Adicionar al analizador léxico el reconocimiento de las directivas del precompilador #Include #Define.`


### Utiles

https://drive.google.com/file/d/1BLwHRqoTSqrxAViiIZ1qN8AcLfxFXz95/view

cd TP_3

flex scriptL.l

gcc lex.yy.c -L "C:\Program Files (x86)\GnuWin32\lib" -lfl

a.exe