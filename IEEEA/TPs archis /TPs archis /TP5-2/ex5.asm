ASSUME CS:code, DS:data

data SEGMENT
    tab DB 1, 1, 20 DUP(?) 
    len DW 20               ; On veut calculer les 20 valeurs suivantes
data ENDS

code SEGMENT
debut:
    MOV AX, data
    MOV DS, AX

    XOR SI, SI              ; SI pointe sur le premier élément du calcul
    MOV CX, len             ; On va boucler 20 fois

boucle:
    MOV AL, tab[SI]         ; Premier nombre (n)
    MOV BL, tab[SI + 1]     ; Deuxième nombre (n+1)
    ADD AL, BL              ; AL = Somme (n+2)
    
    MOV tab[SI + 2], AL     ; On stocke le résultat dans la case suivante
    INC SI                  ; On décale d'une case pour le prochain calcul
    LOOP boucle             ; Décrémente CX et repart à "boucle" si CX > 0

    MOV AX, 4C00h
    INT 21h
code ENDS
    END debut
