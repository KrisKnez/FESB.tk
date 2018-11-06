#include <iostream>
#include <vector>
using namespace std;

int main()
{
	double x;
	vector <double> v;


	while(cin>>x)
	{
		if(x<0)
			break;
		v.push_back(x);
	}


	for(int i=v.size()-1;i>=0;i--)
		cout<<v[i]<<endl;
	return 0;
}