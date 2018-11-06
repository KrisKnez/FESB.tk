/*
Napisati program koji simulira rad reda pomoæu:
 
Liste
Na red se spremaju cijeli brojevi.
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct QueueRecord
{
	int El;
	struct QueueRecord * Next;
};

void Push(struct QueueRecord *);
void Pop(struct QueueRecord *);

void main()
{
	struct QueueRecord head = {0, NULL};
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

void Push(struct QueueRecord *S)
{
	struct QueueRecord *q;
	static struct QueueRecord *last = NULL;

	if(S->Next == NULL)
		last = S;
	

	q = (struct QueueRecord *)malloc(sizeof(struct QueueRecord));
	
	if( q==NULL)
		printf("\nGreska kod alokacije memorije!!");
	else
	{
		printf("\n\tUnesi element:  ");
		scanf(" %d", &q->El);


		q->Next = NULL;

		last->Next = q;

		last = q;
	}
}


void Pop(struct QueueRecord *S)
{
	struct QueueRecord *q;

	if(NULL == S->Next)
		printf("\nRed je prazan\n");
	else
	{
		printf("\n\tSa reda se skida: %d\n", S->Next->El);
		
		q = S->Next;
		S->Next = q->Next;

		free(q);
	}
}