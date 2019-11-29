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

Polynomial& Polynomial::operator=(Polynomial P)
{
    
    //ADD CODE
    std::swap(degree, P.degree);
    std::swap(coefficients, P.coefficients);
    
    //swap coefficients
    
    
    return *this; //to be deleted
}

//Addition operator
Polynomial Polynomial::operator+(const Polynomial& P) const
{
    //ADD CODE
    
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
double& Polynomial::operator[](int i) const
{
    double d = 0.0;
    return d; //to be deleted
}

//clone
Polynomial* Polynomial::clone() const
{
    Polynomial* P{};
    return P; //to be deleted
}

Polynomial operator+(Polynomial lhs, const Polynomial& rhs)
{
    return lhs; //to be deleted
}

void Polynomial::display(std::ostream& os) const
{
    for(int i = 0; i <= degree; i++) {
        if(coefficients[i] != 0) {
            if(i == 0) {
                os << coefficients[i];
            }
            else{
                os << " + " << coefficients[i] << " * X^" << i;
            }
        }
        
    }
}
