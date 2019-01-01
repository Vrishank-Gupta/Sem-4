data segment
n1 db 09h
n2 db 09h 
data ends

code segment
assume cs:code, ds:data
start:

mov ax,data
mov ds,ax

mov al,n1
mov bl,n2
add al,bl

daa
mov ah,00h
mov dl,10h
div dl
add ah,30h
add al,30h
mov dl,al
mov dh,ah

mov ah,02h
int 21h

mov dl,dh
mov ah,02h
int 21h

mov ah,4ch
int 21h

code ends
end start