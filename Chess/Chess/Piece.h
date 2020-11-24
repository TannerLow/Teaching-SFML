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
	bool isValidMove(int col, int row, Board X) {
		if (type == "pawn") {
			if (color == "black") {

				if (x == 6) {
					row == row - 1;
					row == row - 2;
				}
			}
			else {
				if (x == 1) {
					row == row + 1;
					row == row + 2;
				}
			}
		}


	}
};

