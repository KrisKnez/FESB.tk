/*
Skoro isti kod kao i kod primjera za dup2 sa ~dkrst-a
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	int fd;
	char **argumenti;
	
/*
	fd - file deskriptor koji koristimo kod otvaranja datoteke u koju upisujemo izlaz.
	
	**argumenti - pokazivac na pokazivaca koji ce pokazivat na polje pokazivaca
	ciji je prvi element naziv naredbe koju cemo pozivati. Ovo je potrebno zbog 
	toga sto funkcija execvp kao drugi argument prima polje pokazivaca ciji je 
	prvi element naziv naredbe, a ovo je najprakticniji nacin za dobit to polje. 
*/

	if (argc < 3) {
		printf ("koristenje: pokreni <ime_datoteke> <naredba> [argument_1] [argument_2] ...\n");    
		exit (0);  
	}  

/*
	Provjera jel program ima minimalan broj potrebnih argumenata.
*/

	fd = open (argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);  
	if (fd < 0) {
		perror ("open");    
		exit (-1);  
	}

/*
	Funkcija za otvaranje datoteke (open) otvara datoteku cije smo ime napisali kao
	prvi argument (argv[1]), otvara je za citanje (O_WRONLY) te ako ne postoji datoteka
	pod tim imenom stvara novu (O_CREAT) te na kraju pridruzuje prava korisnika 
	(S_IRUSR - pravo citanja korisnika, S_IWUSR - pravo pisanja korisnika).
	
	Nakon toga provjera jeli datoteka uspjesno otvorena.
*/

	argumenti = &argv[2];

/*
	Pokazivac argumenti pokazuje na pokazivac argv[2] koji pokazuje na ime naredbe.
	Ovako smo iz polja pokazivaca koji pokazuje na sve argumente programa izdvojili
	polje pokazivaca koje samo pokazuje na naredbu i njene argumente (ako ih ima).
*/

	dup2 (fd, STDOUT_FILENO);

/*
	Mijenjamo standardni izlaz s vanjskom datotekom.
*/

	if (fd != STDOUT_FILENO)
		close (fd);

/*
	Ovdje provjeravamo jel fd pokazuje na na standardni izlaz. Ako nije onda ga zatvaramo,
	ako je ostavljamo ga otvorenim jer ako bi ga zatvorili nebi imali gdje ispisivat a i bilo
	koja druga datoteka koju bi kasnije otvarali bi dosla na njegovo mjesto.
*/

	execvp (argumenti[0], argumenti);

/*
	Funkcijom execvp pokrecemo naredbu. Prvi argument funkcije je ime naredbe, a drugi je
	polje pokazivaca ciji je prvi element ime naredbe, a ostali argumenti (ako ih ima).
*/

	perror ("exec");

/*
	Za ispisivanje greske vezane uz execvp. Nije potreban if jer sve exec funkcije nakon svog
	pokretanja zamjenjuju kod programa u kojem se nalaze s kodom naredbe koju funkcija poziva.
	Tako da ce se perror jedino pozvati ako se execvp neizvrsi.
*/
	
	return 0;
}
/*
	Falia san Bobane. Ima manje od 50 linija koda. :D
*/