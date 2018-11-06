#include <string>
#include <iostream>
using namespace std;
#include "List.h"

int main()
{
	string Ime;

	List<string> L;

	while(cin>>Ime)
	{
		
	//	if(Ime.length()==0)
	//		break;

		if(Ime[0]>='A' && Ime[0]<='Z')
			L.push_front(Ime);
		else
			L.push_back(Ime);
	}

	if(!L.empty())
	{
		L.to_front();
		string *tmp,gl;
		tmp=&gl;
		for(int i=0;i<L.size();i++)
		{
			tmp=L.get_next();
			if(gl[0]>='A' && gl[0]<='Z')
				cout<<gl<<endl;

		}
	}


	return 0;
}