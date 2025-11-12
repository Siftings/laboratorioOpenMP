/**************************************************
*       Pontificia Universidad Javeriana          *
*               ----------=----------             *
*                                                 *
* Autor: Juan David Daza Caro                     *
* Fecha: 10 noviembre de 2025                     *
* Docente: J. Corredor							  *
* Materia: Sistemas Operativos                    *				  *
* Objetivo: Uso de la directiva y funcion 	      *
* para hacer uso de OpenMP                        *
***************************************************/


#include <stdio.h> // Incluir API OpenMP
#include <stdlib.h>
#include <omp.h>

//Programa principal
int main(int argc, char *argv[]){

int maxThreads= omp_get_max_threads(); // Metodo que retorna el numero maximo de hilos del sistema
printf("Número maximo de hilos del OS: %d \n", maxThreads);

// Directiva para crear una region paralela
#pragma omp parallel
{ // Este bloque se ejecuta en todos los hilos 
	printf("Numero del hilo desde la region paralela: %d \n", omp_get_thread_num());
}
return 0;
}