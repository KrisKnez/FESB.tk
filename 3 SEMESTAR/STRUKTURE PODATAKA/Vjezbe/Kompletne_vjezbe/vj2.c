/*
Prethodnom zadatku dodati funkciju:
	pronaði - koja pronalazi redni broj elementa (pretraga se radi po prezimenu),i promijeniti funkciju:
	brisi - tako da briše bilo koji element (ne mora biti zadnji).
	sortiranje - po prezimenima osoba u nizu, 
	upisivanje niza u datoteku, 
	èitanje niza iz datoteke (to se može napraviti u bilo kojem trenutku, pa treba vodit raèuna da niz ne preðe dozvoljenu velièinu). 
Kao argument funkcija brisi treba uzeti i redni broj elementa koji se briše. 
*/

#include<stdio.h>
#include<string.h>

#define MAX_OSOBA 10

struct osoba
{
	char ime[10];
	char prezime[10];
	int g_r;
};

int unos(int, struct osoba []);
int brisi(int, int, struct osoba []);
void ispis(int, struct osoba []);
int trazi(int , struct osoba []);
void sort(int , struct osoba []);
void u_dat(int, struct osoba []);
int iz_dat(int , struct osoba []);

void main ()
{
	struct osoba popis[MAX_OSOBA];
	int broj_osoba = 0, redni_broj = 0;
	char izbor = 0;

	while(izbor != 'K' && izbor != 'k')
	{
		printf("\nUnesi:");
		printf("\n\t1 - unos elementa u niz");
		printf("\n\t2 - brisanje elementa iz niza");
		printf("\n\t3 - ispis niza");
		printf("\n\t4 - trazenje elementa u nizu");
		printf("\n\t5 - sortiranje");
		printf("\n\t6 - upis u datoteku");
		printf("\n\t7 - citanje iz datoteke");
		printf("\n\tk - kraj\n\n\t");

		scanf(" %c", &izbor);

		switch (izbor)
		{
		case '1':
			broj_osoba = unos(broj_osoba, popis);
			break;
		case '2':
			redni_broj = trazi(broj_osoba, popis);
			if (redni_broj == -1)
				printf("\nOsoba ne postoji!!");
			else
				broj_osoba = brisi(broj_osoba, redni_broj, popis);
			break;
		case '3':
			ispis(broj_osoba, popis);
			break;
		case '4':
			redni_broj = trazi(broj_osoba, popis);
			if (redni_broj == -1)
				printf("\nOsoba ne postoji!!");
			else
				printf("\nOsoba je: %s %s %d", popis[redni_broj].ime, popis[redni_broj].prezime, popis[redni_broj].g_r);
			break;
		case '5':
			sort(broj_osoba, popis);
			break;
		case '6':
			u_dat(broj_osoba, popis);
			break;
		case '7':
			broj_osoba = iz_dat(broj_osoba, popis);
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
		printf("\nUnesite ime, prezime i godinu rodjenja:\t");
		scanf(" %s %s %d", x[n].ime, x[n].prezime, &x[n].g_r);
		n++;
	}
	
	return n;
}

int brisi(int n, int m, struct osoba x[])
{
	int i;

	for(i = m; i < n-1; i++)
		x[i] = x[i+1];
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
			printf("\t%s\t%s\t%d\n", x[i].ime, x[i].prezime, x[i].g_r);
	}
}

int trazi(int n, struct osoba x[])
{
	int i=0;
	int nasao = 0;
	char prez[10];

	printf("\n Unesi prezime:\t");
	scanf(" %s", prez);

	while(i < n && nasao == 0)
	{
		if (strcmpi(x[i].prezime, prez) == 0)
			nasao = 1;
		i++;
	}

	if (nasao == 1)
		return (i-1);
	else 
		return -1;

}

void sort(int n, struct osoba x[])
{
	int i, j;
	struct osoba temp;

	for(i = 0; i< n-1; i++)
		for(j = i+1; j<n ; j++)
			if(strcmp(x[i].prezime, x[j].prezime)==1)
			{
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
}

void u_dat(int n, struct osoba x[])
{
	FILE *dat;
	char ime_dat[11];
	int i;


	printf("\nUpisi ime datoteke u koju zelis spremit niz (max. 10 znakova): ");
	scanf(" %s", ime_dat);

	dat = fopen(ime_dat, "w");
	if(dat == NULL)
			printf("\n\n Greska u otvaranju datoteke");
	else
	{
		for(i = 0; i<n ; i++)
			fprintf(dat, "\n%s %s %d", x[i].ime, x[i].prezime, x[i].g_r);
		fclose(dat);
	}
	
}


int iz_dat(int n, struct osoba x[])
{
	FILE *dat;
	char ime_dat[11];
	int i = n;


	printf("\nUpisi ime datoteke iz koje zelis citati niz (max. 10 znakova): ");
	scanf(" %s", ime_dat);

	dat = fopen(ime_dat, "r");
	if(dat == NULL)
			printf("\n\n Ne postoji datoteka s tim imenom!!");
	else
	{
		while(feof(dat) == 0 && i < MAX_OSOBA)
		{
			fscanf(dat, " %s %s %d", x[i].ime, x[i].prezime, &x[i].g_r);
			i ++;
		}
		fclose(dat);

		if(feof(dat)==0)
			printf("\nNisu procitane sve osobe jer vise nije bilo mjesta");
	}

	return i;
}