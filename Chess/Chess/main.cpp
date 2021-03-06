#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
#include "Renderer.h"
using namespace std;

int main() {
	Renderer r;
	Board board;
	sf::RenderWindow window(sf::VideoMode(800,800), "Chess");

	int row = 0, col = 0;
	int newRow = 0, newCol = 0;
	int counter = 1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (counter == 1) {
					row = event.mouseButton.y / 100;
					col = event.mouseButton.x / 100;
					counter++;
				}
				else if (counter == 2) {
					newRow = event.mouseButton.y / 100;
					newCol = event.mouseButton.x / 100;
					counter = 1;
					cout << (board.move(row, col, newRow, newCol) ? "move successful" : "move marked invalid") << endl;
				}
				cout << "Row: " << event.mouseButton.y/100 << endl;
				cout << "Col: " << event.mouseButton.x/100 << endl;
			}
			
		}

		window.clear();
		r.draw(window, board);
		window.display();
	}
}