assume CS:code, DS:data

data SEGMENT
 tab dw 160, 80, 40, 20, ?
data ENDS

code segment
debut :
mov ax, DATA
mov DS, AX
mov ax, DS:[0000]
add ax, DS:[0001]
add ax, DS:[0002]
add ax, DS:[0003]
MOV DS:[0004], ax

mov ax, 4C00h
 int 21h

code ends
    end debut

