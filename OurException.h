/**
*header file of classes IllegalCharException and IllegalCoordinateException
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
//library
#include <exception>
using namespace std;

//Class to handle illegal char insertions. Using function 'setCh' by the Board Class '=' operator function.
class IllegalCharException:public exception{
    private:
        char ch;
    public:
        //Function for exception throwing, returns the value in ch.
        char theChar() const;

        //Function for setting value in ch.
        void setCh(const char& c);
};

//Class to handle illegal insertions by coordinates. Using constructor by the Board Class '=' operator function.
class IllegalCoordinateException:public exception{
    private:
        int row;
        int col;
    public:
        //Constructor for IllegalCoordinateException class.
        IllegalCoordinateException(const int& r,const int& c);

        //Function for exception throwing - returns the string printed in the exception throwing.
        string theCoordinate() const;
};