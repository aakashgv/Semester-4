extern printf
extern atoi

section .data

format: db '%s', 10, 0
for: db '%d',10,0

section .bss
i resb 64
x resb 64
n resb 64
y resb 64
z resb 64

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
    mov [n],rax
pop r8
pop rsi
pop rcx
pop rdx

mov edx,[n]

mov rdx,0

mov ebx,3
mov [i],ebx
mov ebx,1
mov [x],ebx
mov ebx,1
mov [y],ebx
mov ebx,0
mov [z],ebx

    push rdx
    push rcx
    push rsi
    push r8

    mov rdi,for
    mov rsi,[x]
    mov rax,0
    call  printf

    mov rdi,for
    mov rsi,[y]
    mov rax,0
    call  printf
    
    pop r8
    pop rsi
    pop rcx
    pop rdx

fib:
    mov edx,[i]
    cmp edx,[n]
    jg exit
    mov eax,[x]
    mov ebx,[y]
    add eax,ebx
    mov [z],eax

    push rdx
    push rcx
    push rsi
    push r8

    mov rdi,for
    mov rsi,[z]
    mov rax,0
    call  printf
    
    pop r8
    pop rsi
    pop rcx
    pop rdx

    inc edx
    mov [i],edx
    mov ebx,[y]
    mov [x],ebx
    mov ebx,[z]
    mov [y],ebx
    jmp fib


exit:

    mov rax, 1         
    mov rbx, 0
    int 80h