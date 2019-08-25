section .data

msg	db 'Enter number 1 : ',0ah,0h

msg1 db 'Enter number 2 : ',0ah,0h

menu1 db '1. ADD',0ah

menu2 db '2. SUBTRACT',0ah

menu3 db '3. MULTIPLY',0ah

menu4 db '4. DIVIDE',0ah

menu5 db '5. EXIT',0ah

ch1 db 'Enter your choice or any other number to exit : ',0h

;-----------------------------------------------------------------------

section .bss

num1 resb 1
num2 resb 1
choice resb 1

;------------------------------------------------------------------------

section .text
global _start

;------------------------------------------------------------------------

atoi:
    push    ebx             ; preserve ebx on the stack to be restored after function runs
    push    ecx             ; preserve ecx on the stack to be restored after function runs
    push    edx             ; preserve edx on the stack to be restored after function runs
    push    esi             ; preserve esi on the stack to be restored after function runs
    mov     esi, eax        ; move pointer in eax into esi (our number to convert)
    mov     eax, 0          ; initialise eax with decimal value 0
    mov     ecx, 0          ; initialise ecx with decimal value 0
 
.multiplyLoop:
    xor     ebx, ebx        ; resets both lower and uppper bytes of ebx to be 0
    mov     bl, [esi+ecx]   ; move a single byte into ebx register's lower half
    cmp     bl, 48          ; compare ebx register's lower half value against ascii value 48 (char value 0)
    jl      .finished       ; jump if less than to label finished
    cmp     bl, 57          ; compare ebx register's lower half value against ascii value 57 (char value 9)
    jg      .finished       ; jump if greater than to label finished
    cmp     bl, 10          ; compare ebx register's lower half value against ascii value 10 (linefeed character)
    je      .finished       ; jump if equal to label finished
    cmp     bl, 0           ; compare ebx register's lower half value against decimal value 0 (end of string)
    jz      .finished       ; jump if zero to label finished
 
    sub     bl, 48          ; convert ebx register's lower half to decimal representation of ascii value
    add     eax, ebx        ; add ebx to our interger value in eax
    mov     ebx, 10         ; move decimal value 10 into ebx
    mul     ebx             ; multiply eax by ebx to get place value
    inc     ecx             ; increment ecx (our counter register)
    jmp     .multiplyLoop   ; continue multiply loop
 
.finished:
    mov     ebx, 10         ; move decimal value 10 into ebx
    div     ebx             ; divide eax by value in ebx (in this case 10)
    pop     esi             ; restore esi from the value we pushed onto the stack at the start
    pop     edx             ; restore edx from the value we pushed onto the stack at the start
    pop     ecx             ; restore ecx from the value we pushed onto the stack at the start
    pop     ebx             ; restore ebx from the value we pushed onto the stack at the start
    ret

;------------------------------------------------------------------------

slen:
push ebx
mov ebx, eax
 
nextchar:
cmp byte [eax], 0
jz finished
inc eax
jmp nextchar

finished:
sub eax, ebx
pop ebx
ret

;------------------------------------------------------------------------

print:

push edx
push ecx
push ebx
push eax
call slen

mov edx, eax
pop eax

mov ecx, eax
mov ebx, 1
mov eax, 4
int 80h

pop ebx
pop ecx
pop edx
ret

;-----------------------------------------------------------------------

addition:

push edx
push ebx
push ecx
push eax

mov eax,
mov ebx,

add eax,ebx

mov edx, 1
mov ecx, eax
mov ebx, 1
mov eax, 4
int 80h

pop eax
pop ecx
pop ebx
pop edx

jmp start

;-----------------------------------------------------------------------

subtraction:
push edx
push ebx
push ecx
push eax

mov eax,num1
call print

mov eax,num2
call print

pop edx
pop ebx
pop ecx
pop eax

jmp start

;-----------------------------------------------------------------------

multiplication:
push edx
push ebx
push ecx
push eax

mov eax,num1
call print

mov eax,num2
call print

pop edx
pop ebx
pop ecx
pop eax

jmp start

;-----------------------------------------------------------------------

division:
push edx
push ebx
push ecx
push eax

mov eax,num1
call print

mov eax,num2
call print

pop edx
pop ebx
pop ecx
pop eax

jmp start

;-----------------------------------------------------------------------

switch:

push edx
push ebx
push ecx
push eax

cmp byte[eax],49
jz addition

cmp byte[eax],50
jz subtraction

cmp byte[eax],51
jz multiply

cmp byte[eax],52
jz division

call quit

;------------------------------------------------------------------------

input:
push edx
push ecx
push ebx
push eax

pop eax

mov edx,255
mov ecx,eax
mov ebx,0
mov eax,3
int 80h

pop ebx
pop ecx
pop edx
ret

;------------------------------------------------------------------------

quit:

mov ebx,0
mov eax,1
int 80h
ret

;------------------------------------------------------------------------

_start:

start:

mov eax,msg
call print
mov eax,num1
call input

mov eax,msg1
call print
mov eax,num2
call input

mov eax,menu1
call print

mov eax,choice
call input

mov eax,choice
call switch

call quit