#include <iostream>
#define MAX(a,b) ((a)>(b))?(a):(b)
int main()
{
	int x=0,y=2,z;
	if(z=MAX(x,y))
		std::cout<<"Vrijednsot z je: "<<z;
	return 0;
}