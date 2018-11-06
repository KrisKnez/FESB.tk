#ifndef _COMPLEXX_H_
#define _COMPLEXX_H_

#include <iostream>

class Complexx{

private:
	double Real;
	double Img;

public:
// constructors
	Complexx ();
	Complexx (double real, double img);
// descructor
	~Complexx ();

// overloaded operators - ovi sta imaju & se prenose preko reference
	Complexx operator+ (Complexx that);
	Complexx& operator- (Complexx* that);
	Complexx operator* (Complexx that);
	Complexx& operator/ (Complexx that);

// public functions
	void DisplayResult();
	std::wstring ToString();
};

#endif _COMPLEXX_H_