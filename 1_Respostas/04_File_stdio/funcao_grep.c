#include <stdio.h>
#include "bib_arqs.h"

int main(int argc, char **argv){
	char *palavra_chave = argv[1];
	char *nome_arquivo = argv[2];
	char texto_arquivo[100];
	int i, j, N=0;
	int contador = 0;
	
	while (palavra_chave[N]!='\0'){
		N++;
	}

	printf("N = %d de |%s| e |%s|\n", N,argv[1],palavra_chave);
	le_arq_texto( nome_arquivo, texto_arquivo);
	for(i = 0; i<100;i++){
	printf("%d : Entrou no 1o for: %c\n",i,texto_arquivo[i]); 
		for( j = 0; j < N; ){
			printf("%d : Entrou no 2o for: %c e %c ",j, texto_arquivo[i+j], palavra_chave[j]); 
			if(texto_arquivo[i+j] == palavra_chave[j]){
				j++;
				if(j == (N-1))
					contador++;
				printf("- Letra igual\n");
			}else{
				i = i + j; // Para não ficar repitindo
				printf("- Letra diferente\n");
				break;
			}
		}
	}
	printf("'%s' ocorre %d vezes no arquivo '%s'\n",palavra_chave, contador, nome_arquivo);
	return 1;
}
