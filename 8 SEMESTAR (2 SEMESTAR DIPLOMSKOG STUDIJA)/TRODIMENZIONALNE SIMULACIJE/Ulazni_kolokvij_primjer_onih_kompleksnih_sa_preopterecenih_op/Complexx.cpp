// Complexx class functions implementations
#include "Complexx.h"


// constructors
Complexx::Complexx() : Real(0), Img(0) { }
Complexx::Complexx (double real, double img) : Real(real), Img(img){}

//descructor
Complexx::~Complexx(){ }

// overloaded oparators
Complexx Complexx::operator+ (Complexx that){
		
	Complexx temp;
	temp.Real = this->Real + that.Real;
	temp.Img = this->Img + that.Img;
	return temp;
}

Complexx& Complexx::operator- (Complexx* that){

	this->Real = this->Real - that->Real;
	this->Img = this->Img - that->Img;

	return *this;
}

Complexx Complexx::operator* (Complexx that){

	Complexx temp;
	temp.Real = ((this->Real*that.Real)-(this->Img*that.Img));
	temp.Img = ((this->Real*that.Img)+(this->Img*that.Real));
	return temp;
}

Complexx& Complexx::operator/ (Complexx that){

	double tempReal = (((this->Real*that.Real)+(this->Img*that.Img))/((that.Real*that.Real)+(that.Img*that.Img)));
	double tempImg = (((this->Img*that.Real)-(this->Real*that.Img))/((that.Real*that.Real)+(that.Img*that.Img)));

	this->Real = tempReal;
	this->Img = tempImg;

	return *this;
}

// public functions
void Complexx::DisplayResult(){
	std::cout<<this->Real<<"+"<<this->Img<<"i"<<std::endl;
}