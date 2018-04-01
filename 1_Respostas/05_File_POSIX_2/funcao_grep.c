#include <stdio.h>
#include "bib_arqs.h"

int main(int argc, char **argv){
	char *palavra_chave = argv[1];
	char *nome_arquivo = argv[2];
	char *texto_arquivo;
	int i, j, N=0, tam_arq;
	int contador = 0;
	
	while (palavra_chave[N]!='\0'){
		N++;
	}
	tam_arq = tam_arq_texto(argv[2]);
	texto_arquivo = (char*)malloc(tam_arq+1);

	le_arq_texto( nome_arquivo, texto_arquivo);
	for(i = 0; i<100;i++){
		for( j = 0; j < N; ){
			if(texto_arquivo[i+j] == palavra_chave[j]){
				j++;
				if(j == (N-1))
					contador++;
			}else{
				i = i + j; // Para não ficar repitindo
				break;
			}
		}
	}
	printf("'%s' ocorre %d vezes no arquivo '%s'\n",palavra_chave, contador, nome_arquivo);
	return 1;
}
