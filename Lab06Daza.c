/**************************************************
*       Pontificia Universidad Javeriana          *
*               ----------=----------             *
*                                                 *
* Autor: Juan David Daza Caro                     *
* Fecha: 10 noviembre de 2025                     *
* Docente: J. Corredor							  *
* Materia: Sistemas Operativos                    *				  
* Objetivo: Adicion al lab 05, se toma como       *
* parametro el numero de repeticiones de la suma  *
* de SEN.                                         *
***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#define MIN(x,y) (((x) < (y)) ? (x):(y))

struct timeval inicio, fin; // Variables para medir el tiempo

// Funcion que guarda el tiempo de inicio la ejecucion 
void InicioMuestra(){
	gettimeofday(&inicio, (void *)0);
}

// Funcion que calcula el tiempo total de ejecucion 
void FinMuestra(){
	gettimeofday(&fin, (void*)0);
	fin.tv_usec -= inicio.tv_usec;
	fin.tv_sec -= inicio.tv_sec;
	double tiempo = (double) (fin.tv_sec*1000000 + fin.tv_usec);
	printf("%9.0f microSeg \n", tiempo);
}

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

	// Validacion de argumentos
	if (argc != 3) {
		printf("Error: \n\t$. /ejecutable numHilos numRepeticiones\n");
		exit(0);
	}

    int numHilos= (int) atoi(argv[1]); // Casteo del numero de hilos deseado
	int numRep=(int)atoi(argv[2]); // Casteo del numero de repeticiones 

    // Se obtiene el numero maximo de hilos del sistema
    int maxThreads = omp_get_max_threads();
    printf("Numero maximo de hilos del OS: %d \n", maxThreads);
	// Se le especifica explicitamente a la API OpenMP el numero de hilos a usar
    omp_set_num_threads(numHilos);
    #pragma omp  master
    printf("Numero de hilos fijados: %d \n", numHilos);
	
	//Inicia la medición del tiempo de ejecución
	InicioMuestra();
    
	// Region paralela con reduccion
	// Establece que cada hilo tenga una copia privada de 'resSumatoria' y las combine al final
	#pragma omp parallel for reduction(+: resSumatoria)
	for(int i=0; i<numRep; i++){
		resSumatoria +=fsum(i);
	}
	// Finaliza la medición del tiempo de ejecución
	FinMuestra(); 

    printf("Resultado Sumatoria Funcion SENO: %0.2f \n", resSumatoria);

    return 0;
}