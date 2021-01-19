#pragma once
#include <SFML/Graphics.hpp>

class Renderer
{
private:
	sf::Texture boardImage;
	sf::Texture piece;
	sf::Sprite boardSprite;
	sf::Sprite Boardpiece;
public:
	Renderer() {
		boardImage.loadFromFile("board.png");
		piece.loadFromFile("chess pieces.png");
		boardSprite.setTexture(boardImage);
		Boardpiece.setTexture(piece);
	}

	void draw(sf::RenderWindow& window) {
		window.draw(boardSprite);
		window.draw(Boardpiece);
	}

 sf:IntRect rect(0, 0, sheetSize.x, sheetSize.y);
    sprite[0].setTexture(spriteSheet);
	sprite[0].setTextureRect(Rect);
	sprite[0].setScale(0.5f, 0.5f);

void draw(sf::RenderWindow&window, Board& board)
};

