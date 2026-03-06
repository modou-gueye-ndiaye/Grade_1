Assume CS : Code, DS : Data

Data SEGMENT

    tab dw 120, 60, 30, 15

Data ENDS

Code SEGMENT
  debut :

    mov AX, data
    mov DS, AX

    mov AX, DS:0000
    mov BX, DS:0001
    mov CX, DS:0002
    mov DX, DS:0003
    add AX, BX
    add AX, CX
    add AX, DX
    mov DS:0008, AX

  mov AX, 4C00h
  int 21h

Code ENDS
  end debut
