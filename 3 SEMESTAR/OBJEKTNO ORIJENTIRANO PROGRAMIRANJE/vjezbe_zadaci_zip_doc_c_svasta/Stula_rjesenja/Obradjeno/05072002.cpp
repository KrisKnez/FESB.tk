#include <iostream.h>
int a(int i) {return ++i;}
int b(int &ir) {return ++ir;}
int c(int *ia) {return ++(*ia);}

void main()
{
	int i=0;
	cout<<i<<endl;
	b(i);
	cout<<i<<endl;
	a(i);
	cout<<i<<endl;
	c(&i);
	cout<<i<<endl;
}