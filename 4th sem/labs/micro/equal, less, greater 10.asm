data SEGMENT
msg DB 'input value is less than 10 $'
msg2 DB 'input value is greater than 10 $'
msg3 DB 'input value is equal to 10 $'
n1 DB 0Ch
data ENDS

code SEGMENT
assume CS:code, DS:data
start:

MOV AX,data
MOV DS,AX

MOV AL,n1

CMP AL, 0Ah
JE EQUAL

JMP NOTEQUAL

EQUAL:
MOV AH, 9
LEA DX, msg3
INT 21h
JMP END:

NOTEQUAL:
JC LESSTHAN

MOV AH, 9
LEA DX, msg2 
INT 21h
JMP END
 
LESSTHAN:
MOV AH, 9   
LEA DX, msg 
INT 21h

END:

MOV AH,4ch
INT 21h

code ENDS
END start