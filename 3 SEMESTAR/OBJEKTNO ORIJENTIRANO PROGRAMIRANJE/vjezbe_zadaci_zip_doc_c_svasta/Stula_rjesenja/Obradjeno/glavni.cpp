#include <iostream>
#include <string>
using namespace std;
string ToString(int a)
{
	string temp="";
	
	
	while(a%10)
	{
		int b=(a%10);
		char c;
		
		c='0'+b;

		temp=temp+c;
		a=a/10;
	}
	
	for(int i=0;i<=temp.length()/2;i++)
	{
		int g;
		g=temp[i];
		temp[i]=temp[temp.length()-i-1];
		temp[temp.length()-i-1]=g;
	}
	
	return temp;
}

string ToString(bool a)
{
	string temp="";
	
	if(a==true)
		temp="true";
	else
		temp="false";
	
	return temp;
}


string ToString(double a)
{
	string temp="",temp2="";
	int cijeli;
	double ostatak=0;
	
	cijeli=a;
	
	ostatak=a-cijeli;


	while(cijeli%10)
	{
		int b=(cijeli%10);
		char c;
		
		c='0'+b;

		temp=temp+c;
		cijeli=cijeli/10;
	}
	
	for(int i=0;i<=temp.length()/2;i++)
	{
		int g;
		g=temp[i];
		temp[i]=temp[temp.length()-i-1];
		temp[temp.length()-i-1]=g;
	}
	
	temp=temp+".";

	int z=ostatak*10;
	ostatak=ostatak*10;
	ostatak=ostatak-z;

	while(z)
	{
		char c;
		
		c='0'+z;

		temp2=temp2+c;

		z=ostatak*10;
		ostatak=ostatak*10;
		ostatak=ostatak-z;

	}

	for(i=0;i<=temp2.length()/2;i++)
	{
		int g;
		g=temp2[i];
		temp2[i]=temp2[temp2.length()-i-1];
		temp2[temp2.length()-i-1]=g;
	}

	temp=temp+temp2;

	return temp;
}

main()
{
	int a;
	string b;
	bool d;
	double e;

	cin>>a;

	b=ToString(a);
	
	cout<<"string je"<<b<<endl;

	cin>>d;

	b=ToString(d);
	
	cout<<"string je"<<b<<endl;

	cin>>e;

	b=ToString(e);
	
	cout<<"string je"<<b<<endl;

}