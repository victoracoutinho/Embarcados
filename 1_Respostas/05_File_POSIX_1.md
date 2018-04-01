1. Considerando a biblioteca-padrão da linguagem C, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

```C
FILE *fd = fopen(*char diretorio, *char acao_sobre_o_arquivo)

int fclose( FILE *fd);
```


(b) Quais são as funções (e seus protótipos) para escrever em arquivos?


```C
fprintf( FILE *fd, *char texto, parametros, ...);
```

(c) Quais são as funções (e seus protótipos) para ler arquivos?


```C
fscanf(FILE* fd, char* texto_de_leitura, parametros, ...);
```

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?


```C
fseek( FILE* fd, long offset, int opcoes);

```

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

stdio.h

2. O que é a norma POSIX?


POSIX é uma família de padrões especificados. Esses padrões são especificadoes pela IEEE para que mantenha uma compabtibilidade entre sistemas operacionais.

3. Considerando a norma POSIX, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?


```C
int fd = open(*char diretorio, int acao_sobre_o_arquivo);
int close( int fd );
```

(b) Quais são as funções (e seus protótipos) para escrever em arquivos?


```C
int write(fd, void endereco_da_string, size_t quantidade_de_bytes);
```

(c) Quais são as funções (e seus protótipos) para ler arquivos?


```C
int read (int fd, void endereco_da_string, int quantidade_de_bytes);
```

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?


```C
int lseek(int fd, offset_t offset, int opcoes)

```

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

A biblioteca fcntl.h e unistd.h.


