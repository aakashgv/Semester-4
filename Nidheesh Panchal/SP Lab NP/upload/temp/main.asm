extern add
extern printf
extern exit

global _start

section .data
	format db "%d", 10, 0
section .text

_start:
	mov rdi,2
	mov rsi,6
	call  add     ; add(2, 6)

	mov rsi,rax
	mov rdi,format
	call  printf  ; printf(format, eax)

	mov rdi,0
	call exit     ; exit(0)