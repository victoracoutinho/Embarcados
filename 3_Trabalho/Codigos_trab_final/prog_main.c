#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "prog_defs.h"
#include "prog_functions.h"
#include "gpio_sysfs.h"

//Pinos GPIO
#define PHOTO 14
#define LIGA 21
#define PLAY 15
//#define RETURN 04;
//#define PAUSE 05;



struct pino_e_var{
	int pino;
	int variavel;
};


void* ativa_pino(void* pino_desejado){
	struct pino_e_var* p = (struct pino_e_var*) pino_desejado;
	//printf("Pino %d ativado\n",pino);
	while(1){
		p->variavel = GPIO_Read(p->pino);
		printf("[%d]Valor de leitura: %d\n",p->pino,p->variavel);
		sleep(1);
	}
}

int main(void)
{
	char c;

	struct pino_e_var 	ligar,
				continuar,
				//pausar,
				tirar_foto;

	int 	estado_atual=1,
		proximo_estado=1;

	pthread_t foto_id, liga_id, play_id, retorna_id, pausa_id;

	puts("Favor iniciar a câmera no CHDK e conectá-la à uma das portas USB da \
Raspberry Pi");
	puts("Favor posicionar a câmera alinhada com a página desejada e com a \
objetiva voltada para cima");
	//puts("Pressione ENTER quando pronto");
	//scanf("%c", &c);
	//Ler botão se quer continuar
	//read_continue(21);
	
	while(1){

		switch(estado_atual){
			case 1: //Inicialização
				
				/*Configurando o botão de ligar*/
				if(setGPIO_In(LIGA,"rising"))
					return -1;
				ligar.pino = LIGA;
				ligar.variavel = 0;
				pthread_create(&liga_id, NULL, &ativa_pino, &ligar);

				/*Configurando o botão de continuar*/
				if(setGPIO_In(PLAY,"rising"))
					return -1;
				continuar.pino = PLAY;
				continuar.variavel = 0;
				pthread_create(&play_id, NULL, &ativa_pino, &continuar);

				/*Configurando o botão de pausar*/
				//pausar.pino = PAUSE;
				//pausar.variavel = 0;
				//pthread_create(&foto_id, NULL, &ativa_pino, &pausar);

				/*Configurando o botão de pausar*/
				if(setGPIO_In(PHOTO,"rising"))
					return -1;
				tirar_foto.pino = PHOTO;
				tirar_foto.variavel = 0;
				pthread_create(&foto_id, NULL, &ativa_pino, &tirar_foto);
				while(ligar.variavel == 0);
				ligar.variavel = 0;
				proximo_estado = 2; 
				break;
				
				
			case 2: //Inicialização da camera
			
				/* Inicializar chdk, câmera deve estar preparada */
				init_camera();
				proximo_estado = 3;
				break;
				
			case 3:	//Tira foto do documento
				//printf("Valor para PHOTO : %d\n", tirar_foto.variavel);
				/* Tirar foto e corrigir orientação */
				if (tirar_foto.variavel == 0)
					proximo_estado = 3;
				else{
					tirar_foto.variavel = 0;
					take_photo();
					proximo_estado = 4;
				}

				break;
				
			case 4: //Converter imagem em texto
			
				/* Chamar o tesseract */
				reco_char();
				proximo_estado = 5;
				break;
				
			case 5: //Divide em pedaços
			
				/*Dividir o arquivo texto*/
				//divide_text();
				proximo_estado = 6;
				break;
				
			case 6: //Escolha das opções

				if(ligar.variavel == 1){//Desligar
					ligar.variavel = 0;
					proximo_estado = 11;
				}else if(continuar.variavel == 1){//Vai para o play
					continuar.variavel = 0;
					proximo_estado = 7;
				}else if(tirar_foto.variavel == 1){//Tira outra foto
					//tirar_foto.variavel = 0;
					proximo_estado = 3;
				}else{
					proximo_estado = 6;
				}

				break;
				
			case 7://PLAY
			
				/* Chamar o espeak */
				system("cat saida.txt");
				speak();
				proximo_estado = 6;

				proximo_estado = 6;
				break;
			case 8:
				proximo_estado = 6;
				break;
			case 9:
				proximo_estado = 6;
				break;
			case 10:
				proximo_estado = 6;
				break;
				
			case 11: //Deligar o sistema
			
				/* Disconectar a câmera */
				dc_camera();
				while(ligar.variavel == 0);
				ligar.variavel = 0;
				proximo_estado = 2;
				/*if(ligar.variavel == 0){
					proximo_estado = 11;
				}else{
					proximo_estado = 2;
				}*/
				break;
		}
		printf("Estado atual: %d | ", estado_atual);
		printf("Proximo estado: %d\n", proximo_estado);
		estado_atual = proximo_estado;
		usleep(1000);
	}
	return 0;
}
