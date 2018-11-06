/*
Definirati strukturu osoba (ime, prezime, godina roðenja) i napisati program koji:
	- dinamièki dodaje novi element na poèetak liste,
	- ispisuje listu,
	- dinamièki dodaje novi element na kraj liste,
	- pronalazi element u listi (po prezimenu),
	- briše odreðeni element iz liste,
	- dinamièki dodaje novi element iza odreðenog elementa,
	- dinamièki dodaje novi element ispred odreðenog elementa,
	- Sortiranjeira listu po prezimenima osoba,
	- upisuje listu u datoteku,
	- èita listu iz datoteke.
U zadatku se ne smiju koristiti globalne varijable.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct osoba;

typedef struct osoba * Pozicija;

struct osoba
{
	char ime[10];
	char prezime[10];
	int godina;
	Pozicija Next;
};

void Insert(Pozicija);
void Print(Pozicija);
Pozicija FindLast(Pozicija);
Pozicija Find(Pozicija);
Pozicija FindPrev(Pozicija);
void Delete (Pozicija);
void Sortiranje(Pozicija);
void ReadFromFile(Pozicija);
void WriteToFile(Pozicija);
			

void main ()
{
	struct osoba head, *q;
	char izbor = 0;
	
	head.Next = NULL;
	while(izbor != 'K' && izbor != 'k')
	{
		printf("\nUnesi:");
		printf("\n\t0 - unos elementa na pocetak");
		printf("\n\t1 - ispis niza");
		printf("\n\t2 - unos elementa na kraj");
		printf("\n\t3 - trazenje elementa u listi po prezimenu");
		printf("\n\t4 - brisanje");
		printf("\n\t5 - dodavanje iza elementa");
		printf("\n\t6 - dodavanje ispred elementa");
		printf("\n\t7 - Sortiranjeiranje liste po prezimenu");
		printf("\n\t8 - citanje iz datoteke");
		printf("\n\t9 - upisivanje liste u datoteku");
		printf("\n\tk - kraj\n\n\t");

		scanf(" %c", &izbor);

		switch (izbor)
		{
		case '0':
			Insert(&head);
			break;
		case '1':
			Print(head.Next);
			break;
		case '2':
			q = FindLast(&head);
			Insert(q);
			break;
		case '3':
			q = Find(head.Next);
			if( NULL == q)
				printf("\n Osoba ne postoji u listi!");
			else
				printf("\n\tOsoba je: %s %s, %d", q->ime, q->prezime, q->godina); 
			break;
		case '4':
			Delete(&head);	
			break;
		case '5':
			q = Find(head.Next);
			if( NULL == q)
				printf("\n Osoba ne postoji u listi!");
			else
				Insert(q);
			break;
		case '6':
			q = FindPrev(&head);
			if( NULL == q)
				printf("\n Osoba ne postoji u listi!");
			else
				Insert(q);
			break;
		case '7':
				Sortiranje(&head);
			break;
		case '8':
				ReadFromFile(&head);
			break;
		case '9':
				WriteToFile(head.Next);
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

void Insert(Pozicija P)
{
	Pozicija temp;

	temp = (Pozicija)malloc(sizeof(struct osoba));
	printf("\nUnesite podatke o osobi: ");
	scanf( " %s %s %d", temp->ime, temp->prezime, &temp->godina);

	temp->Next = P->Next;
	P->Next = temp;
}

void Print(Pozicija P)
{
	if(NULL == P)
		printf("\nLista je prazna!!\n");
	else
	{
		printf("\nU listi se nalaze:");
		while(P!=NULL)
		{
			printf("\n\t %s %s %d", P->ime, P->prezime, P->godina);
			P=P->Next;
		}
	}


}

Pozicija FindLast(Pozicija P)
{
	while(NULL != P->Next)
		P = P->Next;
	return P;
}


Pozicija Find(Pozicija P)
{
	char prez[10];


	printf("\nUnesi prezime osobe koju zelis pronaci: ");
	scanf(" %s", prez);

	while(P != NULL && strcmpi(P->prezime, prez)!= 0)
		P = P->Next;

	return P;
}

Pozicija FindPrev(Pozicija P)
{
	char prez[10];

	if(NULL == P->Next)
		P = NULL;
	else
	{
		printf("\nUnesi prezime osobe koju zelis pronaci: ");
		scanf(" %s", prez);


		while(strcmpi(P->Next->prezime, prez)!= 0 && P->Next->Next != NULL)
			P = P->Next;

		if(strcmpi(P->Next->prezime, prez)!= 0)
			P = NULL;
	}
	
	return P;
}

void Delete (Pozicija P)
{
	Pozicija prev;

	prev = FindPrev(P);

	if (NULL != prev)
	{
		P = prev->Next;
		prev->Next = P->Next;
		printf("\n Osoba %s %s %d je obrisana!", P->ime, P->prezime, P->godina);
		free(P);
	}
	else
		printf("\n Osoba ne postoji u listi!");
}

void Sortiranje(Pozicija P)
{
	//Za Sortiranjeiranje se koristi bubble Sortiranje
	Pozicija i, j, prev_j, temp, end; 

	end = NULL;
	
	i = P;
	
	while (i->Next != end)
	{
		prev_j = i;
		j = i->Next;
		while(j->Next!= end)
		{
			if(strcmp(j->prezime, j->Next->prezime)>0)
			{
				temp = j->Next;
				prev_j->Next = temp;
				j->Next = temp->Next;
				temp->Next = j;

				j= temp;
			}

			prev_j=j;
			j = j->Next;
		}
		end = j;
	}

}

void ReadFromFile(Pozicija P)
{
	// ova funkcija dodaje elemente iz datoteke 
	// iza pokazivaca koji se posalje

	FILE *dat;
	char imeDat[10];
	Pozicija temp;

	printf("\nUnesi ime datoteke iz koje zelis procitati listu:");
	scanf(" %s", imeDat);

	dat = fopen(imeDat, "r");
	
	if (NULL == dat)
		printf("\n Ne postoji datoteke s tim imenom");
	else
	{
		while(feof(dat)==0)
		{
			temp = (Pozicija)malloc(sizeof(struct osoba));
			
			fscanf(dat, " %s %s %d", temp->ime, temp->prezime, &temp->godina);

			temp->Next = P->Next;
			P->Next= temp;
			P = temp;
		}

		fclose(dat);
	}
}

void WriteToFile(Pozicija P)
{
	// ova funkcija dodaje elemente iz datoteke 
	// iza pokazivaca koji se posalje

	FILE *dat;
	char imeDat[10];

	printf("\nUnesi ime datoteke u koju zelis spremiti listu:");
	scanf(" %s", imeDat);

	dat = fopen(imeDat, "w");
	
	if (NULL == dat)
		printf("\n Greska u otvaranju datoteke");
	else
	{
		while(P!=NULL)
		{
			fprintf(dat, "\n %s %s %d", P->ime, P->prezime, P->godina);
			P = P->Next;
		}

		fclose(dat);
	}
}
