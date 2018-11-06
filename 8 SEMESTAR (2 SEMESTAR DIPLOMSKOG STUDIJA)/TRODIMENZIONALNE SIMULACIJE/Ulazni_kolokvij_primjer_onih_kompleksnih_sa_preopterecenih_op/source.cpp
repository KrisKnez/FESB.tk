#include <iostream>
#include "Complexx.h"


int wmain(){

// deklaracija nekoliko varijabli
	Complexx a = Complexx(4, 5);
	Complexx b = Complexx(6, 7);
	Complexx *p = new Complexx(2, 3);

	std::cout<<"Komplexsni brojevi: "<<std::endl;
	std::cout<<"a: "; 
	a.DisplayResult();
	std::cout<<"b: "; 
	b.DisplayResult();
	std::cout<<"*p: "; 
	p->DisplayResult();


	Complexx c = a + b;
	Complexx umn = a * b;
	Complexx kol = b / a;
	Complexx d = a - p;
	

	std::cout<<"a + b: "; 
	c.DisplayResult();

	delete(p);

	std::cout<<"a - *p: "; 
	d.DisplayResult();

	std::cout<<"a * b: "; 
	umn.DisplayResult();
	std::cout<<"b / a: "; 
	kol.DisplayResult();
}