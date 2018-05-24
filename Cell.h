/**
*hidden file of class Cell
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
//library
#include <iostream>
using namespace std;

class Cell{
private:
    char value;

public:
    //Empty constructor.
    Cell();

    //Function that sets value in Cell object.
    void setValue(const char& c);

    //Function that gets value from Cell object.
    const char getValue();

    //Operator '=' overloading for Cell class. If the char given is not 'X' or 'O' - an exception is thrown.
    Cell& operator=(char c);

    //operator casting from Cell to char
    operator char() const;

    //----------------------------------
    // friend global IO operators
    //----------------------------------
    friend ostream& operator<< (ostream& os, Cell& c);
};

//----------------------------------------
// friend global IO operators
//----------------------------------------

//Operator '<<' overloading for Cell class.
ostream& operator<< (ostream& os, Cell& c);

