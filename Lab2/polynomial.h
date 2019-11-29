/*************************
* Class Polynomial       *
* TNG033: Lab 2          *
**************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

#include "expression.h"


class Polynomial : public Expression
{
public:
    //Default constructor
    explicit Polynomial();
    
    //Constructor
    Polynomial(int n, double v[]); //kan vi skicka in arrayen som referens?
    
    //Conversion constructor //bör den vara explicit?
     Polynomial(const double d);
    
    //Copy constructor
    Polynomial(const Polynomial& source);
    
    //Destructor
    ~Polynomial() = default; //skriv om!
    
    //Assignment operator
    Polynomial& operator=(Polynomial P);
    
    //Addition operator
    Polynomial operator+=(const Polynomial& P);
    
    //operator()
    double operator()(double d) const override;
    
    //subscript operator
	double& operator[](int i);
	const double& operator[](int i) const;
    
    //clone
    Polynomial* clone() const override;
    
    //display function
    void display(std::ostream& os) const override;
    
    
    
    
protected:
    int degree; //number of coefficients
    double* coefficients; //pointer to array of coefficients
};

//Commutative addtion of double and Polynomial
Polynomial operator+(Polynomial lhs, const Polynomial& rhs);


#endif
