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
	Pok q, prev, sada;
	while (feof(dat)==0) {
		
		prev=T;
		sada=T->NEXT;
		
		q=(Pok)malloc(sizeof(struct student));
		fscanf(dat, "%d %d", &q->godina, &q->maticni_broj);
		
		while ((sada!=NULL) && (q->godina>sada->godina)) {
			prev=sada;
			sada=sada->NEXT;
		}
		
		q->NEXT=sada;
		prev->NEXT=q;	
	
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


void izbrisi (Pok T, int god, int mat) {
	Pok temp, prev=T;
	T=T->NEXT;
	while (T!=NULL) {
		if ((T->godina==god)&&(T->maticni_broj==mat)) {
			temp=T;
			prev->NEXT=T->NEXT;
			T=T->NEXT;
			free (temp);
		}	
		
		prev=T;
		T=T->NEXT;
	
	
	}



}



int main() {
	struct student head;
	head.NEXT=NULL;
	unos(&head);
	ispis(&head);
	int god, mat;
	printf("Unesi godinu trazenog elementa:\n");
	scanf("%d", &god);
	printf("Unesi mat broj trazenog elementa:\n");
	scanf("%d", &mat);
	izbrisi(&head, god, mat);
	ispis(&head);
	



	return 0;
}




