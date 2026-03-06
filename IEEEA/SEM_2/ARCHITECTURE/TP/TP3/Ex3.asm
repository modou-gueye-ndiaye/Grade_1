Assume CS : Code, DS : Data

Data SEGMENT

    tab db 120, 60, 30, 15
    result db ?

Data ENDS

Code SEGMENT
  debut :

    mov AX, data
    mov DS, AX

    mov AL, tab[0]
    add AL, tab[1]
    add AL, tab[2]
    add AL, tab[3]
    mov result, AL

    mov AX, 4C00h
    int 21h

Code ENDS
  end debut
