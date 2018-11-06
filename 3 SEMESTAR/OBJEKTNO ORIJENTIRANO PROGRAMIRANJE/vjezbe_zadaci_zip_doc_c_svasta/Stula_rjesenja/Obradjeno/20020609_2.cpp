#include <iostream>
#include <fstream>

using namespace std;
class moj
{
public:
	int a,b;
};
void main()
{
	ofstream pisi("ime.dat");
	moj tmp1,tmp2;
	cin>>tmp1.a>>tmp1.b;
	cin>>tmp2.a>>tmp2.b;
	pisi.write((char *)&tmp1,sizeof(tmp1));
	pisi.write((char *)&tmp2,sizeof(tmp2));
	pisi.close();
	ifstream citaj("ime.dat");
	moj aa;
	if(!citaj) exit(1);
	//cout<<citaj.width()/sizeof(aa)<<endl;
	//citaj.
	//for(int i=0;i<2;i++)
	//for(int i=0;i<citaj.width()/sizeof(aa);i++)
	for(int i=0;;)
	{
		if(citaj.eof())
			break;
		citaj.read((char *)&aa,sizeof(aa));
		cout<<aa.a<<aa.b<<endl;
		
	}
}