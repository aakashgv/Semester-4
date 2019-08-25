extern exit
extern atoi
extern printf
extern check

section .data
for db '%d',10,0
format db '%s',10,0

section .bss
count resq 26
ij resq 1
trans resb 1

section .text

global main

main:
	mov rcx,rdi
	mov r8,8

		mov rdx,qword[rsi+r8]

		push rdx
			push rcx
			push rsi
			push r8

			mov rdi,format
			mov rsi,rdx
			mov rax,0
			call printf

			pop r8
			pop rsi
			pop rcx
			pop rdx

		mov r9,0
		
		loop:			

			cmp r9,40
			je exitit

			cmp byte[rdx+r9],'a'
			je a
			cmp byte[rdx+r9],'b'
			je b
			cmp byte[rdx+r9],'c'
			je c
			cmp byte[rdx+r9],'d'
			je d
			cmp byte[rdx+r9],'e'
			je e
			cmp byte[rdx+r9],'f'
			je f
			cmp byte[rdx+r9],'g'
			je g
			cmp byte[rdx+r9],'h'
			je h
			cmp byte[rdx+r9],'i'
			je i
			cmp byte[rdx+r9],'j'
			je j
			cmp byte[rdx+r9],'k'
			je k
			cmp byte[rdx+r9],'l'
			je l
			cmp byte[rdx+r9],'m'
			je m
			cmp byte[rdx+r9],'n'
			je n
			cmp byte[rdx+r9],'o'
			je o
			cmp byte[rdx+r9],'p'
			je p
			cmp byte[rdx+r9],'q'
			je q
			cmp byte[rdx+r9],'r'
			je r
			cmp byte[rdx+r9],'s'
			je s
			cmp byte[rdx+r9],'t'
			je t
			cmp byte[rdx+r9],'u'
			je u
			cmp byte[rdx+r9],'v'
			je v
			cmp byte[rdx+r9],'w'
			je w
			cmp byte[rdx+r9],'x'
			je x
			cmp byte[rdx+r9],'y'
			je y
			cmp byte[rdx+r9],'z'
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

			sloop:
				mov rax,[ij]

				push rbx
				mov rbx,qword[count+rax]				

				inc rbx
				mov qword[count+rax],rbx
				mov rbx,qword[count+rax]

				pop rbx

			inc r9
			jmp loop

exitit:
	mov r8,0

	pr:

	mov rax,qword[count+7]

	

	push rdx
	push rcx
	push rsi
	push r8

		mov rdi,for
		mov rsi,rax
		mov rax,0
		call printf

	pop r8
	pop rsi
	pop rcx
	pop rdx

	out:
		mov rax,1
		mov rbx,0
		int 80h