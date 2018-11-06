#include<stdio.h>
#include<stdlib.h>

struct list
{
	int Element;
	struct list *Next;
};

void ReadList(struct list *, char *);
void PrintList(struct list *);
void Unija(struct list *, struct list *, struct list *);
void Presjek(struct list *, struct list *, struct list *);

void main()
{
	struct list L1, L2, U, P;

	L1.Next = NULL;
	L2.Next = NULL;
	U.Next = NULL;
	P.Next = NULL;

	ReadList(&L1, "L1.txt");
	PrintList(&L1);

	ReadList(&L2, "L2.txt");
	PrintList(&L2);

	printf("\n \nUnija je: \n");
	Unija(L1.Next, L2.Next, &U);
	PrintList(&U);


	printf("\n \nPresjek je: \n");
	Presjek(L1.Next, L2.Next, &P);
	PrintList(&P);

}


void ReadList(struct list *P, char *ime_dat)
{
	FILE *dat;
	struct list *q, *temp, *prev;

	dat = fopen(ime_dat, "r");
	if (NULL == dat)
	{
		printf("Greska u otvaranju datoteke!!!");
		exit(1);
	}
	else
	{
		while (0 == feof(dat))
		{
			q = (struct list *)malloc(sizeof(struct list));
			
			fscanf(dat, " %d", &q->Element); 

			temp = P->Next;
			prev = P;
			while(temp != NULL && temp->Element < q->Element  )
			{
				prev = temp;
				temp = temp->Next;
			}
				
			prev->Next = q;

			if (temp != NULL)
				q->Next = temp;
			else 
				q->Next = NULL;
		}
	}


}


void PrintList(struct list *P)
{

	printf("\n");

	P = P->Next;

	while(P != NULL)
	{
		printf("\t%d", P->Element);
		P = P->Next;	
	}
		

	printf("\n");

}

void Unija(struct list *L1, struct list *L2, struct list *U)
{
	struct list *q, *p;

	
	while (L1 && L2)
	{
		q = (struct list *)malloc(sizeof(struct list));
		U->Next = q;
		q->Next = NULL;

		if(L1->Element < L2->Element)
		{
			q->Element = L1->Element;
			L1 = L1->Next;
		}
		else if(L2->Element < L1->Element)
		{
			q->Element = L2->Element;
			L2 = L2->Next;
		}
		else
		{
			q->Element = L1->Element;
			L1 = L1->Next;
			L2 = L2->Next;
		}
	
	
		U = U->Next;
	}

	if(L1)
		p = L1;
	else
		p = L2;

	while(p)
	{
		q = (struct list *)malloc(sizeof(struct list));
		U->Next = q;
		q->Next = NULL;
		q->Element = p->Element;
		U = U->Next;
		p = p->Next;
	}
 
}





void Presjek(struct list *L1, struct list *L2, struct list *P)
{
	struct list *q, *p;

	
	while (L1 && L2)
	{
		if(L1->Element < L2->Element)
			L1 = L1->Next;
		else if(L2->Element < L1->Element)
			L2 = L2->Next;
		else
		{
			q = (struct list *)malloc(sizeof(struct list));
			P->Next = q;
			q->Next = NULL;

			q->Element = L1->Element;
			L1 = L1->Next;
			L2 = L2->Next;
			
			P = P->Next;
		}
	}
}