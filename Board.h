/**
*Header file of class Board
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
//libraries
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <math.h>
#include <ctime>
#include "Cell.h"
#include "OurException.h"
using namespace std;


struct RGB {
  uint8_t red, green, blue;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

class Board{
private:
    int bound;
    Cell **board;

public:
    //Empty constructor for board class
    Board(){}

    //Constructor that receives an int that defines the board size wanted
    Board(int b);

    //A copy constructor that receives a Board object and makes a deep copy to another Board object.
    Board(Board& copy);

    //Distructor for Board object - deletes everything we allocated memory for.
    ~Board();
    
    //This function helps to delete a Board class object (used in distructor and '=' operator function).
    void delBoard();

    //Operator [] overloading for Board class - for a specific cell inside the board.
    Cell& operator[](list<int> lst);

    //Operator '=' overloading for Board class. Inserts value to whole board if '.'. Else throws exception.
    Board& operator=(char c);

    //Operator '=' overloading for Board class. Copies another Board object.
    Board& operator=(Board& copy);

    //Draw function for Board class. Draws the game board.
    const string draw(int n);

    //----------------------------------
    // friend global IO operators
    //----------------------------------
    friend ostream& operator<< (ostream& os, const Board& b);
    friend istream& operator>> (istream& is,Board& c);
};

//----------------------------------------
// friend global IO operators
//----------------------------------------
//Operator '<<' overlaoding for board class.
ostream& operator<< (ostream& os, const Board& b);
//Operator '>>' overlaoding for board class.
istream& operator>> (istream& is,Board& c);



