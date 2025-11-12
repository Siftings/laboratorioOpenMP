
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#define MIN(x,y) ((x<y)? x:y)





// Se implementa la funcion de sumatoria 

double fsum(int i){
	int inicio = i*(i+1)/2;
	int fin = inicio + i;
	double valorSum = 0;
	for(int j = inicio; j< fin; j++){
		valorSum += sin(j);
	}
	return valorSum;
}
int main (int argc, char* argv[]){
	double resSumatoria =0; 
	int rep = 30000;
	if(argc != 2){
		printf("Error: \n\t$./ejecutable numHilos\n");
		exit(0);
	}
	int numHilos = atoi(argv[1]);

	int maxCores = omp_get_max_threads();
	printf("Numero maximo de hilos del OS: %d \n ", maxCores);
	// Se fija el numero de hilos deseado
	omp_set_num_threads(numHilos);
	printf("Numero de hilos fijados: %d\n", numHilos);

	
	/*Region paralela por OMP*/
	#pragma omp parallel 
	{	
	#pragma omp parallel for reduction(+: resSumatoria)
	for (int i=0; i<rep; i++)
		resSumatoria += fsum(i);	
	}
	printf("Resultado Sumatoria de la funcion SEN: %0.2f \n", resSumatoria);

	return(0);
}
