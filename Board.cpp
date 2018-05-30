/**
*cpp file of class Board
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
//library
#include "Board.h"

//Constructor that receives an int that defines the board size wanted
Board::Board(int b){
    this->bound=b;
    this->board=new Cell*[b];
    for (int i=0; i<b; i++){
        this->board[i]=new Cell[b];
    }
    for (int i=0; i<this->bound; i++){
        for (int j=0; j<this->bound;j++){
            this->board[i][j].setValue('.');
        }
    }
}

//A copy constructor that receives a Board object and makes a deep copy to another Board object.
Board::Board(Board& copy){
    this->bound=copy.bound;
    this->board=new Cell*[this->bound];
    for (int i=0; i<this->bound; i++){
        this->board[i]=new Cell[this->bound];
    }
    for (int i=0; i<this->bound; i++){
        for (int j=0; j<this->bound;j++){
            this->board[i][j]=copy.board[i][j];
        }
    }
}

//This function helps to delete a Board class object (used in distructor and '=' operator function).
void Board::delBoard(){
    for (int i=0; i<this->bound; i++){
        delete[] this->board[i];
    }
    delete[] this->board;
}

//Distructor for Board object - deletes everything we allocated memory for.
Board::~Board(){
    delBoard();
}
    
//Operator [] overloading for Board class - for a specific cell inside the board.
Cell& Board::operator[](list<int> lst){
    int r=lst.front(), c=lst.back();
    if (r<this->bound && c<this->bound){
        return this->board[r][c];
    }
    else{
        IllegalCoordinateException ce(r,c);
        throw ce;
    }
}

//Operator '=' overloading for Board class. Inserts value to whole board if '.'. Else throws exception.
Board& Board::operator=(char c){
    if (c=='.'){
        for (int i=0; i<this->bound; i++){
            for (int j=0; j<this->bound;j++){
                this->board[i][j].setValue(c);
            }
        }
	return *this;
    }
    else{
        IllegalCharException ce;
        ce.setCh(c);
        throw ce;
    }
}

//Operator '=' overloading for Board class. Copies another Board object.
Board& Board::operator=(Board& copy){
    delBoard();
    this->bound=copy.bound;
    this->board=new Cell*[this->bound];
    for (int i=0; i<this->bound; i++){
        this->board[i]=new Cell[this->bound];
    }
    for (int i=0; i<this->bound; i++){
        for (int j=0; j<this->bound;j++){
            this->board[i][j]=copy.board[i][j];
        }
    }
    return *this; 
}

//Draw function for Board class. Draws the game board.
const string Board::draw(int n){
    //dimentions for picture
    const int dimx = n, dimy = n;
    int cell_size = n / this->bound;    //defining cell size in board
    int grid_width = cell_size / 10;    //defining grid width in board
    int r_c,g_c,b_c;                    //variables for RGB
    //name for text file
    // time_t now;
    // struct tm * timeinfo;
    // time ( &now );
    // timeinfo = localtime ( &now );
    // string filename= asctime (timeinfo);
    // filename=filename.substr (0,filename.length()-1);
    // replace( filename.begin(), filename.end(), ':', '-'); // replace all ':' to '-'
    // replace( filename.begin(), filename.end(), ' ', '_'); // replace all ':' to '-'
    //filename+=".ppm";
    string filename="board"+to_string(this->bound)+".ppm";
    ofstream imageFile(filename, ios::out | ios::binary);
    imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
    RGB image[dimx*dimy];
    //Background for grid
    for (int j = 0; j < dimy; ++j)  {  // row
        for (int i = 0; i < dimx; ++i) { // column
            //0, 172, 230 - light blue for grid
            image[dimx*j+i].red = (0);
            image[dimx*j+i].green = (172);
            image[dimx*j+i].blue = (230);
        }
    }
    //Painitng the board acoording to '.' or 'X' or 'O' in the original game board
    for (int m=0; m<this->bound; m++)
        for (int k=0; k<this->bound; k++){
            char c = this->board[m][k].getValue();
            if (c=='.'){
                r_c=g_c=b_c=242;
            }else
                if(c=='X'){
                    r_c=255;
                    g_c=102;
                    b_c=102;
                }else{          //'.'
                    r_c=51;
                    g_c=255;
                    b_c=51;
                }
            //Coloring everything at once
            for (int j = m*cell_size+grid_width; j < m*cell_size+cell_size-grid_width; ++j)  {  // row
                for (int i = k*cell_size+grid_width; i < k*cell_size+cell_size-grid_width; ++i) { // column
                    image[dimx*j+i].red = (r_c);
                    image[dimx*j+i].green = (g_c);
                    image[dimx*j+i].blue = (b_c);
                }
            }
            //'X'
            if (c=='X'){
                int left=k*cell_size+grid_width,right=k*cell_size+cell_size-grid_width-1;
                int i=0;
                for (int j = m*cell_size+grid_width; j < m*cell_size+cell_size-grid_width; ++j){
                    //left
                    image[dimx*j+left+i].red = (184);
                    image[dimx*j+left+i].green = (0);
                    image[dimx*j+left+i].blue = (230);
                    //right
                    image[dimx*j+right-i].red = (184);
                    image[dimx*j+right-i].green = (0);
                    image[dimx*j+right-i].blue = (230);
                    i++;

                } 
            }else
                if(c=='O'){
                    double centre_y=(m*cell_size+grid_width)/2+(m*cell_size+cell_size-grid_width-1)/2,
                           centre_x=(k*cell_size+grid_width)/2+(k*cell_size+cell_size-grid_width-1)/2,
                           radius=cell_size/2-2*grid_width;
                    for (int j = m*cell_size+grid_width; j < m*cell_size+cell_size-grid_width; ++j)  {  // row
                        for (int i = k*cell_size+grid_width; i < k*cell_size+cell_size-grid_width; ++i) { // column
                            double d=pow(centre_x-i,2)+pow(centre_y-j,2);
                            d=sqrt (d);
                            d=abs(d-radius);
                            if(d<10){
                                image[dimx*j+i].red = (255);
                                image[dimx*j+i].green = (255);
                                image[dimx*j+i].blue = (153);
                            }
                        }
                    }
                }
        }
    //image processing
    imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
    imageFile.close();
    return filename;
}

//----------------------------------------
// friend global IO operators
//----------------------------------------
//Operator '<<' overlaoding for board class.
ostream& operator<< (ostream& os, const Board& b){
    for (int i=0; i<b.bound; i++){
        for (int j=0; j<b.bound;j++){
            os<<b.board[i][j].getValue();
        }
        os <<endl;
    }
    return os;
}
//Operator '>>' overlaoding for board class.
istream& operator>> (istream& is,Board& b) {
    string line;
    int size;
    is>>line;
    cout<<(int)line.length()<<endl;
    size=(int)line.length();
    Board tmp(size);
    b=tmp;
    for (int i=0; i<size; i++){
        if (line[i]=='X' || line[i]=='O' || line[i]=='.')
            b[{0, i}] = line[i];    //needs to be checked
        else
            size--;
    }
    tmp.bound=size;
    int cur_line = 0;
    while(is>>line){
        cur_line++;
        for (int i=0; i<size && cur_line<size; i++){
            if (line[i]=='X' || line[i]=='O' || line[i]=='.')
                b[{cur_line, i}] = line[i];    //needs to be checked
        }
    }
    return is;
}
