data segment
n1 db 09h
msg db 'prime $'
msg2 db ' not prime $'
data ends

code segment
assume CS:code, DS:data

start:
mov ax, data
mov ds, ax

mov cl, n1
dec cx
mov al, n1
mov bl, n1

l1: mov ah,00h 
div cl
cmp ah,00
jz notprime
mov al,bl
loop l1

mov ah,9
lea dx,msg
int 21h
jmp end

notprime:mov ah, 9
lea dx, msg2
int 21h

end:
mov ah, 4ch
int 21h

code ends
end start