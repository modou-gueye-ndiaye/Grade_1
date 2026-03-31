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
  xor bx, bx
  xor si, si
  add AL, magique[SI + 0000]
	add AL, magique[SI + 0004]
	add AL, magique[SI + 0008]
	mov sommes_par_diagonale[bx + SI + 0000], AL

  xor AL, AL
  xor bx, bx
  xor si, si
  add AL, magique[SI + 0002]
	add AL, magique[SI + 0004]
	add AL, magique[SI + 0006]
	mov sommes_par_diagonale[bx + SI + 0001], AL
	mov AX, 4C00h
	int 21h
code ENDS
  END debut
