comp: check.c temp2.asm
	gcc -c check.c
	nasm -f elf64 temp2.asm
	ld temp2.o check.o -lc -I /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2