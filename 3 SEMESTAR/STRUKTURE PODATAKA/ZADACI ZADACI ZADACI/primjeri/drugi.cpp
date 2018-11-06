#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stablo;
typedef struct stablo *Pok;

struct stablo  {
	int maticni_broj;
	int godina;
	Pok LEFT;
	Pok RIGHT;
};


Pok Dodaj (Pok T, int broj, int god) {
	if (T==NULL) {
		T=(Pok)malloc(sizeof(struct stablo));
		T->maticni_broj=broj;
		T->godina=god;
		T->LEFT=NULL;
		T->RIGHT=NULL;
	}
	else if (god>T->godina) 
		T->RIGHT=Dodaj(T->RIGHT, broj, god);
	else if (god<T->godina) 
		T->LEFT=Dodaj(T->LEFT, broj, god);
	
	return T;
}


Pok Ucitaj_iz_datoteke (Pok T) {
	FILE *dat;
	printf("Unesi ime datoteke:\n");
	char ime[20];
	scanf("%s", ime);
	
	dat=fopen(ime, "r");
	
	if (dat==NULL) {
		printf("Datoteka ne postoji\n");
		return T;	
	}
	
	while (feof(dat)==0) {
		int broj;
		int god;
		fscanf(dat, "%d %d", &god, &broj);
		T=Dodaj (T, broj, god);
	
	}
	 
	return T;
}

Pok nadi_min_desno (Pok T) {
	if (T==NULL) {
		printf("prazno stablo");
		return NULL;	
	}
	T=T->RIGHT;
	if (T==NULL) {
		printf("ne postoji element");
		return NULL;	
	}
	
	while (T->LEFT!=NULL) {
		T=T->LEFT;
	}
	
	return T;

}

float ukupno (Pok T) {

	if (T==NULL)
		return 0;	
	return (ukupno(T->LEFT)+ukupno(T->RIGHT)+T->godina);
}

int broj_elemenata (Pok T) {
	if (T==NULL)
		return 0;	
	return (broj_elemenata(T->LEFT)+broj_elemenata(T->RIGHT)+1);
}



void upisi_u_datoteku (Pok T) {
	FILE *dat;
	static int n=0;
	int i;
	if (-1==n)
		n=0;
	
	if (T!=NULL) {
		n++;
		upisi_u_datoteku (T->RIGHT);
		dat=fopen("idesdurda.txt", "a+");
		fprintf(dat, "\n");
		for (i=0; i<n; i++)
			fprintf(dat, "\t");
		fprintf(dat, "%d", T->godina);
		fprintf(dat, "\n");
		fclose(dat);
		n++;
		upisi_u_datoteku (T->LEFT);
	}
	n--;
		



}


void ispis (Pok T) {
	static int n=0;
	int i;
	if (-1==n)
		n=0;
	
	if (T!=NULL) {
		n++;
		ispis (T->RIGHT);
		printf("\n");
		for (i=0; i<n; i++)
			printf("\t");
		printf("%d", T->godina);
		printf("\n");
		n++;
		ispis (T->LEFT);
	}
	n--;
	
	
	
	
}





int main() {
	Pok root, temp;
	root=NULL;

	root=Ucitaj_iz_datoteke(root);
	temp=nadi_min_desno(root);
	printf("Prvi poslije %d studenta po godini rodenja je student %d", root->maticni_broj, temp->maticni_broj);
	printf("Prosjek godina je %f", ukupno(root)/broj_elemenata(root));
	ispis (root);
	upisi_u_datoteku(root);
	return 0;
	




}










