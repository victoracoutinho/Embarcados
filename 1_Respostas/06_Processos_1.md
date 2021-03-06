1. Como se utiliza o comando `ps` para:

(a) Mostrar todos os processos rodando na máquina?

```Bash
ps -e

```

(b) Mostrar os processos de um usuário?

```Bash
ps -auusuario

```

(c) Ordenar todos os processos de acordo com o uso da CPU?

```Bash
ps -e --sort=pcpu
```

(d) Mostrar a quanto tempo cada processo está rodando?

```Bash
ps -e --sort=cputime

```

2. De onde vem o nome `fork()`?

Vem do inglês que pode significar bifurcação.

3. Quais são as vantagens e desvantagens em utilizar:

(a) `system()`?

Ao usar o `sytem`, você sabe que apos executar o argumento o programa volta para sua execução normal. É fácil de utilizar, porém pode haver problemas de segurança.

(b) `fork()` e `exec()`?

Com essas funções você pode executar o argumento do `exec`paralelamente com a função principal(a função pai). É mais completo de se utilizar.

4. É possível utilizar o `exec()` sem executar o `fork()` antes?

Sim. Porém a execução inicial morre e é substituida pelo argumento.

5. Quais são as características básicas das seguintes funções:

(a) `execp()`?

Executa o programa que está localizado no mesmo local que o programa anterior.

(b) `execv()`?

Os argumentos do programa estão em um vetor fixo terminado em NULL.

(c) `exece()`?

Permite que quem chamou o programa especifique o ambiente em que o programa será executado por meio da variável envp.

(d) `execvp()`?

Os argumentos do programa estão em um vetor fixo terminado em NULL e o programa está localizado no mesmo local que o programa anterior.

(e) `execve()`?

Os argumentos do programa estão em um vetor fixo terminado em NULL e permite que o programa anterior especifique o ambiente em que o programa será executado por meio da variável envp.

(f) `execle()`?

Os argumentos do programa são vários args e que a ultima deve ser NULL, e permite que o programa anterior especifique o ambiente em que o programa será executado por meio da variável envp.
