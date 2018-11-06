#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student;
typedef struct student *Pok;
struct student {
	int maticni_broj;
	int godina;
	Pok NEXT;
};

void unos (Pok T) {
	FILE *dat;
	printf("Unesite ime datoteke:\n");
	char ime[20];
	scanf("%s", ime);
	

	
	dat=fopen(ime, "r");
	if (dat==NULL) {
		printf("Datoteka ne postoji");
		exit(1);
	}
	Pok q;
	while (feof(dat)==0) {
		q=(Pok)malloc(sizeof(struct student));
		fscanf(dat, "%d %d", &q->maticni_broj, &q->godina);
		//sortirani ulaz
		while ((T->NEXT!=NULL) && (q->maticni_broj>T->NEXT->maticni_broj) ){
			   T=T->NEXT;			   
		}
		q->NEXT=T->NEXT;
		T->NEXT=q;	
	}
	
	fclose (dat);

}

void ispis (Pok T) {
	T=T->NEXT;
	if (T==NULL) 
		printf("Niz je prazan\n");
	else {
		while (T!=NULL) {
			printf("Maticni broj: %d, godina: %d\n", T->maticni_broj, T->godina);
			T=T->NEXT;	
		}
	
	}
}

void izbrisi (Pok T1, Pok T2) {
	if (T1==NULL)
		printf("Prva lista je prazna\n");
	else {
		Pok prev=T1;
		T1=T1->NEXT;
		T2=T2->NEXT;
		Pok temp;
			   
		while ((T1!=NULL)&&(T2!=NULL)) {
			if (T1->maticni_broj>T2->maticni_broj)
				T2=T2->NEXT;
			else if(T1->maticni_broj<T2->maticni_broj) {
				T1=T1->NEXT;
				prev=prev->NEXT;
			}
			else {
				temp=T1;
				prev->NEXT=T1->NEXT;
				T1=T1->NEXT;
				T2=T2->NEXT;
				free(temp);
			}
			   
			}
			
	
	
	}



}



int main () {
	
	struct student head1;
	struct student head2;
	head1.NEXT=NULL;
	head2.NEXT=NULL;
	unos (&head1);
	unos (&head2);
	izbrisi (&head1, &head2);
	ispis (&head1);
	return 0;


}