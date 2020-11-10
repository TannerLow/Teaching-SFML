#include "Board.h"
#include <iostream>

Board::Board() {
	cout << "hello" << endl;
}
class Board
{
private:
	Piece* board[8][8];
public: 
	Board() {
		//use a loop to set every spot in the board to a null pointer
		for (int i = 0; i < 8; i++) {
			for (int z = 0; z < 8; z++) {
				board[i][z] = nullptr;
			}
		}
	}
};
void remove() {
	
}
void move(int column, int row) {

}