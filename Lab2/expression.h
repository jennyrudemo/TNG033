/*************************
* Class Expression       *
* TNG033: Lab 2          *
**************************/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <cmath>

const double EPSILON = 1.0e-5;


class Expression
{
public:
    //default constructor
    Expression() = default;
    
    //destructor
    virtual ~Expression() = default;
    
    //Member functions
    virtual bool isRoot(double x) const;//test if a given value x is the root of the function
    
    
    //Pure virtual functions
    virtual double operator()(double d) const = 0; //ska den returnera värde, referens eller pointer?
    virtual Expression* clone() const = 0;
    
    
protected:
    //function
    //vilken typ ska det vara?? //ska den vara virtual?
    friend std::ostream& operator<<(std::ostream& os, const Expression& E);
    
    virtual void display(std::ostream& os) const = 0; //returnerar stream för hur ett uttryck ska displayas //pure virtual?
};

//operator<<




#endif
