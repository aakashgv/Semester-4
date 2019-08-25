extern exit
extern atoi
extern printf
extern check

section .data
for db '%d',10,0
format db '%c',10,0

section .bss
count resq 26
ij resq 1
trans resb 1

section .text

global _start

_start:
	mov rcx,rdi
	mov r8,8

	push rdx
		push rcx
		push rsi
		push r8

		mov rdi,rcx
		call atoi

		pop r8
		pop rsi
		pop rcx
		pop rdx

		mov rcx,rax
	
	push rdx
		push rcx
		push rsi
		push r8

		mov rdi,for
		mov rsi,rcx
		mov rax,0
		call printf

		pop r8
		pop rsi
		pop rcx
		pop rdx

	repeat:
		cmp qword[rsi+r8],0
		je exitit

		mov rdx,qword[rsi+r8]

		mov rbx,0
		
		loop:
			cmp byte[rdi+rbx],0
			je end

			movzx r9,byte[rdi+rbx]
			mov [trans],r9

			push rdx
			push rcx
			push rbx
			push rax
			push rsi
			push r8

			mov rdx,[trans]
			call check
			mov [ij],rax

			pop r8
			pop rsi
			pop rax
			pop rbx
			pop rcx
			pop rdx

			sloop:
				mov rax,[ij]
				push rbx
				mov rbx,qword[count+rax]
				inc rbx
				mov qword[count+rax],rbx
				pop rbx
				inc rbx
				jmp loop

		end:
			inc rcx
			add r8,8
			jmp repeat

exitit:
		mov r8,0
	pr:
		cmp r8,228
		jz out
		mov rbx,qword[count+r8]
		cmp rbx,0
		jnz go
		push rdx
		push rcx
		push rsi
		push r8

		mov rdi,for
		mov rsi,rbx
		mov rax,0
		call printf

		pop r8
		pop rsi
		pop rcx
		pop rdx

		go:
			add r8,8
			jmp pr

	out:
		mov rax,1
		mov rbx,0
		int 80h