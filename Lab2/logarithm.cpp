/*********************************************************
* Class Logarithm member functions implementation        *
* TNG033: Lab 2                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include <cmath>


//default constructor
Logarithm::Logarithm() : c1{ 0 }, c2{ 1 }, b{ 2 }
{
	double v[2]{ 0,1 };
	E = new Polynomial{ 1, v };
}

//constructor with given values
Logarithm::Logarithm(const Expression& F, int l1, int l2, int a) : c1{ l1 }, c2{ l2 }, b{ a }
{
	E = F.clone();
}

//copy constructor
Logarithm::Logarithm(const Logarithm& source) : c1{ source.c1 }, c2{ source.c2}, b{ source.b }, E{ source.E }
{
}

////destructor
//Logarithm::~Logarithm() {
//	delete E;
//	E = nullptr;
//}

Logarithm& Logarithm::operator=(Logarithm L){
	//std::swap(c1, L.c1);
	//std::swap(c2, L.c2);
	//std::swap(b, L.b);
	c1 = L.c1;
	c2 = L.c2;
	b = L.b;
	std::swap(E, L.E);
	
	return *this;
}

void Logarithm::display(std::ostream& os) const {
	if (c1 != 0) {
		os << c1 << " + ";
	}
	if (c2 != 0) {
		os << c2 << " * Log_" << b << "( " << *E << " )";
	}
}

double Logarithm::operator()(double d) const {
	double sum = 0.0;
	sum = c1 + c2 * (log10(E->operator()(d)) / log10(b));
	return sum;
}
Logarithm* Logarithm::clone() const {
	return new Logarithm{ *this }; //to be edited
}

//ADD implementation of the member functions for class Logarithm
