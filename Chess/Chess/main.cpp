#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"

using namespace std;

int main()
{

    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");

    Renderer r;

    //create shape
    sf::Sprite shape;

    //Create texure
    sf::Texture texture;
    texture.loadFromFile("board.png");

    //Attach texture to the shape
    shape.setTexture(texture);



    while (window.isOpen())
    {
        //poll for events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::MouseButtonReleased) {
                cout << sf::Mouse::getPosition(window).x << " " 
                    << sf::Mouse::getPosition(window).y << endl;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}