/*
Napisati program koji simulira rad reda pomoæu:
 
Niza
Na red se spremaju cijeli brojevi.
*/

#include<stdio.h>
#include<stdlib.h>

struct QueueRecord
{
	int Capacity;
	int BeginOfQueue;
	int TopOfQueue;
	int NoOfEl;
	int *Array;
};

void Push(struct QueueRecord *);
void Pop(struct QueueRecord *);

void main()
{
	struct QueueRecord Queue;
	int a=0;

	while(Queue.Capacity<=0)
	{
		printf("\n Upisite kapacitet reda (>0):  ");
		scanf(" %d", &Queue.Capacity);
	}

	Queue.Array = (int *)malloc(sizeof(int)*Queue.Capacity);

	Queue.BeginOfQueue = 0;
	Queue.TopOfQueue = 0;
	Queue.NoOfEl = 0;


	while (a != 3)
	{
		printf("\n Unesi:" );
		printf("\n\t 1 - Push na red");
		printf("\n\t 2 - Pop sa reda");
		printf("\n\t 3 - Kraj\n\t");
	
		scanf(" %d", &a);

		switch(a)
		{
		case 1:
			Push (&Queue);
			break;
		case 2:
			Pop (&Queue);
			break;
		case 3:
			printf("\nKraj!\n");
			break;
		default:
			printf("\nPogresan unos\n");
		}
		
	}
}

void Push(struct QueueRecord *S)
{
	printf("\n\tUnesi element:  ");
	scanf(" %d", &S->Array[S->TopOfQueue]);

	if(S->TopOfQueue == S->BeginOfQueue && S->NoOfEl != 0)
		S->BeginOfQueue ++;
	else 
		S->NoOfEl++;
	
	S->TopOfQueue ++;

	if(S->TopOfQueue == S->Capacity)
		S->TopOfQueue = 0;

	if(S->BeginOfQueue == S->Capacity)
		S->BeginOfQueue = 0;
}


void Pop(struct QueueRecord *S)
{
	if(S->NoOfEl == 0)
		printf("Red je prazan");
	else
	{
		printf("\n\tSa reda se skida: %d\n", S->Array[S->BeginOfQueue]);
		S->BeginOfQueue ++;
		S->NoOfEl --;

		if(S->BeginOfQueue == S->Capacity)
			S->BeginOfQueue = 0;
		
	}
}