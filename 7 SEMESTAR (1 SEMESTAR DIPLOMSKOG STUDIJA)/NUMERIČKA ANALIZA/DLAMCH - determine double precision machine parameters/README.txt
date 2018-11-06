 * Upute za prevođenje:
========================
Preduvjet za prevođenje aplikacije je instaliran Fortran 77 (f77) prevoditelj.
Dodatno pobrinite se da je isti dodan u Windows PATH varijablu ili ga pozovite
s punim pathom do izvršne datoteke.

Preporučam GCC set alata odnosno gfortran kod kojeg sintaksa naredbe glasi:
------------------------------------------------------------------------------
  gfortran dlamch.f main.f -o [ime_izvrsne_datoteke].exe
------------------------------------------------------------------------------

Generiranu datoteku možete pokrenuti iz konzole odnosno klikom na nju s tim da
ukoliko ju pokrećete iz konzole možete iskoristiti redirekciju ispisa u .txt 
datoteku pomoću ">" operatora.


 * Download:
========================
GCC za Windows možete preuzeti na: 
  http://tdm-gcc.tdragon.net/
Originalna kolekcija funckija (dlamch.f) dostupna je na adresi:
  http://www.netlib.org/cgi-bin/netlibfiles.txt?format=txt&filename=lapack/util/dlamch.f


 * Napomene:
========================
1) .f datoteke su obični tekstualni file-ovi koji sadržavaju Fortran 77 kod i 
   mogu se editirati bilo kojim editorom
2) Kod zapisan u main.f je autorski i u tom smislu ukoliko primjetite grešku
   ili smislite elegantnije rješenje dojavite mi ga ili zamijenite postojeće.
3) Ne koristite 64-bitnu verziju gfortran prevoditelja odnosno GCC alata!
4) Greške dojavite u komentarima ili dostavite mail-om.