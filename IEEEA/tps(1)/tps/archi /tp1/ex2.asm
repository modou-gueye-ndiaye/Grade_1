assume  CS:code
code    segment
debut:
 mov ax, 142
 add ax, 151
 mov ax, 4C00h
 int 21h
code    ends
        end debut

; 4 ) le registre permettant la correction du resultat est : AX
