#pragma once
#include <SFML/Graphics.hpp>

class Renderer
{
private:
	sf::Texture boardImage;
	sf::Sprite boardSprite;

	sf::Texture spriteSheet; //added
	sf::Sprite sprite[12]; //added

public:
	Renderer() {
		boardImage.loadFromFile("board.png");
		boardSprite.setTexture(boardImage);

		//load the file in and then attach it to the sprite
		spriteSheet.loadFromFile("chess pieces.png");
		
		sf::Vector2u sheetSize = spriteSheet.getSize(); //1200 x 400
		sheetSize.x /= 6; // 200 
		sheetSize.y /= 2; // 200

		sf::IntRect rect(0,0,sheetSize.x, sheetSize.y);
		sprite[0].setTexture(spriteSheet);
		sprite[0].setTextureRect(rect);
		sprite[0].setScale(0.5f, 0.5f);
	}

	void draw(sf::RenderWindow& window) {
		window.draw(boardSprite);
		window.draw(sprite[0]); //added
	}

};

