#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char* readfrase(int fd){
	int cont=0;
	int erro;
	char a=' ';
	char* str;

	str = (char* )malloc(sizeof(char)+1);

	while(erro !=-1 && a !='\0'){
		erro = read(fd, &a, sizeof(char));
		str = (char* )realloc(str,sizeof(char)+cont);
		if (erro == 1){
			str[cont] = a;
			str[cont+1] = '\0';
			cont++;
		}
	}

	str[cont] = '\0';
	return str;
}

int main(int argc, char** argv){

	int fd[2];
	pipe(fd);
	
	if(fork()!=0){
	
		if(fork()!=0){

		//Processo pai

			char* fala_pai = {"Os dois se enganam. É a mente dos senhores que se move."};
			char* mens_filho[2];

			sleep(1);
			mens_filho[0]=readfrase(fd[0]); // Leu mensagem do filho 1

			sleep(1);
			mens_filho[1]=readfrase(fd[0]); // Leu mensagem do filho 2

			printf("PAI ESCULTA O FILHO 1: %s\n", mens_filho[0]);
			printf("PAI ESCULTA O FILHO 2: %s\n", mens_filho[1]);

			write(fd[1], &*fala_pai, strlen(fala_pai)+1); // Fala para o filho
			printf("PAI FALA PARA OS FILHOS: %s\n", fala_pai);
			sleep(1);

		}else{
		//Processo filho 2

			char* fala_filho = {"Não, é o vento que se move."};
			char* mens_pai;

			sleep(1);

			write(fd[1], &*fala_filho, strlen(fala_filho)+1); // Fala para o pai
			printf("FILHO 2 FALA PARA O PAI: %s\n", fala_filho);
			sleep(1);

			sleep(1);
		}

	} else {
	//Processo filho 1

		char* fala_filho = {"Quando o vento passa, é a bandeira que se move."};
		char* mens_pai;

		write(fd[1], &*fala_filho, strlen(fala_filho)+1); // Fala para o pai
		printf("FILHO 1 FALA PARA O PAI: %s\n", fala_filho);
		sleep(1);

		sleep(1);

		sleep(1);
		mens_pai=readfrase(fd[0]); // Leu mensagem do pai
		printf("FILHO 1 ESCULTA O PAI: %s\n", mens_pai);
	}
	
	return 0;
}
