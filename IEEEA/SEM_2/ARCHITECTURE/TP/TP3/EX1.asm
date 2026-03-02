Assume CS : Code, DS : Data

data segment
  var1 db 169
  var2 db 5
  var3 db 13
  result db ?

data end

code segment
debut :

  mov AX, data
  mov DS, AX

  mov AL, var1
  mov BL, var2
  mov AH, var3
  SUB AL, BL
  add AL, AH
  mov result, AL

  mov AX, 4C00h
  int 21h

code end
end debut
