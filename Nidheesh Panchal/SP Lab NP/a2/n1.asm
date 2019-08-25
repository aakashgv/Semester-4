SECTION .data

m1 db "THE FIRST NUMBER IS : ",0h
len1 equ $-m1
m2 db "THE SECOND NUMBER IS : ",0h
len2 equ $-m2
m3 db "THE THIRD NUMBER IS : ",0h
len3 equ $-m3
m4 db "THE LARGEST NUMBER IS : ",0h
len4 equ $-m4

n1 equ 24
n2 equ 100
n3 equ 43

;------------------------------------------------------------------------------------------------------------------------------------

SECTION .data
global _start

iprint:
push    eax            
push    ecx
push    edx
push    esi
mov     ecx, 0
 
divideLoop:
inc     ecx 
mov     edx, 0
mov     esi, 10       
idiv    esi          
add     edx, 48         
push    edx         
cmp     eax, 0        
jnz     divideLoop   
 
printLoop:
dec     ecx           
mov     eax, esp    
call    sprint      
pop     eax           
cmp     ecx, 0        
jnz     printLoop      
pop     esi             
pop     edx             
pop     ecx             
pop     eax             
ret

sprint:
push    edx
push    ecx
push    ebx
push    eax
call    slen
mov     edx, eax
pop     eax
mov     ecx, eax
mov     ebx, 1
mov     eax, 4
int     80h
pop     ebx
pop     ecx
pop     edx
ret

iprintLF:
call iprint
push eax;
mov eax, 0Ah
push eax
mov eax, esp
call sprint
pop eax
pop eax
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

;------------------------------------------------------------------------------------------------------------------------------------

_start:

mov eax,m1
call print
mov eax,n1
call iprintLF

mov eax,m2
call print
mov eax,n2
call iprintLF

mov eax,m3
call print
mov eax,n3
call iprintLF

mov eax,n1
mov ebx,n2
mov ecx,n3

cmp eax,ebx
jge test1
jle test2

test1:
cmp eax,ecx
jge answer1
jle answer3

test2:
cmp ebx,ecx
jge answer2
jle answer3

answer1:
mov eax,m4
call print
mov eax,n1
call iprint
jmp exitit

answer2:
mov eax,m4
call print
mov eax,n2
call iprint
jmp exitit

answer3:
mov eax,m4
call print
mov eax,n3
call iprint
jmp exitit

exitit:
mov eax,1
int 80h