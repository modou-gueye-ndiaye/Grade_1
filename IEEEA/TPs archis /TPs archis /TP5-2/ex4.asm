ASSUME CS:code, DS:data

data SEGMENT
    mot DB "ressasser"
    len DW 9
    palindrome DB ?
data ENDS

code SEGMENT
debut:
    MOV AX, data
    MOV DS, AX

    XOR SI, SI          ; SI = 0 (début du mot)
    MOV DI, len
    DEC DI              ; DI = len - 1 (fin du mot)
    
    MOV CX, len         ; Nombre d'itérations
    SHR CX, 1           ; Optionnel : On ne teste que la moitié du mot (len/2)

    ; Par défaut, on considère que c'est un palindrome (1)
    MOV AL, 1
    MOV palindrome, AL

boucle:
    MOV AL, mot[SI]     ; On prend la lettre au début
    MOV BL, mot[DI]     ; On prend la lettre à la fin
    CMP AL, BL
    JNE pas_palindrome  ; Si différent -> c'est fini, on saute à l'échec

    INC SI              ; On avance au début
    DEC DI              ; On recule à la fin
    LOOP boucle
    JMP fin             ; Si la boucle finit, c'est que tout était OK

pas_palindrome:
    MOV AL, 0
    MOV palindrome, AL

fin:
    MOV AX, 4C00h       ; Retour au DOS
    INT 21h
code ENDS
    END debut
