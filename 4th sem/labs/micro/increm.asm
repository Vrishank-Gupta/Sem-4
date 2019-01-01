data segment
n1 db 03h
data ends

code segment
assume cs:code, ds:data
start:

mov ax,data
mov ds,ax
mov cx,05h
mov al,n1

l1:

inc al
loop l1

add al,30h
mov dl,al

mov ah,02h
int 21h

mov ah,4ch
int 21h

code ends
end start