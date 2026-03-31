assume CS:code, DS:data

data SEGMENT
tab DB 20, 5, 9, 5, 10, 12
N DB 6
min  DB ?
data ENDS

code segment
debut :
mov AX, data
mov DS, AX
xor si, si
xor dx, dx
xor ax, ax
xor bx, bx
xor cx, cx
mov Cl, N
mov bl, tab[SI]
boucle :
        mov al, tab[SI]
        cmp al, bl
        jle permutation 
        inc SI
        loop boucle
        cmp Cx, 0
        je fin_boucle
permutation :
             mov bl, al
             inc SI 
             loop boucle 

fin_boucle : 
             mov min, Bl  



mov ax, 4C00h
int 21h

code ends
    end debut

