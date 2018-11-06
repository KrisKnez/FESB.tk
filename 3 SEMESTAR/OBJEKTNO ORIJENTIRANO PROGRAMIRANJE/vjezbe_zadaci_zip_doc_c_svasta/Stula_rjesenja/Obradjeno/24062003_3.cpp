#include <iostream.h>
class Tocka
{
	int m_x,m_y;
public:
	Tocka()
	{m_x=0;
	m_y=0;
	}
	void SetX(int x){m_x=x;}
	void SetY(int y){m_y=y;}
	int GetX(){return m_x;}
	int GetY(){return m_y;}
};

class Pravokutnik
{
public:
	Pravokutnik();
	~Pravokutnik(){};
	Pravokutnik(const Pravokutnik & tmp)
	{
		Tocka b;
		b=tmp.a;
		m_sirina=tmp.m_sirina;
		m_visina=tmp.m_visina;
		a.SetX(b.GetX());
		a.SetY(b.GetY());
	}
	void SetSirina(int);
	int GetSirina();
	void SetVisina(int);
	int GetVisina();
	int Povrsina();
	/*void SetX(int x) {m_x=x;}
	void SetY(int y) {m_y=y;}
	int GetX() {return m_x;}
	int GetY() {return m_y;}*/
	void operator=(const Pravokutnik & tmp);
private:
	int m_sirina;
	int m_visina;
	Tocka a;
};
Pravokutnik::Pravokutnik()
{
	m_sirina=m_visina=1;
//	m_x=m_y=0;
}

void Pravokutnik::SetSirina(int a)
{
	m_sirina=a;
}
int Pravokutnik::GetSirina()
{
	return m_sirina;
}
void Pravokutnik::SetVisina(int a)
{
	m_visina=a;
}
int Pravokutnik::GetVisina()
{
	return m_visina;
}
int Pravokutnik::Povrsina()
{
	return m_visina*m_sirina;
}


void Pravokutnik::operator =(const Pravokutnik & tmp)
{
		Tocka b;
		b=tmp.a;

	m_sirina=tmp.m_sirina;
	m_visina=tmp.m_visina;
		a.SetX(b.GetX());
		a.SetY(b.GetY());
}

void main()
{
	Pravokutnik a,c;
	cout<<a.GetSirina()<<","<<a.GetVisina()<<","<<endl;
	cout<<c.GetSirina()<<","<<c.GetVisina()<<","<<endl;

	a.SetSirina(3);
	a.SetVisina(4);
	c=a;
	Pravokutnik b=a;
	cout<<b.GetSirina()<<","<<b.GetVisina()<<","<<endl;
	cout<<c.GetSirina()<<","<<c.GetVisina()<<","<<endl;

	cout<<a.Povrsina()<<","<<b.Povrsina();

}