#include <stdio.h>
int main(int argc, char **argv){
	int i = 1;
	printf("Argumentos: ");
	for ( i = 1; i < argc; i++){
		printf("%s ", argv[i]);
	}
	printf("\n");
}
