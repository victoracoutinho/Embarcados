#include <stdio.h>

int main(int argc, char **argv){
	int i = 1;
	FILE *p_olamundo;
	p_olamundo = fopen("ola_usuario_2.txt", "w");
	
	fprintf(p_olamundo,"Nome: %s\nIdade: %s\n",argv[1],argv[2]);
	fclose(p_olamundo);
}
