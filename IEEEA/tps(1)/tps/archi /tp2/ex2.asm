assume CS:code, DS:data

data SEGMENT
    a db  1
    b dw  2
    c db 103
    d db 69
data ENDS

code segment
debut :
    mov AX, data
    mov DS, AX
    mov AH, 9
    int 21h
    mov ax, 4C00h
    int 21h

code ends
    end debut

