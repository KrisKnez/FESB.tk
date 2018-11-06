#include <iostream>
using namespace std;

int A(int x, int y=1)
{
	return x+y;
}
void B(int &x, int y=1)
{
	x=y;
}
int main()
{
	int a=1, b=2, c;
	a=A(b);
	cout <<"a=" << a << endl;
	B(b);
	cout <<"b=" << b << endl;

	B(c, A(a,2));
	cout << "c=" << c <<endl;

	c=6;
	cout<<9<<"9"<<endl;
	cout << (c<<1)<<endl;
	return 0;
}