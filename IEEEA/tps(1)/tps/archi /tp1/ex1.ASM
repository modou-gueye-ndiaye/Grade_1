assume  CS:code
code    segment
debut:
 mov al, 27h
 add al, 21h
 mov ax, 4C00h
 int 21h
code    ends
        end debut
