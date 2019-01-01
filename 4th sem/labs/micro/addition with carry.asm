data SEGMENT
n1 DB 81h
n2 DB 80h 
cfMask EQU 01h
data ENDS

code SEGMENT
assume CS:code, DS:data
start:

MOV AX,data
MOV DS,AX

MOV AL,n1
MOV BL,n2
ADD AL,BL
mov bl,al


LAHF ; Loads contents of flag register into ah

           AND AH, cfMask ; Check if CF is set or not by anding it with 1

           MOV DL, AH
           ADD DL, 30h 
           MOV AH, 02h           
           INT 21h

	   MOV AL,BL
           MOV DL, AL
           ADD DL, 30h 
           MOV AH, 02h           
           INT 21h

           MOV AH, 04ch
           INT 21h

code ENDS
END start