section .data
m1 db "The factorial of the number is : ",0h
len equ $-m1

n1 equ 5
res equ 1

section .text
global _start

iprint:
push eax            
push ecx
push edx
push esi
mov ecx, 0
 
divideLoop:
inc ecx 
mov edx, 0
mov esi, 10       
idiv esi          
add edx, 48         
push edx         
cmp eax, 0        
jnz divideLoop   
 
printLoop:
dec ecx           
mov eax, esp    
call sprint      
pop eax           
cmp ecx, 0        
jnz printLoop      
pop esi             
pop edx             
pop ecx             
pop eax             
ret

sprint:
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

iprintLF:
call iprint
push eax
mov eax, 0Ah
push eax
mov eax, esp
call sprint
pop eax
pop eax
ret

;-----------------------------------------------------------------------------------

factorial:

cmp eax,1
je exitit
mov ecx,eax
mov edx,ebx
call multiply
dec eax
jmp factorial

multiply:

cmp ecx,1
jg mul
ret

mul:

add ebx,edx
dec ecx
jmp multiply

_start:

mov edx,len
mov ecx,m1
mov ebx,1
mov eax,4
int 80h

mov eax,n1
mov ebx,res
mov ecx,eax
mov edx,eax

call factorial

exitit:
mov eax,ebx
call iprintLF
mov eax,1
int 80h