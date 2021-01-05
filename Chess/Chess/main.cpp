#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
#include "Renderer.h"
using namespace std;

int main() {
	Renderer r;
	sf::RenderWindow window(sf::VideoMode(800,800), "Chess");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		r.draw(window);
		window.display();
	}

	int a;
	int b;
	int c;
	int d;

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

	cout << (board.move(a, b, c, d) ? "move successful" : "move marked invalid")  << endl;
	cout << endl;
}