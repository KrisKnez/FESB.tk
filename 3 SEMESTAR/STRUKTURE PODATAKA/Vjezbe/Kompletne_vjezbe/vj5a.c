/*
Napisati program koji simulira rad stoga pomoæu:
 
Niza
Na stog se spremaju cijeli brojevi.
*/

#include<stdio.h>
#include<stdlib.h>

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	int *Array;
};

void Push(struct StackRecord *);
void Pop(struct StackRecord *);

void main()
{
	struct StackRecord Stack;
	int a=0;

	while(Stack.Capacity<=0)
	{
		printf("\n Upisite kapacitet stoga (>0):  ");
		scanf(" %d", &Stack.Capacity);
	}

	Stack.Array = (int *)malloc(sizeof(int)*Stack.Capacity);

	Stack.TopOfStack = 0;


	while (a != 3)
	{
		printf("\n Unesi:" );
		printf("\n\t 1 - Push");
		printf("\n\t 2 - Pop");
		printf("\n\t 3 - Kraj\n\t");
	
		scanf(" %d", &a);

		switch(a)
		{
		case 1:
			Push (&Stack);
			break;
		case 2:
			Pop (&Stack);
			break;
		case 3:
			printf("\nKraj!\n");
			break;
		default:
			printf("\nPogresan unos\n");
		}
		
	}
}

void Push(struct StackRecord *S)
{
	if(S->TopOfStack == S->Capacity)
		printf("Stog je pun");
	else
	{
		printf("\n\tUnesi element:  ");
		scanf(" %d", &S->Array[S->TopOfStack]);
		S->TopOfStack ++;
	}
}


void Pop(struct StackRecord *S)
{
	if(S->TopOfStack == 0)
		printf("Stog je prazan");
	else
	{
		S->TopOfStack --;
		printf("\n\tSa stoga se skida: %d\n", S->Array[S->TopOfStack]);
	}
}