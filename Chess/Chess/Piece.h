#pragma once
#include <string>
#include <iostream>
#include "Board.h" b
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
	bool isEnemy(Piece*** board, int row, int column) {
		if (board[row][column] != nullptr and color != board[row][column]->getColor()) {
			return true;
		}
		return false;
	}
	bool isAlly(Piece*** board, int row, int column) {
		if (board[row][column] != nullptr and color == board[row][column]->getColor()) {
			return true;
		}
		return false;
	}
	bool isValidMove(int col, int row, Piece***board) {
		if (type == "pawn") {
			if (color == "black") {
				if (col == x - 1 and row == y - 1 and isEnemy(board, row, col)) { // and enemy piece 
					return true;
				}
				if (col == x + 1 and row == y - 1 and isEnemy(board, row, col)) { // and enemy piece 
					return true;
				}
				if (col == x and row == y - 1 and !isEnemy(board, row, col) and !isAlly(board, row, col)) { // and no enemy piece
					return true;
				}
				if (col == x and row == 4 and y == 6 and !isEnemy(board, row, col) and !isAlly(board, row, col) and !isEnemy(board, row + 1, col) and !isAlly(board, row + 1, col)) {
				 // Check if there any pieces in front of it, 1 or 2 spots
					return true;
				
					
				}
			}
			else {
				if (col == x + 1 and row == y + 1 and isEnemy(board, row, col)) { // and enemy piece 
					return true;
				}
				if (col == x - 1 and row == y + 1 and isEnemy(board, row, col)) { // and enemy piece 
					return true;
				}
				if (col == x and row == y + 1 and !isEnemy(board, row, col) and !isAlly(board, row, col)) { // and no enemy piece
					return true;
				}
				if (col == x and row == 3 and y == 1 and !isEnemy(board, row, col) and !isAlly(board, row, col) and !isEnemy(board, row - 1, col) and !isAlly(board, row - 1, col)) {
					// Check if there any pieces in front of it, 1 or 2 spots
					return true;
				}
			}
				
			
		}
		if (type == "king") {  
				if (y - 1 <= row and row <= y + 1) {
					if (x - 1 <= col and col <= x + 1) {
						if (col != x and row != y) // can't land on same piece
							return true;
						if (isAlly(board, row, col) == true) {
							return false;
						}
					}
			    }
		}
		if (type == "Knight") {
			if (col == x + 1 and row == y + 2 and !isAlly(board, row, col))
				return true;
			if (col == x + 1 and row == y - 2 and !isAlly(board, row, col))
				return true;
			if (col == x + 2 and row == y + 1 and !isAlly(board, row, col))
				return true;
			if (col == x + 2 and row == y - 1 and !isAlly(board, row, col)) 
				return true;
			if (col == x - 1 and row == y - 1 and !isAlly(board, row, col))
				return true;
			if (col == x - 1 and row == y + 2 and !isAlly(board, row, col))
				return true;
			if (col == x - 2 and row == y - 1 and !isAlly(board, row, col))
				return true;
			if (col == x - 2 and row == y + 1 and !isAlly(board, row, col))
				return true;
			return false;
		}
		if (type == "Rook") {
			//If the row and column are both changed, the function will see it as an invalid move
			if (x != col and y == row or x == col and y != row) { 
				if (x < col and y == row) { // to the right
					for (int i = 1; col - i > x; i++) {
						if (isEnemy(board, row, col - i)) {
							return false;
						}
						else if (isAlly(board, row, col - i)) {
							return false;
						}
					}
				}
				else if (x > col and y == row) { // to the left
					for (int i = 1; col + i < x; i++) {
						if (isEnemy(board, row, col + i)) {
							return false;
						}
						else if (isAlly(board, row, col + i)) {
							return false;
						}
					}
				}
				else if (x == col and y > row) { // going down
					for (int i = 1; row - i > y; i++) {
						if (isEnemy(board, row - i, col)) {
							return false;
						}
						else if (isAlly(board, row - i, col)) {
							return false;
						}
					}
				}
				else if (x == col and y < row) { // going up
					for (int i = 1; row + i < y; i++) {
						if (isEnemy(board, row + i, col)) {
							return false;
						}
						else if (isAlly(board, row + i, col)) {
							return false;
						}
					}
				}
				if (isAlly(board, row, col)) {
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
						if (isEnemy(board, row - i, col - i)) {
							return false;
						}
						else if (isAlly(board, row - i, col - i)) {
							return false;
						}
					}
				}
				else if (x > col and y > row) { // going bottom left
					for (int i = 1; col + i < x and row + i < y; i++) {
						if (isEnemy(board, row + i, col + i)) {
							return false;
						}
						else if (isAlly(board, row + i, col + i)) {
							return false;
						}
					}
				}
				else if (x < col and y > row) { // going bottom right
					for (int i = 1; row - i > y and col + i < x; i++) {
						if (isEnemy(board, row - i, col + i)) {
							return false;
						}
						else if (isAlly(board, row - i, col + i)) {
							return false;
						}
					}
				}
				else if (x > col and y < row) { // going top left
					for (int i = 1; row + i < y and col - i > x; i++) {
						if (isEnemy(board, row + i, col - i)) {
							return false;
						}
						else if (isAlly(board, row + i, col - i)) {
							return false;
						}
					}
				}
				if (isAlly(board, row, col)) {
					return false;
				}
				return true;
			}
		}
		if (type == "Queen") {
			if (x != col and y == row or x == col and y != row) { // rook check
				if (x < col and y == row) { // to the right
					for (int i = 1; col - i > x; i++) {
						if (isEnemy(board, row, col - i)) {
							return false;
						}
						else if (isAlly(board, row, col - i)) {
							return false;
						}
					}
				}
				else if (x > col and y == row) { // to the left
					for (int i = 1; col + i < x; i++) {
						if (isEnemy(board, row, col + i)) {
							return false;
						}
						else if (isAlly(board, row, col + i)) {
							return false;
						}
					}
				}
				else if (x == col and y > row) { // going down
					for (int i = 1; row - i > y; i++) {
						if (isEnemy(board, row - i, col)) {
							return false;
						}
						else if (isAlly(board, row - i, col)) {
							return false;
						}
					}
				}
				else if (x == col and y < row) { // going up
					for (int i = 1; row + i < y; i++) {
						if (isEnemy(board, row + i, col)) {
							return false;
						}
						else if (isAlly(board, row + i, col)) {
							return false;
						}
					}
				}
				if (isAlly(board, row, col)) {
					return false;
				}
				return true;
			}
			else if (x != col and y != row) { // bishop check
				if (x < col and y < row) { // going top right
					for (int i = 1; col - i > x and row - i > y; i++) {
						if (isEnemy(board, row - i, col - i)) {
							return false;
						}
						else if (isAlly(board, row - i, col - i)) {
							return false;
						}
					}
				}
				else if (x > col and y > row) { // going bottom left
					for (int i = 1; col + i < x and row + i < y; i++) {
						if (isEnemy(board, row + i, col + i)) {
							return false;
						}
						else if (isAlly(board, row + i, col + i)) {
							return false;
						}
					}
				}
				else if (x < col and y > row) { // going bottom right
					for (int i = 1; row - i > y and col + i < x; i++) {
						if (isEnemy(board, row - i, col + i)) {
							return false;
						}
						else if (isAlly(board, row - i, col + i)) {
							return false;
						}
					}
				}
				else if (x > col and y < row) { // going top left
					for (int i = 1; row + i < y and col - i > x; i++) {
						if (isEnemy(board, row + i, col - i)) {
							return false;
						}
						else if (isAlly(board, row + i, col - i)) {
							return false;
						}
					}
				}
				if (isAlly(board, row, col)) {
					return false;
				}
				return true;
			}
		}
 
	}
};