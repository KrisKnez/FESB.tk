/*
Napisati program za zbrajanje i množenje polinoma. 
Iz datoteke se èitaju koeficijenti složeni prema rastuæim eksponentima i
maksimalni eksponent je 10 (implementacija s nizovima). 
*/


#include<stdio.h>
#include<stdlib.h>

#define MaxDegree 10

struct Polynomial
{
	int CoeffArray[MaxDegree + 1];
	int HighPower;
};

typedef struct Polynomial * Polynom;

void ZeroPolynomial(Polynom Poly);
void ReadPolynomial(Polynom, char *);
void PrintPolynomial(struct Polynomial);
void AddPolynomial(Polynom, Polynom, Polynom);
void MulPolynomial(Polynom, Polynom, Polynom);

int Max(int, int);


void main()
{
	struct Polynomial P1, P2, S, P;
		
	ZeroPolynomial(&P1);
	ReadPolynomial(&P1, "P1_niz.txt");
	PrintPolynomial(P1);

	ZeroPolynomial(&P2);
	ReadPolynomial(&P2, "P2_niz.txt");
	PrintPolynomial(P2);



	ZeroPolynomial(&S);
	AddPolynomial(&P1, &P2, &S);
	printf("\n\nSuma je:");
	PrintPolynomial(S);

	ZeroPolynomial(&P);
	MulPolynomial(&P1, &P2, &P);
	printf("\n\nProdukt je:");
	PrintPolynomial(P);

	printf("\n");
}

void ZeroPolynomial(Polynom Poly)
{
	int i;

	for(i=0; i<=MaxDegree; i++)
		Poly->CoeffArray[i] = 0;
	
	Poly->HighPower = 0;
}

void ReadPolynomial(Polynom P, char *ime_dat)
{
	FILE *dat;
	int i;

	dat = fopen(ime_dat, "r");
	if (NULL == dat)
	{
		printf("Greska u otvaranju datoteke!!!");
		exit(1);
	}
	else
	{
		i = 0;
		while (i<=MaxDegree && 0 == feof(dat))
		{
				fscanf(dat, " %d", &P->CoeffArray[i]); 
				i++;
		}
	}

	i = MaxDegree;
	while(P->CoeffArray[i] == 0 && i != 0)
		i--;

	P->HighPower = i;

}

void PrintPolynomial(struct Polynomial P)
{
	int i;

	printf("\n");

	for(i=P.HighPower; i>=0; i--)
		if(P.CoeffArray[i] > 0)
			printf("\t +%d*x^%d", P.CoeffArray[i], i);
		else if(P.CoeffArray[i] < 0)
			printf("\t %d*x^%d", P.CoeffArray[i], i);
	
	printf("\n");
}

void AddPolynomial(Polynom P1, Polynom P2, Polynom S)
{
	int i;

	S->HighPower = Max(P1->HighPower, P2->HighPower);

	for(i = S->HighPower; i>=0; i--)
		S->CoeffArray[i] = P1->CoeffArray[i] + P2->CoeffArray[i];

}

int Max(int x, int y)
{
	if ( x > y )
		return x;
	else
		return y;

}

void MulPolynomial(Polynom P1, Polynom P2, Polynom P)
{
	int i, j;

	P->HighPower = P1->HighPower + P2->HighPower;

	if (P->HighPower > MaxDegree)
		printf("Produkt je nemoguce izracunati jer je rezultantni niz prevelike dimenzije!");
	else
	for(i = P1->HighPower; i>=0; i--)
		for(j = P2->HighPower; j>=0; j--)
			P->CoeffArray[i+j] = P->CoeffArray[i+j] + P1->CoeffArray[i] * P2->CoeffArray[j];

}
