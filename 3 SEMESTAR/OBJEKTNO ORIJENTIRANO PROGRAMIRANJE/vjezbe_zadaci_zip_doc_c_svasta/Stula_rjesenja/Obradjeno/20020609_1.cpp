#include <iostream.h>

class Point2D{
protected:
	int m_x,m_y;
public:
	Point2D():m_x(0),m_y(0){}
	void SetX(int a){m_x=a;}
	void SetY(int b){m_y=b;}
	int GetX()const{return m_x;}
	int GetY()const {return m_y;}
};
class Point3D:public Point2D
{
protected:
	int m_z;
public:
	Point3D(const Point3D &);
	Point3D():m_z(0){m_x=0;m_y=0;}
	void SetZ(int c){m_z=c;}
	int GetZ(){return m_z;}
	Point3D& operator=(const Point3D&);
};
Point3D::Point3D(const Point3D &r)
{
	m_x=r.m_x;
	m_y=r.m_y;
	m_z=r.m_z;
}
Point3D& Point3D::operator =(const Point3D&r)
{
	m_x=r.GetX();
	m_y=r.m_y;
	m_z=r.m_z;
	return *this;
}

void main()
{
	Point3D	a,b;
	b.SetX(4);
	b.SetY(5);
	b.SetZ(6);

	a=b;
	cout<<a.GetX()<<a.GetY()<<a.GetZ()<<endl;

}