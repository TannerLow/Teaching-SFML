#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <iostream>

using namespace std;

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


		//Gavin's nested for loop for loading the pieces
		for (int i = 0; i < 6; i++) {
			for (int b = 0; b < 2; b++) {
				sf::IntRect rect(sheetSize.x * i, sheetSize.y * b, sheetSize.x, sheetSize.y);
				sprite[i + 6 * b].setTexture(spriteSheet);
				sprite[i + 6 * b].setTextureRect(rect);
				sprite[i + 6 * b].setScale(.5f, .5f);
			}
		}

	}

	void draw(sf::RenderWindow& window, Board& board) {
		//draw board
		window.draw(boardSprite);

		//draw pieces
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				//skip squares with no piece
				if (board.getPiece(i, j) == nullptr)
					continue;

				int spriteNumber = 0;
				//if its a white piece
				if (board.getPiece(i, j)->getColor() == "white") {
					if (board.getPiece(i, j)->getType() == "king") {
						spriteNumber = 0;
					}
					else if (board.getPiece(i, j)->getType() == "queen") {
						spriteNumber = 1;
					}
					else if (board.getPiece(i, j)->getType() == "bishop") {
						spriteNumber = 2;
					}
					else if (board.getPiece(i, j)->getType() == "knight") {
						spriteNumber = 3;
					}
					else if (board.getPiece(i, j)->getType() == "rook") {
						spriteNumber = 4;
					}
					else if (board.getPiece(i, j)->getType() == "pawn") {
						spriteNumber = 5;
					}
				}
				//otherwise it is a black piece
				else {
					if (board.getPiece(i, j)->getType() == "king") {
						spriteNumber = 6;
					}
					else if (board.getPiece(i, j)->getType() == "queen") {
						spriteNumber = 7;
					}
					else if (board.getPiece(i, j)->getType() == "bishop") {
						spriteNumber = 8;
					}
					else if (board.getPiece(i, j)->getType() == "knight") {
						spriteNumber = 9;
					}
					else if (board.getPiece(i, j)->getType() == "rook") {
						spriteNumber = 10;
					}
					else if (board.getPiece(i, j)->getType() == "pawn") {
						spriteNumber = 11;
					}
				}
				sprite[spriteNumber].setPosition(j * 100.f, i * 100.f);
				window.draw(sprite[spriteNumber]);
			}
		}
	}

};

