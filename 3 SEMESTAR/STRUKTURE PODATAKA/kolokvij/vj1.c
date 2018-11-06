/* 
Definirati niz sa 10 elemenata tipa struktura osoba (ime, prezime, godina roðenja).
U glavnom programu napraviti izbornik koji dozvoljava: 
	- unošenje novog elemenata u niz (na prvo slobodno mjesto), 
	- brisanje elementa iz niza (briše se zadnji uneseni), 
	- ispis unesenih elemenata, 
	- izlaz iz programa.    
Unos, brisanje i ispis potrebno riješiti u funkcijama.
U mainu može biti izbornik i pozivi funkcija.
Ne smiju se koristiti globalne varijable.
*/

#include<stdio.h>

#define MAX_OSOBA 10

struct osoba
{
	char ime[10];
	char prezime[10];
	int godina;
};

int unos(int, struct osoba []);
int brisi(int);
void ispis(int, struct osoba []);

void main ()
{
	struct osoba popis[MAX_OSOBA];
	int broj_osoba = 0;
	char izbor = 0;

	while(izbor != 'K' && izbor != 'k')
	{
		printf("\nUnesi:");
		printf("\n\t 1 - unos elementa u niz");
		printf("\n\t 2 - brisanje elementa iz niza");
		printf("\n\t 3 - ispis niza");
		printf("\n\t k - kraj\n\n\t");

		scanf(" %c", &izbor);

		switch (izbor)
		{
		case '1':
			broj_osoba = unos(broj_osoba, popis);
			break;
		case '2':
			broj_osoba = brisi(broj_osoba);
			break;
		case '3':
			ispis(broj_osoba, popis);
			break;
		case 'k':
		case 'K':
			printf("\nKraj programa!!!\n");
			break;
		default:
			printf("\nKrivi unos!!!\n");
		}
	}
}

int unos(int n, struct osoba x[])
{
	if (n == MAX_OSOBA)
		printf("\nNiz je pun\n");
	else
	{
		printf("\nUnesite ime, prezime i godinu roðenja:\t");
		scanf(" %s %s %d", x[n].ime, x[n].prezime, &x[n].godina);
		n++;
	}
	
	return n;
}

int brisi(int n)
{
	if (n == 0)
		printf("\nNiz je prazan!\n");
	else
		n--;

	return n;
}

void ispis(int n, struct osoba x[])
{
	int i;
	
	if(n==0)
		printf("\nNiz je prazan!");
	else
	{
		printf("\nU nizu se nalazi:\n");
		for(i = 0; i < n; i++)
			printf("\t%s\t%s\t%d\n", x[i].ime, x[i].prezime, x[i].godina);
	}
}
