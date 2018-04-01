#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
	int i = 0;
	int p_olamundo;
	char mensagem[128];
	p_olamundo = open("ola_usuario_2.txt", O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	
	if (argc >= 2){
		sprintf(mensagem,"Nome: %s\nIdade: %s\n",argv[1],argv[2]);
	}else{
		printf("Erro: quantidade insuficiente de argumentos\n");
		return 1;
	}
	while(mensagem[i]!='\0'){
		write(p_olamundo,&mensagem[i],1);
		i++;
	}

	close(p_olamundo);
	return 1;
}
