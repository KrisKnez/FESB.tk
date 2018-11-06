#include <stdio.h>
#include <stdlib.h>

struct student;
typedef struct student *Pok;
struct student {
	int maticni_broj;
	int godina;
	Pok NEXT;
};


void unos (Pok T) {
	printf("Unesi ime datoteke:\n");
	char ime[20];
	scanf("%s", ime);
	FILE *dat;
	dat=fopen(ime, "r");
	if (dat==NULL) {
		printf("datoteku nije moguce otvoriti");
		exit(1);
	}
	Pok q;
	
	while (feof(dat)==0) {
		
		
		q=(Pok)malloc(sizeof(struct student));
		fscanf(dat, "%d %d", &q->godina, &q->maticni_broj);
		q->NEXT=T->NEXT;
		T->NEXT=q;
		
	}
}

void nova (Pok T1, Pok T2) {
	Pok q;
	T2=T2->NEXT;
	while(T2!=NULL) {
		q=(Pok)malloc(sizeof(struct student));
		q->maticni_broj=T2->maticni_broj;
		q->godina=T2->godina;
		q->NEXT=T1->NEXT;
		T1->NEXT=q;
		
		T2=T2->NEXT;
	}
}

void ispis (Pok T) {
	T=T->NEXT;
	if (T==NULL) 
		printf("prazna lista");
	else {
		while(T!=NULL) {
			printf("%d, %d\n", T->maticni_broj, T->godina);
			T=T->NEXT;
		}
		
	}
	
}


int main() {
	struct student head1;
	struct student head2;
	head1.NEXT=NULL;
	head2.NEXT=NULL;
	
	unos (&head1);
	ispis(&head1);
	printf("\n");
	nova(&head2, &head1);
	ispis(&head2);
	return 0;
}

