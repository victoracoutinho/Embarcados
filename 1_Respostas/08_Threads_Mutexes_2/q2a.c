#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

long int v[50000];

long int encontra_maior(long int* vetor){

	long int maior = vetor[0];
	for( int i = 1; i <50000; i++){
		if(vetor[i] > maior)
			maior = vetor[i];
	}
	return maior;
}


int main(int argc, char** argv){
	
	int i;
	long int valor_maior;
	for(i = 0; i <50000; i++){
		v[i] = random();
	}
	valor_maior = encontra_maior(v);
	printf("Número maior: %d\n", valor_maior);
	return 0;
}
