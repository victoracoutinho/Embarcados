1. Apresente as características e utilidades das seguintes funções:

(a) `popen()`

`FILE *popen(const char *command, const char *type);`

Essa função abre um processo por meio da criação de um `pipe`, fazendo um  `fork` e então chamando a `shell`. O argumento `type`da função indica se será feito apenas leitura(`r`) do processo ou apenas escrita(`w`), isso é devido ao pipe. Pode-se adicionar a letra 'e' e isso para setar a flag `FD_CLOEXEC` no final do descritor do arquivo.

(b) `pclose()`

`int pclose(FILE *stream);`

Essa função o processo associado terminar e retorna o estado de saída do comando como se fosse retornado por `wait4()`.

(c) `fileno()`

`int fileno(FILE *stream);`

Essa função examina o argumento `stream` e retorna seu descritor de arquivo.

2. Quais são as vantagens e desvantagens em utilizar:

(a) `popen()?`

popen executa ambas simultaneamente e há uma comunicação entre as duas.

(b) `exec()?`

O exec para de executar a função principal para executar o argumento
