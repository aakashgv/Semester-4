extern add
extern printf
extern exit

global _start

section .data
  format db "%d", 10, 0
  
section .text

_start:
;    push  6
    mov rdi,6
    mov rsi,2
;    push  2
    call  add     ; add(2, 6)

;    push  eax
;    push  format
    mov rdi,format
;    mov rsi
    call  printf  ; printf(format, eax)

    mov rsi,0
    call exit     ; exit(0)