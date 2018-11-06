#include <iostream>
#include <string>
using namespace std;

void main()
{
	string word="omiljeni lik";
	int num=8;
	cout<<num/2<<"+"<<num%4<<endl;
	cout<<8<<"8"<<endl<<8+10*num<<endl;
	cout<<word.substr(word.find("mi"),3)<<"ko"<<endl;
}