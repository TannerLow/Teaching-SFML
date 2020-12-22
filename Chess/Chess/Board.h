#pragma once
#include <iostream>
using namespace std;
#include "Piece.h"

class Board
{
private:
	Piece*** board;
public:
	Board() {
		board = new Piece * *[8];
		for (int i; i < 8; i++)
			board[i] = new Piece *[8];

		//use a loop to set every spot in the board to a null pointer
		for (int i = 0; i < 8; i++) {
			for (int z = 0; z < 8; z++) {
				board[i][z] = nullptr;
			}
		}
		for (int i = 0; i < 8; i++) {
			board[1][i] = new Piece("pawn", "white", i, 1);
			board[6][i] = new Piece("pawn", "black", i, 6);
		}
		board[0][7] = new Piece("rook", "white", 7, 0);
		board[0][0] = new Piece("rook", "white", 0, 0);
		board[0][1] = new Piece("knight", "white", 1, 0);
		board[0][6] = new Piece("knight", "white", 6, 0);
		board[0][2] = new Piece("bishop", "white", 2, 0);
		board[0][5] = new Piece("bishop", "white", 5, 0);
		board[0][3] = new Piece("king", "white", 3, 0);
		board[0][4] = new Piece("queen", "white", 4, 0);

		board[7][7] = new Piece("rook", "black", 7, 7);
		board[7][0] = new Piece("rook", "black", 0, 7);
		board[7][1] = new Piece("knight", "black", 1, 7);
		board[7][6] = new Piece("knight", "black", 6, 7);
		board[7][2] = new Piece("bishop", "black", 2, 7);
		board[7][5] = new Piece("bishop", "black", 5, 7);
		board[7][3] = new Piece("king", "black", 3, 7);
		board[7][4] = new Piece("queen", "black", 4, 7);

	}
	void remove(int r, int c) {
		delete board[r][c];
		board[r][c] = nullptr;
	}
	void move(int original_row, int original_column, int new_row, int new_column) {
		if (board[original_row][original_column]->isValidMove(new_column, new_row, board)) {
			if (board[new_row][new_column] != nullptr) {
				remove(new_row, new_column);
				board[original_row][original_column] = board[new_row][new_column];
				remove(original_row, original_column);
			}
			else {
				board[original_row][original_column] = board[new_row][new_column];
				remove(original_row, original_column);
			}
		}
	}
	~Board() {
		for (int i; i < 8; i++) {
			for (int b; i < 8; i++) {
				remove(i, b);
			}
		}
		for (int i; i < 8; i++)
			delete[] board[i];
		delete[] board;
	}

};