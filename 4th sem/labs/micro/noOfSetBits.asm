data segment
n1 db 0FFh
n2 db ?
data ends

code segment
assume CS:code, DS:data
start:
mov ax, data
mov ds, ax

mov cl, 08h

mov al, n1

l1: rcl al,1
jc yes
cont:
loop l1
jmp out


yes:inc n2
jmp cont

out:mov al, n2
add al, 30h
mov dl,al
mov ah, 02h
int 21h


end:
mov ah, 4ch
int 21h

code ends
end start