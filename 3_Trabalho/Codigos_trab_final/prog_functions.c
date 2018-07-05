#include <stdio.h>
#include <stdlib.h>
#include "prog_defs.h"
#include "gpio_sysfs.h"
void init_camera()
{
	puts("Inicializar CHDK");
	puts("Conectar a câmera");
	system(CMD_ENTER_REC_MODE);
}

void take_photo()
{
	char rot_cmd[256];
	puts("Tirar foto");
	system(CMD_TAKE_PHOTO);
	/* Rotacionar a imagem */
	sprintf(rot_cmd, "convert %s -rotate 90 %s", PIC_LOCATION, PIC_LOCATION);
	printf("Rotacionando a imagem com:\n%s\n", rot_cmd);
	system(rot_cmd);
}

void reco_char()
{
	char reco_char[256];
	sprintf(reco_char, "tesseract %s %s -l %s", PIC_LOCATION, TESS_OUT_FILE,
TESS_LANG_POR);
	printf("Chamando o tesseract com:\n%s\n", reco_char);
	system(reco_char);
}

void speak()
{
	char spk_cmd[256];
	sprintf(spk_cmd, "espeak-ng -a 200 -s 130 -v %s -f %s", ESPEAK_VOICE_PTBR1,
TESS_OUT_FILE_NAME);
	system(spk_cmd);
}

void dc_camera()
{
	puts("Disconectando câmera");
	system(CMD_DISCONNECT_CAMERA);
	puts("Câmera desconectada");
}

void read_continue(int pin,int mode){
	if(mode == 1)
		if(setGPIO_In(pin,"rising"))
			puts("Erro na leitura do botão...\n");
	if(mode == 2)
		GPIO_Read(pin);
	else
		unsetGPIO(pin);
}
