Assume CS : Code, DS : Data

Data SEGMENT

    tab dw 160, 80, 40, 20, ?

Data ENDS

Code SEGMENT
  debut :

    mov AX, data
    mov DS, AX
    mov AX, tab[0]
    add AX, tab[2]
    add AX, tab[4]
    add AX, tab[6]
    mov tab[8], AX

    mov AX, 4C00h
    int 21h

Code ENDS
  end debut
