DATA SEGMENT
NUM1 DB 05h
NUM2 DB 02h
NUM3 DB 07h
LRGT DB ?
data ENDS

CODE SEGMENT
ASSUME DS:DATA, CS:CODE
START:

MOV AX,DATA
MOV DS,AX

MOV AL,NUM1
MOV LRGT,AL

CMP AL,NUM2
JGE SKIP1

MOV AL,NUM2
MOV LRGT,AL
SKIP1:
MOV AL,LRGT
CMP AL,NUM3
JGE SKIP2
MOV AL,NUM3
MOV LRGT,AL
SKIP2:

MOV AL, LRGT

ADD AL,30h
MOV DL,AL

MOV AH,02h
INT 21h

MOV AH,4CH
INT 21H

code ENDS
END START