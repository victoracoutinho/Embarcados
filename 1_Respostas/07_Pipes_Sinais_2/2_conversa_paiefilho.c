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
		//printf("Leu arquivo?\n");
		erro = read(fd, &a, sizeof(char));
		str = (char* )realloc(str,sizeof(char)+cont);
		if (erro == 1){
			str[cont] = a;
			str[cont+1] = '\0';
			cont++;
		}
	//printf("%d - e%d: Leitura com sucesso: string - %s - tamanho: %d\n", cont, erro, str, strlen(str));
	//if(a == '\0')
		//puts("ACHOU O BARRA O :o");
	}

	//str = (char* )malloc((cont+1)*sizeof(char));
	str[cont] = '\0';
	//printf("Saida: %s\n", str);
	//puts("Fim de leitura");
	return str;
	puts("Não conseguiu retornar");
	
}

int main(int argc, char** argv){

	int const n = 4;

	int fd[2];
	pipe(fd);
	int i,j;
	int tamConversa;
	int tamMensagem[n];
	
	if(fork()!=0){

	//Processo pai

	char* fala_pai[2] = {"Não façais nada violento, praticai somente aquilo que é justo e equilibrado.","Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu..."};
	char* mens_filho[n];
	int tam=0; //apagar

	for(i = 0; i < n ; i++){
		printf("	PAI: i = %d;\n", i);
		//lseek(fd[0],0,SEEK_SET);
		//tamMensagem[i] = 0;
		/*if(i == 1){
			//tamMensagem[i-1] = lseekf(fd[0],0,SEEK_END);
			//printf("tamanho : %d\n", tamMensagem[i-1]);
			//mens_filho[i-1] = (char*)malloc(tamMensagem[i-1] + 1);
			//read(fd[0], &mens_filho[i-1], tamMensagem[i-1]); //Escuta do filho
			mens_filho[i-1] = readfrase(fd[0]); //Escuta do filho
			//mens_filho[i-1] = (char*)malloc(100 + 1);
			//read(fd[0], &*mens_filho[i-1], 100);
			//mens_filho[i-1][20] = '\0';	
			//mens_filho[i-1][tam] = '\0';
			//printf("Leu! :)\n");
			printf("PAI ESCULTA O FILHO: %s\n", mens_filho[i-1]);
			write(fd[1], &*fala_pai[0], strlen(fala_pai[0])+1); // Fala para o filho
			printf("PAI FALA PARA O FILHO: %s\n", fala_pai[(int)(i-1)/2]);
		}else */if ( i%2 != 0) {

			//tamConversa = lseek(fd[0],0,SEEK_END);
			/*for( j = 0; j < (i+1)/2; j++){
				tamMensagem[i-1] = tamConversa - tamMensagem[2*j] - sizeof(fala_pai[j]);
			}*/

			mens_filho[i-1]=readfrase(fd[0]); // Leu mensagem do filho
			printf("PAI ESCULTA O FILHO: %s\n", mens_filho[i-1]);

			write(fd[1], &*fala_pai[(i-1)/2], strlen(fala_pai[(i-1)/2])+1); // Fala para o filho
			printf("PAI FALA PARA O FILHO: %s\n", fala_pai[(int)(i-1)/2]);
		}
		sleep(1);
	}

	} else {
	//Processo filho

	char* fala_filho[2] = {"Pai, qual é a verdadeira essência da sabedoria?","Mas até uma criança de três anos sabe disso!"};
	char* mens_pai[n];
	////char* teste_apagar;


	for(i = 0; i <= n ; i++){
		printf("	FILHO: i = %d;\n", i);
		//lseek(fd[0],0,SEEK_SET);
		tamMensagem[i] = 0;
		if(i == 0){
			//tamMensagem[i-1] = lseek(fp[0],0,SEEK_END);
			//read(fd[0], &mens_pai[i-1], tamMensagem);
			//printf("size of: %d e %d\n",strlen(fala_filho[0]), sizeof(char));
			write(fd[1], &*fala_filho[0], strlen(fala_filho[0])+1); // Fala para o pai
			printf("FILHO FALA PARA O PAI: %s\n", fala_filho[(int)(i)/2]);
		}else if ( i%2 == 0) {

			//tamConversa = lseek(fd[0],0,SEEK_END);
			/*for( j = 0; j < (i)/2; j++){
				if(i = 2){
					tamMensagem[i-1] = tamConversa - sizeof(fala_filho[j]);
				}else{
					tamMensagem[i-1] = tamConversa - tamMensagem[2*j-1] - sizeof(fala_filho[j]);
				}
			}*/

			//if( i != 0 ){
				//puts("Vai ler");
				mens_pai[i-1]=readfrase(fd[0]); // Leu mensagem do pai
				//teste_apagar=(char*)readfrase(fd[0]);
				//puts("retornou");
				printf("FILHO ESCULTA O PAI: %s\n", mens_pai[i-1]);
				//printf("FILHO ESCULTA O PAI: %s\n",teste_apagar);
			//}

			if( i != n){
				write(fd[1], &*fala_filho[(i)/2], strlen(fala_filho[(i)/2])+1); // Fala para o pai
				printf("FILHO FALA PARA O PAI: %s\n", fala_filho[(int)(i)/2]);
			}
		}
		sleep(1);
	}
	}
	
	//close(fd[0]);
	//close(fd[1]);
	return 0;
}
