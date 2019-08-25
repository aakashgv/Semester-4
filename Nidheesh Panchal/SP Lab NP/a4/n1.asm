extern printf
extern atoi

section .data

for: db '%d',10,0

section .bss
i resb 64
n resb 64
sum resb 64

section .text

global main

main:
    mov rcx, rdi 
    mov r8, 8   

    mov rdx, qword [rsi+r8]

push rdx
push rcx
push rsi
push r8

    mov rdi,rdx
    call  atoi
    mov [i],rax
    
pop r8
pop rsi
pop rcx
pop rdx

add r8,8

    mov rdx, qword [rsi+r8]

push rdx
push rcx
push rsi
push r8

    mov rdi,rdx
    call  atoi
    mov [n],rax
    
pop r8
pop rsi
pop rcx
pop rdx


mov ebx,1
mov [sum],ebx
mov ecx,[sum]

mov edx,[n]
mov ecx,[sum]

repeat:
	mov eax,[i]
	cmp eax,[n]
	jg exit
	mov ebx,[i]
	mul ebx
	mov ebx,[sum]
	mul ebx
	mov [sum],eax
	mov eax,[i]
	inc eax
	mov [i],eax
	jmp repeat

exit:

push rdx
push rcx
push rsi
push r8

    mov rdi,for
    mov rsi,[sum]
    mov rax,0
    call  printf
    
pop r8
pop rsi
pop rcx
pop rdx

    mov rax, 1         
    mov rbx, 0
    int 80h