data SEGMENT
msg DB 'numbers are not equal $'
msg2 DB 'numbers are equal  $'
n1 DB 07h
n2 DB 07h
data ENDS

code SEGMENT
assume CS:code, DS:data
start:

MOV AX,data
MOV DS,AX

MOV BL,n1
MOV CL,n2

if:
CMP BL,CL
JE else

MOV AH, 9
LEA DX, msg 
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