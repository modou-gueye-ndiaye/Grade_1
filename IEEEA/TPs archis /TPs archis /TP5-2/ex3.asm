assume CS:code, DS:data

data SEGMENT
tab DB 20, 5, 9, 5, 10, 12
N DB 6
seuil DB 10
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
mov Bl, seuil

boucle :
        mov Al, tab[SI] 
        cmp Al, bl
        je permutation 
        inc SI
        loop boucle 
        cmp CX, 0 
        je fin_boucle 

permutation :
             mov tab[SI], Bl
             inc SI
             loop boucle

fin_boucle :
mov ax, 4C00h
int 21h

code ends
    end debut

