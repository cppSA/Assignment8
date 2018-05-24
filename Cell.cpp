/**
*cpp file of class Cell
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
//library
#include "Board.h"
//Empty constructor.
Cell::Cell(){}

//Function that sets value in Cell object.
void Cell::setValue(const char& c){
    this->value=c;
}

//Function that gets value from Cell object.
const char Cell::getValue(){
    return this->value;
}

//Operator '=' overloading for Cell class. If the char given is not 'X' or 'O' - an exception is thrown.
Cell& Cell::operator=(char c){
    if (c=='X' || c=='O' || c=='.'){
        this->value=c;
        return *this;
    }
    else{
        IllegalCharException ce;
        ce.setCh(c);
        throw ce;
    }
}

//Operator casting from Cell to char
Cell::operator char() const{
    return this->value;
}

//Operator '<<' overloading for Cell class.
ostream& operator<< (ostream& os, Cell& c){
    os << c.getValue();
    return os;
}
