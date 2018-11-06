#include <iostream>
void main(void)
{
	int y=0;

	std::cout<<y++;

	if(y)
	{
		int y=5;
		std::cout<<y;
	}
	std::cout<<y;
}