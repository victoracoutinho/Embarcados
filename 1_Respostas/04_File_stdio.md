Para todas as questões, utilize as funções da biblioteca `stdio.h` de leitura e de escrita em arquivo (`fopen()`, `fclose()`, `fwrite()`, `fread()`, dentre outras). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

Código em C
```C
#include <stdio.h>

int main(int argc, char **argv){
	int i = 1;
	FILE *p_olamundo;
	p_olamundo = fopen("ola_mundo.txt", "w");
	fprintf(p_olamundo,"Olá Mundo");
	printf("\n");
	fclose(p_olamundo);
}
```

2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

Código em C
```C
int main(int argc, char **argv){
	int i = 1;
	FILE *p_olamundo;
	p_olamundo = fopen("ola_usuario_1.txt", "w");
	char nome[100];
	int idade;
	printf("Digite seu nome: ");
	scanf("%s",&nome);
	printf("Digite sua idade: ");
	scanf("%d",&idade);
	
	fprintf(p_olamundo,"Nome: %s\nIdade: %d\n",nome,idade);
	fclose(p_olamundo);
}
```

3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

Código em C
```C
#include <stdio.h>

int main(int argc, char **argv){
	int i = 1;
	FILE *p_olamundo;
	p_olamundo = fopen("ola_usuario_2.txt", "w");
	
	fprintf(p_olamundo,"Nome: %s\nIdade: %s\n",argv[1],argv[2]);
	fclose(p_olamundo);
}
```

4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

Código em C
```C
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
```

5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `void le_arq_texto(char *nome_arquivo, char *conteudo);` Repare que o conteúdo do arquivo é armazenado no vetor `conteudo[]`. Ou seja, ele é passado por referência. Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

Código em C
```C
void le_arq_texto(char *nome_arquivo, char*conteudo){
	FILE *fp = fopen(nome_arquivo, "r");
	fread(conteudo, tam_arq_texto(nome_arquivo),1, fp);
	fclose(fp);
}
```

6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```
Código em C
```C
#include <stdio.h>
#include "bib_arqs.h"

int main(int argc, char **argv){
	char *nome_arquivo = argv[1];
	char texto_arquivo[100];
	le_arq_texto( nome_arquivo, texto_arquivo);
	printf("%s", texto_arquivo);
	return 1;
}
```
7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```
Código em C
```C
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
```
