#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int tam_arq_texto(char *nome_arquivo){
	int fp = open(nome_arquivo, O_RDONLY, S_IRUSR|S_IWUSR);
	int tamanho =lseek(fp,0,SEEK_END);
	close(fp);
	return tamanho;
}

void le_arq_texto(char *nome_arquivo, char*conteudo){
	int fp = open(nome_arquivo ,O_RDONLY, S_IRUSR|S_IWUSR);
	read(fp, &*conteudo, tam_arq_texto(nome_arquivo));
	close(fp);
}
