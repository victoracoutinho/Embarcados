1. Quantos pipes serão criados após as linhas de código a seguir? Por quê?

(a)
```C
int pid;
int fd[2];
pipe(fd);
pid = fork();
```
Um pipe, pois a criação do filho foi feita depois de criar o pipe e este será compartilhado entre o pai e o filho.

(b)
```C
int pid;
int fd[2];
pid = fork();
pipe(fd);
```
Dois pipes, pois o pipe só será criado após a criação do filho, sendo assim cada um(pai e filho) terá um pipe diferente.

2. Apresente mais cinco sinais importantes do ambiente Unix, além do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais são suas características e utilidades?

`SIGHUP` - sinal que é emitido quando um processo é desconectado do terminal ou um processo chefe termina sua execução.

`SIGQUIT` - sinal que é emitido para um processo quando uma tecla de abandono do teclado é acionada.

`SIGILL` - sinal que é emitido quando uma instrução de um processo é detectada.

`SIGKILL` - sinal que é emitido pelo sitema para matar um processo.

`SIGPIPE` - sinal que é emitido quando um processo tenta escrever em um pipe, porém ele não está aberto para leitura.

3. Considere o código a seguir:

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```

Sabendo que a função `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, quão precisos são os alarmes criados neste código? De onde vem a imprecisão? Este é um método confiável para desenvolver aplicações em tempo real?

A função `alarm`tem uma precisão de cerca de dezenas de milisegundos, sendo assim um impreciso. Isso é divido ao processador dos computadores executar vários processos, mas não de forma paralela. Esse método se torna não confiavel a aplicações em tempo real.
