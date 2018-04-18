#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

long int v[50000];
long int v1[12500];
long int v2[12500];
long int v3[12500];
long int v4[12500];
long int maiores[4];

long int encontra_maior(long int* vetor, int N){

	long int maior = vetor[0];
	for( int i = 1; i < N; i++){
		if(vetor[i] > maior){
			maior = vetor[i];
			}
	}
	return maior;

}

void* thread1( void* inutil){
	maiores[0] = encontra_maior(v1, 12500);
	return NULL;
}

void* thread2( void* inutil){
	maiores[1] = encontra_maior(v2, 12500);
	return NULL;
}

void* thread3( void* inutil){
	maiores[2] = encontra_maior(v3, 12500);
	return NULL;
}

void* thread4( void* inutil){
	maiores[3] = encontra_maior(v4, 12500);
	return NULL;
}


int main(int argc, char** argv){
	
	int i;

	pthread_t thread_id1, thread_id2, thread_id3, thread_id4;

	long int valor_maior;
	for(i = 0; i <50000; i++){
		v[i] = random();
	}
	for(i = 0; i <12500; i++){
		v1[i] = v[i];
		v2[i] = v[12500+i];
		v3[i] = v[25000+i];
		v4[i] = v[37500+i];
	}

	pthread_create(&thread_id1, NULL, &thread1, NULL);
	pthread_create(&thread_id2, NULL, &thread2, NULL);
	pthread_create(&thread_id3, NULL, &thread3, NULL);
	pthread_create(&thread_id4, NULL, &thread4, NULL);	

	pthread_join(thread_id1,NULL);
	pthread_join(thread_id2,NULL);
	pthread_join(thread_id3,NULL);
	pthread_join(thread_id4,NULL);	
	
	valor_maior = encontra_maior(maiores,4);

	printf("Número maior: %d\n", valor_maior);
	return 0;
}
