class Razlomak
{
	int m_brojnik,m_nazivnik;
public:
	Razlomak(){}
	Razlomak(int brojnik, int nazivnik=1)
	{	m_brojnik=brojnik;
		m_nazivnik=nazivnik;}
	int Brojnik() const;
	int Nazivnik() const {return m_nazivnik;}
	void Brojnik(int br);
	void Nazivnik(int naz);
};
int Razlomak::Brojnik() const
{	return m_brojnik;}
void Razlomak::Brojnik(int br)
{	m_brojnik=br;}
void Razlomak::Nazivnik(int naz)
{	m_nazivnik=naz;}
Razlomak operator+(const Razlomak &r,const  Razlomak &s)
{	Razlomak temp;
	int nazivnik,brojnik;
	nazivnik=r.Nazivnik()*s.Nazivnik();
	brojnik=r.Brojnik()*s.Nazivnik()+s.Brojnik()*r.Nazivnik();
	temp.Brojnik(brojnik);
	temp.Nazivnik(nazivnik);
	return temp;}
Razlomak operator-(const Razlomak &r,const  Razlomak &s)
{	Razlomak temp;
	int nazivnik,brojnik;
	nazivnik=r.Nazivnik()*s.Nazivnik();
	brojnik=r.Brojnik()*s.Nazivnik()-s.Brojnik()*r.Nazivnik();
	temp.Brojnik(brojnik);
	temp.Nazivnik(nazivnik);
	return temp;}
Razlomak operator*(const Razlomak &r,const  Razlomak &s)
{	Razlomak temp;
	int nazivnik,brojnik;
	nazivnik=r.Nazivnik()*s.Nazivnik();
	brojnik=r.Brojnik()*s.Brojnik();
	temp.Brojnik(brojnik);
	temp.Nazivnik(nazivnik);
	return temp;}
#include <iostream.h>
istream & operator>>(istream &in, Razlomak &r)
{	int a,b;
	in>>a>>b;
	r.Brojnik(a);
	r.Nazivnik(b);
	return in;}
ostream & operator<<(ostream &out, Razlomak &r)
{		out<<r.Brojnik()<<"/"<<r.Nazivnik()<<endl;
		return (out); }
void main()
{
	Razlomak a(4),b(7,5),c;
	c=a+b;
	cout<<c.Brojnik()<<"/"<<c.Nazivnik()<<endl;
	c=a-b;
	cout<<c.Brojnik()<<"/"<<c.Nazivnik()<<endl;
	c=a*b;
	cout<<c.Brojnik()<<"/"<<c.Nazivnik()<<endl;
	cin>>c;
	cout<<c<<endl;
}

