assume CS:code, DS:data

data SEGMENT
 tab1 db 120, 60, 30, 15
 result db ?
data ENDS

code segment
debut :

mov ax, data
mov DS, ax
mov al, DS:[0000]
add DS:[0004], al
mov al, DS:[0001]
add DS:[0004], al
mov al, DS:[0002]
add DS:[0004], al
mov al, DS:[0003]
add DS:[0004], al

mov ax, 4C00h
 int 21h

code ends
    end debut

