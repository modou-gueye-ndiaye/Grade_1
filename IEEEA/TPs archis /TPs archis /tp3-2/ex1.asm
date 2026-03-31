assume CS:code, DS:data

data SEGMENT
 var1 db 169
 var2 db 5
 var3 db 13
 result db  ?
data ENDS

code segment
debut :
mov ax, data
mov DS, ax
mov al, var1
sub al, var2
add al, var3
add result, al
mov ax, 4C00h
 int 21h

code ends
    end debut

