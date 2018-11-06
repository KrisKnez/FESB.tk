#include <iostream>
#include <string>

using namespace std;

string N_Znakova(string str, int n)
{
	string tmp="              ";
	if(str.length()>=n)
	{
		for(int i=0;i<n;i++)
			tmp[i]=str[i];
	}
	else
	{
		for(int j=0;j<str.length();j++)
			tmp[j]=str[j];
		for(int k=j-1;k<n;k++)
			tmp[k]='_';
	}
		
return tmp;

}
void main()
{
string a;
int b;
cin>>a;
cin>>b;
cout<<N_Znakova(a,b);
}