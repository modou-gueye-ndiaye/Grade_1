Assume CS : Code, DS : Data

data segment
    var1 dw 169
    var2 dw 5
    var3 dw 13
    result dw ?

data ends

code segment
  debut :

    mov AX, data
    mov DS, AX

    mov AX, var1
    mov BX, var2
    mov CX, var3
    SUB AX, BX
    add AX, CX
    mov result, AX

    mov AX, 4C00h
    int 21h

code ends
  end debut
