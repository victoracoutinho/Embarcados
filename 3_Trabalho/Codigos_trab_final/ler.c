#include "gpio_sysfs.h"
#include <unistd.h>
#include <stdio.h>

int main(){
	int pin = 21;
	if(setGPIO_In(pin,"rising"))
		return -1;
	while(1){
	printf("Valor de leitura: %d\n",GPIO_Read(pin));
	sleep(1);
	}
	return 0;
}
