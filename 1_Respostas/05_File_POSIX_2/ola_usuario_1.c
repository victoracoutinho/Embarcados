#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
	int i = 0;
	int p_olamundo;
	char nome[100];
	int idade;
	char mensagem[120];
	printf("Digite seu nome: ");
	scanf("%s",&nome);
	printf("Digite sua idade: ");
	scanf("%d",&idade);

	p_olamundo = open("ola_usuario_1.txt", O_WRONLY|O_CREAT|O_APPEND,S_IRUSR|S_IWUSR);
	
	sprintf(mensagem,"Nome: %s\nIdade: %d\n",nome,idade);

	while(mensagem[i]!='\0'){
		write(p_olamundo,&mensagem[i],1);
		i++;
	}

	close(p_olamundo);
}
