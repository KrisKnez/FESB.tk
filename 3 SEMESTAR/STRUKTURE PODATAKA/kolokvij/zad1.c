/*1. Definirati strukturu koja se sastoji od matiènog broja studenta i godine roðenja i napisati funkciju (jednu!) koja
uèitava dva razlièita popisa studenata iz datoteka te ih upisuje u liste na naèin da redoslijed elemenata u listi bude
identièan onome u datoteci. Te liste je potrebno ispisati. Nakon toga napisati funkciju koja æe dopisati u prvu listu
sve one studente koji sue pojavljuju u drugoj listi, a nisu veæ upisani u prvu. Potrebno je ponovno ispisati prvu listu.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct student* pos;
struct student
{
	int mbroj;
	int godina;
	pos next;
};

void Ucitaj(pos L1,pos L2)
{
	FILE* dat;
	pos q;
	dat=fopen("L1.txt","r");
	if(dat==NULL)
		printf("Greska pri otvaranju!\n");
	else
	{
		while(feof(dat)==0)
		{
			q=(pos)malloc(sizeof(struct student));
			fscanf(dat,"%d %d",&q->mbroj,&q->godina);
			q->next=NULL;
			L1->next=q;
			L1=L1->next;
		}
		fclose(dat);
	}
	
	dat=fopen("L2.txt","r");
	if(dat==NULL)
		printf("Greska pri otvaranju!\n");
	else
	{
		while(feof(dat)==0)
		{
			q=(pos)malloc(sizeof(struct student));
			fscanf(dat,"%d %d",&q->mbroj,&q->godina);
			q->next=NULL;
			L2->next=q;
			L2=L2->next;
		}
		fclose(dat);
	}
}

void Ispisi(pos P)
{
	int i=1;
	while(P)
	{
		printf("%d) %d, %d\n",i,P->mbroj,P->godina);
		P=P->next;
		i++;
	}
	printf("\n");
}

pos NadjiZadnji(pos P)
{
	while(P->next)
		P=P->next;
	return P;
}

void DodajDruguUPrvu(pos L1,pos L2)
{
	pos zadnji=NadjiZadnji(L1);
	pos prva,q;
	while(L2)
	{
		prva=L1;
		while(prva)
		{
			if(prva->mbroj==L2->mbroj&&prva->godina==L2->godina)
				break;
			prva=prva->next;
		}
		if(prva==NULL)
		{
			q=(pos)malloc(sizeof(struct student));
			q->mbroj=L2->mbroj;
			q->godina=L2->godina;
			q->next=NULL;
			zadnji->next=q;
			zadnji=zadnji->next;
		}
		L2=L2->next;
	}
}

void main()
{
	struct student L1,L2;
	L1.next=NULL;
	L2.next=NULL;
	Ucitaj(&L1,&L2);
	printf("LISTA 1:\n");
	Ispisi(L1.next);
	printf("LISTA 2:\n");
	Ispisi(L2.next);
	DodajDruguUPrvu(L1.next,L2.next);
	printf("LISTA 1 + LISTA 2\n");
	Ispisi(L1.next);
}