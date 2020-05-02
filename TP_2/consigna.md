# UTN - FRBA


## Sintaxis y Semántica de los Lenguaje
### Trabajo Práctico n° 2 - Autómata finito de pila para expresiones aritméticas

**Implementar en C** un programa que permita reconocer ​**expresiones aritméticas de suma, resta, producto y cociente** ​. El mismo deberá tomar una expresión (cadena de caracteres) **ingresada por el usuario** ​desde la entrada estándar (STDIN) y deberá indicar **por pantalla** (STDOUT) si la expresión es sintácticamente correcta o no. Dicho proceso se deberá poder repetir para cada cadena que vaya ingresando el usuario, siempre de a una cadena por vez.

El programa debe contemplar la ​**implementación de un autómata finito de pila​**, pueden utilizar como referencia el AFP visto en clase con la siguiente tabla de transiciones (también conocida como tabla de movimientos).

|    **TT**    |    0    |  [1-9]  | {+, -, *, /} |    (     |         )        |  
|    :---:     |  :---:  |  :---:  |     :---:    |   :---:  |       :---:      |
| **(q0, $)**  | -       | (q1, $) | -            | (q0, R$) | -                |
| **(q1, $)+** | (q1, $) | (q1, $) | (q0, R)      | -        | -                |
| **(q0, R)**  | -       | (q1, R) | -            | (q0, RR) | -                |
| **(q0, R)**  | (q1, R) | (q1, R) | (q0, R)      | -        | (q2, $\epsilon$) |
| **(q2, R)**  | -       | -       | (q0, R)      | -        | (q2, $\epsilon$) |
| **(q2, $)+** | -       | -       | (q0, R)      | -        | -                |
  

Epsilon hace referencia a que no realizan ningún push sobre la pila. Recuerden que siempre se realiza el pop del símbolo de la cima de la pila. El push si es opcional.

El alfabeto de cual podrán estar compuestas las expresiones (cadena de caracteres) son:
$\sum$ = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, +, -, *, /, ( , ) }

El alfabeto de la pila será: $\sum$ **’** = {R} ,
El símbolo de pila vacía será: p0 = $

Ejemplos de expresiones:

(1 + 2 * (3 - (8 / 2)) - 1 ) + ((12))
1+25-35

Los espacios entre números y operadores no son obligatorios. El programa deberá omitirlos en caso de que los hubiese.

La entrega de este trabajo práctico no es obligatoria, su ​**fecha límite para consulta, entrega y revisión es el día miércoles 3 de junio**​. Luego de esa fecha, no se aceptarán más trabajos, y toda consulta referida quedará para la defensa final que será en el mes de noviembre.

El ​**entorno de programación queda a criterio de cada grupo de trabajo** (Eclipse, Dev, Codeblocks, Visual Studio Code). Se recomienda un IDE que esté integrado con Git para poder realizar el trabajo en equipo de una forma más práctica.

Formará parte de la entrega el **​archivo fuente (.c)** y ​**el archivo ejecutable (.exe)​**. Todo debe estar en el repositorio GitHub.

La **​entrega será a través del repositorio** ​de GitHub en la carpeta correspondiente a cada TP generando un issue que notifique para la corrección @santiagoferreiros

Las **​consultas​** podrán ser respondidas a través de los foros. Es importante que los utilices para compartir sus dudas con el resto de los compañeros

Muchos éxitos =)

***Desafío opcional***:​ En caso de que la cadena no sea sintácticamente correcta, indicar al usuario donde se encontró el error

