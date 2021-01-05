#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
using namespace std;

int main() {
	int a;
	int b;
	int c;
	int d;
	string e;
	Board board;

	cout << "Row 1: ";
	cin >> a;
	cout << endl;
	cout << "Column 1: ";
	cin >> b;
	cout << endl;
	cout << "Row 2: ";
	cin >> c;
	cout << endl;
	cout << "Column 2: ";
	cin >> d;
	cout << "Color: ";
	cin >> e;
	cout << (board.move(a, b, c, d) ? "move successful" : "move marked invalid")  << endl;
	cout << endl;
}