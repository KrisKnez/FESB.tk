.MODEL small
.DATA
	niz DB 103 DUP (0)
	podniz DB 103 DUP (0)
	ima DB "ima podniz$"
	nema DB "nema podniz$"
.STACK
.CODE
;-------------------novired
novired macro near
	mov dl,10
	mov ah,02h
	int 21h
	
	mov dl,13
	mov ah,02h
	int 21h
endm
;--------------------start
start:
	mov ax,@DATA
	mov ds,ax
	mov es,ax
	
	lea si,niz[2]
	lea di,podniz[2]
	
lea dx,niz
mov niz[0],100
mov ah,0Ah
int 21h

novired

lea dx,podniz
mov podniz[0],100
mov ah,0Ah
int 21h

novired

mov cl,niz[1]
mov ch,00h
	for1:
		cmpsb
		jne nijeslovo
			push cx
			mov cl,podniz[1]
			mov ch,00h
			for2:
				cmpsb
				jne nisu
			loop for2
				jmp imapodniz
			nisu:
			pop cx
		nijeslovo:
		dec di
	loop for1
	jmp nemapodniz
	
imapodniz:
	lea dx,ima
	mov ah,09h
	int 21h
	jmp kraj
nemapodniz:
	lea dx,nema
	mov ah,09h
	int 21h
kraj:
	mov ax,4c00h
	int 21h
end start