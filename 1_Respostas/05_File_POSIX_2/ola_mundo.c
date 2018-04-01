#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
	int i = 0;
	int p_olamundo;
	p_olamundo = open("ola_mundo.txt", O_WRONLY|O_CREAT,S_IRUSR | S_IWUSR);
	char *mensagem = "Ola mundo";
	//write(p_olamundo,&mensagem,10);
	while(mensagem[i]!='\0'){
		write(p_olamundo,&mensagem[i++],1);
	}
	close(p_olamundo);
}
