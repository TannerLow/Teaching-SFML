#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

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


		//loads the white king piece
		sf::IntRect rect(0,0,sheetSize.x, sheetSize.y);
		sprite[0].setTexture(spriteSheet);
		sprite[0].setTextureRect(rect);
		sprite[0].setScale(0.5f, 0.5f);

		//Gavin's branch uses the nested for loops we need


	}

	void draw(sf::RenderWindow& window, Board& board) {
		window.draw(boardSprite);
		
		if (board.getPiece(0, 0)->getColor() == "white") {
			if (board.getPiece(0, 0)->getType() == "Rook") {
				window.draw(sprite[4]);
			}
			else if () {

			}
		}
		else { //otherwise its black

		}
	}

};

