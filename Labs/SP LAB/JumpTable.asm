global cond

SECTION .data

	msg1 : db  '%d Januaru',10,0
	msg2 : db  '%d February',10,0
	msg3 : db  '%d March',10,0
	msg4 : db  '%d April',10,0
	msg5 : db  '%d May',10,0
	msg6 : db  '%d June',10,0
	msg7 : db  '%d July',10,0
	msg8 : db  '%d August',10,0
	msg9 : db  '%d September',10,0
	msg10 : db '%d October',10,0
	msg11 : db '%d November',10,0
	msg12 : db '%d December',10,0
	msg13 : db '%d Invalid',10,0

SECTION .text
	global cond
	extern printf

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

cond:
	push ebp
	mov ebp,esp
	
	mov eax,[ebp+8]
	JMP [months+eax*4]
	
Case1:
	push eax
	push msg1
	call printf
	JMP endcheck
Case2:
	push eax
	push msg2
	call printf
	JMP endcheck
Case3:
	push eax
	push msg3
	call printf
	JMP endcheck
Case4:
	push eax
	push msg4
	call printf
	JMP endcheck
Case5:
	push eax
	push msg5
	call printf
	JMP endcheck
Case6:
	push eax
	push msg6
	call printf
	JMP endcheck
Case7:
	push eax
	push msg7
	call printf
	JMP endcheck
Case8:
	push eax
	push msg8
	call printf
	JMP endcheck
Case9:
	push eax
	push msg9
	call printf
	JMP endcheck
Case10:
	push eax
	push msg10
	call printf
	JMP endcheck
Case11:
	push eax
	push msg11
	call printf
	JMP endcheck
Case12:
	push eax
	push msg12
	call printf
	JMP endcheck
	
Invalid:
	push eax
	push msg13
	call printf
	
endcheck:

	add esp,8
	mov esp,ebp
	pop ebp
	ret
	


