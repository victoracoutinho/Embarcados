#include <stdio.h>

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
