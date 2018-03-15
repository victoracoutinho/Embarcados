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
