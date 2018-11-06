#include <iostream.h>
void abc(int *pa,int *pb)
{
	*pa=*pa*4;
	*pb=*pb*3;
}
void main()
{
	int d1=51,d2=12;
	void abc(int *,int *);
	cout<<"d1="<<d1<<" d2="<<d2<<endl;
	abc(&d1,&d2);
	cout<<"d1="<<d1<<" d2="<<d2<<endl;
}

Program ispiše:  

d1=51   d2=12
d1=204  d2=36
                     