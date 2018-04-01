#include <stdio.h>

int main(int argc, char **argv){
	int i = 1;
	FILE *p_olamundo;
	p_olamundo = fopen("ola_mundo.txt", "w");
	fprintf(p_olamundo,"Olá Mundo");
	printf("\n");
	fclose(p_olamundo);
}
