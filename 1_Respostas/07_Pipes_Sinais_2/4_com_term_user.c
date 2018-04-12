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

	int fd[2];
	pipe(fd);

	char* nome_usuario;
	
	if(fork()!=0){
	//Processo pai

		puts("PAI: Bom dia! Vou escutar meu filho... ");
		nome_usuario = readfrase(fd[0]); 
		puts("PAI: Pronto!");
		printf("PAI: Seu nome é %s, certo?! Tchau.\n", nome_usuario);

	} else {
	//Processo filho

		puts("FILHO: Eu sou o filho.Qual o seu nome para que eu possa dizer para o meu pai? ");
		nome_usuario = (char *) malloc(128);
		scanf("%s", &*nome_usuario);
		printf("FILHO: Vou falar para ele... ");
		write(fd[1], &*nome_usuario, strlen(nome_usuario)+1);
		puts("Pronto! Tchou.");

	}
	
	return 0;
}
