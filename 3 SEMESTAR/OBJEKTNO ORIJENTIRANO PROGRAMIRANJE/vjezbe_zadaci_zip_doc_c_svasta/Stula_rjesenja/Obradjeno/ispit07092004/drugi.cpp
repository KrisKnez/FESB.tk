#include <iostream>
#include <vector>
using namespace std;
template <class T> 
void Normaliziraj (vector <T> &v)
{
	T tmp;
	tmp = v[0];
	for (int i=0; i<v.size(); i++)
	{
		if(tmp<v[i])
			tmp=v[i];
	}
	for (i=0; i<v.size(); i++)
	{
		v[i]=v[i]/tmp;
	}
}
void main()
{
	vector <float> moj;
	float g;
	for(int j=0;j<5; j++)
	{
		cin >> g;
		moj.push_back(g);
	}
	for(j=0;j<5; j++)
	{
		cout << moj[j]<<endl;
	}
	Normaliziraj(moj);
	for(j=0;j<5; j++)
	{
		cout << moj[j]<<endl;
	}
}