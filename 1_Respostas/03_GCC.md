Para todas as questões, compile-as com o gcc e execute-as via terminal.

1. Crie um "Olá mundo!" em C.

```C
#include <studio.h>
int main(){
	printf("Ola Mundo\n");
}
```

2. Crie um código em C que pergunta ao usuário o seu nome, e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Ola Eu
```
Código em C:

```C
#include <stdio.h>
int main(){
	char nome[100];
	printf("Qual o seu nome? ");
	scanf("%s", nome);
	printf("Ola %s\n", nome);
}
```

3. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu Mesmo
```

Apresentou apenas o `Eu`.

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_1
$ Digite o seu nome: "Eu Mesmo"
```

Apresentou apenas `"Eu`

(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_1
```

(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_1
```

```besh
Qual o seu nome? Ola Eu
```

(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo "Eu Mesmo" | ./ola_usuario_1
```
```besh
Qual o seu nome? Ola Eu
```


(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_1 < ola.txt
```

Apareceu `Qual o seu nome? Ola Ola`

4. Crie um código em C que recebe o nome do usuário como um argumento de entrada (usando as variáveis argc e *argv[]), e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu
$ Ola Eu
```
Código em C:

```C
#include <stdio.h>
int main(int argc, char **argv){

	printf("Ola %s\n", argv[1]);
}
```

5. Apresente os comportamentos do código anterior nos seguintes casos:

(a) Se o usuário insere mais de um nome.
```bash
$ ./ola_usuario_2 Eu Mesmo
```

Apareceu somente `Ola Eu`.

(b) Se o usuário insere mais de um nome entre aspas duplas. Por exemplo:
```bash
$ ./ola_usuario_2 "Eu Mesmo"
```

Apareceu `Ola Eu Mesmo`

(c) Se é usado um pipe. Por exemplo:
```bash
$ echo Eu | ./ola_usuario_2
```

Apareceu `Ola (null)`.

(d) Se é usado um pipe com mais de um nome. Por exemplo:
```bash
$ echo Eu Mesmo | ./ola_usuario_2
```
Apareceu `Ola (null)`.

(e) Se é usado um pipe com mais de um nome entre aspas duplas. Por exemplo:
```bash
$ echo "Eu Mesmo" | ./ola_usuario_2
```
Apareceu `Ola (null)`.

(f) Se é usado o redirecionamento de arquivo. Por exemplo:
```bash
$ echo Ola mundo cruel! > ola.txt
$ ./ola_usuario_2 < ola.txt
```
Apareceu `Ola (null)`.

6. Crie um código em C que faz o mesmo que o código da questão 4, e em seguida imprime no terminal quantos valores de entrada foram fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_3':

```bash
$ ./ola_usuario_3 Eu
$ Ola Eu
$ Numero de entradas = 2
```

Código em C:

```C
#include <stdio.h>
int main(int argc, char **argv){

	printf("Ola %s\n", argv[1]);
	printf("Número de entradas = %d\n", argc);
}
```

7. Crie um código em C que imprime todos os argumentos de entrada fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_argumentos':

```bash
$ ./ola_argumentos Eu Mesmo e Minha Pessoa
$ Argumentos: Eu Mesmo e Minha Pessoa
```
Código em C:

```C
#include <stdio.h>
int main(int argc, char **argv){
	int i = 1;
	printf("Argumentos: ");
	for ( i = 1; i < argc; i++){
		printf("%s ", argv[i]);
	}
	printf("\n");
}
```

8. Crie uma função que retorna a quantidade de caracteres em uma string, usando o seguinte protótipo:
`int Num_Caracs(char *string);` Salve-a em um arquivo separado chamado 'num_caracs.c'. Salve o protótipo em um arquivo chamado 'num_caracs.h'. Compile 'num_caracs.c' para gerar o objeto 'num_caracs.o'.

Código em C:

```C
#include <stdio.h>
int num_caracs(char *string){
	int i=0;
	while (string[i] != '\0'){
		i++;
	}
	return i;
	
}
```

Compilação no terminal:

```bech
gcc -c num_caracs.c

```

9. Re-utilize o objeto criado na questão 8 para criar um código que imprime cada argumento de entrada e a quantidade de caracteres de cada um desses argumentos. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_1':

```bash
$ ./ola_num_caracs_1 Eu Mesmo
$ Argumento: ./ola_num_caracs_1 / Numero de caracteres: 18
$ Argumento: Eu / Numero de caracteres: 2
$ Argumento: Mesmo / Numero de caracteres: 5
```
Código em C:

```C
#include <stdio.h>
#include "num_caracs.h"

int main(int argc, char **argv){
	int i;
	for (i = 0; i < argc ; i++){
		printf("Argumento: %s / Número de caracteres: %d \n", argv[i], num_caracs(argv[i]));
	}
}
```

10. Crie um Makefile para a questão anterior.

```bash
executar: 9_caracter.o num_caracs.o
	gcc -o ola_num_caracs_1 9_caracter.o num_caracs.o
9_caracter.o: 9_caracter.c
	gcc -c 9_caracter.c
num_caracs.o: num_caracs.c
```

11. Re-utilize o objeto criado na questão 8 para criar um código que imprime o total de caracteres nos argumentos de entrada. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_2':

```bash
$ ./ola_num_caracs_2 Eu Mesmo
$ Total de caracteres de entrada: 25
```

Código em C:

```C
#include <stdio.h>
#include "num_caracs.h"

int main(int argc, char **argv){
	int i;
	int num = 0;
	for (i = 0; i < argc ; i++){
		num = num_caracs(argv[i])+num;
	}
	printf("Total de caracteres de entrada: %d\n", num);
}
```

12. Crie um Makefile para a questão anterior.

```bash
executar: 9_caracter.o num_caracs.o
	gcc -o ola_num_caracs_2 11_caracter.o num_caracs.o
9_caracter.o: 11_caracter.c
	gcc -c 11_caracter.c
num_caracs.o: num_caracs.c
```
	gcc -c num_caracs.c
