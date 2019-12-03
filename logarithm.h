/*************************
* Class Logarithm        *
* TNG033: Lab 2          *
**************************/


#ifndef LOGARITHM_H
#define LOGARITHM_H

#include <iostream>

#include "expression.h"

class Logarithm : virtual public Expression
{

    //ADD CODE
public:
	Logarithm();

	Logarithm(const Expression& F, int l1, int l2, int a);

	Logarithm(const Logarithm& source);

	virtual ~Logarithm();

	Logarithm& operator=(Logarithm L);

	virtual void display(std::ostream& os) const override;

	virtual double operator()(double d) const override; //ska den returnera värde, referens eller pointer?
	virtual Logarithm* clone() const override;

protected:
	int c1, c2;
	int b;
	Expression* E;

};

#endif
