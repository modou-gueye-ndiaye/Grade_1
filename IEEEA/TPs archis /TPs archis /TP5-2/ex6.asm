ASSUME CS:code, DS:data

data SEGMENT
    magique DB 2, 7, 6, 9, 5, 1, 4, 3, 8
    sommes_par_ligne    DB 3 DUP(?)
    sommes_par_colonne  DB 3 DUP(?)
    sommes_par_diagonale DB 2 DUP(?)
data ENDS

code SEGMENT
debut:
    MOV AX, data
    MOV DS, AX

  
    XOR SI, SI     
    XOR DI, DI      
    MOV CX, 3
boucle_lignes:
    MOV AL, magique[SI]
    ADD AL, magique[SI+1]
    ADD AL, magique[SI+2]
    MOV sommes_par_ligne[DI], AL
    ADD SI, 3      
    INC DI
    LOOP boucle_lignes


    XOR SI, SI      
    XOR DI, DI
    MOV CX, 3
boucle_colonnes:
    MOV AL, magique[SI]
    ADD AL, magique[SI+3]
    ADD AL, magique[SI+6]
    MOV sommes_par_colonne[DI], AL
    INC SI         
    INC DI
    LOOP boucle_colonnes


    MOV AL, magique[0]
    ADD AL, magique[4]
    ADD AL, magique[8]
    MOV sommes_par_diagonale[0], AL

    MOV AL, magique[2]
    ADD AL, magique[4]
    ADD AL, magique[6]
    MOV sommes_par_diagonale[1], AL


    MOV AX, 4C00h
    INT 21h
code ENDS
    END debut
