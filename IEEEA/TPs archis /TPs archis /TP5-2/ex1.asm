assume CS:code, DS:data

data SEGMENT
tab DB 20, 5, 9, 5, 10, 12
N   DB 5
occurrences DB ?
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
mov bl, N
mov cl, 5

boucle :
  mov al, tab[SI]
  cmp al, bl
  je suivant
  inc SI
  loop boucle
  ;~ jmp boucle

suivant :
    add dl, 1
    inc SI
    loop boucle
  ;~ jmp boucle


fin_boucle :
     mov occurrences, dl

mov ax, 4C00h
int 21h

code ends
    end debut

