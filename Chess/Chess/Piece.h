#pragma once
#include <string>
#include <iostream>
#include "Board.h"
using namespace std;

class Piece {
private: 
	int x;
	int y;
	string type;
	string color;
public:
	Piece(string n, string ColorX, int col, int row) {
		type = n;
		int x = col;
		int y = row;
		color = ColorX;
	}
	string getColor () {
		return color;
	}
	bool isValidMove(int col, int row, Piece*** boardy) {
		if (type == "pawn") {
			if (color == "black") {
				if (col == x - 1 and row == y - 1 and boardy.isEnemy(row, col, color)) { // and enemy piece 
					return true;
				}
				if (col == x + 1 and row == y - 1 and boardy.isEnemy(row, col, color)) { // and enemy piece 
					return true;
				}
				if (col == x and row == y - 1 and !boardy.isEnemy(row, col, color) and !boardy.isAlly(row, col, color)) { // and no enemy piece
					return true;
				}
				if (col == x and row == 4 and y == 6 and !boardy.isEnemy(row, col, color) and !boardy.isAlly(row, col, color) and !boardy.isEnemy(row + 1, col, color) and !boardy.isAlly(row + 1, col, color)) {
					// Check if there any pieces in front of it, 1 or 2 spots
					return true;


				}
			}
			else {
				if (col == x + 1 and row == y + 1 and boardy.isEnemy(row, col, color)) { // and enemy piece 
					return true;
				}
				if (col == x - 1 and row == y + 1 and boardy.isEnemy(row, col, color)) { // and enemy piece 
					return true;
				}
				if (col == x and row == y + 1 and !boardy.isEnemy(row, col, color) and !boardy.isAlly(row, col, color)) { // and no enemy piece
					return true;
				}
				if (col == x and row == 3 and y == 1 and !boardy.isEnemy(row, col, color) and !boardy.isAlly(row, col, color) and !boardy.isEnemy(row - 1, col, color) and !boardy.isAlly(row - 1, col, color)) {
					// Check if there any pieces in front of it, 1 or 2 spots
					return true;
				}


			}
			if (type == "king") {
				if (y - 1 <= row and row <= y + 1) {
					if (x - 1 <= col and col <= x + 1) {
						if (col != x and row != y) // can't land on same piece
							return true;
						if (boardy.isAlly(row, col, color) == true) {
							return false;
						}
					}
				}
			}
			if (type == "Knight") {
				if (col == x + 1 and row == y + 2 and !boardy.isAlly(row, col, color))
					return true;
				if (col == x + 1 and row == y - 2 and !boardy.isAlly(row, col, color))
					return true;
				if (col == x + 2 and row == y + 1 and !boardy.isAlly(row, col, color))
					return true;
				if (col == x + 2 and row == y - 1 and !boardy.isAlly(row, col, color))
					return true;
				if (col == x - 1 and row == y - 1 and !boardy.isAlly(row, col, color))
					return true;
				if (col == x - 1 and row == y + 2 and !boardy.isAlly(row, col, color))
					return true;
				if (col == x - 2 and row == y - 1 and !boardy.isAlly(row, col, color))
					return true;
				if (col == x - 2 and row == y + 1 and !boardy.isAlly(row, col, color))
					return true;
				return false;
			}
			if (type == "Rook") {
				//If the row and column are both changed, the function will see it as an invalid move
				if (x != col and y == row or x == col and y != row) {
					if (x < col and y == row) { // to the right
						for (int i = 1; col - i > x; i++) {
							if (boardy.isEnemy(row, col - i, color)) {
								return false;
							}
							else if (boardy.isAlly(row, col - i, color)) {
								return false;
							}
						}
					}
					else if (x > col and y == row) { // to the left
						for (int i = 1; col + i < x; i++) {
							if (boardy.isEnemy(row, col + i, color)) {
								return false;
							}
							else if (boardy.isAlly(row, col + i, color)) {
								return false;
							}
						}
					}
					else if (x == col and y > row) { // going down
						for (int i = 1; row - i > y; i++) {
							if (boardy.isEnemy(row - i, col, color)) {
								return false;
							}
							else if (boardy.isAlly(row - i, col, color)) {
								return false;
							}
						}
					}
					else if (x == col and y < row) { // going up
						for (int i = 1; row + i < y; i++) {
							if (boardy.isEnemy(row + i, col, color)) {
								return false;
							}
							else if (boardy.isAlly(row + i, col, color)) {
								return false;
							}
						}
					}
					if (boardy.isAlly(row, col, color)) {
						return false;
					}
					return true;
				}
			}
			if (type == "Bishop") {
				//If the row and column are both changed, the function will see it as an invalid move
				if (x != col and y != row) {
					if (x < col and y < row) { // going top right
						for (int i = 1; col - i > x and row - i > y; i++) {
							if (boardy.isEnemy(row - i, col - i, color)) {
								return false;
							}
							else if (boardy.isAlly(row - i, col - i, color)) {
								return false;
							}
						}
					}
					else if (x > col and y > row) { // going bottom left
						for (int i = 1; col + i < x and row + i < y; i++) {
							if (boardy.isEnemy(row + i, col + i, color)) {
								return false;
							}
							else if (boardy.isAlly(row + i, col + i, color)) {
								return false;
							}
						}
					}
					else if (x < col and y > row) { // going bottom right
						for (int i = 1; row - i > y and col + i < x; i++) {
							if (boardy.isEnemy(row - i, col + i, color)) {
								return false;
							}
							else if (boardy.isAlly(row - i, col + i, color)) {
								return false;
							}
						}
					}
					else if (x > col and y < row) { // going top left
						for (int i = 1; row + i < y and col - i > x; i++) {
							if (boardy.isEnemy(row + i, col - i, color)) {
								return false;
							}
							else if (boardy.isAlly(row + i, col - i, color)) {
								return false;
							}
						}
					}
					if (boardy.isAlly(row, col, color)) {
						return false;
					}
					return true;
				}
			}
			if (type == "Queen") {
				if (x != col and y == row or x == col and y != row) { // rook check
					if (x < col and y == row) { // to the right
						for (int i = 1; col - i > x; i++) {
							if (boardy.isEnemy(row, col - i, color)) {
								return false;
							}
							else if (boardy.isAlly(row, col - i, color)) {
								return false;
							}
						}
					}
					else if (x > col and y == row) { // to the left
						for (int i = 1; col + i < x; i++) {
							if (boardy.isEnemy(row, col + i, color)) {
								return false;
							}
							else if (boardy.isAlly(row, col + i, color)) {
								return false;
							}
						}
					}
					else if (x == col and y > row) { // going down
						for (int i = 1; row - i > y; i++) {
							if (boardy.isEnemy(row - i, col, color)) {
								return false;
							}
							else if (boardy.isAlly(row - i, col, color)) {
								return false;
							}
						}
					}
					else if (x == col and y < row) { // going up
						for (int i = 1; row + i < y; i++) {
							if (boardy.isEnemy(row + i, col, color)) {
								return false;
							}
							else if (boardy.isAlly(row + i, col, color)) {
								return false;
							}
						}
					}
					if (boardy.isAlly(row, col, color)) {
						return false;
					}
					return true;
				}
				else if (x != col and y != row) { // bishop check
					if (x < col and y < row) { // going top right
						for (int i = 1; col - i > x and row - i > y; i++) {
							if (boardy.isEnemy(row - i, col - i, color)) {
								return false;
							}
							else if (boardy.isAlly(row - i, col - i, color)) {
								return false;
							}
						}
					}
					else if (x > col and y > row) { // going bottom left
						for (int i = 1; col + i < x and row + i < y; i++) {
							if (boardy.isEnemy(row + i, col + i, color)) {
								return false;
							}
							else if (boardy.isAlly(row + i, col + i, color)) {
								return false;
							}
						}
					}
					else if (x < col and y > row) { // going bottom right
						for (int i = 1; row - i > y and col + i < x; i++) {
							if (boardy.isEnemy(row - i, col + i, color)) {
								return false;
							}
							else if (boardy.isAlly(row - i, col + i, color)) {
								return false;
							}
						}
					}
					else if (x > col and y < row) { // going top left
						for (int i = 1; row + i < y and col - i > x; i++) {
							if (boardy.isEnemy(row + i, col - i, color)) {
								return false;
							}
							else if (boardy.isAlly(row + i, col - i, color)) {
								return false;
							}
						}
					}
					if (boardy.isAlly(row, col, color)) {
						return false;
					}
					return true;
				}
			}

		}
	}
};

