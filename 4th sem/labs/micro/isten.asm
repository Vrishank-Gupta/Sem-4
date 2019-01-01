data SEGMENT
msg1 DB 'Input value is not equal to 10 $'
msg2 DB 'Input value is equal to 10 $'
num DB 08h
data ENDS

code SEGMENT
assume CS:code, DS:data
start:

MOV AX,data
MOV DS,AX

MOV AL,num


if:
CMP AL, 0ah
JE else

MOV AH, 9
LEA DX, msg1 
INT 21h

JMP endif

else:

MOV AH, 9
LEA DX, msg2
INT 21h

endif:


MOV AH,4ch
INT 21h

code ENDS
END start