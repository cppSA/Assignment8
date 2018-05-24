/**
*cpp file of classes IllegalCharException and IllegalCoordinateException
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
//library
#include "Board.h"

//Function for exception throwing, returns the value in ch.
char IllegalCharException::theChar() const{
    return ch;
}

//Function for setting value in ch.
void IllegalCharException::setCh(const char& c){
    this->ch=c;
}


//Constructor for IllegalCoordinateException class.
IllegalCoordinateException::IllegalCoordinateException(const int& r,const int& c){
    this->row=r;
    this->col=c;
}
        
//Function for exception throwing - returns the string printed in the exception throwing.
string IllegalCoordinateException::theCoordinate() const{
    string ans=to_string(row)+","+to_string(col);
    return ans;
}
