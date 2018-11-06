.model small
.data
niz DB 10 DUP(0)
.stack
.code

NoviRed MACRO
mov dl,10
mov ah,02h
int 21h
mov dl,13
mov ah,02h
int 21h
ENDM

Start:
mov ax,@DATA
mov ds,ax

mov si,0
unos:
	cmp si,10
	jge kraj_unos

	mov ah,01h
	int 21h
	
	sub al,'0'
	mov niz[si],al

	inc si
	jmp unos

kraj_unos:
NoviRed

mov si,0
petljai:
	mov di,si
	inc di
petljaj:
	mov ah,niz[si]
	mov al,niz[di]
	cmp ah,al
	jge preskok
	mov niz[si],al
	mov niz[di],ah

preskok:
	inc di
	cmp di,10
	jl petljaj

	inc si
	cmp si,9
	jl petljai

mov si,0
ispis:
	cmp si,10
	je kraj
	
	mov dl,niz[si]
	add dl,'0'
	mov ah,02h
	int 21h
	
	inc si
	jmp ispis
	

kraj:
mov ax,4c00h
int 21h
END Start