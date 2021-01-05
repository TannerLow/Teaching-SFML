#pragma once
#include <SFML/Graphics.hpp>

class Renderer
{
private:
	sf::Texture boardImage;
	sf::Sprite boardSprite;

public:
	Renderer() {
		boardImage.loadFromFile("board.png");
		boardSprite.setTexture(boardImage);
	}

	void draw(sf::RenderWindow& window) {
		window.draw(boardSprite);
	}
};