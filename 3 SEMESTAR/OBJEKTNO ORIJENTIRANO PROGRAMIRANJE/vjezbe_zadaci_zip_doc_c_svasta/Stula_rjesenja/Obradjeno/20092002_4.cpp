
#include "List.h"
//#include "tvector.h"

void SortListToVector(List <double> &L, vector <double> &V)
{

L.to_front();
double *temp,temp2,a;

for (int i=0;i<L.size();i++)
{
	temp=L.get_next();

	a=*temp;

	V.push_back(a);

}

for (i=0;i<V.size()/2;i++)
{
	if(V[i]>=V[V.size()-i-1])
	{
		temp2=V[i];
		V[i]=V[V.size()-i-1];
		V[V.size()-i-1]=temp2;
	}
}



}


void main()
{
	List <double> neka;
	vector <double> vec;
	double pom;

	while(cin>>pom)
		neka.push_back(pom);

	SortListToVector(neka,vec);


	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<endl;

}


