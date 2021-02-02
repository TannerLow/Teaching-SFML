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
		for (int i = 0; i < 8; i++)
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
	bool move(int original_row, int original_column, int new_row, int new_column) {
		cout << board[original_row][original_column]->getColor() << endl;

		//if it is a valid move
		if (board[original_row][original_column]->isValidMove(new_column, new_row, board)) {
			//if destination is occupied
			if (board[new_row][new_column] != nullptr) {
				//remove piece occupying the destination
				remove(new_row, new_column);
				board[new_row][new_column] = board[original_row][original_column]; //move selected piece
				//remove(original_row, original_column);
				board[original_row][original_column] = nullptr;
			}
			//if destination is empty
			else {
				board[new_row][new_column] = board[original_row][original_column]; //move selected piece
				//remove(original_row, original_column);
				board[original_row][original_column] = nullptr;
			}
			return true;
		}
		return false;
	}
	~Board() {
		for (int i = 0; i < 8; i++) {
			for (int b = 0; i < 8; i++) {
				remove(i, b);
			}
		}
		for (int i = 0; i < 8; i++)
			delete[] board[i];
		delete[] board;
	}
	Piece* getPiece(int row, int col) {
		return board[row][col];
	}
};