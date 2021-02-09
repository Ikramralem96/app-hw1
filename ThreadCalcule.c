#include <stdio.h>
#include <stdlib.h>
#include <pthreadh>
#include "ThreadCalcule.h"
#include "displayMatrix.h"


typedef struct blocksize{

int n;
int **A;
int **B;
int **C;
int Nbr;
int taille;
int instart;
int iend;
int istart;
}blocksize;

typedef struct blocksize_Matrix_Form{
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
}blocksize_Matrix_Form;


 
void * MultipleMatrix(){
	istart = i * 	
	for(int i = blk->istart; i<=blk-> iend, ++i){
              for(int j=0; j<blk->n;j++)
                  for(int k=0;k<blk->n;k++){
                         blk->C[i][j] = blk->C[i][j] + blk->A[i][k] * blk->B[k][j];
		
	}
}
   return NULL;
}
void *Mult_vectorielle(void * args){		
	blocksize * blk = (blocksize *) args;
	for(int i = blk->istart; i<=blk->iend; i++){
		for(int j=0; j<blk->n; j++)
			for(int k=0; k<blk->n; k++){
				blk->C[i][j] = blk->C[i][j] + blk->A[i][k] * blk->B[k][j];			
			}
		}
	return NULL;
}

