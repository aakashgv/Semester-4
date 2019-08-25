extern try
extern printf
extern atoi

section .data
for db "%s",10,0
t db "Abd"

section .bss
a resb 64
b resb 64
text resq 1

section .text

global main

main:
	mov r8,8
	
	mov rdx,qword[rsi+r8]

	mov r9,1

	cmp byte[rdx+r9],'a'
	jne exit

	mov rdi,for
	mov rsi,t
	mov rax,0
	call printf

	exit:

	mov rax,1
	mov rbx,0

	int 80h