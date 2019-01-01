data SEGMENT
a DB 0efh
b DB 01fh
caff DB 'Carry flag =1 i.e. affected.$'
cnotaff DB 'Carry flag not affected. $'
oaff DB 'overflow flag =1 i.e. affected.$'
onotaff DB 'overflow not affected.$'
data ENDS

code SEGMENT
	assume CS:code,DS:data
	start:
		MOV AX,data
		MOV DS,AX
		MOV AL,a
		MOV BL,b
		SUB AL,BL
		JO oa
		JNO ona
	oa:
		MOV AH,09h
		LEA DX,oaff
		INT 21h
		JC ca
		JNC cna
	ona:
		MOV AH,09h
		LEA DX,onotaff
		INT 21h
		JC ca
		JNC cna

	ca:
		MOV AH,09h
		LEA DX,cnotaff
		INT 21h

	cna:
		MOV AH,09h
		LEA DX,cnotaff
		INT 21h

	endit:
		MOV AH,4ch
		INT 21h

code ENDS
END start
