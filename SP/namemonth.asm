global Cond
global Case1
global Case2
global Case3
global Case4
global Case5
global Case6
global Case7
global Case8
global Case9
global Case10
global Case11
global Case12
global Invalid
global EndCheck

section .data
    	msg1	db	"January", 10
    	lenmsg1	equ	$-msg1
    	msg2	db	"February", 10
    	lenmsg2	equ	$-msg2
    	msg3	db	"March", 10
    	lenmsg3	equ	$-msg3
    	msg4	db	"April", 10
    	lenmsg4	equ	$-msg4
    	msg5	db	"May", 10
    	lenmsg5	equ	$-msg5
    	msg6	db	"June", 10
    	lenmsg6	equ	$-msg6
    	msg7	db	"July", 10
    	lenmsg7	equ	$-msg7
    	msg8	db	"August", 10
    	lenmsg8	equ	$-msg8
    	msg9	db	"September", 10
    	lenmsg9	equ	$-msg9
    	msg10	db	"October", 10
    	lenmsg10	equ	$-msg10
    	msg11	db	"November", 10
    	lenmsg11	equ	$-msg11
    	msg12	db	"December", 10
    	lenmsg12	equ	$-msg12
       	msg13	db	"Invalid", 10
    	lenmsg13	equ	$-msg13


	


section .text

months:
	dd Invalid
	dd Case1
	dd Case2
	dd Case3
	dd Case4
	dd Case5
	dd Case6
	dd Case7
	dd Case8
	dd Case9
	dd Case10
	dd Case11
	dd Case12

Cond:
	mov eax,edi
	JMP [months+eax]

Case1:
	mov eax, 4
	mov ebx, 1
	mov ecx, msg1
	mov edx, lenmsg1
	int 0x80
	JMP EndCheck
	
	

Case2:	

	mov eax, 4
	mov ebx, 1
	mov ecx, msg2
	mov edx, lenmsg2
	int 0x80
	JMP EndCheck

Case3:

	mov eax, 4
	mov ebx, 1
	mov ecx, msg3
	mov edx, lenmsg3
	int 0x80
	JMP EndCheck

	
Case4:	

	mov eax, 4
	mov ebx, 1
	mov ecx, msg4
	mov edx, lenmsg4
	int 0x80
	JMP EndCheck

Case5:	

	mov eax, 4
	mov ebx, 1
	mov ecx, msg5
	mov edx, lenmsg5
	int 0x80
	JMP EndCheck
	
Case6:	

	mov eax, 4
	mov ebx, 1
	mov ecx, msg6
	mov edx, lenmsg6
	int 0x80
	JMP EndCheck
	
Case7:	

	mov eax, 4
	mov ebx, 1
	mov ecx, msg7
	mov edx, lenmsg7
	int 0x80
	JMP EndCheck
	
Case8:	

	mov eax, 4
	mov ebx, 1
	mov ecx, msg8
	mov edx, lenmsg8
	int 0x80
	JMP EndCheck
	
Case9:	

	mov eax, 4
	mov ebx, 1
	mov ecx, msg9
	mov edx, lenmsg9
	int 0x80
	JMP EndCheck
	
Case10:	

	mov eax, 4
	mov ebx, 1
	mov ecx, msg10
	mov edx, lenmsg10
	int 0x80
	JMP EndCheck
	
Case11:	
	mov ebx,11
	cmp eax,ebx
	JNZ Case12
	mov eax, 4
	mov ebx, 1
	mov ecx, msg11
	mov edx, lenmsg11
	int 0x80
	JMP EndCheck
	
Case12:	
	mov ebx,4
	cmp eax,ebx
	mov eax, 4
	mov ebx, 1
	mov ecx, msg12
	mov edx, lenmsg12
	int 0x80
	JMP EndCheck

Invalid:
	mov eax, 4
	mov ebx, 1
	mov ecx, msg13
	mov edx, lenmsg13
	int 0x80
	JMP EndCheck		
	
	
	
EndCheck:
	ret


	
