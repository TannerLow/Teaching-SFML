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

};

