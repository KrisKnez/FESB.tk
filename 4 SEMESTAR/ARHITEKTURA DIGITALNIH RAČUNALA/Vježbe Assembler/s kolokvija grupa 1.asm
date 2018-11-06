.MODEL small
.DATA
  niz DB 10 DUP('$')
  znak DB 10 DUP('$')
  novi DB 10 DUP('$')
.STACK
.CODE
unos MACRO
MOV cx,10
MOV si,0
MOV di,0
petlja:
	MOV ah,01h
	INT 21h
	MOV niz[si],al
	SUB al, '0'
	CMP al, 9
	JG dalje
	ADD al,'0'
	MOV novi[di], al
	INC di
	JMP dalje2
dalje:
	ADD al,'0'
	MOV znak[si],al
	INC si
dalje2:
	LOOP petlja
	ENDM

ispisbroj MACRO
MOV si,0
ponovi:
	CMP znak[si],'$'
	JE kraj
	MOV dl, znak[si]
	MOV ah, 02h
	INT 21h
	
	INC si
	JMP ponovi
kraj:

ENDM


ispisznak MACRO
MOV si,0
pono:
	CMP novi[si], '$'
	JE kr
	MOV dl, novi[si]
	MOV ah, 02h
	INT 21h
	
	INC si
	JMP pono
kr:

ENDM

NoviRed MACRO
MOV dl, 10
MOV ah,02h
INT 21h
MOV dl, 13
MOV ah,02h
INT 21h
ENDM

Start:
mov ax, @DATA
mov ds, ax

unos

NoviRed

ispisbroj

NoviRed

ispisznak

NoviRed

MOV si,0
pet:
	CMP novi[si], 36
	JE en
	MOV cl,novi[si]
	AND cl, 00000001b
	CMP cl, 0
	JE parni
	MOV dl, novi[si]
	MOV ah,02h
	INT 21h
parni:
	INC si
	JMP pet
en:


MOV ax,4c00h
INT 21h
END Start
