#include <iostream.h>


class Pravokutnik
{
public:
	Pravokutnik();
	~Pravokutnik(){};
	Pravokutnik(const Pravokutnik & tmp)
	{
		m_sirina=tmp.m_sirina;
		m_visina=tmp.m_visina;
		m_x=tmp.m_x;
		m_y=tmp.m_y;
	}
	void SetSirina(int);
	int GetSirina();
	void SetVisina(int);
	int GetVisina();
	int Povrsina();
	void SetX(int x) {m_x=x;}
	void SetY(int y) {m_y=y;}
	int GetX() {return m_x;}
	int GetY() {return m_y;}
	void operator=(const Pravokutnik & tmp);
private:
	int m_sirina;
	int m_visina;
	int m_x,m_y;
};
Pravokutnik::Pravokutnik()
{
	m_sirina=m_visina=1;
	m_x=m_y=0;
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
	m_sirina=tmp.m_sirina;
	m_visina=tmp.m_visina;
	m_x=tmp.m_x;
	m_y=tmp.m_y;
}

void main()
{
	Pravokutnik a;
	cout<<a.GetSirina()<<","<<a.GetVisina()<<","<<a.GetX()<<","<<a.GetY();
	a.SetSirina(3);
	a.SetVisina(4);
	a.SetX(5);
	a.SetY(6);
	Pravokutnik b=a;
	cout<<b.GetSirina()<<","<<b.GetVisina()<<","<<b.GetX()<<","<<b.GetY();
	cout<<a.Povrsina()<<","<<b.Povrsina();

}