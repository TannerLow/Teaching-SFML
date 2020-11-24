#pragma once
#include <iostream>
using namespace std;
#include "Piece.h"

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
		for (int i = 0; i < 8; i++) {
			board[1][i] = new Piece("pawn", "white", i, 1);
			board[6][i] = new Piece("pawn", "black", i, 1);
		}
		board[0][7] = new Piece("rook", "white", 0, 7);
		board[0][0] = new Piece("rook", "white", 0, 0);
		board[0][1] = new Piece("knight", "white", 0, 1);
		board[0][6] = new Piece("knight", "white", 0, 6);
		board[0][2] = new Piece("bishop", "white", 0, 2);
		board[0][5] = new Piece("bishop", "white", 0, 5);
		board[0][3] = new Piece("king", "white", 0, 3);
		board[0][4] = new Piece("queen", "white", 0, 4);

		board[6][7] = new Piece("rook", "black", 6, 7);
		board[6][0] = new Piece("rook", "black", 6, 0);
		board[6][1] = new Piece("knight", "black", 6, 1);
		board[6][6] = new Piece("knight", "black", 6, 6);
		board[6][2] = new Piece("bishop", "black", 6, 2);
		board[6][5] = new Piece("bishop", "black", 6, 5);
		board[6][3] = new Piece("king", "black", 6, 3);
		board[6][4] = new Piece("queen", "black", 6, 4);

	}
	void remove(int r, int c) {
		board[r][c] = nullptr;
	}
	void move(int original_row, int original_column, int new_row, int new_column) {
		if (board[original_row][original_column]->isValidMove(new_column, new_row)) {
			if (board[new_row][new_column] != nullptr) {
				board[original_row][original_column] = board[new_row][new_column];
				board[original_row][original_column] = nullptr;
			}
			else {
				board[original_row][original_column] = board[new_row][new_column];
				board[original_row][original_column] = nullptr;
				board[new_row][new_column] = nullptr;
			}
		}
	}
};

