#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) { // argc - koliko imamo argumenata
									// argv - polje argumenata i 
									//svi su stringovi
  int fd, n, l, i;	// fd - file deskriptor
					// to je broj kojim se oznacavaju datoteke koje se
					// koriste. Kod linuxa je sve datoteka tako da su i
					// standardni ulaz, izlaz i izlaz za greske 
					// isto datoteke sa brojevima 0, 1 i 2.
					// Al mi koristimo nazive STDIN_FILENO i STDOUT_FILENO
					// radi citljivijeg koda. Da se napise 0 ili 1 umisto
					// toga isto bi radilo.
					// n - broj u kojeg zapisujemo koliko je bajtova
					// funkcija read procitala.
					// l - broj u kojeg zapisujemo koliko znakova
					// moramo procitat.
					// i - brojac u petlji.
  char c;			// c - karakter u kojeg spremamo ono sto smo
					// procitali.
  off_t poz;		// poz - off_t je isto broj, mogli smo i int
					// iskoristit al ovo je pravilnije.
					// oznacava poziciju od koje pocinjemo citat
					// datoteku.
  
  if (argc < 4) {
    printf("koristenje: citaj <ime_datoteke>\n");
    exit(0);
  }
// ova funkcija sluzi da ispita ima li dovoljan broj argumenata
// ako nema onda ispise poruku i prekine izvrsavanje programa

  fd=open(argv[1],O_RDONLY);
  // ovom funkcijom otvaramo datoteku cije ime je prvi argument
  // O_RDONLY je zastavica kojom govorimo da samo zelimo koristit
  // datoteku za citanje
  
  if (fd < 0) {		// provjeravamo jeli datoteka otvorena
    perror("open")	// funkcija open vraca -1 ako datoteka
    exit(-1);		// nije ispravno otvorena
  }					// perror je standardna funkcija koja
					// ispise ono sto pise u zagradi koje
					// sluzi kao osobna poruka programera
					// da se zna koja je greska, a nakon
					// sta ispise tu poruku ispise i zadnji
					// sistemski error koji daje detaljniji
					// opis greske koja se dogodila
  
  poz=atoi(argv[2]);// kako su argumenti svi string
					// a nama treba int
					// funkcijom atoi pretvaramo string u int
  
  if (lseek(fd,poz,SEEK_SET)==-1) {
    perror("lseek");
    exit(-1);
  }
  // funkcijom lseek se pozicioniramo u datoteci na osnovu offseta
  // offset je za nas varijabla poz
  // zastavica SEEK_SET znaci da je offset od pocetka datoteke
  // postoje jos dvije zastavice
  // jedna za offset od trenutne pozicije
  // jedna za offset od kraja
  // obe mogu bit pozitivne i negativne
  // perror i exit imaju istu funkciju kao i prije
  
  l=atoi(argv[3]);	// opet mijenjamo string u int
  
  for (i=0; i < l; i++) { 	// petlja se vrti do broja znakova koje
							// moramo procitat

    if ((n=read(fd,&c, 1)) > 0 )	// read sluzi za citanje iz datoteke
									// prvi argument je odakle citamo
									// drugi u sta pohranjujemo
									// treci koliko byteova citamo
									// read vraca 0 za kraj datoteke
									// -1 za gresku
									// inace vraca broj procitanih
									// byteova
      write(STDOUT_FILENO,&c, 1);	// s write pisemo u neku datoteku
									// slicno argumenti kao i read
									// prvi u sta pisemo
									// drugi iz cega
									// treci koliko pisemo
    else {							// u ovaj else ulazimo
      if (n==-1)					// ako je nastala greska
        perror("read");
      else							// ili ako smo dosli do kraja
        printf("\n\n");				// datoteke a nismo proctali
      close(fd);					// maksimalan, varijabla l,
      exit(0);						// broj znakova
    }    							// bitno je zatvorit datoteku
  }									// nakon koristenja jer inace
  printf("\n\n");					// bi iskoristili previse file
  close(fd);						// deskriptora a to nije dobro
  return 0;							
}