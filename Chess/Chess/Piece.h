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
	bool isValidMove(int col, int row, Board X) {
		if (type == "pawn") {
			if (color == "black") {
				if (col == x - 1 and row == y - 1) { // and enemy piece 
					return true;
				}
				if (col == x + 1 and row == y - 1) { // and enemy piece 
					return true;
				}
				if (col == x and row == y - 1) { // and no enemy piece
					return true;
				}
				if (col == x and row == 4 and x == 6) {
				 // Check if there any pieces in front of it, 1 or 2 spots
					return true;
				}
			}
			else {
				if (x == 1) {
					// if pawn is white 
				}
			}
		}
		if (type == "king") {
			if (color == "black") { //color
				if (y - 1 <= row and row <= y + 1) {
					if (x - 1 <= col and col <= x + 1) {
						if (col != x and row != y) // can't land on same piece 
							return true;
					}
				}
			}  
			if (color == "white") { //color
				if (y - 1 <= row and row <= y + 1) {
					if (x - 1 <= col and col <= x + 1) {
						if (col != x and row != y) // can't land on same piece
							return true;
					}
			  }
			}
		}

	}
};

