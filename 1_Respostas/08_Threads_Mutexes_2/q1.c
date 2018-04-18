#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int var_comunicacao;

void* funcao_thread( void* inutil){

	int i;
	int valores_principal[10];

	for( i = 0; i < 10; i++){
		sleep(0.1);
		valores_principal[i] = var_comunicacao;
		sleep(1);
	}

	for( i = 0; i < 10; i++){
		printf(" %d, ",valores_principal[i]);
	}
	printf("\n");
	return NULL;
}

int main(int argc, char** argv){
	
	int i;
	pthread_t thread_ID;
	pthread_create(&thread_ID, NULL, &funcao_thread, NULL);
	for(i = 0; i <10; i++){
		var_comunicacao = i+1;
		sleep(1);
	}
	sleep(1);
	return 0;
}
