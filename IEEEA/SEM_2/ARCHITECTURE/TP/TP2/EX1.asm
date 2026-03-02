assume CS:code, DS:data

data SEGMENT
   A dw 0FACh
   premiers db 2, 3, 5, 7, 11, 13, 17
   B dd 3141592653
   palindrome db "Engage le jeu que je le gagne"
   erreur db "-ERREUR : ce message ne doit pas s'afficher!"
   C db -99
   vitesse_lumiere dd 300000
   temperatures dw -200, -100, 0, 100, 200

data ENDS

code segment
debut :
    mov AX, data
    mov DS, AX
    mov AH, 9
    lea DX, palindrome
    int 21h
    mov ax, 4C00h
    int 21h

code ends
    end debut

