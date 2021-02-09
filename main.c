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


typedef struct blocksize{
	int n;
	int NbrThreads;
	int taille;
	int reste;
	int istart;
	int iend;
	int **A;
	int **B;
	int **C;
}blocksize;

typedef struct blocksize_Matrix{
	int n;
	int NbrThreads;
	int taille;
	int reste;
	int istart;
	int iend;
	int jstart;
	int jend;
	int **A;
	int **B;
	int **C;
}blocksize_Matrix;


void *MultipleVectorielle(void * args);
void *MultipleMatrix(void * args);

int main(int argc, char **argv) {

	int n;  	// MATRIX DIMENSION
	int i, j;
	clock_t   TempsDeb,Tempsfin;
	double    temps ; 

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
	for (i = 0; i < n; i++)
		C[i] = (int *)malloc(n * sizeof(int));
	
int **D = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		D[i] = (int *)malloc(n * sizeof(int));	

MultMatrices (A,B ,C, n);
printf("affichage de la matrice C\n");
	printMatrix(C, n);
	
	blocksize Argement;
	Argement.NbrThreads = NBR ;
	Argement.n = n;
	Argement.taille = n/NBR;
	Argement.reste = n%NBR;
	Argement.istart = 0;
	Argement.iend = n-1;
	Argement.A = A;
	Argement.B = B;
	Argement.C = C;
	
	blocksize_Matrix PetitMatrix;
	PetitMatrix.NbrThreads = NBR ;
	PetitMatrix.n = n;
	PetitMatrix.taille = n/(int)sqrt((NBR));
	PetitMatrix.reste = n%(int)sqrt((NBR));
	PetitMatrix.A = A;
	PetitMatrix.B = B;
	PetitMatrix.C = D; 
	
	
	
if ((!strcmp(mode,"S"))
printf("sequenciel execution \n");
         TempsDeb = clock();
         MultMatrices(A,B,n);
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


  printf("Parallel execution Petit Matrix : \n");
		debut = clock();
		pthread_t *threads2 = (pthread_t*) malloc(sizeof(pthread_t) * NBR);
		for(i=0; i<NBR; i++){ 
			PetitMatrix.istart = (i/(int)sqrt(NBR)) * PetitMatrix.taille;
			PetitMatrix.iend   = PetitMatrix.istart  + PetitMatrix.taille -1 + PetitMatrix.reste;
			if(i < sqrt(NBR)){
				PetitMatrix.jstart = i * PetitMatrix.taille;
				PetitMatrix.jend   = PetitMatrix.jstart + PetitMatrix.taille -1 + PetitMatrix.reste;
			}else{
				PetitMatrix.jstart = (i % (int)sqrt(NBR)) * PetitMatrix.taille;
				PetitMatrix.jend   = PetitMatrix.jstart + PetitMatrix.taille -1 + PetitMatrix.reste;
			}
			//debut = clock();
			if(pthread_create(&threads2[i], NULL,MultipleMatrix,&PetitMatrix)){ 
				fprintf(stderr, "Error creating thread\n");
				return 3;
			} 
			if(pthread_join(threads2[i], NULL)){ 
				fprintf(stderr, "Error joining thread\n");
			return 4;
			}
		} 		
	}
			printMatrix(PetitMatrix.C,PetitMatrix.n);
			fin = clock();
			temps = ((double)fin - debut) / CLOCKS_PER_SEC; 
			printf("\ntemps d'execution : %f \n",temps);
			printf("\n\n\n");
			
	}else 
		printf("choisi le bon nombre square   \n");
}
