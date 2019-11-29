/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"

//ADD implementation of the member functions for class Expression

//default constructor
/*Expression::Expression(){
}*/

/*Expression::~Expression(){
    //Add code
    //Vad är det vi ska ta bort?
}*/

bool Expression::isRoot(double x) {
    if(this->operator()(x) < abs(EPSILON)) return true; //om funktionens värde av x är nära noll returneras true
    return false; //annars returneras false
}

std::ostream& operator<<(std::ostream& os, const Expression& E) //Ska denna finnas med?
{
    E.display(os);
    return os; //to be edited!!
}

//Implementera display 

//operator<< - Ska den implementeras här?
