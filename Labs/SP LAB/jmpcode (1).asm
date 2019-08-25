global sum
global elseIfZero
global elsePos
global endCheck

section .data
    	msg1	db	"Given input is Negative", 10
    	lenmsg1	equ	$-msg1
    	msg2	db	"Given input is zero", 10
    	lenmsg2	equ	$-msg2
    	msg3	db	"Given input is Positive", 10
    	lenmsg3	equ	$-msg3


	


section .text

sum:
	mov eax,edi
	mov ebx,0
	cmp eax,ebx
	JNS elseIfZero  ;jump if eax is not negative
	mov eax, 4
	mov ebx, 1
	mov ecx, msg1	;Code for negative
	mov edx, lenmsg1
	int 0x80
	JMP endCheck
	
elseIfZero:	;Code for zero
	JNZ elsePos	;j,p if x is not zero
	mov eax, 4
	mov ebx, 1
	mov ecx, msg2
	mov edx, lenmsg2
	int 0x80
	JMP endCheck
	
	
elsePos:	;Code for positive
	mov eax, 4
	mov ebx, 1
	mov ecx, msg3
	mov edx, lenmsg3
	int 0x80


endCheck:
	ret
	
