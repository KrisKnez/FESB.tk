#include <iostream>
#include <String>
using namespace std;
/*string ZamijeniSlova(const string str)
{
	string temp(str);
	for(int i=0;i<=str.length()-1;i++)
		temp[i]=toupper((int) str[i]);

	return (temp);

}*/
string DvostrukiSamoglasnici(const string str)
{
	string temp;


	for(int i=0;i<=str.length()-1;i++)
	{
		if(str[i]!='a' && str[i]!='A' && str[i]!='e' && str[i]!='E' && str[i]!='i'
			&& str[i]!='I' && str[i]!='o' && str[i]!='O' && str[i]!='u' && str[i]!='U')
			temp=temp+str[i];
		else
		{
			temp=temp+str[i];
			temp=temp+str[i];
		}
	}
	return (temp);

}
void main()
{
string s = "Hello World!";
cout<< DvostrukiSamoglasnici(s);

}
