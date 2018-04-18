#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

long int A[60][60];
long int B[60][60];
long int AB[60][60];

struct posicao_i_j{
	int i;
	int j;
};

int main(int argc, char** argv){
	
	int i,j;

	for(i = 0; i <60; i++){
		for(j = 0; j <60; j++){
			A[i][j] = random();
			B[i][j] = random();
			AB[i][j] = A[i][j]+B[i][j];
		}
	}

	//Apresentar a Matriz AB

	for(i = 0; i <60; i++){
		for(j = 0; j <60; j++){
			printf("%ld ",AB[i][j]);
		}
		printf("\n");
	}

	return 0;
}
