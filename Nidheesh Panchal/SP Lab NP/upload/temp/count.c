void count(char str[])
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]<=90)
			a[str[i]-65]+=1;
		else
			a[str[i]-97]+=1;
	}
}

gcc -c try.c
	nasm -f elf64 n1.asm
	ld n1.o try.o -lc -I /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2

	nasm -f elf64 n1.asm
	gcc -Wall try.c n1.o