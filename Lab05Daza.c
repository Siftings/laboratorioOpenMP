/**************************************************
*       Pontificia Universidad Javeriana          *
*               ----------=----------             *
*                                                 *
* Autor: Juan David Daza Caro                     *
* Fecha: 10 noviembre de 2025                     *
* Docente: J. Corredor							  *
* Materia: Sistemas Operativos                    *				  
* Objetivo: Se utiliza open MP para paralelizar un
* proceso de computacion y optimizar el rendimiento. 
* Guardando el resultado en una variable compartida	
***************************************************/




#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>


// Se define el macro MIN para obtener el minimo entre dos valores
#define MIN(x,y) (((x) < (y)) ? (x):(y))

// Calcula la suma de los senos de un rango de valores
double fsum(int i){
	int inicio = i*(i+1)/2; // El incio es la sumatoria de todos los enteros de 1 hasta i 
	int fin = inicio + i; 
	double valorSum = 0;
	for (int j = inicio; j < fin; j++){
		valorSum += sin(j);
	}
	return valorSum;
}

// Programa principal
int main(int argc, char *argv[]){
	
	double resSumatoria = 0;
	int rep = 30000;
	// Validacion de argumentos
	if (argc != 2) {
		printf("Error: \n\t$. /ejecutable numHilos\n");
		exit(0);
	}
	int numHilos = (int) atoi(argv[1]); // Casteo del numero de hilos deseado

	int maxThreads = omp_get_max_threads();// Se obtiene el numero maximo de hilos del sistema
	printf("Numero maximo de hilos del OS: %d \n", maxThreads);

	 // Se le especifica explicitamente a la API OpenMP el numero de hilos a usar
	omp_set_num_threads(numHilos);
	printf("Numero de hilos fijados: %d \n", numHilos);

	// Region paralela con reduccion
	// Establece que cada hilo tenga una copia privada de 'resSumatoria' y las combine al final
	#pragma omp parallel for reduction(+: resSumatoria)
	for(int i=0; i<rep; i++){
		resSumatoria +=fsum(i);
	}
	
	printf("Resultado Sumatoria Funcion SENO: %0.2f \n", resSumatoria);
	return 0;
}

