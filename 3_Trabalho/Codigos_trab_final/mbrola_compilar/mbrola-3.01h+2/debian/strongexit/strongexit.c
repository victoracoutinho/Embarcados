#define _GNU_SOURCE
#include <unistd.h>
#ifdef __i386__
#define SYS_exit 1
#else
#include <sys/syscall.h>
#endif
void exit(int status) {
	syscall(SYS_exit, status);
	while(1);
}
