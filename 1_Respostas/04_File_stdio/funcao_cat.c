#include <stdio.h>
#include "bib_arqs.h"

int main(int argc, char **argv){
	char *nome_arquivo = argv[1];
	char texto_arquivo[100];
	le_arq_texto( nome_arquivo, texto_arquivo);
	printf("%s", texto_arquivo);
	return 1;
}
