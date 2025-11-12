/**************************************************
*       Pontificia Universidad Javeriana          *
*               ----------=----------             *
*                                                 *
* Autor: Juan David Daza Caro                     *
* Fecha: 10 noviembre de 2025                     *
* Docente: J. Corredor							  *
* Materia: Sistemas Operativos                    *				  
* Objetivo: Uso de la condicion private para      *
* crear variable unica para cada Hilo, sin copiar *
* del stack la del hilo padre.                    *
***************************************************/

#include <omp.h> 
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    const int N = 1000;
    int a = 50;
    int b = 0;

    // Cada hilo crea su propia copia de a y i, esto puede (y va a) afectar el funcionamiento del programa
    #pragma omp parallel for private(i) private(a)
    for (i = 0; i < N; i++){
        b = a + i; // Escritura concurrente en b
    }

    // La variable a no es modificada, pero b si, y su valor puede varias devido a una posible Race Condition
    // Se inprime el valor final de las variables junto a los valores que deberian en una situacion perfecta retornar.
    printf("a = %d b = %d (Se espera a=50 b = 1049)\n", a, b);
return 0;
}