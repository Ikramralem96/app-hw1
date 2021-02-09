#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "initMatrix.h"
#include "displayMatrix.h"
#include "MultMatrices.h"
#include "ThreadCalcule.h"

int main(int argc, char **argv) {

	int n;  	// MATRIX DIMENSION
	int i, j;

	if (argc == 1){
		printf("Usage: ./app-hw1 <matrix-size>\n");
		return 1;
	}

	n = atoi (argv[1]);
        Nbr =  = atoi (argv[2]);
        char * mode = argv[1];
     
	printf("Matrix size = %d\n", n);
	int **A = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		A[i] = (int *)malloc(n * sizeof(int));

	generateRandomMatrix(A, n, 0, 99);
printf("affichage de la matrice A\n");
	printMatrix(A, n);

int **B = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		B[i] = (int *)malloc(n * sizeof(int));

	generateRandomMatrix(B, n, 2, 99);
printf("affichage de la matrice B\n");
	printMatrix(B, n);

int **C = (int **)malloc(n * sizeof(int *));
TempsDeb=clock();
	for (i = 0; i < n; i++)
		C[i] = (int *)malloc(n * sizeof(int));

MultMatrices (A,B ,C, n);
printf("affichage de la matrice C\n");
	printMatrix(C, n);
if ((!strcmp(mode,"S"))
printf("sequenciel execution \n");
       TempsFin= clock();
temps = ((double)TempsFin-TempsDeb) / CLOCKS_PER_SEC;

	return 0;
   
   else 
   printf("Parallel execution \n");
exit(0)
}

TempsDeb=clock();

	ptheard_t *threads = (pthreads_t*) malloc(sizeof(pthreads_t) * NBR);
	for(i=0 ; i<NBR ; i++){
              Argement.istart= i * Argement.taille;
              Argement.iend= i * Argement.istart + Argement.taille-1 + Argement.reste ;
                TempsDeb = clock();
		if (pthread_create(&threads[i],NULL,MultipleMatrix(),&Argement)){
             fprintf(stderr, "Error creating thread\n");
              return 1;
	}
     
       if (pthread_join(threads[i], NULL)){
              fprintf(stderr,"Error joining threads \n");
                return 2;
       }
        printMatrix(Argement.C,Argement.n);
TempsFin= clock();
temps = ((double)TempsFin=TempsDeb) / CLOCKS_PER_SEC;
printf("temps d'execution : %f \n",temps);


     }
 }
