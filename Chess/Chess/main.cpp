#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
#include "Renderer.h"
using namespace std;

int main() {
	Renderer r;
	Board board;
	sf::RenderWindow window(sf::VideoMode(800,800), "Chess");

	/*
	int currentRow = 0, currentCol = 0;
	int newRow = 0, newCol = 0;
	bool firstClick = true;
	*/

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed)
		}
		cout << "Row ": << (event.mouseButton.y / 100 + 1) << endl;
		cout << "Column: " << (event.mouseButton.x / 100 + 1) << endl;
		}
		
	
		window.clear();
		r.draw(window, board);
		window.display();
	}

	int a;
	int b;
	int c;
	int d;

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

	cout << (board.move(a, b, c, d) ? "move successful" : "move marked invalid")  << endl;
	cout << endl;
}