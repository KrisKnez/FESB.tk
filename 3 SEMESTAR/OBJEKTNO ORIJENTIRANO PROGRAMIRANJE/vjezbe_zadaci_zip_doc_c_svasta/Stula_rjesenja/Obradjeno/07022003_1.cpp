#include <iostream>
int y=0;
void main(void)
{
	std::cout<<y;
	if(++y)
	{
		int y=5;
		std::cout<<++y; 
		::y=y;
	}
	std::cout<<y;
}