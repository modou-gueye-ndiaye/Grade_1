assume CS:code, DS:data

data SEGMENT
 tab1 db 120, 60, 30, 15
 result db ?
data ENDS

code segment
debut :

mov ax, data
mov DS, ax
mov al, tab1[0]
add result, al
mov al, tab1[1]
add result, al
mov al, tab1[2]
add result, al
mov al, tab1[3]
add result, al

mov ax, 4C00h
 int 21h

code ends
    end debut

