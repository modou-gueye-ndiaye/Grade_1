data SEGMENT
	magique DB 2, 7, 6, 9, 5, 1, 4, 3, 8
	sommes_par_ligne DB 3 dup(?)
	sommes_par_colonne DB 3 dup(?)
	sommes_par_diagonale DB 2 dup(?)
data ENDS

assume cs:code, ds:data

code SEGMENT
debut:
	mov AX, data
	mov DS, AX

	xor AL, AL
	add AL, magique[SI + 0000]
	add AL, magique[SI + 0001]
	add AL, magique[SI + 0002]
	mov sommes_par_ligne[bx +0009], AL

	mov AX, 4C00h
	int 21h
code ENDS
  END debut
