assume CS:code, DS:data

data SEGMENT
N db 4
len db 7
tab db 12, 4, 3, 9, 5, 21, 16
res db ?
data ENDS

code segment
debut :
mov ax, data
mov ds, ax
xor si, si
xor dx, dx
xor ax, ax
xor bx, bx
xor cx, cx
xor dx, dx
mov bl, N
mov cl, len

boucle :
       xor ax, ax
       mov Al, tab[si]
       div Bl
       cmp ah, 0
       je suivant
       inc si
       cmp si, 7
       je fin_boucle
       loop boucle

suivant :
       add Dl, 1
       Inc si
       cmp Cl, 0
       je fin_boucle
       loop boucle
fin_boucle :
           mov res, Dl
mov ax, 4C00h
 int 21h

code ends
    end debut

