#pragma once
#include <SFML/Graphics.hpp>

class Renderer
{
private:
	sf::Texture boardImage;
	sf::Sprite boardSprite;
	sf::Texture spriteSheet;
	sf::Sprite sprite[12];
public:
	Renderer() {
		boardImage.loadFromFile("board.png");
		boardSprite.setTexture(boardImage);
		
		//load the file in and then attach it to the sprite

		spriteSheet.loadFromFile("chess pieces.png");

		sf::Vector2u sheetSize = spriteSheet.getSize(); //1200 x 400
		sheetSize.x /= 6; // 200
		sheetSize.y /= 2; // 200

		for (int i = 0; i < 6; i++) {
			for (int b = 0; b < 2; b++) {
				sf::IntRect rect(sheetSize.x * i, sheetSize.y * b, sheetSize.x, sheetSize.y);
				sprite[0].setTexture(spriteSheet);
				sprite[0].setTextureRect(rect);
				sprite[0].setScale(.5, .5);
			}
		}
	}

	void draw(sf::RenderWindow& window) {
		window.draw(boardSprite);
		window.draw(sprite[0]);
	}
};