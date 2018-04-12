#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv){

	int fd[2];
	pipe(fd);
	int i;
	
	if(fork()!=0){

	//Processo pai

	for(i = 1; i <= 10 ; i++){
		write(fd[1], &i, sizeof(int));
		sleep(1);
	}

	} else {
	//Processo filho

	int j;

	sleep(11); //Esperar o pai terminar de mandar os dados

	for(i = 0; i < 10 ; i++){
		read(fd[0], &j, sizeof(int));
		printf("%d, ",j);
	}
	puts("\n");
	}
	
	close(fd[0]);
	close(fd[1]);
	return 0;
}
