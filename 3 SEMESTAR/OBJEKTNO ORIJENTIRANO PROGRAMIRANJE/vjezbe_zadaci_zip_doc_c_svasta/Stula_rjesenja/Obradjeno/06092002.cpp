#include <iostream>
#include <vector>
using namespace std;
void KumulativnaSuma(vector <int> &v)
{
	for(int i=1;i<v.size();i++)
		v[i]=v[i]+v[i-1];


}

int main()
{
	int x;
	vector <int> v;


	while(cin>>x)
	{
		v.push_back(x);
	}


	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;

	KumulativnaSuma(v);

	for(i=0;i<v.size();i++)
		cout<<v[i]<<endl;

	return 0;
}