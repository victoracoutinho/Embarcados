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

void* thread( void* posicao){

	struct posicao_i_j* pont = (struct posicao_i_j*) posicao;
	int i = pont->i;
	int j = pont->j;
	A[i][j] = random();
	B[i][j] = random();	
	AB[i][j] = A[i][j]+B[i][j];
	return NULL;
}


int main(int argc, char** argv){
	
	int i = 0,j = 0;

	pthread_t thread_id[60][60];

	struct posicao_i_j posicao_main;
	for(i = 0; i <60; i++){
		for(j = 0; j <60; j++){
			posicao_main.i = i;
			posicao_main.j = j;
			pthread_create(&thread_id[i][j],NULL,&thread,&posicao_main);
			//pthread_create(&thread_id1[i][j],NULL,&thread1,&posicao_main, NULL);
			//pthread_create(&thread_id1, NULL, &thread1, NULL);
		}
	}

	pthread_join(thread_id[59][59],NULL);
	//sleep(1);
	
	//Apresentar a Matriz AB

	for(i = 0; i <60; i++){
		for(j = 0; j <60; j++){
			printf("%ld ",AB[i][j]);
		}
		printf("\n");
	}

	return 0;
}
