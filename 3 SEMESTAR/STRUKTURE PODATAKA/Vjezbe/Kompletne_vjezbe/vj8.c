/*Napisati program koji pomoæu vezanih listi (stabala) predstavlja strukturu direktorija.
 Omoguæiti unos novih direktorija i pod-direktorija, ispis sadržaja direktorija i povratak
 u prethodni direktorij. Toènije program treba simulirati korištenje DOS naredbi:
 "md", "cd dir", "cd.." i "dir".*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct direktorij;
typedef struct direktorij dir;
typedef struct direktorij *Node;

struct SimStack;
typedef struct SimStack *Stack;

struct direktorij
{
	char ime[10];
	Node Next;
	Node Child;
};

struct SimStack
{
	Node Element;
	Stack Next;
};

void IspisDir(Node, char *);
Node IzadjiDir(Node, char *, Stack);
Node UdjiDir(Node, char *, char *, Stack);
void StvoriDir(Node, char *);
void Push(Stack, Node);
Node Pop(Stack);


void main()
{ 
	char instr[20], ime[10], naredba[10], path[100];
	char *i, *j;
	dir root;
	struct SimStack S;

	Node UpDir = &root;
	S.Next = NULL;

	printf("Unesi ime root direktorija: ");
	scanf(" %s", root.ime);
	root.Child = NULL;
	root.Next = NULL;
	
	path[0] = 0;
	strcat(path, root.ime);
	strcat(path, ":\\");

	system("cls");
	
	printf("Unesi naredbu:");
	printf("\n\tdir");
	printf("\n\tcd..");
	printf("\n\tcd ime_dir");
	printf("\n\tmk ime_dir");
	printf("\n\n\texit - za kraj");
	printf("\n\n\t");

	fgets(instr, 20,stdin);
	
	while(strcmp(naredba, "exit")!=0)
	{
		printf("\n\n\t%s",path);
		
		strset(ime, 0);
		strset(naredba, 0);

		fgets(instr, 20,stdin);

		i = strchr(instr, ' ');
		
		if (NULL == i)
		{
			strncpy(naredba, instr, sizeof(instr));
			j = strchr(naredba, 10);
			*j = 0;
		}
		else
		{
			strncpy(naredba, instr, i - instr);
			naredba[i-instr] = 0;
			strcpy(ime, i+1);
		}

		if(strcmp(naredba, "dir")==0)
			IspisDir(UpDir, path);
		else if(strcmp(naredba, "cd..")==0)
			UpDir = IzadjiDir(UpDir, path, &S);
		else if(strcmp(naredba, "cd")==0)
			if(ime[0] == 0)
				printf("Greska u sintaksi naredbe!\n Treba biti: cd ime_dir");
			else
				UpDir = UdjiDir(UpDir, ime, path, &S);
		else if(strcmp(naredba, "mk")==0)
			if(ime[0] == 0)
				printf("Greska u sintaksi naredbe!\n Treba biti: mk ime_dir");
			else
				StvoriDir(UpDir, ime);
		else if(strcmp(naredba, "exit")!=0)
			printf("\nPogresan unos!!\n");

	}

}


void IspisDir(Node N, char * path)
{
	int i = 0;
	printf("\nDirectory of %s", path);
	
	N = N->Child;
	while(N != NULL)
	{
		printf("\n\t\t %s", N->ime);
		N = N->Next;
		i++;
	}

	printf("\n\t\t %d Dir(s)", i);


}


Node IzadjiDir(Node N, char *path, Stack S)
{
	Node temp;
	char *a;

	temp = Pop(S);
	if(NULL == temp)
	{
		printf("Nalazimo se u root direktoriju!\nIz njega se ne moze izaci!");
		return N;
	}
	else
	{
		a = strrchr(path, '\\');
		*a = 0;

		a = strrchr(path, '\\');
		*(a+1) = 0;
	
		return temp;
	}
}


Node UdjiDir(Node N, char *ime, char *path, Stack S)
{
	Node temp = N->Child;
	char *a;


	while(temp != NULL && strcmp(temp->ime, ime)!= 0)
		temp = temp->Next;
	if (NULL == temp)
		printf("\n Ne postoji pod-direktorij s tim imenom!!!");
	else
	{
		Push(S, N);
		strcat(path, temp->ime);
		a = strchr(path, 10);
		*a = '\\';
		return temp;
	}

	return N;
}


void StvoriDir(Node N, char *ime)
{
	Node q;

	q = (Node)malloc(sizeof(dir));
	q->Child = NULL;
	q->Next = NULL;

	strcpy(q->ime, ime);

	if(NULL == q)
		printf("\nGreska u alokaciji memorije!!");
	else
	{
		if ( NULL == N->Child)
			N->Child = q;
		else
		{
			q->Next = N->Child;
			N->Child = q;
		}
	}
}

void Push(Stack S, Node T)
{
	Stack q;

	q = (Stack)malloc(sizeof(struct SimStack));

	if( q==NULL)
		printf("\nGreska kod alokacije memorije!!");
	else
	{
		q->Element = T;
		q->Next = S->Next;

		S->Next = q;
	}
}


Node Pop(Stack S)
{
	Node q;
	Stack temp;

	if(NULL == S->Next)
		return NULL;
	else
	{
		q = S->Next->Element;
		temp = S->Next;
		S->Next = temp->Next;

		free(temp);
		return q;
	}
}