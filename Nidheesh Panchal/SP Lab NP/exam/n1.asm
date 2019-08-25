extern add
extern printf
extern exit
extern atoi

global main

section .bss
i resb 64
n resb 64
j resb 64
section .data
	for db '%d',10,0
	format db "%c",10,0
	alph db 'a'
section .text

main:
	mov rcx, rdi 
    mov r8, 8   

    mov rdx, qword [rsi+r8]

push rdx
	push rcx
	push rsi
	push r8

	mov rdi,rdx
	call atoi
	mov [n],rax

	pop rdx
	pop rcx
	pop rsi
	pop r8

	push rdx
	push rcx
	push rsi
	push r8

	mov rsi,[n]
	mov rdi,for
	mov rax,0
	call  printf

	pop rdx
	pop rcx
	pop rsi
	pop r8

mov rax,[n]
dec rax
mov [n],rax

mov rax,1
mov [i],rax

loop1:
	mov rax,[n]
	inc rax
	inc rax
	cmp [i],rax
	je exitit

	mov rax,[i]
	mov [j],rax

;	mul rax,2
;	sub rax,1
;	mov [j],rax
	
	mov rbx,'a'

	loop2:
		mov rax,0
		cmp [j],rax
		je next

		push rdx
		push rcx
		push rsi
		push r8

		mov rsi,rbx
		mov rdi,format
		mov rax,0
		call  printf

		pop rdx
		pop rcx
		pop rsi
		pop r8

		mov rax,[n]
		add rbx,rax

		cmp rax,122
		cmp rbx,rax

		skip:
		
		mov rax,[j]
		dec rax
		mov [j],rax
		jmp loop2

	next :
		mov rax,[i]
		dec rax
		mov [j],rax
		mov rax,[n]
		sub rbx,rax
		sub rbx,rax

	loop3:
		mov rax,0
		cmp [j],rax
		je outside

		push rdx
		push rcx
		push rsi
		push r8

		mov rsi,rbx
		mov rdi,format
		mov rax,0
		call  printf

		pop rdx
		pop rcx
		pop rsi
		pop r8

		mov rax,[n]
		sub rbx,rax

		mov rax,97
		cmp rbx,rax

		skip2:

		mov rax,[j]
		dec rax
		mov [j],rax
		jmp loop3	

	outside:
		mov rax,[i]
		inc rax
		mov [i],rax
		jmp loop1

exitit:
	mov rax,1
	mov rbx,0
	int 80h