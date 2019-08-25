comp: try.c n1.asm
	gcc -c try.c
	nasm -f elf64 n1.asm
	ld n1.o try.o -lc -I /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2