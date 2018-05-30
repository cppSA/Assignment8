CXX=clang++-5.0
CXXFLAGS=-std=c++17

all: Board.o

Board.o: Board.cpp Cell.cpp OurException.cpp Board.h Cell.h OurException.h
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o
	$(CXX) $(CXXFLAGS) --compile Cell.cpp -o Cell.o
	$(CXX) $(CXXFLAGS) --compile OurException.cpp -o OurException.o

make: all
	$(CXX) $(CXXFLAGS) -c main.cpp
	$(CXX) $(CXXFLAGS) *.o -o a.out
	
board3:	
	./a.out < board3.txt

board6:	
	./a.out < board6.txt

allboard:
	./a.out < board1.txt
	./a.out < board2.txt
	./a.out < board3.txt
	./a.out < board4.txt
	./a.out < board5.txt
	./a.out < board6.txt
	./a.out < board7.txt
	./a.out < board8.txt

clean:
	rm *.o a.out *.ppm