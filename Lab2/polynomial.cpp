/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"
#include <cmath>

//ADD implementation of the member functions for class Polynomial
//Default constructor
Polynomial::Polynomial() : degree{0}, coefficients{nullptr}
{
    
}

//Constructor from array
Polynomial::Polynomial(int n, double v[]) : degree{n}, coefficients{new double[degree + 1]}
{
    //gör samma som polygon i föreläsning
    for(int i = 0; i < degree+1; i++) {
        coefficients[i]=v[i];
    }
}

//constructor from double
Polynomial::Polynomial(const double d) : degree{0}, coefficients{new double[1]{d}}
{
}

//copy constructor
Polynomial::Polynomial(const Polynomial& source) : degree{source.degree}, coefficients{new double[source.degree + 1]}
{
    for(int i = 0; i < degree + 1; i++) {
        coefficients[i] = source.coefficients[i];
    }
}

//destructor
Polynomial::~Polynomial() {
	delete[] coefficients;
	coefficients = nullptr;
}

Polynomial& Polynomial::operator=(Polynomial P)
{
    
    //ADD CODE
    //std::swap(degree, P.degree);
	degree = P.degree;
    std::swap(coefficients, P.coefficients);
    
    //swap coefficients
    
    return *this; //to be deleted
}

//Addition operator
Polynomial Polynomial::operator+=(const Polynomial& P) 
{
    //ADD CODE
	Polynomial temp{}; //empty 

	if (this->degree <= P.degree) {
		
		temp = P;

		for (int i = 0; i <= this->degree; i++) {
			temp.coefficients[i] += this->coefficients[i];
		}

		*this = temp;
	}
	else {
		for (int i = 0; i <= P.degree; i++) {
	
			this->coefficients[i] += P.coefficients[i];
		}
	}

    return *this; //to be deleted
}

//operator()
double Polynomial::operator()(double d) const
{
    double sum = 0;
    
    for(int i = 0; i <= degree; i++){
        sum += coefficients[i]*pow(d,i);
    }
    
    return sum; //to be deleted
}

//subscript operator
double& Polynomial::operator[](int i)
{
    double d = 0.0; //no such coefficient exists
	if (i <= degree) {
		return coefficients[i];
	}

	//felmeddelande vid out
	std::cout << "No such coefficient exists" << std::endl;
    return d; //to be deleted???
}

const double& Polynomial::operator[](int i) const
{
	double d = 0.0; //no such coefficient exists
	if (i <= degree) {
		return coefficients[i];
	}

	//felmeddelande vid out
	std::cout << "No such coefficient exists" << std::endl;
	return d; //to be deleted???
}

//clone
Polynomial* Polynomial::clone() const
{
   // Polynomial* P{*this};
	return new Polynomial{ *this }; //to be deleted
}

Polynomial operator+(Polynomial lhs, const Polynomial& rhs)
{
	//std::cout << "Test operator + " << std::endl;
	Polynomial temp{ lhs };
	temp.operator+=(rhs);

	return temp;
}

void Polynomial::display(std::ostream& os) const
{
	os << coefficients[0];
    for(int i = 1; i <= degree; i++) {
        if(coefficients[i] != 0) {
            //if(i == 0) {
               // os << coefficients[i];
            //}
           //else{
                os << " + " << coefficients[i] << " * X^" << i;
           //}
        }
        
    }
}
