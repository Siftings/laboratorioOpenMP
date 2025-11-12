/**************************************************
*       Pontificia Universidad Javeriana          *
*               ----------=----------             *
*                                                 *
* Autor: Juan David Daza Caro                     *
* Fecha: 10 noviembre de 2025                     *
* Docente: J. Corredor							  *
* Materia: Sistemas Operativos                    *				  
* Objetivo: Extra del lab 3, pone como            *
* privada la variable b                           *
**************************************************/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    int i;
    const int N = 1000;
    int a = 50;
    int b = 0;

    // Establece como variables privadas, i, a y b para cada hilo
    #pragma omp parallel for private(i) private(a) private(b)
    for (i = 0; i < N; i++){
        b = a + i; // Cada hilo calcula su propio b, sin afectar el b global
    }

    // Como cada hilo tiene su copia local de b, no se mofiica y permanece en 0
    printf("a = %d b = %d (Se espera a=50 b = 1049)\n", a, b);
	return 0;
}