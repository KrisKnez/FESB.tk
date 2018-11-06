#include <vector>
#include <iostream>
using namespace std;
class NumberStack
{
public:
	void push(const double num);
	double pop();
	bool empty() const {return m_Stack.empty();}
	int size() const {return m_Stack.size();}
private:
	vector <double> m_Stack;
};
void NumberStack::push(const double num)
{
	m_Stack.push_back(num);
}
double NumberStack::pop()
{
	double tmp;
	if(m_Stack.size()>0)
	{
		tmp=m_Stack[m_Stack.size()-1];
		m_Stack.pop_back();
	}
	else
		tmp=-1;

	return tmp;
}
void main()
{
	NumberStack moj;
	for(int i=0;i<4;i++)
		moj.push((double)i);
	moj.pop();
}
