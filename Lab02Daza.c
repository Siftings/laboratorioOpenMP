/**************************************************
*       Pontificia Universidad Javeriana          *
*               ----------=----------             *
*                                                 *
* Autor: Juan David Daza Caro                     *
* Fecha: 10 noviembre de 2025                     *
* Docente: J. Corredor							  *
* Materia: Sistemas Operativos                    *				  
* Objetivo: Uso de la directiva y funcion 	      *
* para hacer uso de OpenMP                        *
***************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char *argv[]){
if (argc!=2){ // Validacion de argumentos
	printf("Error: \n\t$. /ejecutable numHilos\n");
	exit(0);
}
	int numHilos = (int) atoi(argv[1]); // Numero de hilos deseado pasado por argumento 

	// Se obtiene el numero maximo de hilos del sistema
	int maxThreads = omp_get_max_threads();
	printf("Numero maximo de hilos del OS: %d \n", maxThreads);

    // Se le especifica explicitamente a la API OpenMP el numero de hilos a usar
	omp_set_num_threads(numHilos);
	printf("Numero de hilos fijados: %d \n", numHilos);

// Diretiva para crear una region paralela
#pragma omp parallel
{
	printf("Numero del hilo desde la region paralela: %d \n", omp_get_thread_num());
}
return 0;
}