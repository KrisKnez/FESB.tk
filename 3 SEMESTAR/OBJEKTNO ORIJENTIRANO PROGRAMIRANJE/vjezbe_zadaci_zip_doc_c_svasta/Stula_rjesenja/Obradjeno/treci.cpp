#include <vector>
#include <iostream>
using namespace std;

class NumberStack
{
public:
	void push(const double num);
	void pop(double &num);
	bool empty() const {return m_Stack.empty();}
	int size() const {return m_Stack.size();}
private:
	vector<double> m_Stack;
};
void NumberStack::push(const double num)
{
	m_Stack.push_back(num);
}
void NumberStack::pop(double &num)
{
	if (size()>0)
	{
		num=m_Stack[size()-1];
		m_Stack.pop_back();
	}
}
void main()
{
	NumberStack moj;
	double tmp;

	cout<<"unesite proizvoljan niz brojeva"<<endl;

	while(cin>>tmp)
		moj.push(tmp);
		

	if(moj.empty())
		cout<<"nije izvrsen unos"<<endl;
	else
	{
		cout<<"uneseno je "<< moj.size() << "brojeva i to:"<<endl;
		while(!moj.empty())
		{
			moj.pop(tmp);
			cout<<tmp<<endl;
		}
	}
	
}