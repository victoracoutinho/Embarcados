prog: prog_defs.h prog_functions.h gpio_sysfs.h 
	gcc $(CFLAGS) gpio_sysfs.c prog_functions.c prog_main.c -o prog -pthread
clean:
	rm prog
