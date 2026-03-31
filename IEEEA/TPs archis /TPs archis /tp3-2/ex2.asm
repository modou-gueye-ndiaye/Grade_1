assume CS:code, DS:data

data SEGMENT
 var1 dw 169
 var2 dw 5
 var3 dw 13
 result dw  ?
data ENDS

code segment
debut :
mov ax, data
mov DS, ax
mov ax, var1
sub ax, var2
add ax, var3
add result, ax
mov ax, 4C00h
 int 21h

code ends
    end debut

