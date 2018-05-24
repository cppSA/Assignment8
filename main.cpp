//This main file was given in the assignment and was used to run our program.
/**
 * Assignment 8 main.cpp.
 * 
 * Author: Erel Segal-Halevi.
 * 
 * Since: 2018-05
 */
#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	Board board;
	cin >> board;
	string filename = board.draw(600);
	cout << filename << endl;
}