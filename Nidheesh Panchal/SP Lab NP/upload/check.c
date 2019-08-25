#include<stdio.h>

int check(char ch)
{
	switch(ch)
	{
		case 'a': return 0;
		case 'b': return 1;
		case 'c': return 2;
		case 'd': return 3;
		case 'e': return 4;
		case 'f': return 5;
		case 'g': return 6;
		case 'h': return 7;
		case 'i': return 8;
		case 'j': return 9;
		case 'k': return 10;
		case 'l': return 11;
		case 'm': return 12;
		case 'n': return 13;
		case 'o': return 14;
		case 'p': return 15;
		case 'q': return 16;
		case 'r': return 17;
		case 's': return 18;
		case 't': return 19;
		case 'u': return 20;
		case 'v': return 21;
		case 'w': return 22;
		case 'x': return 23;
		case 'y': return 24;
		case 'z': return 25;
	}
}

/*cmp byte[rdi+rbx],'a'
			je a
			cmp byte[rdi+rbx],'b'
			je b
			cmp byte[rdi+rbx],'c'
			je c
			cmp byte[rdi+rbx],'d'
			je d
			cmp byte[rdi+rbx],'e'
			je e
			cmp byte[rdi+rbx],'f'
			je f
			cmp byte[rdi+rbx],'g'
			je g
			cmp byte[rdi+rbx],'h'
			je h
			cmp byte[rdi+rbx],'i'
			je i
			cmp byte[rdi+rbx],'j'
			je j
			cmp byte[rdi+rbx],'k'
			je k
			cmp byte[rdi+rbx],'l'
			je l
			cmp byte[rdi+rbx],'m'
			je m
			cmp byte[rdi+rbx],'n'
			je n
			cmp byte[rdi+rbx],'o'
			je o
			cmp byte[rdi+rbx],'p'
			je p
			cmp byte[rdi+rbx],'q'
			je q
			cmp byte[rdi+rbx],'r'
			je r
			cmp byte[rdi+rbx],'s'
			je s
			cmp byte[rdi+rbx],'t'
			je t
			cmp byte[rdi+rbx],'u'
			je u
			cmp byte[rdi+rbx],'v'
			je v
			cmp byte[rdi+rbx],'w'
			je w
			cmp byte[rdi+rbx],'x'
			je x
			cmp byte[rdi+rbx],'y'
			je y
			cmp byte[rdi+rbx],'z'
			je z

			a:
				mov rax,0
				mov [ij],rax
				jmp sloop

			b:
				mov rax,1
				mov [ij],rax
				jmp sloop

			c:
				mov rax,2
				mov [ij],rax
				jmp sloop

			d:
				mov rax,3
				mov [ij],rax
				jmp sloop

			e:
				mov rax,4
				mov [ij],rax
				jmp sloop

			f:
				mov rax,5
				mov [ij],rax
				jmp sloop

			g:
				mov rax,6
				mov [ij],rax
				jmp sloop

			h:
				mov rax,7
				mov [ij],rax
				jmp sloop

			i:
				mov rax,8
				mov [ij],rax
				jmp sloop

			j:
				mov rax,9
				mov [ij],rax
				jmp sloop

			k:
				mov rax,10
				mov [ij],rax
				jmp sloop

			l:
				mov rax,11
				mov [ij],rax
				jmp sloop

			m:
				mov rax,12
				mov [ij],rax
				jmp sloop

			n:
				mov rax,13
				mov [ij],rax
				jmp sloop

			o:
				mov rax,14
				mov [ij],rax
				jmp sloop

			p:
				mov rax,15
				mov [ij],rax
				jmp sloop

			q:
				mov rax,16
				mov [ij],rax
				jmp sloop

			r:
				mov rax,17
				mov [ij],rax
				jmp sloop

			s:
				mov rax,18
				mov [ij],rax
				jmp sloop

			t:
				mov rax,19
				mov [ij],rax
				jmp sloop

			u:
				mov rax,20
				mov [ij],rax
				jmp sloop

			v:
				mov rax,21
				mov [ij],rax
				jmp sloop

			w:
				mov rax,22
				mov [ij],rax
				jmp sloop

			x:
				mov rax,23
				mov [ij],rax
				jmp sloop

			y:
				mov rax,24
				mov [ij],rax
				jmp sloop

			z:
				mov rax,25
				mov [ij],rax
				jmp sloop
*/