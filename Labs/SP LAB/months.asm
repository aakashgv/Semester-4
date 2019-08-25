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
global BigMonth
global SmallMonth
global FebMonth
global EndCheck

section .data
    	msg1	db	"31 Days", 10
    	lenmsg1	equ	$-msg1
    	msg2	db	"30 Days", 10
    	lenmsg2	equ	$-msg2
    	msg3	db	"28 or 29 Days", 10
    	lenmsg3	equ	$-msg3


	


section .text

Case1:
	mov eax,edi
	mov ebx,1
	cmp eax,ebx
	JNZ Case2
	JMP BigMonth

Case2:	
	mov ebx,2
	cmp eax,ebx
	JNZ Case3
	JMP FebMonth

Case3:
	mov ebx,3
	cmp eax,ebx
	JNZ Case4
	JNS BigMonth

	
Case4:	
	mov ebx,4
	cmp eax,ebx
	JNZ Case5
	JNS SmallMonth

Case5:	
	mov ebx,5
	cmp eax,ebx
	JNZ Case6
	JNS BigMonth
	
Case6:	
	mov ebx,6
	cmp eax,ebx
	JNZ Case7
	JNS SmallMonth
	
Case7:	
	mov ebx,7
	cmp eax,ebx
	JNZ Case8
	JNS BigMonth
	
Case8:	
	mov ebx,8
	cmp eax,ebx
	JNZ Case9
	JNS BigMonth
	
Case9:	
	mov ebx,9
	cmp eax,ebx
	JNZ Case10
	JNS SmallMonth
	
Case10:	
	mov ebx,10
	cmp eax,ebx
	JNZ Case11
	JNS BigMonth
	
Case11:	
	mov ebx,11
	cmp eax,ebx
	JNZ Case12
	JNS SmallMonth
	
Case12:	
	mov ebx,4
	cmp eax,ebx
	JNS BigMonth		
	
	
	
BigMonth:	;Code for 31
	mov eax, 4
	mov ebx, 1
	mov ecx, msg1
	mov edx, lenmsg1
	int 0x80
	JMP EndCheck
	
	
	
SmallMonth:	;Code for 30
	mov eax, 4
	mov ebx, 1
	mov ecx, msg2
	mov edx, lenmsg2
	int 0x80
	JMP EndCheck
	
	
FebMonth:	;Code for Feb
	mov eax, 4
	mov ebx, 1
	mov ecx, msg3
	mov edx, lenmsg3
	int 0x80
	JMP EndCheck
	
EndCheck:
	ret


	
