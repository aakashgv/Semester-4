extern printf
extern atoi

section .data
for db "%d",10,0
;arr dq 0,1,2

section .bss
i resq 1
arr resq 26

global main

section .text:

main:
	mov r8,8
	mov rcx,rdi

	;mov rdx,qword[rsi+8]
	mov qword[arr+16],12
	mov rdx,qword[arr+16]

	push rcx 
    push rdx
    push rsi
    push r8

	mov rdi,for
	mov rsi,rdx
	mov rax,0
	call printf

	pop r8 
    pop rsi
    pop rdx
    pop rcx

exit:
	mov rax,1
	mov rbx,0
	int 80h