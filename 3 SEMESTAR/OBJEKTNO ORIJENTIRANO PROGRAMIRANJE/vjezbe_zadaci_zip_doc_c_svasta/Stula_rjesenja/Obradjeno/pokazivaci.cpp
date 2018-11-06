#include <iostream>
using namespace std;

struct broj
{
	int a;
	float b;
} dupli;

void zamjeni (int *, int *);
void zamjeni (int &, int &);
void zamjeni (struct broj *, struct broj *);

void main()
{
	struct broj jen,dva;
	int x,y;
	cin>>x>>y;
	cout<<x<<","<<y<<endl;
	zamjeni(&x,&y);
	cout<<x<<","<<y<<endl;
	zamjeni(x,y);
	cout<<x<<","<<y<<endl;
	cin>>jen.a>>jen.b;
	cin>>dva.a>>dva.b;
	cout<<jen.a<<","<<jen.b<<endl;
	cout<<dva.a<<","<<dva.b<<endl;
	zamjeni(&jen,&dva);
	cout<<jen.a<<","<<jen.b<<endl;
	cout<<dva.a<<","<<dva.b<<endl;


}

void zamjeni (int *a, int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
void zamjeni (int &a, int &b)
{
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}
void zamjeni (struct broj *a, struct broj *b)
{
	struct broj v;
	v.a=a->a;
	v.b=a->b;
	a->a=b->a;
	a->b=b->b;
	b->a=v.a;
	b->b=v.b;
}
