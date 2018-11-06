/*
Napisati program koji simulira rad stoga pomoæu:
 
Niza
Na stog se spremaju cijeli brojevi.
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h >

struct StackRecord
{
	int El;
	struct StackRecord * Next;
};

void Push(struct StackRecord *);
void Pop(struct StackRecord *);

void main()
{
	struct StackRecord head = {0, NULL};
	char a=0;

		
	while (a != 27)
	{
		printf("\n Unesi:" );
		printf("\n\t 1   - Push");
		printf("\n\t 2   - Pop");
		printf("\n\t ESC - Kraj\n\n\t");
	
		a = getch();

		switch(a)
		{
		case '1':
			Push (&head);
			break;
		case '2':
			Pop (&head);
			break;
		case 27:
			printf("\nKraj!\n");
			break;
		default:
			printf("\nPogresan unos\n");
		}
		
	}
}

void Push(struct StackRecord *S)
{
	struct StackRecord *q;

	q = (struct StackRecord *)malloc(sizeof(struct StackRecord));

	if( q==NULL)
		printf("\nGreska kod alokacije memorije!!");
	else
	{
		printf("\n\tUnesi element:  ");
		scanf(" %d", &q->El);

		q->Next = S->Next;

		S->Next = q;
	}
}


void Pop(struct StackRecord *S)
{
	struct StackRecord *q;

	if(NULL == S->Next)
		printf("\nStog je prazan\n");
	else
	{
		printf("\n\tSa stoga se skida: %d\n", S->Next->El);
		
		q = S->Next;
		S->Next = q->Next;

		free(q);
	}
}