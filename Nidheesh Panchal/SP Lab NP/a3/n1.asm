extern printf
extern atoi

section .data

format: db '%s', 10, 0
for: db '%d',10,0

section .bss
i resb 64
j resb 64
n resb 64
res resb 64
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
    mov ebx,[i]
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
    mov [j],rax
    
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

mov ebx,[i]
mov ecx,[j]
mov edx,[n]

mov rdx,0
mov ebx,0
mov [sum],ebx

repeat:
mov eax,[n]
inc eax
cmp eax,[i]
jz exit
mov eax,[i]
mov ebx,[j]
mul ebx
mov ebx,[sum]
add eax,ebx
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