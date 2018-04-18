#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

long int v[50000];

long double encontra_media(long int* vetor, int N){

	long long int soma = 0;
	long double media = 0;
	for( int i = 0; i < N; i++){
			soma += vetor[i];
	}
	media = ((long double ) soma)/N;
	printf("soma: %lld\n", soma);
	printf("N: %d\n", N);
	printf("media: %llf\n", media);
	return media;
}


int main(int argc, char** argv){
	
	int i;
	long double valor_media;
	for(i = 0; i <50000; i++){
		v[i] = random();
	}
	valor_media = encontra_media(v, 50000);
	printf("Média: %d\n", valor_media);
	return 0;
}
