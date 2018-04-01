#include <stdio.h>

int tam_arq_texto(char *nome_arquivo){
	FILE *fp = fopen(nome_arquivo, "r");
	int i = 0;
	while(!(feof(fp))){
		getc(fp);
		i = i+ sizeof(char);
	}
	fclose(fp);
	return i;
}

void le_arq_texto(char *nome_arquivo, char*conteudo){
	FILE *fp = fopen(nome_arquivo, "r");
	fread(conteudo, tam_arq_texto(nome_arquivo),1, fp);
	fclose(fp);
}
