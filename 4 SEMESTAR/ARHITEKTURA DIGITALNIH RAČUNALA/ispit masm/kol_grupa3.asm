;grupa 3
;koristeæi prekid za unos stringa unesite niz sa max 20 znakova i ispišite ga
;tako da se svaki znak ispisuje u novom redu [2]
;prebrojite koliko ima parnih brojeva u nizu [3-4] 
;ako je znak veliko slovo, prebacite ga u malo

.model small
.data
	niz DB 23 DUP()
	djeljitelj DB 2
	brojac DB 0
	parni DB "Parnih brojeva ima   $"
	ispis DB "Ispis niza$"
.stack
.code
	newline macro			;novi red
	
		mov dl,10
		mov ah,02h
		int 21h
		mov dl,13
		mov ah,02h
		int 21h
		
	endm
	
	Ispis_niza1 macro bx			;ispis niza,svaki znak u novom redu
		local Print;
		inc bx
		mov cl,[bx]
		mov ch,0
		
		Print:
			inc bx
			mov dl,[bx]
			mov ah,02h
			int 21h
				
			newline
		loop Print
	endm

	Ispis_niza2 macro bx			;ispis niza,obièno
			local Print;
		inc bx
		mov cl,[bx]
		mov ch,0
		
		Print:
			inc bx
			mov dl,[bx]
			mov ah,02h
			int 21h
				
		loop Print
	endm
	
	
	Prebroji_parne macro bx				;broji koliko ima parnih brojeva u nizu
		Local zavrsi;
		inc bx
		mov cl,[bx]
		mov ch,0
	
		Broji:
			inc bx
			mov dl,[bx]
			
			cmp dl,'0'					; provjeri da li je broj 0-9
			jl  zavrsi
			cmp dl,'9'
			jg  zavrsi
			
			mov al,dl			
			mov ah,0
			sub al,'0'
			div djeljitelj				; podijeli s 2
			
			cmp ah,0					; provjeri da li je paran
			jg zavrsi
			
			inc brojac
		zavrsi:
		loop Broji
		
		mov dl,brojac					; ispisi broj parnih
		add dl,'0'
		mov ah,02h
		int 21h
	
	endm

	Pretvori_znakove macro bx			;pretvori velika slova u mala
		local zavrsi;
		inc bx
		mov cl,[bx]
		mov ch,0
		
		Pretvori:
			inc bx
			mov dl,[bx]
			
			cmp dl,'A'					;provjeri da li je znak A-Z
			jl  zavrsi
			cmp dl,'Z'
			jg  zavrsi
			
			sub dl,'A'					;pretvori ga u malo
			add dl,'a'
			mov [bx],dl
			
		zavrsi:
		loop Pretvori
	endm

start:
	mov ax,@data
	mov ds,ax
		
	lea dx,niz						;unos niza
	mov niz[0],21
	mov ah,0Ah
	int 21h
	
	newline
	newline
	
	lea dx,ispis
	mov ah,09h
	int 21h
	newline
	lea bx,niz
	Ispis_niza1 bx 
	
	newline
	
	lea dx,parni
	mov ah,09h
	int 21h
	
	lea bx,niz
	Prebroji_parne bx
	
	newline
	
	lea bx,niz
	Pretvori_znakove bx
	
	newline
	
	lea dx,ispis
	mov ah,09h
	int 21h
	newline
	lea bx,niz
	Ispis_niza2 bx 
	
	newline
	
	mov ah,4ch
	int 21h
	
end start