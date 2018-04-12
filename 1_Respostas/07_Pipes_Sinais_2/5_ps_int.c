#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

void funcao_para_control_c()
{
	puts("\nProcesso Terminado!");
	exit(1);
}

int main(int argc, char** argv){

	signal(SIGINT, funcao_para_control_c);
	while(1){
		system("clear");
		system("ps --sort=pcpu");
		sleep(1);
	}

	return 0;
}
