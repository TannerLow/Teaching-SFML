#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"

int main()
{
    using namespace std;
    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    sf::Sprite shape;
    sf::Texture texture;
    texture.loadFromFile("board.png");
    shape.setTexture(texture);

    while (window.isOpen())
    {
        //poll for events (While loop constantly runs)
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonReleased); {
                cout << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << endl;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}