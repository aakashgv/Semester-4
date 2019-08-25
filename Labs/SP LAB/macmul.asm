%macro multiplication 1

mov %1,edi

%endmacro

global mult
global check
global End

section .data

section .text
mult:
	mov eax,edi
	mov ebx,esi
	multiplication eax
	
check:

	add eax,edi
	dec ebx
	cmp ebx,1	
	jz End
	jmp check
End:
	ret
